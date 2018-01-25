#ifndef STORAGE_H
#define STORAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "structure.h"
#include "list.h"

List * Storage_load(const char * fileName);
void Storage_save(const char * fileName, List * computer_game);


#endif
