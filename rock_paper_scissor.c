
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the choice that is choosed 
void printChoice(char c) {
    if (c == 'r') printf("Rock");
    else if (c == 'p') printf("Paper");
    else if (c == 's') printf("Scissors");
}

// Function to generate random number in range [0, n) for computer choice 
int getRandom(int n) {
    return rand() % n;
}

//Function that Returns: 1 if p1 wins, 0 if p2 wins, -1 if draw
int compare(char p1, char p2) {
    if (p1 == p2){
     return -1;
    }
 else if ((p1 == 'r' && p2 == 's') ||(p1 == 'p' && p2 == 'r') ||(p1 == 's' && p2 == 'p'))      
        return 1;
    else
        return 0;
}

int main() {
    srand(time(0));

    int playerscore = 0, compscore = 0;
    char dict[] = {'r', 'p', 's'};
    int choice;

    printf("######################################\n");
    printf("        ROCK PAPER SCISSORS GAME       \n");
    printf("######################################\n\n");

    while (playerscore < 3 && compscore < 3) { // loops that runs till anyone reaches score of 3 
        printf("Your Turn! Choose:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) { // Take care of wrong or mistake choices
            printf("Invalid choice! Try again.\n\n");
            continue; // to skip this iteration of loop and moves for next iteration 
        }

        char player = dict[choice - 1];
        char cpu = dict[getRandom(3)]; // as getrandom returns int in the range of [0,3) so we can directly use it for index 

        printf("\nYou chose: ");
        printChoice(player); // to print what user and comp choosed 
        printf("\nCPU chose: ");
        printChoice(cpu);
        printf("\n");

        int result = compare(player, cpu);

        if (result == 1) {
            playerscore++;
            printf(">> You won this round!\n");
        } else if (result == -1) {
            printf(">> It's a draw.\n");
        } else {
            compscore++;
            printf(">> CPU won this round.\n");
        }

        printf("Score => You: %d | CPU: %d\n", playerscore, compscore); // prints score in each round 
        printf("-------------------------------------\n\n");
    }

    // Final Result
    printf("\n============ GAME OVER ============\n");
    if (playerscore > compscore)
        printf(" Congratulations! You Win the Game!\n");
    else
        printf("CPU Wins! Better luck next time.\n");

    return 0;
}




