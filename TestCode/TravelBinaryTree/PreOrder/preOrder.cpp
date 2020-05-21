/** 
 * author: zzw5005
 * date: 2020/1/6 11:59
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

class Node_pre{

public:
    Node_pre() : left(0), right(0){
    }
    Node_pre(int val) : val(val), left(0), right(0){};
    Node_pre(const int val_1, Node_pre* left, Node_pre* right)
        : val(val_1), left(left), right(right){};

    int val;
    Node_pre *left, *right;
};

void visit(Node_pre* root){
    std::cout << root->val << " ";
}

/**
 * 递归前序遍历
 * @param curNode
 */
void preOrder(Node_pre *curNode){
    if(curNode != 0){
        visit(curNode);
        preOrder(curNode->left);
        preOrder(curNode->right);
    }
}

void iterativePreOrder(Node_pre* root){
    Stack<Node_pre *> travelStack;
    Node_pre *curNode = root;

    //- 注意这里判断curNode是否为空，可以直接使用!curNode 或者 NULL != curNode
    while(!travelStack.empty() || NULL != curNode){
        while(NULL != curNode){
            travelStack.push(curNode);
            visit(curNode);

            curNode = curNode->left;
        }

        if(!travelStack.empty()){
            curNode = travelStack.pop();
            curNode = curNode->right;
        }
    }
}

int main7hv3(){
    Node_pre* node1 = new Node_pre(8);
    Node_pre* node2 = new Node_pre(6);
    Node_pre* node3 = new Node_pre(10);

    Node_pre* node4 = new Node_pre(5);
    Node_pre* node5 = new Node_pre(7);

    Node_pre* node6 = new Node_pre(9);
    Node_pre* node7 = new Node_pre(11);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    preOrder(node1);
    std::cout << std::endl;

    iterativePreOrder(node1);

}