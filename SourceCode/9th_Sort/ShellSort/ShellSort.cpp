/** 
 * author: zzw5005
 * date: 2020/1/17 16:26
*/

/**
 * ϣ������:
 * ����˼��:
 * ���Ƚ�ԭ����ָ�Ϊ���������飬�ȱȻ��������Զ��Ԫ�أ�Ȼ���ٱȽ�����Ͻ���Ԫ�أ�
 * �Դ����ƣ����һ�αȽ����ڵ�����Ԫ�ء���ԭʼ������ÿ�� ����h ��Ԫ����ѡһ��Ԫ�أ���Ϊ�������һ���֣�
 * �����ͽ�ԭʼ�������߼��Ϸֳ��˼��������顣
 *
 * ���벿�֣�����ʹ��gap��Ϊ��������ʵ���������һ����������������ʾ��ֻ����ʹ��gap��Լ�ռ䣩
 * �������gap��������k��ֵ�����ԭ�������k������
 *
 */

#include <iostream>
#include <vector>
#include <math.h>
#include "../ToolClass.h"

using namespace std;

void ShellSort(vector<int>& vec){

    //- ��ȡ�������У�������������ֵ��Ȼ�����γ���3ȡ�������λ�ȡ��������
    int gap = 1;
    while(gap < vec.size()){
        gap = gap * 3 + 1;
    }

    //- ��������ֵ��k������ѭ��k��
    while(gap > 0){
        //- ��ÿ���������ڲ�ʹ�ò�������
        for(int i = gap; i < vec.size(); i++){
            int tmp = vec[i];
            int j = i - gap;

            while(j >= 0 && vec[j] > tmp){
                vec[j + gap] = vec[j];
                j -= gap;      //- ������ǲ�������ֻ�������������е�gap�̶���1���������gap�ǻ�仯��
            }

            vec[j + gap] = tmp;
        }

        gap = (int)floor(gap/3);  //- ʹ����һ������ֵ����������
    }
}

int main9lk2(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};

    cout << "����֮ǰ��ԭ����: " << endl;
    printArr(vec);

    ShellSort(vec);

    cout << "�����Ժ��������: " << endl;
    printArr(vec);
}