#include<iostream>
#include<string>
#include<stdlib.h>

#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/exception.h>
#include "jdbc/mysql_driver.h"

using namespace std;

// 全局变量
sql::Statement* stmt; // 全局变量声明


//////////////////////菜单//////////////////
int menu() {
    int n;
    system("cls"); //清屏
    cout << "运动会管理系统" << endl;
    cout << "----------------" << endl;
    cout << "1.【各学院-各项】分数总览" << endl;
    cout << "2.【各学院-男女】总分总览" << endl;
    cout << "3.学院总分名次查询" << endl;
    cout << "4.【各项目】运动员排名查询" << endl;
    cout << "5.运动员信息录入" << endl;
    cout << "6.项目成绩录入" << endl;
    cout << "7.结束程序" << endl;
    cout << "请输入所需功能前的序号:";
    cin >> n;

    while (n < 0 || n > 7) {
        cout << "请重新输入所需功能前的序号，eg:1"<<endl;
        cin >> n;
    }

    return n;
}

//1.【各学院-各项】分数总览
void scoreAcademy(sql::Statement* stmt) {
    system("cls"); //清屏
    cout << "【各学院-各项】分数总览" << endl;
    cout << "----------------" << endl;
    string output_message;

    output_message = "SELECT a.academy_name,e.event_name, SUM(r.score) AS total_score FROM registration r JOIN students s ON r.student_id = s.student_id JOIN academy a ON r.academy_id JOIN events e ON r.event_id = e.event_id GROUP BY a.academy_name, e.event_name ORDER BY a.academy_name, e.event_name";
    sql::ResultSet* res = stmt->executeQuery(output_message);
    cout << "学院" << "\t项目" << "\t总分" << endl;
    while (res->next()) {
        cout << res->getString("academy_name")
            << "\t" << res->getString("event_name")
            << "\t" << res->getInt("total_score") << endl;
    }
    delete res; // 清理资源


    int temp;
    cout << "返回请输入1\n";
    cin >> temp;
}

//2.【各学院-男女】总分总览
void scoreGender(sql::Statement* stmt) {
    system("cls"); //清屏
    cout << "【各学院-男女】总分总览" << endl;
    cout << "----------------" << endl;
    string output_message;
    // 总分
    output_message = "SELECT a.academy_name, SUM(r.score) AS total_score, SUM(CASE WHEN s.gender = 'male' THEN r.score ELSE 0 END) AS total_male_score, SUM(CASE WHEN s.gender = 'female' THEN r.score ELSE 0 END) AS total_female_score FROM registration r JOIN students s ON r.student_id = s.student_id JOIN academy a ON r.academy_id = a.academy_id GROUP BY a.academy_name";
    sql::ResultSet* res = stmt->executeQuery(output_message);

    cout << "学院" << "\t总分" << "\t男子总分" << "\t女子总分" << endl;
    while (res->next()) {
        cout << res->getString("academy_name")
            << "\t " << res->getInt("total_score")
            << "\t " << res->getInt("total_male_score")
            << "\t\t " << res->getInt("total_female_score") << endl;
    }

    delete res; // 清理资源


    int temp;
    cout << "返回请输入1\n";
    cin >> temp;
}

//3.学院总分名次查询
void rankAcademy(sql::Statement* stmt) {
    system("cls"); //清屏
    cout << "学院总分名次查询" << endl;
    cout << "----------------" << endl;
    string output_message;

    output_message = "SELECT a.academy_name, SUM(r.score) AS total_score FROM registration r JOIN academy a ON r.academy_id = a.academy_id GROUP BY a.academy_name ORDER BY total_score DESC";
    sql::ResultSet* res = stmt->executeQuery(output_message);
    cout << "学院" << "\t总分" << endl;
    while (res->next()) {
        cout << res->getString("academy_name")
            << "\t" << res->getInt("total_score") << endl;
    }
    delete res; // 清理资源



    int temp;
    cout << "返回请输入1\n";
    cin >> temp;
}

//4.【各项目】运动员排名查询
void rankAthlete(sql::Statement* stmt) {
    system("cls"); //清屏
    cout << "【各项目】运动员排名查询" << endl;
    cout << "----------------" << endl;
    cout << "请输入录入项目序号" << endl;
    cout << "1.100m 2.200m 3.跳远 4.跳高" << endl;
    string event_id;
    cin >> event_id;
    string output_message = "SELECT s.student_name, r.score FROM registration r JOIN students s ON r.student_id = s.student_id WHERE r.event_id = "+ event_id +" ORDER BY score DESC";
    sql::ResultSet* res = stmt->executeQuery(output_message);
    cout << "姓名\t分数" << endl;
    while (res->next()) {
        cout << res->getString("student_name")
            << "\t" << res->getInt("score") << endl;
    }

    int temp;
    cout << "返回请输入1\n";
    cin >> temp;
}


