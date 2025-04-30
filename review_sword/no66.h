/*
no66. 机器人的运动范围
*/
#include "..\head.h"

bool canReach(int threshold, int x, int y) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    while (y > 0) {
        sum += y % 10;
        y /= 10;
    }
    return sum <= threshold;
}

int movingCountCore(int threshold, int i, int rows, int j, int cols, vector<vector<bool>> &visit) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || !canReach(threshold, i, j) || visit[i][j] == true)
        return 0;
    visit[i][j] = true;

    return movingCountCore(threshold, i - 1, rows, j, cols, visit) +
    movingCountCore(threshold, i + 1, rows, j, cols, visit) +
    movingCountCore(threshold, i, rows, j - 1, cols, visit) +
    movingCountCore(threshold, i, rows, j + 1, cols, visit) + 1;
}

int movingCount(int threshold, int rows, int cols) {
    vector<vector<bool>> visit(rows, vector<bool>(cols, false));
    return movingCountCore(threshold, 0, rows, 0, cols, visit);
}


// BFS
bool can_reach(int threshold, int x, int y) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    while (y > 0) {
        sum += y % 10;
        y /= 10;
    }
    return sum <= threshold;
    
}

int moving_count(int threshold, int rows, int cols) {
    vector<vector<bool>> grid(rows, vector<bool>(cols, false));
    queue<pair<int, int>> que;
    if (can_reach(threshold, 0, 0)) {
        que.push(make_pair(0, 0));
        grid[0][0] = true;
    }
    int cnt = 0;
    while (!que.empty()) {
        ++cnt;
        int x, y;
        tie(x, y) = que.front();
        que.pop();
        if (x + 1 < rows && !grid[x + 1][y] && can_reach(threshold, x + 1, y)) {
            grid[x + 1][y] = true;
            que.push(make_pair(x + 1, y));
        }
        if (y + 1 < cols && !grid[x][y + 1] && can_reach(threshold, x, y + 1)) {
            grid[x][y + 1] = true;
            que.push(make_pair(x, y + 1));
        }
    }
    return cnt;
}