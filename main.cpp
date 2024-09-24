#include <iostream>

// Dynamic Array and Lists
#include "DynamicArray.h"
#include "SinglyLL.h"
#include "SinglyLLTailed.h"
#include "DLList.h"

// Stack and Queue Implementations
#include "StackArray.h"
#include "StackLL.h"
#include "QueueArray.h"
#include "QueueLL.h"
#include "DequeArray.h"
#include "DequeLL.h"

// Hash Tables
#include "ChainedHashTable.h"
#include "LinearHashTable.h"

// Trees
#include "BinaryTreeArray.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "BTreeNode.h"

// Heaps and Priority Queues
#include "BinaryHeap.h"
#include "PriorityQueue.h"

// Graphs
#include "GraphAdjMatrix.h"
#include "GraphAdjList.h"

// Maps and Advanced Data Structures
#include "Map.h"
#include "SEList.h"
#include "SkipList.h"

// Task Management
#include "TaskManager.h"
#include "TaskHandlerApp.h"

// Friend Management
#include "FriendManager.h"
#include "FriendsHandlerApp.h"

// Library System
#include "LibraryHandlerApp.h"

using namespace std;

void testDynamicArray() {
    cout << "...Testing DynamicArray..." << endl;

    // Initialization and Push Operations
    DynamicArray<int> x;
    x.pushFront(1);
    x.pushFront(2);
    x.pushFront(3);
    x.pushFront(4);
    x.pushFront(5);
    x.pushFront(6);
    x.pushFront(7);
    cout << "Array after pushFront \t";
    x.print();

    x.pushBack(80);
    x.pushBack(81);
    x.pushBack(82);
    x.pushBack(83);
    x.pushBack(84);
    x.pushBack(85);
    x.pushBack(86);
    x.pushBack(87);
    x.pushBack(88);
    cout << "Array after pushBack \t";
    x.print();

    // Insertion Operations
    x.pushFront(30);
    x.insertAt(5, 40);
    cout << "Array after insertions: \t";
    x.print();

    // Pop Operations
    x.popBack();
    cout << "Array after popBack: \t\t";
    x.print();

    x.popFront();
    cout << "Array after popFront: \t\t";
    x.print();

    // Access and Modify Elements
    cout << "Element at index 1: " << x.get(1) << endl;
    x.set(1, 50);
    cout << "Array after set 1 to 50: \t";
    x.print();

    // Index and Top Element Operations
    cout << "Index of element 50: " << x.indexOf(50) << endl;
    cout << "Top front element: " << x.topFront() << endl;
    cout << "Top back element: " << x.topBack() << endl;

    // Clear the Array
    x.clear();
    cout << "Array after clear: ";
    x.print();
    cout << "--------------------------------------------------\n";
}

void testSinglyLL() {
    cout << "...Testing SinglyLL..." << endl;

    // Initialization and Insert Operations
    SinglyLL<int> y;
    y.pushFront(10);
    y.pushBack(20);
    y.pushFront(30);
    y.insertAt(1, 40);
    cout << "List after insertions: ";
    y.print();

    // Pop Operations
    y.popBack();
    cout << "List after popBack: ";
    y.print();

    y.popFront();
    cout << "List after popFront: ";
    y.print();

    // Access and Modify Elements
    cout << "Element at index 1: " << y.get(1) << endl;
    y.set(1, 50);
    cout << "List after setting index 1 to 50: ";
    y.print();

    // Index and Top Element Operations
    cout << "Index of element 50: " << y.indexOf(50) << endl;
    cout << "Top front element: " << y.topFront() << endl;
    cout << "Top back element: " << y.topBack() << endl;

    // Clear the List
    y.clear();
    cout << "List after clear: ";
    y.print();
    cout << "--------------------------------------------------\n";
}

void testSinglyLLTailed() {
    cout << "...Testing SinglyLLTailed..." << endl;

    // Initialization and Insert Operations
    SinglyLLTailed<int> z;
    z.pushFront(10);
    z.pushBack(20);
    z.pushFront(30);
    z.insertAt(1, 40);
    cout << "List after insertions: ";
    z.print();

    // Pop Operations
    z.popBack();
    cout << "List after popBack: ";
    z.print();

    z.popFront();
    cout << "List after popFront: ";
    z.print();

    // Access and Modify Elements
    cout << "Element at index 1: " << z.get(1) << endl;
    z.set(1, 50);
    cout << "List after setting index 1 to 50: ";
    z.print();

    // Index and Top Element Operations
    cout << "Index of element 50: " << z.indexOf(50) << endl;
    cout << "Top front element: " << z.topFront() << endl;
    cout << "Top back element: " << z.topBack() << endl;

    // Clear the List
    z.clear();
    cout << "List after clear: ";
    z.print();
    cout << "--------------------------------------------------\n";
}

