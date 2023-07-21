# Write your MySQL query statement below
SELECT d1.name AS department, e1.name AS employee , e1.salary AS salary
FROM Employee AS e1
JOIN Department AS d1 ON d1.id = e1.departmentId
WHERE 
3> (
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee AS e2
    WHERE e2.salary > e1.salary AND e1.departmentId = e2.departmentId
)