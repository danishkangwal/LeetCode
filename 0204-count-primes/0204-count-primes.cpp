class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        vector<bool> prime(n+1,true);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<n;i++){
            if (prime[i]) {
				for (int j = i * i; j <= n; j += i) {
					prime[j] = false;
				}
			}
        }
        int ans = 0;
        for(int i=2;i<n;i++)
            if(prime[i])
                ans++;
        return ans;
    }
};