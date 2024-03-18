#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Function declarations
int max(int len, int alpha[]);
int min(int len, int alpha[]);
double avg(int len, int *alpha);
int gap(int len, int *alpha);
int second_maximum(int len, int *alpha);
int *rev(int *alpha, int len);
int *every_second(int len, int *alpha);
int *even_numbers(int len, int *alpha);
int *new_array(int len, int *alpha);

int main(void)
{
    // Prompt the user to enter the number of elements, ensuring it's between 1 and 100 📏
    int n;
    do
    {
        printf("Please give me a number between 1 and 100 📏: ");
        scanf("%i", &n);
    }
    while (n <= 0 || n > 100);

    // Dynamically allocate memory to store the elements in an array 📦
    int *alpha = malloc(n * sizeof(int));
    if (alpha == NULL) {
        fprintf(stderr, "Memory allocation failed 💥\n");
        return 1;
    }

    // Collect the elements from the user and store them in the array 🔢
    printf("Enter %d elements 🔢: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &alpha[i]);
    }

    // Display the elements stored in the array 🖥️
    printf("Array 🖥️: ");
    for (int i = 0; i < n; i++)
    {
        printf("%i, ", alpha[i]);
    }
    printf("\n");

    // Perform calculations and display the results 📊
    printf("The maximum is: %i 📈\n", max(n, alpha));
    printf("The minimum is: %i 📉\n", min(n, alpha));
    printf("The average is: %.2lf 📊\n", avg(n, alpha));
    printf("The gap between maximum and minimum is: %i 🔍\n", gap(n, alpha));
    printf("The second maximum is: %i 🥈\n", second_maximum(n, alpha));

    // Call functions that manipulate the array and display their results 🔄
    rev(alpha, n);
    every_second(n, alpha);
    even_numbers(n, alpha);
    new_array(n, alpha);

    // Free the allocated memory to prevent memory leaks 🧹
    free(alpha);
}

// Function to find the maximum value in an array 📈
int max(int len, int alpha[])
{
    int maximum = INT_MIN;  // Initialize to the smallest possible value to handle all possible int values
    for (int i = 0; i < len; i++)
    {
        if (alpha[i] > maximum)
        {
            maximum = alpha[i];  // Update maximum if current element is larger
        }
    }
    return maximum;  // Return the maximum value found
}

// Function to find the minimum value in an array 📉
int min(int len, int alpha[])
{
    if (len == 0) return INT_MAX; // Return the largest possible int value if array is empty

    int minimum = alpha[0];  // Initialize minimum with the first element of the array
    for (int i = 1; i < len; i++)
    {
        if (alpha[i] < minimum)
        {
            minimum = alpha[i];  // Update minimum if current element is smaller
        }
    }
    return minimum;  // Return the minimum value found
}

// Function to calculate the average value of an array's elements 📊
double avg(int len, int *alpha)
{
    double sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += alpha[i];  // Sum all elements
    }
    return len > 0 ? sum / len : 0;  // Return the average or 0 for empty array
}

// Function to calculate the gap (difference between max and min) in an array 🔍
int gap(int len, int *alpha)
{
    return max(len, alpha) - min(len, alpha);  // Calculate and return the gap
}

// Function to find the second maximum value in an array 🥈
int second_maximum(int len, int *alpha) {
    int maximum = max(len, alpha);  // First find the maximum value
    int maximum2 = INT_MIN;  // Initialize to the smallest possible value

    for (int i = 0; i < len; i++) {
        // Check if the current element is greater than maximum2 and not equal to the maximum value
        if (alpha[i] > maximum2 && alpha[i] < maximum) {
            maximum2 = alpha[i];  // Update second maximum
        }
    }

    return maximum2;  // Return the second maximum value found
}

// Function to reverse the array 🔄
int *rev(int *alpha, int len) {
    int *reversed = malloc(len * sizeof(int));  // Allocate memory for the reversed array
    if (reversed == NULL) {
        fprintf(stderr, "Memory allocation failed 💥\n");
        return NULL;  // Return NULL if memory allocation fails
    }

    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = alpha[i];  // Reverse the array elements
    }

    return reversed;  // Return the reversed array
}

// Function to return an array with every second element of the input array ✌️
int *every_second(int len, int *alpha) {
    int *second_elements = malloc((len / 2 + len % 2) * sizeof(int));  // Allocate memory for the new array
    if (second_elements == NULL) {
        fprintf(stderr, "Memory allocation failed 💥\n");
        return NULL;  // Return NULL if memory allocation fails
    }

    for (int i = 1, j = 0; i < len; i += 2, j++) {
        second_elements[j] = alpha[i];  // Copy every second element
    }

    return second_elements;  // Return the new array
}

// Function to filter out even numbers from an array 🌟
int *even_numbers(int len, int *alpha) {
    int counter = 0;  // Count how many even numbers are there

    // Count even numbers
    for (int i = 0; i < len; i++) {
        if (alpha[i] % 2 == 0) {
            counter++;
        }
    }

    int *even = malloc(counter * sizeof(int));  // Allocate memory for even numbers
    if (even == NULL) {
        fprintf(stderr, "Memory allocation failed 💥\n");
        return NULL;  // Return NULL if memory allocation fails
    }

    for (int i = 0, j = 0; i < len; i++) {
        if (alpha[i] % 2 == 0) {
            even[j++] = alpha[i];  // Store even numbers
        }
    }

    // Display the array with even numbers
    printf("Array with even numbers is: ");
    for (int i = 0; i < counter; i++) {
        printf("%i ", even[i]);
    }
    printf("\n");

    return even;
}

// Function to merge two halves of an array into a new array alternately 🔀
int *new_array(int len, int *alpha) {
    int new_len = ceil(len / 2.0);  // Determine the new length based on half of the original length

    int *new_alpha = malloc(len * sizeof(int));  // Allocate memory for the new array
    if (new_alpha == NULL) {
        fprintf(stderr, "Memory allocation failed 💥\n");
        return NULL;  // Return NULL if memory allocation fails
    }

    int counter = 0;  // Counter for the new array index
    // Merge two halves alternately
    for (int i = 0, j = new_len; i < new_len; i++, counter++) {
        new_alpha[counter] = alpha[i];  // First half element
        if (j < len) {
            new_alpha[++counter] = alpha[j++];  // Second half element
        }
    }

    // Display the merged array
    printf("Merged arrays: ");
    for (int i = 0; i < len; i++) {
        printf("%i ", new_alpha[i]);
    }
    printf("\n");

    return new_alpha;
}