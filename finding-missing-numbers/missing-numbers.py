class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        og_nums = set(nums) #converting the list to a set
        new_nums = []

        #creating the new set with all the elements "supposedly" missing inclusive
        for i in range(1, len(nums) +1):
            new_nums.append(i)
        
        return set(new_nums) - og_nums