#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* leftChild = nullptr;
    TreeNode* rightChild = nullptr;
    void initializeValues(int input){
        switch (input)
        {
        case 0:
        case 1:
            value = 1;
            break;
        
        default:
            leftChild = new TreeNode();
            leftChild->initializeValues(input - 1);
            rightChild = new TreeNode();
            rightChild->initializeValues(input - 2);
            value = leftChild->value + rightChild->value;
        };
    };

    void printInPreOrder(void){
        cout << value << " ";
        if(leftChild != nullptr){
            leftChild->printInPreOrder();
            rightChild->printInPreOrder();
        }
    };

    int leafCount(void){
        if(leftChild == nullptr){
            return 1;
        }
        return leftChild->leafCount() + rightChild->leafCount();
    };

    int nodeCount(void){
        if(leftChild == nullptr){
            return 1;
        }
        return leftChild->nodeCount() + rightChild->nodeCount() + 1;
    };
    int depth(void){
        if(leftChild == nullptr){
            return 1;
        }
        return max(leftChild->depth(), rightChild->depth()) + 1;
    };
};

int main(int argc, char const *argv[])
{
    int input;
    cin >> input;

    TreeNode* rootNode = new TreeNode();
    
    rootNode->initializeValues(input);

    cout << "Call tree in pre-order: ";
    rootNode->printInPreOrder();
    cout << endl;

    cout << "Call tree size: " << rootNode->nodeCount() << endl;

    cout << "Call tree depth: " << rootNode->depth() << endl;

    cout << "Call tree leafs: " << rootNode->leafCount() << endl;
    return 0;
}
