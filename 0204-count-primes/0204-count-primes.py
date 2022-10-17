class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        
        prime = [1] * n
        prime[0] = prime[1] = 0
        
        
        for i in range(2, int(n**0.5)+1):
            if  prime[i] != 0:
                prime[i*i:n:i] = [0] * ((n-1-i*i)//i + 1)

        return sum(prime)
        