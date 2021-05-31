#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start;
    do
    {
        start = get_int("Starting population size: ");
    }
    while (start < 9);

    // Prompt for end size
    int end;
    do
    {
        end = get_int("Ending population size: ");
    }
    while (end < start);


    // Calculate number of years until we reach threshold and print it
    int years = 0;

    if (end == start)
    {
        printf("Years: %i\n", years);
    }

    else
    {
        do
        {
            start = start + (start / 3) - (start / 4);
            years++;
        }
        while (start < end);


        printf("Years: %i\n", years);
    }
}
