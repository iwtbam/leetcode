# https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/ 
# dui lie de zui da zhi lcof 
class MaxQueue:

    def __init__(self):
        self.elements = collections.deque()
        self.max_val = collections.deque()

    def max_value(self) -> int:
        return -1 if len(self.max_val) == 0 else self.max_val[0]

    def push_back(self, value: int) -> None:
        self.elements.append(value)
        while len(self.max_val) and value > self.max_val[-1]:
            self.max_val.pop()
        self.max_val.append(value)
 
    def pop_front(self) -> int:
        if len(self.elements) == 0:
            return -1;
        ret = self.elements.popleft()
        while len(self.max_val) and ret == self.max_val[0]:
            self.max_val.popleft()
        return ret






# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()