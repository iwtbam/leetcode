# https://leetcode-cn.com/problems/combination-sum/ 
# combination sum 
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        def backtrack(candidates,cur_sum,track, step):
            if cur_sum == 0:
                result.append(track[:])
                return
            if cur_sum < 0:
                return
            for i in range(step, len(candidates)):
                # cur_sum = cur_sum - candidates[i]
                track.append(candidates[i])
                backtrack(candidates,cur_sum - candidates[i],track, i)
                track.pop()
        cur_sum = target
        backtrack(candidates,cur_sum,[], 0)
        return result