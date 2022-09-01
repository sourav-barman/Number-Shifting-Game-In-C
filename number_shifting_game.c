#include <stdio.h>
#include <stdlib.h> // For system("cls")
#include <conio.h>  // For getch()
#include <time.h>   // For time()

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET   "\x1B[0m"

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
    int move, ch, pos[2], arr[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, ' '};

    printf("Enter Player Name: ");
    scanf("%[^\n]s", player);
    system("cls");

    printf(CYAN "\n\t\t:NUMBER SHIFTING GAME:\n" RESET);
    printf(YELLOW "\n\t\t   RULE OF THE GAME\n" RESET);
    printf(RED "\n1. You can move only 1 step at a time with the arrow key." RESET);
    printf("\n\tMove Up    : By Up Arrow Key");
    printf("\n\tMove Down  : By Down Arrow Key");
    printf("\n\tMove Left  : By Left Arrow Key");
    printf("\n\tMove Right : By Right Arrow Key");
    printf(RED "\n\n2. You can move numbers at an empty position only." RESET);
    printf(RED "\n\n3. For each valid move : your total number of moves will be decrease by 1." RESET);
    printf(RED "\n\n4. Number in a 4*4 matrix should be in order from 1 to 15" RESET);
    printf(YELLOW "\n\t Winning Situation:" RESET);
    display(arr);
    printf(RED "\n5. You can exit the game at any time by pressing 'E' or 'e'" RESET);
    printf("\n\tTry to win in minimum no. of moves");
    printf(YELLOW "\n\n\t    Happy gaming , Good Luck" RESET);
    printf("\n\nEnter any key to start.....    ");

    getch();

    do {
        /* Initialization */
        move = 500;
        pos[0] = 3, pos[1] = 3;
        initializeArray(*arr);

        /* Shuffling the array */
        shuffle(*arr);

        do {
            system("cls");
            printf(YELLOW "\n\t:NUMBER SHIFTING GAME:\n" RESET);
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
            } 
            move--;

            /* Check for win */
            if (isSorted(*arr)) {
                system("cls");
                printf(YELLOW "\n\t:NUMBER SHIFTING GAME:\n" RESET);
                display(arr);
                printf(YELLOW "\n\tCongrats ! You Won the Game.\n\n" RESET);
                break;
            }

            /* Check for move expiry */
            if (move == 0) {
                system("cls");
                printf(YELLOW "\n\tOops ! You Lost the Game.\n\n" RESET);
                break;
            }

        } while(1);

        printf("Press 'y' to play again else press any other key to stop.... ");
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

    printf(CYAN "\n\t---------------------\n\t|" RESET);
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            if (arr[i][j] == ' ')
                printf(CYAN " %2c |" RESET, arr[i][j]);
            else 
                printf(CYAN " %2d |" RESET, arr[i][j]);
        }
        printf(CYAN "\n\t|" RESET);
    }
    printf(CYAN "\b---------------------\n" RESET);
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