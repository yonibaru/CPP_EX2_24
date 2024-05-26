#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>
namespace ariel{
    //AUTHOR: Yoni Baruch | 211465786 | theyonib@gmail.com
    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        std::vector<std::vector<int>> prevMatrix;
        std::vector<std::vector<int>> distMatrix;
        int vxs;
        int edges;
    public:
        Graph(); 
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        std::string printGraph() const;
        int size() const;
        std::vector<std::vector<int>> getMatrix() const;
        int getEdges() const;
        int getOrderOfMagnitude() const;
        bool isSubGraph(const Graph& g) const;
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
        //Comparison Operators
        bool operator==(const Graph& g) const;
        bool operator>=(const Graph& g) const;
        bool operator<=(const Graph& g) const;
        bool operator>(const Graph& g) const;
        bool operator<(const Graph& g) const;
        //Inc./Dec. Operators
        Graph operator++();
        Graph operator--();
        //Multiplication Operators
        friend Graph operator*(const Graph& g1,const Graph& g2);
        Graph operator*(int scalar);

        //Old functions from Ex1
        std::vector<std::vector<int>> getGraph() const;
        std::vector<std::vector<int>> getPrevMatrix() const;
        std::vector<std::vector<int>> getDistMatrix() const;
        void floydWarshall();
        void floydWarshallNegCycle();
        void dfs(int v,std::vector<bool>& visited) const;

    };
}
#endif 