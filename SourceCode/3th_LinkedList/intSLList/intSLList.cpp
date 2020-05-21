/** 
 * author: zzw5005
 * date: 2020/1/2 21:28
*/

/**
 *
 */

#include <iostream>
#include "intSLList.h"

//- 析构函数
IntSLList::~IntSLList(){
    //- 遍历链表，删除每个节点
    for(IntSLLNode *p ; !isEmpty(); ){
        p = head -> next;
        delete head;
        head = p;
    }
}


void IntSLList::addToHead(int el){
    //- 这个构造函数，构造一个链表节点，然后链表节点的下一个节点是原先的head节点。如果原先链表是空链表，则head和tail都是null
    head = new IntSLLNode(el, head);
    if(tail == 0){   //- 如果链表原先为一个空链表
        tail = head;
    }
}

void IntSLList::addToTail(int el){
    if(tail != 0){  //- 如果链表不为空
        tail->next = new IntSLLNode(el); //- 先创建一个节点，next为null，然后让原先的尾节点的next指向该节点
        tail = tail->next;   //- 更新tail
    }else{ //- 如果原先链表为空
        head = tail = new IntSLLNode(el);
    }
}

/**
 * 删除头节点
 * @return
 */
int IntSLList::deleteFromHead(){
    int el = head -> info;
    IntSLLNode *tmp = head;
    if(head == tail){  //- 如果链表此时只有一个节点
        head = tail;
    }else{
        head = head->next;
    }

    delete tmp;
    return el;
}

/**
 * 删除尾节点
 * @return
 */
int IntSLList::deleteFromTail(){
    int el = tail->info;
    if(head == tail){     //- 如果链表只有一个节点
        delete head;
        head = tail = 0;
    }else{  //- 如果链表中有超过一个的节点
        IntSLLNode *tmp;  //- 找到尾节点的前一个节点
        for(tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp;       //- 让尾节点的前一个节点变成新的尾节点
        tail->next = 0;
    }

    return el;
}

/**
 * 删除链表中的一个节点，这个节点可能是尾节点，可能是头节点和链表中间的节点
 * 平均时间复杂度O(n)
 * @param el
 */
void IntSLList::deleteNode(int el){
    if(head != 0){  //- 如果链表不为空
        if(head == tail && el == head->info){ //- 如果链表只有一个节点
            delete head;      //- 删除头节点
            head = tail = 0;  //- 更新头节点和尾节点
        }else if(el == head->info){  //- 链表多余一个节点并且删除的节点是头节点（这里假设节点的之间的值是不同的，可见存在一定的限制）
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp;   //- 删除原先的头节点
        }else{  //- 如果删除的节点是尾节点或者是链表中间的节点
            //- 如果删除的节点是尾节点，因为单链表无法回溯到上一个节点，所以需要找到尾节点的前一个节点
            //- 如果删除的节点是链表中间的节点，则在遍历过程中寻找这个节点的前一个节点
            IntSLLNode *pred, *tmp;
            for(pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el);
                        pred = pred->next, tmp = tmp->next);

            if(tmp != 0){ //- 如果删除的节点不是尾节点（tmp是pred节点的下一个节点）
                pred->next = tmp->next;  //- 跨过去了tmp节点
                if(tmp == tail){   //- 如果要删除的节点是tmp是尾节点，则直接将pred设置尾尾节点即可
                    tail = pred;
                }

                delete tmp;
            }
        }
    }
}

/**
 * 查找一个节点是否在链表中
 * 时间复杂度O(n)
 * @param el
 * @return
 */
bool IntSLList::isInList(int el) const{
    IntSLLNode *tmp;
    for(tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);

    return tmp != 0;
}

/**
 * 打印链表中的元素
 */
void IntSLList::printAll() const{
    for(IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next){
        std::cout << tmp->info << " ";
    }

    std::cout << std::endl;
}

















