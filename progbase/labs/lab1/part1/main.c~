#include <math.h>
#include <progbase.h>

int main(void) 
{
	double x = 0;
	double y = 0;
	double z = 0;
	double a1 = 0;
	double a2 = 0;
	double a3 = 0;
	double a = 0;
	
	
	puts ("Введіть цілочисельне x:");
	x = getDouble();
	printf ("x = %f\n" , x );
	 
	puts ("Введіть цілочисельне y:");
	y = getDouble(); 
	printf ("y = %f\n" , y );
	
	puts ("Введіть цілочисельне z:" );
	z = getDouble ();
	printf ("z = %f\n" , z );
	

	if ( !fabs(x+y)) {
		printf ("Неможливо обчислити значення a0 \n");
	}
	else {
		a2 = y / (10 *fabs(x + y));
		printf ( "a0 = %.10f\n" , a2 );
	}


	if ( !z ) {
		printf ("Неможливо обчислити значення a1 \n");
	}	else if ((x - y) <= 0) {
			printf ("Неможливо обчислити значення  a1 \n");
		}
	else {
		a1 = pow(x, y+1) / pow(x-y, 1/z);
		printf ( "a1 = %.10f\n" , a1 );
	} 


	if ( !(z + fabs(x-y))) {
		printf ("Неможливо обчислити значення  a2\n");
	} 
	else {
		a3 = pow(2 + sin(y),cos(x)/(z + fabs(x-y)));
		printf ( "a2 = %.10f\n" , a3 );
	} 

	if ( !(z + fabs(x-y))) {
		printf ("Неможливо обчислити значення a \n");
	}	else if ( !fabs(x+y) ) {
			printf ("Неможливо обчислити значення a \n");
		}
		else if ( (x - y) <= 0) {
			printf ("Неможливо обчислити значення a \n");
		}
		else if ( !z ) {
			printf ("Неможливо обчислити значення a \n");
		}
	else {
		a = a1 + a2 + a3;
		printf ( "a =  %.10f\n" , a );
	}
	


	return 0;
}
