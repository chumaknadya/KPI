#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pensioner.h"
/*struct Grandchildren{
	char * name;

};

struct Pensioner {
	char * 	name;
	char * 	surname;
	int 	year;
	float	GPA; 
	Grandchildren ** grandchildren;
    int grandchildren_length;
};
*/

int  Get_year(Pensioner *self) {
     if (self == NULL) {
         printf("There is NULL reference\n");
     } 
    
   
     return self->year;
}
float  Get_GPA(Pensioner *self) {
     if (self == NULL) {
         printf("There is NULL reference\n");
     } 
     return self->GPA;
  
}

char * Get_name(Pensioner * self){

    //guards
     if (self == NULL) {
         printf("There is NULL reference\n");
     }
     if (self->name == NULL) {
         printf("Can not set fullname\n");
     }

     char * res = (char *)malloc(sizeof(strlen(self->name)));
     strcpy(res, self->name);
     return res;
}
char * Get_surname(Pensioner * self) {

    //guards
     if (self == NULL) {
         printf("There is NULL reference\n");
     }
     if (self->surname == NULL) {
         printf("Can not set genre\n");
     }

     char * res = (char *)malloc(sizeof(strlen(self->surname)));
     strcpy(res, self->surname);
     return res;
}
char * Get_grandchildren_name(Grandchildren * self) {

    //guards
     if (self == NULL) {
         printf("There is NULL reference\n");
     }
     if (self->name == NULL) {
         printf("Can not get grandchildren name\n");
     }

     char * res = (char *)malloc(sizeof(strlen(self->name)));
     strcpy(res, self->name);
     return res;
}




Pensioner * Pensioner_new(void) {
    Pensioner *pensioner = (Pensioner *)malloc(sizeof( Pensioner ));
    pensioner->name = NULL;
    pensioner->surname = NULL;
    pensioner->year = 0;
    pensioner->GPA = 0;
    pensioner->grandchildren = NULL;
    pensioner->grandchildren_length = 0;
    return pensioner;
   
}

Pensioner * Pensioner_addNewGrandchildren(Pensioner * self, Grandchildren * newGrandchildren) {
    if(self->grandchildren == 0){
		self->grandchildren = (Grandchildren **)malloc(sizeof(Grandchildren *));
		self->grandchildren[0] = newGrandchildren;
		self->grandchildren_length = 1;
		return self;
	}
	self->grandchildren_length ++;
	self->grandchildren = (Grandchildren **)realloc(self->grandchildren, sizeof(Grandchildren *) * self->grandchildren_length);
	self->grandchildren[self->grandchildren_length - 1] = newGrandchildren;
	return self;
}


void Pensioner_print(Pensioner * self) {
      printf("\t%10s: %s\n", "name", self->name);
	  printf("\t%10s: %s\n", "surname", self->surname);
	  printf("\t%10s: %i\n", "year", self->year);
	  printf("\t%10s: %f\n", "GPA", self->GPA);
      for(int i = 0; i < self->grandchildren_length; i++){
	 	    printf("\t%10s: %s \n", "grandchildren", self->grandchildren[i]->name);
	  }
	 
}
void Pensioner_free(Pensioner ** self) {
     if((*self)->name != NULL) free((*self)->name);
     if((*self)->surname != NULL) free((*self)->surname);
	 for(int i = (*self)->grandchildren_length - 1; i >= 0; i--) Grandchildren_free(&((*self)->grandchildren[i]));
     if((*self)->grandchildren != NULL) free((*self)->grandchildren);
 	 free(*self);
	 self = NULL;
}

Grandchildren * Grandchildren_new(void){
    Grandchildren * self = (Grandchildren *)malloc(sizeof(Grandchildren));
	self->name = NULL;
    return self;
}
void Grandchildren_free(Grandchildren ** self) {
    if((*self)->name != NULL) free((*self)->name);
	free(*self);
	self = NULL;
}