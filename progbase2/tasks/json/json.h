
#ifndef JSON_H
#define JSON_H
#include "pensioner.h"
#include <string.h>
#include <stdio.h>
#include <jansson.h>


void JsonLoader_loadFromString(Pensioner * pensioner, const char * jsonString);

char * JsonLoader_saveToString(const Pensioner * pensioner,char * jsonString);
#endif 


