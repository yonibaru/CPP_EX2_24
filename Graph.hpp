#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>
namespace ariel{
    //AUTHOR: Yoni Baruch | 211465786 | theyonib@gmail.com
    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        int vxs;
        int edges;
    public:
        Graph(); 
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        int size() const;
        std::vector<std::vector<int>> getMatrix() const;
        int getEdges() const;
        //Print operator
        friend std::ostream& operator<<(std::ostream& os, const Graph& g);
        //Addition Operators
        friend Graph operator+(const Graph& g1, const Graph& g2);
        Graph& operator+=(const Graph& other);
        Graph operator+() const;
        // Subtraction Operators
        friend Graph operator-(const Graph& g1, const Graph& g2);
        Graph& operator-=(const Graph& other);
        Graph operator-() const;
    };
}
#endif 