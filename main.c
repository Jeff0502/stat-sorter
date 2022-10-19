#include <stdio.h>
#include <stdlib.h>
// Wil nie in powershell werk nie, dus gebruik dit in cmd
int sort(const void *n1, const void *n2)
{
    return ( *(double *)n1 - *(double *)n2);
}

int main(int argc, char const **argv)
{
    double mean = 0;
    double *numbers = calloc(50, sizeof(double));

    int size = 0;

    // 1 is the delimter
    char del = argv[1][0];

    if(del != ';' && del != ',')
    {
        del = '\0';
    }

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == del && del != '\0')
            continue;

        else
        {
            sscanf(argv[i], "%lf", &numbers[size]);
            size++;
        }
    }

    qsort(numbers, size, sizeof(numbers[0]), sort);

    printf("\n");

    for(int i = 0; i < size; i++)
    {
        mean += numbers[i];
        printf("%.2lf ", numbers[i]);
    }

    // Calculate the median, q1 and q3
    float q1 = numbers[((size + 1) / 4) - 1];
    float q2 = numbers[((size + 1) / 2) - 1];
    float q3 = numbers[(size + 1) * (3 / 4)];

    mean /= size;
    printf("\nMean: %.2lf", mean);
    printf("\nQ1: %.2lf\nQ2: %.2lf\nQ3: %.2lf", q1, q2, q3);

    return 0;
}

