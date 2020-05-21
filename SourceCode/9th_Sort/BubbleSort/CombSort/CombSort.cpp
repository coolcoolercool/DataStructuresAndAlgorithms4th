/** 
 * author: zzw5005
 * date: 2020/1/16 21:21
*/

/**
 * ������:
 * ��ð������Ļ����ϣ�ͨ���Ƚ�Ԫ�ر˴�֮��Ĳ���λ�����ַ�ʽ�ȶ�����Ԫ�ؽ���Ԥ����
 * ��ÿ���ƶ��У�������Խ��ԽС��ֱ��������1��
 * ��һ��������ڽ�����ʽ����ǰ�Ƚ�һЩ��Ԫ����������ĵײ���
 *
 * ʱ�临�Ӷ�O(nlgn)
 */


#include <iostream>
#include <vector>
#include "../../ToolClass.h"

using namespace std;

void CombSort(vector<int>& vec){
    int step = vec.size(), j = 0, k = 0;

    //- Ԥ������
    while((step = int(step / 1.3)) > 1){
        for(j = vec.size() - 1; j >= step; j--){
            k = j - step;
            if(vec[j] < vec[k]){
                swap(vec[j], vec[k]);
            }
        }
    }

    //- Ԥ����󣬽���ԭ����ð������
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

    cout << "����֮ǰ��ԭ����: " << endl;
    printArr(vec);

    CombSort(vec);

    cout << "�����Ժ��������: " << endl;
    printArr(vec);
}



















