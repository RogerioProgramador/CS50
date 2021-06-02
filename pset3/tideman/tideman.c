#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];


// Count
int pair_count;
int candidate_count;
int strength[MAX];


// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int     main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool    vote(int rank, string name, int ranks[])
{
    int i;

    i = 0;
    while (candidates[i])
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
        i++;
    }
    return false;
}

// Update preferences given one voter's ranks
void    record_preferences(int ranks[])
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < (candidate_count - 1))
    {
        preferences[ranks[i]][ranks[j]]++;
        j++;
        if (j == candidate_count)
        {
            i++;
            j = i + 1;
        }
    }
    return ;
}

// Record pairs of candidates where one is preferred over the other
void    add_pairs(void)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < (candidate_count - 1))
    {
        if (preferences[i][j] > preferences[j][i])
        {
            pairs[pair_count].winner = i;
            pairs[pair_count].loser = j;
            strength[pair_count] = preferences[i][j] - preferences[j][i];
            pair_count++;
        }
        if (preferences[i][j] < preferences[j][i])
        {
            pairs[pair_count].winner = j;
            pairs[pair_count].loser = i;
            strength[pair_count] = preferences[j][i] - preferences[i][j] ;
            pair_count++;
        }
        j++;
        if (j == candidate_count)
        {
            i++;
            j = i + 1;
        }
    }
    return ;
}

// Sort pairs in decreasing order by strength of victory
void    sort_pairs(void)
{
    int i;
    int j;
    int swap_count;

    swap_count = -1;
    while (swap_count != 0)
    {
        i = 0;
        j = 0;
        swap_count = 0;
        while (i < (pair_count - 1))
        {
            if ((preferences[pairs[j].winner][pairs[j].loser]) < (preferences[pairs[j + 1].winner][pairs[j + 1].loser]))
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
                swap_count++;
            }
            i++;
            j++;
        }
    }
    return ;
}

// Lock pairs into the candidate graph in order, without creating cycles
void    lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void    print_winner(void)
{
    int tmp;
    int i;

    while (strength[i])
    return;
}

