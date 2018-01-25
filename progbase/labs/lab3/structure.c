#include "header.h"
enum {  BUFFER_SIZE = 100 };


void prints(void) {
  printf("1.Видалити дані із вказаної позиції у масиві\n");
  printf("2.Перезаписати дані у вказаній позиції на нововведені\n");
  printf("3.Перезаписати тільки обране поле даних елемента на вказаній позиції\n");
  printf("4.Записати дані із одної структури у строку\n");
  printf("5.Записати дані із строки в структуру\n");
  printf("6.Записати масив структур в текст\n");
  printf("7.Знайти всі ігри із рейтингом меншим за Х\n");
  printf("8.Перезапис структури по індексу даними із іншої структури\n");
  printf("9.Видалити структуру із масиву структур\n");
  printf("0.Натисніть ,щоб повернутися до головного меню\n");


}
int valid_Computer_Reverse_record1 (char *string){
	int checker = 0;
	int minCheck = 0;


	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '.')
			minCheck++;
		if (isalpha (string[i]) == 0 && minCheck > 1)
			checker = 1;
		if (isalpha (string[i]) == 0 && string[i] != '.')
			checker = 1;
	}

	return checker;
}

int valid_Computer_Reverse_record2 (char *string){
	int checker = 0;

	for (int i = 0; string[i] != '\0'; i++)
	{
		if (isdigit (string[i])  )
			checker = 1;
	}
	return checker;
}


int valid_Computer_Reverse_record (char *string){
	int checker = 0;
	int minCheck = 0;
	if (string[0] == '\n')
		checker = 1;
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '\n')
			string[i] = '\0';
  }

	for (int i = 0; string[i] != '\0'; i++)
	{

		if (string[i] == '-')
			minCheck++;
		if (isalpha (string[i]) == 0 && minCheck > 1)
			checker = 1;
		if (isalpha (string[i]) == 0 && string[i] != '-')
			checker = 1;
	}

	return checker;
}


int   Computer_Game_REVERSE_record(struct Computer_Game * st,int count ,char *string,int checker) {
  if (checker == 0){
      sscanf(string," %s %s %d %f %s %s\n",
      st->fullname, st->genre, &(st->year), &(st->rating), st->games.platform, st->games.numbers_of_player);
  } else {
    return 1;
  }
  return 0;
}

int valid_Game_record(int count){
  int number  = 0;
  int checker = 0;
  int counter = 0;
  while ( checker != 1) {
    printf ("Введіть номер структури  для запису в строку: ");
    number = getInt();
    if (number > count || number <= 0) {

       counter ++;

    } else {
      checker = 1;
    }
    if (counter > 0 && checker == 0){
      printf("Попробуйте ще раз\n");
    }

  }
  return number;
}

void Computer_Game_record(struct Computer_Game * st,char *string ,int count,int number) {
  for (int i = 0; i < count;i ++) {
    if (i == (number - 1)){
      sprintf(string,"%s %s %d %0.02f %s %s",
      st[i].fullname, st[i].genre, st[i].year,st[i].rating, st[i].games.platform, st[i].games.numbers_of_player);
      printf("%s",string);
    }
  }


}
void arrays_of_structers(struct Computer_Game * st,char *text,int count) {
  for (int i = 0;i < count; i ++) {
    sscanf(text,"%s %s %d %f %s %s",
    st[i].fullname, st[i].genre, &st[i].year,&st[i].rating, st[i].games.platform, st[i].games.numbers_of_player);

  }
    printf("Успішно записано");

}

void text(struct Computer_Game * st,char *text,int count) {
  for (int i = 0;i < count; i ++) {
    sprintf(text,"Назва: %s Жанр: %s Рік: %d Рейтинг: %f Платформа: %s Кількість: %s\n",
    st[i].fullname, st[i].genre, st[i].year,st[i].rating, st[i].games.platform, st[i].games.numbers_of_player);
    printf("Назва: %s Жанр: %s Рік: %d Рейтинг: %f Платформа: %s Кількість: %s\n",
    st[i].fullname, st[i].genre, st[i].year,st[i].rating, st[i].games.platform, st[i].games.numbers_of_player);
  }


}

