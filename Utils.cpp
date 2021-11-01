#include <iostream>
#include <vector>

using namespace std;


//Find all 2^N Subsets of a vector
vector< vector<int> > generateSubsets(const vector<int>& v){
	
	int N = (1<<v.size()); // 2^N
	vector< vector<int> > powerset(N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < v.size(); j++){
			// if jth bit is set in i
			if(i & (1 << j)) powerset[i].push_back(v[j]);
		}
	}

	return powerset;
}


void generateSubsetsBacktrack(const vector<int>& v, vector< vector<int> >& ans, vector<int>& curr, int idx) {
	if (idx == v.size()) {
		ans.push_back(curr);
		return;
	}
	generateSubsetsBacktrack(v, ans, curr, idx + 1);
	curr.push_back(v[idx]);
	generateSubsetsBacktrack(v, ans, curr, idx + 1);
	curr.pop_back();
}

void generateSubsetsBacktrack2(const vector<int>& v, vector< vector<int> >& ans, vector<int>& curr, int idx) {
 		ans.push_back(curr);

        for (int i = idx; i < v.size(); i++) {
            curr.push_back(v[i]);
            generateSubsetsBacktrack2(v, ans, curr, i + 1);
            curr.pop_back();
        }
}


vector< vector<int> >  generateSubsetsBacktrack(const vector<int>& v) {
	vector< vector<int> > powerset;
	vector<int> temp;
	generateSubsetsBacktrack(v, powerset, temp, 0);

	return powerset;
}

template<typename T>
void print2DVector(const vector< vector<T> >& v){
	cout << "--------------------\n";
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

	print2DVector( generateSubsetsBacktrack(v) );
}
