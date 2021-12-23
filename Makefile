all: BigNumber Bitmask Dijkstra ExponentialModular FenwickTree GcdAndLcm KmpStringMatching PrimeNumberOperations Trie SegmentTree UnionFind Utils

BigNumber: BigNumber.cpp
	g++ BigNumber.cpp -std=c++17 -o BigNumber.out

Bitmask: Bitmask.cpp
	g++ Bitmask.cpp -std=c++17 -o Bitmask.out

Dijkstra: Dijkstra.cpp
	g++ Dijkstra.cpp -std=c++17 -o Dijkstra.out

ExponentialModular: ExponentialModular.cpp
	g++ ExponentialModular.cpp -std=c++17 -o ExponentialModular.out

FenwickTree: FenwickTree.cpp
	g++ FenwickTree.cpp -std=c++17 -o FenwickTree.out

GcdAndLcm: GcdAndLcm.cpp
	g++ GcdAndLcm.cpp -std=c++17 -o GcdAndLcm.out

KmpStringMatching: KmpStringMatching.cpp
	g++ KmpStringMatching.cpp -std=c++17 -o KmpStringMatching.out

PrimeNumberOperations: PrimeNumberOperations.cpp
	g++ PrimeNumberOperations.cpp -std=c++17 -o PrimeNumberOperations.out

SegmentTree: SegmentTree.cpp
	g++ SegmentTree.cpp -std=c++17 -o SegmentTree.out

Trie: Trie.cpp
	g++ Trie.cpp -std=c++17 -o Trie.out

UnionFind: UnionFind.cpp
	g++ UnionFind.cpp -std=c++17 -o UnionFind.out

Utils: Utils.cpp
	g++ Utils.cpp -std=c++17 -o Utils.out

test: 
	./BigNumber.out
	./Bitmask.out
	./Dijkstra.out
	./ExponentialModular.out
	./FenwickTree.out
	./GcdAndLcm.out
	./KmpStringMatching.out
	./PrimeNumberOperations.out
	./SegmentTree.out
	./Trie.out
	./UnionFind.out
	./Utils.out

clean:
	rm *.out