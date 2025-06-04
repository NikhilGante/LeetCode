#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int width, height;
        bool exist(vector<vector<char>>& board, string word) {
            ios::sync_with_stdio(false);
            cin.tie(0);

            width = board[0].size(), height = board.size();
            vector<vector<bool>> visited(height, vector<bool>(width, false));
            for(int r = 0; r < height; r++){
                for(int c = 0; c < width; c++){
                    if(backtrack(board, word, 0, visited, r, c)) return true;
                }
            }
            return false;
        }
    
    
        bool backtrack(vector<vector<char>>& board, string& word, int index, vector<vector<bool>>& visited, int r, int c){
            if(c < 0 || c > width - 1 || r < 0 || r > height - 1 || visited[r][c])  return false;
            visited[r][c] = true;
    
            char cur = board[r][c];
            if(cur == word[index]){
                if(index == word.size() - 1)   return true;
            }
            else goto exit;
            
            if(backtrack(board, word, index + 1, visited, r + 1, c))   return true;
            if(backtrack(board, word, index + 1, visited, r - 1, c))   return true;
            if(backtrack(board, word, index + 1, visited, r, c + 1))   return true;
            if(backtrack(board, word, index + 1, visited, r, c - 1))   return true;
        exit:       
            index--;
            visited[r][c] = false;
            return false;
        }
};