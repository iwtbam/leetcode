# https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/ 
# zui xiao de kge shu lcof 
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:

        if k == 0:
            return []
        heap = []
        for num in arr:
            if len(heap) < k:
                heapq.heappush(heap, -num)
            else:
                if -num > heap[0]:
                    # heapq.heappop(heap)
                    heapq.heapreplace(heap, -num)

        return [ -val for val in heap]

"""

Ä¬ÈÏĞ¡¸ù¶Ñ

"""