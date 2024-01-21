#include <cs50.h>
#include <math.h>
#include <stdio.h>

long get_valid_card_number();
string get_card_number_type(long card_number);
bool is_card_checksum_valid(long card_number, int digits_count);
int calculate_checksum(long card_number, int digits_count);
int number_of_digits(long card_number);
int starting_two_digits(long card_number, int number_of_digits);
int digits_sum(int number);

int main(void)
{
    long card_number = get_valid_card_number();
    string card_number_type = get_card_number_type(card_number);
    printf("%s\n", card_number_type);
}

long get_valid_card_number()
{
    long card_number = 0;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number == 0);

    return card_number;
}

string get_card_number_type(long card_number)
{
    const string Invalid_ID = "INVALID";
    const string American_Express_ID = "AMEX";
    const string Master_Card_ID = "MASTERCARD";
    const string Visa_ID = "VISA";

    int digits_count = number_of_digits(card_number);

    // checksum validation
    bool is_checksum_valid = is_card_checksum_valid(card_number, digits_count);
    if (!is_checksum_valid)
    {
        return Invalid_ID;
    }

    // iterating over card types
    int leading_digits = starting_two_digits(card_number, digits_count);

    if (digits_count == 15 && (leading_digits == 34 || leading_digits == 37))
    {
        return American_Express_ID;
    }
    else if (digits_count == 16 &&
             (leading_digits == 51 || leading_digits == 52 || leading_digits == 53 || leading_digits == 54 || leading_digits == 55))
    {
        return Master_Card_ID;
    }
    else if ((digits_count == 13 || digits_count == 16) && leading_digits / 10 == 4)
    {
        return Visa_ID;
    }
    else
    {
        return Invalid_ID;
    }
}

bool is_card_checksum_valid(long card_number, int digits_count)
{
    int card_checksum = calculate_checksum(card_number, digits_count);
    // checksum is valid if its leading number is 0 (total modulo 10 is congruent to 0)
    return (card_checksum % 10) == 0;
}

int calculate_checksum(long card_number, int digits_count)
{
    // Let's make a local copy not to mess up the initial value
    long temporary_card_number = card_number;
    // collects sum of numbers(digits) on even indices
    int even_register = 0;
    // collects sum of numbers(digits) on odd indices
    int odd_register = 0;

    for (int i = 1; i <= digits_count; i++)
    {
        // represents digit in index i of the card number
        int digit = temporary_card_number % 10;

        if (i % 2 == 0)
        {
            // digit on even position
            int sum_of_digits = digits_sum(digit * 2);
            even_register += sum_of_digits;
        }
        else
        {
            // digit on odd position
            odd_register += digit;
        }

        // we are "cutting off" last digit from card number on each loop cycle
        temporary_card_number = temporary_card_number / 10;
    }

    return even_register + odd_register;
}

int number_of_digits(long card_number)
{
    int digits_counter = 0;
    // Let's make a local copy not to mess up the initial value
    long temporary_card_number = card_number;
    do
    {
        temporary_card_number = temporary_card_number / 10;
        digits_counter++;
    }
    while (temporary_card_number > 0);

    return digits_counter;
}

int starting_two_digits(long card_number, int number_of_digits)
{
    long denominator = pow(10, (number_of_digits - 2));
    return card_number / denominator;
}

int digits_sum(int number)
{
    int sum = 0;
    int temporary_number = number;
    do
    {
        int digit = temporary_number % 10;
        sum += digit;
        temporary_number = temporary_number / 10;
    }
    while (temporary_number > 0);
    return sum;
}
