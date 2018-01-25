#include <math.h>
#include <stdio.h>

int main() 
{
	double x = 0;
	double f1 = 0;
	double f2 = 0;


	for (x = -10; x <= 10; x += 0.5) {
		f1 = pow(x, 2) - 5;
		f2 = cos(pow(x, 2)) + pow(sin(2 * x), 2) + 1;
		printf("x = %.3f\n", x);
		printf("f1() =  %.3f\n", f1 );
		printf("f2() =  %.3f\n", f2 );
		printf("f1() + f2() = %.3f\n", f1 + f2);
		printf("f1() * f2() = %.3f\n", f1 * f2);
		
		if ( f2 == 0 ) {
			printf("division by zero\n");
		} else {
			printf("f1() / f2() = %.3f\n", f1 / f2);
		}
	
		if ( f1 == 0 ){
			printf("division by zero\n");
		} else {
			printf("f2() / f1() =  %.3f\n", f2 / f1);
		}

		printf("\n");
	}

	return 0;
}
