#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void swap(int& a, int& b){
            int temp = a;
            a = b;
            b = temp;
        }
    
    
        void rotate(vector<vector<int>>& matrix) {
            int height = matrix.size(), width = matrix[0].size();
            for(int r = 0; r < height; r++){
                for(int c = 0; c < r; c++){
                    swap(matrix[r][c], matrix[c][r]);
                }
            }
    
            for(int r = 0; r < height; r++){
                for(int c = 0; c < width/2; c++){
                    swap(matrix[r][c], matrix[r][width - 1 - c]);
                }
            }
        }
};