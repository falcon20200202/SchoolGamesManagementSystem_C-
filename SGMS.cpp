#include<iostream>
#include<string>
#include<stdlib.h>

#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/exception.h>
#include "jdbc/mysql_driver.h"

using namespace std;

// ȫ�ֱ���
sql::Statement* stmt; // ȫ�ֱ�������


//////////////////////�˵�//////////////////
int menu() {
    int n;
    system("cls"); //����
    cout << "�˶������ϵͳ" << endl;
    cout << "----------------" << endl;
    cout << "1.����ѧԺ-�����������" << endl;
    cout << "2.����ѧԺ-��Ů���ܷ�����" << endl;
    cout << "3.ѧԺ�ܷ����β�ѯ" << endl;
    cout << "4.������Ŀ���˶�Ա������ѯ" << endl;
    cout << "5.�˶�Ա��Ϣ¼��" << endl;
    cout << "6.��Ŀ�ɼ�¼��" << endl;
    cout << "7.��������" << endl;
    cout << "���������蹦��ǰ�����:";
    cin >> n;

    while (n < 0 || n > 7) {
        cout << "�������������蹦��ǰ����ţ�eg:1"<<endl;
        cin >> n;
    }

    return n;
}

//1.����ѧԺ-�����������
void scoreAcademy(sql::Statement* stmt) {
    system("cls"); //����
    cout << "����ѧԺ-�����������" << endl;
    cout << "----------------" << endl;
    string output_message;

    output_message = "SELECT a.academy_name,e.event_name, SUM(r.score) AS total_score FROM registration r JOIN students s ON r.student_id = s.student_id JOIN academy a ON r.academy_id JOIN events e ON r.event_id = e.event_id GROUP BY a.academy_name, e.event_name ORDER BY a.academy_name, e.event_name";
    sql::ResultSet* res = stmt->executeQuery(output_message);
    cout << "ѧԺ" << "\t��Ŀ" << "\t�ܷ�" << endl;
    while (res->next()) {
        cout << res->getString("academy_name")
            << "\t" << res->getString("event_name")
            << "\t" << res->getInt("total_score") << endl;
    }
    delete res; // ������Դ


    int temp;
    cout << "����������1\n";
    cin >> temp;
}

//2.����ѧԺ-��Ů���ܷ�����
void scoreGender(sql::Statement* stmt) {
    system("cls"); //����
    cout << "����ѧԺ-��Ů���ܷ�����" << endl;
    cout << "----------------" << endl;
    string output_message;
    // �ܷ�
    output_message = "SELECT a.academy_name, SUM(r.score) AS total_score, SUM(CASE WHEN s.gender = 'male' THEN r.score ELSE 0 END) AS total_male_score, SUM(CASE WHEN s.gender = 'female' THEN r.score ELSE 0 END) AS total_female_score FROM registration r JOIN students s ON r.student_id = s.student_id JOIN academy a ON r.academy_id = a.academy_id GROUP BY a.academy_name";
    sql::ResultSet* res = stmt->executeQuery(output_message);

    cout << "ѧԺ" << "\t�ܷ�" << "\t�����ܷ�" << "\tŮ���ܷ�" << endl;
    while (res->next()) {
        cout << res->getString("academy_name")
            << "\t " << res->getInt("total_score")
            << "\t " << res->getInt("total_male_score")
            << "\t\t " << res->getInt("total_female_score") << endl;
    }

    delete res; // ������Դ


    int temp;
    cout << "����������1\n";
    cin >> temp;
}

//3.ѧԺ�ܷ����β�ѯ
void rankAcademy(sql::Statement* stmt) {
    system("cls"); //����
    cout << "ѧԺ�ܷ����β�ѯ" << endl;
    cout << "----------------" << endl;
    string output_message;

    output_message = "SELECT a.academy_name, SUM(r.score) AS total_score FROM registration r JOIN academy a ON r.academy_id = a.academy_id GROUP BY a.academy_name ORDER BY total_score DESC";
    sql::ResultSet* res = stmt->executeQuery(output_message);
    cout << "ѧԺ" << "\t�ܷ�" << endl;
    while (res->next()) {
        cout << res->getString("academy_name")
            << "\t" << res->getInt("total_score") << endl;
    }
    delete res; // ������Դ



    int temp;
    cout << "����������1\n";
    cin >> temp;
}

//4.������Ŀ���˶�Ա������ѯ
void rankAthlete(sql::Statement* stmt) {
    system("cls"); //����
    cout << "������Ŀ���˶�Ա������ѯ" << endl;
    cout << "----------------" << endl;
    cout << "������¼����Ŀ���" << endl;
    cout << "1.100m 2.200m 3.��Զ 4.����" << endl;
    string event_id;
    cin >> event_id;
    string output_message = "SELECT s.student_name, r.score FROM registration r JOIN students s ON r.student_id = s.student_id WHERE r.event_id = "+ event_id +" ORDER BY score DESC";
    sql::ResultSet* res = stmt->executeQuery(output_message);
    cout << "����\t����" << endl;
    while (res->next()) {
        cout << res->getString("student_name")
            << "\t" << res->getInt("score") << endl;
    }

    int temp;
    cout << "����������1\n";
    cin >> temp;
}


