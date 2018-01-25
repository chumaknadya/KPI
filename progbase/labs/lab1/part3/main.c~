#include <math.h>
#include <progbase.h>

int main(void) 
{ 
	int a = 0;
	int b = 0;
	int op = 0;
	int temp = 0;
	int min = 0;
	int max = 0;
	int sum = 0;
	float product = 0;
	float div = 0;
	float c = 0;
	const double PI = 3.14159265;


	puts ("Введіть цілочисельне  a:" );
	a = getInt();
	printf ("a = %d\n" , a );
	puts ("Введіть цілочисельне  b:" );
	b = getInt(); 
	printf ("b = %d\n" , b );
	
	printf ("0 сума  \n");
	printf ("1 бінарний мінус : \n");
	printf ("2 добуток  \n");
	printf ("3 цілочисельне ділення  \n");
	printf ("4 |a| \n");
	printf ("5 мінімальне з чисел a i b  \n");
	printf ("6 максимальне з чисел a i b  \n");
	printf ("7 a^b\n");
	printf ("8 var(a,b) =  (pi*(a + b) mod 12)/2 \n");
	printf ("? def(a,b) = (op mod|a + 1| op mod |b + 1|)  \n");
	
	
	puts ("Введіть код операції(цілочисельне значення op):" );
	op = getInt();

	
	if ( op < 0 ) {
		temp = a;
		a = b;
		b = temp;
		op = abs(op);
	}

	switch(op) {
		case 0:{
			c = a + b;
			printf ("сума : %f\n" , c);
		}
		case 1: {
			c = a - b;
			printf ("бінарний мінус : %f\n" , c );
		}
		break;
		case 2: {
			c = a*b;
			printf ("добуток : %f\n" , c );
		}
		break;
		case 3: { 
			if ( !b ) {
				printf ("Неможливо обчислити значення\n");
			}
			else {
				c = a/b;
				printf ("цілочисельне ділення : %f\n" , c );
			}
		}
		break;
		case 4: { 
			c = abs(a);
			printf ( "%f\n" , c );
		}
		break;
		case 5:{ 
			if ( a < b ) {
				min = a;
				printf ("мінімальне з чисел a i b : %d\n" , min );
			}
			else {
				min = b;
				printf ("мінімальне з чисел a i b : %d\n" , min );
			}
		}
		break;
		case 6:{
			if ( a > b ) {
				max = a;
				printf ("максимальне з чисел a i b : %d\n" , max );
			}
			else {
				max = b;
				printf ("максимальне з чисел a i b : %d\n" , max );
			}
		}
		break;
		case 7: { 
			if ( a > 0 ) {
				c = pow(a,b);
				printf ("a^b =  %f\n" , c);
			}
			else {
				printf ("Неможливо обчислити значення\n");
			}
		}
		break;
		case 8: {
			if ( !b ) {
				printf ("Неможливо обчислити значення\n");
			}
			else {
				c = (PI*((a+b) % 12))/b;
				printf ("var(a,b) =  %f\n" , c);
			}
		}
		break;
		default: {
			c = ( op%abs(a + 1) + op%abs(b + 1));
			printf ("def(a,b) =  %f\n" , c);
		}
	}

		return 0; 
}
