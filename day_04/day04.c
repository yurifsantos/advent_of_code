/*  Fourth day of Advent of Code
    No message today, just code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int find_overlaps(FILE* data, int part);
int is_section_fully_inside(int* section_array);
int is_section_part_inside(int* section_array);

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

    int result = find_overlaps(input, part_choice);

    fclose(input);

    printf("Result: %d\n", result);
    
    return 0;
}

int find_overlaps(FILE* data, int part_choice)
{
    int section_array[4] = {0}, total_sum = 0;

    while (fscanf(data, "%d-%d,%d-%d", &section_array[0], &section_array[1], &section_array[2], &section_array[3]) == 4)
    {
        if (part_choice == 1)
        {
            total_sum += is_section_fully_inside(section_array);
        } else if (part_choice == 2)
        {
            total_sum += is_section_part_inside(section_array);
        }
    }
    return total_sum;
}

int is_section_fully_inside(int *section_array)
{
    if (((section_array[0] <= section_array[2]) && (section_array[3] <= section_array[1])) ||
        ((section_array[2] <= section_array[0]) && (section_array[1] <= section_array[3])))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_section_part_inside(int *section_array)
{
    if (((section_array[0] <= section_array[2]) && (section_array[2] <= section_array[1])) ||
        ((section_array[2] <= section_array[0]) && (section_array[0] <= section_array[3])))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}