#ifndef MODULE_H
#define MODULE_H

#include "list.h"
#include "structure.h"

typedef enum {
	MODULE_ERR_OK,
	MODULE_ERR_LIST_EMPTY,
	ERROR
} Module_ErrorCode;

/**
	if fails, sets errno to error code of type Module_ErrorCode
**/
int Module_min(List * list);

#endif
