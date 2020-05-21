/** 
 * author: zzw5005
 * date: 2020/1/17 21:35
*/

/**
 * 快速排序:
 * 1、从数列中挑出一个元素，称为 “基准”（pivot）;
 * 2、重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
 *   在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
 * 3、递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
 *    每次的迭代（iteration）中，它至少会把一个元素摆到它最后的位置去。
 */

#include <iostream>
#include <vector>
#include "../ToolClass.h"

using namespace std;

void QuickSort(vector<int>&);
void QuickSort(vector<int>&, int, int);
int partition(vector<int>&, int, int);

void QuickSort(vector<int>& vec){
    QuickSort(vec, 0, vec.size() - 1);
}

void QuickSort(vector<int>& vec, int left, int right){
    if(left < right){
        int partitionIndex = partition(vec, left, right);
        //- 对于枢纽值的左半部分和枢纽值的右半部分，分别递归调用函数进行快排
        QuickSort(vec, left, partitionIndex - 1);
        QuickSort(vec, partitionIndex + 1, right);
    }
}

/**
 * 将枢纽值 pivot 放到数组合适的位置。
 * 具体说，就是数组中，枢纽值大于在它左边的元素值，小于等于在它右边元素的值
 * @param vec
 * @param left
 * @param right
 * @return
 */
int partition(vector<int>& vec, int left, int right){
    int pivot = left;   //- pivot表示枢纽值
    int index = pivot + 1;  //- index左边的值都小于等于pivot，右边的值都大于pivot

    for(int i = index; i <= right; i++){
        if(vec[i] < vec[pivot]){
            swap(vec[i], vec[index]); //- 遇到小于pivot的值，就把index和i的值交换，index++
            index++;
        }
    }

    swap(vec[pivot], vec[index - 1]); //- 将index-1与pivot交换，则此时pivot大于左边的值，小于右边的值

    return index - 1;
}


int main0gd4(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};

    cout << "排序之前的原数组: " << endl;
    printArr(vec);

    QuickSort(vec);

    cout << "排序以后的新数组: " << endl;
    printArr(vec);

    return 0;
}


