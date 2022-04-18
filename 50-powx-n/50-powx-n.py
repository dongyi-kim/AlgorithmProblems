class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0 : return 1
        if n < 0 : return 1 / self.myPow(x, -n)
        
        ret = 1 if n % 2 == 0 else x 
        return ret * self.myPow(x*x, n // 2)