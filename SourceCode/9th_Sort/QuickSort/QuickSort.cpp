/** 
 * author: zzw5005
 * date: 2020/1/17 21:35
*/

/**
 * ��������:
 * 1��������������һ��Ԫ�أ���Ϊ ����׼����pivot��;
 * 2�������������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ��棨��ͬ�������Ե���һ�ߣ���
 *   ����������˳�֮�󣬸û�׼�ʹ������е��м�λ�á������Ϊ������partition��������
 * 3���ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������
 *    ÿ�εĵ�����iteration���У������ٻ��һ��Ԫ�ذڵ�������λ��ȥ��
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
        //- ������Ŧֵ����벿�ֺ���Ŧֵ���Ұ벿�֣��ֱ�ݹ���ú������п���
        QuickSort(vec, left, partitionIndex - 1);
        QuickSort(vec, partitionIndex + 1, right);
    }
}

/**
 * ����Ŧֵ pivot �ŵ�������ʵ�λ�á�
 * ����˵�����������У���Ŧֵ����������ߵ�Ԫ��ֵ��С�ڵ��������ұ�Ԫ�ص�ֵ
 * @param vec
 * @param left
 * @param right
 * @return
 */
int partition(vector<int>& vec, int left, int right){
    int pivot = left;   //- pivot��ʾ��Ŧֵ
    int index = pivot + 1;  //- index��ߵ�ֵ��С�ڵ���pivot���ұߵ�ֵ������pivot

    for(int i = index; i <= right; i++){
        if(vec[i] < vec[pivot]){
            swap(vec[i], vec[index]); //- ����С��pivot��ֵ���Ͱ�index��i��ֵ������index++
            index++;
        }
    }

    swap(vec[pivot], vec[index - 1]); //- ��index-1��pivot���������ʱpivot������ߵ�ֵ��С���ұߵ�ֵ

    return index - 1;
}


int main0gd4(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};

    cout << "����֮ǰ��ԭ����: " << endl;
    printArr(vec);

    QuickSort(vec);

    cout << "�����Ժ��������: " << endl;
    printArr(vec);

    return 0;
}


