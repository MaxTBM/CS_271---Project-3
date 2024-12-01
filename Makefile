all: mytests

mytests: mytests.o HashMap.o HashMapTree.o Set.o RBTree.o RBTreeNode.o
	g++ -std=c++11 -o mytests HashMap.o HashMapTree.o Set.o RBTree.o mytests.o RBTreeNode.o
	./mytests

mytests.o: mytests.cpp
	g++ -std=c++11 -c mytests.cpp

HashMap.o: HashMap.cpp HashMap.hpp
	g++ -std=c++11 -c HashMap.cpp

HashMapTree.o: HashMapTree.cpp HashMapTree.hpp
	g++ -std=c++11 -c HashMapTree.cpp

Set.o: Set.cpp Set.hpp
	g++ -std=c++11 -c Set.cpp

RBTree.o: RBTree.cpp RBTree.hpp
	g++ -std=c++11 -c RBTree.cpp

RBTreeNode.o: RBTreeNode.cpp RBTreeNode.hpp
	g++ -std=c++11 -c RBTreeNode.cpp

clean:
	rm -f *.o mytests
