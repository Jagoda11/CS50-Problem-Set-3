//program that ask a user for a number of elements n (max 100) then prompt the user n times
//to get the n elements and store them in an array:
//function that takes an array and its size and returns the average of its elements

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
    int n;
    do
    {
        printf("please give me a number beteen 1 and 100: ");
        scanf("%i", &n);
    }
    while (n < 0 || n > 100);

    int *alpha = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%i", alpha + i);
    }


    for (int i = 0; i < n; i++)
    {
        printf("%i,", alpha[i]);
    }

    int len = n;
    printf("\n");

    printf("the maximum is: %i\n", max(len, alpha));
    printf("the minimum is: %i\n", min(len, alpha));
    printf("the average is: %lf\n", avg(len, alpha));
    printf("the gap between maximum and minimum is: %i\n", gap(len, alpha));
    printf("the second maximum is: %i\n", second_maximum(len, alpha));
    rev(alpha, len);
    every_second(len, alpha);
    even_numbers(len, alpha);
    new_array(len, alpha);


}
// function that takes an array and its size and returns the maximum value of its elements.
int max(int len, int alpha[])
{
    int maximum = 0;
    for (int i = 0; i < len; i++)
    {
        if (alpha[i] > maximum)
        {
            maximum = alpha[i];
        }
    }

    return maximum;
}
//a function that takes an array and its size and returns the minimum value of its elements
int min(int len, int alpha[])
{
    int minimum = alpha[0];
    for (int i = 1; i < len; i++)
    {
        if (alpha[i] < minimum)
        {
            minimum = alpha[i];
        }
    }

    return minimum;
}
//average between minimum and maximum
double avg(int len, int *alpha)
{
    double sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum = sum + alpha[i];
    }
    double avg_value = sum / len;
    return avg_value;
}

//function that takes an array and its size and returns its gap value
//(the gap is the difference between the max and min)

int gap(int len, int *alpha)
{
    return max(len, alpha) - min(len, alpha);

}

//function that takes an array and its size and returns the second maximum value of its elements.
int second_maximum(int len, int *alpha)
{
    int maximum2 = INT_MIN;

    for (int i = 0; i < len; i++)
    {

        if (alpha[i] > maximum2 && alpha[i] < max(len, alpha))

        {

            maximum2 = alpha[i];

        }
    }

    return maximum2;
}

//takes an array and its size and returns a new array as a reverse of the input array

int *rev(int *alpha, int len)

{

    int *reversed = malloc(len * sizeof(int));

    for (int i = len - 1, j = 0; i >= 0; i--, j++)

    {

        reversed[j] = alpha[i];

    }

    return reversed;

}



//function that takes an array and its size and returns a new array with every second element of the first array
int *every_second(int len, int *alpha)
{

    int *second_elements = malloc((len / 2) * sizeof(int));

    for (int i = 1, j = 0; i < len; i += 2, j++)

    {

        second_elements[j] = alpha[i];

    }

    return second_elements;

}

//function that takes an array and its size and returns a new array with only even numbers

int *even_numbers(int len, int *alpha)

{

    int counter = 0;

    int j = 0;


    for (int i = 0; i < len; i++)

    {

        if (alpha[i] % 2 == 0)

        {

            counter++;

        }

    }

    int new_len = counter;



    int *even = malloc(new_len * sizeof(int));

    for (int i = 0; i < len; i++)

    {

        if (alpha[i] % 2 == 0)

        {

            even[j] = alpha[i];

            j++;

        }

    }

    printf("Array with even numbers is: ");

    for (int i = 0; i < new_len; i++)

    {

        printf("%i ", even[i]);

    }

    printf("\n");

    return 0;
}

//function that takes an array and its size, then split the array by half into 2 arrays,

// then create a new array and return it by merging the 2 arrays element by element

int *new_array(int len, int *alpha)

{

    int new_len;

    if (len % 2 == 0)

    {

        new_len = ceil(len / 2);

    }


    if (len % 2 != 0)

    {

        new_len = ceil(len / 2) + 1;

    }


    int *new_alpha = malloc(len * sizeof(int));

    int counter = 0;

    for (int i = 0, j = i + new_len; i < new_len; i++, j++)

    {

        new_alpha[counter] = alpha[i];

        counter++;

        if (j < len)

        {

            new_alpha[counter] = alpha[j];

            counter++;

        }

    }

    printf("Merged arrays: ");

    for (int i = 0; i < len; i++)

    {

        printf("%i ", new_alpha[i]);

    }

    printf("\n");

    return 0;

}