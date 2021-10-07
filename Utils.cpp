#include <iostream>
#include <vector>

using namespace std;


//Find all 2^N Subsets of a vector
vector< vector<int> > generateSubsets(const vector<int>& v){

	int N = (1<<v.size()); // 2^N
	vector< vector<int> > permutations(N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			// if jth bit is set in i
			if(i & (1 << j)) permutations[i].push_back(v[j]);
		}
	}

	return permutations;
}


template<typename T>
void print2DVector(const vector< vector<T> >& v){
	for(int i=0; i<v.size(); i++){
		cout<<i<<" : [ ";
		for(int j=0; j<v[i].size(); j++){
			cout<<v[i][j]<<" ";
		}
		cout<<"]\n";
	}
}


int main(){

	vector<int> v{1,2,3,4,5};
	print2DVector( generateSubsets(v) );
}
