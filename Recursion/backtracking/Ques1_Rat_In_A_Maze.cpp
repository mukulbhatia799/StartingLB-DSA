// asked in most of the companies to check the knowledge of backtracking.
// gfg ques.

/*

1. there are four directions to move.
2. check the valid move means check that the move which should not be out of bound(or size of array).
3. create a checked vector of vector and in each recursive function, mark the place as true so that when we come back and find for new route, the checked route is marked and this will also keep us away from infinite loop.
4. Base condition - when the maze reach the [n-1][n-1] index then print the answer and return ;

*/

#include<iostream>
#include<vector>
using namespace std;

void findDifferentPaths(vector<vector<int> >& m, int n, vector<vector<bool> >& passed, int i, int j, string& ans)
    {
        // base cond.
        if(i == n-1 && j == n-1) {
            cout << "->" << ans << endl;
            ans.clear();
            return ;
        }
        
        // down
        // out of bound, passed[i][j] != true, m[i][j] == 1
        if((i+1 < n && j < n) && passed[i+1][j] == false && m[i+1][j] == 1)
        {
            ans.push_back('D');
            passed[i+1][j] = true;
            findDifferentPaths(m, n, passed, i+1, j, ans);
            ans.pop_back();     // backtracking.
        }
        
        // left
        if((i < n && j-1 < n) && passed[i][j-1] == false)
        {
            ans.push_back('L');
            passed[i][j-1] = true;
            findDifferentPaths(m, n, passed, i, j-1, ans);
            ans.pop_back();
        }
        
        // Up 
        if((i+1 < n && j < n) && passed[i-1][j] == false)
        {
            ans.push_back('U');
            passed[i-1][j] = true;
            findDifferentPaths(m, n, passed, i-1, j, ans);
            ans.pop_back();
        }
        
        // Right
        if((i+1 < n && j < n) && passed[i][j+1] == false)
        {
            ans.push_back('R');
            passed[i][j+1] = true;
            findDifferentPaths(m, n, passed, i, j+1, ans);
            ans.pop_back();
        }

        return ;
    }
    vector<string> findPath(vector<vector<int>> &m, int row, int col) {
        vector<vector<bool> > passed(row, vector<bool> (col, false));
        passed[0][0] = true;

        // for(int i = 0; i < passed.size(); i++)
        // {
        //     for(int j = 0; j < passed[i].size(); j++)
        //     {
        //         cout << passed[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        string ans;
        findDifferentPaths(m, row, passed, 0, 0, ans);
    }

int main(){
    vector<vector<int> > m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    findPath(m, m.size(), m[0].size());

    return 0;
}