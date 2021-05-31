#include <stdio.h>
#include <cs50.h>

//added functions
void spaces(int n);
void hashtag(int n);
int teste(int a);



int main(void)
{
	int height;

	do
	{
		height = get_int("Height: ");
	}
	while (height > 8 || height <= 0);

	//Making the pyramid
	int counter = 1;
	do
	{
		spaces(height - counter);
		hashtag(counter);
		printf("  ");
		hashtag(counter);
		printf("\n");
		counter++;
	}
	while (height >= counter);

}

//functions
void spaces(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" ");
	}
}

void hashtag(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("#");
	}
}
