#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e) {
        V = v;
        E = e;
    }

    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    void unionSets(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    void printGraph() {
        cout << "b1: Ğ? th? ban d?u:" << endl;
        for (Edge edge : edges) {
            cout << "Edge (" << edge.src << "-" << edge.dest << ") with weight " << edge.weight << endl;
        }
    }

    void kruskalMST() {
        cout << "b2: Tr?ng s? k gi?m:" << endl;
        vector<Edge> result;
        int i = 0, e = 0;

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V);
        for (int v = 0; v < V; v++) {
            parent[v] = v;
        }

        while (e < V - 1 && i < E) {
            Edge nextEdge = edges[i++];
            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);
            if (x != y) {
                result.push_back(nextEdge);

                cout << "Adding edge (" << nextEdge.src << "-" << nextEdge.dest << ") with weight " << nextEdge.weight << " to the MST." << endl;

                unionSets(parent, x, y);
                e++;
            } else {
                cout << "Edge (" << nextEdge.src << "-" << nextEdge.dest << ") with weight " << nextEdge.weight << " forms a cycle, skipping." << endl;
            }
        }

        cout << "b3: K?t qu? c?a thu?t toán Kruskal (Minimum Spanning Tree):" << endl;
        for (Edge edge : result) {
            cout << "Edge (" << edge.src << "-" << edge.dest << ") with weight " << edge.weight << endl;
        }
    }
};

int main() {
    int V = 4; // S? d?nh
    int E = 5; // S? c?nh

    Graph graph(V, E);

    // Thêm c?nh vào d? th?
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    graph.printGraph();
    graph.kruskalMST();

    return 0;
}

