/** 
 * author: zzw5005
 * date: 2020/1/6 14:32
*/



#include <iostream>
#include <stack>

template<class T>
class Stack : public std::stack<T>{
public:
    T pop(){
        T tmp = Stack::top();
        std::stack<T>::pop();
        return tmp;
    }
};

class Node_in{

public:
    Node_in() : left(0), right(0){
    }
    Node_in(int val) : val(val), left(0), right(0){};
    Node_in(const int val_1, Node_in* left, Node_in* right)
            : val(val_1), left(left), right(right){};

    int val;
    Node_in *left, *right;
};

void visit(Node_in* root){
    std::cout << root->val << " ";
}

void inOrder(Node_in *curNode){
    if(curNode != 0){
        inOrder(curNode->left);

        std::cout << curNode->val << " ";

        inOrder(curNode->right);
    }
}

void iterativeInOrder(Node_in* root){
    Stack<Node_in*> travelStack;
    Node_in *curNode = root;

    while(!travelStack.empty() || NULL != curNode){
        while(NULL != curNode){
            travelStack.push(curNode);
            curNode = curNode->left;
        }

        if(!travelStack.empty()){
            curNode = travelStack.pop();

            std::cout << curNode->val << " ";

            curNode = curNode->right;
        }
    }
}


int main8gf1() {
    Node_in *node1 = new Node_in(8);
    Node_in *node2 = new Node_in(6);
    Node_in *node3 = new Node_in(10);

    Node_in *node4 = new Node_in(5);
    Node_in *node5 = new Node_in(7);

    Node_in *node6 = new Node_in(9);
    Node_in *node7 = new Node_in(11);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    std::cout << "inOrder: " << std::endl;
    inOrder(node1);

    std::cout << std::endl;

    iterativeInOrder(node1);

    return 0;
}