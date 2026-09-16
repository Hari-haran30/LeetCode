class Solution {
public:
    long long makePal(long long x, bool odd) {
        long long res = x;

        if (odd)
            x /= 10;

        while (x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }

    long long minOperations(vector<int>& nums) {
        static vector<long long> evenPal, oddPal;
        static bool initialized = false;

        if (!initialized) {
            for (long long i = 1; i <= 99999; i++) {
                long long p1 = makePal(i, true);
                long long p2 = makePal(i, false);

                if (p1 <= 1000000000LL) {
                    if (p1 % 2)
                        oddPal.push_back(p1);
                    else
                        evenPal.push_back(p1);
                }

                if (p2 <= 1000000000LL) {
                    if (p2 % 2)
                        oddPal.push_back(p2);
                    else
                        evenPal.push_back(p2);
                }
            }

            sort(evenPal.begin(), evenPal.end());
            sort(oddPal.begin(), oddPal.end());

            initialized = true;
        }

        long long ans = 0;

        for (long long x : nums) {
            vector<long long>& pal = (x % 2) ? oddPal : evenPal;

            auto it = lower_bound(pal.begin(), pal.end(), x);

            long long best = LLONG_MAX;

            if (it != pal.end())
                best = min(best, llabs(*it - x));

            if (it != pal.begin()) {
                --it;
                best = min(best, llabs(*it - x));
            }

            ans += best / 2;
        }

        return ans;
    }
};