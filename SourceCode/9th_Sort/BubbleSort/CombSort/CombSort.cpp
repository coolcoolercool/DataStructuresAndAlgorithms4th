/** 
 * author: zzw5005
 * date: 2020/1/16 21:21
*/

/**
 * 梳排序:
 * 在冒泡排序的基础上，通过比较元素彼此之间的步长位置这种方式先对数组元素进行预处理。
 * 在每次移动中，步长会越来越小，直至他等于1。
 * 这一理念就是在进行正式排序前先将一些大元素移至数组的底部。
 *
 * 时间复杂度O(nlgn)
 */


#include <iostream>
#include <vector>
#include "../../ToolClass.h"

using namespace std;

void CombSort(vector<int>& vec){
    int step = vec.size(), j = 0, k = 0;

    //- 预处理部分
    while((step = int(step / 1.3)) > 1){
        for(j = vec.size() - 1; j >= step; j--){
            k = j - step;
            if(vec[j] < vec[k]){
                swap(vec[j], vec[k]);
            }
        }
    }

    //- 预处理后，进行原来的冒泡排序
    bool flag = true;
    for(int i = 0; (i < vec.size() - 1) && flag; i++){
        for(j = vec.size() - 1, flag = false; j > i; --j){
            if(vec[j] < vec[j - 1]){
                swap(vec[j], vec[j - 1]);
                flag = true;
            }
        }
    }
}


int main6nb1(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};

    cout << "排序之前的原数组: " << endl;
    printArr(vec);

    CombSort(vec);

    cout << "排序以后的新数组: " << endl;
    printArr(vec);
}



















