#include "funcs.h"

int main() {
    char ch;
    int num;
    intro();
    system("clear");
    int n = login();
    if (n == -1) {
        do {
            cout<<"\n\n\n\tMAIN MENU";
            cout<<"\n\n\t01. NEW ACCOUNT";
            cout<<"\n\n\t02. ALL ACCOUNT HOLDER LIST";
            cout<<"\n\n\t03. BALANCE ENQUIRY";
            cout<<"\n\n\t04. CLOSE AN ACCOUNT";
            cout<<"\n\n\t05. MODIFY AN ACCOUNT";
            cout<<"\n\n\t06. EXIT";
            cout<<"\n\n\tSelect Your Option (1-6) ";
            cin>>ch;
            system("clear");
            switch(ch) {
                case '1':
                    write_account();
                    break;
                case '2':
                    display_all();
                    break;
                case '3':
                    cout<<"\n\ntEnter The account No. : "; cin>>num;
                    display_sp(num);
                    break;
                case '4':
                    cout<<"\n\n\tEnter The account No. : "; cin>>num;
                    delete_account(num);
                    break;
                    case '5':
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        modify_account(num);
                        break;
                case '6':
                    cout<<"\n\n\tThanks for using bank managemnt system";
                    break;
                default :cout<<"a";
            }
            cin.ignore();
            cin.get();
        } while(ch!='6');
        return 0;
    }
    else if (n == 0) {
        cout << "\nLogin Error";
        return 0;
    }
    else {
        do {
            cout<<"\n\n\n\tMAIN MENU";
            cout<<"\n\n\t01. DEPOSIT AMOUNT";
            cout<<"\n\n\t02. WITHDRAW AMOUNT";
            cout<<"\n\n\t03. BALANCE ENQUIRY";
            cout<<"\n\n\t04. MODIFY A PASSWORD";
            cout<<"\n\n\t05. TRANSFER MONEY";
            cout<<"\n\n\t06. EXIT";
            cout<<"\n\n\tSelect Your Option (1-5) ";
            cin>>ch;
            system("clear");
            switch(ch)
            {
                case '1':
                    deposit_withdraw(n, 1);
                    break;
                case '2':
                    deposit_withdraw(n, 2);
                    break;
                case '3':
                    display_sp(n);
                    break;
                case '4':
                    modify_account(n,1);
                    break;
                case '5':
                    cout << "\n\nEnter account number : ";
                    cin >> num;
                    cout << "\n\nEnter sum to transfer : ";
                    int sum;
                    cin >> sum;
                    if (check(n,sum)){
                        deposit_withdraw(n,2,sum);
                        deposit_withdraw(num,1,sum);
                    }
                    else{
                        cout << "Fail\n";
                        break;
                    }
                    break;
                case '6':
                    cout<<"\n\n\tThanks for using bank managemnt system";
                    break;
                default :cout<<"a";
            }
            cin.ignore();
            cin.get();
        }while(ch!='6');
        return 0;
    }

}