void testDLList() {
    cout << "...Testing DLList..." << endl;

    // Initialization and Insert Operations
    DLList<int> list;
    list.pushFront(10);
    list.pushBack(20);
    list.pushFront(30);
    list.pushBack(40);
    cout << "List after pushFront and pushBack: ";
    list.print();

    // Insertion at Specific Index
    list.insertAt(2, 25);
    cout << "List after insertAt index 2 (25): ";
    list.print();

    // Pop Operations
    int front = list.popFront();
    cout << "Popped front element: " << front << endl;
    cout << "List after popFront: ";
    list.print();

    int back = list.popBack();
    cout << "Popped back element: " << back << endl;
    cout << "List after popBack: ";
    list.print();

    // Access and Modify Elements
    cout << "Element at index 1: " << list.get(1) << endl;
    list.set(1, 50);
    cout << "List after setting index 1 to 50: ";
    list.print();

    // Index Operations
    cout << "Index of element 50: " << list.indexOf(50) << endl;
    cout << "Index of element 20: " << list.indexOf(20) << endl;

    // Top Element Operations
    cout << "Top front element: " << list.topFront() << endl;
    cout << "Top back element: " << list.topBack() << endl;

    // Clear the List
    list.clear();
    cout << "List after clear: ";
    list.print();
    cout << "--------------------------------------------------\n";
}

void testStackArray() {
    cout << "...Testing StackArray..." << endl;

    // Initialization and Push Operations
    StackArray<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);
    stack.push(11);
    stack.push(12);
    stack.push(13);
    cout << "Stack after pushes: ";
    stack.print();

    // Pop Operation
    int top = stack.pop();
    cout << "Popped element: " << top << endl;
    cout << "Stack after pop: ";
    stack.print();

    // Insert at Specific Position
    stack.insertAt(5, 40);
    cout << "Array after insertions 40 at 5: \t";
    stack.print();

    // Additional Pop Operation
    top = stack.pop();
    cout << "Popped element: " << top << endl;
    cout << "Stack after pop: ";
    stack.print();
    cout << "--------------------------------------------------\n";
}

void testStackLL() {
    cout << "...Testing StackLL..." << endl;

    // Initialization and Push Operations
    StackLL<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack after pushes: ";
    stack.print();

    // Pop Operations
    int top = stack.pop();
    cout << "Popped element: " << top << endl;
    cout << "Stack after pop: ";
    stack.print();

    top = stack.pop();
    cout << "Popped element: " << top << endl;
    cout << "Stack after pop: ";
    stack.print();
    cout << "--------------------------------------------------\n";
}

void testQueueArray() {
    cout << "...Testing QueueArray..." << endl;

    // Initialization and Enqueue Operations
    QueueArray<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    queue.enqueue(11);
    queue.enqueue(12);
    cout << "Queue Capacity: " << queue.getCapacity() << endl;
    cout << "Queue after enqueues: ";
    queue.print();

    // Top Elements
    cout << "Queue TopFront: " << queue.topFront() << endl;
    cout << "Queue TopBack : " << queue.topBack() << endl;

    // Dequeue Operations
    int front = queue.dequeue();
    cout << "Dequeued element: " << front << endl;
    cout << "Queue after dequeue: ";
    queue.print();

    front = queue.dequeue();
    cout << "Dequeued element: " << front << endl;
    cout << "Queue after dequeue: ";
    queue.print();

    front = queue.dequeue();
    cout << "Dequeued element: " << front << endl;
    cout << "Queue after dequeue: ";
    queue.print();

    front = queue.dequeue();
    cout << "Dequeued element: " << front << endl;
    cout << "Queue after dequeue: ";
    queue.print();

    // Insert at Specific Index
    queue.insertAt(1, 25);
    cout << "Queue after insertAt index 1 (25): ";
    queue.print();

    queue.insertAt(2, 24);
    cout << "Queue after insertAt index 2 (24): ";
    queue.print();

    queue.insertAt(3, 22);
    cout << "Queue after insertAt index 3 (22): ";
    queue.print();

    queue.insertAt(0, 50);
    cout << "Queue after insertAt index 0 (50): ";
    queue.print();

    // Remove at Specific Index
    queue.removeAt(1);
    cout << "Queue after removeAt index 1: ";
    queue.print();

    queue.removeAt(7);
    cout << "Queue after removeAt index 7: ";
    queue.print();

    // Dequeue All Elements
    while (!queue.isEmpty()) {
        cout << "Queue Capacity: " << queue.getCapacity() << endl;
        cout << "Dequeued element: " << queue.dequeue() << endl;
    }
    cout << "Queue after dequeue all: ";
    queue.print();

    cout << "Finished testing QueueArray." << endl;
    cout << "--------------------------------------------------\n";
}

void testQueueLL() {
    cout << "...Testing QueueLL..." << endl;

    // Initialization and Enqueue Operations
    QueueLL<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    cout << "Queue after enqueues: ";
    queue.print();

    // Dequeue Operation
    int front = queue.dequeue();
    cout << "Dequeued element: " << front << endl;
    cout << "Queue after dequeue: ";
    queue.print();

    // Insert at Specific Index
    queue.insertAt(1, 25);
    cout << "Queue after insertAt index 1 (25): ";
    queue.print();

    // Remove at Specific Index
    queue.removeAt(1);
    cout << "Queue after removeAt index 1: ";
    queue.print();

    // Dequeue All Elements
    while (!queue.isEmpty()) {
        cout << "Dequeued element: " << queue.dequeue() << endl;
    }
    cout << "Queue after dequeue all: ";
    queue.print();

    cout << "Finished testing QueueLL." << endl;
    cout << "--------------------------------------------------\n";
}

