# Write your MySQL query statement below
SELECT p.product_name , SUM(o.unit) AS unit
FROM Products AS p JOIN Orders AS o using (product_id)
WHERE MONTH(order_date) = '02' AND YEAR(order_date) = '2020'
GROUP BY p.product_name
HAVING unit>=100