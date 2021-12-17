all: BigNumber Bitmask FenwickTree SegmentTree

BigNumber: BigNumber.cpp
	g++ BigNumber.cpp -std=c++17 -o BigNumber.out

Bitmask: Bitmask.cpp
	g++ Bitmask.cpp -std=c++17 -o Bitmask.out

FenwickTree: FenwickTree.cpp
	g++ FenwickTree.cpp -std=c++17 -o FenwickTree.out

SegmentTree: SegmentTree.cpp
	g++ SegmentTree.cpp -std=c++17 -o SegmentTree.out

test: 
	./BigNumber.out
	./Bitmask.out
	./FenwickTree.out
	./SegmentTree.out

clean:
	rm *.out