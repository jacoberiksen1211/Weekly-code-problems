#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

// week 2 assignments!
double pi(int n)
{
    int divident = 1;
    double total = 0;
    for(int x = 0; x < n; x++){
        
        total += pow(-1, x) / divident ;
        
        divident += 2;
    }
    return total * 4;
}

// week three assignments!
void funWithBags1(){
    int bagArray[1000000] = {};
    string cmd;
    cin >> cmd;
    int cmdVal;
    while(cmd.compare("quit") != 0){
        cin >> cmdVal;
        if(cmd.compare("add") == 0){
            bagArray[cmdVal] = 1;
        }
        else if (cmd.compare("del") == 0){
            bagArray[cmdVal] =0;
            
        }
        else if (cmd.compare("qry") == 0){
            if(bagArray[cmdVal] > 0){
                cout << "T";
            }
            else{
                cout << "F";
            }
        }
        cin >> cmd;
    }
}
// week three assignments!
void funWithBags2(){
    int bagArray[1000000] = {};
    string cmd;
    cin >> cmd;
    int cmdVal;
    while(cmd.compare("quit") != 0){
        cin >> cmdVal;
        if(cmd.compare("add") == 0){
            bagArray[cmdVal] += 1;
        }
        else if (cmd.compare("del") == 0){
            bagArray[cmdVal] -= 1;
            if(bagArray[cmdVal] < 0){
                bagArray[cmdVal] = 0;
            }
        }
        else if (cmd.compare("qry") == 0){
            if(bagArray[cmdVal] > 0){
                cout << "T";
            }
            else{
                cout << "F";
            }
        }
        cin >> cmd;
    }
}

struct AddressPage
{
    bool taken = false;
    string fName = "";
    string mName = "";
    string lName = "";
    string phone = "";
    string street = "";
    int house = 0;
    int zip = 0;
    string region = "";
};

//Address book
void AddressBook(){
    AddressPage addressBook[50] = {};
    string cmd;
    cin >> cmd;
    int cmdVal;
    while(cmd.compare("quit") != 0){
        cin >> cmdVal;
        cmdVal--;
        // if inside parameters
            if(cmd.compare("add") == 0){
                AddressPage x;
                x.taken = true;
                cin >> x.fName;
                cin >> x.mName;
                cin >> x.lName;
                cin >> x.phone;
                cin >> x.street;
                cin >> x.house;
                cin >> x.zip;
                cin >> x.region;
                if(addressBook[cmdVal].taken == false){
                    if(cmdVal >= 0 && cmdVal < 50){
                        addressBook[cmdVal] = x;
                    }
                }
            }
            else if (cmd.compare("clr") == 0){
                if(cmdVal >= 0 && cmdVal < 50){
                    if(addressBook[cmdVal].taken == true){
                        AddressPage x;
                        addressBook[cmdVal] = x;
                    }   
                }
                
            }
            else if (cmd.compare("qry") == 0){
                if(cmdVal >= 0 && cmdVal < 50){
                    if(addressBook[cmdVal].taken){
                        AddressPage x = addressBook[cmdVal];
                        cout << x.fName << "," << x.mName << "," << x.lName << "," << x.phone << "," << x.street << "," << x.house << "," << x.zip << "," << x.region << endl;
                    }
                }
            }
        

        cin >> cmd;
    }
}

int main(int argc, char const *argv[])
{
    AddressBook();

    return 0;
}
