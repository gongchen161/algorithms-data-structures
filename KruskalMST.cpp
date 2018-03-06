#include <vector>
#include “UnionSet.hpp”


//edgeList: sorted edge list with <weight, (v1, v2)>
int kruskalMST(const vector< pair<int, pair<int,int> >>& edgeList, int nVertex, int nEdge) {
    
    int minCost = 0;
    UnionSet uSet(nVertex);
    
    for (int i = 0; i < nEdge; i++) {
        pair<int, pair<int,int>> elm = edgeList[i];
        
        if (!uSet.isSameSet(elm.second.first, elm.second.second)) {
            minCost += elm.first;
            uSet.unionTwo(elm.second.first, elm.second.second);
        }
    }
    
    return minCost;
}
