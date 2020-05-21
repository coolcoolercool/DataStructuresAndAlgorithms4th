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

    //- ��������ѣ������һ����Ҷ�ӽڵ㿪ʼ���ϵ�����
    for(int i = size / 2 - 1; i >= 0; i--){
        AdjustHeap(vec, size, i);
    }

    //- ���������
    for(int i = size - 1; i >= 1; i--){
        swap(vec[0], vec[i]);   //- ����ǰ��������ֵ�����õ�����ĩβ
        AdjustHeap(vec, i, 0);  //- ��δ�������Ĳ��ָֻ������
    }
}

/**
 * �ָ�����ѵ�����: ÿ�����ڵ㶼�����ӽڵ��ֵҪ��
 * ÿ���ȼ���Ƿ���ڵ�����ӽڵ�Ҫ����������򽻻����ڵ���ӽڵ��λ��
 * @param vec
 * @param len
 * @param index ��ǰ�������ڵ��������е�����λ�ã���λ��Ԫ���ǵ�ǰ���������ֵ��
 *              ���������־��ǵ�ǰ�����Լ�������ĩβ��Ԫ���е����ֵ
 */
void AdjustHeap(vector<int>& vec, int len, int index){
    int left = 2 * index + 1;     //- index�ڵ�����ӽڵ�
    int right = 2 * index + 2;    //- index�ڵ�����ӽڵ�

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

    cout << "����֮ǰ��ԭ����: " << endl;
    printArr(vec);

    HeapSort(vec);

    cout << "�����Ժ��������: " << endl;
    printArr(vec);

    return 0;
}