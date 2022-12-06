#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //  Setting up the path to the file to be read;
    FILE* file_path;
    //  Opening the file
    file_path = fopen("../day01_input.txt", "r");

    //  Setting up the variables for the challange;
    char calories[8];

    int elfs_calories = 0;
    int max_calories = 0; 
    int second_max = 0;
    int third_max = 0;

    //  Just checking if the file was successfully opened;
    if (NULL == file_path)
    {
        printf("It wasn't possible to open the file\n");
    }

    //  The whole magics happens here. I'll be using fgets for it is
    //  how I learned how to read from a file. 
    while (fgets(calories, 8, file_path) != NULL)
    {
        if (strcmp(calories, "\n") == 0 || strcmp(calories, "\r\n") == 0)
        {
            elfs_calories = 0;
        } else
        {
            elfs_calories += atoi(calories);
        }

        if (elfs_calories > max_calories)
        {
            third_max = second_max;
            second_max = max_calories;
            max_calories = elfs_calories;
        }else if (elfs_calories > second_max)
        {
            third_max = second_max;
            second_max = elfs_calories;
        }else if (elfs_calories > third_max)
        {
            third_max = elfs_calories;
        }
    }

    //  Closing the file
    fclose(file_path);

    int total_calories = max_calories + second_max + third_max;

    printf("The elf with the most calories is carrying %d calories.\n\r"
            "The elf with the second most calories is carrying %d calories.\r\n"
            "The elf with the third most calories is carrying %d calories.\r\n"
            "In total, the three of them are carrying %d calories\r\n!",
            max_calories, second_max, third_max, total_calories);

    return 0;
}