#include <iostream>
#include <chrono>
using namespace std;

int ctr = 0, flag = 0;
int rows, cols, arr[10][10];

bool isPossible(int row, int col) {
    if (row < rows && row >= 0 && col < cols && col >= 0)
        return 1;
    return 0;
}

void dfs(int row, int col) {
    int testrow[] = {row-1, row, row+1};
    int testcol[] = {col-1, col, col+1};
    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j <= 2; j++) {
            if(isPossible(testrow[i], testcol[j])) {
                if(flag == 0) {
                    ctr++;
                    flag = 1;
                }
                if(arr[testrow[i]][testcol[j]] == 1) {
                    arr[testrow[i]][testcol[j]] = 0;
                    dfs(testrow[i], testcol[j]);
                }
            }
        }
    }
}

int main() {
    auto start = chrono::steady_clock::now();
    cout << "Enter no of rows and cols" << endl;
    cin >> rows;
    cin >> cols;
    cout << "Enter elements of the array:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }
    
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            if(arr[i][j] == 1) {
                flag = 0;
                dfs(i, j);
                flag = 1;
            }
    }
    
    cout << "No of Islands: " << ctr << endl;
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
    << chrono::duration_cast<chrono::milliseconds>(end - start).count()
    << " ms" << endl;
    
    return 0;
}
