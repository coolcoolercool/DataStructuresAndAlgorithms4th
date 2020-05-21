/** 
 * author: zzw5005
 * date: 2020/1/6 14:50
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

class Node_post{

public:
    Node_post() : left(0), right(0){
    }
    Node_post(int val) : val(val), left(0), right(0){};
    Node_post(const int val_1, Node_post* left, Node_post* right)
            : val(val_1), left(left), right(right){};

    int val;
    Node_post *left, *right;
};


void postOrder(Node_post *curNode){
    if(curNode != 0){
        postOrder(curNode->left);
        postOrder(curNode->right);
        std::cout << curNode->val << " ";
    }
}


void iterativePostOrder(Node_post* root) {
    Node_post * curNode = root;

    Stack<Node_post *> stack_1;
    Stack<int> stack_2;

    while(!stack_1.empty() || NULL != curNode){
        while(NULL != curNode) {
            stack_1.push(curNode);
            stack_2.push(0);
            curNode = curNode->left;
        }

        while(!stack_1.empty() && stack_2.top() == 1){
            std::cout << stack_1.pop()->val << " ";
            stack_2.pop();
        }

        if(!stack_1.empty()){
            stack_2.pop();
            stack_2.push(1);
            curNode = stack_1.top();
            curNode = curNode->right;
        }
    }
}


int main9bw1(){
    Node_post* node1 = new Node_post(8);
    Node_post* node2 = new Node_post(6);
    Node_post* node3 = new Node_post(10);

    Node_post* node4 = new Node_post(5);
    Node_post* node5 = new Node_post(7);

    Node_post* node6 = new Node_post(9);
    Node_post* node7 = new Node_post(11);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    std::cout << "postOrder: " << std::endl;
    postOrder(node1);

    std::cout << std::endl;
    iterativePostOrder(node1);
}