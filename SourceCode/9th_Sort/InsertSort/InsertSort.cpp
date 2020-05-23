/** 
 * author: zzw5005
 * date: 2020/1/12 21:49
*/

#include <vector>
#include <iostream>

#include "../ToolClass.h"

/**
 * 插入排序：
 * 插入排序思路：
 * 1. 从第一个元素开始，该元素可以认为已经被排序
 * 2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
 * 3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
 * 4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
 * 5. 将新元素插入到该位置后
 * 6. 重复步骤2~5
 */
using std::vector;
using std::cout;
using std::endl;

void insertSort(vector<int>& vec) {
    //- 从下标为1的元素开始选择合适的位置插入，因为要与前一个元素比较，选择下标1是为了预防越界
    for (int i = 1; i < vec.size(); i++) {
        int tmp = vec[i]; //- 记录要插入的数据

        //- 从已经排序的序列的最右边的开始向左边依次比较，找到比其小的数
        int j = i;
        //- 所有比tmp大的元素都要复制到下一个位置上
        for (; j > 0 && tmp < vec[j - 1]; j--) {
            vec[j] = vec[j - 1];
        }

        //- 存在比其小的数，插入
        vec[j] = tmp;
    }
}

int main5mn3() {
    vector<int> vec = {6, 9, 2, 6, 5, 0, 2};
    printArr(vec);

    insertSort(vec);

    printArr(vec);
}