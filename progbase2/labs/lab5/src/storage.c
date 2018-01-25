
#include <storage.h>

#include <jansson.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <structure.h>

char * readAllText(const char * filename, char * text) {
	char line[100];

  FILE * fr = fopen(filename, "r");
	if (fr == NULL) return NULL;
    while(fgets(line, 100, fr)) {
        strcat(text, line);

    }
	fclose(fr);
	return text;
}

enum {  BUFFER_SIZE = 100 };

List * Storage_load(const char * fileName) {
	FILE *fin = fopen(fileName,"r");
  if (fin == NULL) {
    printf("There is NULL reference\n");
  }
  List * list = List_new();
  char buffer[BUFFER_SIZE];

  while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
      List_add(list, Computer_Game_newFromString(buffer));

  }

  fclose(fin);
	return list;
}

void Storage_save(const char * fileName, List * computer_game) {
	printf("List saved to %s\n", fileName);
  FILE * fin = fopen(fileName,"w");
	char buffer[100];
	for (int i = 0; i < List_count(computer_game); i++) {
		Computer_Game * c = (Computer_Game *)List_get(computer_game, i);
		char * strPtr = Computer_Game_toString(c, buffer);
    fprintf(fin,"%s\n",strPtr);
		printf("\t%i) %s\n", i, strPtr);
	}
  fclose(fin);
}
void Storage_writeAsXml(const char * filePath, List * list) {
      char strBuf[100];
     
      FILE * fout = fopen(filePath,"w");
      xmlDoc * doc = xmlNewDoc(BAD_CAST "1.0");
      xmlNode * rootNode = xmlNewNode(NULL, BAD_CAST "computer_games");
      xmlDocSetRootElement(doc, rootNode);
      for (int i = 0; i < List_count(list) ; i++) {
          xmlNode * computer_gameNode = xmlNewChild(rootNode, NULL, BAD_CAST "computer_game", NULL);
          xmlNewChild(computer_gameNode, NULL, BAD_CAST "fullname", BAD_CAST  Get_fullname(list->items[i]));
          xmlNewChild(computer_gameNode, NULL, BAD_CAST "genre", BAD_CAST Get_genre(list->items[i]));
          sprintf(strBuf, "%i",Get_year(list->items[i])); 
          xmlNewChild(computer_gameNode, NULL, BAD_CAST "year", BAD_CAST strBuf);
          strBuf[0] = '\0';
          sprintf(strBuf, "%f",Get_rating(list->items[i]));  
          xmlNewChild(computer_gameNode, NULL, BAD_CAST "rating", BAD_CAST strBuf);
          strBuf[0] = '\0';
          xmlNode * classificationNode = xmlNewChild(computer_gameNode, NULL, BAD_CAST "classification", NULL);
          xmlNewChild(classificationNode, NULL, BAD_CAST "platform", BAD_CAST Get_platform(list->items[i]));
          xmlNewChild(classificationNode, NULL, BAD_CAST "numbers_of_player", BAD_CAST Get_numbers_of_player(list->items[i]));
      }

      xmlBuffer * buffer = xmlBufferCreate();
	    xmlNodeDump(buffer, NULL, (xmlNode *)doc, 0, 1);
      fprintf(fout, "%s", (const char *)buffer->content);
      fclose(fout);
	    xmlBufferFree(buffer);
     	xmlFreeDoc(doc);
    	xmlCleanupParser();
	    xmlMemoryDump();

}
void Storage_writeAsJson(const char * filePath, List * list) {
     char * jsonString ;
     FILE * fout = fopen(filePath,"w");
     for(int i = 0;i < List_count(list);i++) {
       json_t * json = json_object();
	     json_object_set_new(json, "fullname", json_string(Get_fullname(list->items[i])));
       json_object_set_new(json, "genre", json_string(Get_genre(list->items[i])));
	     json_object_set_new(json, "year", json_integer(Get_year(list->items[i])));
	     json_object_set_new(json, "rating", json_real(Get_rating(list->items[i])));
       json_t * classificationObj = json_object();
       json_object_set_new(classificationObj, "platform", json_string(Get_platform(list->items[i])));
       json_object_set_new(classificationObj, "numbers_of_player", json_string(Get_numbers_of_player(list->items[i])));
       json_object_set_new(json , "classification", classificationObj);
       
       jsonString = json_dumps(json, JSON_INDENT(2));
       fprintf(fout,"%s",jsonString);
       free(jsonString);
       json_decref(json);
	  
       }
       fclose(fout);
    
 
}

