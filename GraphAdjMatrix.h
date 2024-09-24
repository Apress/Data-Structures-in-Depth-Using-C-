#ifndef GRAPHADJMATRIX_H_INCLUDED
#define GRAPHADJMATRIX_H_INCLUDED

#include "IGraph.h"
#include "DynamicArray.h"

template <typename T>
class GraphAdjMatrix :
    public IGraph<T, DynamicArray, DynamicArray> {
public:
    GraphAdjMatrix(int nVertices) :
        IGraph<T, DynamicArray, DynamicArray>(nVertices) {
           // Initialize graph with the given number of vertices
            for (int i = 0; i < nVertices; ++i) {
                graph.pushBack(new DynamicArray<T>(nVertices, 0));
            }
        }
    ~GraphAdjMatrix(){}

    // IGraph Interface Methods
    void addVertex();
    void removeVertex(int i);
    void addEdge(int i, int j);
    void addEdge(int i, int j, T w = 1);
    void removeEdge(int i, int j);
    bool hasEdge(int i, int j) const;
    void print() const;
    int edgeCount() const;
    DynamicArray<int> outEdges(int i) const;
    DynamicArray<int> inEdges(int i) const;
    int getOutDegree(int v) const;
    int getInDegree(int v) const;

protected:
    // Inherited members to use directly
    using IGraph<T, DynamicArray, DynamicArray>::V;
    using IGraph<T, DynamicArray, DynamicArray>::graph;
};

template <typename T>
void GraphAdjMatrix<T>::addVertex() {
    V++;
    // (1) Resize all existing edge lists to accommodate
    // the new vertex by adding 0 to represent no edge
    for (size_t i = 0; i < graph.getSize(); ++i) {
        graph[i]->pushBack(0);
    }
    // (2) Add the new vertex and initialize its row with 0s
    DynamicArray<T>* newRow = new DynamicArray<T>(V,0);
    graph.pushBack(newRow);
}

template <typename T>
void GraphAdjMatrix<T>::removeVertex(int i) {
    if (i < 0 || (size_t)i >= V) return;
    // (a) Remove the row of the vertex
    graph.removeAt(i);

    for (size_t j = 0; j < graph.getSize(); ++j) {
        // (b) Remove the column of the vertex
        graph[j]->removeAt(i);
    }
    V--;
}

template <typename T>
void GraphAdjMatrix<T>::addEdge(int i, int j) {
    (*graph[i])[j] = 1;
}

template <typename T>
void GraphAdjMatrix<T>::addEdge(int i, int j, T w) {
    (*graph[i])[j] = w;
}

template <typename T>
void GraphAdjMatrix<T>::removeEdge(int i, int j) {
    (*graph[i])[j] = 0;
}

template <typename T>
bool GraphAdjMatrix<T>::hasEdge(int i, int j) const {
    return (*graph[i])[j] != 0;
}

template <typename T>
void GraphAdjMatrix<T>::print() const {
    for (size_t i = 0; i < V; ++i) {
        for (size_t j = 0; j < V; ++j) {
            std::cout << (*graph[i])[j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
int GraphAdjMatrix<T>::edgeCount() const {
    int count = 0;
    for (size_t i = 0; i < V; ++i) {
        for (size_t j = 0; j < V; ++j) {
            if ((*graph[i])[j] != 0) {
                count++;
            }
        }
    }
    return count;
}

template <typename T>
DynamicArray<int> GraphAdjMatrix<T>::outEdges(int i) const {
    DynamicArray<int> edges;
    for (size_t j = 0; j < V; ++j) {
        if ((*graph[i])[j] != 0) {
            edges.pushBack(j);
        }
    }
    return edges;
}

template <typename T>
DynamicArray<int> GraphAdjMatrix<T>::inEdges(int i) const {
    DynamicArray<int> edges;
    for (size_t j = 0; j < V; ++j) {
        if ((*graph[i])[j] != 0) {
            edges.pushBack(j);
        }
    }
    return edges;
}

template <typename T>
int GraphAdjMatrix<T>::getOutDegree(int v) const {
    int outDegree = 0;
    for (size_t j = 0; j < V; ++j) {
        if ((*graph[v])[j] != 0) {
            outDegree++;
        }
    }
    return outDegree;
}

template <typename T>
int GraphAdjMatrix<T>::getInDegree(int v) const {
    int inDegree = 0;
    for (size_t i = 0; i < V; ++i) {
        if ((*graph[i])[v] != 0) {
            inDegree++;
        }
    }
    return inDegree;
}


#endif // GRAPHADJMATRIX_H_INCLUDED