void testDequeArray() {
    cout << "...Testing DequeArray..." << endl;

    // Initialization and Enqueue Operations
    DequeArray<int> deque;
    deque.enqueueRear(1);
    deque.enqueueRear(2);
    deque.enqueueRear(3);
    deque.enqueueRear(4);
    deque.enqueueRear(5);
    deque.enqueueRear(6);
    deque.enqueueFront(11);
    deque.enqueueFront(12);
    deque.enqueueFront(13);
    deque.enqueueFront(14);
    deque.enqueueFront(15);
    deque.enqueueFront(16);
    cout << "Deque after enqueueRear/enqueueFront: ";
    deque.print();

    // Dequeue Operations
    int front = deque.dequeueFront();
    cout << "Dequeued front element: " << front << endl;
    cout << "Deque after dequeueFront: ";
    deque.print();

    // Enqueue Front Operation
    deque.enqueueFront(0);
    cout << "Deque after enqueueFront (0): ";
    deque.print();

    // Dequeue Rear Operation
    int rear = deque.dequeueRear();
    cout << "Dequeued rear element: " << rear << endl;
    cout << "Deque after dequeueRear: ";
    deque.print();

    // Dequeue All Elements
    while (!deque.isEmpty()) {
        cout << "Dequeued front element: " << deque.dequeueFront() << endl;
    }
    cout << "Deque after dequeue all: ";
    deque.print();

    cout << "Finished testing DequeArray." << endl;
    cout << "--------------------------------------------------\n";
}

void testDequeLL() {
    cout << "...Testing DequeLL..." << endl;

    // Initialization and Enqueue Operations
    DequeLL<int> deque;
    deque.enqueueRear(1);
    deque.enqueueRear(2);
    deque.enqueueRear(3);
    deque.enqueueRear(4);
    deque.enqueueRear(5);
    deque.enqueueRear(6);
    cout << "Deque after enqueueRear: ";
    deque.print();

    // Dequeue Front Operation
    int front = deque.dequeueFront();
    cout << "Dequeued front element: " << front << endl;
    cout << "Deque after dequeueFront: ";
    deque.print();

    // Enqueue Front Operation
    deque.enqueueFront(0);
    cout << "Deque after enqueueFront (0): ";
    deque.print();

    // Dequeue Rear Operation
    int rear = deque.dequeueRear();
    cout << "Dequeued rear element: " << rear << endl;
    cout << "Deque after dequeueRear: ";
    deque.print();

    // Dequeue All Elements
    while (!deque.isEmpty()) {
        cout << "Dequeued front element: " << deque.dequeueFront() << endl;
    }
    cout << "Deque after dequeue all: ";
    deque.print();

    cout << "Finished testing DequeLL." << endl;
    cout << "--------------------------------------------------\n";
}

void testChainedHashTable() {
    cout << "...Testing ChainedHashTable..." << endl;

    // Initialization and Add Operations
    ChainedHashTable<int> hashTable(10);
    hashTable.add(5);
    hashTable.add(10);
    hashTable.add(15);
    cout << "-----------------------\n";
    hashTable.print();

    // Retrieve and Print All Elements
    DynamicArray<int> allItems = hashTable.getAll();
    cout << "All items in the hash table:\n";
    for (size_t i = 0; i < allItems.getSize(); ++i) {
        cout << allItems[i] << " ";
    }
    cout << endl;

    // Contains Operations
    cout << "Contains 5: " << hashTable.contains(5) << endl;  // Expected: 1
    cout << "Contains 20: " << hashTable.contains(20) << endl;  // Expected: 0

    // Remove Operations
    hashTable.remove(5);
    cout << "-----------------------\n";
    hashTable.print();  // Expected: 5 should be removed from its bucket
    cout << "Contains 5: " << hashTable.contains(5) << endl;  // Expected: 0

    // Retrieve and Print All Elements After Removal
    allItems = hashTable.getAll();
    cout << "All items in the hash table:\n";
    for (size_t i = 0; i < allItems.getSize(); ++i) {
        cout << allItems[i] << " ";
    }
    cout << endl;

    // Clear Hash Table
    hashTable.clear();
    hashTable.print();  // Expected: All buckets should be empty

    cout << "Finished testing ChainedHashTable." << endl;
    cout << "--------------------------------------------------\n";
}

