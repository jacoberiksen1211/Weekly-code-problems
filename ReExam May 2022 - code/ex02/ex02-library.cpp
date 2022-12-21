#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void shift(Passenger *q, unsigned int n) {
    // Write your code here
    // update q.row to q.row + n
    while(q != nullptr){
        q->row = q->row + n;
        q = q->next;
    }
}

// Task 2(b).  Implement this function
Passenger* find(Passenger *q, unsigned int rowMin,
                unsigned int rowMax) {
    // Replace the following with your code
    //return a NEW queue with copies of all element in q that have row > rowMin && row < rowMax
   if(q == nullptr){
    return nullptr;
   }
    
    Passenger *head = nullptr;
    
    do
    {
        if(q->row >= rowMin && q->row <= rowMax){
            //create copy
            Passenger *p = new Passenger();
            p->name = q->name;
            p->next = nullptr;
            p->row = q->row;
            p->seat = q->seat;
            p->ticket = q->ticket;
            
            
            if(head == nullptr){
                //handle first element
                head = p;
            }
            else{
                //find tail
                Passenger *tmp = head;
                while(tmp->next != nullptr){
                    tmp = tmp->next;
                }
                //set new tail
                tmp->next = p;
            }
        }
        //go to next element
        q = q->next;
    } while (q != nullptr);
    
    return head;
}

// Task 2(c).  Implement this function
bool occupied(Passenger *q, unsigned int row, char seat) {
    // Replace the following with your code
    // return true if any passenger in q has row and seat, else false

    while (q != nullptr){
        if(q->row == row && q->seat == seat){
            return true;
        }
        q = q->next;
    }
    
    return false;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    cout << ", seat " << q->row << q->seat << endl;
    displayQueue(q->next);
}

