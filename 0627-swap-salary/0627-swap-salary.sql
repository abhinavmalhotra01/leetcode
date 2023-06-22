# Write your MySQL query statement below
UPDATE Salary 
SET sex =
    case sex 
    when 'm' then 'f'
    when 'f' then 'm'
    else sex
    end;
