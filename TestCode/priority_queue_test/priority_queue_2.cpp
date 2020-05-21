/** 
 * author: zzw5005
 * date: 2020/1/4 20:34
*/

#include <iostream>
#include <queue>
#include <vector>

int main9nh4(){
    std::priority_queue<int, std::vector<int>, std::less<int>> LessPQueue;
    std::priority_queue<int, std::vector<int>, std::greater<int>> GreaterPQueue;

    int arr[5] = {3,4,5,2,1};

    for(int i = 0; i < 5; i++){
        LessPQueue.push(arr[i]);
        GreaterPQueue.push(arr[i]);
    }

    std::cout << "GreaterPQueue: " << std::endl;
    while(!GreaterPQueue.empty()){
        std::cout << "(" << GreaterPQueue.top() << ") ";
        GreaterPQueue.pop();
    }

    std::cout << std::endl;

    std::cout << "LessPQueue: " << std::endl;
    while(!LessPQueue.empty()){
        std::cout << "(" << LessPQueue.top() << ") ";
        LessPQueue.pop();
    }


}


