//5.运动员信息录入
void enterGender(sql::Statement* stmt) {
    int n;
    system("cls"); //清屏
    cout << "运动员信息录入"<<endl;
    cout << "----------------" << endl;
    cout << "1.添加运动员" << endl;
    cout << "2.删除运动员" << endl;
    cout << "3.修改运动员信息" << endl;
    cout << "4.查询所有运动员报名信息" << endl;
    cout << "请输入所需功能前的序号:";
    cin >> n;

    while (n < 0 || n > 4) {
        cout << "请重新输入所需功能前的序号，eg:1" << endl;
        cin >> n;
    }

    // 1.添加运动员
    if (n == 1) {
        cout << "添加运动员" << endl;
        string student_name;
        string gender;
        string academy_id;
        string event_id;
        cout << "请输入姓名：";
        cin >> student_name;
        cout << "请输入性别（male/female）：";
        cin >> gender;
        cout << "请输入学院id" << endl;
        cout << "1.电子工程 2.传播 3.通信工程 4.机电工程 5.中俄 6.数学" << endl;
        cin >> academy_id;
        cout << "请输入填报项目序号" << endl;
        cout << "1.100m 2.200m 3.跳远 4.跳高" << endl;
        cin >> event_id;
        
        // 向students表添加
        string add_message2students;
        add_message2students = "insert into students(student_name, gender, academy_id) values('" + student_name + "', '" + gender + "',' " + academy_id + "')";

        stmt->execute(add_message2students);
        sql::ResultSet* res = stmt->executeQuery("SELECT LAST_INSERT_ID() AS id");
        res->next();
        int student_id = res->getInt("id");
        // 向registration表添加
        string add_message2registration;
        add_message2registration = "insert into registration(student_id, academy_id, event_id, score) values('" + to_string(student_id) + "', '" + academy_id + "', '" + event_id + "', '0')";
        stmt->execute(add_message2registration);

        cout << "添加成功！你的序号为：";
        cout << student_id << endl;
        delete res;
    }

    // 2.删除运动员
    else if (n == 2) {
        cout << "删除运动员" << endl;
        cout << "请输入运动员序号" << endl;
        string num_athlete;
        cin >> num_athlete;
        string del_message;

        try {
            del_message = "DELETE FROM registration WHERE student_id = " + num_athlete;
            stmt->execute(del_message);
            del_message = "DELETE FROM students WHERE student_id = " + num_athlete;
            stmt->execute(del_message);

            cout << "删除成功" << endl;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error code: " << e.getErrorCode() << std::endl;
            std::cerr << "SQL state: " << e.getSQLState() << std::endl;
            std::cerr << "Error message: " << e.what() << std::endl;
        }

    }
    // 3.修改运动员报名信息
    else if (n == 3) {
        cout << "修改运动员报名信息" << endl;
        cout << "请输入运动员序号" << endl;
        string student_id;
        cin >> student_id;
        cout << "请输入要修改为的项目序号" << endl;
        cout << "1.100m 2.200m 3.跳远 4.跳高" << endl;
        string event_id;
        cin >> event_id;
        string update_message;
        update_message = "UPDATE registration SET event_id = " + event_id + " WHERE student_id = " + student_id;

        stmt->execute(update_message);
        cout << "修改成功！" << endl;

    }
    // 4.查询所有运动员报名信息
    else {
        cout << "查询所有运动员报名信息" << endl;
        string select_message;
        try {
            select_message = "SELECT registration.student_id, students.student_name, students.gender, events.event_name FROM registration JOIN students ON registration.student_id = students.student_id JOIN events ON registration.event_id = events.event_id";
            cout << "序号\t姓名\t性别\t项目" << endl;
            sql::ResultSet* res = stmt->executeQuery(select_message);
            while (res->next()) {
                cout << res->getString("student_id") << "\t" << res->getString("student_name")
                    << " \t" << res->getString("gender") << "\t" << res->getString("event_name") << endl;
            }
            delete res;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error code: " << e.getErrorCode() << std::endl;
            std::cerr << "SQL state: " << e.getSQLState() << std::endl;
            std::cerr << "Error message: " << e.what() << std::endl;
        }
    }   

    int temp;
    cout << "返回请输入1\n";
    cin >> temp;
}

//6.项目成绩录入
void enterScore(sql::Statement* stmt) {
    string event_id;
    system("cls"); //清屏
    cout << "项目成绩录入" << endl;
    cout << "----------------" << endl;
    cout << "请输入录入项目序号" << endl;
    cout << "1.100m 2.200m 3.跳远 4.跳高" << endl;
    cin >> event_id;
    string output_message;
    output_message = "SELECT registration.student_id FROM registration WHERE event_id = "+ event_id;
    cout << "报名该项目的学生为：" << endl;
    try {
        sql::ResultSet* res = stmt->executeQuery(output_message);
        while (res->next()) {
            cout << res->getString("student_id") << endl;
        }
        delete res;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQL state: " << e.getSQLState() << std::endl;
        std::cerr << "Error message: " << e.what() << std::endl;
    }

    cout << "请输入对应得分" << endl;
    sql::ResultSet* res = stmt->executeQuery(output_message);
    while (res->next()) {
        string score;
        string student_id = res->getString("student_id");
        cout << student_id << ": ";
        cin >> score;
        string input_message;
        input_message = "UPDATE registration SET score = " + score + " WHERE student_id = " + student_id;
        stmt->execute(input_message);
    }
    delete res;
 
    cout << "录入成功！" << endl;

    int temp;
    cout << "返回请输入1\n";
    cin >> temp;
}

int main() {
//int __main(){
    // 注册 MySQL 驱动程序
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    sql::Connection* con = driver->connect("tcp://公网ip:3306", "root", "密码");
    // 设置字符集
    con->setClientOption("character_set_results", "utf8mb4");

    sql::Statement* stmt = con->createStatement();
    stmt->execute("USE codertest"); // 切换到 codertest 数据库

    int n = 1;

    while (n > 0 && n < 7) {
        n = menu();
        switch (n) {
        case 1: scoreAcademy(stmt); break;
        case 2: scoreGender(stmt); break;
        case 3: rankAcademy(stmt); break;
        case 4: rankAthlete(stmt); break;
        case 5: enterGender(stmt); break;
        case 6: enterScore(stmt); break;
        }
    }
    delete stmt;
    delete con;
    

	return 0;
}