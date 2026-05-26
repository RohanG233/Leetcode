class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int res = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(candy(candies, k, mid))
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }

    bool candy(vector<int> &candies, long long k, int c)
    {
        long long res = 0;
        for(int i=0; i<candies.size(); i++)
        {
            res += (candies[i] / c);
            if(res >= k)
            {
                return true;
            }
        }
        return false;
    }
};