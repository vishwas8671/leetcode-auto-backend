# Write your MySQL query statement below
SELECT 
ROUND (SUM(player_login) / COUNT(DISTINCT player_id), 2) AS FRACTION 
FROM
(SELECT player_id, datediff(event_date, min(event_date) over (partition by player_id)) = 1 AS player_login FROM Activity) AS new_table