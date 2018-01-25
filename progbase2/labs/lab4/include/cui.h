#ifndef CUI_H
#define CUI_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pbconsole.h>
#include <progbase.h>
#include <time.h>
#include <limits.h>

void prebox(int x_width_name,int x_height_name,enum conAttribute_e color);
void box(int box_width,int box_left,int box_top,int box_height,int y_console_height,enum conAttribute_e color);
void clearLine(char c,int y,int x,int num,enum conAttribute_e color);
void print_drawing(void);
#endif
