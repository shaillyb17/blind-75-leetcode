#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    bool row = false, col = false;
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] == 0) {
                if(i == 0)  row = true;
                if(j == 0)   col = true;
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    
    for(int i = 1; i < r; i++) {
        for(int j = 1; j < c; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    
    if(row)
        for(int i = 0; i < c; i++)
            matrix[0][i] = 0;
    
    if(col)
        for(int i = 0; i < r; i++)
            matrix[i][0] = 0;
    
}

int main(){
    int m, n;	cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    setZeroes(matrix);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}