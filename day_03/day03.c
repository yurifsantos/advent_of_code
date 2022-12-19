/*  Third day of Advent of Code 2022.
    I'll probably won't be able to finish in time this year.
    Whoever, I'll be finishing it regardless.
    Maybe next year I'll be able to keep up with the daily challagens.
    Who knows? Anyway, let's keep coding!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UPPER_LETTER_DIFF 38
#define LOWER_LETTER_DIFF 96

int part_1(FILE* data);
int part_2(FILE* data);
void split_array(char* array, char* left_array, char* right_array);
char find_letter(char* first_array, char* second_array, char* third_array);

int main(int argc, char* argv[])
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

    int result = (part_choice == 1 ? part_1(input) : part_2(input));

    fclose(input);

    printf("Result: %d\n", result);
    
    return 0;
}

int part_1(FILE* data)
{
    char rucksack[52];
    char left_rucksack[26], right_rucksack[26];
    int total_sum = 0;

    while ((fgets(rucksack, sizeof(rucksack), data)) != NULL)
    {
        rucksack[strlen(rucksack) - 2] = '\0';
        split_array(rucksack, left_rucksack, right_rucksack);
        
        for(int i = 0; i < strlen(left_rucksack); i++)
        {
            char* letter = strchr(right_rucksack, left_rucksack[i]);
            if (letter != NULL)
            {
                if (isupper(*letter))
                {
                    total_sum += (*letter - UPPER_LETTER_DIFF);
                } else
                {
                    total_sum += (*letter - LOWER_LETTER_DIFF);
                }
                break;
            }
        }
    }

    return total_sum;
}

int part_2(FILE* data)
{
    char rucksacks[3][52];
    char rucksack_01[52], rucksack_02[52], rucksack_03[52];
    int rucksack_count = 0, total_sum = 0;

    while ((fgets(rucksacks[rucksack_count], 52, data)) != NULL)
    {
        rucksacks[rucksack_count][strlen(rucksacks[rucksack_count]) - 2] = '\0';
        if (rucksack_count == 2)
        {
            char letter = find_letter(rucksacks[0], rucksacks[1], rucksacks[2]);
            if (isupper(letter))
            {
                total_sum += (letter - UPPER_LETTER_DIFF);
            } else
            {
                total_sum += (letter - LOWER_LETTER_DIFF);
            }
        }
        rucksack_count++;
        if (rucksack_count == 3)
        {
            rucksack_count = 0;
        } 
    }
    return total_sum;
}

void split_array(char* array, char* left_array, char* right_array)
{
    int len = strlen(array);
    int first_half = len/2;
    int second_half = len - first_half;
    memcpy(left_array, array, first_half);
    left_array[first_half] = '\0';
    memcpy(right_array, array + first_half, second_half);
    right_array[second_half] = '\0';
}

char find_letter(char* first_array, char* second_array, char* third_array)
{
    for (int i = 0; i < strlen(first_array); i++)
    {
        if ((strchr(second_array, first_array[i]) != NULL) && 
            (strchr(third_array, first_array[i]) != NULL))
            {
                return first_array[i];
            }
    }
}