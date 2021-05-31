#include <cs50.h>
#include <stdio.h>

int main(void)
{
	long cardn = get_long("Credit card number: ");
	long digitn = cardn / 1000000000000;

	// 13 DIGITS ///////////////////////////////////////////////////////////

	if (digitn <= 9 && digitn == 4)
	{
		//1st part__________________________________________________________
		long divisor = 1e11;
		long sum1 = 0;

		do
		{
			long sum = (cardn / divisor) % 10;
			sum = sum * 2;
			if (sum >= 10)
			{
				sum1 = (sum % 10) + (sum / 10) + sum1;
			}
			else if (sum < 10)
			{
				sum1 = sum + sum1;
			}
			divisor = divisor / 100;
		}
		while (divisor > 1);
		sum1 = sum1 + (cardn % 10);

		//2nd part__________________________________________________________
		long divisor1 = 1e12;
		long sum2 = 0;
		do
		{
			long sumb = (cardn / divisor1) % 10;
			sum2 = sumb + sum2;
			divisor1 = divisor1 / 100;
		}
		while (divisor1 > 1);
		long final = (sum1 + sum2);

		//Printing__________________________________________________________
		if (final % 10 == 0)
		{
			if (digitn == 4)
			{
				printf("VISA\n");
			}

		}
		else
		{
			printf("INVALID\n");
		}
	}






	// 15 DIGITS //////////////////////////////////////////////////////////

	else if (digitn > 99 && digitn <= 999)
	{
		//1st part_________________________________________________________
		long divisor = 1e13;
		long sum1 = 0;
		do
		{
			long sum = (cardn / divisor) % 10;
			sum = sum * 2;
			if (sum >= 10)
			{
				sum1 = (sum % 10) + (sum / 10) + sum1;
			}
			else if (sum < 10)
			{
				sum1 = sum + sum1;
			}
			divisor = divisor / 100;
		}
		while (divisor > 1);
		sum1 = sum1 + (cardn % 10);

		//2nd part_________________________________________________________
		long divisor1 = 1e14;
		long sum2 = 0;
		do
		{
			long sumb = (cardn / divisor1) % 10;
			sum2 = sumb + sum2;
			divisor1 = divisor1 / 100;
		}
		while (divisor1 > 1);
		long final = (sum1 + sum2);

		//Printing_________________________________________________________
		if (final % 10 == 0)
		{
			if (digitn / 10 == 34 || digitn / 10 == 37)
			{
				printf("AMEX\n");
			}
			else
			{
				printf("INVALID\n");
			}

		}
		else
		{
			printf("INVALID\n");
		}


	}

	// 16 DIGITS //////////////////////////////////////////////////////////
	else if (digitn > 999 && digitn <= 9999)
	{
		//1st part_________________________________________________________
		long divisor = 1e15;
		long sum1 = 0;
		do
		{
			long sum = (cardn / divisor) % 10;
			sum = sum * 2;
			if (sum >= 10)
			{
				sum1 = (sum % 10) + (sum / 10) + sum1;
			}
			else if (sum < 10)
			{
				sum1 = sum + sum1;
			}
			divisor = divisor / 100;
		}
		while (divisor > 1);

		//2nd part_________________________________________________________
		long divisor1 = 1e14;
		long sum2 = 0;
		do
		{
			long sumb = (cardn / divisor1) % 10;
			sum2 = sumb + sum2;
			divisor1 = divisor1 / 100;
		}
		while (divisor1 > 1);
		sum2 = sum2 + (cardn % 10);
		long final = (sum1 + sum2);

		//Printing_________________________________________________________
		if (final % 10 == 0)
		{
			if (digitn / 1000 == 4)
			{
				printf("VISA\n");
			}
			else if (digitn / 100  >= 51 && digitn / 100 <= 55)
			{
				printf("MASTERCARD\n");
			}
			else
			{
				printf("INVALID\n");
			}
		}
		else
		{
			printf("INVALID\n");
		}


	}
	else
	{
		printf("INVALID\n");
	}
}

