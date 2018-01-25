

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <progbase.h>
#include <assert.h>
#include <stdbool.h>


typedef struct Computer_Game Computer_Game;
typedef struct Classification Classification;
bool Computer_Game_is_equals_fullname(Computer_Game * game1,Computer_Game * game2);
bool Computer_Game_is_equals_genre(Computer_Game * game1,Computer_Game * game2);
bool Computer_Game_is_equals_platform(Computer_Game * game1,Computer_Game * game2);
bool Computer_Game_is_equals_numbers_of_player(Computer_Game * game1,Computer_Game * game2);
bool Computer_Game_is_equals_year(Computer_Game * game1,Computer_Game * game2);
bool Computer_Game_is_equals_rating(Computer_Game * game1,Computer_Game * game2);
bool Computer_Game_is_equals(Computer_Game * game1,Computer_Game * game2);

Computer_Game * Computer_Game_new(char * fullname, char * genre, int year,float rating,char * platform,char * numbers_of_player);
void Computer_Game_free(Computer_Game  ** selfPtr);
void Computer_Game_print(Computer_Game * self);
char * Computer_Game_toString(Computer_Game * self, char * buffer);
Computer_Game * Computer_Game_newFromString(const char * str);
Computer_Game *  Computer_Game_Set_field (Computer_Game * self);

void Set_fullname(Computer_Game * self, char *names);
void Set_genre(Computer_Game * self, char *genre);
void Set_platform(Computer_Game * self, char *platform);
void Set_numbers_of_player(Computer_Game * self, char *numbers_of_player);
void Set_year(Computer_Game * self, int year);
void Set_rating(Computer_Game * self, float rating);



char * Get_fullname(Computer_Game * self);
char * Get_platform(Computer_Game * self);
char * Get_numbers_of_player(Computer_Game * self);
char * Get_genre(Computer_Game * self);
float  Get_rating(Computer_Game *self);
int  Get_year(Computer_Game *self);
