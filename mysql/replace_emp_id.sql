# Write your MySQL query statement below
-- https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/?envType=study-plan-v2&envId=top-sql-50
SELECT  EmployeeUNI.unique_id,Employees.name 
  FROM Employees LEFT JOIN EmployeeUNI 
ON Employees.id = EmployeeUNI.id;