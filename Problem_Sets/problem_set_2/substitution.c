#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid(string key);
string lowercase(string key);
string make_cypher(string key, string text);

int main(int argc, string argv[])
{
    // getting key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string lowercased_key = lowercase(key);

    // key validation
    if (!is_valid(lowercased_key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // getting plain text
    string plaintext = get_string("plaintext: ");

    // generatic cypher text
    string cyphertext = make_cypher(lowercased_key, plaintext);
    printf("ciphertext: %s\n", cyphertext);

    return 0;
}

bool is_valid(string key)
{
    bool mentionied_characters[26] = {0};
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        char character = key[i];

        if (!isalpha(character))
        {
            return false;
        }

        // index of a character relative to 'a' letter
        int character_index = character - 'a';

        if (mentionied_characters[character_index] == true)
        {
            // found character that was already mentioned
            return false;
        }

        mentionied_characters[character_index] = true;
    }

    return true;
}

string lowercase(string key)
{
    int length = strlen(key);
    string lowercase_key = key;
    for (int i = 0; i < length; i++)
    {
        lowercase_key[i] = tolower(lowercase_key[i]);
    }

    return lowercase_key;
}

string make_cypher(string key, string text)
{
    int length = strlen(text);
    string cypher = text;
    for (int i = 0; i < length; i++)
    {
        char character = text[i];

        if (!isalpha(character))
        {
            cypher[i] = character;
            printf("Character %c should not be replaced", character);
        }
        else if (islower(character))
        {
            int character_index = character - 'a';
            cypher[i] = key[character_index];
            printf("Character %c should be replaced with character %c\n", character, key[character_index]);
        }
        else
        {
            int character_index = character - 'A';
            cypher[i] = toupper(key[character_index]);
            printf("Character %c should be replaced with character %c\n", character, toupper(key[character_index]));
        }
    }

    return cypher;
}
