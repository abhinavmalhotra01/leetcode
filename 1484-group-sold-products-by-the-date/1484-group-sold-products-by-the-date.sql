# Write your MySQL query statement below
select sell_date, count(distinct product) as num_sold,
GROUP_CONCAT( DISTINCT product order by product ) as products
from Activities group by sell_Date order by sell_date asc;
