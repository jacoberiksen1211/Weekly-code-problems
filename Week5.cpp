#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//Vector passed by reference! changed made will be seen in caller !
// take inputs of "x n" (x being identifier = "a" or "b", n being a number)
void takeInput(vector<int>& dataA, vector<int>& dataB){
    char tmpId;
    int tmpValue;
    while(true){
        //while there is more input
        cin >> tmpId;
        if(cin.fail()) break;
        cin >> tmpValue;
        if(cin.fail()) break;
        if(tmpId == 'a'){
            dataA.push_back({tmpValue});
        }
        else if(tmpId == 'b'){
            dataB.push_back({tmpValue});
        }
    }
}

//dataset 1 (sorting)
void data1(){
    vector<int> dataA;
    vector<int> dataB;
    takeInput(dataA, dataB);
    
    //sort list
    sort(dataA.begin(), dataA.end());
    sort(dataB.begin(), dataB.end());

    for(int i = 0; i < dataA.size(); i++){
        cout << dataA[i] << ' ';
    }
    for(int i = 0; i < dataB.size(); i++){
        cout << dataB[i] << ' ';
    }
}

//datasets 2 (one from each set at a time)
void data2(){
    vector<int> dataA;
    vector<int> dataB;
    takeInput(dataA, dataB);
    int maxSize = max({dataA.size(), dataB.size()});
    for(int i =0; i < maxSize; i++){
        if(i < dataA.size()){
            cout << dataA[i] << ' ';
        }
        if(i < dataB.size()){
            cout << dataB[i] << ' ';
        }
    }
}

//datasets 3 (scalar product ({3, 2} x {4, 6, 5} = 3*4 + 2*6 + 0*5))
void data3(){
    vector<int> dataA;
    vector<int> dataB;
    takeInput(dataA, dataB);
    int minSize = min({dataA.size(), dataB.size()}); // ignoring tail of longer vector as it is multiplied by 0 anyways
    int result = 0;
    for(int i =0; i < minSize; i++){
        result += dataA[i] * dataB[i];
    }
    cout << result;
}

int main(int argc, char const *argv[])
{
    //data1();
    //data2();
    data3();
    return 0;
}
