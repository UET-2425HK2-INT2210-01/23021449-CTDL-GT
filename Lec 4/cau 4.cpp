#include <iostream>
using namespace std;
struct Student {
    int id;
    string name;
    string className;
};

const int MAX_STUDENTS = 1000;
Student studentList[MAX_STUDENTS];
int studentCount = 0;

void insertStudent(int id, string name, string className) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentList[i].id == id) {
            return; 
        }
    }
    if (studentCount < MAX_STUDENTS) {
        studentList[studentCount].id = id;
        studentList[studentCount].name = name;
        studentList[studentCount].className = className;
        studentCount++;
    }
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentList[i].id == id) {
            for (int j = i; j < studentCount - 1; ++j) {
                studentList[j] = studentList[j + 1];
            }
            studentCount--;
            return;
        }
    }
}

string getStudentInfo(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentList[i].id == id) {
            return studentList[i].name + "," + studentList[i].className;
        }
    }
    return "NA,NA";
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;

        size_t space = line.find(' ');
        string command = line.substr(0, space);
        string rest = line.substr(space + 1);

        if (command == "Insert") {
            size_t comma1 = rest.find(',');
            size_t comma2 = rest.find(',', comma1 + 1);

            int id = stoi(rest.substr(0, comma1));
            string name = rest.substr(comma1 + 1, comma2 - comma1 - 1);
            string className = rest.substr(comma2 + 1);

            insertStudent(id, name, className);
        } else if (command == "Delete") {
            int id = stoi(rest);
            deleteStudent(id);
        } else if (command == "Infor") {
            int id = stoi(rest);
            cout << getStudentInfo(id) << endl;
        }
    }
    return 0;
}