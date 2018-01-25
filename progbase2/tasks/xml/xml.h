#ifndef XML_H
#define XML_H
#include "pensioner.h"

char * XmlLoader_saveToString(const Pensioner * pensioner,char * str);
void XmlLoader_loadFromString(Pensioner * pensioner, const char * xmlStr); 

#endif