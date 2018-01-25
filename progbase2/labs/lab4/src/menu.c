#include "../include/menu.h"

enum {  BUFFER_SIZE = 100 };
int  input_position_of_element(int position,List * self) {
  position = getInt();
  while (position < 0 || position > List_count(self)) {
     printf("Спробуйте ще раз\n");
     position = getInt();
  }
  return position;
}
int input_year(int counter) {
  counter = getInt();
  while (counter < 0 || isalpha(counter) ) {
     printf("Спробуйте ще раз\n");
     counter = getInt();
  }
  return counter;
}
float  input_rating(float rating) {
  printf("Введіть рейтинг\n");
  char str[45];
  fgets(str,10,stdin);
  rating = 0;
  sscanf(str, "%f", &rating);
  while(rating < 0) {
    printf("Попробуйте ще раз\n");
    fgets(str,10,stdin);
    sscanf(str, "%f", &rating);
  }
  return rating;
}

Computer_Game *  Computer_Game_Set_field (Computer_Game * self) {
       char  keyDown_4;
       char str[16];
       print_for_Set_field ();

        printf("Введіть номер операції\n");
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
                while (counter < 0 || isalpha(counter)) {
                  printf("Спробуйте ще раз\n");
                  counter = getInt();
                }
                Set_year(self, counter);
            }break;
            case '4' : {
               fgets(str,10,stdin);
               float rait = 0;
               sscanf(str, "%f", &rait);
               while(rait < 0) {
                 printf("Попробуйте ще раз\n");
                 fgets(str,10,stdin);
                 sscanf(str, "%f", &rait);
               }
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
        return self;
 }
void print_list(List * self) {

  for (int i = 0; i < List_count(self); i++) {
          conMove(12 + i,35);
          Computer_Game_print(List_get(self, i));
          printf("\n");
  }
}
void print_for_Set_field (void) {
 printf("1.Замінити поле <ім'я>\n");
 printf("2.Замінити поле <жанр>\n");
 printf("3.Замінити поле <рік>\n");
 printf("4.Замінити поле <рейтинг>\n");
 printf("5.Замінити поле <платформа>\n");
 printf("6.Замінити поле <кількість гравців>\n");
 printf("0.Перейти до іншого завдання\n");


}


void Set_Computer_Game_data(Computer_Game * self) {

  char str[16];

      printf("Введіть ім'я\n");
      fgets(str,16,stdin);
      str[strlen(str) -1] = '\0';
      Set_fullname(self, str);
      printf("Введіть жанр\n");
      fgets(str,16,stdin);
      str[strlen(str) -1] = '\0';
      Set_genre(self, str);
      printf("Введіть рік\n");
      int count  = getInt();
      Set_year(self, count);
      printf("Введіть рейтинг\n");
      fgets(str,10,stdin);
      float rait = 0;
      sscanf(str, "%f", &rait);
      while(rait < 0) {
        printf("Попробуйте ще раз\n");
        fgets(str,10,stdin);
        sscanf(str, "%f", &rait);
      }
      Set_rating(self, rait);
      printf("Введіть платформу\n");
      fgets(str,16,stdin);
      str[strlen(str) -1] = '\0';
      Set_platform(self, str);
      printf("Введіть кількість гравців\n");
      fgets(str,16,stdin);
      str[strlen(str) -1] = '\0';
      Set_numbers_of_player(self, str);
}

int valid_input_count(void) {
 int count;
 int number6 = 5;
 printf ("\tВи можете охарактеризувати не більше 5 ігор\n");
 printf ("\tВиберіть кількість ігор ,які ви бажаєте охарактеризувати: ");
 count = getInt();

 if (count > number6 || count <= 0) {
     printf("Попробуйте ще раз\n");
     count = getInt();
  }
  return count;
  }

void menu_main_print (void) {

  printf("1.Створити новий _список елементів типу Комп'ютерна гра\n");
  printf("2.Зчитати список елементів типу Комп'ютерна гра із дискового файлу\n");
  printf("3.Зберегти змінений список елементів на файлову систему\n");
  printf("0.Вихід з програми\n");
  puts ("Введіть номер операції: ");


}
void menu_print_tasks (void) {
  printf("1.Додати новий елемент на довільну позицію\n");
  printf("2.Видалити елемент із вказаної позиції.\n");
  printf("3.Обрати довільний елемент і замінити деяке значення його полів на нові\n");
  printf("4.Знайти всі ігри із рейтингом меншим за Х\n");
  printf("0.Вихід з таску \n");

}

