#include "header.h"
#include "assert_.h"


 int main(int argc,char *argv[]) {
   if(argc > 1){
    test1();
    test2();
    test3();

     printf ("All asserts are passed\n");
     return EXIT_SUCCESS;
    }




   srand((unsigned)time(NULL));
   menu();
   conReset();


   return 0;
 }
