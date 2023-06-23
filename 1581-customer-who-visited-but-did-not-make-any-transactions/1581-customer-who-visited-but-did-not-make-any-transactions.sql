# Write your MySQL query statement below
SELECT DISTINCT(c.customer_id) , COUNT(c.customer_id) AS count_no_trans
FROM Visits as c 
LEFT JOIN Transactions as t
ON c.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY c.customer_id
