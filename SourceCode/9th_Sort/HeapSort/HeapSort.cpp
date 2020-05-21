/** 
 * author: zzw5005
 * date: 2020/1/17 20:46
*/

#include <iostream>
#include <vector>
#include "../ToolClass.h"

using namespace std;

void AdjustHeap(vector<int>&, int, int);

void HeapSort(vector<int>& vec){
    int size = vec.size();

    //- 构建大根堆（从最后一个非叶子节点开始向上调整）
    for(int i = size / 2 - 1; i >= 0; i--){
        AdjustHeap(vec, size, i);
    }

    //- 调整大根堆
    for(int i = size - 1; i >= 1; i--){
        swap(vec[0], vec[i]);   //- 将当前数组的最大值，放置到数组末尾
        AdjustHeap(vec, i, 0);  //- 将未完成排序的部分恢复大根堆
    }
}

/**
 * 恢复大根堆的特性: 每个根节点都比其子节点的值要大
 * 每次先检查是否根节点比其子节点要大，如果不是则交换根节点和子节点的位置
 * @param vec
 * @param len
 * @param index 当前子树根节点在数组中的索引位置，此位置元素是当前子树的最大值，
 *              在数组体现就是当前索引以及到数组末尾的元素中的最大值
 */
void AdjustHeap(vector<int>& vec, int len, int index){
    int left = 2 * index + 1;     //- index节点的左子节点
    int right = 2 * index + 2;    //- index节点的右子节点

    int maxIndex = index;

    if(left < len && vec[left] > vec[maxIndex]){
        maxIndex = left;
    }

    if(right < len && vec[right] > vec[maxIndex]){
        maxIndex = right;
    }

    if(maxIndex != index){
        swap(vec[maxIndex], vec[index]);
        AdjustHeap(vec, len, maxIndex);
    }
}

int main0hd4(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};

    cout << "排序之前的原数组: " << endl;
    printArr(vec);

    HeapSort(vec);

    cout << "排序以后的新数组: " << endl;
    printArr(vec);

    return 0;
}