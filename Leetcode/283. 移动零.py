class Solution:
       def moveZeroes(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        kengwei=0
        for i in range(len(nums)):
            if nums[i]:
                nums[kengwei]= nums[i]
                kengwei =kengwei +1
            #print(f"kw:{kengwei}, {i}, {nums}")


        for i in range(kengwei,len(nums)):
            nums[i] =0
        #print(f"{nums}")
