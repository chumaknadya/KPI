#include "header.h"
enum {  BUFFER_SIZE = 100 };


int print_in_text_files(int count,struct Computer_Game *st) {


  int LENNAME = 30;
  char readFileName[LENNAME];
  fgets(readFileName, 30, stdin);



   FILE * fout = fopen(readFileName, "w");

   if (fout == NULL) {
    	printf("Error opening file\n");
    	return EXIT_FAILURE;
	 }

   for (int i = 0;i < count;i++ ) {

      fprintf(fout,"%s ",st[i].fullname);
      fprintf(fout,"%s ",st[i].genre);
      fprintf(fout,"%d ",st[i].year);
      fprintf(fout,"%0.02f ",st[i].rating);
      fprintf(fout,"%s ",st[i].games.platform);
      fprintf(fout,"%s\n",st[i].games.numbers_of_player);

   }
   fclose(fout);
return 0;
}
int load (struct Computer_Game *st) {

 char buffer[BUFFER_SIZE];

  FILE *fin = fopen("classification.txt","r");

  if (fin == NULL) {
    printf ("Помилка зчитування з файлу");
    return EXIT_FAILURE;
  }
  int count = 0;
  while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
   count++;
  }
 //fseek(fin,0,SEEK_SET);
 rewind(fin);

fflush(stdout);
 for ( int i = 0; i < 3;i++) {

fflush(stdout);
       fscanf(fin,"%s %s %d %f %s %s",
     st[i].fullname, st[i].genre, &(st[i].year),&(st[i].rating), st[i].games.platform,st[i].games.numbers_of_player);
     fflush(stdout);

  }
/*for (int i = 0; i < count;i++){
  printf("Назва: %s Жанр: %s Рік: %d Рейтинг: %f Платформа:  %s Кількість: %s\n",st[i].fullname, st[i].genre, st[i].year,st[i].rating, st[i].games.platform,st[i].games.numbers_of_player);
}*/





  fclose(fin);
  return 0;
}
