#include <stdio.h> /*Standard C I/O lib*/
#include <math.h> /*Math Lib*/
#include <string.h> /*String Lib*/ 

#define DISP(f,x) printf("sqrt(%g) = %g\n", x, f(x));
#define DISP2(f,x,y) printf("strcmp(%s, %s) = %d\n", x, y, f(x, y));

int main(void)
{
	DISP(sqrt, 3.0);
	DISP2(strcmp, "batt", "bat");

	return 0;	
}
