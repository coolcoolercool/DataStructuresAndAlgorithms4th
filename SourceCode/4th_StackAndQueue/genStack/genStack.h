/** 
 * author: zzw5005
 * date: 2020/1/3 20:39
*/

#ifndef DATASTRUCTURESANDALGORITHMS4TH_GENSTACK_H
#define DATASTRUCTURESANDALGORITHMS4TH_GENSTACK_H

#include<vector>

template<class T, int capacity = 30>
class Stack{
    Stack(){
        pool.reverse(capacity);
    }

    //- 清空栈
    void clear(){
        pool.clear();
    };

    //- 判断栈是否为空
    bool isEmpty(){
        return pool.back();
    }

    //- 弹出栈顶元素
    T pop(){
        T el = pool.back();
        pool.pop_back();
        return el;
    }

    //- 将元素el压入栈顶
    void push(const T& el){
        pool.push_back(el);
    }

private:
    std::vector<T> pool; //- 使用数组储存栈中的元素
};


#endif //DATASTRUCTURESANDALGORITHMS4TH_GENSTACK_H
