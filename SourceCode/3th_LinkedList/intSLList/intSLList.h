/** 
 * author: zzw5005
 * date: 2020/1/2 20:11
*/


/**
 * 单向链表
 */


#ifndef DATASTRUCTURESANDALGORITHMS4TH_INTSLLIST_H
#define DATASTRUCTURESANDALGORITHMS4TH_INTSLLIST_H

class IntSLLNode{
public:
    //- 构造器
    IntSLLNode(){
        next = 0;
    }

    IntSLLNode(int el, IntSLLNode *ptr = 0){
        info = el;
        next = ptr;
    }

    //- 注意这里的成员是共有的，不是私有的
    int info;  //- 节点的值
    IntSLLNode *next;  //- 指向下一个链表节点
};

class IntSLList{
public:
    IntSLList(){
        head = tail = 0;
    }

    ~IntSLList();

    int isEmpty(){
        return head == 0;
    }

    void addToHead(int);   //- 从头节点前添加一个节点。
    void addToTail(int);   //- 从尾节点后添加一个节点
    int deleteFromTail();  //- 删除头节点，并返回它的值
    int deleteFromHead();  //- 删除尾节点，并返回它的值
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;

private:
    IntSLLNode *head, *tail;
};


#endif //DATASTRUCTURESANDALGORITHMS4TH_INTSLLIST_H













