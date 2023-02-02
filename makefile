test: clean compile runtest

clean:
	rm -f test
  
compile: main.cpp LinkedList.cpp LinkedListItem.cpp
	g++ -std=c++14 -I . -o test main.cpp LinkedList.cpp LinkedListItem.cpp
  
runtest:
	./test
