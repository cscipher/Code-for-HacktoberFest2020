// Code-For-Hacktoberfest2020
// @Agarwal-Kritik
// Check Whether A Number is Prime or Composite

#include <stdio.h>
void second(void)
{
	int n, f = 1;
	printf("\n\nEnter a Number: ");
	scanf("%d", &n);
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			f = 0;
			break;
		}
	}
	if (n == 1)
		printf("\n\"1\" is neither Prime nor Composite\n");
	else if (f == 1)
		printf("\n\"%d\" is a Prime Number\n", n);
	else
		printf("\n\"%d\" is a Composite Number\n", n);
}