void testLinearHashTable() {
    cout << "...Testing LinearHashTable..." << endl;

    // Initialization and Add Operations
    LinearHashTable<int> hashTable(8);
    cout << "Adding elements to the hash table:" << endl;
    hashTable.add(5);
    hashTable.add(12);
    hashTable.add(15);
    hashTable.add(7);
    hashTable.print();

    // Contains Operations
    cout << "\nChecking if elements are present:" << endl;
    cout << "Contains 5: " << (hashTable.contains(5) ? "Yes" : "No") << endl;
    cout << "Contains 12: " << (hashTable.contains(12) ? "Yes" : "No") << endl;
    cout << "Contains 10: " << (hashTable.contains(10) ? "Yes" : "No") << endl;

    // Remove Operations
    cout << "\nRemoving elements from the hash table:" << endl;
    hashTable.remove(12);
    hashTable.print();
    cout << "Contains 12: " << (hashTable.contains(12) ? "Yes" : "No") << endl;

    // Add More Elements to Trigger Resize
    cout << "\nAdding more elements to trigger resize:" << endl;
    hashTable.add(23);
    hashTable.add(35);
    hashTable.add(47);
    hashTable.add(59);
    hashTable.print();
    cout << "--------------------------------------------------\n";
}

void testBinaryTreeArray() {
    cout << "...Testing BinaryTreeArray..." << endl;

    // Initialization and Insert Operations
    BinaryTreeArray<int> btArray(15);  // Create a binary tree array with capacity 15
    for (int i = 0; i < 11; ++i) {
        btArray.insertAt(i, i + 1);
    }

    // Access and Print Node Details
    for (int i = 0; i < 5; ++i) {
        cout << "Node " << i << ": " << btArray.get(i) << endl;
        cout << "  Left Child: " << btArray.getLeftChild(i) << endl;
        cout << "  Right Child: " << btArray.getRightChild(i) << endl;
        cout << "  Parent: " << btArray.getParent(i) << endl;
    }
    cout << "--------------------------------------------------\n";
}

void testBinarySearchTree() {
    cout << "...Testing BinarySearchTree..." << endl;

    // Initialization and Insert Operations
    BinarySearchTree<int> tree;
    cout << "Inserting nodes...\n";
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // Tree Size and Height
    cout << "Tree size: " << tree.getSize(tree.getRoot()) << endl;  // Expected: 7
    cout << "Tree height: " << tree.height() << endl;

    // Traversal Methods
    cout << "In-order traversal: ";
    tree.traverse();  // Expected: 3 5 7 10 12 15 18

    cout << "Pre-order traversal: ";
    tree.preOrderTraversal(tree.getRoot());
    cout << endl;  // Expected: 10 5 3 7 15 12 18

    cout << "Post-order traversal: ";
    tree.postOrderTraversal(tree.getRoot());
    cout << endl;  // Expected: 3 7 5 12 18 15 10

    cout << "Level-order traversal: ";
    tree.levelOrderTraversal(tree.getRoot());
    cout << endl;  // Expected: 10 5 15 3 7 12 18

    // Search Operation
    cout << "Searching for node with key 7: ";
    auto node = tree.find(7);
    if (node != nullptr) {
        cout << "Found node with key " << node->key << endl;  // Expected: Found node with key 7
    } else {
        cout << "Node not found" << endl;
    }

    // Remove Operation
    cout << "Removing node with key 5\n";
    tree.remove(5);
    cout << "In-order traversal after removal: ";
    tree.traverse();  // Expected: 3 7 10 12 15 18

    cout << "Tree size after removal: " << tree.getSize(tree.getRoot()) << endl;  // Expected: 6
    cout << "--------------------------------------------------\n";
}

void testAVLTree() {
    cout << "...Testing AVLTree..." << endl;

    // Initialization and Insert Operations
    AVLTree<int> avlTree;
    cout << "Inserting nodes...\n";
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);

    // Traversal
    cout << "In-order traversal: ";
    avlTree.print();
    cout << endl;

    // Search Operation
    cout << "Searching for 30: ";
    if (avlTree.find(30) != nullptr) {
        cout << "Found 30" << endl;
    } else {
        cout << "30 not found" << endl;
    }

    // Remove Operations
    cout << "Removing 40\n";
    avlTree.remove(40);
    cout << "In-order traversal after removal: ";
    avlTree.print();
    cout << endl;

    cout << "Removing 25\n";
    avlTree.remove(25);
    cout << "In-order traversal after removal: ";
    avlTree.print();
    cout << endl;
    cout << "--------------------------------------------------\n";
}

