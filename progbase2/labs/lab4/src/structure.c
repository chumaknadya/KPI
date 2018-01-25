#include "../include/structure.h"




#define throw(MSG) assert(0 && MSG)


struct Classification {
    char platform [80];
    char numbers_of_player[80];
};
struct Computer_Game {
    char fullname[100];
    char genre[50];
    int year;
    float rating;
    Classification games;

};

void Set_fullname(Computer_Game * self, char *names) {
  if (self == NULL) throw ("There is NULL reference");
  if (names == NULL) throw ("There is NULL reference");
  if(strlen(names) == 0) {
      strcpy(names,"No Name");
  }
  if (self->fullname != NULL)  {
     strcpy(self->fullname,names);
  }



}
void Set_genre(Computer_Game * self, char *genre) {
  if (self == NULL) throw ("There is NULL reference");
  if (genre == NULL) throw ("There is NULL reference");
  if(strlen(genre) == 0) {
      strcpy(genre,"No genre");
  }
 if (self->genre != NULL)  {
     strcpy(self->genre,genre);
  }

}
void Set_platform(Computer_Game * self, char *platform) {
  if (self == NULL) throw ("There is NULL reference");
  if (platform == NULL) throw ("There is NULL reference");
  if(strlen(platform) == 0) {
      strcpy(platform,"No platform");
  }
  if (self->games.platform != NULL)  {
     strcpy(self->games.platform,platform);
  }

}
void Set_numbers_of_player(Computer_Game * self, char *numbers_of_player) {
  if (self == NULL) throw ("There is NULL reference");
  if (numbers_of_player == NULL) throw ("There is NULL reference");
  if(strlen(numbers_of_player) == 0) {
      strcpy(numbers_of_player,"No platform");
  }

  if (self->games.numbers_of_player != NULL)  {
     strcpy(self->games.numbers_of_player,numbers_of_player);
  }

}
void Set_year(Computer_Game * self, int year) {
  if (self == NULL) throw ("There is NULL reference");
  self->year = year;

}
void Set_rating(Computer_Game * self, float rating) {
    if (self == NULL)  throw ("There is NULL reference");

    
    self->rating = rating;

}

int  Get_year(Computer_Game *self) {
     if (self == NULL) throw ("There is NULL reference");


     return self->year;
}
float  Get_rating(Computer_Game *self) {
     if (self == NULL)  throw ("There is NULL reference");
     return self->rating;

}

char * Get_fullname(Computer_Game * self){

    //guards
     if (self == NULL)  throw ("There is NULL reference");
     if (self->fullname == NULL)  throw ("There is NULL reference");

     char * res = (char *)malloc(sizeof(strlen(self->fullname)));
     strcpy(res, self->fullname);
     return res;
}
char * Get_genre(Computer_Game * self) {

    //guards
     if (self == NULL) throw ("There is NULL reference");
     if (self->genre == NULL) throw ("There is NULL reference");

     char * res = (char *)malloc(sizeof(strlen(self->genre)));
     strcpy(res, self->genre);
     return res;
}
char * Get_platform(Computer_Game * self) {

    //guards
     if (self == NULL) throw ("There is NULL reference");
     if (self->games.platform == NULL) throw ("There is NULL reference");


     char * res = (char *)malloc(sizeof(strlen(self->games.platform)));
     strcpy(res, self->genre);
     return res;
}
char * Get_numbers_of_player(Computer_Game * self) {

    //guards
     if (self == NULL) throw ("There is NULL reference");
     if (self->games.numbers_of_player == NULL) throw ("There is NULL reference");

     char * res = (char *)malloc(sizeof(strlen(self->games.numbers_of_player)));
     strcpy(res, self->genre);
     return res;
}





Computer_Game * Computer_Game_new(char * fullname, char * genre, int year,float rating,char * platform,char * numbers_of_player) {
	Computer_Game * self = (Computer_Game *)malloc(sizeof(Computer_Game));
	strcpy(self->fullname, fullname);
	strcpy(self->genre, genre);
	self->year = year;
  self->rating = rating;
  strcpy(self->games.platform , platform);
  strcpy(self->games.numbers_of_player,numbers_of_player);

	return self;
}

void Computer_Game_free(Computer_Game  ** selfPtr) {
	free(*selfPtr);
	*selfPtr = NULL;
}

void Computer_Game_print(Computer_Game * self) {

	printf("%s %s %d %f %s %s",
		self->fullname,
        self->genre,
        self->year,
        self->rating,
        self->games.platform,
        self->games.numbers_of_player);
}

char * Computer_Game_toString(Computer_Game * self, char * buffer) {
  if (self == NULL || buffer == NULL)  return NULL;
  if (self == NULL) throw("NULL reference");
	sprintf(buffer, "%s %s %d %0.2f %s %s",
    self->fullname,
    self->genre,
    self->year,
    self->rating,
    self->games.platform,
    self->games.numbers_of_player);

	 return buffer;
}

Computer_Game * Computer_Game_newFromString(const char * str) {
  if ( str == NULL) return NULL;
	Computer_Game * self = Computer_Game_new("", "", 0,0.0 ,"","");
	sscanf(str, "%s %s %d %f %s %s",
    self->fullname,
    self->genre,
    &(self->year),
    &(self->rating),
    self->games.platform,
    self->games.numbers_of_player);
	return self;
}
/*Computer_Game *  Computer_Game_Set_field (Computer_Game * self) {
  char  keyDown_4;
  char str[16];
//  print_for_Set_field ();
    while (keyDown_4 != '0') {
        print_for_Set_field ();
        keyDown_4 = conGetChar();
        switch(keyDown_4) {
            case '1' : {
               fgets(str,16,stdin);
               str[strlen(str) -1] = '\0';
               Set_fullname(self, str);
            }break;
            case '2' : {
                fgets(str,16,stdin);
                str[strlen(str) -1] = '\0';
                Set_genre(self, str);
            }break;
            case '3' : {
                int counter = getInt();
                Set_year(self, counter);
            }break;
            case '4' : {
               fgets(str,10,stdin);
               float rait = 0;
               sscanf(str, "%f", &rait);
               Set_rating(self, rait);
            }break;
             case '5': {
               fgets(str,16,stdin);
               str[strlen(str) -1] = '\0';
               Set_platform(self, str);
            }break;
            case '6' : {
              fgets(str,16,stdin);
              str[strlen(str) -1] = '\0';
              Set_numbers_of_player(self, str);
            }break;

        }
    }
    return self;
 }
*/
