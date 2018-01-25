#include "xml.h"
#include <string.h>
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

char * XmlLoader_saveToString(const Pensioner * pensioner,char * str){
	char buff[100];
	str = (char *)malloc(sizeof(char) * 1500);
    xmlDoc * doc = xmlNewDoc(BAD_CAST "1.0");

	xmlNode * root = xmlNewNode(NULL, BAD_CAST "pensioner");
	xmlSetProp(root, BAD_CAST "name", BAD_CAST pensioner->name);
	xmlDocSetRootElement(doc, root);
    xmlNewChild(root, NULL, BAD_CAST "surname", BAD_CAST pensioner->surname);

	sprintf(buff, "%i", pensioner->year);
	xmlNewChild(root, NULL, BAD_CAST "year", BAD_CAST buff);
	buff[0] = '\0';

	sprintf(buff, "%f", pensioner->GPA);
	xmlNewChild(root, NULL, BAD_CAST "GPA", BAD_CAST buff);
	buff[0] = '\0';
    xmlNode *  grandchildren = xmlNewNode(NULL, BAD_CAST "grandchildrens");
   
	for(int i = 0; i < pensioner->grandchildren_length; i++){
		xmlNode * currNode = xmlNewNode(NULL, BAD_CAST "grandchildren");
        xmlNewChild(currNode, NULL, BAD_CAST "name", BAD_CAST pensioner->grandchildren[i]->name);
    	xmlAddChild(grandchildren, currNode);
	}
	xmlAddChild(root, grandchildren);



	xmlBuffer * buffer = xmlBufferCreate();
	xmlNodeDump(buffer, NULL, (xmlNode *)doc, 0, 1);
	sprintf(str, "%s", (const char *)buffer->content);
	xmlBufferFree(buffer);

	xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();

	return str;
}
void XmlLoader_loadFromString(Pensioner * pensioner, const char * xmlStr){
	xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
	if(xDoc == NULL){
		printf("Error parsing xml");
		return;
	}
	xmlNode * xRoot = xmlDocGetRootElement(xDoc);
	pensioner->name = (char *)xmlGetProp(xRoot, BAD_CAST "name");
	for(xmlNode * xCurr = xRoot->children; xCurr != NULL; xCurr = xCurr->next){
		if(xCurr->type == XML_ELEMENT_NODE) {
            if(xmlStrcmp(xCurr->name, BAD_CAST "surname") == 0) {
                  pensioner->surname = (char *)xmlNodeGetContent(xCurr);
             }
			if(xmlStrcmp(xCurr->name, BAD_CAST "year") == 0){
				pensioner->year = atoi((char *)xCurr->children->content);
			}
			else{
				if(xmlStrcmp(xCurr->name, BAD_CAST "GPA") == 0){
					pensioner->GPA = atof((char *)xCurr->children->content);
				}
				else{
					if(xmlStrcmp(xCurr->name, BAD_CAST "grandchildrens") == 0){
						for(xmlNode * xChild = xCurr->children; xChild != NULL; xChild = xChild->next){
							if(xChild->type == XML_ELEMENT_NODE && xmlStrcmp(xChild->name, BAD_CAST "grandchildren") == 0){
								Grandchildren * newGrandchildren = Grandchildren_new();
								newGrandchildren->name = (char *)xmlNodeGetContent(xChild);
							
								pensioner = Pensioner_addNewGrandchildren(pensioner, newGrandchildren);
							}
						}
					}
				}
			}
		}
	}
	xmlFreeDoc(xDoc);
	xmlCleanupParser();
	xmlMemoryDump();
}