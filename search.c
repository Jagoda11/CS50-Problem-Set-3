#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include <ctype.h>

char *strcasestr(const char *haystack, const char *needle);

int main(void)
{


    char *text =  malloc(100 * sizeof(char));
    printf("Text, please: ");
    scanf("%[^\n]", text);

    printf("Key, please: ");
    char *keyword =  malloc(100 * sizeof(char));
    scanf("%s", keyword);

    char *ptr = strcasestr(text, keyword);

    if (ptr != NULL)
    {
        int position = ptr - text;
        printf("The word %s is found on the position %i\n", keyword, position);
    }
    else
    {
        printf("The word %s is not found in the text\n", keyword);
    }
}