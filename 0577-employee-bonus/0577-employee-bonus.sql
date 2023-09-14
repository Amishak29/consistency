select e.name , b.bonus from Employee e left join Bonus b on e.empID=b.empId where bonus<1000 OR bonus IS NULL;
