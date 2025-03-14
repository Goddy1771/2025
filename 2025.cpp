#include <iostream>
using namespace std;

class student {
private:
    string name;
    int age;
    float grade;

public:
    student(string n, int a, float g) : name(n), age(a), grade(g) {}

    void display() const {
        cout << "name: " << name << ", age: " << age << ", grade: " << grade << endl;
    }

    friend void modifygrade(student* studentptr, float newgrade) {
        studentptr->grade = newgrade;
    }

    friend void modifyage(student& studentref, int newage) {
        studentref.age = newage;
    }
};

int main() {
    student student("josh", 20, 88.5);
    cout << "initial values:" << endl;
    student.display();

    modifygrade(&student, 92.0);
    modifyage(student, 21);

    cout << "modified values:" << endl;
    student.display();

    return 0;
}
