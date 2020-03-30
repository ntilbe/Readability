// Readability.cpp 

#include <iostream>
#include <string>

using namespace std;

int count_letters(string s)
{
    int count_letters_total = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]) != 0)
        {
            count_letters_total = count_letters_total + 1;
        }
    }
    return count_letters_total;

}

int count_words(string s)
{
    int count_words_total = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isblank(s[i]) != 0)
        {
            count_words_total = count_words_total + 1;
        }
    }
    return count_words_total + 1;

}

int count_sentences(string s)
{
    int count_sentences_total = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count_sentences_total = count_sentences_total + 1;
        }
    }
    return count_sentences_total;

}

int main(void)
{
    string s;
    cout << "Text: ";
    getline(cin, s);

    float L = (float)count_letters(s) / (float)count_words(s) * 100.0;
    float S = (float)count_sentences(s) / (float)count_words(s) * 100.0;


    int index = 0;
    index = round(0.0588 * L - 0.296 * S - 15.8);

    cout << "Text: " << s << endl;

    if (index < 1)
    {
        cout << "Before Grade 1\n";
    }
    else if (index >= 16)
    {
        cout << "Grade 16+\n";
    }
    else
    {
        cout << "Grade " << index << endl;
    }

}

