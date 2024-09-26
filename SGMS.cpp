#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int menu();
void Sum();
void sort();
void csh(); //1
void xyskzl(); //2
void gxyxxzf(); //3
void gxyzfmccx(); //4
void gxyzfcx(); //5
void gxmhjydyxxxxg(); //6
void Add(); //6
int convert(int i); //6

struct Athlete {
    int num;  //���
    string project;  //��Ŀ
    int ranking;  //����
    int score;  //����
};

struct collage {
    int num;
    string name;  //ѧԺ����
    Athlete Ma[10];  //���˶�Ա
    Athlete Wo[10];  //Ů�˶�Ա
    int sum;
    int sumM;
    int sumW;
};


collage Class[6] = {
    {1,"dianzigongcheng", {{1,"1100",1,7},{3,"��Զ",1,7}}, {{2,"1100",1,7},{4,"��Զ",1,7}}},
    {2,"chuanbo", {{5,"1100",3,3},{7,"��Զ",2,5}}, {{6,"1100",3,3},{8,"��Զ",2,5}}},
    {3,"shengmingkexue", {{9,"1100",2,5},{11,"��Զ",5,1}}, {{10,"1100",2,5},{12,"��Զ",5,1}}},
    {4,"jidiangongcheng", {{13,"1100",4,2},{15,"��Զ",4,2}}, {{14,"1100",4,2},{16,"��Զ",4,2}}},
    {5,"zhonge", {{17,"1100",6,0},{19,"��Զ",3,3}}, {{18,"1100",6,0},{20,"��Զ",3,3}}},
    {6,"shuxue", {{21,"1100",5,1},{23,"��Զ",6,0}}, {{22,"1100",5,1},{24,"��Զ",6,0}}}
};

int N;  //����Ժϵ����
int M;  //������������
int W;  //����Ů������
int JM = 2;  //ÿ��ѧԺ�����˶�Ա
int JW = 2;  //ÿ��ѧԺ��Ů�˶�Ա

int main() {
    int n = 1;

    while (n > 0 && n < 7) {
        n = menu();
        switch (n) {
        case 1: csh(); break;
        case 2: xyskzl(); break;
        case 3: gxyxxzf(); break;
        case 4: gxyzfmccx(); break;
        case 5: gxyzfcx(); break;
        case 6: gxmhjydyxxxxg(); break;
        }
    }

    return 0;
}

//////////////////////�˵�//////////////////
int menu() {
    int n;
    system("cls"); //����
    cout << "�˶������ϵͳ\n";
    cout << "----------------\n";
    cout << "1.��ʼ��\n";
    cout << "2.ѧԺ��������\n";
    cout << "3.��ѧԺ��ϸ�ܷ�\n";
    cout << "4.��ѧԺ�ܷ����β�ѯ\n";
    cout << "5.��ѧԺ�ֲܷ�ѯ\n";
    cout << "6.����Ŀ���˶�Ա��Ϣ�޸�\n";
    cout << "7.��������\n";
    cout << "���������蹦��ǰ�����:";
    cin >> n;

    while (n < 0 || n > 7) {
        cout << "�������������蹦��ǰ����ţ�eg:1";
        cin >> n;
    }

    return n;
}

//////////////////��ʼ��1////////////////
void csh() {
    cout << "���������Ժϵ������";
    cin >> N;
    cout << "�������������������";
    cin >> M;
    cout << "���������Ů��������";
    cin >> W;
}

//////////////ѧԺ��������2/////////////////
void xyskzl() {
    for (int i = 0; i < 6; i++) {
        cout << Class[i].name << endl;
        for (int j = 0; j < JM; j++) {
            cout << "\t" << Class[i].Ma[j].project << "\n\t" << Class[i].Ma[j].num << "\t" << Class[i].Ma[j].score << "\n\t"
                << Class[i].Wo[j].num << "\t" << Class[i].Wo[j].score << endl;
        }
    }
    cout << "�����밴1\n";
    int temp;
    cin >> temp;
}

