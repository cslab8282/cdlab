#include <stdio.h>
#include <string.h>

int main()
{
    char line[100];
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        perror("Error opening the file");
        return 1;
    }
    char variable;
    int value;
    int variables[26];        // Assuming variables are single letters from 'a' to 'z
    int variableAssigned[26]; // Keep track of whether a variable has been assigned

    for (int i = 0; i < 26; i++)
    {
        variables[i] = 0;
        variableAssigned[i] = 0;
    }
    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, " %c = %d;", &variable, &value) == 2)
        {
            if (variable >= 'a' && variable <= 'z')
            {
                variables[variable - 'a'] = value;
                variableAssigned[variable - 'a'] = 1;
            }
        }
        else
        {
            for (int i = 0; line[i] != '\0'; i++)
            {
                if (line[i] >= 'a' && line[i] <= 'z' && variableAssigned[line[i] - 'a'])
                {
                    line[i] = variables[line[i] - 'a'] + '0';
                }
            }
            printf("%s", line);
        }
    }
    printf("\n");
    fclose(file);
    return 0;
}
