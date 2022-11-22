#include "doubly-linked.h"



List::List(){
    this->first = nullptr;
}
List::~List(){
    Node *current = this->first;
    Node *next = nullptr;
    while(current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
}
void List::insert(int n){
    Node *node = new Node;
    node->val = n;
    node->next = nullptr;
    if(this->first == nullptr){
        node->prev = nullptr;
        this->first = node;
    }
    else{
        // finde last node
        Node* lastNode = this->first;
        while(lastNode->next != nullptr){
            lastNode = lastNode->next;
        }
        // add new node at end
        lastNode->next = node;
        node->prev = lastNode;
    }
}

void List::reverse(void){
    Node* current = this->first;
    Node* temp = nullptr;
    
    //return if the list is empty!
    if(current == nullptr){
        return;
    }

    while(true){//cancel when reached end
        //flip next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        if(current->prev == nullptr){
            //if reached last node set new head and break
            this->first = current;
            break;
        }
        else{
            //go to "next" node which is now previous.
            current = current->prev;
        }
    }
}

void List::print(void){
    Node* current = this->first;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    
}

// int main(int argc, char const *argv[])
// {
    
//     List l;
//     int n;
    
//     while(cin >> n){
//         l.insert(n);
//     }
    
//     // Print list as read from cin
//     l.print();
//     // Reverse the list and print it
//     l.reverse();
//     l.print();
//     // Reverse again and print it
//     l.reverse();
//     l.print();
    
//     return 0;
// }
