#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

typedef enum { wood, stone } material;
struct tile {
    int x, y;
    bool isWall;
    material type;
};
#define NROWS 12
#define NCOLS 16

//print1 for maze1
void print1(tile playground[NROWS][NCOLS], int py, int px){
    for(int i = 0; i<NROWS; i++){
        for(int j = 0; j<NCOLS; j++){
            if(playground[i][j].isWall){
                 cout << "*";
            }
            else if(i == py && j == px){
                cout << "O";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

//maze1 static allocation
void maze1(){
        
    //setup playground
    tile playground[NROWS][NCOLS];
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(NROWS-1) || (i==0 && j!=3) || j==(NCOLS-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    //player coordinates
    int px = 5;
    int py = 5;
    
    //play game (take input and print)
    while(true){
        print1(playground, py, px);
        char tmp;
        cin >> tmp;
        if(tmp == 'q'){
            break;
        }
        else if(tmp == 'l'){
            if(!playground[py][px-1].isWall){
                px--;
            }
        }else if(tmp == 'r'){
            if(!playground[py][px+1].isWall){
                px++;
            }
        }else if(tmp == 'u'){
            if(!playground[py-1][px].isWall){
                py--;
            }
        }else if(tmp == 'd'){
            if(!playground[py+1][px].isWall){
                py++;
            }
        }
        
    }


}

void print2(tile** playground, int rowCount, int colCount, int py, int px){
    for(int i = 0; i<rowCount; i++){
        for(int j = 0; j<colCount; j++){
            if(playground[i][j].isWall){
                cout << "*";
            }
            else if(i == py && j == px){
                cout << "O";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}
//maze2 dynamic 2d array allocation
void maze2(){
    int rowCount;
    int colCount;

    cin >> rowCount;
    cin >> colCount;

    //setup playground
    tile** playground = new tile*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        playground[i] = new tile[colCount];

        for (int j = 0; j < colCount; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(rowCount-1) || (i==0 && j!=3) || j==(colCount-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    //player coordinates
    int px = colCount / 2;
    int py = rowCount / 2;
    
    //play game (take input and print)
    while(true){
        print2(playground, rowCount, colCount, py, px);
        char tmp;
        cin >> tmp;
        if(tmp == 'q'){
            break;
        }
        else if(tmp == 'l'){
            if(!playground[py][px-1].isWall){
                px--;
            }
        }else if(tmp == 'r'){
            if(!playground[py][px+1].isWall){
                px++;
            }
        }else if(tmp == 'u'){
            if(!playground[py-1][px].isWall){
                py--;
            }
        }else if(tmp == 'd'){
            if(!playground[py+1][px].isWall){
                py++;
            }
        }
        
    }


}

int main() {

    //maze1();
    maze2();
    
    return 0;
}