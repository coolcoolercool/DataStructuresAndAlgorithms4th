/** 
 * author: zzw5005
 * date: 2020/1/3 14:38
*/

#ifndef DATASTRUCTURESANDALGORITHMS4TH_GENDLLIST_H
#define DATASTRUCTURESANDALGORITHMS4TH_GENDLLIST_H

#include <iostream>

template<class T>
class DLLNode{
    //- 构造器
    DLLNode(){
        next = prev = 0;
    }
    //- 有参构造器，指定节点的值，前驱节点和后继节点
    DLLNode(const T& el, DLLNode<T> *n = 0, DLLNode<T> *p = 0){
        info = el;
        next = n;
        prev = p;
    }

    T info;
    DLLNode<T> *next, *prev;  //- 指向下一个节点和指向前一个节点的指针
};


template<class T>
class DoublyLinkedList{
    DoublyLinkedList(){
        head = tail = 0;
    }

    void addToDLLTail(const T&); //- 在链表尾部添加一个节点
    T deleteFromDLLTail();  //- 删除链表尾节点

    ~DoublyLinkedList(){
        clear();
    }

    void clear();

    void setToNull(){
        head = tail = 0;
    }

    void addToDLLHead(const T&);  //- 在链表的头节点之前添加一个节点

    T deleteFromDLLHead();  //- 删除链表的头节点

    T& firstEl();   //- 返回链表头节点的值
    T* find(const T&) const;

protected:
    DLLNode<T> *head, *tail;

    //- 操作符重载
    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& dll){
        for(DLLNode<T> *tmp = dll.head; tmp != 0; tmp = tmp->next){
            out << tmp->info << ' ';
        }

        return out;
    }
};



template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el){
    if(head != 0){
        head = new DLLNode<T>(el, head, 0);
        head->next->prev = head;
    }else{
        head = tail = new DLLNode<T>(el);
    }
}

/**
 *
 * @tparam T
 * @param el
 */
template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el){
    if(tail != 0){ //- 如果链表不为空
        tail = new DLLNode<T>(el, 0, tail);  //- 更新tail节点，该结点的next节点为null，prev节点为原tail
        tail->prev->next = tail;             //- 原来的tail节点成了现在tail节点的prev节点，此时让tail节点的前驱节点指向新节点
    }else{ //- 如果链表本来为空，只有一个节点
        head = tail = new DLLNode<T>(el);
    }
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead(){
    T el = head->info;
    if(head == tail){
        delete head;
        head = tail = 0;
    }else{
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }

    return el;
}

/**
 * 删除链表的尾节点，
 * 注意: 调用此函数必须保证链表非空，判断链表中至少存在一个节点
 * @tparam T
 * @return
 */
template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail(){
    T el = tail->info;  //- 需要先保存尾节点的值，因为需要返回它的值
    if(head == tail){  //- 如果链表只有一个节点
        delete head;
        head = tail = 0;  //- 因为此时链表已经没有节点了，所以head和tail都是指向空
    }else{  //- 如果链表多于一个节点
        tail = tail->prev;  //- 更新tail节点
        delete tail->next;  //- 删除原来的tail节点
        tail->next = 0;     //- 更新tail节点的next指针
    }

    return el;  //- 返回原先的尾节点的值
}

template<class T>
T* DoublyLinkedList<T>::find(const T& el) const{
    DLLNode<T> *tmp = head;  //- 这里使用临时变量，为了不影响head的指针指向链表的头节点
    for(; tmp != 0 && !(tmp->info == el); tmp = tmp->next);

    if(tmp == 0){  //- 表示没找到
        return 0;
    }else{         //- 找到了，返回节点的值
        return &tmp->info;
    }
}


template<class T>
T& DoublyLinkedList<T>::firstEl(){
    return head->info;
}

template<class T>
void DoublyLinkedList<T>::clear(){
    for(DLLNode<T> *tmp; head != 0;){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

#endif




























#endif //DATASTRUCTURESANDALGORITHMS4TH_GENDLLIST_H
