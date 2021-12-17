#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& v) : vals(v) {
        int n  = v.size();
        sums.assign( 4 * n, 0);
        buildTree(1, 0, n -1);
    }

    int sum(int left, int right) const {
        return sum(1, 0, vals.size()-1, left, right);
    }
    int update(int idx, int newVal) {
        int diff = newVal - vals[idx];
        vals[idx] = newVal;
        update(1, 0, vals.size() - 1, idx, diff);
    }
private:
    void update (int idx, int segmentLeft, int segmentRight, int targetIdx, int diff) {
        if (targetIdx < segmentLeft || targetIdx > segmentRight) {
            return;
        }
        sums[idx] += diff;
        if (segmentLeft != segmentRight) {
            int mid = segmentLeft + (segmentRight - segmentLeft) / 2;
            update(leftIdx(idx), segmentLeft, mid, targetIdx, diff);
            update(rightIdx(idx), mid + 1, segmentRight, targetIdx, diff);
        }
    }
    int sum(int idx, int segmentLeft, int segmentRight, int queryLeft, int queryRight) const {
        if (queryLeft <= segmentLeft && queryRight >= segmentRight) return sums[idx];
        if (queryLeft > segmentRight || queryRight < segmentLeft) return 0;
        int mid = segmentLeft + (segmentRight-segmentLeft) / 2;
        return sum(leftIdx(idx), segmentLeft, mid, queryLeft, queryRight) + sum(rightIdx(idx), mid + 1, segmentRight, queryLeft, queryRight);
    }
    void buildTree(int idx, int left, int right) {
        if (left == right) {
            sums[idx] = vals[left];
        } else {
            int mid = left + (right - left) / 2;
            buildTree(leftIdx(idx), left , mid);
            buildTree(rightIdx(idx), mid + 1, right);
            sums[idx] = sums[leftIdx(idx)] + sums[rightIdx(idx)];
        }
    }
    int leftIdx(int idx) const {return idx * 2; }
    int rightIdx(int idx) const { return idx * 2 + 1; }
    std::vector<int> sums;
    std::vector<int> vals;
};




int main() {
    std::vector<int> vec = {23, 4, 2, 18, 15, 20, 11};
    SegmentTree st(vec);

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
    assert(st.sum(3, 3) == 182);
}
