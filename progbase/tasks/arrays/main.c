
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <progbase.h>
#include <pbconsole.h>
#include <math.h>


int main( )
{

	int A[10]/* = { 320 , 231 ,232  ,239 , -50, 67, 67, 50, 223, 67}*/ ;
	char S[10];
	int i = 0;
	int imin = 0;
	int imax = 0;
	int Count = 0;
	int Sum = 0;
	int max = -50;
	int min = 199;
	double Average = 0;
	srand(time(0));



	printf("1.Згенерувати масив A випадкових цілих чисел \n");
	for(i = 0; i < 10; i++) {
		A[i] = rand() % 299 - 99;
		printf("\t%i ", A[i]);
		
	}
	printf("\n");
	

	printf("2. Виділити певним кольором фону всі числа у межах від [-50..50] \n");
	for (i = 0; i < 10; i++) {
		if (A[i] >= - 50 && A [i] <= 50) {
		conSetAttr(BG_GREEN);
		}
		printf("\t%i ", A[i]);
		conReset();
	}
	conReset();
	printf("\n");



	printf("3. Виділити певним кольором фону всі числа, які більші 100 \n");
	for (i = 0; i < 10; i++) {
		if (A[i] > 100) {
			conSetAttr(BG_RED);
			Sum += A[i];
			Count += sizeof(A[i]) / sizeof(A[0]);
			Average = (double)Sum/Count;
		}
		printf("\t%i ", A[i]);
		conReset();
	}
	printf("\n");
	printf("Sum: %i\n", Sum);
	printf("Count: %i\n", Count);
	printf("Average: %f\n", Average);
	printf("\n");


	printf("4.значення та індекс першого максимального в межах від [-50..50] числа \n");
	for (i = 0; i < 10; i++) {
		if (A[i] >= - 50 && A [i] <= 50) {
			if (A[i] > max) {
				max = A[i];
				imax = i;
			}
		}
	}
	printf("A[%i] = %i\n",imax , max);
	printf("\n");


	printf("5.значення та індекс першого найменшого додатнього числа масиву  \n");
	for (i = 0; i < 10; i++) {
		if (A[i] < min && A[i] > 0) {
			min = A[i];
			imin = i;
		}
	}
	printf("A[%i] = %i\n",imin , min);
	printf("\n");
	
	
	printf("6.Створити окремий масив символів S  \n");
	for (i = 0; i <= 8; i++) {
		S[i] = abs(A[i]) % 95 + 32;
	}
	S[9] = S['\0'];
	puts(S);
	
	printf("\n");
	
	
	printf("7. Обнулити у масиві A всі числа, які менші -25 та вивести його \n");
	for (i = 0; i < 10; i++) {
		if (A[i] < -25) {
			A[i] = 0;
			conSetAttr(BG_RED);
		}
		printf("\t%i ", A[i]);
		conReset();
	}
	printf("\n");



	return 0;
}


