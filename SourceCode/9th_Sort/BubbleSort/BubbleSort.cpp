/** 
 * author: zzw5005
 * date: 2020/1/16 13:31
*/


/**
 * 冒泡排序:
 * 从数组的头部到尾部，每次比较两个相邻的位置的元素，如果前者比后者大，则交换两者的位置，然后接着比较下一个相邻的位置元素
 * 这样最后较小的元素就来到数组的左边，较大的元素就来到了数组的右边
 */

#include <vector>
#include <iostream>
#include "../ToolClass.h"

using namespace std;

void BubbleSort(vector<int>& vec){
    //- 标志，表示一次遍历下来数组是否发生了交换的操作，如果没有发生交换的操作，
    //- 则表示数组已经是有序的，可以停止排序过程
    bool flag = true;

    int pos = 0;  //- 表示循环中，最后一次交换的位置索引
    int end = vec.size() - 1;

    //- 外层循环只是为了控制遍历的次数，内层循环的交换操作才是实际排序过程
    for(int i = 0; (i < vec.size()) && flag; i++){
        flag = false;

        for(int j = 0; j < end; j++){
            if(vec[j] > vec[j + 1]){
                swap(vec[j], vec[j + 1]);
                flag = true;
                pos = j;
            }
        }

        end = pos;
        cout << "flag: " << flag << endl;
        cout << pos << endl;

        printArr(vec);
    }
}

int main9lg4(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};

    cout << "排序之前的原数组: " << endl;
    printArr(vec);

    BubbleSort(vec);

    cout << "排序以后的新数组: " << endl;
    printArr(vec);
}










