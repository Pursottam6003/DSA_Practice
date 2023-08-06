-- https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/solutions/2533481/3-different-solutions-join-not-in-not-exists/?envType=study-plan-v2&envId=top-sql-50
# Write your MySQL query statement below
SELECT customer_id, COUNT(v.visit_id) as count_no_trans FROM Visits v
LEFT JOIN Transactions t ON v.visit_id = t.visit_id 
WHERE transaction_id IS NULL 
GROUP BY customer_id;


-- another approach 
SELECT customer_id, COUNT(visit_id) as count_no_trans 
FROM Visits
WHERE visit_id NOT IN (
	SELECT visit_id FROM Transactions
	)
GROUP BY customer_id

-- another approach 
SELECT customer_id, COUNT(visit_id) as count_no_trans 
FROM Visits v
WHERE NOT EXISTS (
	SELECT visit_id FROM Transactions t 
	WHERE t.visit_id = v.visit_id
	)
GROUP BY customer_id