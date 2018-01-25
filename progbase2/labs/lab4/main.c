
#include <time.h>
#include "include/menu.h"




int main (void) {
  srand((unsigned)time(NULL));
  menu();
  conReset();
  return 0;
}
