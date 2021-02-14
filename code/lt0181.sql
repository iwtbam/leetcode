// https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/
// employees earning more than their managers
# Write your MySQL query statement below

select 
    Name Employee 
from Employee  as a
where
    Salary > (select Salary from Employee  where Id = a.ManagerId);