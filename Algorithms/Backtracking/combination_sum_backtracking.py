# Leetcode 40. Combination Sum II
# Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

# Each number in candidates may only be used once in the combination.

# Note: The solution set must not contain duplicate combinations.


result = []

def combinationSum2(candidates, target):
    
    candidates.sort()
    combinations(candidates,len(candidates),target,[])
    
    return result
    
    
def combinations(nums,n,target,included):
    
    # Base condition to check target == 0
    if target == 0:
        #Condition to check if given combination is already included in result or not
        if included not in result:
            result.append(included)
        return
    
    # Base condition to check when len of array == 0
    if n == 0:
        return
    
    # if target is greater than curr element under consideration you have two choices that is to include in result or not
    if nums[n-1] <= target:
    
        combinations(nums,n-1,target-nums[n-1],included+[nums[n-1]])
        combinations(nums,n-1,target,included)
        
    else:
    # if target is lesser than curr element under consideration you have only one choice that is to not include it in result   
        
        combinations(nums,n-1,target,included)

candidates = [10,1,2,7,6,1,5]
target = 8
print(combinationSum2(candidates, target))
        