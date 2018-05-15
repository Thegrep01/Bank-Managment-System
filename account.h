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
}log;

class account {
private:
    log l;
    char name[50];
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
