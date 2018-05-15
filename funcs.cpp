#include "funcs.h"

void write_account() {
    account ac;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
    outFile.close();
}

void display_sp(int n) {
    account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\nBALANCE DETAILSn";

    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        if(ac.GetLog().Number==n)
        {
            ac.show_account();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nAccount number does not exist";
}

void modify_account(int n) {
    bool found=false;
    account ac;
    fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
        if(ac.GetLog().Number==n)
        {
            ac.show_account();
            cout<<"\n\nEnter The New Details of account"<<endl;
            ac.modify();
            int pos=(-1)*static_cast<int>(sizeof(account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"nnt Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}

void modify_account(int n,int flag) {
    bool found=false;
    account ac;
    fstream File;
    char pas[12];
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File) {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false) {
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
        if(ac.GetLog().Number==n) {
            cout<<"\n\nEnter The Password"<<endl;
            cin.ignore();
            cin.getline(ac.GetLog().Password,12);
            int pos=(-1)*static_cast<int>(sizeof(account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}

void delete_account(int n) {
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        if(ac.GetLog().Number!=n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"\n\n\tRecord Deleted ..";
}

void display_all() {
    account ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"====================================================\n";
    cout<<"A/c no.      NAME          Balance\n";
    cout<<"====================================================\n";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}

void deposit_withdraw(int n, int option) {
    int amt;
    bool found=false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
        if(ac.GetLog().Number==n)
        {
            ac.show_account();
            if(option==1)
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                cout<<"\n\nEnter The amount to be deposited";
                cin>>amt;
                ac.dep(amt);
            }
            if(option==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                cout<<"\n\nEnter The amount to be withdraw";
                cin>>amt;
                int bal= ac.GetDeposite()-amt;
                ac.draw(amt);
            }
            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}

void intro() {
    cout<<"\n\n\n\t  BANK";
    cout<<"\n\n\tMANAGEMENT";
    cout<<"\n\n\t  SYSTEM";
    cin.get();
}

int login() {
    string num;
    char password[12];
    cout << "\nEnter your account number : ";
    cin >> num;
    cout << "\nEnter your password : ";
    cin.ignore();
    cin.getline(password,12);
    system("clear");
    if (num == "admin" && strcmp(password,"admin") == 0)
        return -1;
    else {
        account ac;
        ifstream inFile;
        inFile.open("account.dat", ios::binary);
        if (!inFile) {
            cout << "File could not be open !! Press any Key...";
            return 0;
        }
        while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
            if (ac.GetLog().Number == stoi(num) && strcmp(password,ac.GetLog().Password) == 0) {
                inFile.close();
                return ac.GetLog().Number;
            }
    }
    return 0;
}

