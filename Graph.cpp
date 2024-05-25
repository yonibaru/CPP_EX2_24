#include "Graph.hpp"
#include <climits>
#include <list>
#include <iterator>
namespace ariel {
    //AUTHOR: Yoni Baruch | 211465786 | theyonib@gmail.com
    Graph::Graph(){}
    //undirected graph is just a directed graph with an edge from a to b and b to a.
    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        Graph::adjMatrix = matrix;
        if(matrix.size() != matrix[0].size()){
            exit(EXIT_FAILURE);
        }
        edges = 0;
        for(int i = 0; i < matrix.size();i++){
            for(int j = 0; j < matrix.size();j++){
                if(matrix[i][j] != 0){
                    edges++;
                }
            }
        }
        vxs = matrix.size();
    }
    void Graph::printGraph() const{
        std::cout<< "Graph with " << std::to_string(Graph::vxs) << " vertices and " << std::to_string(Graph::edges) << " edges." << std::endl;
    }
    int Graph::size() const{
        return Graph::adjMatrix[0].size();
    }
    std::vector<std::vector<int>> Graph::getMatrix() const {
        return Graph::adjMatrix;
    }
    int Graph::getEdges() const{
        return Graph::edges;
    }
    //Print Operator
    std::ostream& operator<<(std::ostream& os, const Graph& g) {
        const auto& matrix = g.adjMatrix;

        for(int i = 0; i < matrix.size();i++){
            os << "[";
            for(int j = 0; j < matrix.size();++j){
                os << matrix[i][j];
                if (j < matrix[j].size() - 1) os << ", ";
            }
            os << (i < matrix[i].size() - 1 ? "], " : "");
        }
        os << "]\n";
        return os;
    }
    //Addition Operators
    Graph operator+(const Graph& g1, const Graph& g2) {
        const auto& matrix1 = g1.getMatrix();
        const auto& matrix2 = g2.getMatrix();

        if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
            exit(EXIT_FAILURE);
        }
        
        std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix1.size(), 0));

        for (size_t i = 0; i < matrix1.size(); ++i) {
            for (size_t j = 0; j < matrix1[i].size(); ++j) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        Graph g = Graph();
        g.loadGraph(result);
        return g;
    }
    Graph& Graph::operator+=(const Graph& g_arg) {
        const auto& g = g_arg.getMatrix();
        if (g.size() != adjMatrix.size() || g[0].size() != adjMatrix[0].size()) {
            exit(EXIT_FAILURE);
        }
        
        std::vector<std::vector<int>> result(g.size(), std::vector<int>(g.size(), 0));

        for (size_t i = 0; i < g.size(); ++i) {
            for (size_t j = 0; j < g[i].size(); ++j) {
                adjMatrix[i][j] += g[i][j];
            }
        }

        return *this; //return the current object
    }
    Graph Graph::operator+() const {
        return *this;
    }

    //Subtraction Operators
    Graph operator-(const Graph& g1, const Graph& g2) {
        const auto& matrix1 = g1.getMatrix();
        const auto& matrix2 = g2.getMatrix();

        if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
            exit(EXIT_FAILURE);
        }
        
        std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix1.size(), 0));

        for (size_t i = 0; i < matrix1.size(); ++i) {
            for (size_t j = 0; j < matrix1[i].size(); ++j) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        Graph g = Graph();
        g.loadGraph(result);
        return g;
    }
    Graph& Graph::operator-=(const Graph& g_arg) {
        const auto& g = g_arg.getMatrix();
        if (g.size() != adjMatrix.size() || g[0].size() != adjMatrix[0].size()) {
            exit(EXIT_FAILURE);
        }
        
        std::vector<std::vector<int>> result(g.size(), std::vector<int>(g.size(), 0));

        for (size_t i = 0; i < g.size(); ++i) {
            for (size_t j = 0; j < g[i].size(); ++j) {
                adjMatrix[i][j] -= g[i][j];
            }
        }

        return *this; //return the current object
    }
    Graph Graph::operator-() const {
        
        std::vector<std::vector<int>> result(adjMatrix.size(), std::vector<int>(adjMatrix.size(), 0));

        for (size_t i = 0; i < adjMatrix.size(); ++i) {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j) {
                result[i][j] = -adjMatrix[i][j];
            }
        }

        Graph g = Graph();
        g.loadGraph(result);
        return g;
    }
}