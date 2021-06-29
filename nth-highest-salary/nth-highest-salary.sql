CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
   DECLARE M INT;
SET M=N;
  RETURN (
      # Write your MySQL query statement below.
      Select distinct e1.Salary from Employee e1 where M = (Select count(distinct (e2.salary)) from Employee e2 where e1.Salary<=e2.Salary)
  );
END