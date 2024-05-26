CXX=clang++
CXXFLAGS=-std=c++11
SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
#AUTHOR: Yoni Baruch | 211465786 | theyonib@gmail.com

run: demo
	./demo

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo test
