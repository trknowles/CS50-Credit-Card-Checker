#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Promt user for card number
    long number = get_long("Number: ");
    long temp = number; // A temp copy for calculations

    int sum = 0;   // Will store total sum for Luhn's algorithm
    int digit;     // Varible to extract each card digit
    int count = 0; // To track the position of the digits

    // Luhn's algorithm - runs whilst there are still digits in 'temp'
    while (temp > 0)
    {
        digit = temp % 10; // Extract the last digit from the card number

        // If position is even (0 indexed from right), add digit directly
        if (count % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            // If digit is in an ODD position double it
            int doubled = digit * 2;
            // If the doubled value is a two digit number, add both of them individually e.g. 7 * 2
            // = 14 - 1 + 4 = 5
            sum += doubled / 10 + doubled % 10;
        }
        // Remove the last digit from temp
        temp /= 10;
        // Move to the end digit position
        count++;
    }

    // Check validity
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine card type
    // Extract starting two digits
    long start = number;
    while (start >= 100)
    {
        start /= 10;
    }

    // Check card type based on length and starting digits
    if ((start == 34 || start == 37) && count == 15)
    {
        printf("AMEX\n");
    }
    else if ((start >= 51 && start <= 55) && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 4 || start == 4) && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
