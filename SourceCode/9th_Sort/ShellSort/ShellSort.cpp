/** 
 * author: zzw5005
 * date: 2020/1/17 16:26
*/

/**
 * 希尔排序:
 * 核心思想:
 * 首先将原数组分割为几个字数组，先比基奥相隔较远的元素，然后再比较相隔较近的元素，
 * 以此类推，最后一次比较相邻的两个元素。从原始数组中每隔 增量h 个元素挑选一个元素，作为子数组的一部分，
 * 这样就将原始数组在逻辑上分成了几个子数组。
 *
 * 代码部分，首先使用gap作为增量（其实这里可以用一个增量的数组来表示，只不过使用gap节约空间）
 * 假设这个gap增量共有k个值，则对原数组进行k次排序
 *
 */

#include <iostream>
#include <vector>
#include <math.h>
#include "../ToolClass.h"

using namespace std;

void ShellSort(vector<int>& vec){

    //- 获取增量序列，先算出增量最大值，然后依次除以3取整，依次获取所有增量
    int gap = 1;
    while(gap < vec.size()){
        gap = gap * 3 + 1;
    }

    //- 假设增量值有k个，则循环k次
    while(gap > 0){
        //- 在每个子数组内部使用插入排序
        for(int i = gap; i < vec.size(); i++){
            int tmp = vec[i];
            int j = i - gap;

            while(j >= 0 && vec[j] > tmp){
                vec[j + gap] = vec[j];
                j -= gap;      //- 这里就是插入排序，只不过插入排序中的gap固定是1，而这里的gap是会变化的
            }

            vec[j + gap] = tmp;
        }

        gap = (int)floor(gap/3);  //- 使用下一个增量值，进行排序
    }
}

int main9lk2(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};

    cout << "排序之前的原数组: " << endl;
    printArr(vec);

    ShellSort(vec);

    cout << "排序以后的新数组: " << endl;
    printArr(vec);
}