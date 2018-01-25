#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <progbase.h>
#include <pbconsole.h>
#include "storage.h"
#include "list.h"
#include "cui.h"
#include "structure.h"



int menu (void);
void print_list(List * self);
void print_for_Set_field (void);
void menu_print_tasks (void);
void menu_main_print (void);
int valid_input_count(void);
void print_for_Set_field (void);
void Set_Computer_Game_data(Computer_Game * self);
Computer_Game *  Computer_Game_Set_field (Computer_Game * self);



#endif
