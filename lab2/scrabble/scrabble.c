#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string upper(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    upper(word1);
    upper(word2);


    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie!\n");
    }
}


//Function uppercase
string upper(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (islower(word[i]))
        {
            word[i] = toupper(word[i]);
        }

    }
    return word;
}

//Function that gives the score
int compute_score(string word)
{
    int i = 65 ;
    int l = 0;
    int nscore = 0;
    do
    {
        if (word[l] == i)
        {
            nscore += POINTS[i - 65];
            l++;
            i = 65;
        }


        else if (word[l] != i)
        {
            i++;
            if (i > 122)
            {
                nscore += 0;
                l++;
                i = 65;
            }
        }


    }
    while (word[l] != 0);
    return nscore;

}






