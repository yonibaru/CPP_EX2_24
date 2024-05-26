#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1][2, 0, 3][1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    g4.printGraph();
    CHECK(g4.printGraph() == "[1, 0, 2][1, 3, 1][1, 0, 2]");
}

TEST_CASE("Loading Invalid Graphs"){
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1}};
    CHECK_THROWS(g1.loadGraph(graph));
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {1, 0, 0, 1}};
    CHECK_THROWS(g5.loadGraph(graph2));
 
}

TEST_CASE("Invalid operations"){
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g2 + g6);
}

TEST_CASE("Comparison Operations"){
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1,1},
        {1,1}};
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1,1,1},
        {0,0,0},
        {0,1,1}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    CHECK(!(g1 == g2)); //Check they are not equal
    CHECK(g1 == g1);
    CHECK(g1 < g2);
    CHECK(g2 > g1);
    CHECK(!(g2 < g1));
    CHECK(g1 <= g2);
    CHECK(g1 <= g1);

    //Same size, more edges
    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    g3.loadGraph(graph3);
    CHECK(g3 > g2);
    CHECK(!(g3 < g2));

    //Subgraph
    vector<vector<int>> graph4 = {
        {1,1},
        {1,0}};
    ariel::Graph g4;
    vector<vector<int>> graph5 = {
        {1,1,0},
        {1,0,0},
        {0,0,1}};
    ariel::Graph g5;
    g4.loadGraph(graph4);
    g5.loadGraph(graph5);
    CHECK(g5 > g4);
    CHECK(g4 < g5);
}
TEST_CASE("Subtraction Operations"){
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {8, 7, 6},
        {5, 4, 3},
        {2, 1, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 - g2;
    CHECK(g3.printGraph() == "[-8, -6, -4][-2, 0, 2][4, 6, 8]");
}
TEST_CASE("Unary minus Operator"){
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    g1.loadGraph(graph1);
    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[-1, -2, -3][-4, -5, -6][-7, -8, -9]");
}
TEST_CASE("Unary plus Operator"){
      ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    g1.loadGraph(graph1);
    ariel::Graph g2 = +g1;
    CHECK(g2.printGraph() == "[1, 2, 3][4, 5, 6][7, 8, 9]");
}
