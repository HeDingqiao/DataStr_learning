//
//  main.cpp
//  hash_table
//
//  Created by hedingqiao on 16/8/8.
//  Copyright © 2016年 hedingqiao. All rights reserved.
//

#include <iostream>
#include "vector"
#include "list"
#include "algorithm"
#include "string"
using namespace std;




//散列函数
int hash(const string &key)
{
    int hashval=0;
    for(int i=0;i<key.length();i++)
    {
        hashval=hashval*37+key[i];
    }
    return hashval;
}
static const int gPrimesCount=10;
static unsigned long gPrimesArray[gPrimesCount]={53,97,193,389,769,1543,3079,6151,12289,25593};
inline unsigned long nextPrime(unsigned long n)
{
    const unsigned long *first=gPrimesArray;
    const unsigned long *last=gPrimesArray+gPrimesCount;
    const unsigned long *pos=lower_bound(first,last,n);
    return pos==last?*(last-1):*pos;
}

//分离链接法
class HashTable
{
public:
    explicit HashTable(int size=101)
    {
        theLists.resize(size);
        currentSize=size;
    }
private:
    vector<list<HashedObj>> theLists;//The array of lists
    int currentSize;
    void rehash();
    int myhash(const HashedObj &x) const;
    
};
int HashTable<HashedObj>::myhash(const HashedObj &x) const
{
    int hashval=hash(x);
    hashval%=theLists.size();
    if(hashval<0)
        hashval+=theLists.size();
}
void HashedObj















int main() {
    return 0;
}
