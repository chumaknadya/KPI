#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char symbols(const char * pStart, const char * pChar);

int main(void) {
    char str[100];
    char character = 0;
    printf("Введіть строку : ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    printf("Ви ввели: %s\n", str);

    /* call recursive function and print it's result*/
    character = symbols(str, str + strlen(str) - 1);
    printf("\nОбчислити і вивести символ, що слідує за останнім символом ‘@' : %c\n\n", character);


    return EXIT_SUCCESS;
}

 char symbols(const char * pStart, const char * pChar) {

   if (pStart > pChar ) {
      return '0';
   }
   else if (*pChar == '@') {
      if (iscntrl(*(pChar+1 ) )){
        return '0';
      } else {
         return *(pChar + 1);
       }
    } else {
        return symbols(pStart, pChar - 1);


    }

}
