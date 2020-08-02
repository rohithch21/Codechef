#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, char board[9][9]){
    if(x < 1 && y > 8) return false;
    else if (x > 8 && y < 1) return false;
    else if (board[x][y] == 'X') return false;
    else return true;
}


int main(){
    char board[9][9];
    int t,k;
    cin >> t;
    while (t--)
    {
        cin >> k;
        int i=1,j=1;
        for(int i=0;i<=8;i++){
            for(int j=0;j<=8;j++){
                board[i][j] = '*';
            }
        }
        board[1][1] = 'O';
        while(k--){
            for(i=1;i<=8;i++){
                for(j=1;j<=8;j++){
                    if(k == 0) break;
                    if(i==1 && j== 1) j++;

                    board[i][j] = '.';
                    k--;
                    
                }
                if(k == 0) break;
                 
            }
            
        }
        for(i=1;i<=7;i++){
            for(j=1;j<=7;j++){
                if(board[i][j] == '.' || board[i][j] == 'O') {
                    if(board[i+1][j] == '*') board[i+1][j] = 'X';
                    if(board[i+1][j+1] == '*') board[i+1][j+1] = 'X';
                    if(board[i][j+1] == '*') board[i][j+1] = 'X';
                }
            }
        }
        for(i=1;i<=8;i++){
            for(j=1;j<=8;j++){
                if(board[i][j] == '*'){
                    board[i][j] = '.';
                }
            }
        }

        for(int i=1;i<9;i++){
            for(int j=1;j<9;j++){
                cout << board[i][j];
            }
            cout << endl;
        }
    }
}
    