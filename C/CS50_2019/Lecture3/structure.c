#include <stdio.h>
#include <stirng.h>

typedef struct
{
    char *name;
    char *number;
}
person;

int main(void)
{
    person people[4];
    people[0].name ="EMMA";
    people[0].number = "617-555-0100";

    people[1].name = "RODRIGO";
    people[1].number = "617-555-0101";

    people[2].name = "BRAIN";
    people[2].number = "617-555-0102";

    people[3].name = "DAVID";
    people[3].number ="617-555-0103";


    for (int i = 0; i < 4; i++)
    {
        if (strcmp(people[i].name, "EMMA") == 0)
        {
            printf("%s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}