//////////////////��ѧԺ�ֲܷ�ѯ3//////////////////////
void gxyxxzf() {
    int c[6], d[6], e[6];
    for (int i = 0; i < 6; i++) {
        c[i] = Class[i].Ma[0].score + Class[i].Ma[1].score;
        d[i] = Class[i].Wo[0].score + Class[i].Wo[1].score;
        e[i] = c[i] + d[i];
    }
    for (int i = 0; i < 6; i++) {
        cout << "ѧԺ\t�ܷ�\t\t�����ܷ� Ů���ܷ�\n";
        cout << Class[i].name << "\t" << e[i] << "\t" << c[i] << "\t" << d[i] << endl;
    }
    cout << "����������1\n";
    int temp;
    cin >> temp;
}

////////////////��ѧԺ�ܷ����β�ѯ4///////////
void gxyzfmccx() {
    int temp, c[6], d[6], e[6];
    string a[6] = { "shuxue", "zhonge", "jidiangongcheng", "chuanbo", "shengmingkexue", "dianzigongcheng" };

    for (int i = 0; i < 6; i++) {
        c[i] = Class[i].Ma[0].score + Class[i].Ma[1].score;
        d[i] = Class[i].Wo[0].score + Class[i].Wo[1].score;
        e[i] = c[i] + d[i];
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (e[j] > e[j + 1]) {
                temp = e[j]; e[j] = e[j + 1]; e[j + 1] = temp;
            }
        }
    }

    cout << "ѧԺ\t�ܷ�\n";
    for (int i = 5; i >= 0; i--) {
        cout << a[i] << "\t" << e[i] << endl;
    }
    cout << "����������1\n";
    cin >> temp;
}

/////////////////��ѧԺ�ֲܷ�ѯ5/////////////
void gxyzfcx() {
    int c[6], d[6], e[6];
    for (int i = 0; i < 6; i++) {
        c[i] = Class[i].Ma[0].score + Class[i].Ma[1].score;
        d[i] = Class[i].Wo[0].score + Class[i].Wo[1].score;
        e[i] = c[i] + d[i];
    }

    int n;
    cout << "1.���ӹ���\n2.����\n3.������ѧ\n4.���繤��\n5.�ж�\n6.��ѧ\n7.����\n";
    cout << "���������\n";
    cin >> n;

    while (n > 0 && n < 7) {
        cout << Class[n - 1].name << "\t" << e[n - 1] << endl;
        cout << "1.���ӹ���\n2.����\n3.������ѧ\n4.���繤��\n5.�ж�\n6.��ѧ\n7.����\n";
        cout << "���������\n";
        cin >> n;
    }
}

///////////����Ŀ���˶�Ա��Ϣ�޸�6///////////////////
void gxmhjydyxxxxg() {
    int n;
    cout << "1.����\n2.ɾ��\n3.����\n";
    cout << "���������蹦��ǰ����ţ�\n";
    cin >> n;

    while (n < 1 || n > 3) {
        cout << "�������������蹦��ǰ����ţ�eg:1";
        cin >> n;
    }

    if (n == 1) {
        Add();
    }
}

void Add() {
    int i, flag = 1;
    char c;

    while (flag == 1) {
        cout << "��������Ҫ�޸���Ϣ��ѧԺ��ţ�";
        cin >> i;

        cout << "������������Ҫ��ӵ��˶�Ա��š�������Ŀ���������Ρ������ɼ���\n";
        Athlete newAthlete;
        cin >> newAthlete.num >> newAthlete.project >> newAthlete.ranking >> newAthlete.score;

        cout << "�л�Ů��M or W��:";
        cin >> c;

        if (c == 'M') {
            Class[i - 1].Ma[JM] = newAthlete;
            JM++;
        }
        else if (c == 'W') {
            Class[i - 1].Wo[JW] = newAthlete;
            JW++;
        }

        cout << "�����밴1";
        cin >> flag;
    }
}
