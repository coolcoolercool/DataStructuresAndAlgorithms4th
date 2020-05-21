/** 
 * author: zzw5005
 * date: 2020/1/15 16:03
*/

/**
 * 核心思想:
 * 1、首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
 * 2、再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
 * 3、重复第二步，直到所有元素均排序完毕。
 */

#include <iostream>
#include <vector>

#include "../ToolClass.h"

using std::cout;
using std::endl;
using std::vector;
using std::swap;

void selectSort(vector<int>& vec){
    //- 外层循环n - 1次比较
    for(int i = 0; i < vec.size() - 1; i++){
        int min = i;  //- 保存目前能找到最小值在数组中的下标

        //- 内层循环 n - i次比较
        for(int j = i + 1; j < vec.size(); j++){
            if(vec[j] < vec[min]){
                min = j;  //- 记录目前能找到的最小值的下标
            }
        }

        //- 将找到的最小值和i下标位置的值进行交换
        if(i != min){
            //swap(vec, i, min);         //- 这里使用的自定义的swap函数
            std::swap(vec[i], vec[min]); //- 这里使用的库函数swap
        }
    }
}

int main0nd3(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};
    printArr(vec);

    selectSort(vec);

    printArr(vec);
}