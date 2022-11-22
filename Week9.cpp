#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void reverse(){
    int value;
    cin >> value;
    if(cin.fail() == true){
        return;
    }
    else{
        reverse();
        cout << value << " ";
    }
}

unsigned int fibonacci(unsigned int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

bool palindrome(vector<int> input, int a, int b){
    if(a == b){
        return true;
    }
    else if(a == b-1 ){
        if(input[a] == input[b]){
            return true;
        }
        else{
            return false;
        }
    }
    return input[a] == input[b] && palindrome(input, a+1, b-1);
}

int levenshteinCharCheck(char a, char b){
    if(a == b){
        return 0;
    }
    return 1;
}

int levenshteinDistance(string a, string b){
    if(a.length() == 0){
        return b.length();
    }
    if(b.length() == 0){
        return a.length();
    }

    return min( levenshteinDistance(a.substr(1), b) + 1 ,
             min(levenshteinDistance(a, b.substr(1)) + 1 ,
                levenshteinDistance(a.substr(1), b.substr(1)) + levenshteinCharCheck(a[0], b[0])));
}

int main(int argc, char const *argv[])
{
    
    //reverse();

    //fibonacci
    // int temp;
    // vector<int> inputs;
    // while(true){
    //     cin >> temp;
    //     if(cin.fail() == true){
    //         break;
    //     } 
    //     cout << fibonacci(temp) << " ";
    // }
    
    // palindrome
    // int temp;
    // vector<int> inputs;
    // while(true){
    //     cin >> temp;
    //     if(cin.fail() == true){
    //         break;
    //     } 
    //     inputs.push_back(temp);
    // }
    // if(palindrome(inputs, 0, inputs.size()-1)){
    //     cout << "yes";
    // }
    // else{
    //     cout << "no";
    // }

    //Levenshtein distance between words
    string a;
    string b;
    cin >> a;
    cin >> b;
    cout << levenshteinDistance(a,b);

    return 0;
}
