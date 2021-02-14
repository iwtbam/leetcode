// https://leetcode-cn.com/problems/combine-two-tables/
// combine two tables
# Write your MySQL query statement below
select
    FirstName, LastName, City, State
from 
    Person p
left join
    Address a
on
    p.PersonId = a.PersonId;