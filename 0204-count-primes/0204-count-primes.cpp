class Solution {
public:
    int countPrimes(int n) {
        return sieveOfEratosthenes(n);
    }
private:
    int sieveOfEratosthenes(int n){
        vector<bool> ISprime(n+1, true);
        ISprime[0] = ISprime[1] = false;
        for (int i = 2; i <= n; i++) 
        {
            if (ISprime[i] && (long long)i * i <= n) 
            {
                for (int j = i * i; j <= n; j += i)ISprime[j] =                                 false;
            }
        }
        int ans = 0;
        for(int i = 2;i<n;i++)
            if(ISprime[i])
                ans++;
        return ans;
    }
    bool isPrime(int n) {
        if(n <= 1) 
            return false;
        if(n <= 3) 
            return true;
        if(n % 2 == 0 || n % 3 == 0) 
            return false;
        for(int i = 5; i * i <= n; i = i + 6)
            if(n % i == 0 || n % (i + 2) == 0) 
                return false;
        return true;
    }
};