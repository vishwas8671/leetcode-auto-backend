# Write your MySQL query statement below
SELECT v.customer_id , count(v.visit_id) as  count_no_trans
FROM visits v
left join transactions t
on t.visit_id = v.visit_id
where t.transaction_id is null
group by v.customer_id