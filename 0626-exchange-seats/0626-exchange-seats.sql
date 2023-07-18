# Write your MySQL query statement below
SELECT
IF (s.id IN (SELECT MAX(id) FROM Seat),IF (MOD(s.id,2)=0 , s.id-1,s.id),IF (MOD(s.id,2)=0 , s.id-1,s.id+1)) AS id,
s.student
FROM Seat AS s
ORDER BY id