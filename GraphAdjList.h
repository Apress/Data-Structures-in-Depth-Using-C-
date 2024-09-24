#ifndef GRAPHADJLIST_H_INCLUDED
#define GRAPHADJLIST_H_INCLUDED

#include "IGraph.h"
#include "DynamicArray.h"
#include "StackArray.h"
#include "QueueArray.h"
#include "DLList.h"
#include "Vertex.h"

template <typename T>
class GraphAdjList :
    public IGraph<Vertex<T>, DynamicArray, DLList> {

public:
    GraphAdjList(int nVertices)
        : IGraph<Vertex<T>, DynamicArray, DLList>(nVertices) {
        for (int i = 0; i < nVertices; ++i) {
            graph.pushBack(new DLList<Vertex<T>>());
        }
    }

    ~GraphAdjList() {
        for (size_t i = 0; i < graph.getSize(); ++i) {
            if (graph[i] != nullptr) {
                graph[i]->clear();  // Clear the list
                delete graph[i];    // Delete the list
                graph[i] = nullptr; // Avoid dangling pointers
            }
        }
    }

    // IGraph Interface Methods
    void addVertex();
    void removeVertex(int i);
    void addEdge(int i, int j);
    void addEdge(int i, int j, T w);
    void removeEdge(int i, int j);
    bool hasEdge(int i, int j) const;
    void print() const;
    int edgeCount() const;
    DynamicArray<int> outEdges(int i) const;
    DynamicArray<int> inEdges(int i) const;
    int getOutDegree(int v) const;
    int getInDegree(int v) const;

    // DFS and BFS Traversals
    void BFS(int s) const;
    void DFS(int v) const;
    void DFS() const;
    bool isConnected() const;
    bool pathExists(int src, int dest) const;

protected:
    // Inherited members to use directly
    using IGraph<Vertex<T>, DynamicArray, DLList>::V;
    using IGraph<Vertex<T>, DynamicArray, DLList>::graph;

private:
    void DFSUtil(int v, DynamicArray<bool>& visited) const;
    bool DFS(int src, int dest, DynamicArray<bool>& visited) const;
};


template <typename T>
void GraphAdjList<T>::addVertex() {
    // Add new vertex
    graph.pushBack(new DLList<Vertex<T>>());
    ++V;
}

template <typename T>
void GraphAdjList<T>::removeVertex(int i) {
    if (i < 0 || (size_t)i >= V) return;
    // (1) Remove the list for the vertex
    graph.removeAt(i);
    V--;
    // (2) Search through all vertices to
    //     remove the removed vertex
    for (size_t j = 0; j < V; ++j) {
        for (size_t k = 0; k < graph[j]->getSize(); ++k) {
            auto& glist = *graph[j];
            // Find the index of the vertex and remove it
            if (glist[k].index == i) {
                graph[j]->removeAt(k);
                --k; // Ensure we don't skip elements
            } else if (glist[k].index > i) {
                // Adjust indices after the removed one
                glist[k].index--;
            }
        }
    }
}

// Add a unweighted edge from vertex i to vertex j
template <typename T>
void GraphAdjList<T>::addEdge(int i, int j) {
    addEdge(i,j,1);
}

// Add a weighted edge from vertex i to vertex j
template <typename T>
void GraphAdjList<T>::addEdge(int i, int j, T w) {
    if (i >= 0 && (size_t)i < V && j >= 0 && (size_t)j < V) {
       graph[i]->pushBack(Vertex<T>(w, j));
    }
}

// Remove the edge between vertices i and j
template <typename T>
void GraphAdjList<T>::removeEdge(int i, int j) {
    if (i >= 0 && (size_t)i < V) {
        for (size_t k = 0; k < graph[i]->getSize(); ++k) {
            if ((*graph[i])[k].index == j) {
                graph[i]->removeAt(k);
                return;
            }
        }
    }
}

// Check if there is an edge between vertices i and j
template <typename T>
bool GraphAdjList<T>::hasEdge(int i, int j) const {
    if (i < 0 || (size_t)i >= V || j < 0 || (size_t)j >= V) {
        return false; // Invalid indices
    }
    for (size_t k = 0; k < graph[i]->getSize(); ++k) {
        if ((*graph[i])[k].index == j) {
            return true;
        }
    }
    return false;
}

// Print the adjacency list representation of the graph
template <typename T>
void GraphAdjList<T>::print() const {
    for (size_t i = 0; i < V; ++i) {
        std::cout << "Vertex " << i << ": ";
        for (size_t j = 0; j < graph[i]->getSize(); ++j) {
            std::cout << (*graph[i])[j].index << " ";
        }
        std::cout << std::endl;
    }
}

