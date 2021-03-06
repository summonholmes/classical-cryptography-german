#include <ctype.h>

int preprocess(char *nachtlied_text)
{
    /* Two concurrent pointers for character traversal */
    char *rawtext = nachtlied_text, *plaintext = nachtlied_text;
    int nachtlied_processed_size = 0; /* For reallocation */

    while (*rawtext)
    {
        if (isspace((unsigned char)*rawtext) || (ispunct((unsigned char)*rawtext)))
        {
            /* Remove/skip spaces and punctuation */
            rawtext++;
        }
        else
        {
            /* Increment malloc counter */
            nachtlied_processed_size += 1;
            if (isupper((unsigned char)*rawtext))
            {
                /* Convert upper to lower */
                *plaintext++ = tolower((unsigned char)*rawtext);
                rawtext++;
            }
            else if (*rawtext == -100)
            {
                /* Ü isn't captured by ctype */
                *plaintext++ = -68;
                rawtext++;
            }
            else
            {
                /* Copy and increment */
                *plaintext++ = *rawtext++;
            }
        }
    }
    /* Cleanup  */
    *plaintext = 0;

    return nachtlied_processed_size;
}