//5.�˶�Ա��Ϣ¼��
void enterGender(sql::Statement* stmt) {
    int n;
    system("cls"); //����
    cout << "�˶�Ա��Ϣ¼��"<<endl;
    cout << "----------------" << endl;
    cout << "1.����˶�Ա" << endl;
    cout << "2.ɾ���˶�Ա" << endl;
    cout << "3.�޸��˶�Ա��Ϣ" << endl;
    cout << "4.��ѯ�����˶�Ա������Ϣ" << endl;
    cout << "���������蹦��ǰ�����:";
    cin >> n;

    while (n < 0 || n > 4) {
        cout << "�������������蹦��ǰ����ţ�eg:1" << endl;
        cin >> n;
    }

    // 1.����˶�Ա
    if (n == 1) {
        cout << "����˶�Ա" << endl;
        string student_name;
        string gender;
        string academy_id;
        string event_id;
        cout << "������������";
        cin >> student_name;
        cout << "�������Ա�male/female����";
        cin >> gender;
        cout << "������ѧԺid" << endl;
        cout << "1.���ӹ��� 2.���� 3.ͨ�Ź��� 4.���繤�� 5.�ж� 6.��ѧ" << endl;
        cin >> academy_id;
        cout << "���������Ŀ���" << endl;
        cout << "1.100m 2.200m 3.��Զ 4.����" << endl;
        cin >> event_id;
        
        // ��students�����
        string add_message2students;
        add_message2students = "insert into students(student_name, gender, academy_id) values('" + student_name + "', '" + gender + "',' " + academy_id + "')";

        stmt->execute(add_message2students);
        sql::ResultSet* res = stmt->executeQuery("SELECT LAST_INSERT_ID() AS id");
        res->next();
        int student_id = res->getInt("id");
        // ��registration�����
        string add_message2registration;
        add_message2registration = "insert into registration(student_id, academy_id, event_id, score) values('" + to_string(student_id) + "', '" + academy_id + "', '" + event_id + "', '0')";
        stmt->execute(add_message2registration);

        cout << "��ӳɹ���������Ϊ��";
        cout << student_id << endl;
        delete res;
    }

    // 2.ɾ���˶�Ա
    else if (n == 2) {
        cout << "ɾ���˶�Ա" << endl;
        cout << "�������˶�Ա���" << endl;
        string num_athlete;
        cin >> num_athlete;
        string del_message;

        try {
            del_message = "DELETE FROM registration WHERE student_id = " + num_athlete;
            stmt->execute(del_message);
            del_message = "DELETE FROM students WHERE student_id = " + num_athlete;
            stmt->execute(del_message);

            cout << "ɾ���ɹ�" << endl;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error code: " << e.getErrorCode() << std::endl;
            std::cerr << "SQL state: " << e.getSQLState() << std::endl;
            std::cerr << "Error message: " << e.what() << std::endl;
        }

    }
    // 3.�޸��˶�Ա������Ϣ
    else if (n == 3) {
        cout << "�޸��˶�Ա������Ϣ" << endl;
        cout << "�������˶�Ա���" << endl;
        string student_id;
        cin >> student_id;
        cout << "������Ҫ�޸�Ϊ����Ŀ���" << endl;
        cout << "1.100m 2.200m 3.��Զ 4.����" << endl;
        string event_id;
        cin >> event_id;
        string update_message;
        update_message = "UPDATE registration SET event_id = " + event_id + " WHERE student_id = " + student_id;

        stmt->execute(update_message);
        cout << "�޸ĳɹ���" << endl;

    }
    // 4.��ѯ�����˶�Ա������Ϣ
    else {
        cout << "��ѯ�����˶�Ա������Ϣ" << endl;
        string select_message;
        try {
            select_message = "SELECT registration.student_id, students.student_name, students.gender, events.event_name FROM registration JOIN students ON registration.student_id = students.student_id JOIN events ON registration.event_id = events.event_id";
            cout << "���\t����\t�Ա�\t��Ŀ" << endl;
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
    cout << "����������1\n";
    cin >> temp;
}

//6.��Ŀ�ɼ�¼��
void enterScore(sql::Statement* stmt) {
    string event_id;
    system("cls"); //����
    cout << "��Ŀ�ɼ�¼��" << endl;
    cout << "----------------" << endl;
    cout << "������¼����Ŀ���" << endl;
    cout << "1.100m 2.200m 3.��Զ 4.����" << endl;
    cin >> event_id;
    string output_message;
    output_message = "SELECT registration.student_id FROM registration WHERE event_id = "+ event_id;
    cout << "��������Ŀ��ѧ��Ϊ��" << endl;
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

    cout << "�������Ӧ�÷�" << endl;
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
 
    cout << "¼��ɹ���" << endl;

    int temp;
    cout << "����������1\n";
    cin >> temp;
}

int main() {
//int __main(){
    // ע�� MySQL ��������
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    sql::Connection* con = driver->connect("tcp://����ip:3306", "root", "����");
    // �����ַ���
    con->setClientOption("character_set_results", "utf8mb4");

    sql::Statement* stmt = con->createStatement();
    stmt->execute("USE codertest"); // �л��� codertest ���ݿ�

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