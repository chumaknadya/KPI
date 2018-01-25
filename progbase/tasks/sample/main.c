

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

  int countspace(){
  int count = 0;
  int c;
  int N = 20;
  int i = 0;
   for ( i = 0;i<N && (c = getchar()) != EOF;i++) {
    if (isspace(c)){

      count ++;
    }
  }
/*printf("count %i",count);*/
  return count;
}
 void (int number){
   if (number > 1){
      number = 1;
   }
 }



  int main (){
  countspace();

    return 0;
  }
