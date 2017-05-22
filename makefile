CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

mstapp: mstapp.o graph.o minpriority.o
	$(CXX) -o mstapp mstapp.o graph.o minpriority.o

mstapp.o: mstapp.cpp mstapp.h graph.h

graph.o: graph.cpp graph.h minpriority.h

minpriority.o: minpriority.cpp minpriority.h

clean:
	rm -f *.o mstapp
