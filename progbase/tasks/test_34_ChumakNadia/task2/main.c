#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pbconsole.h>
#include <progbase.h>
#include <time.h>
#include <limits.h>


struct city {
  char fullname[50];
  float rating;
  int year;
};
struct mer {
  struct city name;
  char friends [100];
  int year;
};
void city_print(struct city * st) {
    printf("Fullname: %s\nRating: %f\nPopulation: %i\n",
   	 st->fullname, st->rating, st->year);
}


void city_printAll(struct city cities[], int size) {
    int i;
    for (i = 0; i < size; i++) {
   	 city_print(&cities[i]);
   	 puts("-------");
    }
}
void mer_print(struct mer * st) {
    printf("Fullname: %s\nFriends: %s\nYear: %d\n",
   	 st->name.fullname, st->friends, st->year);
}


void mer_printAll(struct mer mers[], int size) {
    int i;
    for (i = 0; i < size; i++) {
   	 mer_print(&mers[i]);
   	 puts("-------");
    }
}
struct city *
city_50(struct city cities[], int size,struct city * st) {
   int   min = 50;
    int i;
    for (i = 1; i < size; i++) {
   	 if (cities[i].year < min) {
        printf("%d",st->year);
   	 }
    }
    return 0;
}

struct mer *
mer_30(struct mer mers[], int size,struct city * st) {
   int   min = 30;
    int i;
    for (i = 1; i < size; i++) {
   	 if (mers[i].year < min) {
       printf("%d",st->year);
   	 }
    }
    return 0;
}



#define mers_COUNT 5
#define cities_COUNT 5


int main(void) {
 int number = 0;
 printf("Enter a number N\n");
  number = getInt();
  struct city *release;
  release = (struct city*)malloc(number*sizeof(struct city));
  if (NULL == release) {
		printf("Can't alloc memory");
		return EXIT_FAILURE;
	}
  struct city first[cities_COUNT] = {
    { " ", 0, 0 },
    { " ", 0, 0 },
    { " ", 0, 0 },
    { " ", 0, 0},

  };
  city_printAll(first, 4);
  
/*struct mer fir[mers_COUNT] = {
    { " ", " ", 0},
    { " ", " ", 0 },
    { " ", " ", 0 },
    { " ", " ", 0},

  };
  mer_printAll(fir, 4);*/



  struct city cities[cities_COUNT] = {
    { "Murhorod", 345.5, 10000 },
    { "Kyiv", 34.4, 3476732 },
    { "Donets", 4783.4, 3562531 },
    { "Ternopil", 4783.4, 94238},

  };
city_printAll(cities,4);


/*struct mer mers[mers_COUNT] = {
    { "Vasya","Pane", 32},
    { "Kolya", "Kate", 45 },
    { "Anna", "Roma", 12 },
    { "Kate", "Sascha", 78},

  };

mer_printAll(mers, 4);*/



  free(release);

    return 0;
}
