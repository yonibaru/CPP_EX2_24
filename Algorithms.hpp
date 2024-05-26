#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"
namespace ariel {
    //AUTHOR: Yoni Baruch | 211465786 | theyonib@gmail.com
    //The definition of the Algorithms class;
    class Algorithms{
    public:
        Algorithms();
        bool static isConnected(const Graph& g);
        std::string static shortestPath(Graph& g, int start, int end);
        bool static isContainsCycle(Graph& g);
        std::string static isBipartite(const Graph& g);
        bool static negativeCycle(Graph& g);
    };

}
#endif 