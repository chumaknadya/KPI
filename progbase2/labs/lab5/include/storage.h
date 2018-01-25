#ifndef STORAGE_H
#define STORAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#include <list.h>



List * Storage_load(const char * fileName);
void Storage_save(const char * fileName, List * computer_game);

void Storage_writeAsXml(const char * filePath, List * list);
List * Storage_readAsXml(const char * filePath);

void Storage_writeAsJson(const char * filePath, List * list);
List * Storage_readAsJson(const char * filePath);
#endif
