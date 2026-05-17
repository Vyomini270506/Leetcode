class Solution(object):
    def countGoodNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """

        m = 10**9 + 7

        return (pow(5,(n+1)//2,m) * pow(4,n//2,m)) % m