void print_ratingX(struct Computer_Game * st,int count,float number){
  int counter = 0;
  for (int i = 0;i < count;i ++) {
    if (st[i].rating <= number){
          count ++;
          printf("Назва гри: %s\n",st[i].fullname);

    }
  }
  if (counter == 0){
    printf("Не знайдено");
  }
}
 void all_structure_ratingX(struct Computer_Game * st,int count,float number){


  int counter = 0;
   for (int i = 0;i < count;i ++) {
     if (st[i].rating <= number){
         printf("Назва гри: %s\n",st[i].fullname);
         counter ++;
     }
   }
   if (counter == 0){
     printf("Не знайдено");
   }

 }

 int  valid_removing(int count) {
   int number;
   int checker = 0;
   int counter = 0;
   while ( checker != 1) {
     printf("Введіть номер структури,який ви хочете видалити: ");
     number = getInt();
     if (number > count || number <= 0) {

        counter ++;

     } else {
       checker = 1;
     }
     if (counter > 0 && checker == 0){
       printf("Попробуйте ще раз\n");
     }
   }

   return number;
 }
 void remove_array(struct Computer_Game *st,int count,int number){




        strcpy(st[number-1].fullname, "") ;
        strcpy(st[number-1].genre, "") ;
        st[number-1].year = 0;
        st[number-1].rating = 0;
        strcpy(st[number-1].games.platform, "") ;
        strcpy(st[number-1].games.numbers_of_player, "") ;





 }

int valid_recording1(int count){

     int checker = 0;
     int counter = 0;
     int number1;
     while ( checker != 1) {
     printf("Введіть номер  структури  для запису даних: ");
       number1 = getInt();
       if (number1 > count || number1 <= 0) {

          counter ++;

       } else {
         checker = 1;
       }
       if (counter > 0 && checker == 0){
         printf("Попробуйте ще раз\n");
       }


     }
  return number1;
}


int valid_recording2(int count){
  int checker = 0;
  int counter = 0;
  int number2;
  while ( checker != 1) {
   printf("Введіть номер структури з якої ви хочете перезаписати дані: ");
    number2 = getInt();
    if (number2 > count || number2 <= 0) {

       counter ++;

    } else {
      checker = 1;
    }
    if (counter > 0 && checker == 0){
      printf("Попробуйте ще раз\n");
    }


  }

  return number2;
}



 void rerecording(struct Computer_Game *st,int count,int number1,int number2){
             strcpy(st[number1-1].fullname,st[number2-1].fullname ) ;
             strcpy(st[number1-1].genre, st[number2-1].genre) ;
             st[number1-1].year = st[number2-1].year;
             st[number1-1].rating = st[number2-1].rating;
             strcpy(st[number1-1].games.platform, st[number2-1].games.platform) ;
             strcpy(st[number1-1].games.numbers_of_player, st[number2-1].games.numbers_of_player) ;





 }


