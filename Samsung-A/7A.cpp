#include <iostream>
#include <queue>
using namespace std;

// Kiểm tra xem tọa độ (x, y) có nằm trong phạm vi của ảnh hay không
bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// Thuật toán floodfill sử dụng BFS
void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int rows = image.size();
    int cols = image[0].size();
    int originalColor = image[sr][sc];

    if (originalColor == newColor) {
        return; // Không cần thay đổi màu nếu màu mới giống màu cũ
    }

    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        // Thay đổi màu của điểm ảnh hiện tại
        image[x][y] = newColor;

        // Duyệt các điểm ảnh kề nhau và có cùng màu
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY, rows, cols) && image[newX][newY] == originalColor) {
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1}
    };

    int sr = 1, sc = 2; // Tọa độ điểm ảnh bắt đầu
    int newColor = 2; // Màu mới

    floodFill(image, sr, sc, newColor);

    // In ra ảnh sau khi áp dụng thuật toán floodfill
    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[i].size(); j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

