#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>





int file_process(const char * readFileName, const char * writeFileName) {
  enum { BUFFER_SIZE = 300 };
  char buffer[BUFFER_SIZE];
  long number = 0;
  const char * input = readFileName;
  const char * output = writeFileName;
  FILE * fin = fopen(input, "r");
  FILE * fout = fopen(output, "w");
  if (fin == NULL || fout == NULL) {
      printf("Error opening file\n");
      return 1;
  }
  printf("Для кожного рядка, який починається на ціле число (від'ємні також враховувати),\n"
   "записати у рядок всі додатні числа, розділяючи їх комами\n");
  puts("");

  while (!feof(fin))
    {
        fgets(buffer, BUFFER_SIZE, fin);
        buffer[strlen(buffer) - 1] = '\0';
        if(isdigit(buffer[0]) ||(buffer[0] == '-' && isdigit(buffer[1])))
        {
            const char * ptr = buffer;
            while(*ptr!='\0')
            {
                if(isdigit(*ptr) || (*ptr == '-' && isdigit(buffer[1])))
                {
                    number = strtol(ptr,(char**)&ptr,10);
                    if(number > 0)
                    {
                        fprintf(fout," %ld,", number);
                    }

                }
                else
                {
                    ptr++;
                }

            }
        }
    }
    fseek(fout,-1,SEEK_END);
    fputs("." , fout);




  fclose(fin);
  fclose(fout);

return EXIT_SUCCESS;
}


int main(void) {

  file_process("input.txt", "output.txt");




return 0;
  }
