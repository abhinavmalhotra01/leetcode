# Write your MySQL query statement below
SELECT d.name AS Department , e.name AS Employee , e.salary AS Salary 
FROM Employee AS e 
JOIN Department AS D
ON e.departmentId = d.id
WHERE (e.departmentId, salary) IN (
    SELECT departmentId , MAX(salary)
    FROM Employee
    GROUP BY departmentId
)