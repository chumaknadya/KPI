#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pbconsole.h>
#include <progbase.h>
#include <time.h>
#include <limits.h>
int file_process(const char * readFileName, const char * writeFileName) {
  enum { BUFFER_SIZE = 300 };
  char buffer[BUFFER_SIZE];

  int count = 0;
  const char * input = readFileName;
  const char * output = writeFileName;
  FILE * fin = fopen(input, "r");
  FILE * fout = fopen(output, "w");
  if (fin == NULL || fout == NULL) {
      printf("Error opening file\n");
      return 1;
  }
  while (!feof(fin))  {
        fgets(buffer, BUFFER_SIZE, fin);
        buffer[strlen(buffer) - 1] = '\0';
        const char * ptr = buffer;

          if( isalpha(buffer[0])) {
            while (*ptr != '\0') {
              count ++;
              if(isalpha(*ptr) && count == 4) {
                fprintf(fout," %s,", buffer);
                count = 0;
              } else {
              ptr ++;
              }
            }


        }
  }

}
int main(void) {
  file_process("input.txt", "output.txt");

   return 0;
}
