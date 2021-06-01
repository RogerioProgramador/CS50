#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Function
int readability(string text);

int main(void)
{
	//Prompt user for text
	string text1 = get_string("Text: ");

	//Answer
	readability(text1);

}

int readability(string text)
{
	//Counting letters,words and sentences
	int letters = 0;
	int words = 0;
	int sentences = 0;
	int i = 0;

	do
	{
		if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
		{
			letters++;
		}

		else if (text[i] == 32)
		{
			words++;
		}

		else if (text[i] == 46 || text[i] == 33 || text[i] == 63)
		{
			sentences++;
		}

		i++;

		if (i == strlen(text))
		{
			words++;
		}


	}
	while (i < strlen(text));


	//Doing the math
	float L = ((letters * 100) / words);
	float S = ((sentences * 100) / words);
	float index = (0.0588 * L - 0.296 * S - 15.8);
	int grade;

	if ((index - (int)index) > 0.55)
	{
		grade = ((int)index + 1);
	}
	else
	{
		grade = (int)index;
	}


	//Printing Grade
	if (index >= 16)
	{
		printf("Grade 16+\n");

	}
	else if (index < 1)
	{
		printf("Before Grade 1\n");
	}
	else
	{
		printf("Grade %i\n", grade);
	}

	return index;


}