void testGraphAdjMatrix() {
    cout << "...Testing GraphAdjMatrix..." << endl;

    // Initialization and Add Edge Operations
    GraphAdjMatrix<int> g(5);
    cout << "Adding edges...\n";
    g.addEdge(0, 1, 4);
    g.addEdge(0, 3, 5);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 0, 2);
    g.addEdge(2, 2, 6);
    g.addEdge(3, 2, 3);

    // Print Matrix and Properties
    cout << "Graph adjacency matrix:\n";
    g.print();
    cout << "Number of vertices: " << g.vertexCount() << endl;
    cout << "Number of edges: " << g.edgeCount() << endl;

    // Edge Retrieval
    cout << "Outgoing edges from vertex 0: ";
    DynamicArray<int> outEdges = g.outEdges(0);
    for (size_t i = 0; i < outEdges.getSize(); ++i) {
        cout << outEdges[i] << " ";
    }
    cout << endl;

    cout << "Incoming edges to vertex 3: ";
    DynamicArray<int> inEdges = g.inEdges(3);
    for (size_t i = 0; i < inEdges.getSize(); ++i) {
        cout << inEdges[i] << " ";
    }
    cout << endl;

    // Edge Existence Check
    cout << "Checking if edges exist...\n";
    cout << "Has edge (0, 1): " << g.hasEdge(0, 1) << endl;
    cout << "Has edge (0, 2): " << g.hasEdge(0, 2) << endl;
    cout << "Has edge (2, 2): " << g.hasEdge(2, 2) << endl;

    // Degree Information
    cout << "Getting degrees...\n";
    cout << "Out degree of vertex 0: " << g.getOutDegree(0) << endl;
    cout << "In degree of vertex 3: " << g.getInDegree(3) << endl;

    // Remove Edge and Vertex
    cout << "Removing edge (2, 2)...\n";
    g.removeEdge(2, 2);
    cout << "Graph adjacency matrix after removing edge (2, 2):\n";
    g.print();

    cout << "Removing vertex 2...\n";
    g.removeVertex(2);
    cout << "Graph adjacency matrix after removing vertex 2:\n";
    g.print();

    // Add Vertex and Edge
    cout << "Adding vertex...\n";
    g.addVertex();
    cout << "Graph adjacency matrix after adding a vertex:\n";
    g.print();

    cout << "Adding edge to the new vertex...\n";
    g.addEdge(4, 0, 7);
    g.addEdge(0, 4, 8);
    cout << "Graph adjacency matrix after adding edges to the new vertex:\n";
    g.print();

    cout << "Removing vertex 0...\n";
    g.removeVertex(0);
    cout << "Graph adjacency matrix after removing vertex 0:\n";
    g.print();

    cout << "Final graph state:\n";
    g.print();
    cout << "--------------------------------------------------\n";
}

void testGraphAdjList() {
    cout << "...Testing GraphAdjList..." << endl;

    // Initialization and Print
    try {
        GraphAdjList<int> g(5);
        g.print();

        // Add Vertex
        g.addVertex();
        cout << "Graph state after adding vertex:\n";
        g.print();
    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    cout << "--------------------------------------------------\n";
}

void testGraphAdjList1() {
    cout << "...Testing GraphAdjList with specific edge operations..." << endl;

    // Initialization and Add Edge Operations
    GraphAdjList<int> g(5);
    cout << "Adding edges...\n";
    g.addEdge(0, 1, 4);
    g.addEdge(0, 3, 5);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 0, 2);
    g.addEdge(2, 2, 6);
    g.addEdge(3, 2, 3);

    // Print List and Properties
    cout << "Graph adjacency list:\n";
    g.print();
    cout << "Number of vertices: " << g.vertexCount() << endl;
    cout << "Number of edges: " << g.edgeCount() << endl;

    // Edge Retrieval
    cout << "Outgoing edges from vertex 0: ";
    DynamicArray<int> outEdges = g.outEdges(0);
    for (size_t i = 0; i < outEdges.getSize(); ++i) {
        cout << outEdges[i] << " ";
    }
    cout << endl;

    cout << "Incoming edges to vertex 3: ";
    DynamicArray<int> inEdges = g.inEdges(3);
    for (size_t i = 0; i < inEdges.getSize(); ++i) {
        cout << inEdges[i] << " ";
    }
    cout << endl;

    // Edge Existence Check
    cout << "Checking if edges exist...\n";
    cout << "Has edge (0, 1): " << g.hasEdge(0, 1) << endl;
    cout << "Has edge (0, 2): " << g.hasEdge(0, 2) << endl;
    cout << "Has edge (2, 2): " << g.hasEdge(2, 2) << endl;

    // Degree Information
    cout << "Getting degrees...\n";
    cout << "Out degree of vertex 0: " << g.getOutDegree(0) << endl;
    cout << "In degree of vertex 3: " << g.getInDegree(3) << endl;

    // Remove Edge and Vertex
    cout << "Removing edge (2, 2)...\n";
    g.removeEdge(2, 2);
    cout << "Graph adjacency list after removing edge (2, 2):\n";
    g.print();

    cout << "Removing vertex 2...\n";
    g.removeVertex(2);
    cout << "Graph adjacency list after removing vertex 2:\n";
    g.print();

    // Add Vertex and Edge
    cout << "Adding vertex...\n";
    g.addVertex();
    cout << "Graph adjacency list after adding a vertex:\n";
    g.print();

    cout << "Adding edge to the new vertex...\n";
    g.addEdge(4, 0, 7);
    g.addEdge(0, 4, 8);
    cout << "Graph adjacency list after adding edges to the new vertex:\n";
    g.print();

    cout << "Removing vertex 0...\n";
    g.removeVertex(0);
    cout << "Graph adjacency list after removing vertex 0:\n";
    g.print();

    cout << "Final graph state:\n";
    g.print();
    cout << "--------------------------------------------------\n";
}

