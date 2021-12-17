#include <iostream>
#include <vector>


class FenwickTree {
public:
    FenwickTree(const std::vector<int>& v)  {
        tree.assign(v.size() + 1, 0);
        vals.assign(v.size(), 0);
        for (int i = 0; i < v.size(); i++) {
            update(i, v[i]);
        }
    }

    int sum(int left, int right) const {
        return sum(right + 1) - sum(left);
    }

    void update(int idx, int newVal) {
        
        updateByDiff(idx + 1, newVal - vals[idx]); 
        vals[idx] = newVal;
    }


private:
    int sum(int idx) const {
        if (idx <= 0) {
            return 0;
        }
        
        return tree[idx] + sum(idx - LSB(idx));
    }
    void updateByDiff(int idx, int diff) {
        for (int i = idx; i < tree.size(); i += LSB(i)) {
            tree[i] += diff;
        }
    }

    int LSB(int x) const { return x & -x; }

    std::vector<int> tree;
    std::vector<int> vals;
};


int main() {


    std::vector<int> vec = {23, 4, 2, 18, 15, 20, 11, 88};
    FenwickTree st(vec);
   
    assert(st.sum(0, 6) == 93);
    assert(st.sum(0, 5) == 82);
    assert(st.sum(1, 5) == 59);
    assert(st.sum(2, 4) ==  35);
    assert(st.sum(3, 3) == 18);

    st.update(2, 12);
    assert(st.sum(0, 6) == 103);
    assert(st.sum(0, 5) == 92);
    assert(st.sum(1, 5) == 69);
    assert(st.sum(2, 4) == 45);
    assert(st.sum(3, 3) == 18);
}