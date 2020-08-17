#include <iostream>
#include <vector>

using namespace std;

struct contact {
    string name;
    string phone;
};

vector<contact> PhoneBook;

void start();
void about();
void menu();
void add();
void nameCor(string &s);
void sort();
void view();
void edit();
void remove();
void search();
void exitapp();

int main() {
    start();

    return 0;
}

void start() {
    system("cls");
    cout << endl
         << "\t****************WELCOME TO PHONEBOOK*****************" << endl
         << "\t_____________________________________________________" << endl
         << endl
         << endl
         << endl
         << "\t1.Menu     2.About the App     3.Exit" << endl
         << endl;

    char c;
    cout << "\t";
    cin >> c;
    switch (c) {
        case '1':
            menu();
            break;
        case '2':
            about();
            break;
        case '3':
            exitapp();
            break;
        default:
            system("cls");
            cout << endl
                 << "\tInvalid Entry" << endl
                 << endl;
            system("pause");
            start();
    }
}

void about() {
    system("cls");
    system("cls");
    cout << endl
         << "\t**************WELCOME TO PHONEBOOK**************" << endl
         << "\t__________________________________________________" << endl
         << endl
         << "\tA PROJECT BY:" << endl
         << endl
         << "\t\tMd. Albin Hossain" << endl
         << "\t\tNusrat Jahan Marjana" << endl
         << "\t\tMarjea Anam Mila" << endl
         << "\t\tRaju Ahmed" << endl
         << "\t\tSection: O-13\tBatch: 52\t" << endl
         << endl
         << endl
         << "\tSubmitted To:" << endl
         << endl
         << "\t\tSubroto Nag Pinku" << endl
         << "\t\tDepartment of CSE" << endl
         << "\t\tDaffodil International University." << endl
         << endl
         << endl;
    system("pause");
    start();
}

void menu() {
    system("cls");
    cout << endl
         << "\t**************WELCOME TO PHONEBOOK**************" << endl
         << endl
         << endl
         << "\t                      MENU" << endl
         << "\t_________________________________________________" << endl
         << endl
         << endl
         << "\t1.Add New Contact      2.View List      3.Back" << endl
         << endl
         << "\t4.Edit Contact         5.Search         6.Delete" << endl
         << endl
         << "\t";
    char c;
    cin >> c;
    switch (c) {
        case '1':
            add();
            break;
        case '2':
            view();
            break;
        case '3':
            start();
            break;
        case '4':
            edit();
            break;
        case '5':
            search();
            break;
        case '6':
            remove();
            break;
        default:
            system("cls");
            cout << endl
                 << "\tInvalid Entry" << endl
                 << endl;
            system("pause");
            menu();
    }
}

void add() {
    system("cls");
    contact NewContact;
    cout << endl
         << "\tEnter New Contact's Data" << endl
         << endl
         << "\tName: ";
    cin >> NewContact.name;
    nameCor(NewContact.name);
    cout << endl
         << "\tPhone No: ";
    cin >> NewContact.phone;
    PhoneBook.push_back(NewContact);
    system("cls");
    cout << endl
         << "\tRecord Saved" << endl
         << endl;
    sort();
    system("pause");
    menu();
}

void nameCor(string &s) {
    if (s[0] > 'Z') s[0] -= 32;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
}

void sort() {
    int min_idx;
    for (int i = 0; i < PhoneBook.size(); i++) {
        min_idx = i;
        for (int j = i + 1; j < PhoneBook.size(); j++) {
            if (PhoneBook[j].name < PhoneBook[min_idx].name) min_idx = j;
        }
        swap(PhoneBook[i], PhoneBook[min_idx]);
    }
}

void view() {
    system("cls");
    if (PhoneBook.empty())
        cout << endl
             << "\tYour PhoneBook is Empty\n"
             << endl;
    else {
        cout << endl
             << "\tContact List" << endl
             << "\t____________________________________________________" << endl;
        for (int i = 0; i < PhoneBook.size(); i++) {
            cout << endl
                 << "\tName: " << PhoneBook[i].name << endl
                 << "\tPhone: " << PhoneBook[i].phone << endl;
        }
        cout << endl;
    }
    system("pause");
    menu();
}

void search() {
    system("cls");
    string name;
    bool found = false;
    contact x;

    if (PhoneBook.empty())
        cout << endl
             << "\tPhoneBook is Empty\n"
             << endl;
    else {
        cout << endl
             << "\tEnter a Name to Search: ";
        cin >> name;
        nameCor(name);
        for (int i = 0; i < PhoneBook.size(); i++) {
            if (PhoneBook[i].name == name) {
                found = true;
                x = PhoneBook[i];
                break;
            }
        }
        system("cls");
        if (!found)
            cout << endl
                 << "\t" << name << " Did Not Match any Contact" << endl
                 << endl;
        else {
            cout << "\tName: " << x.name << endl
                 << "\tPhone: " << x.phone << endl;
        }
    }
    system("pause");
    menu();
}

void remove() {
    system("cls");
    string name;
    bool found = false;
    if (PhoneBook.empty())
        cout << endl
             << "\t"
             << "PhoneBook is Empty\n"
             << endl;
    else {
        cout << endl
             << "\tEnter a Name to Delete: ";
        cin >> name;
        for (int i = 0; i < PhoneBook.size(); i++) {
            if (PhoneBook[i].name == name) {
                found = true;
                PhoneBook.erase(PhoneBook.begin() + i);
                break;
            }
        }
        system("cls");
        if (found)
            cout << endl
                 << "\t" << name << " Deleted Successfully" << endl
                 << endl;
        else
            cout << endl
                 << "\t" << name << " Not found" << endl
                 << endl;
    }
    system("pause");
    menu();
}

void edit() {
    system("cls");
    string name;
    bool found = false;

    if (PhoneBook.empty())
        cout << endl
             << "\tPhoneBook is Empty" << endl
             << endl;
    else {
        cout << endl
             << "\tEnter a Contact Name to Edit: ";
        cin >> name;
        for (int i = 0; i < PhoneBook.size(); i++) {
            if (PhoneBook[i].name == name) {
                found = true;
                cout << "\tName: " << PhoneBook[i].name << endl
                     << "\tPhone: " << PhoneBook[i].phone << endl
                     << endl
                     << "\tEnter New Data: " << endl
                     << endl
                     << "\tName: ";
                cin >> PhoneBook[i].name;
                cout << endl
                     << "\tPhone No: ";
                cin >> PhoneBook[i].phone;
                cout << endl
                     << "\tContact Updated Successfully" << endl
                     << endl
                     << endl;
                break;
            }
        }
        system("cls");
        if (!found) cout << endl
                         << "\t" << name << " Did Not Match any Contact" << endl
                         << endl;
    }
    sort();
    system("pause");
    menu();
}

void exitapp() {
    system("cls");
    cout << endl
         << endl
         << "\t***************THANK YOU FOR USING PHONEBOOK***************" << endl
         << endl
         << endl;
    system("pause");
    exit(0);
}
