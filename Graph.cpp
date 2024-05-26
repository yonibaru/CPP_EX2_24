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
            throw std::invalid_argument("Incompatible matrix size!");
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
    std::string Graph::printGraph() const{
        std::string result;
        for (int i = 0; i < this->adjMatrix.size();++i) {
            result += "[";
            for (int j = 0; j < this->adjMatrix[0].size(); ++j) {
                result += std::to_string(this->adjMatrix[i][j]);
                if (j < this->adjMatrix[0].size() - 1) {
                    result += ", ";
                }
            }
            result += "]";
        }
        return result;
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
    int Graph::getOrderOfMagnitude() const{
        return Graph::adjMatrix.size() * Graph::adjMatrix.size();
    }
    std::vector<std::vector<int>> Graph::getGraph() const {
        return Graph::adjMatrix;
    }
    bool Graph::isSubGraph(const Graph& g) const{
        if (this->getOrderOfMagnitude() < g.getOrderOfMagnitude()) return false;
        for(int i = 0; i < g.adjMatrix.size();++i){
            for(int j = 0; j < g.adjMatrix[0].size();++j){
                if(this->adjMatrix[i][j] != g.adjMatrix[i][j]) return false;
            }
        }
        return true;
    }
    //Print Operator (Unused in tests)
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
            throw std::invalid_argument("Incompatible matrix size!");
        }
        
        std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix1.size(), 0));

        for (int i = 0; i < matrix1.size(); ++i) {
            for (int j = 0; j < matrix1[i].size(); ++j) {
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
            throw std::invalid_argument("Incompatible matrix size!");
        }
        
        std::vector<std::vector<int>> result(g.size(), std::vector<int>(g.size(), 0));

        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
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
            throw std::invalid_argument("Incompatible matrix size!");
        }
        
        std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix1.size(), 0));

        for (int i = 0; i < matrix1.size(); ++i) {
            for (int j = 0; j < matrix1[i].size(); ++j) {
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
            throw std::invalid_argument("Incompatible matrix size!");
        }
        
        std::vector<std::vector<int>> result(g.size(), std::vector<int>(g.size(), 0));

        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                adjMatrix[i][j] -= g[i][j];
            }
        }

        return *this; //return the current object
    }
    Graph Graph::operator-() const {
        
        std::vector<std::vector<int>> result(adjMatrix.size(), std::vector<int>(adjMatrix.size(), 0));

        for(int i = 0; i < adjMatrix.size(); ++i) {
            for (int j = 0; j < adjMatrix[i].size(); ++j) {
                result[i][j] = -adjMatrix[i][j];
            }
        }

        Graph g = Graph();
        g.loadGraph(result);
        return g;
    }
    //Comparison Operators
    bool Graph::operator==(const Graph& g) const{
        if(this->getOrderOfMagnitude() != g.getOrderOfMagnitude()){
            return false; //If g1 is represented by 3x3 matrix and g2 is represented by a 4x4 matrix, they cannot be equal.
        }
        for(int i = 0; i < g.size(); ++i){
            for(int j = 0; j < g.size();++j){
                if(this->adjMatrix[i][j] != g.adjMatrix[i][j]) return false;
            }
        }
        return true;
    }
    bool Graph::operator>=(const Graph& g) const{
        if(*this == g) return true; 
        return *this > g;
    }
    bool Graph::operator<=(const Graph& g) const{
        if(*this == g) return true;
        return *this < g;
    }
    bool Graph::operator>(const Graph& g) const{
        if(this->isSubGraph(g)) return true; 
        if(this->getEdges() > g.getEdges()) return true;
        if(this->getOrderOfMagnitude() > g.getOrderOfMagnitude()) return true;
        return false;
    }
    bool Graph::operator<(const Graph& g) const{
        return g > *this;
    }
    //Increment/Decrement Operators
    Graph Graph::operator++(){
        for(int i = 0; i < this->adjMatrix.size(); ++i){
            for(int j = 0; j < this->adjMatrix[0].size();++j){
                this->adjMatrix[i][j]++;
            }
        }
        return *this;
    }
    Graph Graph::operator--(){
        for(int i = 0; i < this->adjMatrix.size(); ++i){
            for(int j = 0; j < this->adjMatrix[0].size();++j){
                this->adjMatrix[i][j]--;
            }
        }
        return *this;
    }
    //Multiplication Operators
    Graph operator*(const Graph& g1,const Graph& g2){
        const auto& mat1 = g1.getMatrix();
        const auto& mat2 = g2.getMatrix();
        if (mat1.size() != mat2.size() || mat1[0].size() != mat2[0].size()) {
            throw std::invalid_argument("Incompatible matrix size!");
        }
        std::vector<std::vector<int>> result(mat1.size(), std::vector<int>(mat2[0].size(), 0));

        // Multiply matrices
        for (int i = 0; i < mat1.size(); ++i) {
            for (int j = 0; j < mat2[0].size(); ++j) {
                for (int k = 0; k < mat1[0].size(); ++k) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        Graph g = Graph();
        g.loadGraph(result);
        return g;
    }
    Graph Graph::operator*(int scalar){
       for (int i = 0; i < this->adjMatrix.size(); ++i) {
            for (int j = 0; j < this->adjMatrix[0].size(); ++j) {
                this->adjMatrix[i][j] *= scalar;
            }
        }
        return *this;
    }

    //Old functions from Ex1

    std::vector<std::vector<int>> Graph::getPrevMatrix() const {
        return Graph::prevMatrix;
    }
    std::vector<std::vector<int>> Graph::getDistMatrix() const {
        return Graph::distMatrix;
    }
    void Graph::floydWarshall(){
        //Fills prevMatrix and distMatrix appropriately.
        int n = Graph::size();

        std::vector<std::vector<int>> dist(n, std::vector<int>(n)); //Initializing an array within an array -> a MATRIX
        std::vector<std::vector<int>> prev(n, std::vector<int>(n,INT_MAX)); //Initializing the prev array, which is required for backtracking

        //Copy matrix into dist.
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                //we need prepare our matrix accordingly.
                if(i == j) prev[i][j] = i;
                if(i != j && Graph::adjMatrix[i][j] == 0){
                    dist[i][j] = INT_MAX;
                } else{
                    dist[i][j] = Graph::adjMatrix[i][j];
                    prev[i][j] = i;
                }
            }
        }

        //The Floyd-Warshall Algorithm
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][k] != INT_MAX && dist[j][i] != INT_MAX && i != j && i != k && j != k) {
                        //We have to insure dist[k][j] and dist[i][k] are not individually equal to INT_MAX because summing them up could result in unexpected errors.
                        if (dist[j][k] > dist[j][i] + dist[i][k]) {
                            dist[j][k] = dist[j][i] + dist[i][k];
                            prev[j][k] = prev[i][k];
                        }
                    }
                }
            }
        }
        prevMatrix = prev;
    }
    void Graph::floydWarshallNegCycle(){
        int n = Graph::size();
        std::vector<std::vector<int>> dist = Graph::getGraph(); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (dist[i][k] != INT_MAX && dist[j][k] > dist[j][i] + dist[i][k] && dist[j][i] != INT_MAX) {
                        dist[j][k] = dist[j][i] + dist[i][k];
                    }
                }
            }
        }
        distMatrix = dist;
    }
    void Graph::dfs(int v,std::vector<bool>&visited) const{
        visited[v] = true;
        for(int i =0; i < Graph::size() ;i++){
            if(Graph::adjMatrix[v][i] != 0 && !visited[i]){
                dfs(i,visited);
            }
        }
    }
}