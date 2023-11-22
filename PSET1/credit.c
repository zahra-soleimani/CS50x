#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNum = get_long("Number: ");
    int i = 0;
    long count = cardNum;
    // count digits
    while (count > 0)
    {
        count = count / 10;
        i++;
    }
    // check digits
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    // calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long card = cardNum;
    int totalSum = 0;
    int mod1;
    int mod2;
    int x1;
    int x2;

    do
    {
        mod1 = card % 10;
        card = card / 10;
        sum1 += mod1;
        mod2 = card % 10;
        card = card / 10;
        mod2 = mod2 * 2;
        x1 = mod2 % 10;
        x2 = mod2 / 10;
        sum2 = sum2 + x1 + x2;
    }
    while (card > 0);

    totalSum = sum1 + sum2;

    if (totalSum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // check first digits
    long firstDigits = cardNum;
    do
    {
        firstDigits = firstDigits / 10;
    }
    while (firstDigits > 100);

    long fDigit = cardNum;
    do
    {
        fDigit = fDigit / 10;
    }
    while (fDigit > 10);
    // AMEX card
    if (i == 15 && (firstDigits == 34 || firstDigits == 37))
    {
        printf("AMEX\n");
    }
    // MASTERCARD
    else if (i == 16 && (firstDigits == 51 || firstDigits == 52 || firstDigits == 53 || firstDigits == 54 || firstDigits == 55))
    {
        printf("MASTERCARD\n");
    }
    // VISA card
    else if (i == 13 && (fDigit == 4))
    {
        printf("VISA\n");
    }
    else if (i == 16 && (fDigit == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}