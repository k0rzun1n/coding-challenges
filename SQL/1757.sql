-- CREATE TYPE mood AS ENUM ('sad', 'ok', 'happy');
-- CREATE TYPE lofat AS ENUM ('Y', 'N');
-- CREATE TYPE recyc AS ENUM ('Y', 'N');

Create table If Not Exists Products (product_id int, low_fats lofat, recyclable recyc);
Truncate table Products;
insert into Products (product_id, low_fats, recyclable) values ('0', 'Y', 'N');
insert into Products (product_id, low_fats, recyclable) values ('1', 'Y', 'Y');
insert into Products (product_id, low_fats, recyclable) values ('2', 'N', 'Y');
insert into Products (product_id, low_fats, recyclable) values ('3', 'Y', 'Y');
insert into Products (product_id, low_fats, recyclable) values ('4', 'N', 'N');

select product_id FROM products where low_fats = 'Y' and recyclable = 'Y';


-- select * FROM shoes where 0=9;
-- select row_to_json
-- INSERT INTO shoes VALUES 

