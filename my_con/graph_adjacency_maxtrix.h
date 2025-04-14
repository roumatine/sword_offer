#include "..\head.h"

class GraphAdjMat {
    vector<int> vertices;
    vector<vector<int>> adjmat;

    GraphAdjMat(const vector<int>& vertices, const vector<vector<int>>& edeges) {
        for (int val : vertices) {
            addVertex(val);
        }
        for (const vector<int> &edge : edeges) {
            addEdge(edge[0], edge[1]);
        }
    }
    int size() const {
        return vertices.size();
    }

    void addVertex(int val) {
        int n = size();
        vertices.push_back(val);
        adjmat.emplace_back(vector<int>(n, 0));
        for( vector<int> &row:adjmat) {
            row.push_back(0);
        }
    }
    void removeVertex(int index) {
        if (index >= size()) {
            throw out_of_range("顶点不存在");
        }
        vertices.erase(vertices.begin() + index);
        adjmat.erase(adjmat.begin() + index);
        for (vector<int> &row : adjmat) {
            row.erase(row.begin() + index);
        }
    }
    
    void addEdge(int i, int j) {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw out_of_range("顶点不存在");
        }
        adjmat[i][j] = 1;
        adjmat[j][i] = 1;
    }

    void removeEdge(int i, int j) {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw out_of_range("顶点不存在");
        }
        adjmat[i][j] = 0;
        adjmat[j][i] = 0;
    }
    void print() {
        cout << "顶点列表 = ";
        // printVector(vertices);
        cout << "邻接矩阵 =" << endl;
        // printVectorMatrix(adjMat);
    }
};