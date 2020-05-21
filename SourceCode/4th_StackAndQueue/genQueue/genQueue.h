/** 
 * author: zzw5005
 * date: 2020/1/3 21:02
*/

/**
 * 使用链表实现队列
 */

#ifndef DATASTRUCTURESANDALGORITHMS4TH_GENQUEUE_H
#define DATASTRUCTURESANDALGORITHMS4TH_GENQUEUE_H

#include <list>


template<class T>
class Queue{
public:
    Queue(){}

    void clear(){
        lst.clear();
    }

    bool isEmpty() const{
        return lst.front();  //- 返回链表的第一个元素
    }

    //- 弹出并返回队列顶部元素
    T dequeue(){
        T el = lst.front();
        lst.pop_front();
        return el;
    }

    //- 在队列的尾部添加元素
    void enqueue(const T& el){
        lst.push_back(el);
    }

private:
    std::list<T> lst;
};

#endif //DATASTRUCTURESANDALGORITHMS4TH_GENQUEUE_H
