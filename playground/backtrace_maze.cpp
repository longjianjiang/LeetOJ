#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    // 1,2,3,4 东南西北
    /*
     北
   西  东
     南
     */
    vector<tuple<int, int, char>> edges = { {1, 0, '2'}, {0, -1, '3'},{0, 1, '1'}, {-1, 0, '4'},  };
    vector<char> directions = {'1', '2', '3', '4'};
public:
    void dfs(vector<vector<char>>& matrix, int row, int col, int x, int y) {
        char ch = matrix[x][y];
        if (ch != 'o') { return; }
        
        auto checkHasFound = [&]() -> bool {
            if (matrix[row-1][col-1] == '1' || matrix[row-1][col-1] == '2') {
                return true;
            }
            return false;
        };
        
        if (x == row-1 && y == col-1) {
            vector<tuple<int, int, char>> edges = {{0, -1, '2'}, {-1, 0, '1'}};
            for (int i = 0; i < edges.size(); ++i) {
                auto edge = edges[i];
                int x1 = x+get<0>(edge), y1 = y+get<1>(edge);
                if (x1 < 0 || x1 >= row || y1 < 0 || y1 >= col) { continue; }
                char tmp = matrix[x1][y1];
                if (tmp != 'o') {
                    continue;
                }
                matrix[x][y] = get<2>(edge);
            }
            return;
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (checkHasFound()) {
                return;
            }
            auto edge = edges[i];
            int x1 = x+get<0>(edge), y1 = y+get<1>(edge);
            if (x1 < 0 || x1 >= row || y1 < 0 || y1 >= col) { continue; }
            char tmp = matrix[x1][y1];
            if (tmp != 'o') { continue; }
            
            matrix[x][y] = get<2>(edge);
            dfs(matrix, row, col, x1, y1);
        }
        if (checkHasFound()) {
            return;
        }
        if (find(directions.begin(), directions.end(), matrix[x][y]) != directions.end()) {
            matrix[x][y] = 'o';
        }
        return;
    }
    
    void searchMatrix(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            cout << "NO Path" << endl;
            return;
        }
        int col = matrix[0].size();
        if (col == 0) {
            cout << "NO Path" << endl;
            return;
        }
        
        dfs(matrix, row, col, 0, 0);
        
        if (matrix[row-1][col-1] == '1' || matrix[row-1][col-1] == '2') {
            show_arr_two_dimensional(matrix);
        } else {
            cout << "NO Path" << endl;
        }
    }
    
    void show_arr_one_dimensional(vector<char> arr) {
        cout << "[";
        for (int i = 0; i < arr.size(); ++i) {
            char num = arr[i];
            if (i == arr.size()-1) {
                cout << num;
            } else {
                cout << num << " ";
            }
        }
        cout << "]\n";
    }

    void show_arr_two_dimensional(vector<vector<char>> arr) {
        for (auto v: arr) {
            show_arr_one_dimensional(v);
        }
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<char>> matrix = {
		{'o', 'o', 'o', 'x', 'x', 'o', 'x'},

		{'o', 'x', 'o', 'o', 'x', 'o', 'o'},

		{'o', 'o', 'x', 'o', 'o', 'o', 'x'},

		{'x', 'o', 'o', 'x', 'x', 'x', 'o'},

		{'o', 'o', 'x', 'o', 'o', 'x', 'o'},

		{'o', 'x', 'o', 'o', 'o', 'x', 'o'},

		{'o', 'o', 'o', 'x', 'o', 'o', 'o'}
    };
    
    Solution s;
    s.searchMatrix(matrix);
    return 0;
}
