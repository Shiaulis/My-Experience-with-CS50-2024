#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string requestText(void);
double calculate_grade(string text);
void output_result(int grade);
bool is_sentence_separator(char character);

int main(void)
{
    string text = requestText();
    int grade = calculate_grade(text);
    output_result(grade);
    return 0;
}

string requestText(void)
{
    return get_string("Text: ");
}

double calculate_grade(string text)
{
    int length = strlen(text);
    int letters = 0;
    int words = 0;
    int sentences = 0;
    for (int i = 0; i < length; i++)
    {
        char character = text[i];

        if (isalpha(character))
        {
            letters++;
        }

        if (isspace(character))
        {
            words++;
        }

        if (is_sentence_separator(character))
        {
            sentences++;
        }
    }

    if (length > 0 && letters > 0)
    {
        // since our assumption of words based on spaces
        // the very last word won't be counted. Exception for empty text
        // or text without letters
        words++;

        if (sentences == 0)
        {
            // if we have sentence text with letters but without punctuation
            // we assume it consists at least 1 sentence
            sentences++;
        }
    }

    double l_value = ((double) letters / (double) words) * 100.0;
    double s_value = ((double) sentences / (double) words) * 100.0;

    // index = 0.0588 * L - 0.296 * S - 15.8
    double index = 0.0588 * l_value - 0.296 * s_value - 15.8;
    return round(index);
}

void output_result(int grade)
{
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

bool is_sentence_separator(char character)
{
    if (character == '.' || character == '!' || character == '?')
    {
        return true;
    }
    else
    {
        return false;
    }
}
