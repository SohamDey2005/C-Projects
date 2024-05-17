#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int random, guess, no_of_guess=0;
    srand(time(NULL));
    printf("\n--------------------------------------------------\n");
    printf("\nWelcome to the World of Number Guessing Game !!!\n");
    random = rand() % 100 + 1; // Generating Random Number between 1 to 100

    do
    {
        printf("\nPlease...Enter your Guess between (1 to 100): ");
        scanf("%d",&guess);
        no_of_guess++;

        if (guess < random)
        {
            printf("\nGuess a Larger Number...\n");
        }
        else if (guess > random)
        {
            printf("\nGuess a Smaller Number...\n");
        }
        else
        {
            printf("\nCongratulations !!! You have Successfully Guessed the Number in %d Attempts.\n",no_of_guess);
        }

    } while (guess != random);

    printf("\nBye Bye, Thanks for Playing.");
    printf("\nDeveloped by: SOHAM DEY \n");
    printf("\n--------------------------------------------------\n\n");
    return 0;
}