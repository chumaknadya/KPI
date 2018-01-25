#include "lab_2.h"

void clearLine1(char c,int y,int x,int num,enum conAttribute_e color) {
  int i,j;
  conSetAttr(color);
  for (j = 0; j < num; j ++) {

    for (i = 0; i < x; i ++) {
      conMove(y+j,1+i);
      putchar(c);
    }
  }
}

void task_2(void) {



  double arr1[10] = { 0 };
	double arr2[10] = { 0 };
	double arr3[10];
  int length = 10;
  double Sum1 = 0;
  double Sum2 = 0;
	int i = 0;

	int imin = 0;
	int imax = 0;
  double dmin = 20.0;
  double dmax = -20.0;
	int temp = 0;
  char keyDown = 0;
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
  printf("Task 2\n");
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
  printf ("1.Заповнити масиви випадковими дробовими числами від -20.0 до 20.0\n");
  conMove(7,2);
  printf ("2.Обнулити всі елементи масивів.\n");
  conMove(8,2);
  printf ("3.Знайти значення нового масиву чисел, елементи якого будуть різницею \n   відповідних елементів першого і другого масиву.\n");
  conMove(10,2);
  printf ("4.Вивести номер масиву, у якому максимальна сума елементів.\n");
  conMove(11,2);
  printf ("5.Поміняти місцями мінімальний елемент першого масиву і максимальний елемент\n   другого масиву.\n");
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

	switch (keyDown) {
		case '1': {
      clearLine1(' ',18,box_width-1,11,BG_BLACK);
      conMove(18,1);
			for (i = 0;i < length; i++) {
				arr1[i] = (rand()%80)/2.0-40/2.0;
				printf("\t%0.1f",arr1[i]);
			}
			printf("\n");
			for (i = 0;i < length; i++) {
				arr2[i] = (rand()%80)/2.0-40/2.0;
				printf("\t%0.1f",arr2[i]);
			}
			printf("\n");
		break;
		}
		case '2': {
      clearLine1(' ',17,box_width-1,3,BG_BLACK);
      conMove(18, 3);
			for (i = 0;i < length; i++) {
				arr1[i] = 0;
				printf("\t%0.1f",arr1[i]);

			}
			printf("\n");
			for (i = 0;i < length; i++) {
				arr2[i] = 0;
				printf("\t%0.1f",arr2[i]);
			}
			printf("\n");
		}
		break;
		case '3': {
      conMove(20, 3);
			for (i = 0;i < length; i++) {
				arr3[i] = arr1[i]- arr2[i];
				printf("\t%0.1f",arr3[i]);
			}
			printf("\n");

		}
		break;
		case '4': {
      conMove(21, 3);
			for(i = 0;i < length; i++) {
					Sum1 += arr1[i];
			}

			for(i = 0;i < length; i++) {
					Sum2 += arr2[i];
			}

			if (Sum1 > Sum2) {
				printf("1 - number of array1\n");
			} else if (Sum2 > Sum1) {
				printf("2 - number of array2\n");
			}
			else {
				printf("arrays are equal\n");
			}
		}
		break;
		case '5': {
      conMove(22, 3);
			for (i = 0;i < length;i ++) {
				if (arr1[i] < dmin) {
					dmin = arr1[i];
					imin = i;
				}
				if (arr2[i] > dmax) {
					dmax = arr2[i];
					imax = i;
				}
			}

			temp = arr1[imin];
			arr1[imin] = arr2[imax];
			arr2[imax] = temp;
			for (i = 0; i < length; i ++) {
				printf("\t%0.1f",arr1[i]);
			}
			printf("\n");
			for (i = 0; i < length; i ++) {
				printf("\t%0.1f",arr2[i]);
			}
			printf("\n");

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