void removing (struct Computer_Game *st,int count,int number) {

   char down;
  // int box_width = 87;


       printf("1.Видалити дані з поля /назва/\n");
       printf("2.Видалити дані з поля /жанр/ \n");
       printf("3.Видалити дані з поля /рік/\n");
       printf("4.Видалити дані з поля /рейтинг/\n");
       printf("5.Видалити дані з поля /платформа/\n");
       printf("6.Видалити дані з поля /кількість гравців/\n");
       printf("Ваш вибір: \n");
       down = conGetChar();
        switch(down) {
        case '1':{ strcpy(st[number-1].fullname, "");} break;
        case '2':{ strcpy(st[number-1].genre, "");}break;
        case '3':{ st[number-1].year = 0;}break;
        case '4':{ st[number-1].rating = 0;}break;
        case '5':{ strcpy(st[number-1].games.platform, ""); }break;
        case '6':{ strcpy(st[number-1].games.numbers_of_player, "");}break;


   }

}




 void rerecording_1 (struct Computer_Game *st,int count,int number) {

   char kyDown;
   int maximum_counter = 100;
   //int box_width = 87;
   char buffer[BUFFER_SIZE];
   for ( int i= 0;i < count;i++ ){
     if (i == number - 1){


       printf("1.Перезаписати дані з поля /назва/\n");
       printf("2.Перезаписати дані з поля /жанр/ \n");
       printf("3.Перезаписати дані з поля /рік/\n");
       printf("4.Перезаписати дані з поля /рейтинг/\n");
       printf("5.Перезаписати дані з поля /платформа/\n");
       printf("6.Перезаписати дані з поля /кількість гравців/\n");
       printf("Ваш вибір: \n");
       kyDown = conGetChar();
       switch(kyDown) {
        case '1':{
          fgets(st[i].fullname, maximum_counter, stdin);
          st[i].fullname[strlen(st[i].fullname) - 1] = '\0';
        } break;
        case '2':{
          fgets(st[i].genre, maximum_counter, stdin);
          st[i].genre[strlen(st[i].genre) - 1] = '\0';
        }break;
        case '3':{
          st[i].year = 0;
          fgets(buffer,maximum_counter,stdin);
          sscanf(buffer,"%d",&(st + i)->year);
        }break;
        case '4':{
          st[i].rating = 0;
          fgets(buffer,maximum_counter,stdin);
          sscanf(buffer,"%f",&(st + i)->rating);
        }break;
        case '5':{
          fgets(st[i].games.platform, maximum_counter, stdin);
          st[i].games.platform[strlen(st[i].games.platform) - 1] = '\0';
        }break;
        case '6':{
          fgets(st[i].games.numbers_of_player, maximum_counter, stdin);
          st[i].games.numbers_of_player[strlen(st[i].games.numbers_of_player) - 1] = '\0';
        }break;
      }
     }
   }


 }

 void print_array(struct Computer_Game *st, int count){
   for(int i = 0;i < count; i++){
     printf("Назва: %s ",st[i].fullname);
     printf(" Жанр: %s ",st[i].genre);
     printf(" Рік: %d ",st[i].year);
     printf(" Рейтинг: %0.02f ",st[i].rating);
     printf(" Платформа: %s ",st[i].games.platform);
     printf(" Кількість: %s\n",st[i].games.numbers_of_player);


  }

 }

int   valid_rerecord (int count){
  int number;
  int checker = 0;
  int counter = 0;
  while ( checker != 1) {
   printf("Введіть номер структури,яку ви хочете перезаписати: ");
    number = getInt();
    if (number > count || number <= 0) {

       counter ++;

    } else {
      checker = 1;
    }
    if (counter > 0 && checker == 0){
      printf("Попробуйте ще раз\n");
    }


  }
  return number;
 }


 void rerecording_2(struct Computer_Game *st, int count,int number) {


   int maximum_counter = 100;
   char buffer[BUFFER_SIZE];
   for ( int i= 0;i < count;i++ ){
     if (i == number - 1){

       printf("Введіть назву  гри: ");
       fgets((st + i)->fullname,maximum_counter,stdin);
       (st + i)->fullname[strlen((st + i)->fullname) -1] = '\0';
       printf("Введіть  жанр  гри: ");
       fgets((st + i)->genre,maximum_counter,stdin);
       (st + i)->genre[strlen((st + i)->genre) -1] = '\0';
       printf("Введіть рік створення  гри: ");
       fgets(buffer,maximum_counter,stdin);
       sscanf(buffer,"%d",&(st + i)->year);
       printf("Введіть  рейтинг  гри : ");
       fgets(buffer,maximum_counter,stdin);
       sscanf(buffer,"%f",&(st + i)->rating);
       printf("Введіть  ігрову платформу  гри : ");
       fgets((st + i)->games.platform,maximum_counter,stdin);
       (st + i)->games.platform[strlen((st + i)->games.platform) -1] = '\0';
       printf("Введіть  кількість гравців  гри : ");
       fgets((st + i)->games.numbers_of_player,maximum_counter,stdin);
       (st + i)->games.numbers_of_player[strlen((st + i)->games.numbers_of_player) -1] = '\0';


     }
   }



 }
