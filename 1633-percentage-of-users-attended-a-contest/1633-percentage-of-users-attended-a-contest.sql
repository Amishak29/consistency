select b.contest_id, ROUND(count(distinct b.user_id)*100/(select count(user_id) from Users),2) as percentage from Users a JOIN Register b ON a.user_id=b.user_id group by contest_id order by percentage desc,contest_id;

# select 
# contest_id, 
# round(count(distinct user_id) * 100 /(select count(user_id) from Users) ,2) as percentage
# from  Register
# group by contest_id
# order by percentage desc,contest_id
