/** 
 * author: zzw5005
 * date: 2020/1/4 20:15
*/

#include <cstdio>
#include <queue>
#include <iostream>

struct node_1{
    node_1(){}
    node_1(int x, int y) : x(x), y(y){
    }

    int x, y;
    bool operator<(const node_1& node) const{
        return x < node.x;
    }
};

int main7lc4(){
    std::priority_queue<node_1> PQueue;

    node_1 node1(1,1);
    PQueue.push(node1);
    node_1 node2(2,2);
    PQueue.push(node2);
    node_1 node3(3,3);
    PQueue.push(node3);

    PQueue.push(node_1(5,5));
    PQueue.push(node_1(4,4));

    while(!PQueue.empty()){
        std::cout << "(" << PQueue.top().x << "," << PQueue.top().y << ") ";
        PQueue.pop();
    }
}

