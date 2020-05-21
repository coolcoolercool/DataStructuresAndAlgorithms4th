/** 
 * author: zzw5005
 * date: 2020/1/3 15:55
*/

/**
 * 跳表的实现
 */

#ifndef DATASTRUCTURESANDALGORITHMS4TH_GENSKIPLIST_H
#define DATASTRUCTURESANDALGORITHMS4TH_GENSKIPLIST_H

#include <cstdlib>

const int MaxLevel = 4;

template<class T>
class SkipListNode{
public:
    SkipListNode(){

    }

    T key;
    SkipListNode **next; //- 指向指针的指针？
};

template<class T>
class SkipList{
public:
    SkipList();
    bool isEmpty() const;
    void choosePowers();
    int chooseLevel();
    T* skipListSearch(const T&);
    void skipListInsert(const T&);

private:
    typedef SkipListNode<T> *nodePtr;
    nodePtr root[MaxLevel];
    int powers[MaxLevel];  //- 确定要插入的节点的级
};


/**
 * 构造器
 * @tparam T
 */
template<class T>
SkipList<T>::SkipList(){
    for(int i = 0; i < MaxLevel; i++){
        root[i] = 0;
    }
}

template<class T>
bool SkipList<T>::isEmpty() const{
    return root[0] == 0;
}

template<class T>
void SkipList<T>::choosePowers(){
    powers[MaxLevel - 1] = (2 << (MaxLevel - 1)) - 1; //- 2^MaxLevel - 1
    for(int i = MaxLevel - 2, j = 0; i >= 0; i--, j++){
        powers[i] = powers[i + 1] - (2 << j);          //- 2^(j+1)
    }
}


template<class T>
int SkipList<T>::chooseLevel(){
    int i, r = rand() % powers[MaxLevel - 1] + 1;
    for(i = 1; i < MaxLevel; i++){
        if(r < powers[i]){
            return i - 1;
        }
    }

    return i - 1;  //-
}


template<class T>
T* SkipList<T>::skipListSearch(const T& key){
    if(isEmpty()){
        return 0;
    }

    nodePtr prev, curr;
    int lvl;
    for(lvl = MaxLevel - 1; lvl >= 0 && !root[lvl]; lvl--);

    prev = curr = root[lvl];
    while(true){
        if(key == curr->key){
            return &curr->key;
        }else if(key < curr->key){
            if(lvl == 0){
                return 0;
            }else if(curr == root[lvl]){
                curr = root[--lvl];
            }else{
                curr = *(prev->next + lvl);
            }
        }else{
            prev = curr;
            if(*(curr->next + lvl) != 0){
                curr = *(curr->next + lvl);
            }else{
                for(lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--);

                if(lvl >= 0){
                    curr = *(curr->next + lvl);
                }else{
                    return 0;
                }
            }
        }
    }
}

/**
 * 在跳表中插入一个节点
 * @tparam T
 * @param key
 */
template<class T>
void SkipList<T>::skipListInsert(const T& key){
    nodePtr curr[MaxLevel] , prev[MaxLevel], newNode;
    int lvl, i;

    curr[MaxLevel - 1] = root[MaxLevel - 1];
    prev[MaxLevel - 1] = 0;

    for(lvl = MaxLevel - 1; lvl >= 0; lvl--){
        while(curr[lvl] && curr[lvl]->key < key){  //- 此层发现比目标值要小，则向下层链表搜索
            prev[lvl] = curr[lvl];
            curr[lvl] = *(curr[lvl]->next + lvl);
        }

        if(curr[lvl] && curr[lvl]->key == key){
            if(prev[lvl] == 0){
                curr[lvl - 1] = root[lvl - 1];
                prev[lvl - 1] = 0;
            }else{
                curr[lvl - 1] = *(prev[lvl]->next + lvl - 1);
                prev[lvl - 1] = prev[lvl];
            }
        }
    }

    lvl = chooseLevel();
    newNode = new SkipListNode<T>();
    newNode->next = new nodePtr[sizeof(nodePtr) * (lvl + 1)];
    newNode->key = key;
    for(i = 0; i <= lvl; i++){
        *(newNode->next + i) = curr[i];
        if(prev[i] == 0){
            root[i] = newNode;
        }else{
            *(prev[i]->next + i) = newNode;
        }
    }
}

#endif //DATASTRUCTURESANDALGORITHMS4TH_GENSKIPLIST_H























