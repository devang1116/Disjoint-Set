//
//  main.cpp
//  Disjoint Set Data Structure
//
//  Created by Devang Papinwar on 05/10/21.
//

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
    public:
    int size = 10;
    int set[10];
    
    
    DisjointSet(int s)
    {
        size = s;
    }
    
    void makeSet()
    {
        for(int i = 0 ; i < size ; i++)
        {
            set[i] = i;
        }
    }
    
    int find(int val)
    {
        int value = 0;
        if(val <= 0 || val >= size)
        {
            return 0;
        }
        if(set[val] == val)
        {
            value = set[val];
        }
        else
        {
            find(set[val]);
        }
        return value;
    }
    
    void union_(int node1 , int node2)
    {
        if(node1 <= 0 || node1 >= size || node2 <= 0 || node2 >= size)
        {
            return;
        }
        if(find(node1) == find(node2))
        {
            return;
        }
        set[node1] = node2;
    }
    
};

int main(int argc, const char * argv[])
{
    DisjointSet ds(5);
    
    ds.makeSet();
    
    for(int i =0 ; i < 5 ; i++)
    {
        cout << ds.find(i) << endl;
    }
    
    ds.union_(1, 3);
    ds.union_(3, 4);
    
    for(int i =0 ; i < 5 ; i++)
    {
        cout << ds.find(i) << endl;
    }
    return 0;
}
