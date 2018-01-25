#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "pensioner.h"
#include "json.h"

#include <jansson.h>


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
    strg = readAllText("Pensioner.json",text);
    printf("%s",strg);
 	//char * text = Storage_readTextFromFile("Pensioner.json");
    JsonLoader_loadFromString(pensioner, strg);
    Pensioner_print(pensioner);
	//free(text);
	
    char * string;
    char * str = JsonLoader_saveToString(pensioner,string);
    printf("%s",str);
 //   Storage_writeToFile("result.json", str);
    free(str);
		
	Pensioner_free(&pensioner);
	return 0;
}




