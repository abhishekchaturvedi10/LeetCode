# Write your MySQL query statement below

select d.name as 'Department', e.name as 'Employee', Salary from Department d, Employee e where d.Id=e.DepartmentId and (e.DepartmentId, Salary) in (select DepartmentId, max(Salary) from Employee group by DepartmentId);