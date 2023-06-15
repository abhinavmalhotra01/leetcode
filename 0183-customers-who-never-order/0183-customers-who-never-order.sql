# Write your MySQL query statement below
SELECT c1.name  as 'Customers'
FROM customers as c1 
WHERE c1.id not in (
    SELECT customerId from orders
)