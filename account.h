#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <cstring>
#include <string>
#include<unistd.h>

using namespace std;

typedef struct LogInfo {
    char Password[12];
    int Number;
    char name[50];
}log;

class account {
private:
    log l;
    int deposit;
public:
    log GetLog(){ return l;}
    void create_account();
    void show_account() const;
    void modify();
    void dep(int);
    void draw(int);
    void report() const;
    int GetDeposite() const;
};
