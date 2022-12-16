/*  Second day of Advent of Code 2022. 
    Will be doing it in C from now on due to
    I need to train my C skill a bit more. 
    Wish me luck!
*/

#include <stdio.h>
#include <stdlib.h>

#define PART_1 1
#define PART_2 2

typedef enum
{
    rock = 1,
    paper = 2, 
    scissor = 3,
    lost = 0,
    draw = 3,
    win = 6,
} decision_values_t;

/*  Creating the prototypes of the functions I'll be using  */
int jokenpo(FILE* data, int part);
int result_1(char opponent, char me);
int result_2(char opponent, char me);

int main (int argc, char* argv[])
{
    FILE* input = NULL;
    int part_choice;

    if (argc != 2)
    {
        fprintf(stderr, "A file must be provided as paramenter as you invoke the exe. "
                "Please, rerun the program and provide the path to a valid file input\n");
        exit(EXIT_FAILURE);
    }

    if ((input = fopen(argv[1], "r")) == NULL)
    {
        printf("\nUnable to open the file.\n"
                "Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    printf("Part to Solve: ");
    scanf("%d", &part_choice);

    int result = jokenpo(input, part_choice);

    fclose(input);

    printf("Result : %d\n", result);

}

int jokenpo(FILE* data, int part)
{
    char play[4];
    int total_sum = 0;

    while ((fgets(play, sizeof(play), data)) != NULL)
    {
        if (part == PART_1)
        {
            total_sum += result_1(play[0], play[2]);
        } else 
        {
            total_sum += result_2(play[0], play[2]);
        }
    }

    return total_sum;
}

int result_1(char opponent, char me)
{
    if (me == 'X')
    {
        if (opponent == 'A')
        {
            return rock + draw;
        }
        if (opponent == 'B')
        {
            return rock + lost;
        }
        if (opponent == 'C')
        {
            return rock + win;
        }
    } else if (me == 'Y')
    {
        if (opponent == 'A')
        {
            return paper + win;
        }
        if (opponent == 'B')
        {
            return paper + draw;
        }
        if (opponent == 'C')
        {
            return paper + lost;
        }
    } else if (me == 'Z')
    {
        if (opponent == 'A')
        {
            return scissor + lost;
        }
        if (opponent == 'B')
        {
            return scissor + win;
        }
        if (opponent == 'C')
        {
            return scissor + draw;
        }
    }
}

int result_2(char opponent, char me)
{
    if (me == 'X')
    {
        if (opponent == 'A')
        {
            return scissor + lost;
        }
        if (opponent == 'B')
        {
            return rock + lost;
        }
        if (opponent == 'C')
        {
            return paper + lost;
        }
    } else if (me == 'Y')
    {
        if (opponent == 'A')
        {
            return rock + draw;
        }
        if (opponent == 'B')
        {
            return paper + draw;
        }
        if (opponent == 'C')
        {
            return scissor + draw;
        }
    } else if (me == 'Z')
    {
        if (opponent == 'A')
        {
            return paper + win;
        }
        if (opponent == 'B')
        {
            return scissor + win;
        }
        if (opponent == 'C')
        {
            return rock + win;
        }
    }
}