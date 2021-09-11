#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt for text
    string text = get_string("Text: ");
    
    int letters = 0;
    int words = 0;
    int sentences = 0;
    
    // Iterate over text for number of letters, words and sentences
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]) || islower(text[i])) 
        {
            letters++; 
        }
        
        if (text[i] == ' ')
        {
            words++;
        }
        
        if (text[i] == '.')
        {
            sentences++;
        }
        
        if (text[i] == '?')
        {
            sentences++;
        }
        
        if (text[i] == '!')
        {
            sentences++;
        }
    }
    words++;
    
    // Calculate Coleman-Liau index
    float l = (float)letters * 100 / (float)words;
    float s = (float)sentences * 100 / (float)words;
    
    float index = 0.0588 * l - 0.296 * s - 15.8;
    index = round(index);
    
    // Print grade result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    
    if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", (int)index);
    }
}