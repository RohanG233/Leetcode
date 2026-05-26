class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int row = matrix[0][0];
        int col = matrix[n-1][n-1];
        int ans = row;

        while(row <= col)
        {
            int mid = row + (col - row) / 2;
            int c = counting(matrix, k, mid);
            if(c >= k)
            {
                ans = mid;
                col = mid - 1;
            }
            else
            {
                row = mid + 1;
            }
        }
        return ans;
    }

    int counting(vector<vector<int>>& matrix, int k, int mid)
    {
        int n = matrix.size();
        int row = n-1;
        int col = 0;

        int count = 0;

        while(row >= 0 && col < n)
        {
            if(matrix[row][col] <= mid)
            {
                count += (row + 1);
                col ++;
            }
            else
            {
                row --;
            }
        }
        return count;
    }
};