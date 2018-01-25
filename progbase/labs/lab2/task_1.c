#include "lab_2.h"



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


void task_1(void) {

 int number = 0;
 int Array[10] = { 0 ,0,0,0,0,0,0,0,0,0};
 int length = 10;
 int imin = 0;
 int imax = 0;
 int min = 100;
 int max = -100;
 int temp = 0;
 int Sum = 0;
 int Product = 1;
 int counter = 0;
 int i = 0;
 int j = 0;
 char keyDown;
 int x = 0 ;
 int y = 0;
 int box_left = 0;
 int box_top = 5;
 int box_width = 87;
 int box_height = 12;
 int x_width_name = 87;
 int x_height_name = 5;
 int y_console_height = 12;
 srand(time(0));


 /*prebox*/
 conSetAttr(BG_BLACK);
 for (x = 0;x < x_width_name;x ++) {
 	for (y = 0;	y < x_height_name; y ++) {
 		conMove(y, x);
    putchar(' ');
 	}
 }

 conMove(3,40);
 printf("Task 1\n");
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
 printf ("1.Заповнити масив випадковими числами від -100 до 100\n");
 conMove(7,2);
 printf ("2.Обнулити всі елементи масиву.\n");
 conMove(8,2);
 printf ("3.Знайти мінімальний елемент та його індекс.\n");
 conMove(9,2);
 printf ("4.Знайти суму елементів масиву.\n");
 conMove(10,2);
 printf ("5.Вивести добуток від'ємних елементів масиву.\n");
 conMove(11,2);
 printf ("6.Знайти перший елемент, що повторюється найбільшу кількість раз.\n");
 conMove(12,2);
 printf ("7.Поміняти місцями максимальний і мінімальний елементи масиву\n");
 conMove(13,2);
 printf ("8.Помножити всі елементи масиву на введене число.\n");
 conMove(14,10);
 printf ("Натисність '9' ,щоб щоб  повернутия до головного меню\n");
 conMove(15,10);
 printf ("Натисність q ,щоб вийти з програми\n");
conReset();
conSetAttr(BG_BLACK);
for ( x = box_left;x < box_left + box_width; x++) {
  for (y = box_top + box_height ; y < box_top + box_height + y_console_height; y++) {
     conMove(y, x);
     putchar(' ');
  }
}


while(keyDown != 'q') {



  conMove(17, 1);
  conSetAttr(BG_BLACK);
  puts ("Enter your number");
  keyDown = conGetChar();

  switch (keyDown){
    case '1': {

      conMove(18,1);
      for (i = 0; i < length; i++ ) {
        Array[i]= rand()%200 - 100;
        printf("\t%i",Array[i]);
      }
      printf("\n");

    }
    break;
    case '2': {
      conMove(17,1);
      clearLine(' ',17,box_width-1,2,BG_BLACK);
      conMove(18,2);
      for (i = 0;i < length; i++) {
        Array[i] = 0;
        printf("\t%i",Array[i]);
      }
      printf("\n");

    }
    break;
    case '3': {
      conMove(19, 3);
      for(i = 0; i < length; i++) {
        if (Array[i] < min) {
          min = Array[i];
          imin = i;
        }
      }
      printf("\n");
      printf("A[%i] = %i\n",imin , min);
    }
    break;
    case '4': {
      conMove(20, 3);
      for(i = 0;i < length; i++) {
        Sum += Array[i];
      }
      printf("\n");
      printf("Sum: %d\n", Sum);
    }
    break;
    case '5': {
      conMove(21, 3);
      for(i = 0;i < length; i++) {
          if (Array[i] < 0) {
            Product *= Array[i];
          }
        }
      printf("\n");
      if (Product == 1){
        printf("Array doesn`t consist of negative elements\n");
      }
      else {
        printf("Product: %d\n", Product);
      }
    }
    break;
    case '6': {
      conMove(21, 20);
      for( i = 0; i < length; i++) {
        counter = 1;
        for (j = i + 1; j < length; j++) {
          if(Array[i] == Array[j]) {
            counter++;
            if (counter > max) {
              max = counter;
              imax = j;
            }
          }
          else {
            counter = 0;
          }
        }
      }
      if (imax == 0) {
          printf("There is no repeating elements\n");
        }
      else {
          printf("First repeating element %d\n",Array[imax]);
        }
    }
    break;
    case '7': {
      conMove(23, 3);
      imax = 0;
      imin = 0;
      max = -100;
      min = 100;

      for (i = 0 ; i < length; i ++) {
        if (Array[i] < min) {
          min = Array[i];
          imin = i;
        }
        if (Array[i] > max) {
          max = Array[i];
          imax = i;
        }
      }
      temp = Array[imin];
      Array[imin]=Array[imax];
      Array[imax]=temp;
      for (i = 0; i < length; i ++) {
      printf("\t%i",Array[i]);
      }
      printf("\n");
    }
    break;
    case '8': {
      conMove(24, 3);
      printf ("Enter your number\n");
      number = getInt();
      conMove(24, 3);
      clearLine(' ',24,box_width-1,2,BG_BLACK);
      conMove(24, 3);

       for (i = 0;i < length; i++) {
        Array[i] = number * Array[i];
        printf("\t%i",Array[i]);
       }

      conMove(17, 3);




    }
    break;
    case '9':{
      conReset();
      menu();

      break;
    }
  }

conReset();


}



}
