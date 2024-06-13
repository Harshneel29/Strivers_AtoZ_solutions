#include <algorithm>

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if( m == 1) return matrix[0][0];
        int mini = 1e9;
        vector<int> front(m,0),cur(m,0);
        for(int k = 0; k < m; k++) front[k] = matrix[0][k];

        for(int i = 1; i < m; i++){
            for(int j = 0; j < m; j++){
                int down = matrix[i][j] + front[j];

                int right = matrix[i][j];
                if(j < m-1) right += front[j+1];
                else right += 1e9;

                int left = matrix[i][j];
                if(j > 0) left += front[j-1];
                else left += 1e9;

                int temp = min(left,right);
                cur[j] = min(down,temp);
            }
            front = cur;
        }

        for(int i = 0; i < m; i++){
            mini = min(mini,cur[i]);
        }

        return mini;
    }
};