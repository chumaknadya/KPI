#include <math.h>
#include <progbase.h>

int main(void) 
{
	int a = 0;
	int b = 0;
	int c = 0;
	int modmin = 0;
	int sum2 = 0;
	int min = 0;
	int max = 0;

	
	puts ( "Enter int a:" );
	a = getInt();
	printf ( "Your: a = %d\n" , a );
	 
	puts ( "Enter int b:" );
	b = getInt(); 
	printf ( "Your : b = %d\n" , b );
	
	puts ( "Enter int c:" );
	c = getInt();
	printf ( "Your: c = %d\n" , c );
	
	if (a < 0 && b < 0 && c < 0) { 
		int min = a ;
		if (b < min ) {
			min = b;
			modmin = abs(b);
			sum2 = a + c;
			
		} 
		if (c < min) {
			min = c;
			modmin = abs(c);
			sum2 = a + b;
		} 
		{
			modmin = abs (a);
			sum2 = b + c;
		}
		while (modmin % 2 == 0)
			modmin = modmin/2;
		if (modmin == 1,sum2 > -256) {
			printf ( "true \n" );
			}
		else {
			if ( abs(sum2) > 16 ) {
				printf ( "true \n");
			}	else if ( modmin > 8 ) {
				printf ( "true \n");
				}
			printf ("false \n");
		
		}
	} 
	if (a >= 0 || b >= 0 || c >= 0 ) {
		if (a < 0 ) { 
			if ( a > -256) {
				printf ( "true \n");
			}
			else {
				printf ( "false \n");
			}
		}
		if (b < 0 ) { 
			if ( b > -256) {
				printf ( "true \n");
			}
			else {
				printf ( "false \n");
			}
		}
		if (c < 0 ) { 
			if ( c > -256) {
				printf ( "true \n");
			}
			else {
				printf ( "false \n");
			}
		}
		if ( (a < 0 && b < 0) || ( a < 0 && c < 0) || (b < 0 && c < 0) ) {
			if ((11*(a + b) > -256) || (11*(b + c) > -256) || (11*(a + c) > -256)) {
				printf ( "true \n");
			}
			else {
				printf ( "false \n");
			}
		}
	}
	

	
	
	if (a >= 0 && b >= 0 && c >= 0) { 
		int min = a ;
		int max = a;
		if (b <= min ) {
			 min = b;
		} 
		if (c <= min) {
			min = c;
		} 
		if (b >= max) {
			max = b;
		}
		if (c >= max) {
			max = c;
		} 
		if (pow(max,min) >= -32768 && pow(max,min) <= 32767){
			printf ( "true \n" );
		}
		else {
			printf ( "false \n" );
		}
		
	} 

		printf("\n");
	

	return 0;
}
