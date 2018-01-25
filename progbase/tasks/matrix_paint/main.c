#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>


int main(void) {
	/* colors encoding table */
		const char colorsTable[16][2] = {
		{'0', BG_BLACK},
		{'1', BG_INTENSITY_BLACK},
		{'2', BG_RED},
		{'3', BG_INTENSITY_RED},
		{'4', BG_GREEN},
		{'5', BG_INTENSITY_GREEN},
		{'6', BG_YELLOW},
		{'7', BG_INTENSITY_YELLOW},
		{'8', BG_BLUE},
		{'9', BG_INTENSITY_BLUE},
		{'A', BG_MAGENTA},
		{'B', BG_INTENSITY_MAGENTA},
		{'C', BG_CYAN},
		{'D', BG_INTENSITY_CYAN},
		{'E', BG_WHITE},
		{'F', BG_INTENSITY_WHITE}
	};
	char image[28][28] = {
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ 'B','0','0','0','B','B','B','B','B','B','B','B','0','0','0','B','B','B','B','B','B','B','B','B','B','B','B','B' },
{ '0','3','3','3','0','0','0','0','0','0','0','0','3','3','3','0','0','B','B','B','B','B','B','B','B','B','B','B' },
{ '3','3','3','0','F','F','F','F','F','3','3','3','0','3','3','3','0','B','B','B','B','B','B','B','B','B','B','B' },
{ '3','0','0','0','F','0','F','3','3','3','0','3','0','0','0','3','0','B','B','B','B','B','B','B','B','B','B','B' },
{ '0','B','0','F','F','F','F','3','3','3','3','3','3','0','B','0','B','B','B','B','B','B','B','B','B','B','B','B' },
{ 'B','B','0','F','F','F','F','0','0','F','F','F','F','0','B','B','B','B','B','B','B','B','B','B','B','B','B','B' },
{ 'B','B','0','F','F','F','F','F','F','F','F','F','F','0','0','B','B','B','B','B','B','B','0','0','0','B','B','B' },
{ 'B','B','B','0','F','F','F','0','0','F','F','F','0','F','0','0','B','B','B','B','B','B','0','3','3','0','B','B' },
{ 'B','B','B','B','0','0','0','2','2','0','0','0','F','F','F','0','0','0','B','B','B','B','B','0','3','3','0','B' },
{ 'B','B','B','B','B','B','0','2','2','0','F','F','F','F','F','3','3','3','0','0','B','B','B','B','0','3','3','0' },
{ 'B','B','B','B','B','B','0','0','0','0','F','F','F','F','F','3','3','3','3','0','0','0','B','B','0','F','F','0' },
{ 'B','B','B','B','B','B','B','B','B','0','F','F','0','F','F','0','3','3','3','3','3','3','0','0','F','F','F','0' },
{ 'B','B','B','B','B','B','B','B','B','0','F','F','0','F','F','0','F','F','F','F','F','F','F','F','F','F','F','0' },
{ 'B','B','B','B','B','B','B','B','B','0','F','F','0','F','F','0','F','F','F','F','F','F','F','0','F','F','F','0' },
{ 'B','B','B','B','B','B','B','B','0','3','3','3','0','3','3','3','0','F','F','F','F','3','0','3','3','F','F','0' },
{ 'B','B','B','B','B','B','B','B','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
{ '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' }
};
	int colorsTableLength = sizeof(colorsTable) / sizeof(colorsTable[0]);
	char colorsPalette[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int colorsPaletteLength = sizeof(colorsPalette) / sizeof(colorsPalette[0]);
	int i = 0;
	int j = 0;
	char colorCode = '\0';
	char color = '\0';
	int image_lenght = 28;
	const unsigned long MILLIS = 10;
	int colorPairIndex = 0;
	conClear();
	/*task1*/
	for (i = 0; i < colorsPaletteLength; i++) {
		char colorCode = '\0';
		char color = '\0';
/* get current color code from colorsPalette */
		colorCode = colorsPalette[i];
/* find corresponding color in table */
		for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) {
			char colorPairCode = colorsTable[colorPairIndex][0];
			char colorPairColor = colorsTable[colorPairIndex][1];
			if (colorCode == colorPairCode) {
				color = colorPairColor;
				break;  /* we have found our color, break the loop */
			}
		}
/* print space with founded color background */

		conSetAttr(color);
		putchar(' ');
	}
	puts("");
	conReset();
	
	/*task2*/
	
	for (i = 0; i < image_lenght; i++) {
		for (j = 0; j < image_lenght; j ++) {
			
			char colorCode = '\0';
			char color = '\0';
			colorCode = image[i ][j];
			
			for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) {
				char colorPairCode = colorsTable[colorPairIndex][0];
				char colorPairColor = colorsTable[colorPairIndex][1];
					if (colorCode == colorPairCode) {
						color = colorPairColor;
						break;
					}
			}
		conSetAttr(color);
		putchar(' ');
		}
	conReset();
	puts("");
	}
	conSetAttr(BG_DEFAULT);
	putchar('\n');
	conReset();
	for (i = 0;i < 32; i ++) {
			puts("");
	}

