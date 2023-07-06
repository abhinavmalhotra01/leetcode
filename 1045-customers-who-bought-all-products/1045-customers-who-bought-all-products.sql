# Write your MySQL query statement below
SELECT c1.customer_id
FROM Customer AS c1
GROUP BY c1.customer_id
HAVING COUNT(DISTINCT c1.product_key) = (
    SELECT COUNT(*)
    FROM Product
)