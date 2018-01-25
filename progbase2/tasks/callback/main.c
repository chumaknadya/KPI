#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_task2(void);
void print_task1(void);
void task_1(void);
void task_2(void);
void printArr(char  arr[][100], int count);
int struct_cmp_by_score(const void * a, const void * b);
int descending (const void * a,const void * b);
void Array_foreach(int arr[], int len, void (*action)(int, int));
void Array_foreachReversed(int arr[], int len, void (*action)(int, int));


typedef struct {
  char name[100];
  int score;
}Participant;

void print_task2(void) {
  printf("Виконати сортування масиву елементів Учасник турніру у порядку спадання кількісті набраних балів\n");
}
void print_struct_array(Participant  * array, int len) {
   for(int i = 0; i < len; i++) {
        printf("[Name: %s \t Score %d ]\n", array[i].name, array[i].score);
   }
   puts("--");
}
int struct_cmp_by_score(const void * a, const void * b) {
    Participant *ia = (Participant *)a;
    Participant *ib = (Participant *)b;
    return ib->score - ia->score;
}

void task_2(void) {
  Participant structs[] = {
    {"Kolya", 299}, {"Danil", 2200},
    {"Masha", 1300}, {"Nadia", 499},
    {"Alena", 150}, {"Pasha", 123 }
  };
  print_task2();
  int length = sizeof(structs) / sizeof (structs[0]);
  printf("Array of structure before sorting\n");
  print_struct_array(structs, length);
  printf("Array of structure after sorting\n");
  qsort(structs, length, sizeof(structs[0]), struct_cmp_by_score);
  print_struct_array(structs, length);

}
void task_1(void) {
  char arr[][100] = {"masha"," katya", "romka" , "football", "result"};
  int length = sizeof(arr) / sizeof (arr[0]);
  print_task1();
  printf("Array before sorting: \n");
  printArr(arr, length);
  printf("Array after sorting: \n");
  qsort(arr, length, sizeof(arr[0]), descending);
  printArr(arr, length);

}

void print_task1(void) {
  printf("Виконати сортування масиву слів у порядку спадання кількості приголосних букв\n");
}
bool IsUpperConsonant(char s) {
  if ( s == 'B' || s == 'C' || s == 'D' || s == 'F'  || s == 'G' || s == 'H'
    || s == 'J' || s == 'K' || s == 'L' || s == 'M' || s == 'N' || s == 'P'
		|| s == 'Q' || s == 'R' || s == 'S' || s == 'T'  || s == 'V' || s == 'W'
		|| s == 'X' || s == 'Z' ) {
			return true;
		}
    return false;
}
bool IsDownConsonant(char s) {
  if ( s == 'b' || s == 'c' || s == 'd' || s == 'f'  || s == 'g' || s == 'h'
    || s == 'j' || s == 'k' || s == 'l' || s == 'm' || s == 'n' || s == 'p'
		|| s == 'q' || s == 'r' || s == 's' || s == 't'  || s == 'v' || s == 'w'
		|| s == 'x' || s == 'z' ) {
			return true;
		}
    return false;
}

int descending(const void * a,const void * b) {
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < strlen(a);i++ ) {
     if (IsUpperConsonant( *(char *)a) || IsDownConsonant(*(char *)b)) {
          count1++;
      }
  }
  for (int i = 0; i < strlen(b);i++ ) {
    if (IsUpperConsonant(*(char *)b) || IsDownConsonant(*(char *)b)) {
         count2++;
     }
  }
  return count2 - count1;

}
void print_task3_1(void) {
  printf("Cтворити функцію,яка проходить по масиву у прямому порядку  виводить індекс і значення додатніх елементів\n");

}
void print_task3_2(void){
    printf("Cтворити функцію,яка проходить по масиву у зворотньому порядку  виводить індекс і значення додатніх елементів\n");
}
void action (int  initialValue, int position) {
   if (initialValue > 0) {
     printf("Value %d position %i\n",initialValue,position);
   }
}
void Array_foreach(int arr[], int len, void (*action)(int, int)){
    for(int i = 0; i < len; i++) {
      action(arr[i],i);
    }
}
void Array_foreachReversed(int arr[], int len, void (*action)(int, int)){
     for(int i = len - 1; i >= 0; i--){
          action(arr[i],i);
     }
}

void printArrOfDigit(int * arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("%i ", arr[i]);
    }
    puts("");
}
int main(void) {
   task_1();
   task_2();
   printf("Arrays of integer\n");
   int arr[] = {5, 0, -4, 4, 5, 10};
   int length = sizeof(arr) / sizeof (arr[0]);
   printArrOfDigit(arr,length);
   print_task3_1();
   Array_foreach( arr, length, action);
   printArrOfDigit(arr,length);
   print_task3_2();
   Array_foreachReversed(arr, length,action);
    return 0;
}
void printArr(char  arr[][100], int count) {
	for (int i = 0; i < count; i++) {
		printf("%s ",arr[i]);
	}
	puts("");
}
