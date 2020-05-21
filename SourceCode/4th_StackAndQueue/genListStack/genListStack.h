/** 
 * author: zzw5005
 * date: 2020/1/3 20:45
*/

#ifndef DATASTRUCTURESANDALGORITHMS4TH_GENLISTSTACK_H
#define DATASTRUCTURESANDALGORITHMS4TH_GENLISTSTACK_H

#include <list>

template<class T>
class LLStack{
public:
    LLStack(){
    }

    void clear(){
        lst.clear();   //- 删除链表所有节点
    }

    bool isEmpty() const{
        return lst.empty();
    }

    T& topEl(){
        return lst.back();  //- 链表中的最后一个元素
    }

    T pop(){
        T el = lst.back();
        lst.pop_back();   //- 删除链表的最后一个节点
        return el;
    }

    void push(const T& el){
        lst.push_back(el);  //- 在链表尾部插入节点
    }

private:
    std::list<T> lst;
};

#endif //DATASTRUCTURESANDALGORITHMS4TH_GENLISTSTACK_H
