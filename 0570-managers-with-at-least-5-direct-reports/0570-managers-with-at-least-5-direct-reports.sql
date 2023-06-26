# Write your MySQL query statement below
SELECT a.Name
From Employee a, Employee b
Where a.Id = b.ManagerId
Group By b.ManagerId
Having Count(*) >= 5