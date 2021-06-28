# Write your MySQL query statement below
select  FirstName, LastName, City, State from Person P left JOIN Address A on P.PersonId = A.PersonId;