
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pbconsole.h>
#include <progbase.h>
#include <time.h>
#include <limits.h>


int menu(void);
void clearLine(char c,int y,int x,int num,enum conAttribute_e color);
void prebox(int x_width_name,int x_height_name,enum conAttribute_e color);
void box(int box_width,int box_left,int box_top,int box_height,int y_console_height,enum conAttribute_e color);
struct classification {
    char platform [80];
    char numbers_of_player[80];
};
struct Computer_Game {
    char fullname[100];
    char genre[50];
    int year;
    float rating;
    struct classification games;

};
struct Computer_Game *release;
void print_array(struct Computer_Game *st, int count);
int print_in_text_files(int count,struct Computer_Game *st);
int load (struct Computer_Game *st);
void prints(void);
int Computer_Game_REVERSE_record(struct Computer_Game * st,int count ,char *string,int checker);
void Computer_Game_record(struct Computer_Game * st,char *string ,int count,int number);
void all_structure_ratingX(struct Computer_Game * st,int count,float number);
void text(struct Computer_Game * st,char *text,int count);
void arrays_of_structers(struct Computer_Game * st,char *text,int count);
void remove_array(struct Computer_Game *st,int count,int number);
void rerecording_1 (struct Computer_Game *st,int count,int number);
void rerecording(struct Computer_Game *st,int count,int number1,int number2);
void rerecording_2(struct Computer_Game *st, int count,int number);
void input_data(struct Computer_Game *st,int count);
void removing (struct Computer_Game *st,int count,int number);
int valid_removing(int count);
int   valid_rerecord (int count);
int valid_Game_record(int count);
int valid_recording1(int count);
int valid_recording2(int count);
int valid_Computer_Reverse_record (char *string);
int valid_Computer_Reverse_record1 (char *string);
int valid_Computer_Reverse_record2 (char *string);
void print_ratingX(struct Computer_Game * st,int count,float number);
