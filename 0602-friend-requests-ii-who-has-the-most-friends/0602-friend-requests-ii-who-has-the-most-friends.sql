# Write your MySQL query statement below
# SELECT requester_id AS id,
# (SELECT COUNT(*) FROM RequestAccepted
#  WHERE id =requester_id OR id=accepter_id
# ) AS num
# FROM RequestAccepted
# GROUP BY requester_id
# ORDER BY num DESC LIMIT 1

SELECT user_id AS id, COUNT(*) AS num
FROM
(
    SELECT requester_id AS user_id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS user_id
    FROM RequestAccepted
) AS all_users
GROUP BY user_id
HAVING num = (
    SELECT COUNT(*) AS max_friends
    FROM
    (
        SELECT requester_id AS user_id
        FROM RequestAccepted
        UNION ALL
        SELECT accepter_id AS user_id
        FROM RequestAccepted
    ) AS all_users
    GROUP BY user_id
    ORDER BY max_friends DESC
    LIMIT 1
);