void testGraphAdjList2() {
    cout << "...Testing GraphAdjList with traversal and path queries..." << endl;

    // Initialization and Add Edge Operations
    GraphAdjList<int> g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 2, 1);
    g.addEdge(3, 2, 1);

    // Print List and Properties
    cout << "Graph adjacency list:\n";
    g.print();
    cout << "Number of vertices: " << g.vertexCount() << endl;
    cout << "Number of edges: " << g.edgeCount() << endl;

    // Edge Retrieval
    cout << "Outgoing edges from vertex 0: ";
    DynamicArray<int> outEdges0 = g.outEdges(0);
    for (size_t i = 0; i < outEdges0.getSize(); ++i) {
        cout << outEdges0[i] << " ";
    }
    cout << endl;

    cout << "Incoming edges to vertex 3: ";
    DynamicArray<int> inEdges3 = g.inEdges(3);
    for (size_t i = 0; i < inEdges3.getSize(); ++i) {
        cout << inEdges3[i] << " ";
    }
    cout << endl;

    // Edge Existence Check
    cout << "Checking if edges exist...\n";
    cout << "Has edge (0, 1): " << g.hasEdge(0, 1) << endl;
    cout << "Has edge (0, 2): " << g.hasEdge(0, 2) << endl;
    cout << "Has edge (2, 2): " << g.hasEdge(2, 2) << endl;

    // Degree Information
    cout << "Getting degrees...\n";
    cout << "Out degree of vertex 0: " << g.getOutDegree(0) << endl;
    cout << "In degree of vertex 3: " << g.getInDegree(3) << endl;

    // Remove Edge
    cout << "Removing edge (2, 2)...\n";
    g.removeEdge(2, 2);
    cout << "Graph adjacency list after removing edge (2, 2):\n";
    g.print();

    // Traversal Methods
    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    cout << "DFS traversal of all vertices: ";
    g.DFS();
    cout << endl;

    cout << "BFS traversal starting from vertex 0: ";
    g.BFS(0);
    cout << endl;

    // Connectivity Check
    cout << "Is graph connected? " << (g.isConnected() ? "Yes" : "No") << endl;

    // Path Existence Queries
    cout << "Path exists between 0 and 2: " << (g.pathExists(0, 2) ? "Yes" : "No") << endl;
    cout << "Path exists between 0 and 4: " << (g.pathExists(0, 4) ? "Yes" : "No") << endl;
    cout << "--------------------------------------------------\n";
}

void testBinaryHeap() {
    cout << "...Testing BinaryHeap..." << endl;

    // Initialization and Add Operations
    BinaryHeap<int> heap(HeapType::MIN_HEAP);
    cout << "Adding elements to the heap..." << endl;
    heap.add(10);
    heap.add(20);
    heap.add(15);
    heap.add(30);
    heap.add(40);
    heap.add(5);
    cout << "Heap after additions:" << endl;
    heap.print();

    // Remove Operations
    cout << "Removing the root element..." << endl;
    heap.deleteRoot();
    heap.print();

    cout << "Removing element 15..." << endl;
    heap.remove(15);
    heap.print();

    cout << "Removing element 30..." << endl;
    heap.remove(30);
    heap.print();

    // Heapify and Sort
    cout << "Heapifying an arbitrary array..." << endl;
    DynamicArray<int> arr;
    arr.pushBack(10);
    arr.pushBack(5);
    arr.pushBack(20);
    arr.pushBack(30);
    arr.pushBack(15);
    arr.pushBack(25);
    arr.pushBack(40);

    heap.heapify(arr);
    heap.print();

    cout << "Performing heap sort..." << endl;
    heap.heapSort();
    heap.print();
    cout << "--------------------------------------------------\n";
}

void testPriorityQueue() {
    cout << "...Testing PriorityQueue..." << endl;

    // Initialization and Add Operations
    PriorityQueue<string> pq;
    pq.add("Task 1", 2);  // Lower priority
    pq.add("Task 2", 3);
    pq.add("Task 3", 1);  // Higher priority
    pq.add("Task 4", 5);  // Highest priority
    pq.add("Task 5", 4);
    cout << "Priority Queue after insertions:" << endl;
    pq.print();  // Expected order of removal: Task 4, Task 5, Task 2, Task 1, Task 3

    // Peek and Pop Operations
    cout << "Peek highest priority element: " << pq.peek() << endl;  // Should return "Task 4"
    cout << "Remove highest priority element: " << pq.pop() << endl;  // Should remove "Task 4"
    pq.print();  // Expected order after removal: Task 5, Task 2, Task 1, Task 3

    // Remove All Elements
    cout << "Remove all elements:" << endl;
    while (!pq.isEmpty()) {
        cout << pq.pop() << " ";
    }
    cout << endl;

    cout << "Priority Queue after clearing:" << endl;
    pq.print();  // Should show an empty queue
    cout << "--------------------------------------------------\n";
}

void testMap() {
    cout << "...Testing Map..." << endl;

    // Initialization and Add Operations
    Map<int, string> map(10);
    map.add(1, "One");
    map.add(2, "Two");
    map.add(3, "Three");
    cout << "Map contents:\n";
    map.print();

    // Lookup Operations
    try {
        cout << "Value for key 2: " << map.get(2) << "\n";
    } catch (const runtime_error& e) {
        cout << e.what() << "\n";
    }

    // Remove Operations
    map.remove(2);
    cout << "Map after removing key 2:\n";
    map.print();

    // Attempting to Access Removed Key
    try {
        cout << "Value for key 2: " << map.get(2) << "\n";
    } catch (const runtime_error& e) {
        cout << e.what() << "\n";
    }
    cout << "--------------------------------------------------\n";
}

