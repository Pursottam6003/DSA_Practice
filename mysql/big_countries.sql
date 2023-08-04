# Write your MySQL query statement below
SELECT name,population,area FROM World WHERE population>='25000000' OR area>='3000000'

-- another approach 
# Write your MySQL query statement below

SELECT 
    name,population,area 
FROM 
    world
WHERE 
    area >='3000000'
    OR population >='25000000'