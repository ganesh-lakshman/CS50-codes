

select distinct(name) from people where id in
(select distinct(person_id) from stars where movie_id in
(select movie_id from stars where person_id in
 (select id from people where name = "Kevin Bacon"
 and birth = 1958))) and name != "Kevin Bacon"

/*select distinct(person_id) from stars where movie_id in
(select movie_id from stars where person_id in
(select id from people where name = "Kevin Bacon"
 and birth = 1958))*/
