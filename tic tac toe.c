#include <stdio.h>

struct myDataType{
    int i;
    char ch;
}inputvalue();

void main(){
run();
getch();

}

void run(){
    int count;
    struct myDataType info;
    char symbol[9] = {'1','2','3','4','5','6','7','8','9'};
    board (symbol);

    again:
    info = inputvalue(symbol,count);
    symbol[info.i] = info.ch;
    board(symbol);
    count++;
    goto again;
}

int check(char sym[9],char ch,int count){
    int i;
    for(i = 0;i<=6; i+=3)//it's for row
        if(sym[i] == ch && sym[i+1]==ch&&sym[i+2]==ch){
            printf("the Winner is : %c",ch);return 1;
        }
    for(i = 0;i<3; i++)//it's for column
        if(sym[i]==ch && sym[i+3]==ch&&sym[i+6]==ch){
            printf("the Winner is : %c",ch);return 1;
        }
    if(sym[0]==ch && sym[4]==ch&&sym[8]==ch){
            printf("the Winner is : %c",ch);return 1;
        }
    else if(sym[2]==ch && sym[4]==ch && sym[6]==ch){
            printf("the Winner is : %c",ch);return 1;
        }
    else if(count==8){
        printf("the Game is DRAW");
        return 1;
    }else return 0;
}

struct myDataType inputvalue(char sym[9],int count){
    char value;
    int i;
    struct myDataType info;

    inputAgain:
    if (count%2==0){
        printf("\n Please Enter Your Choice - X:");
    } else {
       printf("\n Please Enter Your Choice - 0:");
    }
    scanf("%s", &value);

    for(i=0;i<9;i++){
        if (value == sym[i]){
            info.i=i;
            if(count%2==0){
                info.ch='x';
            }else{
                info.ch='0';
            }
            break;
        }else{
            info.i = -1;
            info.ch= ' ';
        }
    }
    if(info.i == -1){
        printf("\n Input Is Not Valid");
        goto inputAgain;
    }
    return info;
};

void board (char sym[9]) {
    system("cls");
	printf("\n\t\t\t tic tac toe ");
	printf(" \n player 1  symbol: X");
	printf(" \n player 2  symbol: 0");
	printf("\n\t\t\t     |    |    ");
	printf("\n\t\t\t  %c  | %c  | %c  ",sym[0],sym[1],sym[2]);
	printf("\n\t\t\t ----|----|----");
	printf("\n\t\t\t     |    |    ");
	printf("\n\t\t\t  %c  | %c  | %c  ",sym[3],sym[4],sym[5]);
	printf("\n\t\t\t ----|----|----");
	printf("\n\t\t\t     |    |    ");
	printf("\n\t\t\t  %c  | %c  | %c  ",sym[6],sym[7],sym[8]);
	printf("\n\t\t\t     |    |    ");
}
