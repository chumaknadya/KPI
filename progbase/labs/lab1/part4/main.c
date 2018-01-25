#include <math.h>
#include <progbase.h>

int main(void) 
{
	int n = 0;
	int m = 0;
	int i = 0;
	int j = 0;
	double sum1 = 0;
	double sum2 = 0;
	const double PI = 3.14159265;
	
	puts ( "Enter int m:" );
	m = getInt();
	printf ( "Your: m = %d\n" , m );
	puts ( "Enter int n:" );
	n = getInt(); 
	printf ( "Your : n = %d\n" , n );
	
	
	for (i = 1; i <= n; i++) {
		sum2 = 0;
		for (j = 1; j <= m; j++) {
			sum2 += (cos(i*PI/2) + 3 * sin (j*PI/2));
		}
		sum1 += sum2;
	}
	printf ( "x = %f\n" , sum1 );
	
	return 0; 
}
