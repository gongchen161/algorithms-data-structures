#include <vector>
#include <queue>
#include <limits>
#include <climits>
using namespace std;


// Find the shortest path from start to all the other nodes
// adjList[i] = vector of (neighborNodeIdx, weight) of the ith node
vector<int> dijkstra(const vector< vector< pair<int,int> > >& adjList, int start) {
    vector<int> dist(adjList.size());

    for (size_t i = 0; i<adjList.size(); ++i){
        dist[i] = INT_MAX;
    }
    
    dist[start] = 0;
    
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > > pq;
    
    // push a pair of (distance, nodeIdx)
    pq.push(make_pair(0, start));
    
    while(!pq.empty()) {
        pair<int,int> front = pq.top();
        pq.pop();
        int w = front.first;
        int v = front.second;
        
        if (w <= dist[v]) {
            for (auto& neighbor : adjList[v]) {
                
                if(dist[v] + neighbor.second < dist[neighbor.first]){
                    // found a shorter path
                    dist[neighbor.first] = dist[v] + neighbor.second;
                    pq.push(make_pair(dist[neighbor.first], neighbor.first));
                    
                }
            }
            
        }
        
    }
    
    return dist;
}

vector< vector< pair<int,int> > > convertAdjacencyMatrixToAdjacencyList(const vector< vector<int> >& matrix) {

    vector< vector< pair<int,int> > > res(matrix.size());

    for (size_t i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] != 0) {
                res[i].push_back(make_pair(j, matrix[i][j]));
            }
        }
    }
    return res;
}

int main() {

    // this test case was borrowed from
    // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    vector<int> dist = dijkstra( convertAdjacencyMatrixToAdjacencyList( { 
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }
    ), 0);

    vector<int> ans  = {0, 4, 12, 19, 21, 11, 9, 8, 14};
    assert(dist.size() == ans.size());
    for (int i = 0; i < ans.size(); i++) {
         assert(dist[i] == ans[i]);
    }
   

}