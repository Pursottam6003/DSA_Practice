# Write your MySQL query statement below
-- https://leetcode.com/problems/find-customer-referee/description/?envType=study-plan-v2&envId=top-sql-50
SELECT name FROM Customer WHERE referee_id is NULL OR referee_id !='2';

