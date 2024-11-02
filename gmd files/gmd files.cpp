




#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int max_students = 100;
const int subjects = 10;

struct Student {
    string name;
    bool grades[subjects];

    
    void fill() {
        cout << "Enter student's PIB: ";
        getline(cin, name);
        cout << "Enter grades (0 - didn't pass, 1 - passed) for 10 subjects:\n";
        for (int i = 0; i < subjects; ++i) {
            int grade;
            cout << "Grade " << (i + 1) << ": ";
            cin >> grade;
            grades[i] = (grade == 1);
        }
        cin.ignore();
    }

    
    void printInfo() const {
        cout << "PIB: " << name << "\ngrades: ";
        for (int i = 0; i < subjects; ++i) {
            cout << (grades[i] ? "passed " : "Didn't pass ") << " ";
        }
        cout << endl;
    }

    
    double average() const {
        int passed = 0;
        for (int i = 0; i < subjects; ++i) {
            if (grades[i]) {
                passed++;
            }
        }
        return static_cast<double>(passed) / subjects * 100;
    }
};


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define square(x) ((x) * (x))
#define power(base, exp) (pow((base), (exp)))
#define is_even(x) ((x) % 2 == 0)
#define is_odd(x) ((x) % 2 != 0)

int main() {
    Student students[max_students];
    int studentCount = 0;
    int option;

    do {
        cout << "1. Add student \n";
        cout << "2. Show list of students\n";
        cout << "3. Druk borzhnykiv\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        cin >> option;
        cin.ignore();

        switch (option) {
        case 1: {
            if (studentCount < max_students) {
                students[studentCount].fill();
                studentCount++;
            }
            else {
                cout << "Achieved max amount of students\n";
            }
            break;
        }
        case 2: {
            for (int i = 0; i < studentCount; ++i) {
                students[i].printInfo();
            }
            break;
        }
        case 3: {
            cout << "Borzhnyky:\n";
            for (int i = 0; i < studentCount; ++i) {
                if (students[i].average() < 50) {
                    cout << students[i].name << endl;
                }
            }
            break;
        }
        case 0: {
            cout << "Exit\n";
            break;
        }
        default:
            cout << "wrong option\n";
        }
    } while (option != 0);

    
    int a = 5, b = 10;
    cout << "minimum: " << min(a, b) << endl;
    cout << "maximum: " << max(a, b) << endl;
    cout << "square: " << square(a) << endl;
    cout << "5 exp 3: " << power(5, 3) << endl;
    cout << "5 is even? " << (is_even(a) ? "yes" : "no") << endl;
    cout << "5 is odd? " << (is_odd(a) ? "yes" : "no") << endl;

    
}
