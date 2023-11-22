#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startNum;
    do
    {
        startNum = get_int("Start size: ");
    }
    while (startNum < 9);

    // TODO: Prompt for end size
    int endNum;
    do
    {
        endNum = get_int("End size: ");
    }
    while (endNum < startNum);

    // TODO: Calculate number of years until we reach threshold
    int Years = 0;
    while (startNum < endNum)
    {
        startNum = startNum + (startNum / 3) - (startNum / 4);
        Years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", Years);
}
