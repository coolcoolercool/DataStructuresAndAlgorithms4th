/** 
 * author: zzw5005
 * date: 2020/1/16 13:31
*/


/**
 * ð������:
 * �������ͷ����β����ÿ�αȽ��������ڵ�λ�õ�Ԫ�أ����ǰ�߱Ⱥ��ߴ��򽻻����ߵ�λ�ã�Ȼ����űȽ���һ�����ڵ�λ��Ԫ��
 * ��������С��Ԫ�ؾ������������ߣ��ϴ��Ԫ�ؾ�������������ұ�
 */

#include <vector>
#include <iostream>
#include "../ToolClass.h"

using namespace std;

void BubbleSort(vector<int>& vec){
    //- ��־����ʾһ�α������������Ƿ����˽����Ĳ��������û�з��������Ĳ�����
    //- ���ʾ�����Ѿ�������ģ�����ֹͣ�������
    bool flag = true;

    int pos = 0;  //- ��ʾѭ���У����һ�ν�����λ������
    int end = vec.size() - 1;

    //- ���ѭ��ֻ��Ϊ�˿��Ʊ����Ĵ������ڲ�ѭ���Ľ�����������ʵ���������
    for(int i = 0; (i < vec.size()) && flag; i++){
        flag = false;

        for(int j = 0; j < end; j++){
            if(vec[j] > vec[j + 1]){
                swap(vec[j], vec[j + 1]);
                flag = true;
                pos = j;
            }
        }

        end = pos;
        cout << "flag: " << flag << endl;
        cout << pos << endl;

        printArr(vec);
    }
}

int main9lg4(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};

    cout << "����֮ǰ��ԭ����: " << endl;
    printArr(vec);

    BubbleSort(vec);

    cout << "�����Ժ��������: " << endl;
    printArr(vec);
}










