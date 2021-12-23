#include <vector>
#include <iostream>
#include <cassert>

// class UnionSet {
// public:
//     UnionSet(int n) : _rank(n, 0) {
//         _parent.resize(n);
//         for (int i = 0; i < n; i++) {
//             _parent[i] = i;
//         }
//     }
    
//     int findSet(int i) {
//         if (_parent[i] == i)
//             return i;
        
//         return _parent[i] = findSet(_parent[i]);
//     }
//     bool isSameSet(int i, int j) {
//         return findSet(i) == findSet(j);
//     }
//     void unionTwo(int i, int j) {
//         int x = findSet(i);
//         int y = findSet(j);
        
//         if (x == y){
//             return;
//         }
        
//         if (_rank[x] > _rank[y]) {
//             _parent[y] = x;
//         } else {
//             _parent[x] = y;
            
//             if (_rank[x] ==_rank[y]) {
//                 _rank[x]++;
//             }
//         }
//     }
// private:
//     std::vector<int> _parent;
//     std::vector<int> _rank;
// };


class UnionFind {
public:
    UnionFind(int n) : rank(n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unionSet(int i, int j) {
        
        int x = find(i);
        int y = find(j);

        if (x != y) {
            if (rank[x] > rank[y]) {
                parent[y] = x;
            } else {
                parent[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }

    }
private:
    std::vector<int> parent;
    std::vector<int> rank;
};

bool detectCycle(const std::vector<std::pair<int,int>>& edgeList, int num) {
    UnionFind unionFind(num);

    for (const auto& [a, b] : edgeList) {
        int x = unionFind.find(a);
        int y = unionFind.find(b);

        if (x == y) {
            return true;
        }

        unionFind.unionSet(a, b);
    }
    return false;
}

int main() {
    // We can use unionFind to find cycles in a undirected graph
    std::vector<std::pair<int,int>> edgeList = {
        {0, 1},
        {1, 2},
        {0, 2}
    };

    assert(detectCycle(edgeList, 3));

    std::vector<std::pair<int,int>> edgeList2 = {
        {0, 1},
        {1, 2},
        {0, 3}
    };

    assert(!detectCycle(edgeList2, 4));
}