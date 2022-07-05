#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int r = matrix.size(), c = matrix[0].size();
    int left = 0, right = c - 1, up = 0, down = r - 1;
    while(left <= right && up <= down) {
        for(int i = left; i <= right; i++)
            res.push_back(matrix[up][i]);
        up++;
        for(int i = up; i <= down; i++)
            res.push_back(matrix[i][right]);
        right--;
        if(up <= down) {
            for(int i = right; i >= left; i--)
                res.push_back(matrix[down][i]);
            down--;
        }
        if(left <= right) {
            for(int i = down; i >= up; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
}

int main() {
    int m, n;	cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> res = spiralOrder(matrix);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}