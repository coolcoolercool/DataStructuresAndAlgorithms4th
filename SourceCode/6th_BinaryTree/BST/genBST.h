/** 
 * author: zzw5005
 * date: 2020/1/5 16:05
*/

#ifndef DATASTRUCTURESANDALGORITHMS4TH_GENBST_H
#define DATASTRUCTURESANDALGORITHMS4TH_GENBST_H

#include <queue>
#include <stack>
#include <iostream>

template<class T>
class Stack : public std::stack<T>{
public:
    T pop(){
        T tmp = Stack::top();
        std::stack<T>::pop();
        return tmp;
    }
};

template<class T>
class Queue : public std::queue<T>{
public:
    T dequeue(){
        T tmp = Queue::front();
        std::queue<T>::pop();
        return tmp;
    }

    void enqueue(const T& el){
        Queue::push(el);
    }
};


template<class T>  class BST;

template<class T>
class BSTNode{
    BSTNode(){
        left = right = 0;
    }

    BSTNode(const T& el, BSTNode<T> *left = 0, BSTNode<T> *right = 0)
        : val(el), left(left), right(right){
    }

    T val;
    BSTNode<T> *left, *right;
};


template<class T>
class BST{
public:
    BST(){
        root = 0;
    }

    ~BST(){
        clear();
    }

    void clear(){
        clear(root);
        root = 0;
    }

    bool isEmpty() const{
        return root == 0;
    }

