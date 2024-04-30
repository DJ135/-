#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 有向图类
class DirectedGraph {
public:
    // 构造函数，初始化图的顶点数和邻接表
    DirectedGraph(int vertices) : vertex_count(vertices) {
        adjacency_list.resize(vertices);
    }

    // 添加一条边
    void addEdge(int source, int destination) {
        adjacency_list[source].push_back(destination);
    }

    // 打印邻接表
    void printGraph() const {
        for (int i = 0; i < vertex_count; ++i) {
            cout << "Vertex " << i << " :";
            for (const auto& dest : adjacency_list[i]) {
                cout << " -> " << dest;
            }
            cout << endl;
        }
    }

    // 寻找所有简单路径
    void findAllSimplePaths() {
        for (int i = 0; i < vertex_count; ++i) {
            for (int j = 0; j < vertex_count; ++j) {
                if (i != j) {
                    list<int> path;
                    vector<bool> visited(vertex_count, false);
                    findSimplePathsUtil(i, j, visited, path);
                }
            }
        }
    }

private:
    int vertex_count; // 顶点数
    vector<list<int>> adjacency_list; // 邻接表

    // 递归查找简单路径的工具方法
    void findSimplePathsUtil(int start, int end, vector<bool>& visited, list<int>& path) {
        visited[start] = true;
        path.push_back(start);

        if (start == end) {
            printPath(path);
        }
        else {
            for (const auto& neighbor : adjacency_list[start]) {
                if (!visited[neighbor]) {
                    findSimplePathsUtil(neighbor, end, visited, path);
                }
            }
        }

        visited[start] = false;
        path.pop_back();
    }

    // 打印路径
    void printPath(const list<int>& path) const {
        for (const auto& vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    }
};

// 主函数
int main() {
    // 输入顶点数和边数
    int vertices, edges;
    cout << "请输入顶点数V和边数E: ";
    cin >> vertices >> edges;

    // 创建有向图对象
    DirectedGraph graph(vertices);

    // 输入边信息
    cout << "请输入边 (source destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    // 打印图的邻接表
    cout << "图的邻接表表示:" << endl;
    graph.printGraph();

    // 寻找并打印所有简单路径
    cout << "所有简单路径:" << endl;
    graph.findAllSimplePaths();

    return 0;
}
