//
//  main.cpp
//  heap
//
//  Created by hedingqiao on 16/8/9.
//  Copyright © 2016年 hedingqiao. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
template <typename Comparable>
class BinaryHeap {
public:
    explicit BinaryHeap(int capacity=100);
    explicit BinaryHeap(const vector<Comparable> & items);
    bool isEmpety() const;//常函数，不允许修改成员变量
    const Comparable &finMin()const;
    void insert(const Comparable &x);
    void deleteMin(Comparable &minItem);
private:
    int currentSize;
    vector<Comparable> array;
    void BuildHeap();
    void percolateDown(int hole);
    
};
template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x)
{
    if(currentSize==array.size()-1)//容量不够时加倍
        array.resize(array.size()*2);
    int hole=++currentSize;//添加一个空位置
    for(;hole>1&&x<array[hole/2];hole/=2)
        array[hole]=array[hole/2];//不断向下移位
    array[hole]=x;
    
}
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable &minItem)
{
    if(isEmpety())
        throw 5;
    minItem=array[1];
    array[1]=array[currentSize--];
    percolateDown(1);
}
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child;
    Comparable tmp=array[hole];
    for(;hole*2<=currentSize;hole=child)
    {
        child=hole*2;
        if(child!=currentSize&&array[child+1]<array[child])
            child++;
        if(array[child]<tmp)
            array[hole]=array[child];
        else
            break;
    }
    array[hole]=tmp;
}
int main() {
   }