void FileProcessing_loadComputer_Game(Computer_Game  *game, xmlNode *xCurr) {
     for (xmlNode * xJ = xCurr->children; NULL != xJ ; xJ = xJ->next) {
          if (XML_ELEMENT_NODE == xJ->type) {
              char * content = (char *)xmlNodeGetContent(xJ);
              if(xmlStrcmp(xJ->name, BAD_CAST "fullname") == 0) {
                  Set_fullname(game,content);

               }
              if(xmlStrcmp(xJ->name, BAD_CAST "genre") == 0) {
                   Set_genre(game,content);
               }
		        	if(xmlStrcmp(xJ->name, BAD_CAST "year") == 0){
                    Set_year(game,atoi(content));
		        	}
		      
			   	    if(xmlStrcmp(xJ->name, BAD_CAST "rating") == 0){
				             Set_rating(game,atof(content));
				      }
              if (xmlStrcmp(xJ->name, BAD_CAST "classification") == 0) {
                 for(xmlNode *xCurNode = xJ->children; NULL != xCurNode; xCurNode = xCurNode->next) {
                    if (XML_ELEMENT_NODE == xCurNode->type) {
                       char * buff = (char *)xmlNodeGetContent(xCurNode);
                       if(xmlStrcmp(xCurNode->name, BAD_CAST "platform") == 0) {
                             Set_platform(game,buff);
                       }
                       if(xmlStrcmp(xCurNode->name, BAD_CAST "numbers_of_player") == 0) {
                       Set_numbers_of_player(game,buff);
                       }
                       xmlFree(buff);
                    }
                 }
               }		
               xmlFree(content);		
          }
       }

}

List * Storage_readAsXml(const char * filePath) {
  List * list = List_new();

  char text[1000] =  "";
  const char * xmlStr;
  xmlStr = readAllText(filePath,text);
  xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
	if(xDoc == NULL){
		printf("Error parsing xml");
		return NULL;
	}
  
	xmlNode * xRoot = xmlDocGetRootElement(xDoc);
	for(xmlNode * xCurr = xRoot->children; xCurr != NULL; xCurr = xCurr->next){
		if(xCurr->type == XML_ELEMENT_NODE) {
            Computer_Game * game = Computer_Game_new(" ", " ", 0, 0.0, " ", " ");
            FileProcessing_loadComputer_Game(game, xCurr);
            List_add(list, game);
		}
	}
  
  
	xmlFreeDoc(xDoc);
	xmlCleanupParser();
	xmlMemoryDump();
  return list;
}


List * Storage_readAsJson(const char * filePath) {
  List * list = List_new();
  char text[1000] =  "";
  const char * jsonStr;
  jsonStr = readAllText(filePath,text);
  json_error_t err;
	json_t * jsonArr = json_loads(jsonStr, 0, &err);
  int index = 0;
  json_t * value = NULL;
  json_array_foreach(jsonArr, index, value){
      char * fullname = (char *)json_string_value(json_object_get(value, "fullname"));
      char * genre = (char *)json_string_value(json_object_get(value, "genre"));
      int year = json_integer_value(json_object_get(value, "year"));
      float rating  = json_real_value(json_object_get(value, "rating"));
      json_t * classificationObj = json_object_get(value, "classification");
      char * platform = (char *)json_string_value(json_object_get(classificationObj, "platform"));
      char * numbers_of_player = (char *)json_string_value(json_object_get(classificationObj, "numbers_of_player"));
      Computer_Game *game = Computer_Game_new(fullname,genre,year,rating,platform,numbers_of_player);
      List_add(list,game);
  }
 json_decref(jsonArr);
 return list;
}    
