# Write your MySQL query statement below
SELECT e.employee_id , e.name , e2.reports_count , ROUND(e2.average_age) AS average_age
FROM Employees AS e
JOIN (
    SELECT reports_to , COUNT(*) AS reports_count , AVG(age) AS average_age
    FROM Employees
    GROUP BY reports_to
) e2 ON e2.reports_to = e.employee_id
ORDER BY employee_id