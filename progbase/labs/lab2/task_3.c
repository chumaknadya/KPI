#include "lab_2.h"
void clearLine2(char c,int y,int x,int num,enum conAttribute_e color) {
  int i,j;
  conSetAttr(color);
  for (j = 0; j < num; j ++) {

    for (i = 0; i < x; i ++) {
      conMove(y+j,1+i);
      putchar(c);
    }
    printf("\n");
  }
}


void task_3(void)
{
  char keyDown ;

	int i = 0;
	int j = 0;
	int max = -10;
	int min = 10;
	int imin = 0;
	int jmin = 0;
	int imax = 0;
	int jmax = 0;
	int temp = 0;
	int length = 8;
  int Sum = 0;
  int x ;
  int y ;
  int box_left = 0;
  int box_top = 5;
  int box_width = 87;
  int box_height = 12;
  int x_width_name = 87;
  int x_height_name = 5;
  int y_console_height = 12;
  int value_element = 0;
  int i_element = 0;
  int j_element = 0;
	int arr4[8][8]= {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}} ;
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
	printf("Task 3\n");
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
  printf ("1.Заповнити масив випадковими числами від -10 до 10\n");
  conMove(7,2);
  printf ("2.Обнулити всі елементи масиву.\n");
  conMove(8,2);
  printf ("3.Знайти максимальний елемент та його індекси.\n");
  conMove(9,2);
  printf ("4.Знайти суму побічної діагоналі масиву.\n");
  conMove(10,2);
  printf ("5.Знайти суму стовпця за заданим індексом.\n");
  conMove(11,2);
  printf ("6.Поміняти місцями максимальний і мінімальний елементи масиву.\n");
  conMove(12,2);
  printf ("7.Змінити значення елементу за вказаними індексами на задане.\n");
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

	  switch (keyDown){
	    case '1': {
        
        conMove(18,1);

		   for (i = 0; i < length; i++) {
			  for(j = 0; j < length; j ++) {
				  arr4[i][j] =rand()%20 - 10;
			  	printf("\t%3i",arr4[i][j]);
			 }
			 printf("\n");
		  }
	  	printf("\n");

	  }
	  break;
	  case '2': {
      clearLine2(' ',17,box_width-1,7,BG_BLACK);
      conMove(18, 3);
		  for (i = 0; i < length; i++) {
			  for(j = 0; j < length; j ++) {
				  arr4[i][j] = 0;
				  printf("\t%3i",arr4[i][j]);
			 }
			 printf("\n");
		 }
		 printf("\n");
	 }
	 break;
	 case '3': {
     conMove(26,3);
		for (i = 0; i < length; i++) {
			for(j = 0; j < length; j ++) {
				if ( arr4[i][j] > max) {
					max = arr4[i][j];
					imax = i;
					jmax = j;
				}
			}
		 }
		printf("Array[%i][%i] = %i\n",imax , jmax,max);
	 }
	 break;
	 case '4': {
    clearLine2(' ',26,box_width-1,1,BG_BLACK);
    conMove(26,3);
		for (i = 0; i < length; i++) {
			for(j = 0; j < length; j ++) {
				if ( i + j == length -1) {
					Sum += arr4[i][j];
				}
			}
		}

		printf("Sum: %d\n", Sum);
	 }
	 break;
	 case '5': {
      Sum = 0;
      clearLine2(' ',26,box_width-1,1,BG_BLACK);
      conMove(26,3);
			puts ("Введіть цілочисельне j:");
			j = getInt();
      conMove(28,3);
      if (j >= 0 && j < 8) {
        for(i = 0; i < length; i ++) {
  				Sum += arr4[i][j];

  			}
        printf("Sum: %d\n", Sum);
      }
      else {
        	printf("Index is not found\n");
      }





      clearLine2(' ',29,box_width-1,1,BG_DEFAULT);
      conMove(17,3);

	 }
	 break;

	 case '6': {

     clearLine2(' ',17,box_width-1,14,BG_BLACK);

     conMove(18,1);
     max = -10;
     imax = 0;
     jmax = 0;
		 for (i = 0; i < length; i++) {
			for(j = 0; j < length; j ++) {
				if ( arr4[i][j] > max) {
					max = arr4[i][j];
					imax = i;
					jmax = j;
				}
				if (arr4[i][j] < min) {
					min = arr4[i][j];
					imin = i;
					jmin = j;
				}
			}
		 }
		temp = arr4[imin][jmin];
		arr4[imin][jmin] = arr4[imax][jmax];
		arr4[imax][jmax] = temp;

		for (i = 0; i < length; i++) {
			for(j = 0; j < length; j ++) {
				printf("\t%3i",arr4[i][j]);
			}
			printf("\n");
		}

   }
	 break;
	 case '7': {

    clearLine2(' ',16,box_width-1,14,BG_BLACK);

    conMove(19,1);
		puts ("Enter i:");
		i_element = getInt();
		puts ("Enter j:");
		j_element = getInt();
    conMove(23,1);
		puts ("Enter value of your element:");
		value_element = getInt();
    clearLine2(' ',17,box_width-1,11,BG_BLACK);
    conMove(18,3);
    if (i_element >= 0 && j_element >= 0 && i_element < 8 && j_element < 8) {
		 for (i = 0; i < length; i++) {
			 for(j = 0; j < length; j ++) {
				 if (i == i_element && j  == j_element) {
					  arr4[i][j] = value_element;
						printf("\t%3i",arr4[i][j]);
				 } else {

           printf("\t%3i",arr4[i][j]);
         }
			 }
			 printf("\n");
		 }
  }
  else {
     printf("Try to enter index from  0 to 7");
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
