#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::renameRoom(string oldName, string newName) {
    // Write your code here
    for(int i = 0; i < roomNames.size(); i++){
        if(this->roomNames[i].compare(newName) == 0){
            return;
        }
    }

    for(int i = 0; i < roomNames.size(); i++){
        if(this->roomNames[i].compare(oldName) == 0){
            this->roomNames[i] = newName;
        }
    }
    auto nh = this->roomOccupancy.extract(oldName);
    if(!nh.empty()){
        nh.key() = newName;
        this->roomOccupancy.insert(std::move(nh));
    }
    
}

// Task 3(b).  Implement this method
void Hotel::removeGuest(string roomName, string guestName, string guestId) {
    // Write your code here
    if(this->roomOccupancy.find(roomName) == this->roomOccupancy.end()){
        return;
    }
    if(this->roomOccupancy[roomName].id.compare(guestId) == 0 && 
        this->roomOccupancy[roomName].name.compare(guestName) == 0){
        this->roomOccupancy.erase(roomName);
    }
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuestId(vector<string> guestIds) {
    // Write your code here
    for(int i =0; i<roomNames.size(); i++){
        if(this->roomOccupancy.find(roomNames[i]) != this->roomOccupancy.end()){
            for(int j=0; j < guestIds.size(); j++){
                if(this->roomOccupancy[roomNames[i]].id.compare(guestIds[j]) == 0){
                    cout << this->roomNames[i] << endl;
                }
            }
        }
    }
}


// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}


