all: BigNumber Bitmask Dijkstra ExponentialModular FenwickTree GcdAndLcm SegmentTree

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

SegmentTree: SegmentTree.cpp
	g++ SegmentTree.cpp -std=c++17 -o SegmentTree.out

test: 
	./BigNumber.out
	./Bitmask.out
	./Dijkstra.out
	./ExponentialModular.out
	./FenwickTree.out
	./GcdAndLcm.out
	./SegmentTree.out

clean:
	rm *.out