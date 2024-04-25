#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Student {
private:
    int age;
    string first_name;
    string last_name;
    int standard;

public:
    void set_age(int a) {
        age = a;
    }

    int get_age() {
        return age;
    }

    void set_first_name(string name) {
        first_name = name;
    }

    string get_first_name() {
        return first_name;
    }

    void set_last_name(string name) {
        last_name = name;
    }

    string get_last_name() {
        return last_name;
    }

    void set_standard(int s) {
        standard = s;
    }

    int get_standard() {
        return standard;
    }

    string to_string() {
        stringstream ss;
        ss << age << "," << first_name << "," << last_name << "," << standard;
        return ss.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student s;
    s.set_age(age);
    s.set_first_name(first_name);
    s.set_last_name(last_name);
    s.set_standard(standard);

    cout << s.get_age() << endl;
    cout << s.get_last_name() << ", " << s.get_first_name() << endl;
    cout << s.get_standard() << endl;
    cout << s.to_string() << endl;

    return 0;
}

