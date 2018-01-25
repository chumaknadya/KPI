#include "../include/storage.h"

enum {  BUFFER_SIZE = 100 };

List * Storage_load(const char * fileName) {
	FILE *fin = fopen(fileName,"r");
  if (fin == NULL) {
    printf("There is NULL reference\n");
  }
  List * list = List_new();
  char buffer[BUFFER_SIZE];

  while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
      List_add(list, Computer_Game_newFromString(buffer));

  }
  rewind(fin);
  fclose(fin);
	return list;
}

void Storage_save(const char * fileName, List * computer_game) {
	printf("List saved to %s\n", fileName);
  FILE * fin = fopen(fileName,"w");
	char buffer[100];
	for (int i = 0; i < List_count(computer_game); i++) {
		Computer_Game * c = (Computer_Game *)List_get(computer_game, i);
		char * strPtr = Computer_Game_toString(c, buffer);
    fprintf(fin,"%s\n",strPtr);
		printf("\t%i) %s\n", i, strPtr);
	}
  fclose(fin);
}
