#include "account.h"

void account::create_account() {
    cout<<"\nEnter The account No. :";
    cin>>l.Number;
    cout<<"\n\nEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name,50);
    cout << "\n\nEnter password : ";
    cin.getline(l.Password,12);
    cout<<"\nEnter The Initial amount : ";
    cin>>deposit;
    cout<<"\n\n\nAccount Created..";
}

void account::show_account() const {
    cout<<"\nAccount No. : "<<l.Number;
    cout<<"\nAccount Holder Name : ";
    cout<<name;
    cout<<"\nBalance amount : "<<deposit;
}

void account::modify() {
    cout<<"\nAccount No. : "<<l.Number;
    cout<<"\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name,50);
    cout << "\n\nEnter password : ";
    cin.ignore();
    cin.getline(l.Password,12);
    cout<<"\nModify Balance amount : ";
    cin>>deposit;
}

void account::dep(int x) {
    deposit+=x;
}

void account::draw(int x) {
    deposit-=x;
}

void account::report() const {
    cout<<l.Number<<setw(10)<<" "<<name<< " " << setw(6)<<deposit<<endl;
}

int account::GetDeposite() const {
    return deposit;
}
