#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    /* pointers declaration */
    char * inputStr     = NULL;
    char * last_character = NULL;
    char * is_digit       = "1234567890";
    int  * digit        = NULL;

     digit    = (int  *) malloc( 1 * sizeof(int ));
    /* memory allocation */
    inputStr = (char *) malloc(50 * sizeof(char));

    if (NULL == inputStr ){
        printf("Alloc error");
        return EXIT_FAILURE;
    }

    /* assignments */

    printf("Please, input string: ");
  /*  scanf("%s", inputStr);*/
    fgets(inputStr, 50, stdin);


    /* algorithm */
    last_character = strpbrk(inputStr, is_digit);

    while ( NULL != last_character ) {

      *digit = *last_character- '0';
      last_character = strpbrk(last_character + 1, is_digit);

    }
    printf (" %i\n", *digit);






    /* memory deallocation */
    free(inputStr);
    free(digit);



    return EXIT_SUCCESS;
}
