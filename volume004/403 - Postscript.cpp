#include <stdio.h>
#include <string.h>
char C5[][5][7] = {
    {".***..", "*...*.", "*****.", "*...*.", "*...*."},//A
    {"****..", "*...*.", "****..", "*...*.", "****.."},//B
    {".****.", "*...*.", "*.....", "*.....", ".****."},//C
    {"****..", "*...*.", "*...*.", "*...*.", "****.."},//D
    {"*****.", "*.....", "***...", "*.....", "*****."},//E
    {"*****.", "*.....", "***...", "*.....", "*....."},//F
    {".****.", "*.....", "*..**.", "*...*.", ".***.."},//G
    {"*...*.", "*...*.", "*****.", "*...*.", "*...*."},//H
    {"*****.", "..*...", "..*...", "..*...", "*****."},//I
    {"..***.", "...*..", "...*..", "*..*..", ".**..."},//J
    {"*...*.", "*..*..", "***...", "*..*..", "*...*."},//K
    {"*.....", "*.....", "*.....", "*.....", "*****."},//L
    {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."},//M
    {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."},//N
    {".***..", "*...*.", "*...*.", "*...*.", ".***.."},//O
    {"****..", "*...*.", "****..", "*.....", "*....."},//P
    {".***..", "*...*.", "*...*.", "*..**.", ".****."},//Q
    {"****..", "*...*.", "****..", "*..*..", "*...*."},//R
    {".****.", "*.....", ".***..", "....*.", "****.."},//S
    {"*****.", "*.*.*.", "..*...", "..*...", ".***.."},//T
    {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."},//U
    {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."},//V
    {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."},//W
    {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."},//X
    {"*...*.", ".*.*..", "..*...", "..*...", "..*..."},//Y
    {"*****.", "...*..", "..*...", ".*....", "*****."},//Z
    {"......", "......", "......", "......", "......"},//BLANK
};
int main() {
    char text[60][60];
    memset(text, '.', sizeof(text));
    char cmd[5], font[5], msg[100];
    int row, col, i, j, k;
    scanf("%s", cmd);
    do {
        if(!strcmp(cmd, ".EOP")) {
            for(i = 0; i < 60; i++) {
                for(j = 0; j < 60; j++) {
                    putchar(text[i][j]);
                }
                puts("");
            }
            puts("");
            puts("------------------------------------------------------------");
            puts("");
            memset(text, '.', sizeof(text));
            continue;
        }
        scanf("%s %d ", font, &row);
        row--;
        int ch = font[1]-'0';
        col = 0;
        if(!strcmp(cmd, ".C")) {
            gets(msg);
            int i = 1;
            while(msg[i] != '|') i++;
            msg[i+1] = '\0';
            if(ch == 1) {
                int len = strlen(msg)-2;
                col = 30 - len/2;
            } else {
                int len = (strlen(msg)-2)*6;
                col = 30 - len/2;
            }
        } else if(!strcmp(cmd, ".P")) {
            scanf("%d ", &col);
            col--;
            gets(msg);
        } else if(!strcmp(cmd, ".L")) {
            gets(msg);
        } else { // .R
            gets(msg);
            int i = 1;
            while(msg[i] != '|') i++;
            msg[i+1] = '\0';
            if(ch == 1) {
                int len = strlen(msg)-2;
                col = 60 - len;
            } else {
                int len = (strlen(msg)-2)*6;
                col = 60 - len;
            }
        }
        if(ch == 1) {
            for(i = 1; msg[i] != '|'; i++) {
                if(col+i-1 >= 0 && col+i-1 < 60 && msg[i] != ' ')
                    text[row][col+i-1] = msg[i];
            }
        } else {
            for(i = 1; msg[i] != '|'; i++) {
                if(msg[i] == ' ')   continue;
                for(j = 0; j < 5; j++) {
                    for(k = 0; k < 6; k++) {
                        if(col+k-6+6*i >= 0 && col+k-6+6*i < 60 && row+j >= 0 && row+j < 60)
                            text[row+j][col+k-6+6*i] = C5[msg[i]-'A'][j][k];
                    }
                }
            }
        }
    } while(scanf("%s", cmd) == 1);
    return 0;
}
