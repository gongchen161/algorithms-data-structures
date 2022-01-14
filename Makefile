files = BigNumber Bitmask Dijkstra ExponentialModular FenwickTree FordFulkersonMaxFlow GcdAndLcm KmpStringMatching PrimeNumberOperations Trie SegmentTree UnionFind Utils
all: $(files)

BigNumber: BigNumber.cpp
	g++ BigNumber.cpp -std=c++17 -o BigNumber

Bitmask: Bitmask.cpp
	g++ Bitmask.cpp -std=c++17 -o Bitmask

Dijkstra: Dijkstra.cpp
	g++ Dijkstra.cpp -std=c++17 -o Dijkstra

ExponentialModular: ExponentialModular.cpp
	g++ ExponentialModular.cpp -std=c++17 -o ExponentialModular

FenwickTree: FenwickTree.cpp
	g++ FenwickTree.cpp -std=c++17 -o FenwickTree

FordFulkersonMaxFlow: FordFulkersonMaxFlow.cpp
	g++ FordFulkersonMaxFlow.cpp -std=c++17 -o FordFulkersonMaxFlow

GcdAndLcm: GcdAndLcm.cpp
	g++ GcdAndLcm.cpp -std=c++17 -o GcdAndLcm

KmpStringMatching: KmpStringMatching.cpp
	g++ KmpStringMatching.cpp -std=c++17 -o KmpStringMatching

PrimeNumberOperations: PrimeNumberOperations.cpp
	g++ PrimeNumberOperations.cpp -std=c++17 -o PrimeNumberOperations

SegmentTree: SegmentTree.cpp
	g++ SegmentTree.cpp -std=c++17 -o SegmentTree

Trie: Trie.cpp
	g++ Trie.cpp -std=c++17 -o Trie

UnionFind: UnionFind.cpp
	g++ UnionFind.cpp -std=c++17 -o UnionFind

Utils: Utils.cpp
	g++ Utils.cpp -std=c++17 -o Utils

test: 
	./BigNumber
	./Bitmask
	./Dijkstra
	./ExponentialModular
	./FenwickTree
	./FordFulkersonMaxFlow
	./GcdAndLcm
	./KmpStringMatching
	./PrimeNumberOperations
	./SegmentTree
	./Trie
	./UnionFind
	./Utils

.PHONY: clean
clean:
	rm -f *.o $(files)
