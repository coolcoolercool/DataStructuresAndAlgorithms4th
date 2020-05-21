/** 
 * author: zzw5005
 * date: 2020/1/4 21:21
*/

#include <iostream>
#include <queue>

struct cmp1{
    int x;
    cmp1(int a) : x(a){
    }

    bool operator<(const cmp1& a) const{
        return x < a.x;        //- 大顶堆
    }
};

//- 可以看成结构cmp1的自定义比较器结构
struct cmp2{
    //- 重载操作符()，叫做仿函数
    bool operator()(cmp1 a, cmp1 b){
        return a.x < b.x;       //- 大顶堆
    }
};

int main9gb4(){
    cmp1 a(1);
    cmp1 b(2);
    cmp1 c(3);

    std::priority_queue<cmp1> pqueue;

    pqueue.push(b);;
    pqueue.push(c);
    pqueue.push(a);

    while(!pqueue.empty()){
        std::cout << pqueue.top().x << std::endl;
        pqueue.pop();
    }

    std::cout << std::endl;

    std::priority_queue<cmp1, std::vector<cmp1>, cmp2> pqueue1;
    pqueue1.push(c);
    pqueue1.push(b);
    pqueue1.push(a);

    while(!pqueue1.empty()){
        std::cout << pqueue1.top().x << std::endl;
        pqueue1.pop();
    }
}






























