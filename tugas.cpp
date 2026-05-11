#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->nama = nama;
        this->email = email;
        generateId();
    }   

    ~User() {
        cout << "User \"" << nama << "\" dihapus\n";
    }

    void generateId();

};

int User::globalId = 0;

class Member : public User {
private:
    bool status;

public:
    Member(string nama, string email) : User(nama, email) {
        status = true;
    }

    ~Member() {
        cout << "Member \"" << nama << "\" dihapus\n";
    }

    void showProfile();

    void toggleStatus();

    string getNama();

    bool getStatus();
};   

class Admin : public User {
public:
    Admin(string nama, string email) : User(nama, email){}

    ~Admin() {
        cout << "Admin \"" << nama << "\" dihapus\n";
    }

    void showAllMember(vector<Member*> &members);

    void toggleActivationMember(Member *m);
};

void User::generateId() {
    id = ++globalId;
}

void Member::showProfile() {
    cout << "ID     : " << id << endl;
    cout << "Nama   : " << nama << endl;
    cout << "Email  : " << email << endl;
    cout << "Status : " << (status ? "Aktif" : "Nonaktif") << endl;
}

void Member::toggleStatus() {
    status = !status;
}

string Member::getNama() {
    return nama;
}

bool Member::getStatus() {
    return status;
}

void Admin::showAllMember(vector<Member*> &members) {
    cout << "\n=== DAFTAR MEMBER ===\n";

    for (int i = 0; i < members.size(); i++) {
        cout << i + 1 << ". "
             << members[i]->getNama()
             << " - "
             << (members[i]->getStatus() ? "Aktif" : "Nonaktif")
             << endl;
    }
}

void Admin::toggleActivationMember(Member *m) {
    m->toggleStatus();
}

int main() {

    Member *member1 = new Member("Maritza", "maritza@gmail.com");
    Member *member2 = new Member("Fidelya", "fidelya@gmail.com");

    Admin *admin = new Admin("Admin", "admin@gmail.com");

    vector<Member*> members = {member1, member2};

    admin->showAllMember(members);

    cout << "\n=== PROFILE MEMBER 1 ===\n";
    members[0]->showProfile();

    cout << "\nAdmin menonaktifkan Member 1...\n";
    admin->toggleActivationMember(members[0]);

    cout << "\n=== PROFILE MEMBER 1 SETELAH DIUBAH ===\n";
    members[0]->showProfile();

    cout << endl;
    delete member1;
    delete member2;
    delete admin;

    return 0;
}