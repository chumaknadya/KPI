#include "lab_2.h"

void menu(void) {
  char  keyDown ;
  int x = 0 ;
  int y = 0;
  int box_left = 0;
  int box_top = 5;
  int box_width = 87;
  int box_height = 12;
  int x_width_name = 87;
  int x_height_name = 5;
  int y_console_height = 12;

  conClear();

  /*prebox*/
  conSetAttr(BG_BLACK);
  for (x = 0;x < x_width_name;x ++) {
  	for (y = 0;	y < x_height_name; y ++) {
  		conMove(y, x);
     	putchar(' ');
  	}
  }
  conReset();
  conSetAttr(BG_BLACK);
  conMove(3,35);
  printf(" MAIN MENU\n");
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
  printf ("1.Одномірний масив\n");
  conMove(7,2);
  printf ("2.Два одномірні масиви\n");
  conMove(8,2);
  printf ("3.Двомірний масив\n");
  conMove(9,2);
  printf ("4.Обробка рядків мови С\n");
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
  while (keyDown != 'q') {
		conMove(17, 1);
    puts ("Enter your number:");
		keyDown = conGetChar();

		    switch (keyDown) {
		        case '1':
			         task_1();
			      break;
		        case '2':
			        task_2();
			      break;
		        case '3':
			         task_3();
			      break;
		        case '4':
			         task_4();
			      break;

 		      }


  }
  conReset();
  conMove(32,1);

}
