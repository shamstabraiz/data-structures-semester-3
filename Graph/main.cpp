#include <iostream>
#include <string>
#include "Graph/graph.h"

using namespace std;

void displayMenu() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════╗" << endl;
    cout << "║              Graph Operations              ║" << endl;
    cout << "╠════════════════════════════════════════════╣" << endl;
    cout << "║  1. Display Graph                          ║" << endl;
    cout << "║  2. Perform BFS (Breadth-First Search)     ║" << endl;
    cout << "║  3. Perform DFS (Depth-First Search)       ║" << endl;
    cout << "║  4. Exit                                   ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    cout << "Enter your choice: ";
}

int main() {
    string filePath;
    cout << "╔════════════════════════════════════════════╗" << endl;
    cout << "║        Welcome to the Graph Program        ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    cout << "Enter the path to the graph file: ";
    cin >> filePath;

    try {
        Graph graph(filePath.c_str());

        int choice;
        do {
            displayMenu();
            cin >> choice;

            switch (choice) {
            case 1: // Display the graph
                cout << "\nGraph Representation:\n";
                cout << graph << endl;
                break;

            case 2: { // Perform BFS
                int start, target;
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter target vertex: ";
                cin >> target;
                cout << "Performing BFS from " << start << " to " << target << "...\n";
                graph.bfs(start, target);
                break;
            }

            case 3: { // Perform DFS
                int start, target;
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter target vertex: ";
                cin >> target;
                cout << "Performing DFS from " << start << " to " << target << "...\n";
                graph.dfs(start, target);
                break;
            }

            case 4: // Exit
                cout << "╔════════════════════════════════════════════╗" << endl;
                cout << "║          Exiting the program. Goodbye!     ║" << endl;
                cout << "╚════════════════════════════════════════════╝" << endl;
                break;

            default:
                cout << "Invalid choice! Please select a valid option.\n";
            }
        } while (choice != 4);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
