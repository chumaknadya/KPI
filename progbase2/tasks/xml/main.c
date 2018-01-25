#include <string.h>
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "pensioner.h"
#include "xml.h"
#include <stdlib.h>


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
int main(void) {
    Pensioner * pensioner = Pensioner_new();
    char text[1000] =  "";
    const char * strg;
    strg = readAllText("Pensioner.xml",text);
    printf("%s",strg);

     XmlLoader_loadFromString(pensioner, strg);
     Pensioner_print(pensioner);

    char * string;
    char * output = XmlLoader_saveToString(pensioner,string);
    printf("%s",output);


	free(output);

	Pensioner_free(&pensioner);



    return 0;
}
