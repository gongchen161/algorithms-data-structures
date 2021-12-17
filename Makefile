all: BigNumber.o Bitmask.o FenwickTree.o SegmentTree.o

BigNumber.o: BigNumber.cpp
	g++ -c BigNumber.cpp -std=c++17

Bitmask.o: Bitmask.cpp
	g++ -c Bitmask.cpp -std=c++17

FenwickTree.o: FenwickTree.cpp
	g++ -c FenwickTree.cpp -std=c++17

SegmentTree.o: SegmentTree.cpp
	g++ -c SegmentTree.cpp -std=c++17

test:
	./BigNumber
	./Bitmask
	./FenwickTree
	./SegmentTree

clean:
	rm *.o