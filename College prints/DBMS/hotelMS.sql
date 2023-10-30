use hotel_management_system;

create table customer(
cus_id varchar(10) primary key,
name_ varchar(20) not null,
email varchar(20) not null,
phone_no varchar(20) not null,
identity_type varchar(20) not null,
identity_no varchar(20) not null
);


