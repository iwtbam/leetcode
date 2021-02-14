# https://leetcode-cn.com/problems/reformat-phone-number/ 
# reformat phone number 
class Solution:
    def reformatNumber(self, number: str) -> str:
        data = ''.join(list(filter(lambda x : x!='', re.split('[-\s]', number))))
        length = len(data)
        if length <= 3:
            return ''.join(data)
        res = 4 if length % 3 == 1 else length % 3
        n = length - res
        item = []
        seg = n // 3
        for i in range(seg):
            item.append(''.join(data[i * 3 : i * 3 + 3]))
        
        while res >= 2:
            item.append(''.join(data[n : n + 2]))
            n += 2
            res -= 2
        
        return '-'.join(item)
        
        
        