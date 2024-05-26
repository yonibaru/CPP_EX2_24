#include "Algorithms.hpp"
#include "Graph.hpp"
#include <climits>
#include <queue>
#include <list>

namespace ariel{
    //AUTHOR: Yoni Baruch | 211465786 | theyonib@gmail.com
    //We're going to create a static class which will hold all required algorithms.
    //Implementation of the Algorithms class (Definition is in header file):
    Algorithms::Algorithms(){}
    bool Algorithms::isConnected(const Graph& g) {
        // return true if graph is connected
        std::vector<bool> visited(g.size(),0); //Create a visited array, each index representing a vertex.
        g.dfs(0,visited); //Run DFS on the first vertex (doesn't matter), this is a recursive function.
        //Lastly, check whether we've successfully visited all possible vertices, if so return true.
        for(int i = 0; i < g.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
    std::string Algorithms::shortestPath(Graph& g, int start, int end) {

        g.floydWarshall();
        std::vector<std::vector<int>> prev = g.getPrevMatrix(); 
  
        if (prev[start][end] == INT_MAX) return "-1";  // No path exists

        //Backtrack through to store the path (the path is stored in reverese)
        std::vector<int> path;
        path.push_back(end);
        while(start != end){
            end = prev[start][end];
            path.push_back(end);
        }
        //Save the path in the desired format and finally return it
        std::string result;
        for(int i = path.size() - 1; i >= 0; --i){
            result += (i == path.size() - 1 ? "" : "->") + std::to_string(path[i]);
        }
        return result;
    }
    bool Algorithms::isContainsCycle(Graph& g) {
        int n = g.size();
        std::vector<bool> visited(n, 0);
        for (int i = 0; i < n; ++i) {
            g.dfs(0,visited);
            if (!visited[i])
                return true;
        }
        return false;
    }
    std::string Algorithms::isBipartite(const Graph& g) {
        // Thanks to GeekForGeeks for the algorithm.
        int g_size = g.size();
        std::vector<std::vector<int>> graph = g.getGraph(); 
        std::vector<int> blue_vxs(g_size,0); 
        std::vector<int> red_vxs(g_size,0); 
        std::queue <int> q;
        int color[g_size];
        for (int i = 0; i < g_size; ++i){
            color[i] = -1;
        }
        //Blue vxs: 1, Red vxs: 0, unpainted: -1.

        //Color the first vx in blue, doesn't matter.
        color[0] = 1; 
        q.push(0);
        blue_vxs[0] = 1;

        while (!q.empty()){
            int u = q.front();
            q.pop();
            if (graph[u][u] == 1){
                return "0"; 
            } 
            for (int v = 0; v < g_size; ++v){
                if (graph[u][v] && color[v] == -1){
                    color[v] = 1 - color[u]; //Inverse color
                    if(color[v] == 1){
                        blue_vxs[v] = 1;
                        red_vxs[v] = 0;
                    }else if(color[v] == 0){
                        blue_vxs[v] = 0;
                        red_vxs[v] = 1;
                    }
                    q.push(v);
                }
                else if (graph[u][v] && color[v] == color[u]){
                    return "0";
                }
            }
        }
        bool comma = false;
        std::string result = "The graph is bipartite: A={";
        for (int i = 0;i < g_size;i++) {
            if(blue_vxs[i] == 1){
                result += (comma ? ", " : "") + std::to_string(i);
                comma = true;
            }
        }
        result+= "}, B={";
        comma = false;
        for (int j = 0;j < g_size;j++) {
            if(red_vxs[j] == 1){
                result += (comma ? ", " : "") + std::to_string(j);
                comma = true;
            }
        }
        result+= "}";
        return result;
    }
    bool Algorithms::negativeCycle(Graph& g) {
        g.floydWarshallNegCycle();
        std::vector<std::vector<int>> dist = g.getDistMatrix(); 
        for (int i = 0; i < g.size(); ++i) {
            if (dist[i][i] < 0) {
                return true; 
            }
        }
        return false;
    }
}