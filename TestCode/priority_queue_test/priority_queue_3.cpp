/** 
 * author: zzw5005
 * date: 2020/1/4 21:08
*/

#include <queue>
#include <vector>
#include <iostream>

struct node{
    int x, y;
    node(int x, int y) : x(x), y(y){}
};

/**
 * 自定义的比较器
 */
struct cmp{
    //- 在STL中默认使用()比较，这个其实叫做仿函数
    bool operator()(node a, node b){
        if(a.x == b.x){
            return a.y >= b.y;
        }else{
            return a.x > b.x;
        }
    }
};

int main0kc5(){
    std::priority_queue<node, std::vector<node>, cmp> PQueue;

    for(int i = 0; i<= 5; i++){
        for(int j = 1; j <= 5; j++){
            PQueue.push(node(i, j));
        }
    }

    while(!PQueue.empty()){
        std::cout << "(" << PQueue.top().x << "," << PQueue.top().y << ") ";
        PQueue.pop();
    }

    return 0;
}



























