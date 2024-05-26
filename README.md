        
The following is a documentation for EX2 of SE2.
AUTHOR: Yoni Baruch | 211465786 | theyonib@gmail.com
Various helpful sources I have used includes: ChatGPT, Wikipedia, GeekForGeeks, StackOverflow.
# Disclaimer
I couldn't get the given makefile to work with my code, therefore I had to create my own. You should be able to run ./test normally.
Regarding tests, I added 15 tests to the given tests.

I've taken the liberty to remove all irrelevant functions from the last exercise.
# Graph:
Represented by a class.
## Fields
* adjMatrix: The adjacency matrix inserted by calling loadGraph().
* vxs: # of vertices in the given graph.
* edges: # of edges in the given graph.
## Methods:
* Graph(): default constructor.
* loadGraph(): Loads the graph from a given adjacency matrix.
* printGraph(): Prints the edges and vxs in a graph in the correct format.
* size(): Returns # of vxs in the given graph.
* getEdges(): Returns the # of edges in the given graph.
* getOrderOfMagnitude(): Returns the order of magntitude of the Matrix.
* isSubGraph(graph): Given a graph, this function returns true if it is a subgraph of the current graph.
## Operators
* operator<<(): Overloads the default << operator to print out a graph correctly. It's unused in the tests.
* operator+(): Overloads the default + operator to allow addition of 2 graphs by recursively additioning their adj. matrices.
* operator-(): Overloads the default - operator to allow addition of 2 graphs by recursively subtracting their adj. matrices.
* operator+=(): Same as operator+() but does the calculation in place.
* operator-=(): Same as operator-() but does the calculations in place.
* operator-() (unary): In-place, causes all edge weights to be multiplied by -1.
* operator+() (unary): Returns the same graph.
* operator*(): Overloads the default * operator to allow addition of 2 graphs by recursively multiplying their adj. matrices.
* operator*(int scalar): Multiplies all edges of the graph by some scalar.
# Comparison Operators
* operator==(): Returns true if the two graph's adj. matrices are of the same order of magnitude and have matching weight edges.
* operator>(): Returns true if: right graph is a subgraph of the left graph, or have the same weight edges, or are of the same order of magnitude.
* operator<(): Exactly as the > operator but in reverse order for simplicity.
* operator>=(): Combination of the < operator and the == operator.
* operator<=(): Combination of the > operator and the == operator.
# Inc./Dec. Operators
* operator++(): Increments all edges of the adj. matrix by 1.
* operator--(): Decrements all edges of the adj. matrix by 1.


## How does Algorithms.cpp changes now that we've added operators?
It makes tidious calculations commonly seen in algorithms such as Floyd-Warshall algorithm much easier in code by simply allowing us to multiply 2 matrices.

