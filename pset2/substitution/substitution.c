#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int duplicate(string key);
int main(int argc, string argv[])
{
	string cipher = argv[1];

	//checking if there is less or more than 1 key
	if (argc == 1 || argc > 2)
	{
		printf("Usage: ./substitution key\n");
		return 1;
	}

	//checking if the key have less than 26 characters
	else if (strlen(cipher) < 26)
	{
		printf("Key must contain 26 characters.\n");
		return 1;
	}

	//looking for duplicate characters
	duplicate(cipher);


	//encrypting
	if (argc == 2 && strlen(cipher) == 26)
	{

		string plaintext = get_string("plaintext: ");
		printf("ciphertext: ");

		int i = 0;
		int a = 65;

		do
		{
			if (plaintext[i] == a)
			{
				int n = (a - 65);

				char c = toupper(cipher[n]);

				printf("%c", c);

				a = 65;
				i++;
			}

			else if (plaintext[i] == (a + 32))
			{
				int n = (a - 65);
				char c = tolower(cipher[n]);

				printf("%c", c);

				a = 65;
				i++;
			}

			else if (plaintext[i] < 65 || (plaintext[i] > 90 && plaintext[i] < 97) || plaintext[i] > 122)
			{
				printf("%c", plaintext[i]);
				a = 65;
				i++;
			}

			if (plaintext[i] != a && plaintext[i] != (a + 32))
			{
				a++;
			}

		}
		while (i < strlen(plaintext));
		printf("\n");
		return 0;

	}
}

//function: look for duplicate characters
int duplicate(string key)
{
	int d = 0;
	int e = 1;

	do
	{
		if (e == strlen(key))
		{
			d++;
			e = d + 1;
		}

		else if (key[d] == key[e] || key[d] + 32 == key[e] || key[d]  == key[e] + 32)
		{
			printf("Invalid Key\n");
			exit(1);
		}
		else if (key[d] != key[e] || key[d] + 32 != key[e] || key[d]  == key[e] + 32)
		{
			e++;
		}
	}
	while (d < strlen(key));
	return 0;
}
