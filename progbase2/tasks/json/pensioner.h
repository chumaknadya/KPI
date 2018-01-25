#ifndef PENSIONER_H
#define PENSIONER_H


//typedef struct Grandchildren Grandchildren;
//typedef struct Pensioner Pensioner;
typedef struct {
	char * name;

} Grandchildren;

typedef struct {
	char * 	name;
	char * 	surname;
	int 	year;
	float	GPA; 
	Grandchildren ** grandchildren;
    int grandchildren_length;
} Pensioner;

Pensioner * Pensioner_new(void);
Pensioner * Pensioner_addNewGrandchildren(Pensioner * self, Grandchildren * newGrandchildren);
void Pensioner_print(Pensioner * self);
void Pensioner_free(Pensioner ** self);

Grandchildren * Grandchildren_new(void);
void Grandchildren_free(Grandchildren ** self);


int  Get_year(Pensioner *self);
float  Get_GPA(Pensioner *self);
char * Get_name(Pensioner * self);
char * Get_surname(Pensioner * self);
char * Get_grandchildren_name(Grandchildren * self);

#endif
