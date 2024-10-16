#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/exception.h>
#include "jdbc/mysql_driver.h"
//#include <windows.h>
#include <iostream>

//int main() {
int __main() {
    //SetConsoleOutputCP(CP_UTF8);

    try {
        // 注册 MySQL 驱动程序
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("tcp://公网ip:3306", "root", "密码");
        // 设置字符集
        con->setClientOption("character_set_results", "utf8mb4");

        sql::Statement* stmt = con->createStatement();
        stmt->execute("USE codertest"); // 切换到 codertest 数据库

  
        //stmt->execute("DROP TABLE IF EXISTS registration"); //删除表
        //stmt->execute("DROP TABLE IF EXISTS students"); //删除表
        //stmt->execute("DROP TABLE IF EXISTS academy"); //删除表
        //stmt->execute("DROP TABLE IF EXISTS events"); //删除表
     
        //// 查看数据库的默认字符集
        //std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT DEFAULT_CHARACTER_SET_NAME FROM information_schema.SCHEMATA WHERE SCHEMA_NAME = 'codertest'"));
        //while (res->next()) {
        //    std::cout << "Default character set: " << res->getString(1) << std::endl;
        //}

        //// 查看表的状态
        //res.reset(stmt->executeQuery("SHOW TABLE STATUS WHERE Name = 'events'"));
        //while (res->next()) {
        //    std::cout << "Table: " << res->getString("Name") << ", Character Set: " << res->getString("Collation") << std::endl;
        //}
        
 //--------------------------------------------------------------------------------------------------------------------------------------//
         添加运动项目表
        stmt->execute("create table if not exists events (event_id int primary key auto_increment," // 运动项目id，主键，自动递增
            "event_name varchar(100) not null)"); // 运动项目名称

        // 添加学院表
        stmt->execute("create table if not exists academy (academy_id int primary key auto_increment," // 学院id，主键，自动递增
            "academy_name varchar(100) not null)"); // 学院名称

        // 添加学生表
        stmt->execute("create table if not exists students (student_id int primary key auto_increment," // 序号，主键，自动递增
            "student_name varchar(255) not null," // 学生姓名
            "gender enum('male','female') not null," // 性别
            "academy_id int," // 学院id，外键
            "constraint student_academy foreign key (academy_id) references academy(academy_id))");

        // 添加报名表
        stmt->execute("create table if not exists registration (student_id int," // 学生id，外键
            "academy_id int," // 学院id，外键
            "event_id int," // 运动项目id，外键
            "score int," // 该学生的该项目分数
            "constraint fk_student foreign key(student_id) references students(student_id),"
            "constraint fk_academy foreign key(academy_id) references academy(academy_id),"
            "constraint fk_event foreign key(event_id) references events(event_id))");

        // 添加运动项目
        stmt->execute("insert into events (event_name) values ('100m')");
        stmt->execute("insert into events (event_name) values ('200m')");
        stmt->execute("insert into events (event_name) values ('tiaoyuan')");
        stmt->execute("insert into events (event_name) values ('tiaogao')");

        // 添加学院
        stmt->execute("insert into academy (academy_name) values ('dianzi')");
        stmt->execute("insert into academy (academy_name) values ('chuanbo')");
        stmt->execute("insert into academy (academy_name) values ('tongxin')");
        stmt->execute("insert into academy (academy_name) values ('jidian')");
        stmt->execute("insert into academy (academy_name) values ('zhonge')");
        stmt->execute("insert into academy (academy_name) values ('shuxue')");

//--------------------------------------------------------------------------------------------------------------------------------------//
// 
// 
        // 添加学生
        //stmt->execute("insert into students (student_name, gender, academy_id) values ('zhao', 'male', 1)");
        //stmt->execute("insert into students (student_name, gender, academy_id) values ('qian', 'female', 1)");
        //stmt->execute("insert into students (student_name, gender, academy_id) values ('sun', 'male', 1)");
        //stmt->execute("insert into students (student_name, gender, academy_id) values ('li', 'female', 1)");
   
        // 添加报名
        //stmt->execute("insert into registration (student_id, event_id) values (1, 1)"); // john doe 报名100米
        //stmt->execute("insert into registration (student_id, event_id) values (2, 2)"); // jane smith 报名200米

        // 清理资源
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQL state: " << e.getSQLState() << std::endl;
        std::cerr << "Error message: " << e.what() << std::endl;
    }

    return 0;
}
