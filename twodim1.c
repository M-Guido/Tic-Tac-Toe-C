#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7

int win(char dungeons[SIZE][SIZE], char player){
    int i,j;
    for(i=1; i<=5; i+=2){
        if (dungeons[i][1] == player && dungeons[i][3] == player && dungeons[i][5] == player) return 1;
        if (dungeons[1][i] == player && dungeons[3][i] == player && dungeons[5][i] == player) return 1;
    }
    if (dungeons[1][1] == player && dungeons[3][3] == player && dungeons[5][5] == player) return 1;
    if (dungeons[1][5] == player && dungeons[3][3] == player && dungeons[5][1] == player) return 1;
    
    return 0;
}

int main(){
    srand(time(NULL));
    char dungeons[SIZE][SIZE];
    int i, j;
    char input;
    int is_running = 1;
    char player = 'O';
    int moves = 0;
    int player_choice=1;
    int a, b;

    printf("Tic tac toe! Please select if u want to play vs bot:\n");
    printf("vs Bot press 1 \n");
    printf("Duo press 2 \n");

    scanf("%d", &player_choice);

    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(i%2!=0 && j%2!=0){
                dungeons[i][j]=' ';
            }
            else{
                dungeons[i][j] = '#';
            }
        }
    }

    while(is_running){
        system("cls");

        for(i=0; i<SIZE; i++){
            for(j=0; j<SIZE; j++){
                putchar(dungeons[i][j]);
            }
            putchar('\n');
        }

        int r = 0, c =0;

        if(player_choice==1 && player == 'X'){
            do {
                r = (rand() % 3) * 2 + 1; 
                c = (rand() % 3) * 2 + 1;   
            } while (dungeons[r][c] != ' '); 
        }
        else {
            printf("\nPlayer's turn %c. Select pole which you want to put in 1-9 or 0  to exit: ", player);
            scanf(" %c", &input);
            switch (input) {
                case '1': r=1; c=1; break;
                case '2': r=1; c=3; break;
                case '3': r=1; c=5; break;
                case '4': r=3; c=1; break;
                case '5': r=3; c=3; break;
                case '6': r=3; c=5; break;
                case '7': r=5; c=1; break;
                case '8': r=5; c=3; break;
                case '9': r=5; c=5; break;
                case '0': is_running=0; continue; 
                default: 
                    printf("Undefined choice!\n");
                    while(getchar() != '\n');
                    getchar();
                    continue; 
            }
        }

        if(dungeons[r][c] == ' '){
            dungeons[r][c] = player;
            moves++;

            if(win(dungeons, player)){
                system("cls");
                for(i = 0; i < SIZE; i++) {
                    for(j = 0; j < SIZE; j++){ 
                        putchar(dungeons[i][j]);
                    }
                    putchar('\n');
                }
                printf("\nWinner is %c!\n", player);
                is_running = 0;
            }
            else if(moves == 9){
                system("cls");
                for(i = 0; i < SIZE; i++) {
                    for(j = 0; j < SIZE; j++){ 
                        putchar(dungeons[i][j]);
                    }
                    putchar('\n');
                }
                printf("\nDraw!\n");
                is_running = 0;
            }
            else { 
                if(player == 'O') player = 'X';   
                else player = 'O';
            }
        }
        else {
            printf("Spot is taken! Press Enter to choose another...\n");
            getchar(); getchar(); 
        }
    }
    return 0;
}