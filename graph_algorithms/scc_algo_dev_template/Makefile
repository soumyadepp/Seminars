CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = main

SRCS = main.cpp directed_graph.cpp strongly_connected.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o