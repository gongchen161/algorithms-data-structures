//Find all the Subsets of a vector
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > GenerateSubsets(const vector<int>& v){

	int N = (1<<v.size());
	vector< vector<int> > permutations(N);
	for(int i=0; i< N; i++){
		for(int j=0; j < N; j++){
			if(i & (1 << j))
				permutations[i].push_back(v[j]);
		}
	}

	return permutations;
}


template<typename T>
void Print2DVector(const vector< vector<T> >& v){
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
	vector< vector<int> > p = GenerateSubsets(v);
	Print2DVector(p);
}
