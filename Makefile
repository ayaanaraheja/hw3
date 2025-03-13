CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.cpp -o $@ 

valgrind: llrec.h llrec.cpp llrec-test.cpp 
	$(VALGRIND) ./llrec-test llrec-test1.in

stack_test: stack_test.cpp stack.h heap.h
	$(CXX) $(CXXFLAGS) stack_test.cpp -o $@

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 