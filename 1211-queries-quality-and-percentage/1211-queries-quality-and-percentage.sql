# Write your MySQL query statement below
SELECT  
query_name ,
round(avg(rating/position),2) AS quality ,
round(avg(if(rating < 3, 1, 0) * 100) ,2) AS poor_query_percentage
FROM Queries
WHERE query_name is not NULL
GROUP BY query_name