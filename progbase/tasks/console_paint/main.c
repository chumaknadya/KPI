#include <stdio.h>

#include <progbase.h>
#include <pbconsole.h>

int main(void) 
{
	int x = 0;
	int y = 0;
	int shiftX = 1;
	int shiftY = 1;
	int height = 16;
	int width = 28;

	
	conClear();
	conSetAttr (BG_RED);
	for ( y = 1; y < 17 ; y ++) {
		for ( x = 1 ; x < 29; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	
	conSetAttr (BG_BLACK);
	for ( y = 1 ; y < 3 ; y ++) {
		for ( x = 5 ; x < 10 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 2; y < 4 ; y ++) {
		for ( x = 10 ; x < 13 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 3 ; y < 8 ; y ++) {
		for ( x = 13 ; x < 15 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 2 ; y < 4 ; y ++) {
		for ( x = 15 ; x < 18 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = shiftY  ; y < 3 ; y ++) {
		for ( x = 18 ; x < 25 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 4 ; y < 6 ; y ++) {
		for ( x = 8 ; x < 11 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 4 ; y < 6 ; y ++) {
		for ( x = 17 ; x < 20 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( x = 8, y = 11; x < 14; y++, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 11, y = 11; x < 14; y++, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 4, y = 7; x < 7; y++, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 15, y = 7; x < 18; y++, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 14, y = 13; x < 17; y--, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 14, y = 16; x < 20; y--, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 19, y = 10; x < 23; y--, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 10, y = 9; x < 13; y--, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 4, y = 4; y < 8; y++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 22, y = 4; y < 8; y++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 1, y = 1; x < 5; x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
			conMove ( 3 , 21);
			putchar ( ' ' );
			conMove ( 3 , 5);
			putchar ( ' ' );
			conMove ( 1 , 25);
			putchar ( ' ' );
	conSetAttr (BG_WHITE);
	for ( y = 4 ; y < 7 ; y ++) {
		for ( x = 11 ; x < 13 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 4 ; y < 8 ; y ++) {
		for ( x = 5 ; x < 8 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 6 ; y < 8 ; y ++) {
		for ( x = 5 ; x < 12 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( x = 6, y = 3 ; x < 10 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( y = 4 ; y < 7 ; y ++) {
		for ( x = 15 ; x < 17 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 4 ; y < 8 ; y ++) {
		for ( x = 20; x < 22; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( y = 6 ; y < 8 ; y ++) {
		for ( x = 16 ; x < 22 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
		}
	}
	for ( x = 18, y = 3 ; x < 21 ; x ++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 6, y = 8; x < 11;  x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 17, y = 8; x < 21;  x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	conSetAttr (BG_INTENSITY_YELLOW);
	for ( x = 10, y = 12; x < 14; y++, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 11, y = 12; x < 14; y++, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 14, y = 15; x < 18; y--, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 14, y = 14; x < 17; y--, x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 13, y = 12 ; x < 15; x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for ( x = 12, y = 8 ; x < 16; x++) {
			conMove ( y , x );
			putchar ( ' ' );
	}
	for (x = 6, y = 9; x < 21; x++) {
		if (x > 10 && x < 17) {
				conSetAttr(BG_INTENSITY_YELLOW);
		} else {
				conSetAttr(BG_BLACK);
		}
		conMove(y, x);
		putchar(' ');
	}
	for (x = 8, y = 10; x < 20; x++) {
		if (x > 8 && x < 19) {
				conSetAttr(BG_INTENSITY_YELLOW);
		} else {
				conSetAttr(BG_BLACK);
		}
		conMove(y, x);
		putchar(' ');
	}
	for (x = 8, y = 11; x < 20; x++) {
		if (x > 11 && x < 16) {
				conSetAttr(BG_INTENSITY_YELLOW);
		} else {
				conSetAttr(BG_BLACK);
		}
		conMove(y, x);
		putchar(' ');
	}
 
 	conReset();
	conMove(17, 1);
	return 0;
}
