#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include <ctype.h>

// Function declaration for case-insensitive substring search
char *strcasestr(const char *haystack, const char *needle);

int main(void) {
    // Allocate memory for the text and prompt the user 📝
    char *text = malloc(100 * sizeof(char));
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed 💥\n");
        return 1;
    }
    printf("Text, please: ");
    scanf("%[^\n]", text);

    // Allocate memory for the keyword and prompt the user 🔑
    printf("Key, please: ");
    char *keyword = malloc(100 * sizeof(char));
    if (keyword == NULL) {
        fprintf(stderr, "Memory allocation failed 💥\n");
        free(text);
        return 1;
    }
    scanf("%s", keyword);

    // Search for the keyword in the text, ignoring case 🕵️‍♂️
    char *ptr = strcasestr(text, keyword);

    // Report the result of the search 📊
    if (ptr != NULL) {
        int position = ptr - text;  // Calculate the position
        printf("The word '%s' is found at position %i\n", keyword, position);
    } else {
        printf("The word '%s' is not found in the text\n", keyword);
    }

    // Free allocated memory 🧹
    free(text);
    free(keyword);
    return 0;
}
