#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < matrix.size(); i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main(){
    int m, n;	cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    rotate(matrix);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}