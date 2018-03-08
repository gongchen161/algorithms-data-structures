#include <vector>
#include <queue>
#include <limits>
using namespace std;


//adjList: the ith row is vertex i's (neighbor, weight)
//return: a vector containing the shortest distance from start to vetex i
vector<int> dijkstra(const vector< vector<pair<int,int>> > adjList, int start) {
    vector<int> dist(adjList.size() + 1);
    for (size_t i = 0; i<adjList.size(); ++i){
        dist[i] = numeric_limits<int>::max();
    }
    dist[start] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater< pair<int,int> > > pq;
    
    pq.push(make_pair(0, start));
    
    while(!pq.empty()) {
        pair<int,int> front = pq.top();
        pq.pop();
        int w = front.first;
        int v = front.second;
        
        if (w <= dist[v]) {
            for (size_t i = 0; i < adjList[v].size(); i++) {
                pair<int,int> cur = adjList[v][i];
                if(dist[v] + cur.second < dist[cur.first]){
                    dist[cur.first] = dist[v] + cur.second;
                    pq.push(make_pair(dist[cur.first], cur.first));
                    
                }
            }
            
        }
        
    }
    
    return dist;
}