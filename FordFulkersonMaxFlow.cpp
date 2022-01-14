#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cassert>

using namespace std;

int findMaxFlow(const vector<vector<int>>& inputFlowMatrix, int source, int target);
pair<bool, int> bfsEdmondsKarps(int source, int target,  vector<vector<int>>& flowMatrix, int N);
int getMinFlow(int source, int target, const vector<int>& parent, const vector<vector<int>>& flowMatrix);
void updateFlowMatrixByMinFlow(int source, int target, const vector<int>& parent, vector<vector<int>>& flowMatrix, int minFlow) ;

// inputFlowMatrix[i][j] = max capacity of node i to node j
int findMaxFlow(const vector<vector<int>>& inputFlowMatrix, int source, int target) {

    // make a copy of inputFlowMatrix to avoid input being modified
    vector<vector<int>> flowMatrix(inputFlowMatrix);

    const int N = flowMatrix.size();
    bool hasAumentedPath = true;
    int maxFlow = 0;
    while (hasAumentedPath) {
        // BFS using Edmonds Karp method
        const auto [foundAugmentedPath, currFlow] = bfsEdmondsKarps(source, target, flowMatrix, N);
        hasAumentedPath = foundAugmentedPath;
        maxFlow += currFlow;
    }

    return maxFlow;
}

pair<bool, int> bfsEdmondsKarps(int source, int target,  vector<vector<int>>& flowMatrix, int N) {

    queue<int> bfsQueue;
    
    // for retrieving back the path from target to source after bfs
    vector<int> parent(N, -1);
    vector<bool> visited(N, false);

    bfsQueue.push(source);
    visited[source] = true;

    bool foundTarget = false;
    while (!bfsQueue.empty()) {
        int curr = bfsQueue.front();
        bfsQueue.pop();

        if (curr == target) {
            foundTarget = true;
            break;
        }
        for (int neighborIndex = 0; neighborIndex < N; neighborIndex++) {
            if (!visited[neighborIndex] && flowMatrix[curr][neighborIndex] > 0) {
                // we can add at least one flow from curr to neighbor
                bfsQueue.push(neighborIndex);
                visited[neighborIndex] = true;

                // store curr -> neighbor
                parent[neighborIndex] = curr;


            }
        }
    }

    if (foundTarget) {
        // retrieve back the path,  find min flow in the path and update flowMatrix
        int minFlow = getMinFlow(source, target, parent, flowMatrix);
        
        // update flowMatrix -- decrease capacity from parent -> neighbor and increase capacity from neighbor -> parent
        updateFlowMatrixByMinFlow(source, target, parent, flowMatrix, minFlow);

        return make_pair(foundTarget, minFlow);
    }

    return make_pair(false, 0);
}

int getMinFlow(int source, int target, const vector<int>& parent, const vector<vector<int>>& flowMatrix) {

    int curr = target;
    int minFlow = INT_MAX;

    while (curr != source) {
    
        int p = parent[curr];

        minFlow = min(minFlow, flowMatrix[p][curr]);

        curr = p;
    }
    return minFlow;
}

void updateFlowMatrixByMinFlow(int source, int target, const vector<int>& parent, vector<vector<int>>& flowMatrix, int minFlow) {
    
    int curr = target;

    while (curr != source) {

        int p = parent[curr];

        flowMatrix[p][curr] -= minFlow;
        flowMatrix[curr][p] += minFlow;

        curr = p;
    }

}


int main() {

    // 0 -> 1: 23
    assert(findMaxFlow({
           {0, 23},
           {0, 0}
        }, 0, 1) == 23);


    // no route from source to target
    assert(findMaxFlow({
            { 0, 3, 2, 0, 0, 0 },
            { 0, 0, 2, 0, 0, 0 },
            { 0, 0, 0, 0, 8, 0 },
            { 0, 0, 0, 0, 2, 3 },
            { 0, 0, 0, 0, 0, 7 },
            { 0, 0, 0, 0, 0, 0 } 
        }, 0, 3) == 0);

    // 0 -> 1 -> 3 -> 5 : 3
    // 0 -> 1 -> 3 -> 4 -> 5 : 2
    // 0 -> 2 -> 4 -> 5 : 10
    assert(findMaxFlow({
            { 0, 7, 8, 0, 0, 0 },
            { 0, 0, 2, 5, 0, 0 },
            { 0, 0, 0, 0, 10, 0 },
            { 0, 0, 0, 0, 2, 3 },
            { 0, 0, 0, 0, 0, 12 },
            { 0, 0, 0, 0, 0, 0 } 
        }, 0, 5) == 15);

}