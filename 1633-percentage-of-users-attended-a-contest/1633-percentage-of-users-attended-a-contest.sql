# Write your MySQL query statement below
SELECT r.contest_id , ROUND(COUNT(DISTINCT r.user_id)*100.0/(SELECT COUNT(u.user_id) FROM Users u),2) AS percentage
FROM Register AS r
JOIN Users AS u
GROUP BY r.contest_id
ORDER BY percentage DESC , r.contest_id 