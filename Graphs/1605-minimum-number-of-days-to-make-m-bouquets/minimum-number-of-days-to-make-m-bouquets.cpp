class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        if(arr.size() < (long long)m*k)
        {
            return -1;
        }

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int res = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(blooms(arr, m, k, mid) >= m)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }

    long long blooms(vector<int> &arr, int m, int k, int day)
    {
        long long bouq = 0;
        int kval = 0;

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] <= day)
            {
                kval += 1;
            }
            else
            {
                kval = 0;
            }
            if(kval == k)
            {
                bouq += 1;
                kval = 0;
            }
        }
        return bouq;
    }


};