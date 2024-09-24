#ifndef IGRAPH_H_INCLUDED
#define IGRAPH_H_INCLUDED

#include <iostream>
#include <stdexcept>

template <typename T,
        template <typename> class L1,
        template <typename> class L2>
class IGraph {
public:
    IGraph(size_t num_vertices) :
        V(num_vertices),
        graph(num_vertices) {}

    virtual ~IGraph() {}

    // Add/Remove a vertex
    virtual void addVertex() = 0;
    virtual void removeVertex(int i) = 0;

    // Add/Remove an edge between vertices i and j
    virtual void addEdge(int i, int j) = 0;
    virtual void removeEdge(int i, int j) = 0;

    // Check if there is an edge between two vertices
    virtual bool hasEdge(int i, int j) const = 0;

    // Get the number of edges in the graph
    virtual int edgeCount() const = 0;

    // Get a list of all integers j such i->j is an edge
    virtual L1<int> outEdges(int i) const = 0;

    // Get a list of all integers j such j->i is an edge
    virtual L1<int> inEdges(int i) const = 0;

    // Print the graph representation
    virtual void print() const = 0;

    // Get the number of vertices in the graph
    int vertexCount() const {
        return V;
    }

    // Access the graph data structure
    const L1<L2<T>>& getGraph() const {
        return graph;
    }

    // Get the degree of a vertex
    virtual int getDegree(int v) const {
        return getInDegree(v) + getOutDegree(v);
    }
    virtual int getOutDegree(int v) const = 0;
    virtual int getInDegree(int v) const = 0;

protected:
    // Number of vertices
    size_t V;
    L1<L2<T>*> graph;
};

#endif // IGRAPH_H_INCLUDED
