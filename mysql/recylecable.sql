# Write your MySQL query statement below

-- https://leetcode.com/problems/recyclable-and-low-fat-products/description/?envType=study-plan-v2&envId=top-sql-50
SELECT product_id FROM Products WHERE low_fats='Y' AND recyclable='Y';

-- we can also mention order by asc for sorted list
SELECT product_id FROM Products WHERE low_fats = 'Y' AND recyclable = 'Y' ORDER BY 1 ASC
