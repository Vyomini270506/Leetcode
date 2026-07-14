class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            s += piles[i];
        }

        long long x;
        if (s % h == 0) {
            x = s / h;
        } else {
            x = (s / h) + 1;
        }

        long long m = x;
        int up = *max_element(piles.begin(),piles.end());
        while (m <= up) {
            long long t = 0;

            for (int i = 0; i < n; i++) {
                t += ceil((double)piles[i] / m);
            }

            if (t <= h) {
                return (int)m;
            }

            m++;
        }

        return 0;
    }
};