class Solution(object):
    def minMergedInteger(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        x=1000000009
        for i in range(0,len(nums),2):
            st=str(nums[i])+str(nums[i+1])
            x=min(x,int(st))
        return x