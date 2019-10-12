#include <iostream>

using namespace std;

int num;

bool ifillegal(bool **matrix,int n,int x,int y)
{
    for(int i = 0;i < n;++i){
        if(matrix[x][i] || matrix[i][y]) return false;
    }
    
    int i = x,j = y;
    while(i > -1 && i < 8 && j > -1 && j < 8){
        if(matrix[i--][j--]) return false;
    }
    i = x,j = y;
    while(i > -1 && i < 8 && j > -1 && j < 8){
        if(matrix[i--][j++]) return false;
    }
    i = x,j = y;
    while(i > -1 && i < 8 && j > -1 && j < 8){
        if(matrix[i++][j--]) return false;
    }
    i = x,j = y;
    while(i > -1 && i < 8 && j > -1 && j < 8){
        if(matrix[i++][j++]) return false;
    }

    return true;
}

void display(bool **matrix,int n)
{
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            if(matrix[i][j]) cout << "*" << " ";
            else cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void eightQueen(bool ** matrix,int n,int k)
{
    if(k == n ) {
        num++;
        if(num == 2){
            display(matrix,n);
            cout << '\n';
            }
    }
    else{
        for(int i = 0;i < n;++i){
            if(ifillegal(matrix,n,k,i)){
                matrix[k][i] = 1;
                eightQueen(matrix,n,k+1);
                matrix[k][i] = 0;
            }
        }
    }
}

int main()
{
    bool **existion = new bool*[8];
    for(int i = 0;i < 8;++i){
        existion[i] = new bool[8];
    }

    eightQueen(existion,8,0);

    for(int i = 0;i < 8;++i){
        delete []existion[i];
    }
    delete []existion;


    return 0;
}