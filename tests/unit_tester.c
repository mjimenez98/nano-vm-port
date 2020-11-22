#include <stdio.h>


int unit()
{

	return 10-3;
}



int main()
{

	printf("Test unit\n"); // Print the name of the test program.
	printf("1\n"); // Expected output.
	printf("%d\n", unit()); // Execution the function One() and print the result.

	return 0;

}