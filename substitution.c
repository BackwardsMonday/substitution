#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkKey(string key);
string convert(string text, string key);
string stringToUpper(string text);
string stringToLower(string text);

int main(int argc, string argv[])
{
    string key = argv[1];
    string boldRed = "\033[1;31m";
    string normal = "\033[0;0m";
    if (argc != 2)
    {
        printf("%sArgument error:%s\nUsege is: ./substitution key\n", boldRed, normal);
        return 1;
    }
    if (checkKey(key) == 1)
    {
        printf("%sArgument error:%s\nKey must be 26 alphapatical characters, using each character only once\n", boldRed, normal);
        return 1;
    }
    string plaintext = get_string("plaintext:");
    string ciphertext = convert(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

int checkKey(string key)
{
    int usedLeters[26];
    if (strlen(key) != 26)
    {
        return 1;
    }
    for(int i = 0; i < 26; i++)
    {
        char leter = key[i];
        if(isalpha(leter) == 0)
        {
            return 1;
        }
        for(int j = i; j > 0; j--)
        {
            char leter2 = usedLeters[j];
            if (leter == leter2)
            {
                return 1;
            }
        }
        usedLeters[i] = leter;
    }
    return 0;
}

string stringToLower(string text)
{
    int length = strlen(text);
    for(int i = length; i >= 0; i--)
    {
        text[i] = tolower(text[i]);
    }
    return text;
}

string stringToUpper(string text)
{
    int length = strlen(text);
    for(int i = length; i >= 0; i--)
    {
        text[i] = toupper(text[i]);
    }
    return text;
}

string convert(string text, string key)
{
    int length = strlen(text);
    for(int i = length; i >= 0; i--)
    {
        char letter = text[i];
        if(isupper(letter))
        {
            int place = letter - 65;
            text[i] = toupper(key[place]);
        }
        else if (islower(letter))
        {
            int place = letter - 97;
            text[i] = tolower(key[place]);
        }
    }
    return text;
}