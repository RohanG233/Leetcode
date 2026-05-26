class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int p : piles)
        {
            high = max(high, p);
        }

        int res = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(EatTime(piles, mid) <= h)
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

    long long EatTime(vector<int> &piles, int speed)
    {
        long long h = 0;
        for(int i=0;i<piles.size();i++)
        {
            h += piles[i] / speed;
            if((piles[i] % speed) != 0)
            {
                h += 1;
            }
        }
        return h;
    }
};