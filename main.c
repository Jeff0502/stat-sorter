#include <stdio.h>
#include <stdlib.h>
// Wil nie in powershell werk nie, dus gebruik dit in cmd
int sort(const void *n1, const void *n2)
{
    return ( *(double *)n1 - *(double *)n2);
}

int main(int argc, char const **argv)
{
    
    double *numbers = calloc(50, sizeof(double));

    int size = 0;

    // 1 is the delimter
    char del = argv[1][0];

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == del)
            continue;

        else
        {
            sscanf(argv[i], "%lf", &numbers[size]);
            size++;
        }
    }

    qsort(numbers, size, sizeof(numbers[0]), sort);

    
    for(int i = 0; i < size; i++)
    {
        printf("%.2lf ", numbers[i]);
    }

    return 0;
}