// Count the number of edges in the graph
template <typename T>
int GraphAdjList<T>::edgeCount() const {
    int count = 0;
    for (size_t i = 0; i < V; ++i) {
        count += graph[i]->getSize();
    }
    return count;
}

// Get the outgoing edges from a vertex
template <typename T>
DynamicArray<int> GraphAdjList<T>::outEdges(int i) const {
    DynamicArray<int> edges;
    for (size_t j = 0; j < graph[i]->getSize(); ++j) {
        edges.pushBack((*graph[i])[j].index);
    }
    return edges;
}

// Get the incoming edges to a vertex
template <typename T>
DynamicArray<int> GraphAdjList<T>::inEdges(int i) const {
    DynamicArray<int> edges;
    for (size_t j = 0; j < V; ++j) {
        for (size_t k = 0; k < graph[j]->getSize(); ++k) {
            // Check if vertex i is in the adjacency list of vertex j
            if ((*graph[j])[k].index == i) {
                edges.pushBack(j);
            }
        }
    }
    return edges;
}

// Get the out-degree of a vertex
template <typename T>
int GraphAdjList<T>::getOutDegree(int v) const {
    if (v >= 0 && (size_t)v < V) {
        return graph[v]->getSize();
    }
    return 0;
}

// Get the in-degree of a vertex
template <typename T>
int GraphAdjList<T>::getInDegree(int v) const {
    int inDegree = 0;
    for (size_t i = 0; i < V; ++i) {
        for (size_t j = 0; j < graph[i]->getSize(); ++j) {
            if ((*graph[i])[j].index == v) {
                inDegree++;
            }
        }
    }
    return inDegree;
}

// Perform Depth-First Search (DFS)
template <typename T>
void GraphAdjList<T>::DFSUtil(int v, DynamicArray<bool>& visited) const {
    StackArray<int> stack;
    stack.push(v);

    while (!stack.isEmpty()) {
        int current = stack.pop();

        if (!visited[current]) {
            std::cout << current << " ";
            visited[current] = true;
        }

        const auto& adjList = *graph[current];
        for (size_t i = 0; i < adjList.getSize(); ++i) {
            int neighbor = adjList[i].index;
            if (!visited[neighbor]) {
                stack.push(neighbor);
            }
        }
    }
}

// Perform DFS starting from a given vertex
template <typename T>
void GraphAdjList<T>::DFS(int v) const {
    DynamicArray<bool> visited(V, false);
    DFSUtil(v, visited);
}

// Perform DFS for the entire graph to
// handle disconnected components
template <typename T>
void GraphAdjList<T>::DFS() const {
    DynamicArray<bool> visited(V, false);
    for (size_t v = 0; v < V; ++v) {
        if (!visited[v]) {
            DFSUtil(v, visited);
        }
    }
}

// Perform Breadth-First Search (BFS)
template <typename T>
void GraphAdjList<T>::BFS(int s) const {
    DynamicArray<bool> visited(V, false);
    QueueArray<int> queue;
    visited[s] = true;
    queue.enqueue(s);

    while (!queue.isEmpty()) {
        int current = queue.dequeue();

        std::cout << current << " ";

        const auto& adjList = *graph[current];
        for (size_t i = 0; i < adjList.getSize(); ++i) {
            int neighbor = adjList[i].index;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.enqueue(neighbor);
            }
        }
    }
}

// Check if the graph is connected
template <typename T>
bool GraphAdjList<T>::isConnected() const {
    DynamicArray<bool> visited(V, false);
    DFSUtil(0, visited);  // Start DFS from vertex 0

    for (size_t i = 0; i < V; ++i) {
        // If any vertex isn't visited, the graph isn't connected
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}


// Check if there is a path between two vertices
template <typename T>
bool GraphAdjList<T>::DFS(int v, int dest, DynamicArray<bool>& visited) const {
    visited[v] = true;
    if (v == dest) return true;

    for (size_t i = 0; i < graph[v]->getSize(); ++i) {
        int neighbor = (*graph[v])[i].index;
        if (!visited[neighbor] &&
            DFS(neighbor, dest, visited)) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool GraphAdjList<T>::pathExists(int src, int dest) const {
    DynamicArray<bool> visited(V, false);
    return DFS(src, dest, visited);
}


/** NOT IN BOOK **/
template <typename T>
std::ostream& operator<<(std::ostream& os, const DLList<Vertex<T>>& dllist) {
    for (size_t i = 0; i < dllist.getSize(); ++i) {
        os << dllist[i].index << " ";
    }
    return os;
}

template <typename T>
bool operator==(const DLList<T>& lhs, const DLList<T>& rhs) {
    if (lhs.getSize() != rhs.getSize()) {
        return false;
    }

    for (size_t i = 0; i < lhs.getSize(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}


#endif // GRAPHADJLIST_H_INCLUDED
