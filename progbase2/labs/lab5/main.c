
#include <time.h>
#include <menu.h>
#include <pbconsole.h>
#include <storage.h>

int main (void) {
  srand((unsigned)time(NULL));
  menu();
  conReset();
  return 0;
}

