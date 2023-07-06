# Write your MySQL query statement below
SELECT MAX(s.num) AS num
FROM (
    SELECT num , COUNT(*) AS cnt
    FROM MyNumbers
    GROUP BY num
    HAVING cnt=1
) AS s