int menu (void) {

    int box_left = 0;
    int box_top = 5;
    int box_width = 100;
    int box_height = 0;
    int x_width_name = 100;
    int x_height_name = 10;
    int y_console_height = 40;
    // print_drawing();

    conClear();

    prebox(x_width_name,x_height_name,BG_BLACK);
    conMove(3,44);
    printf("MENU\n");
    conReset();
    conMove(10,0);
    box(box_width, box_left, box_top,box_height, y_console_height,BG_RED);

    Computer_Game * games = Computer_Game_new(" ", " ", 0,0.0," "," ");
    Computer_Game * input_games;

//  release = ( Computer_Game*)malloc(8*sizeof(Computer_Game));
    List * computer_games = Storage_load("classification.txt");
    List * input_computer_games = List_new();

    char  keyDown_1;
    while (keyDown_1 != '0') {
          clearLine(' ',6,box_width-1,40,BG_RED);
          conMove(6,1);
          print_drawing();
          menu_main_print();
          keyDown_1 = conGetChar();
          switch (keyDown_1) {
              case '1': {
                  clearLine(' ',6,box_width-1,40,BG_RED);
                  conMove(6,1);
                  menu_print_tasks();
                  printf("Введіть кількість структур,які ви хочете додати\n");
                  int count = getInt();
                  for (int i = 0; i < count; i ++) {
                         input_games = Computer_Game_new(" ", " ", 0,0.0," "," ");
                         Set_Computer_Game_data(input_games);
                         clearLine(' ',11,box_width-1,40,BG_RED);
                         conMove(11,1);
                         List_add(input_computer_games,input_games);

                   }
                  char  keyDown_2 ;
                  while (keyDown_2 != '0') {
                      conMove(12,1);
                      printf("Введіть номер операції\n");
                      print_list(input_computer_games);
                      keyDown_2 = conGetChar();
                      switch(keyDown_2) {
                            case '1': {
                              printf("Введіть позицію list,для якого ви хочете додати list \n");
                              int position = input_position_of_element(position,input_computer_games);
                              input_games = Computer_Game_new(" ", " ", 0,0.0," "," ");
                              Set_Computer_Game_data(input_games);
                              List_insert(input_computer_games, position, input_games);
                              clearLine(' ',11,box_width-1,20,BG_RED);
                              conMove(12,1);
                              print_list(input_computer_games);
                            }break;
                            case '2': {
                              printf("Введіть позицію list,з якого ви хочете вилучити list \n");
                              int position = input_position_of_element(position,input_computer_games);
                              List_removeAt(input_computer_games, position);
                              clearLine(' ',11,box_width-1,20,BG_RED);
                              conMove(12,1);
                              print_list(input_computer_games);

                            }break;
                            case '3': {
                              printf("Введіть позицію list,для якого ви хочете зробити зміни \n");
                              int position = input_position_of_element(position,input_computer_games);
                              input_games = Computer_Game_Set_field (List_get(input_computer_games, position));
                              clearLine(' ',11,box_width-1,20,BG_RED);
                              conMove(12,1);
                              print_list(input_computer_games);

                            }break;
                            case '4': {

                              float rait = input_rating(rait);
                              input_computer_games =  List_filter_by_rating(input_computer_games,rait);
                              clearLine(' ',11,box_width-1,20,BG_RED);
                              conMove(12,1);
                              print_list(input_computer_games);

                            }break;
                     }
                   }
              }break;
               case '2': {
                 clearLine(' ',6,box_width-1,40,BG_RED);
                 conMove(6,1);
                 menu_print_tasks();
                 char  keyDown_3;
                 while (keyDown_3 != '0') {
                    conMove(12,1);
                    printf("Введіть номер операції\n");
                    keyDown_3 = conGetChar();
                    print_list(computer_games);

                    switch(keyDown_3) {
                          case '1': {
                            printf("Введіть позицію list,для якого ви хочете додати list \n");
                            int position =  input_position_of_element(position,computer_games);
                            Set_Computer_Game_data(games);
                            List_insert(computer_games, position, games);
                            clearLine(' ',11,box_width-1,26,BG_RED);
                            conMove(12,1);
                            print_list(computer_games);


                          }break;
                          case '2': {
                            printf("Введіть позицію list,з якого ви хочете вилучити list \n");
                            int position =  input_position_of_element(position,computer_games);
                            List_removeAt(computer_games, position);
                            clearLine(' ',11,box_width-1,20,BG_RED);
                            conMove(12,1);
                            print_list(computer_games);

                          }break;
                          case '3': {
                            printf("Введіть позицію list,для якого ви хочете зробити зміни \n");
                            int position = input_position_of_element(position,computer_games);
                            games = Computer_Game_Set_field (List_get(computer_games, position));
                            clearLine(' ',11,box_width-1,20,BG_RED);
                            conMove(12,1);
                            print_list(computer_games);



                          }break;
                          case '4': {

                            float rait = input_rating(rait);
                            computer_games =  List_filter_by_rating(computer_games,rait);
                            clearLine(' ',11,box_width-1,20,BG_RED);
                            conMove(12,1);
                            print_list(computer_games);
                            }break;

                   }

                 }

              }break;

              case '3': {
                    clearLine(' ',6,box_width-1,40,BG_RED);
                    conMove(6,1);
                    char str[16];
                    printf("Введіть назву файлу для збереження даних\n");
                    fgets(str,16,stdin);
                    Storage_save(str, input_computer_games);
                    Storage_save(str, computer_games);

              } break;

          }
    }
    conMove(60,1);

    List_free(&computer_games);
    List_free(&input_computer_games);
    Computer_Game_free(&games);
    Computer_Game_free(&input_games);



  return 0;
}
