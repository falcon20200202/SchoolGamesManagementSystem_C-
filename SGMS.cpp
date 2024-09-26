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
    int num;  //序号
    string project;  //项目
    int ranking;  //名次
    int score;  //分数
};

struct collage {
    int num;
    string name;  //学院名称
    Athlete Ma[10];  //男运动员
    Athlete Wo[10];  //女运动员
    int sum;
    int sumM;
    int sumW;
};


collage Class[6] = {
    {1,"dianzigongcheng", {{1,"1100",1,7},{3,"跳远",1,7}}, {{2,"1100",1,7},{4,"跳远",1,7}}},
    {2,"chuanbo", {{5,"1100",3,3},{7,"跳远",2,5}}, {{6,"1100",3,3},{8,"跳远",2,5}}},
    {3,"shengmingkexue", {{9,"1100",2,5},{11,"跳远",5,1}}, {{10,"1100",2,5},{12,"跳远",5,1}}},
    {4,"jidiangongcheng", {{13,"1100",4,2},{15,"跳远",4,2}}, {{14,"1100",4,2},{16,"跳远",4,2}}},
    {5,"zhonge", {{17,"1100",6,0},{19,"跳远",3,3}}, {{18,"1100",6,0},{20,"跳远",3,3}}},
    {6,"shuxue", {{21,"1100",5,1},{23,"跳远",6,0}}, {{22,"1100",5,1},{24,"跳远",6,0}}}
};

int N;  //参赛院系总数
int M;  //参赛男子总数
int W;  //参赛女子总数
int JM = 2;  //每个学院的男运动员
int JW = 2;  //每个学院的女运动员

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

//////////////////////菜单//////////////////
int menu() {
    int n;
    system("cls"); //清屏
    cout << "运动会管理系统\n";
    cout << "----------------\n";
    cout << "1.初始化\n";
    cout << "2.学院赛况总览\n";
    cout << "3.各学院详细总分\n";
    cout << "4.各学院总分名次查询\n";
    cout << "5.各学院总分查询\n";
    cout << "6.各项目获奖运动员信息修改\n";
    cout << "7.结束程序\n";
    cout << "请输入所需功能前的序号:";
    cin >> n;

    while (n < 0 || n > 7) {
        cout << "请重新输入所需功能前的序号，eg:1";
        cin >> n;
    }

    return n;
}

//////////////////初始化1////////////////
void csh() {
    cout << "请输入参赛院系总数：";
    cin >> N;
    cout << "请输入参赛男子总数：";
    cin >> M;
    cout << "请输入参赛女子总数：";
    cin >> W;
}

//////////////学院赛况总览2/////////////////
void xyskzl() {
    for (int i = 0; i < 6; i++) {
        cout << Class[i].name << endl;
        for (int j = 0; j < JM; j++) {
            cout << "\t" << Class[i].Ma[j].project << "\n\t" << Class[i].Ma[j].num << "\t" << Class[i].Ma[j].score << "\n\t"
                << Class[i].Wo[j].num << "\t" << Class[i].Wo[j].score << endl;
        }
    }
    cout << "返回请按1\n";
    int temp;
    cin >> temp;
}

//////////////////各学院总分查询3//////////////////////
void gxyxxzf() {
    int c[6], d[6], e[6];
    for (int i = 0; i < 6; i++) {
        c[i] = Class[i].Ma[0].score + Class[i].Ma[1].score;
        d[i] = Class[i].Wo[0].score + Class[i].Wo[1].score;
        e[i] = c[i] + d[i];
    }
    for (int i = 0; i < 6; i++) {
        cout << "学院\t总分\t\t男子总分 女子总分\n";
        cout << Class[i].name << "\t" << e[i] << "\t" << c[i] << "\t" << d[i] << endl;
    }
    cout << "返回请输入1\n";
    int temp;
    cin >> temp;
}

////////////////各学院总分名次查询4///////////
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

    cout << "学院\t总分\n";
    for (int i = 5; i >= 0; i--) {
        cout << a[i] << "\t" << e[i] << endl;
    }
    cout << "返回请输入1\n";
    cin >> temp;
}

/////////////////各学院总分查询5/////////////
void gxyzfcx() {
    int c[6], d[6], e[6];
    for (int i = 0; i < 6; i++) {
        c[i] = Class[i].Ma[0].score + Class[i].Ma[1].score;
        d[i] = Class[i].Wo[0].score + Class[i].Wo[1].score;
        e[i] = c[i] + d[i];
    }

    int n;
    cout << "1.电子工程\n2.传播\n3.生命科学\n4.机电工程\n5.中俄\n6.数学\n7.返回\n";
    cout << "请输入序号\n";
    cin >> n;

    while (n > 0 && n < 7) {
        cout << Class[n - 1].name << "\t" << e[n - 1] << endl;
        cout << "1.电子工程\n2.传播\n3.生命科学\n4.机电工程\n5.中俄\n6.数学\n7.返回\n";
        cout << "请输入序号\n";
        cin >> n;
    }
}

///////////各项目获奖运动员信息修改6///////////////////
void gxmhjydyxxxxg() {
    int n;
    cout << "1.增添\n2.删除\n3.返回\n";
    cout << "请输入所需功能前的序号：\n";
    cin >> n;

    while (n < 1 || n > 3) {
        cout << "请重新输入所需功能前的序号，eg:1";
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
        cout << "请输入需要修改信息的学院序号：";
        cin >> i;

        cout << "请依次输入需要添加的运动员序号、比赛项目、比赛名次、比赛成绩：\n";
        Athlete newAthlete;
        cin >> newAthlete.num >> newAthlete.project >> newAthlete.ranking >> newAthlete.score;

        cout << "男或女（M or W）:";
        cin >> c;

        if (c == 'M') {
            Class[i - 1].Ma[JM] = newAthlete;
            JM++;
        }
        else if (c == 'W') {
            Class[i - 1].Wo[JW] = newAthlete;
            JW++;
        }

        cout << "返回请按1";
        cin >> flag;
    }
}
