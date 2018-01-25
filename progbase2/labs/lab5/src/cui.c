#include <cui.h>
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
void print_drawing(void) {
  FILE *fin = fopen("draw.txt","r");
  if (fin == NULL) {
    printf("There is NULL reference\n");
  }
  char buffer[BUFFER_SIZE];
  while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
      printf("%s",buffer);

  }
  fclose(fin);
}
