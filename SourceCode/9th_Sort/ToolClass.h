/** 
 * author: zzw5005
 * date: 2020/1/15 16:37
*/

#ifndef DATASTRUCTURESANDALGORITHMS4TH_TOOLCLASS_H
#define DATASTRUCTURESANDALGORITHMS4TH_TOOLCLASS_H

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void printArr(const vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template<typename T>
void swap(vector<T>& vec, int i, int j){
    T tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

#endif //DATASTRUCTURESANDALGORITHMS4TH_TOOLCLASS_H
