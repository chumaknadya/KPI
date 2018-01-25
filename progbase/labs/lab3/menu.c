#include "header.h"

enum {  BUFFER_SIZE = 100 };




void clearLine(char c,int y,int x,int num,enum conAttribute_e color) {
  int i,j;
  conSetAttr(color);
  for (j = 0; j < num; j ++) {

    for (i = 0; i < x; i ++) {
      conMove(y+j,1+i);
      putchar(c);
    }
  }
}
void prebox(int x_width_name,int x_height_name,enum conAttribute_e color) {
  conSetAttr(color);
  int x,y;
  for (x = 0;x < x_width_name;x ++) {
    for (y = 0;	y < x_height_name; y ++) {
      conMove(y, x);
      putchar(' ');
    }
  }
}
void box(int box_width,int box_left,int box_top,int box_height,int y_console_height,enum conAttribute_e color) {
  conSetAttr(color);
  int x,y;
  for ( x = box_left;x < box_left + box_width; x++) {
    for (y = box_top + box_height ; y < box_top + box_height + y_console_height; y++) {
      conMove(y, x);
      putchar(' ');
    }
  }
}


void input_data(struct Computer_Game *st,int count) {

  int i;
  int maximum_counter = 100;
  int box_width = 87;
  clearLine(' ',6,box_width-1,4,BG_CYAN);
  for(i = 0; i < count; i++) {
      conMove(6,1);
      char buffer[100];
      printf("Введіть назву %d гри: ",i + 1);
      fgets((st + i)->fullname,maximum_counter,stdin);
      (st + i)->fullname[strlen((st + i)->fullname) -1] = '\0';
      printf("Введіть  жанр %d гри: ",i + 1);
      fgets((st + i)->genre,maximum_counter,stdin);
      (st + i)->genre[strlen((st + i)->genre) -1] = '\0';
      printf("Введіть рік створення %d гри: ",i + 1);
      fgets(buffer,maximum_counter,stdin);
      sscanf(buffer,"%d",&(st + i)->year);
      printf("Введіть  рейтинг %d гри : ",i + 1);
      fgets(buffer,maximum_counter,stdin);
      sscanf(buffer,"%f",&(st + i)->rating);
      printf("Введіть  ігрову платформу %d гри : ",i + 1);
      fgets((st + i)->games.platform,maximum_counter,stdin);
      (st + i)->games.platform[strlen((st + i)->games.platform) -1] = '\0';
      printf("Введіть  кількість гравців %d гри : ",i + 1);
      fgets((st + i)->games.numbers_of_player,maximum_counter,stdin);
      (st + i)->games.numbers_of_player[strlen((st + i)->games.numbers_of_player) -1] = '\0';
      clearLine(' ',6,box_width-1,10,BG_CYAN);
  }

}









