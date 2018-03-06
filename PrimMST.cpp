#include <vector>
#include <queue>
using namespace std;

//adjList -- row j is vertex j's (neighbor, weight)
void processVertex(const vector< vector<pair<int, int> >>& adjList, priority_queue<pair<int,int>>& pq, vector<bool>& visited, int v) {
    visited[v] = true;
    for (size_t i = 0;  i < adjList[v].size(); i++) {
        pair<int,int> cur = adjList[v][i];
        if(!visited[cur.first]) {
            pq.push(make_pair(-cur.second, -cur.first));
        }
    }
}

//adjList -- row j is vertex j's (neighbor, weight)
int primMST(const vector< vector<pair<int, int> >>& adjList, int start) {
    priority_queue<pair<int,int>> pq;
    vector<bool> visited(adjList.size());
    
    processVertex(adjList, pq, visited, start);
   
    int mstCost = 0;
    while (!pq.empty()) {
        pair<int,int> front = pq.top();
        pq.pop();
        
        int v = -front.second;
        int w = -front.first;
        
        if (!visited[v]) {
            mstCost += w;
            processVertex(adjList, pq, visited, v);
        }
    }
    
    return mstCost;
}