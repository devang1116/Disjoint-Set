//
//  main.cpp
//  Disjoint Set Data Structure
//
//  Created by Devang Papinwar on 05/10/21.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// A class to represent a disjoint set
class DisjointSet
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
 
public:
 
    // perform MakeSet operation
    void makeSet(vector<int> const &universe)
    {
        // create `n` disjoint sets (one for each item)
        for (int i: universe)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
 
    // Find the root of the set in which element `k` belongs
    int Find(int k)
    {
        // if `k` is root
        if (parent[k] == k) {
            return k;
        }
 
        // recur for the parent until we find the root
        return Find(parent[k]);
    }
 
    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find the root of the sets in which elements
        // `x` and `y` belongs
        int x = Find(a);
        int y = Find(b);
 
        if(x == y)
        {
            return ;
        }
        if(rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else if(rank[y] > rank[x])
        {
            parent[x] = y;
        }
        else
        {
            parent[x] = y;
            rank[y]++;
        }
    }
};
 
void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i: universe) {
        cout << ds.Find(i) << " - ";
    }
    cout << endl;
}
 
// Disjoint–Set data structure (Union–Find algorithm)
int main()
{
    // universe of items
    vector<int> universe = { 1, 2, 3, 4, 5 };
 
    // initialize `DisjointSet` class
    DisjointSet ds;
 
    cout << "Disjoint Set using Union Rank" << endl;
    // create a singleton set for each element of the universe
    ds.makeSet(universe);
    printSets(universe, ds);
 
    ds.Union(4, 3);        // 4 and 3 are in the same set
    printSets(universe, ds);
 
    ds.Union(2, 1);        // 1 and 2 are in the same set
    printSets(universe, ds);
    ds.Union(1, 3);        // 1, 2, 3, 4 are in the same set
    printSets(universe, ds);
 
    return 0;
}
