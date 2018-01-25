#include "lab_2.h"

void clearLine3(char c,int y,int x,int num,enum conAttribute_e color) {
  int i,j;
  conSetAttr(color);
  for (j = 0; j < num; j ++) {

    for (i = 0; i < x; i ++) {
      conMove(y+j,1+i);
      putchar(c);
    }
  }
}

void getDoubles(char * p){
        char * t;
        char isRealPresent = 0;
        for(; *p != '\0'; p++) {
                if(isdigit(*p) || (*p=='-' && isdigit(*(p+1)))) {
                        for(t = p + 1; *t != '\0' && *t != '.' && isdigit(*t); t++) ;
                        if(*t == '.' && isdigit(*(t + 1))) {
                                isRealPresent = 1;
                                printf("%.5f ", atof(p));
                                for(p = t+1; isdigit(*(p + 1)); p++) ;
                        }
                }
        }
        if(!isRealPresent) {
                printf("There is no float numbers" );
        }
}




void task_4(void) {
  char str[81] = "******Hi,I am a string !******";
  char character = '\0';
  int length = 0;
  int minl = strlen(str);
  int wordl = 0;
  int wordIndex = 0;
  int flag = 0;

  char keyDown ;
  int i = 0;
  int x1 = 0;
  int x2 = 0;
/*  int count = 0;
  int imin = 0;
  int min = INT_MAX;*/
  long product = 1;
  int countdigit = 0;
  int x ;
  int y ;
  int box_left = 0;
  int box_top = 5;
  int box_width = 87;
  int box_height = 12;
  int x_width_name = 87;
  int x_height_name = 5;
  int y_console_height = 12;

  /*prebox*/
  conSetAttr(BG_BLACK);
  for (x = 0;x < x_width_name;x ++) {
   for (y = 0;	y < x_height_name; y ++) {
     conMove(y, x);
     putchar(' ');
   }
  }
  conMove(3,40);
  printf("Task 4\n");
  conReset();
  conSetAttr(BG_CYAN);
  for ( x = box_left;x < box_left + box_width; x++) {
    for (y = box_top ; y < box_top + box_height ; y++) {
       conMove(y, x);
       putchar(' ');
    }
  }
  puts("");

  conMove(6,2);
  printf ("1.Заповнити строку вводом із консолі.\n");
  conMove(7,2);
  printf ("2.Очистити строку.\n");
  conMove(8,2);
  printf ("3.Вивести довжину строки.\n");
  conMove(9,2);
  printf ("4.Вивести підстроку із заданої позиції і заданої довжини.\n");
  conMove(10,2);
  printf ("5.Вивести список підстрок, розділених заданим символом.\n");
  conMove(11,2);
  printf ("6.Вивести найкоротше слово .\n");
  conMove(12,2);
  printf ("7.Знайти та вивести всі дробові числа, що містяться у строці.\n");
  conMove(13,2);
  printf ("8.Знайти та вивести добуток всіх цілих чисел, що містяться у строці.\n");
  conMove(14,10);
  printf ("Натисність '9' ,щоб щоб  повернутия до головного меню\n");
  conMove(15,10);
  printf ("Натисність q ,щоб вийти з програми\n");

  conSetAttr(BG_BLACK);
  for ( x = box_left;x < box_left + box_width; x++) {
    for (y = box_top + box_height ; y < box_top + box_height + y_console_height; y++) {
       conMove(y, x);
       putchar(' ');
    }
  }

  while (keyDown != 'q') {
    conMove(17, 1);
    conSetAttr(BG_BLACK);
    puts ("Enter your number");
    keyDown = conGetChar();
   switch(keyDown) {
    case '1': {
      clearLine3(' ',18,box_width-1,11,BG_BLACK);

      conMove(19, 1);
      puts("Please enter a string (maximum 80 characters):");
      fgets(str,81, stdin);




      puts("");

     }
     break;
     case '2': {

       str[0] = '\0';
       length = strlen(str);
       for (i = 0; i < length;i ++ ) {
         printf("%i",str[0]);
       }



     }
     break;
     case '3': {
       conMove(22,1);
       length = strlen(str);
       if (length == 80 || length == 0){
       printf("Length = %d\n", length);
       }
       else {
        printf("Length = %d\n", length - 1);
       }
     }
     break;
     case '4': {
      conMove(23,1);
      length = strlen(str);
      if (length == 80 || length == 0){
        length = strlen(str);
      }
      else {
        length = strlen(str) - 1;
      }

      puts("Enter start position of your stringle:");
      x1 = getInt();
      puts("Enter length of your string:");
      x2 = getInt();
      if (x2 < length - x1) {
        for (i = x1; i < (x1+ x2); i ++) {
            putchar(str[i]);
        }
        puts("");
      } else {
        printf("There is no string or you puts an alphabetic numbers.Try again:)\n");
      }


     }
     break;
     case '5': {
      clearLine3(' ',21,box_width-1,7,BG_BLACK);
      conMove(22,3);
      printf("Enter some characters\n");
      character = conGetChar();

      for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == character) {
          printf("\n");
        } else {
          putchar(str[i]);
        }
     }


     }
     break;
     case '6': {
      clearLine3(' ',22,box_width-1,8,BG_BLACK);
      conMove(21,1);

    /*  int minl = strlen(str);
      int wordl = 0;
      int wordIndex = 0;
      int flag = 0;*/
      for(i = 0; str[i] != '\0'; i++) {
      if(isalpha(str[i])) {
          wordl++;
          flag = 1;
        } else if(flag) {
            if(minl > wordl) {
              minl = wordl;
              wordIndex = i - wordl;
          }
        wordl = 0;
        flag = 0;
      }
    }
    for(i = wordIndex; i < wordIndex + minl && str[i] != '\0'; i++) {
      putchar(str[i]);
    }




    /*  for (i = 0; str[i] != '\0'; i ++) {
        if (isalpha(str[i])) {
          count ++;
        } else {
                if (count < min) {
                 min = count;
                 imin = i - count;
                }
          count = 0;
        }
     }
      for ( i = imin;i < imin + min; i++){
        putchar(str[i]);
      }
      if (min == 0) {
        printf("The string does not consist of words or  there is no compare");
      }*/


     }
     break;
     case '7': {
      clearLine3(' ',22,box_width-1,7,BG_BLACK);
      conMove(23,1);

      /*for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        char nextCh = str[i + 1];
        if (isdigit(ch) || ('-' == ch && isdigit(nextCh))){
            double number = atof(str + i);
            count = printf("%f", number);
            puts("");
            i += count - 1;
            countdigit++;
        }

      }
      if (countdigit == 0) {
        printf("Input string don't contain digits\n");
      }*/
      getDoubles(&str[0]);
      putchar('\n');
     }
     break;
     case '8': {
      clearLine3(' ',22,box_width-1,7,BG_BLACK);
      conMove(22,1);

      for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        char nextCh = str[i + 1];
        if (isdigit(ch) || ('-' == ch && isdigit(nextCh)) ){
          int number = atoi(str + i);
          int count = printf("%d", number);
          puts("");
          product *= number;
          i += count - 1;
          countdigit ++;

       }
     }
      if (countdigit == 0) {
        printf("Input string don't contain digits\n");
      } else {
        printf("Mult of digits in string: %ld\n",product);
      }
     }
     break;
     case '9': {
       conReset();
       menu();
     }
     break;
    }
  }
  conReset();
}