/*task3*/

            
	for(j = 0; j < image_lenght; j++) {
		
		if( j % 2 ==0 ) {
			for(i= image_lenght - 1; i >= 0; i--) {
				colorCode = image[i][j];
				for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) {
					char colorPairCode = colorsTable[colorPairIndex][0];
					char colorPairColor = colorsTable[colorPairIndex][1];
						if (colorCode == colorPairCode) {
							color = colorPairColor;
							break;
						}
				}
		conMove(i ,j );
		conSetAttr(color);
		fflush(stdout);  
		sleepMillis(MILLIS);
		putchar(' ');
			}
	}

		else {
			for(i = 0; i < image_lenght; i++) {
				colorCode = image[i][j];
				for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) {
					char colorPairCode = colorsTable[colorPairIndex][0];
					char colorPairColor = colorsTable[colorPairIndex][1];
					if (colorCode == colorPairCode) {
						color = colorPairColor;
						break;
					}
				}
		conMove(i ,j );
		conSetAttr(color);
		fflush(stdout);  
		sleepMillis(MILLIS);
		putchar(' ');
			}
		}
	conReset();
	}

	conSetAttr(BG_DEFAULT);
	putchar('\n');
	conReset();
	for (i = 0;i < 32; i ++) {
			puts("");
	}


	/*task4*/
	
	for (i = 0; i < image_lenght/2; i++) {
		for (j = i+1; j < image_lenght-i; j ++) {
			

			colorCode = image[i][j];
			
			image[i][j] = image[image_lenght - 1 - j][i];
			image[image_lenght - 1 - j][i] = colorCode;
			
			colorCode = image[image_lenght - 1 - j][i];
			image[image_lenght - 1 - j][i] = image[image_lenght - 1 - i][image_lenght - 1 - j];
			image[image_lenght - 1 - i][image_lenght - 1 - j] = colorCode;
			
			colorCode = image[image_lenght - 1 - i][image_lenght - 1 - j];
			image[image_lenght - 1 - i][image_lenght - 1 - j] = image[j][image_lenght - 1 - i];
			image[j][image_lenght - 1 - i] = colorCode;
			}
		}

 
	for (i = 0; i < image_lenght*image_lenght; i++) {
		if (i % image_lenght == 0) {
			printf("\n");
			
			}
			
			
			colorCode = image[i / image_lenght ][i % image_lenght];
			
			for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) {
				char colorPairCode = colorsTable[colorPairIndex][0];
				char colorPairColor = colorsTable[colorPairIndex][1];
					if (colorCode == colorPairCode) {
						color = colorPairColor;
						break;
					}
			
			}
			
		conSetAttr(color);
		putchar(' ');
		conReset();
		
		}

		

	
	conSetAttr(BG_DEFAULT);
	putchar('\n');
	conReset();

	return 0;
}
