# Write your MySQL query statement below

select id, movie, description, rating from Cinema where description not like '%boring%' and LEFT(id, 1) % 2 <> 0 order by rating desc;