    void preorder(){
        preOrder(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    void insert(const T&);

    void recursiveInsert(const T& el){
        recursiveInsert(root, el);
    }

    T* search(const T& el) const{
        return search(root, el);
    }

    T* recursiveSearch(const T& el) const{
        return recursiveSearch(root, el);
    }

    void deleteByCopying(BSTNode<T>*&);
    void findAndDeleteByCopying(const T&);
    void deleteByMerging(BSTNode<T>*&);
    void findAndDeleteByMerging(const T&);

    void iterativePreOrder();
    void iterativeInOrder();
    void iterativePostOrder();

    void levelOrder();   //- 从上到下，从左到右的广度优先遍历（层次遍历）
    void MorrisPreOrder();
    void MorrisInOrder();
    void MorrisPostOrder();

    void balance(T*, int , int);

protected:
    BSTNode<T> *root;
    void clear(BSTNode<T> *);
    void recursiveInsert(BSTNode<T> *&, const T&);

    T* search(BSTNode<T>*, const T&) const;     //- 二叉查找树的查找函数
    T* recursiveSearch(BSTNode<T>*, const T&) const;

    void preOrder(BSTNode<T> *);
    void inOrder(BSTNode<T> *);
    void postOrder(BSTNode<T> *);

    virtual void visit(BSTNode<T>* p){
        std::cout << p->val << ' ';
    }
};


template<class T>
void BST<T>::clear(BSTNode<T> *p){
    if(p != 0){
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

/**
 * 二叉查找树插入节点，并且不破坏二查找树的平衡性
 * @tparam T
 * @param el
 */
template<class T>
void BST<T>::insert(const T& el){
    BSTNode<T> *curNode = root, *prev = 0;
    while(curNode != 0){
        prev = curNode;
        //- 在扫描树的过程中，比较键值el和当前检查的节点的键值。
        // 如果el小于该键值，则扫描当前节点的左子节点，如果el大于该键值，则扫描当前节点的右子节点
        //- 知道要测试的当前节点的子节点为空，则停止扫描，该子节点就是新节点的位置
        if(el < curNode->val){
            curNode = curNode->left;
        }else{
            curNode = curNode ->right;
        }
    }

    if(root = 0){
        root = new BSTNode<T>(el);
    }else if(el < prev->val){
        prev->left = new BSTNode<T>(el);
    }else{
        prev->right = new BSTNode<T>(el);
    }
}

template<class T>
void BST<T>::recursiveInsert(BSTNode<T>*& p, const T& el){
    if(p == 0){
        p = new BSTNode<T>(el);
    }else if(el < p->val){
        recursiveInsert(p->left, el);
    }else{
        recursiveInsert(p->right, el);
    }
}

/**
 * 二叉查找树的查找节点函数
 * @tparam T
 * @param targetNode
 * @param el
 * @return
 */
template<class T>
T* BST<T>::search(BSTNode<T>* targetNode, const T& el) const{
    while(targetNode != 0){
        if(el == targetNode->val){       //- 如果目标值等于当前节点的值
            return &targetNode->val;
        }else if(el < targetNode->val){  //- 如果目标值小于当前节点的值，则转向左子树
            targetNode = targetNode->left;
        }else{                 //- 如果目标值大于当前节点的值，则转向右子树
            targetNode = targetNode->right;
        }
    }

    return 0;
}

template<class T>
T* BST<T>::recursiveSearch(BSTNode<T>* p, const T& el) const{
    if(p != 0){
        if(el == p->val){
            return &p->val;
        }else if(el < p->val){
            return recursiveSearch(p->left, el);
        }else{
            return recursiveSearch(p->right, el);
        }
    }else{
        return 0;
    }
}

template<class T>
void BST<T>::inOrder(BSTNode<T> *curNode){
    if(curNode != 0){
        inOrder(curNode->left);
        visit(curNode);
        inOrder(curNode->right);
    }
}

template<class T>
void BST<T>::preOrder(BSTNode<T> *curNode){
    if(curNode != 0){
        visit(curNode);
        preOrder(curNode->left);
        preOrder(curNode->right);
    }
}


template<class T>
void BST<T>::postOrder(BSTNode<T> *curNode){
    if(curNode != 0){
        postOrder(curNode->left);
        postOrder(curNode->right);
        visit(curNode);
    }
}

template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node){
    BSTNode<T> *previous, *tmp = node;
    if(node->right == 0){
        node = node->left;
    }else if(node->left == 0){
        node = node->left;
    }else{
        tmp = node->left;
        previous = node;
        while(tmp->right != 0){
            previous = tmp;
            tmp = tmp->right;
        }
        node->val = tmp->val;
        if(previous == node){
            previous->left = tmp->left;
        }else{
            previous->right = tmp->left;
        }
    }
    delete tmp;
}

template<class T>
void BST<T>::findAndDeleteByCopying(const T& el){
    BSTNode<T> *p = root, *prev = 0;
    while(p != 0 && !(p->val == el)){
        prev = p;
        if(el < p->val){
            p = p->left;
        }else{
            p = p->right;
        }
    }

    if(p != 0 && p->val == el){
        if(p == root){
            deleteByCopying(root);
        }else if(prev->left == p){
            deleteByCopying(prev->right);
        }else{
            deleteByCopying(prev->right);
        }
    }else if(root != 0){
        std::cout << "val: " << el << " is not in the tree\n";
    }else{
        std::cout << "the tree is empty\n";
    }
}

/**
 * 合并删除，删除二查找树中节点，该结点具有两个子节点
 * 注意这里是给定目标节点的引用，然后删除该节点，并保持二叉查找树的平衡性
 * 方法1：找到当前节点的左子树最右侧的节点，即左子树值最大的节点，让它成为右子树的父节点
 * 方法2：找到当前节点的右子树最左侧的节点，即右子树值最小的节点，让它成为左子数的父节点
 * @tparam T
 * @param targetNode
 */
template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& targetNode){
    BSTNode<T> *tmp = targetNode;  //- tmp保存要删除的节点
    if(targetNode != 0){ //- 如果目标节点非空，找当前节点左子树的值最大的节点
        if(!targetNode->right){ //- 目标节点的右子树不为空
            targetNode = targetNode->left;  //-
        }else if(targetNode->left == 0){  //- 如果目标节点的左子树为空
            targetNode = targetNode->right;
        }
    }else{ //- 如果当前节点为空，则表示已经找到左子树最大的节点，此时可以合并子树了
        tmp = targetNode->left; //- 左移
        while(tmp->right != 0){ //- 找到tmp节右子树的最右边的节点
            tmp = tmp->right;
        }

        tmp->right = targetNode->right; //- 将左子树最右边的节点和右子树连接起来

        tmp = targetNode;
        targetNode = targetNode->left;
    }

    delete tmp;
}

/**
 * 根据给的节点的键值，删除二叉查找树的节点，并保持二叉查找树的平衡
 * @tparam T
 * @param el
 */
template<class T>
void BST<T>::findAndDeleteByMerging(const T& el){
    BSTNode<T> *targetNode = root, *prev = 0; //- 当前节点和前驱节点

    //- 因为二叉查找树是有序的，所以使用二分查找
    while(targetNode != 0){
        if(targetNode->val == el){
            break;
        }

        prev = targetNode;
        if(el < targetNode->val){
            targetNode = targetNode->left;
        }else{
            targetNode = targetNode->right;
        }
    }

    //- 等查找过程结束，如果目标节点targetNode为空，则表示树中不存在该目标节点
    //- 如果目标节点targetNode不为空，且节点的值等于目标值，则进行删除的过程
    if(targetNode != 0 && targetNode->val == el){
        if(targetNode == root){
            deleteByMerging(root);
        }else if(prev->left == targetNode){
            deleteByMerging(prev->left);  //- prev->left可能为空
        }else{
            deleteByMerging(prev->right); //- prev->right可能为空
        }
    }else if(root != 0){
        std::cout << "val " << el << " is not in the tree\n";
    }else{
        std::cout << "the tree is empty\n";
    }
}

/**
 * 非递归二叉树前序遍历
 * 先访问节点，再遍历节点的左子树，遍历节点的右子树
 * @tparam T
 */
template<class T>
void BST<T>::iterativePreOrder(){
    Stack<BSTNode<T>*> travelStack;
    BSTNode<T> *curNode = root;

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


/**
 * 非递归中序遍历
 * @tparam T
 */
template<class T>
void BST<T>::iterativeInOrder(){
    Stack<BSTNode<T>*> travelStack;
    BSTNode<T> *curNode = root;

    while(!travelStack.empty() || NULL != curNode){
        while(NULL != curNode){
            travelStack.push(curNode);
            curNode = curNode->left;
        }

        if(!travelStack.empty()){
            curNode = travelStack.pop();

            visit(curNode);

            curNode = curNode->right;
        }
    }
}

template<class T>
void BST<T>::iterativePostOrder() {
    BSTNode<T> * curNode = root;

    Stack<BSTNode<T> *> stack_1;
    Stack<int> stack_2;

    while(!stack_1.empty() || NULL != curNode){
        while(NULL != curNode) {
            stack_1.push(curNode);
            stack_2.push(0);
            curNode = curNode->left;
        }

        while(!stack_1.empty() && stack_2.top() == 1){
            visit(stack_1.pop());
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


/**
 * 从上到下，从左到右的广度优先遍历（层次遍历）
 * 每次访问了一个节点后，如果它的子节点不为空，则将其自节点放到队列末尾，然后访问队列头部的节点
 * @tparam T
 */
template<class T>
void BST<T>::levelOrder(){
    Queue<BSTNode<T> *> queue;
    BSTNode<T> *curNode = root;

    if(curNode != 0){
        queue.enqueue(curNode);

        while(!queue.empty()){
            curNode = queue.dequeue();  //- 弹出队列队首元素

            visit(curNode);

            if(curNode->left != 0){
                queue.enqueue(curNode->left);
            }

            if(curNode->right != 0){
                queue.enqueue(curNode->right);
            }
        }
    }
}



template<class T>
void BST<T>::MorrisInOrder(){
    BSTNode<T> *p = root, *tmp;
    while(p != 0){
        if(p->left == 0){
            visit(p);
            p = p->right;
        }else{
            tmp = p->left;
            while(tmp->right != 0 && tmp->right != p){
                tmp = tmp->right;
            }

            if(tmp->right == 0){
                tmp->right = p;
                p = p->left;
            }else{
                visit(p);
                tmp->right = 0;
                p = p->right;
            }
        }
    }
}


template<class T>
void BST<T>::MorrisPreOrder(){
    BSTNode<T> *p = root, *tmp;
    while(p != 0){
        if(p->left == 0){
            visit(p);
            p = p->right;
        }else{
            tmp = p->left;

            while(tmp->right != 0 && tmp->right != p){
                tmp = tmp->right;
            }

            if(tmp->right == 0){
                visit(p);
                tmp->right = p;
                p = p->left;
            }else{
                tmp->right = 0;
                p = p->right;
            }
        }
    }
}


template<class T>
void BST<T>::MorrisPostOrder(){
    BSTNode<T> *p = new BSTNode<T>(), *tmp, *q, *r, *s;
    p->left = root;

    while(p != 0){
        if(p->left == 0){
            p = p->right;
        }else{
            tmp = p->left;

            while(tmp->right != 0 && tmp->right != p){
                tmp = tmp->right;
            }

            if(tmp->right == 0){
                tmp->right = p;
                p = p->left;
            }else{
                for(q = p->left, r = q->right, s = r->right;
                    r != p; q = r, r = s, s = s->right){
                    r->right = q;
                }

                for(s = q->right; q != p->left;
                    q->right = r, r = q, q = s, s = s->right){
                    visit(q);
                }

                visit(p->left);
                tmp->right = 0;
                p = p->right;
            }
        }
    }
}

/**
 * 保持二叉查找树的平衡性，插入节点
 * 这里使用数组作为二叉树的方式有点不一样，数组中间的元素指定为根，这个数组包含两个子数组，
 * 一个数组是从开始到刚才根的元素之间所有的元素；另一个是选为根的元素到数组末尾之间所有的元素
 * @tparam T
 * @param data
 * @param first
 * @param last
 */
template<class T>
void BST<T>::balance(T data[], int first, int last){
    if(first <= last){
        int middle = (first + last) / 2;
        insert(data[middle]);
        balance(data, first, middle - 1); //- 递归，当前节点的左子树
        balance(data, middle + 1, last);  //- 递归，当前节点的右子树
    }
}


#endif //DATASTRUCTURESANDALGORITHMS4TH_GENBST_H

