void testSEList() {
    cout << "...Testing SEList..." << endl;

    // Initialization and Add Operations
    SEList<int> list(3);  // Each node can hold up to 3 elements
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    cout << "Initial list: ";
    list.print();  // Expect: 1 2 3
    cout << "Sublists after initial insertions: ";
    list.printSubLists();  // Expect: [1, 2, 3]

    // Insertion to Cause Split
    list.pushBack(4);
    list.pushBack(5);
    cout << "List after more insertions: ";
    list.print();  // Expect: 1 2 3 4 5
    cout << "Sublists after more insertions: ";
    list.printSubLists();  // Expect: [1, 2, 3] -> [4, 5]

    // Front Insert and Pops
    list.pushFront(0);
    cout << "List after inserting 0 at the front: ";
    list.print();  // Expect: 0 1 2 3 4 5
    list.popFront();
    cout << "List after popping front: ";
    list.print();  // Expect: 1 2 3 4 5
    list.popBack();
    cout << "List after popping back: ";
    list.print();  // Expect: 1 2 3 4

    // Insert and Access
    list.insertAt(2, 9);
    cout << "List after inserting 9 at index 2: ";
    list.print();  // Expect: 1 2 9 3 4
    cout << "Access element at index 0: " << list.get(0) << endl;
    cout << "Access element at index 2: " << list.get(2) << endl;
    cout << "Access element at index 4: " << list.get(4) << endl;

    // Set and Clear
    list.set(2, 8);
    cout << "List after setting index 2 to 8: ";
    list.print();  // Expect: 1 2 8 3 4
    while (!list.isEmpty()) list.popBack();
    cout << "List after clearing: ";
    list.print();  // Expect: empty
    cout << "--------------------------------------------------\n";
}

void testSkipList() {
    cout << "...Testing SkipList..." << endl;

    // Initialization and Add Operations
    SkipList<int> sl(4, 0.5);
    sl.add(3);
    sl.add(6);
    sl.add(7);
    sl.add(9);
    sl.add(12);
    sl.add(19);
    sl.add(17);
    sl.add(26);
    sl.add(21);
    sl.add(25);
    cout << "Skip List after insertion:\n";
    sl.print();

    // Contains and Remove Operations
    cout << "Contains 19: " << sl.contains(19) << endl;  // Should print 1 (true)
    cout << "Contains 15: " << sl.contains(15) << endl;  // Should print 0 (false)
    sl.remove(19);
    cout << "Skip List after removing 19:\n";
    sl.print();

    // Edge Case Removal
    sl.remove(3);
    cout << "Skip List after removing 3:\n";
    sl.print();

    // Clear the Skip List
    sl.clear();
    cout << "Skip List after clearing:\n";
    sl.print();
    cout << "--------------------------------------------------\n";
}

