select 
    name, bonus 
from 
    Employee e
left join
    Bonus b 
on
    e.empId = b.empId 
where
    b.bonus is null or b.bonus < 1000;