#include <vector>
using namespace std;

class UnionSet {
public:
    UnionSet(int n) : _rank(vector<int>(n, 0)) {
        _parent.resize(n);
        for (int i = 0; i < n; i++) {
            _parent[i] = i;
        }
    }
    
    int findSet(int i) {
        if (_parent[i] == i)
            return i;
        
        return _parent[i] = findSet(_parent[i]);
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        int x = findSet(i);
        int y = findSet(j);
        
        if (x == y){
            return;
        }
        
        if (_rank[x] > _rank[y]) {
            _parent[y] = x;
        } else {
            _parent[x] = y;
            
            if (_rank[x] ==_rank[y]) {
                _rank[x]++;
            }
        }
    }
private:
    vector<int> _parent;
    vector<int> _rank;
};