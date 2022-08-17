#include <stdio.h>
#include <stdlib.h> // For system("cls")
#include <conio.h>  // For getch()
#include <time.h>   // For time()

void shuffle(int *);
int isSorted(int *);
void initializeArray(int *);
void display(int [4][4]);
void upKey(int [4][4], int [2]);
void downKey(int [4][4], int [2]);
void leftKey(int [4][4], int [2]);
void rightKey(int [4][4], int [2]);

int main() {
    char player[30];
    int move, ch, pos[2], arr[4][4];
    
    /* Initialization */
    move = 500;
    pos[0] = 3, pos[1] = 3;
    initializeArray(*arr);

    printf("Enter Player Name: ");
    scanf("%[^\n]s", player);
    system("cls");

    printf("\n\t\t:NUMBER SHIFTING GAME:\n");
    printf("\n\t\t   RULE OF THE GAME\n");
    printf("\n1. You can move only 1 step at a time with the arrow key.");
    printf("\n\tMove Up    : By Up Arrow Key");
    printf("\n\tMove Down  : By Down Arrow Key");
    printf("\n\tMove Left  : By Left Arrow Key");
    printf("\n\tMove Right : By Right Arrow Key");
    printf("\n\n2. You can move numbers at an empty position only.");
    printf("\n\n3. For each valid move : your total number of moves will be decrease by 1.");
    printf("\n\n4. Number in a 4*4 matrix should be in order from 1 to 15");
    printf("\n\t Winning Situation:");
    display(arr);
    printf("\n5. You can exit the game at any time by pressing 'E' or 'e'");
    printf("\n\tTry to win in minimum no. of moves");
    printf("\n\n\t    Happy gaming , Good Luck");
    printf("\n\nEnter any key to start.....    ");

    getch();

    do {
        /* Shuffling the array */
        shuffle(*arr);

        do {
            system("cls");
            printf("\nHello %s , Move remaining : %d\n", player, move);    
            display(arr);

            switch(ch = getch()) 
            {
                case 0:
                case 224:
                    switch (ch = getch())
                    {
                        case 72: // Up key
                            upKey(arr, pos);
                            break;
                        case 80: // Down key
                            downKey(arr, pos);
                            break;
                        case 75: // Left key
                            leftKey(arr, pos);
                            break;
                        case 77: // Right key
                            rightKey(arr, pos);
                    }
                    break;
                case 'e':
                case 'E':
                    exit(0);
                    break;
            } 
            move--;

            if (isSorted(*arr)) {
                system("cls");
                display(arr);
                printf("\n\tCongrats ! You Won.\n\n");
                break;
            }

            if (move == 0) {
                system("cls");
                printf("\n\tOops ! You Lost.\n\n");
                break;
            }

        } while(1);

        /* Initialization */
        move = 500;
        pos[0] = 3, pos[1] = 3;
        initializeArray(*arr);

        printf("Press 'y' to play again else press any key to stop.... ");
        ch = getch();        
        
    } while(ch == 'y' || ch == 'Y');

    return 0;
}

void shuffle(int *p) {
    int i, j, tmp;

    srand(time(0));
    for(i=0; i<15; i++) {
        j = rand() % 15;
        tmp =  *(p+i);
        *(p+i) = *(p+j);
        *(p+j) = tmp;
    }
}

int isSorted(int *p) {
    int i;

    for(i=0; i<15; i++) {
        if (*(p+i) > *(p+i+1))
            return 0;
    }
    return 1;
}

void initializeArray(int *p) {
    int i;

    for(i=0; i<15; i++) {
        *(p+i) = i+1;
    }
    *(p+i) = ' ';
}

void display(int arr[4][4]) {
    int i, j;

    printf("\n\t---------------------\n\t|");
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            if (arr[i][j] == ' ')
                printf(" %2c |", arr[i][j]);
            else 
                printf(" %2d |", arr[i][j]);
        }
        printf("\n\t|");
    }
    printf("\b---------------------\n");
}

void upKey(int arr[4][4], int pos[2]) {
    int i, j;

    i = pos[0] - 1;
    j = pos[1];
    if (i >= 0 && i <= 3) {
        arr[pos[0]][j] = arr[i][j];
        arr[i][j] = ' ';
        pos[0] = i;
    }
}

void downKey(int arr[4][4], int pos[2]) {
    int i, j;

    i = pos[0] + 1;
    j = pos[1];
    if (i >= 0 && i <= 3) {
        arr[pos[0]][j] = arr[i][j];
        arr[i][j] = ' ';
        pos[0] = i;
    }
}

void leftKey(int arr[4][4], int pos[2]) {
    int i, j;

    i = pos[0];
    j = pos[1] - 1;
    if (j >= 0 && j <= 3) {
        arr[i][pos[1]] = arr[i][j];
        arr[i][j] = ' ';
        pos[1] = j;
    }
}

void rightKey(int arr[4][4], int pos[2]) {
    int i, j;

    i = pos[0];
    j = pos[1] + 1;
    if (j >= 0 && j <= 3) {
        arr[i][pos[1]] = arr[i][j];
        arr[i][j] = ' ';
        pos[1] = j;
    }
}