int menu (void) {
  char buffer[BUFFER_SIZE];
  char  keyDown ;
  int box_left = 0;
  int box_top = 5;
  int box_width = 100;
  int box_height = 0;
  int x_width_name = 100;
  int x_height_name = 5;
  int y_console_height = 40;


  conClear();
  prebox(x_width_name,x_height_name,BG_BLACK);
  conMove(3,44);
  printf("MENU\n");
  conReset();
  conMove(12,0);
  box(box_width, box_left, box_top,box_height, y_console_height,BG_CYAN);



  struct Computer_Game *release;

  release = (struct Computer_Game*)malloc(8*sizeof(struct Computer_Game));

 if (NULL == release) {
		printf("Can't alloc memory");
		return EXIT_FAILURE;
	}



  conMove(6,5);
  printf("Натисніть 1,щоб створити новий масив даних\n");
  conMove(7,5);
  printf("Натисніть 2,щоб зчитати масив даних із файлу\n");
  conMove(8,5);
  printf("Натисніть 0,щоб вийти із програми \n");


  while (  keyDown != '0') {
    conMove(19,1);
    printf("--------------------------------------------------------------------------------------------------");
    conMove(20,1);
    puts ("Введіть номер операції: ");
    keyDown = conGetChar();
    switch (keyDown) {
        case '1': {

          clearLine(' ',5,box_width-1,6,BG_CYAN);
          conMove(6,1);
          int count;
          int number6 = 5;
          printf ("\tВи можете охарактеризувати не більше 5 ігор\n");
          printf ("\tВиберіть кількість ігор ,які ви бажаєте охарактеризувати: ");
          count = getInt();

          if (count > number6 || count <= 0) {
            printf("Попробуйте ще раз\n");
            count = getInt();
          }
          input_data(release,count);
          clearLine(' ',5,box_width-1,20,BG_CYAN);

          conMove(6,1);
          prints();

          conMove(3,44);
          printf("Task 1\n");

          char Down;
           while(Down != '0') {
              conMove(16,1);
              printf("--------------------------------------------------------------------------------------------------");
              conMove(17,1);
              puts ("Введіть номер операції: ");
              Down = conGetChar();

              switch(Down){
                case '1':{
                    clearLine(' ',18,box_width-1,30,BG_CYAN);
                    conMove(19,1);
                //    valid_removing(count);
                    int number =   valid_removing(count);
                    removing (release, count,number);
                    print_array(release, count);


                }break;
                case '2':{
                  clearLine(' ',18,box_width-1,30,BG_CYAN);
                  conMove(19,1);
                  int number = valid_rerecord(count);
                  rerecording_2(release,  count,number);
                  print_array(release, count);

                }break;
                case '3':{
                  clearLine(' ',18,box_width-1,30,BG_CYAN);
                  conMove(19,1);
                  int number = valid_rerecord(count);
                  rerecording_1 (release, count,number);
                  print_array(release, count);

                }break;
                case '4':{
                  clearLine(' ',18,box_width-1,30,BG_CYAN);
                  conMove(19,1);
                  int number  = valid_Game_record( count);
                  Computer_Game_record(release,buffer ,count,number);

                }break;
                case '5':{
                  clearLine(' ',18,box_width-1,30,BG_CYAN);
                  conMove(19,1);
                  int checker = valid_Computer_Reverse_record (buffer);
                  Computer_Game_REVERSE_record(release, count ,buffer,checker);
                  printf("Успішно записано");

                }break;
                case '6':{
                  clearLine(' ',18,box_width-1,30,BG_CYAN);
                  conMove(19,1);
                  text(release,buffer, count);
              //   arrays_of_structers(release,buffer, count);

                }break;
                case '7':{
                  clearLine(' ',18,box_width-1,30,BG_CYAN);
                  conMove(19,1);
                  float number1 = 0;
                  printf("Введіть рейтинг: ");
                  number1 = getDouble();

                  all_structure_ratingX(release,count,number1);
              //    print_ratingX(release,count,number1);

                } break;
                case '8': {
                  clearLine(' ',18,box_width-1,30,BG_CYAN);
                  conMove(19,1);
                  int number1 = valid_recording1(count);
                  int number2 = valid_recording2(count);
                  rerecording(release, count,number1,number2);
                  print_array(release, count);


                }break;
                case '9':{
                  clearLine(' ',18,box_width-1,30,BG_CYAN);
                  conMove(19,1);
            //      valid_removing(count);
                  int number =   valid_removing(count);
                  remove_array(release,count,number);
                  print_array(release, count);


                }break;

              }

            }


        clearLine(' ',5,box_width-1,30,BG_CYAN);
        conMove(6,1);
        printf("Не забудьте зберегти дані\n");
        printf("Введіть назву текстового файлу для збереження\n");
        print_in_text_files( count,release);
        clearLine(' ',5,box_width-1,5,BG_CYAN);
        conMove(6,1);
        printf("Натисніть 2 ,щоб зчитати массив з файлу\n");
        printf("Натисніть 0,щоб вийти з програми\n");

        }
        break;
        case '2': {
      //    int count = 0;
          clearLine(' ',5,box_width-1,10,BG_CYAN);
          conMove(5,1);
          load (release);
          print_array(release, 3);
          conMove(8,1);
          printf("--------------------------------------------------------------------------------------------------");
          conMove(9,1);
          prints();


          clearLine(' ',19,box_width-1,30,BG_CYAN);
          conMove(3,44);
          printf("Task 2\n");

           char kDown;
           while(kDown != '0') {
              conMove(18,1);
              printf("--------------------------------------------------------------------------------------------------");
              conMove(19,1);
              puts ("Введіть номер операції: ");
              kDown = conGetChar();

              switch(kDown){
                case '1':{
                    clearLine(' ',19,box_width-1,30,BG_CYAN);
                    conMove(21,1);
                  //  valid_removing(3);
                    int number =   valid_removing(3);
                    removing (release, 3,number);
                    print_array(release, 3);



                }break;
                case '2':{
                  clearLine(' ',19,box_width-1,30,BG_CYAN);
                  conMove(21,1);
                  int number = valid_rerecord(3);
                  rerecording_2(release,  3,number);
                  print_array(release, 3);

                }break;
                case '3':{
                  clearLine(' ',19,box_width-1,30,BG_CYAN);
                  conMove(21,1);
                  int number = valid_rerecord(3);
                  rerecording_1 (release, 3,number);
                  print_array(release, 3);

                }break;
                case '4':{
                  clearLine(' ',19,box_width-1,30,BG_CYAN);
                  conMove(21,1);
                  int number  = valid_Game_record( 3);
                  Computer_Game_record(release,buffer ,3, number);

                }break;
                case '5':{
                  clearLine(' ',19,box_width-1,30,BG_CYAN);
                  conMove(21,1);
                  int checker = valid_Computer_Reverse_record (buffer);
                  Computer_Game_REVERSE_record(release,3 ,buffer,checker);

                }break;
                case '6':{
                  clearLine(' ',19,box_width-1,30,BG_CYAN);
                  conMove(21,1);
                  text(release,buffer, 3);

                }break;
                case '7':{
                  clearLine(' ',19,box_width-1,30,BG_CYAN);
                  conMove(21,1);
                  int number;

                  printf("Введіть рейтинг: ");
                  number = getDouble();

                  all_structure_ratingX(release,3,number);
                //  print_ratingX(release,3,number);


                } break;
                case '8': {
                  clearLine(' ',19,box_width-1,30,BG_CYAN);
                  conMove(21,1);
                  int number1 = valid_recording1(3);
                  int number2 = valid_recording2(3);

                  rerecording(release, 3,number1,number2);
                  print_array(release, 3);
                }break;
                case '9':{
                  clearLine(' ',19,box_width-1,30,BG_CYAN);
                  conMove(21,1);
            //      valid_removing(3);
                  int number =   valid_removing(3);
                  remove_array(release,3,number);
                  print_array(release, 3);
                }break;

              }
        }

          clearLine(' ',5,box_width-1,30,BG_CYAN);
          conMove(6,1);
          printf("Не забудьте зберегти дані\n");
          printf("Введіть назву текстового файлу для збереження\n");
          print_in_text_files( 3,release);
          clearLine(' ',5,box_width-1,5,BG_CYAN);
          conMove(6,1);
          printf("Натисніть 2 ,щоб зчитати массив з файлу\n");
          printf("Натисніть 0,щоб вийти з програми\n");



        }
       break;

    }
  }

    box(box_width, box_left, 0, box_height,y_console_height,BG_CYAN);
    conMove(22,40);
    printf("Кінець\n");
    conMove(50,1);
    free(release);
    return 0;
}
