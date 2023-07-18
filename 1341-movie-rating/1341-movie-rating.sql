# Write your MySQL query statement below
SELECT name as results
FROM
( 
  SELECT u.name, COUNT(mr.user_id) AS count
  FROM Users AS u
  JOIN MovieRating AS mr ON u.user_id = mr.user_id
  GROUP BY u.name
  ORDER BY count DESC, u.name
  LIMIT 1
) a
UNION ALL
SELECT title as results
FROM
(
  SELECT m.title, AVG(mr.rating) AS max_rating
  FROM Movies AS M
  JOIN MovieRating AS mr ON m.movie_id = mr.movie_id
  WHERE mr.created_at >= '2020-02-01' AND mr.created_at <= '2020-02-28'
  GROUP BY m.title
  ORDER BY max_rating DESC, title
  LIMIT 1
) b
