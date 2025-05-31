#include <bits/stdc++.h>
using namespace std;
int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; ++i)    f *= i;
    return f;
}

class Solution {
    public:
        int n;
        vector<vector<string>> solveNQueens(int n) {
            ios::sync_with_stdio(false);
            cin.tie(0);

            this->n = n;
            vector<vector<string>> acc_ans;
            acc_ans.reserve(factorial(n));

            vector<int> q_locs; // current locations of queens
            vector<vector<int>> ans;    // final locations of queens
            vector<bool> occupied(n, false);
            backTrack(occupied, q_locs, ans);

            for(auto& board: ans){  // Convert from position format to strings
                acc_ans.push_back({});
                vector<string>& cur_board = acc_ans.back();
                cur_board.reserve(n);
                for (int row = 0; row < board.size(); row++){
                    cur_board.push_back("");
                    string& cur = cur_board.back();
                    cur.reserve(n);
                    int col = board[row];
                    for(int i = 0; i < col; i++)    cur.push_back('.');
                    cur.push_back('Q');
                    for(int i = col + 1; i < n; i++)    cur.push_back('.');
                }
            }
            return acc_ans;
        }

        void backTrack(vector<bool>& occupied, vector<int>& q_locs, vector<vector<int>>& ans){
            if(q_locs.size() == n){
                ans.push_back(q_locs);
                return;
            }
            int r = q_locs.size();
            for (int c = 0; c < n; c++){
                if(!inCheck(r, c, q_locs) && !occupied[c]){
                    occupied[c] = true;
                    q_locs.push_back(c);
                    backTrack(occupied, q_locs, ans);
                    occupied[c] = false;
                    q_locs.pop_back();
                }
            }
        }

        bool inCheck(int r, int c, vector<int>& q_locs){    // Returns if queen at [r][c] is in DIAGONAL CHECK with past queens
            for (int row = 0; row < q_locs.size(); row++){
                if(abs(row - r) == abs(q_locs[row] - c))    return true;
            }
            return false;
        }
};