void testTaskManager() {
    cout << "...Testing TaskManager..." << endl;

    // Initialization and Adding Tasks
    TaskManager manager;
    manager.addTask(Task(1, "Complete homework", 5));
    manager.addTask(Task(2, "Buy groceries", 10));
    manager.addTask(Task(3, "Call plumber", 4));
    cout << "Tasks after addition:" << endl;
    manager.viewTasks();

    // Fetch Next Highest Priority Task
    try {
        Task nextTask = manager.getNextTask();
        cout << "Highest Priority Task: " << nextTask << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    // Complete Highest Priority Task
    try {
        manager.completeHighestPriorityTask();
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    cout << "Tasks after removal of the highest priority task:" << endl;
    manager.viewTasks();

    // Fetch Next Highest Priority Task Again
    try {
        Task nextTask = manager.getNextTask();
        cout << "Highest Priority Task: " << nextTask << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    cout << "--------------------------------------------------\n";
}

void RunTaskApp() {
    cout << "...Running TaskHandlerApp..." << endl;
    TaskHandlerApp app;
    app.run();
    cout << "--------------------------------------------------\n";
}

void testFriendRecommendation() {
    cout << "...Testing FriendRecommendation..." << endl;

    // Initialization and Adding Users
    FriendManager frSystem;
    frSystem.addUser(User(1, "Alice"));
    frSystem.addUser(User(2, "Bob"));
    frSystem.addUser(User(3, "Charlie"));
    frSystem.addUser(User(4, "Diana"));

    // Adding Friendships
    frSystem.addFriendship(1, 2);
    frSystem.addFriendship(1, 3);
    frSystem.addFriendship(2, 3);
    frSystem.addFriendship(3, 4);

    // Getting Recommendations
    frSystem.getRecommendations(1);
    cout << "--------------------------------------------------\n";
}

void RunFriendRecommendationApp() {
    cout << "...Running FriendsHandlerApp..." << endl;
    FriendsHandlerApp app;
    app.run();
    cout << "--------------------------------------------------\n";
}

void testLibrarySystem1() {
    cout << "...Testing LibrarySystem1..." << endl;

    // Initialization and Adding Books
    LibraryManager lm;
    lm.addBook(Book(1, "Clean Code", "Robert"));
    lm.addBook(Book(2, "The Programmer", "Andrew"));
    lm.addBook(Book(3, "Design Patterns", "Erich"));

    // Adding Borrowers
    lm.addBorrower(Borrower(1, "John"));
    lm.addBorrower(Borrower(2, "Mary"));
    lm.addBorrower(Borrower(3, "Alice"));

    // Issue and Return Books
    lm.issueBook(1, 1);  // John borrows "Clean Code"
    lm.returnBook(1, 1);  // John returns "Clean Code"
    cout << "--------------------------------------------------\n";
}

void testLibrarySystem2() {
    cout << "...Testing LibrarySystem2..." << endl;

    // Initialization and Adding Books
    LibraryManager libraryManager;
    cout << "=== Adding Books ===\n";
    libraryManager.addBook(Book(1, "The Great Gatsby", "F. Scott Fitzgerald"));
    libraryManager.addBook(Book(2, "1984", "George Orwell"));
    libraryManager.addBook(Book(3, "To Kill a Mockingbird", "Harper Lee"));
    libraryManager.addBook(Book(4, "Moby Dick", "Herman Melville"));

    // Display Inventory
    cout << "\n=== Displaying Inventory ===\n";
    libraryManager.displayInventory();

    // Adding Borrowers
    cout << "\n=== Adding Borrowers ===\n";
    libraryManager.addBorrower(Borrower(1, "Alice Johnson"));
    libraryManager.addBorrower(Borrower(2, "Bob Smith"));
    libraryManager.addBorrower(Borrower(3, "Charlie Brown"));

    // Display Borrowers
    cout << "\n=== Displaying Borrowers ===\n";
    libraryManager.displayBorrowers();

    // Issue Books
    cout << "\n=== Issuing Books ===\n";
    libraryManager.issueBook(1, 1);  // Issue "The Great Gatsby" to Alice
    libraryManager.issueBook(2, 2);  // Issue "1984" to Bob
    libraryManager.issueBook(3, 1);  // Issue "To Kill a Mockingbird" to Alice
    libraryManager.issueBook(4, 3);  // Issue "Moby Dick" to Charlie

    // Attempt to Issue Unavailable Book
    cout << "\n=== Attempting to Issue an Unavailable Book ===\n";
    libraryManager.issueBook(1, 2);  // Attempt to issue "The Great Gatsby" to Bob (should fail)

    // Display Updated Inventory
    cout << "\n=== Displaying Updated Inventory ===\n";
    libraryManager.displayInventory();

    // Display Updated Borrowers
    cout << "\n=== Displaying Updated Borrowers ===\n";
    libraryManager.displayBorrowers();

    // Return Books
    cout << "\n=== Returning Books ===\n";
    libraryManager.returnBook(1, 1);  // Alice returns "The Great Gatsby"
    libraryManager.returnBook(3, 1);  // Alice returns "To Kill a Mockingbird"

    // Manage Overdue Books
    cout << "\n=== Managing Overdue Books ===\n";
    libraryManager.addOverdueBook(1, 5);  // The Great Gatsby is 5 days overdue
    libraryManager.addOverdueBook(2, 2);  // 1984 is 2 days overdue
    libraryManager.handleMostOverdueBook();
    libraryManager.handleMostOverdueBook();  // Handle next most overdue

    // Display Final Inventory and Borrowers
    cout << "\n=== Displaying Final Inventory ===\n";
    libraryManager.displayInventory();
    cout << "\n=== Displaying Final Borrowers ===\n";
    libraryManager.displayBorrowers();
    cout << "--------------------------------------------------\n";
}

void RunLibrarySystemApp() {
    cout << "...Running LibraryHandlerApp..." << endl;
    LibraryHandlerApp app;
    app.run();
    cout << "--------------------------------------------------\n";
}

int main() {
    // Data Structure Tests
    testDynamicArray();

    // Linked List Tests
    testSinglyLL();
    testSinglyLLTailed();
    testDLList();

    // Stack Tests
    testStackArray();
    testStackLL();

    // Queue Tests
    testQueueArray();
    testQueueLL();

    // Deque Tests
    testDequeArray();
    testDequeLL();

    // Skip List and Space-Efficient List Tests
    testSkipList();
    testSEList();

    // Map and Priority Queue Tests
    testMap();
    testPriorityQueue();

    // Heap Tests
    testBinaryHeap();

    // Tree Tests
    testBinaryTreeArray();
    testBinarySearchTree();
    testAVLTree();

    // Graph Tests
    testGraphAdjMatrix();
    testGraphAdjList();
    testGraphAdjList1();
    testGraphAdjList2();

    // Hash Table Tests
    testLinearHashTable();
    testChainedHashTable();


    // Library System Tests
    testLibrarySystem1();
    testLibrarySystem2();

    // Friend Recommendation App
    RunFriendRecommendationApp();
    testFriendRecommendation();

    // Task Manager App
    RunTaskApp();
    testTaskManager();
    // Final Output
    cout << "Hello world!" << endl;

    return 0;
}
