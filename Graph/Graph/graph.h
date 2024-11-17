#include <iostream>
#include <fstream>
#include <sstream>
#include "../Queue/QueueWithLinkedList.h"
#include "../Stack/StackWithLinkedList.h"


using namespace std;
void showPath(int u, int v, int p[]) {
    if (u != v) showPath(u, p[v], p);
    cout << v << " ";
}

int countLines(const char* filename) {
    ifstream file(filename);
    string line;
    int totalLines = 0;
    while (getline(file, line)) {
        totalLines++;
    }
    file.close();
    return totalLines;
}

class Graph {
private:
    int size, ** graph;
public:
    Graph(const char* file);
    ~Graph() {
        for (int i = 0; i < size; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
    }

    inline const int numberOfVertices()const {
        return size;
    }

    inline  int*& operator[](int index)const {
        return graph[index];
    }

    void bfs(const int s, const  int g);
    void dfs(const int s, const  int g);


};

Graph::Graph(const char* file) {
    size = countLines(file);
    graph = new int* [size];
    ifstream inpFile(file);
    string line;
    for (int i = 0; getline(inpFile, line);i++) {
        graph[i] = new int[size];
        stringstream values(line);
        string val;
        for (int j = 0; getline(values, val, '\t'); j++) {
            graph[i][j] = atoi(val.c_str());
        }
    }
    inpFile.close();
}


ostream& operator<<(ostream& out, const Graph& g) {
    for (int i = 0; i < g.numberOfVertices(); i++) {
        for (int j = 0; j < g.numberOfVertices(); j++) {
            out << g[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

void Graph::bfs(const int s, const int g) {
    int p[size];
    int visited[size] = { 0 };
    QueueWithLinkedList<int> queue;
    queue.insert(s);
    visited[s] = 1;

    while (!queue.isEmpty()) {
        int u = queue.extract();
        if (u == g)break;
        for (int v = 0; v < size; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                visited[v] = 1;
                p[v] = u;
                queue.insert(v);
            }
        }
    }
    showPath(s, g, p);
    cout << endl;
}

void Graph::dfs(const int s, const int g) {
    int p[size];
    int visited[size] = { 0 };
    StackWithLinkedList<int> stack;
    stack.push(s);
    visited[s] = 1;
    while (!stack.isEmpty()) {
        int u = stack.pop();
        if (u == g)break;
        for (int v = 0; v < size; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                visited[v] = 1;
                p[v] = u;
                stack.push(v);
            }
        }
    }
    showPath(s, g, p);
    cout << endl;
}

