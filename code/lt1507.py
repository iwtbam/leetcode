# https://leetcode-cn.com/problems/reformat-date/ 
# reformat date 
class Solution:
    def reformatDate(self, date: str) -> str:
        months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        indexs = list(range(1, 13, 1))
        months = dict(zip(months, indexs))

        
        new_date = date.split(" ")
        d = int(new_date[0][0:-2])
        m = months[new_date[1]]
        
        
        return "{0}-{1:02d}-{2:02d}".format(new_date[2], m, d)