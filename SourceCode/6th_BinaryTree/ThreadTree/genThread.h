/** 
 * author: zzw5005
 * date: 2020/1/6 16:51
*/

/**
 * 线索树，带有前继节点指针和后继节点指针的二叉树
 */

#ifndef DATASTRUCTURESANDALGORITHMS4TH_GENTHREAD_H
#define DATASTRUCTURESANDALGORITHMS4TH_GENTHREAD_H

#include <iostream>


template<class T>
class ThreadedNode{
public:
    ThreadedNode() : left(0), right(0){
    }

    ThreadedNode(const T& el, ThreadedNode* left = 0, ThreadedNode *right = 0)
       : key(el), left(left), right(right), successor(0){};

    T key;
    ThreadedNode *left, *right;
    unsigned int successor : 1;  //- 后继
};

template<class T>
class ThreadedTree{
public:
    ThreadedTree() : root(0){};

    void clear(){
        clear(root);
        root = 0;
    }

    ~ThreadedTree(){
        clear();
    }

    void virtual visit(ThreadedNode<T>* p){
        std::cout << p->key << " ";
    }

    void preOrder();
    void inOrder();
    void postOrder();
    void insert(const T&);

protected:
    ThreadedNode<T>* root;
    void clear(ThreadedNode<T>*);
};

template<class T>
void ThreadedTree<T>::clear(ThreadedNode<T>* curNode){
    if(curNode != 0){
        clear(curNode->left);
        if(curNode->successort == 0){
            clear(curNode->right);
        }

        delete curNode;
    }
}

template<class T>
void ThreadedTree<T>::insert(const T& el){
    ThreadedNode<T> *curNode, *prev = 0, *newNode;
    newNode = new ThreadedNode<T>(el);
    if(root == 0){
        root = newNode;
        return;
    }

    curNode = root;
    while(curNode != 0){
        prev = curNode;
        if(curNode->key > el){
            curNode = curNode->left;
        }else if(curNode->successor == 0){
            curNode = curNode->right;
        }else{
            break;
        }
    }

    if(prev->key > el){
        prev->left = newNode;
        newNode->successor = 1;
        newNode->right = prev;
    }else if(prev->successor == 1){
        newNode->successor = 1;
        prev->successor = 0;
        newNode->right = prev->right;
        prev->right = newNode;
    }else{
        prev->right = newNode;
    }
}

template<class T>
void ThreadedTree<T>::inOrder(){
    ThreadedNode<T>  *prev, *curNode = root;

    if(curNode != 0){
        while(curNode->left != 0){
            curNode = curNode->left;
        }

        while(curNode != 0){
            visit(curNode);
            prev = curNode;
            curNode = curNode->right;
            if(curNode != 0 && prev->successor == 0){
                while(curNode->left != 0){
                    curNode = curNode->left;
                }
            }
        }
    }
}


template<class T>
void ThreadedTree<T>::preOrder(){
    ThreadedNode<T> *curNode = root;

    while(curNode != 0){
        visit(curNode);
        if(curNode->left != 0){
            curNode = curNode->left;
        }else if(curNode->right != 0 && curNode->successor == 0){
            curNode = curNode->right;
        }else{
            while(curNode->successor == 1){
                curNode = curNode->right;
            }

            curNode = curNode->right;
        }
    }
}

template<class T>
void ThreadedTree<T>::postOrder(){
    ThreadedNode<T> *q, *r, *s, *curNode = new ThreadedNode<T>, *rightmost, *dummy = curNode;
    curNode->left = root;
    for(rightmost = root; rightmost->right != 0; rightmost = rightmost->right);

    rightmost->successor = 1;
    rightmost->right = curNode;

    enum direction {goLeft, goRight, visiting} dir = goLeft;

    while(curNode != 0){
        if(dir == goLeft){
            if(curNode->left != 0){
                curNode = curNode->left;
            }else{
                dir = goRight;
            }
        }else if(dir == goRight){
            if(curNode->right != 0 && curNode->successor == 0){
                curNode = curNode->right;
                dir = goRight;
            }else{
                dir = visiting;
            }
        }else{
            if(curNode == dummy){
                rightmost->right = 0;
                rightmost->successor = 0;
                delete dummy;
                return;
            }

            visit(curNode);
            if(curNode->right != 0 && curNode->right->left == curNode){
                curNode = curNode->right;
                dir = goRight;
            }else{
                for(q = curNode->right->left, r = q->right, s = r->right;
                    r != curNode; q = r, r = s, s = s->right){
                    r->right = q;
                }

                for(s = q->right; q != curNode->right->left;
                    q->right = r, r = q, q = s, s = s->right){
                    visit(q);
                }

                visit(q);
                curNode = curNode->right;
                dir = goRight;
            }
        }
    }
}




#endif //DATASTRUCTURESANDALGORITHMS4TH_GENTHREAD_H
