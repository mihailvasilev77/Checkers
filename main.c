#include <stdio.h>
#include <stdlib.h>

enum State{false,true};

void boardDefaults(char board[8][8]){
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            if((y+x) % 2 == 0){
                board[y][x] = ' ';

            }else{
                board[y][x] = ' ';
                if(y == 0 || y == 1 || y == 2){
                    board[y][x] = 'x';
                }
                if(y == 5 || y == 6 || y == 7){
                    board[y][x] = 'o';
                }
            }
        }
    }
}

void printBoard(char board[8][8]){
    system("cls");
    for(int y=0;y<8;y++){
        printf("%d|",y+1);
        for(int x=0;x<8;x++){
            printf("%c",board[y][x]);
            printf("|");
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

void queenCheck(char board[8][8],int turn,int cord[4]){
    if(turn == 0){
        if(cord[2] == 1){
            board[cord[2]-1][cord[3]-1] = 'O';
        }
    }
    if(turn == 1){
        if(cord[2] == 8){
            board[cord[2]-1][cord[3]-1] = 'X';
        }
    }
}

void movement(char board[8][8],int turn,int pawn[2]){
    int cord[4],count = 0,i = 0;
	char ac[2];
    int check = false,ccheck = 0;
    char temp;

    if(turn == 0){
        printf("O`s turn!\n");
    }else if(turn == 1){
        printf("X`s turn!\n");}

    printf("<y><x> <new y><new x>\n");

    checkpoint:
    if(ccheck == 1){
        printf("Enter your next move again:\n");
    }else{
        printf("Enter your next move:\n");
    }
    //scanf("%d %c %d %c",&cord[0],&ac[0],&cord[2],&ac[1]);
    scanf("%c %d %c %d",&ac[0],&cord[0],&ac[1],&cord[2]);

	switch(ac[0]){
		case 'a':
			cord[1] = 1;
			break;
		case 'b':
			cord[1] = 2;
			break;
		case 'c':
			cord[1] = 3;
			break;
		case 'd':
			cord[1] = 4;
			break;
		case 'e':
			cord[1] = 5;
			break;
		case 'f':
			cord[1] = 6;
			break;
		case 'g':
			cord[1] = 7;
			break;
		case 'h':
			cord[1] = 8;
			break;
	}

	switch(ac[1]){
		case 'a':
			cord[3] = 1;
			break;
		case 'b':
			cord[3] = 2;
			break;
		case 'c':
			cord[3] = 3;
			break;
		case 'd':
			cord[3] = 4;
			break;
		case 'e':
			cord[3] = 5;
			break;
		case 'f':
			cord[3] = 6;
			break;
		case 'g':
			cord[3] = 7;
			break;
		case 'h':
			cord[3] = 8;
			break;
	}

    if(turn == 0){
        if(cord[0] == 5 && ac[0] == 'k' && cord[2] == 1 && ac[1] == 'p'){
            goto end;
        }
        if(board[cord[0]-1][cord[1]-1] == 'O'){
            if(cord[2] == cord[0] + 1 && cord[3] == cord[1] + 1 || cord[3] == cord[1] - 1){
            if(board[cord[2]-1][cord[3]-1] == 'x'){
                check = false;
            }else{
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[2]-1][cord[3]-1] = 'O';
                queenCheck(board,turn,cord);
                check = true;
            }
        }
        else if(cord[2] == cord[0] + 2){
            if(cord[3] == cord[1] + 2 && board[cord[0]+2][cord[1]] == 'x' && board[cord[2]-1][cord[3]-1] == ' '){
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[0]][cord[1]] = ' ';
                board[cord[2]-1][cord[3]-1] = 'O';
                pawn[0]--;
                check = true;
                queenCheck(board,turn,cord);
                printBoard(board);
                printf("O`s turn!\n");
                goto checkpoint;
            }
            else if(cord[3] == cord[1] - 2 && board[cord[0]][cord[1]-2] == 'x' && board[cord[2]-1][cord[3]-1] == ' '){
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[0]][cord[1]-2] = ' ';
                board[cord[2]-1][cord[3]-1] = 'O';
                pawn[0]--;
                check = true;
                queenCheck(board,turn,cord);
                printBoard(board);
                printf("O`s turn!\n");
                goto checkpoint;
            }
         }
        }
        if(cord[2] == cord[0] - 1 && cord[3] == cord[1] + 1 || cord[3] == cord[1] - 1){
            if(board[cord[2]-1][cord[3]-1] == 'x'){
                check = false;
            }else{
            if(board[cord[0]-1][cord[1]-1] == 'O'){
                board[cord[2]-1][cord[3]-1] = 'O';
            }else{
                board[cord[2]-1][cord[3]-1] = 'o';
            }
            board[cord[0]-1][cord[1]-1] = ' ';
            queenCheck(board,turn,cord);
            check = true;
            }
        }
        else if(cord[2] == cord[0] - 2){
            if(cord[3] == cord[1] + 2 && board[cord[0]-2][cord[1]] == 'x' && board[cord[2]-1][cord[3]-1] == ' '){

                if(board[cord[0]-1][cord[1]-1] == 'O'){
                    board[cord[2]-1][cord[3]-1] = 'O';
                }else{
                    board[cord[2]-1][cord[3]-1] = 'o';
                }
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[0]-2][cord[1]] = ' ';
                pawn[0]--;
                check = true;
                queenCheck(board,turn,cord);
                printBoard(board);
                printf("O`s turn!\n");
                goto checkpoint;
            }
            else if(cord[3] == cord[1] - 2 && board[cord[0]-2][cord[1]-2] == 'x' && board[cord[2]-1][cord[3]-1] == ' '){
                if(board[cord[0]-1][cord[1]-1] == 'O'){
                    board[cord[2]-1][cord[3]-1] = 'O';
                }else{
                    board[cord[2]-1][cord[3]-1] = 'o';
                }
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[0]-2][cord[1]-2] = ' ';
                pawn[0]--;
                check = true;
                queenCheck(board,turn,cord);
                printBoard(board);
                printf("O`s turn!\n");
                goto checkpoint;
            }

        }
        if(check == false){
            printf("Invalid move!\n");
            ccheck = 1;
            goto checkpoint;
        }
    }

    if(turn == 1){
        if(cord[0] == 5 && ac[0] == 'k' && cord[2] == 1 && ac[1] == 'p'){
            goto end1;
        }
        if(board[cord[0]-1][cord[1]-1] == 'X'){
            if(cord[2] == cord[0] - 1 && cord[3] == cord[1] + 1 || cord[3] == cord[1] - 1){
            if(board[cord[2]-1][cord[3]-1] == 'o'){
                check = false;
            }else{
            board[cord[0]-1][cord[1]-1] = ' ';
            board[cord[2]-1][cord[3]-1] = 'X';
            queenCheck(board,turn,cord);
            check = true;
            }
        }
        else if(cord[2] == cord[0] - 2){
            if(cord[3] == cord[1] + 2 && board[cord[0]-2][cord[1]] == 'o' && board[cord[2]-1][cord[3]-1] == ' '){
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[0]-2][cord[1]] = ' ';
                board[cord[2]-1][cord[3]-1] = 'X';
                pawn[1]--;
                check = true;
                queenCheck(board,turn,cord);
                printBoard(board);
                printf("X`s turn!\n");
                goto checkpoint;
            }
            else if(cord[3] == cord[1] - 2 && board[cord[0]-2][cord[1]-2] == 'o' && board[cord[2]-1][cord[3]-1] == ' '){
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[0]-2][cord[1]-2] = ' ';
                board[cord[2]-1][cord[3]-1] = 'X';
                pawn[1]--;
                check = true;
                queenCheck(board,turn,cord);
                printBoard(board);
                printf("X`s turn!\n");
                goto checkpoint;
            }
         }
        }
        if(cord[2] == cord[0] + 1 && cord[3] == cord[1] + 1 || cord[3] == cord[1] - 1){
            if(board[cord[2]-1][cord[3]-1] == 'o'){
                check = false;
            }else{
                if(board[cord[0]-1][cord[1]-1] == 'X'){
                    board[cord[2]-1][cord[3]-1] = 'X';
                }else{
                    board[cord[2]-1][cord[3]-1] = 'x';
                }
                board[cord[0]-1][cord[1]-1] = ' ';
                queenCheck(board,turn,cord);
                check = true;
            }
        }
        else if(cord[2] == cord[0] + 2){
            if(cord[3] == cord[1] + 2 && (board[cord[0]+2][cord[1]] == 'o' || board[cord[0]][cord[1]-2] == 'o') && board[cord[2]-1][cord[3]-1] == ' '){
                if(board[cord[0]-1][cord[1]-1] == 'X'){
                    board[cord[2]-1][cord[3]-1] = 'X';
                }else{
                    board[cord[2]-1][cord[3]-1] = 'x';
                }
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[0]][cord[1]] = ' ';
                pawn[1]--;
                check = true;
                queenCheck(board,turn,cord);
                printBoard(board);
                printf("X`s turn!\n");
                goto checkpoint;
            }
            else if(cord[3] == cord[1] - 2 && (board[cord[0]+2][cord[1]] == 'o' || board[cord[0]][cord[1]-2] == 'o') && board[cord[2]-1][cord[3]-1] == ' '){
                if(board[cord[0]-1][cord[1]-1] == 'X'){
                    board[cord[2]-1][cord[3]-1] = 'X';
                }else{
                    board[cord[2]-1][cord[3]-1] = 'x';
                }
                board[cord[0]-1][cord[1]-1] = ' ';
                board[cord[0]][cord[1]-2] = ' ';
                pawn[1]--;
                check = true;
                queenCheck(board,turn,cord);
                printBoard(board);
                printf("X`s turn!\n");
                goto checkpoint;
            }
        }
        if(check == false){
            printf("Invalid move!\n");
            ccheck = 1;
            count ++;
            if(count < 20){
                goto checkpoint;
             }
        }
    }
    end:
    end1:
    i++;
}


int Winner(int *x,int *o){
    if(*x == 0){
        printf("O won!");
        return 0;
    }
    else if(*o == 0){
        printf("X won!");
        return 0;
    }
    else{
        return 1;
    }
}

void switchTurns(int *turn){
    if(*turn == 0){
        *turn = 1;
    }else{
        *turn = 0;
    }
}

void gameRules(){
    char ans;
    printf("Would you like to look at the rules of checkers, mate?(Y/N)\n");
    scanf("%c",&ans);

    if(ans == 'Y' || ans == 'y'){
        FILE *f = fopen("rules.txt","r");
        char buffer[255];

        while(fgets(buffer,255,f)){
            printf("%s",buffer);
        }

        fclose(f);
    }else{
        printf("Bloody hell maTte, I hope you know what you ae doing!  ");
    }
    printf("\n");
    system("pause");
}

void playGame(){
    char board[8][8];
    int pawn[2] = {12,12};
    int turn = 0;
    gameRules();

    boardDefaults(board);
    while(Winner(&pawn[0],&pawn[1])){
        printBoard(board);
        movement(board,turn,pawn);
        switchTurns(&turn);
    }
}

int main()
{
    playGame();
}
