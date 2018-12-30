#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

using namespace std;

int clean_stdin()
{
	while (getchar() != '\n')
	{
	}
	return 1;
}
//doi pass thanh ****
void get_pass(string & str)
{
	char temp[100];
	int i = 0;
	while (1)
	{
		char c = _getch();
		if (i == 0 && c == 8) continue;
		if (c != 13) // (int) '\n' = 13
		{
			if (c == 8) { cout << "\b" << " " << "\b"; i--; }
			else
			{
				temp[i++] = c;
				cout << "*";
			}
		}
		else break;
	}
	temp[i] = '\0';
	str.clear();
	for (int i = 0; i < strlen(temp); i++) str += temp[i];
	cout << endl;
}
string score()
{
	char ch = 'a', xau[10], i = 0, flag = 1;
	while (ch != 0xD || i == 0)
	{
		ch = _getch();
		if (ch == 0x8) xau[i - 1] == '.' ? printf("\b\b  \b\b"), i = 0, flag = 1 : i ? --i, printf("\b \b") : 0;
		if (i >= 7 || (*xau == '1' && (i == 2 && xau[1] == '0') || (i == 1 && ch != '.'&&ch != '0'))) continue;
		if (ch == '.'&&flag) flag = 0; else if (ch<'0' || ch>'9') continue;
		if (i == 0 && ch != '1') xau[i++] = ch, xau[i++] = '.', printf("%c.", ch), flag = 0; else xau[i++] = ch, printf("%c", ch);
	}
	xau[i] = 0; printf("\n");
	return xau;
}

typedef struct thongtin_user {
	string user;
	string pass;
	string admin;
};
vector<thongtin_user> User;

typedef struct student {
	string id;
	string name;
	string birthday;
	string address;
};
vector<student> Student;

typedef struct teacher{
	string id;
	string name;
	string birthday;
	string phone;
	string address;
};
vector<teacher> Teacher;

typedef struct course {
	string course_id;
	string teacher_id;
	string course_name;
	string n_student;
	string slot;
};
vector<course> Course;

typedef struct object {
	string course_id;
	string student_id;
	string teacher_id;
	string score;
	string semeter_id;
};
vector<object> Object;


void read_user(vector<thongtin_user> &User) {
	thongtin_user u;
	ifstream fin;
	fin.open("user.csv");
	while (!fin.eof()) {
		getline(fin, u.user, ',');
		getline(fin, u.pass, ',');
		getline(fin, u.admin);
		User.push_back(u);
	}
	int x = User.size() - 1;
	User.erase(User.begin() + x);
	fin.close();
}

void read_teacher(vector<teacher> &Teacher) {
	teacher t;
	ifstream fin;
	fin.open("teacher.csv");
	while (!fin.eof()) {
		getline(fin, t.id, ',');
		getline(fin, t.name, ',');
		getline(fin, t.birthday, ',');
		getline(fin, t.phone, ',');
		getline(fin, t.address);
		Teacher.push_back(t);
	}
	int x = Teacher.size() - 1;
	Teacher.erase(Teacher.begin() + x);
	fin.close();
}

void read_student(vector<student> &Student) {
	student st;
	ifstream fin;
	fin.open("student.csv");
	while (!fin.eof()) {
		getline(fin, st.id, ',');
		getline(fin, st.name, ',');
		getline(fin, st.birthday, ',');
		getline(fin, st.address);
		Student.push_back(st);
	}
	int x = Student.size()-1;
	Student.erase(Student.begin() + x);
	fin.close();
}

void read_course(vector<course> &Course) {
	course c;
	string temp;
	ifstream fin;
	fin.open("course.csv");
	getline(fin, temp);
	while (!fin.eof()) {
		getline(fin, c.course_id, ',');
		getline(fin, c.teacher_id, ',');
		getline(fin, c.course_name, ',');
		getline(fin, c.n_student, ',');
		getline(fin, c.slot);
		Course.push_back(c);
	}
	int x = Course.size() - 1;
	Course.erase(Course.begin() + x);
	fin.close();
}

void read_object(vector<object> &Object) {
	object o;
	string temp;
	ifstream fin;
	fin.open("object.csv");
	getline(fin, temp);
	while (!fin.eof()) {
		getline(fin, o.course_id, ',');
		getline(fin, o.student_id, ',');
		getline(fin, o.teacher_id, ',');
		getline(fin, o.score, ',');
		getline(fin, o.semeter_id);
		Object.push_back(o);
	}
	int x = Object.size() - 1;
	Object.erase(Object.begin() + x);
	fin.close();
}

void write_course(vector<course> &Course)
{
	ofstream fout;
	fout.open("course.csv");
	fout << "Course_ID,Teacher_ID,Name,n_student,slot" << endl;
	for (int i = 0; i < Course.size(); i++)
	{
		fout << Course[i].course_id << ",";
		fout << Course[i].teacher_id << ",";
		fout << Course[i].course_name << ",";
		fout << Course[i].n_student << ",";
		fout << Course[i].slot << endl;
	}
	fout.close();
}

void write_object(vector<object> &Object) {
	ofstream fout;
	fout.open("object.csv");
	fout << "Course_ID,Student_ID,Teacher_ID,Score,Semeter_ID" << endl;
	for (int i = 0; i < Object.size(); i++) {
		fout << Object[i].course_id << ",";
		fout << Object[i].student_id << ",";
		fout << Object[i].teacher_id<< ",";
		fout << Object[i].score << ",";
		fout << Object[i].semeter_id << endl;
	}
	fout.close();
}
void write_user(vector<thongtin_user> &User) {
	ofstream fout;
	fout.open("user.csv");
	for (int i = 0; i < User.size(); i++) {
		fout << User[i].user << ",";
		fout << User[i].pass << ",";
		fout << User[i].admin << endl;
	}
	fout.close();
}

void write_student(vector<student> &Student) {
	ofstream fout;
	fout.open("student.csv");
	for (int i = 0; i < Student.size(); i++) {
		fout << Student[i].id << ",";
		fout << Student[i].name << ",";
		fout << Student[i].birthday << ",";
		fout << Student[i].address << endl;
	}
	fout.close();
}

void write_teacher(vector<teacher> &Teacher) {
	ofstream fout;
	fout.open("teacher.csv");
	for (int i = 0; i < Teacher.size(); i++) {
		fout << Teacher[i].id << ",";
		fout << Teacher[i].name << ",";
		fout << Teacher[i].birthday << ",";
		fout << Teacher[i].phone << ",";
		fout << Teacher[i].address << endl;
	}
	fout.close();
}

thongtin_user login(vector<thongtin_user> &Thongtin)
{
	bool checkLogin = false;
	bool firstLogin = true;
	string user, pass;
	while (checkLogin == false)
	{
		system("cls");
		if (firstLogin == false)
		{
			cout << "user or pass not correct" << endl;
		}
		else firstLogin = false;
		cout << "User: ";
		getline(cin, user);
		cout << "Pass: ";
		get_pass(pass);
	
		for(int i=0;i < Thongtin.size();i++){
			if (user.compare(Thongtin[i].user) == 0 && pass.compare(Thongtin[i].pass) == 0)
			{
				checkLogin == true;
				thongtin_user tt;
				tt.user = user;
				tt.pass = pass;
				tt.admin = Thongtin[i].admin;
				return tt;
			}
		}
	}

}

string cre_teacherid(vector<teacher> &Teacher) {
	vector<teacher> t;
	teacher tc;
	for (int i = 0; i < Teacher.size(); i++) {
		tc.id = Teacher[i].id;
		t.push_back(tc);
	}
	for (int i = 0; i < t.size(); i++) {
		t[i].id.erase(t[i].id.begin() + 0);
	}
	int max = stoi(t[0].id);
	for (int i = 0; i < t.size(); i++) {
		if (stoi(t[i].id) > max) max = stoi(t[i].id); //stoi chuyen string sang int
	}
	max = max + 1;
	if (max < 1000) return "S0" + to_string(max); //to_string chuyen int sang string
	if (max >=1000) return "S" + to_string(max);
}

string cre_studentid(vector<student> &Student) {
	int max = stoi(Student[0].id);
	for (int i = 0; i < Student.size(); i++) {
		if (stoi(Student[i].id) > max) max = stoi(Student[i].id);
	}
	return to_string(max + 1);
}

void change_pass(vector<thongtin_user> &User,string user) {
	for (int i = 0; i < User.size(); i++)
	{
		if (User[i].user.compare(user) == 0) {
			string pass;
			cout << "Enter new password: ";
			getline(cin, pass);
			User[i].pass = pass;
		}
	}
	write_user(User);
	cout << "Change pass successfully" << endl;
	system("pause");
	system("cls");
}

void add_teacher(vector<teacher> &Teacher, vector<thongtin_user> &User) {
	teacher tc;
	thongtin_user u;
	cout << "Teacher_ID: ";
	tc.id = cre_teacherid(Teacher);
	cout << tc.id;
	cout << "\nEnter Teacher_name: ";
	getline(cin, tc.name);
	cout << "Enter Teacher_birthday: ";
	getline(cin, tc.birthday);
	cout << "Enter phone: ";
	getline(cin, tc.phone);
	cout << "Enter address: ";
	getline(cin, tc.address);
	u.user = tc.id;
	u.pass = tc.id;
	u.admin = "teacher";
	Teacher.push_back(tc);
	User.push_back(u);
	write_user(User);
	write_teacher(Teacher);
	cout << "Add Teacher successfully" << endl;
	system("pause");
	system("cls");
}

void add_student(vector<student> &Student, vector<thongtin_user> &User) {
	student st;
	thongtin_user u;
	cout << "Student_ID: ";
	st.id = cre_studentid(Student);
	cout << st.id;
	cout << "\nEnter Student_name: ";
	getline(cin, st.name);
	cout << "Enter Student_birthday: ";
	getline(cin, st.birthday);
	cout << "Enter address: ";
	getline(cin, st.address);
	u.user = st.id;
	u.pass = st.id;
	u.admin = "student";
	Student.push_back(st);
	User.push_back(u);
	write_student(Student);
	write_user(User);
	cout << "Add Student successfully" << endl;
	system("pause");
	system("cls");
}

void del_teacher(vector<teacher> &Teacher, vector<thongtin_user> &User) {
	string id;
	cout << "Enter Teacher_ID need delete: ";
	getline(cin, id);
	int dem = 0;
	for (int i = 0; i < Teacher.size(); i++) {
		if (Teacher[i].id.compare(id) == 0) {
			dem++;
			Teacher.erase(Teacher.begin() + i);
		}
	}
	for (int i = 0; i < User.size(); i++) {
		if (User[i].user.compare(id) == 0) User.erase(User.begin() + i);
	}
	if (dem == 0) cout << "Don't find Teacher of ID" << endl;
	else cout << "Delete successfully" << endl;
	write_teacher(Teacher);
	write_user(User);
	system("pause");
	system("cls");
}

void del_student(vector<student> &Student, vector<thongtin_user> &User) {
	string id;
	cout << "Enter Student_ID need delete: ";
	getline(cin, id);
	int dem = 0;
	for (int i = 0; i < Student.size(); i++) {
		if (Student[i].id.compare(id) == 0) {
			dem++;
			Student.erase(Student.begin() + i);
		}
	}
	for (int i = 0; i < User.size(); i++) {
		if (User[i].user.compare(id) == 0) User.erase(User.begin() + i);
	}
	if (dem == 0) cout << "Don't find Student of ID" << endl;
	else cout << "Delete successfully" << endl;
	write_student(Student);
	write_user(User);
	system("pause");
	system("cls");
}

void display_user(vector<thongtin_user> &User) {
	cout << setw(20) << "User" << setw(25) << "Quyen truy cap" << endl;
	for (int i = 0; i < User.size(); i++) {
		cout <<setw(20)<< User[i].user << setw(25) << User[i].admin << endl;
	}
	system("pause");
	system("cls");
}
void search(vector<student> &Student, vector<teacher> &Teacher) {
	string key;
	cout << "Enter key for search: ";
	getline(cin, key);
	int count_t = 0, count_s = 0;
	for (int i = 0; i < Student.size(); i++) {
		int search = Student[i].name.find(key);
		if (search != -1) {
			count_s++;
		}	
	}
	if (count_s != 0) cout << "\n     - Student: " << endl;
	else cout << "Don't find Student" << endl;
	for (int i = 0; i < Student.size(); i++) {
		int search = Student[i].name.find(key);
		if (search != -1) {
			cout << setw(25)<<Student[i].name << setw(20) << Student[i].id << endl;
		}
	}

	for (int i = 0; i < Teacher.size(); i++) {
		int search = Teacher[i].name.find(key);
		if (search != -1) {
			count_t++;
		}
	}
	if (count_t != 0) cout << "       - Teacher: " << endl;
	else cout << "Don't find Teacher" << endl;
	for (int i = 0; i < Teacher.size(); i++) {
		int search = Teacher[i].name.find(key);
		if (search != -1) {
			cout << setw(25)<<Teacher[i].name << setw(20) << Teacher[i].id << endl;
		}
	}
	system("pause");
	system("cls");
}
void del_multiple(vector<student> &Student, vector<teacher> &Teacher, vector<thongtin_user> &User) {
	string key;
	cout << "Enter key need delete multiple: ";
	getline(cin, key);
	for (int i = 0; i < Student.size(); i++) {
		int search = Student[i].name.find(key);
		if (search != -1) cout << setw(25) << Student[i].name << setw(20) << Student[i].id << endl;
	}
	for (int i = 0; i < Teacher.size(); i++) {
		int search = Teacher[i].name.find(key);
		if (search != -1) cout << setw(25) << Teacher[i].name << setw(20) << Teacher[i].id << endl;
	}
	cout << "Are you sure delete: Yes(Y)   No(N)" << endl;
	cout << "Enter select: ";
	string s;
	getline(cin, s);
	if (s == "Y") {
		for (int i = 0; i < Student.size(); i++) {
			int search = Student[i].name.find(key);
			if (search != -1) {
				for (int j = 0; j < User.size(); j++) {
					if (Student[i].id == User[j].user) User.erase(User.begin() + j);
				}
				Student.erase(Student.begin() + i);
			}
		}
		for (int i = 0; i < Teacher.size(); i++) {
			int search = Teacher[i].name.find(key);
			if (search != -1) {
				for (int j = 0; j < User.size(); j++) {
					if (Teacher[i].id == User[j].user) User.erase(User.begin() + j);
				}
				Teacher.erase(Teacher.begin() + i);
			}
		}
		cout << "Delete Multiple successfully" << endl;
	}

	else cout << "Cancel successfully" << endl;
	system("pause");
	system("cls");
	write_user(User);
	write_teacher(Teacher);
	write_student(Student);
}

void add_subject(vector<course> &Course,string id) {
	int count = 0;
	course c;
	for (int i = 0; i < Course.size(); i++) {
		if (Course[i].teacher_id == id) {
			count++;
		}
	}
	if (count >= 5) {
		cout << "Enough 5 subject, cann't add" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		string id_course;
		cout << "Enter Course_ID: ";
		getline(cin, id_course);
		for (int i = 0; i < Course.size(); i++)
		{
			if (Course[i].course_id == id_course && Course[i].teacher_id == id)
			{
				cout << "Course_ID has registered by teacher" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		c.course_id = id_course;
		c.teacher_id = id;
		cout << "Enter course name: ";
		getline(cin, c.course_name);
		c.n_student = "0";
		cout << "Enter slot: ";
		getline(cin, c.slot);
		Course.push_back(c);
		cout << "Add subject successfully" << endl;
	}
	write_course(Course);
	system("pause");
	system("cls");
}

void enter_score(vector<course> &Course, vector<object> &Object,string user) {
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < Course.size(); i++) {
		if (Course[i].teacher_id == user) {
			count++;
		}
	}
	if (count == 0) cout << "No exist course of teacher" << endl;
	else cout <<" -Course of teacher:\n"<< setw(15) << "Course_ID" << setw(25) << "Name subject" << endl;
	for (int i = 0; i < Course.size(); i++) {
		if (Course[i].teacher_id == user) {
			cout << setw(15) << Course[i].course_id << setw(15) << setw(25) << Course[i].course_name << endl;
		}
	}
	string id_course;
	cout << "Enter Course_ID: ";
	getline(cin, id_course);
	for (int i = 0; i < Object.size(); i++) {
		if (Object[i].course_id == id_course) {
			count1++;
		}
	}
	for (int i = 0; i < Course.size(); i++) {
		if (Course[i].course_id == id_course) {
			count2++;
		}
	}
	if (count2 == 0) {
		cout << "No exist Course_ID of teacher" << endl;
	}
	else {
		if (count1 == 0) cout << "No exist student in subject" << endl;
		else {
			for (int i = 0; i < Object.size(); i++) {
				if (Object[i].course_id == id_course) {
					cout << "Enter score of student ID is " << Object[i].student_id << ": ";
					Object[i].score = score();
				}
			}
			cout << "Enter score for a student successfully" << endl;
		}
	}
	write_course(Course);
	write_object(Object);
	system("pause");
	system("cls");
}

void edit_score(vector<course> &Course, vector<object> &Object,string user) {
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < Course.size(); i++) {
		if (Course[i].teacher_id == user) {
			count++;
		}
	}
	if (count == 0) cout << "No exist course of teacher" << endl;
	else cout << " -Course of teacher:\n" << setw(15) << "Course_ID" << setw(25) << "Name subject" << endl;
	for (int i = 0; i < Course.size(); i++) {
		if (Course[i].teacher_id == user) {
			cout << setw(15) << Course[i].course_id << setw(15) << setw(25) << Course[i].course_name << endl;
		}
	}
	string id_course;
	cout << "Enter Course_ID: ";
	getline(cin, id_course);
	for (int i = 0; i < Object.size(); i++) {
		if (Object[i].course_id == id_course) {
			count1++;
		}
	}
	for (int i = 0; i < Course.size(); i++) {
		if (Course[i].course_id == id_course) {
			count2++;
		}
	}
	if (count2 == 0) {
		cout << "No exist Course_ID of teacher" << endl;
	}
	else {
		if (count1 == 0) cout << "No exist student in subject" << endl;
		else {
			cout << setw(15) << "Student_ID" << setw(20) << "Score" << endl;
			for (int i = 0; i < Object.size(); i++) {
				if (Object[i].course_id == id_course) {
					cout << setw(15) << Object[i].student_id << setw(20) << Object[i].score << endl;
				}
			}
			bool check = true;
			int d=0;
			string id_student;
			while (check == true) {
				if (d == 0) cout << "Enter Student_id: ";
				else cout << "Please re-enter Student_id: ";
				d++;
				getline(cin, id_student);
				for (int i = 0; i < Object.size(); i++) {
					if (Object[i].student_id == id_student) {
						cout << "Enter score of student_id is " << Object[i].student_id << ": ";
						Object[i].score = score();
						check = false;
						break;
					}
				}
			}
			cout << "Edit score for a student successfully" << endl;
		}
	}
	write_course(Course);
	write_object(Object);
	system("pause");
	system("cls");
}

void list_subject(vector<course> &Course,string user)
{
	int count = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (Course[i].teacher_id == user)
		{
			count++;
		}
	}
	if (count == 0) cout << "No exist course of teacher" << endl;
	else
	{
		cout << setw(15) << "Course_ID" << setw(25) << "Course_name" << setw(15) << "Teacher_ID" << setw(15) << "n_student" << setw(10) << "Slot" << endl;
		for (int i = 0; i < Course.size(); i++)
		{
			if (Course[i].teacher_id == user)
			{
				cout << setw(15) << Course[i].course_id << setw(25) << Course[i].course_name << setw(15) << Course[i].teacher_id << setw(15) << Course[i].n_student << setw(10) << Course[i].slot << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void register_subject(vector<course> &Course, vector<object> &Object, string user) {
	int count = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if (Object[i].student_id == user) count++;
	}
	cout << "Credits present register is: " << 4 * count << endl;
	cout << setw(25) << "Available subjects of teachers:" << endl;
	cout << setw(15) << "Course_ID" << setw(25) << "Course_name" << setw(15) << "Teacher_ID" << setw(15) << "n_student" << setw(10) << "Slot" << endl;
	for (int i = 0; i < Course.size(); i++)
	{
		cout << setw(15) << Course[i].course_id << setw(25) << Course[i].course_name << setw(15) << Course[i].teacher_id << setw(15) << Course[i].n_student << setw(10) << Course[i].slot << endl;
	}
	
	if (count >= 5) cout << "Enough 20 credits present. Can not register" << endl;
	else
	{
		string id;
		int d = 0;
		bool check = true;
		while (check == true)
		{
			if (d == 0) cout << "Enter Course_ID need register: ";
			else cout << "Please re-enter Course_ID need register: ";
			d++;
			getline(cin, id);
			for (int i = 0; i < Object.size(); i++)
			{
				if (Object[i].course_id == id && Object[i].student_id == user)
				{
					cout << "You has registered subject" << endl;
					system("pause");
					system("cls");
					return;
				}
			}
			for (int i = 0; i < Course.size(); i++)
			{
				if (Course[i].course_id == id)
				{
					bool check1 = true;
					int k = 0;
					string id_teacher;
					while (check1 == true)
					{
						if (k == 0) cout << "Enter Teacher_ID: ";
						else cout << "Please re-enter Teacher_ID: ";
						k++;
						getline(cin, id_teacher);
						for (int j = 0; j < Course.size(); j++)
						{
							if (Course[j].teacher_id == id_teacher && Course[i].course_id == Course[j].course_id)
							{
								object o;
								o.course_id = Course[j].course_id;
								o.student_id = user;
								o.teacher_id = Course[j].teacher_id;
								o.score = "-1";
								o.semeter_id = "171";
								Object.push_back(o);
								int n = stoi(Course[j].n_student) + 1;
								Course[j].n_student = to_string(n);
								check1 = false;
								break;
							}
						}
					}
					check = false;
					break;

				}
				
			}
		}
		cout << "Register subject successfully" << endl;
	}
	write_course(Course);
	write_object(Object);
	system("pause");
	system("cls");
}

void cancel_subject(vector<course> &Course, vector<object> &Object, string user) {
	int count = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if (Object[i].student_id == user)
		{
			count++;
		}
	}
	if (count == 0) cout << "No exist subject of student" << endl;
	else
	{
		cout << setw(25) << "Available subjects of student: " << endl;
		cout << setw(15) << "Course_ID" << setw(15) << "Teacher_ID" << endl;
		for (int i = 0; i < Object.size(); i++)
		{
			if (Object[i].student_id == user)
			{
				cout << setw(15) << Object[i].course_id << setw(15) << Object[i].teacher_id << endl;
			}
		}
		string id;
		int d = 0;
		bool check = true;
		while (check == true)
		{
			if (d == 0) cout << "Enter Course_ID need cancel: ";
			else cout << "Please re-enter Course_ID need cancel: ";
			d++;
			getline(cin, id);
			for (int i = 0; i < Course.size(); i++)
			{
				if (Course[i].course_id == id)
				{
					bool check1 = true;
					int k = 0;
					string id_teacher;
					while (check1 == true)
					{
						if (k == 0) cout << "Enter Teacher_ID: ";
						else cout << "Please re-enter Teacher_ID: ";
						k++;
						getline(cin, id_teacher);
						for(int j=0;j<Course.size();j++)
						{
							if (Course[j].teacher_id == id_teacher && Course[i].course_id==Course[j].course_id)
							{
								for (int k = 0; k < Object.size(); k++)
								{
									if (Object[k].teacher_id == id_teacher && Object[k].course_id == id)
									{
										Object.erase(Object.begin() + k);
									}
								}
								int n = stoi(Course[j].n_student) - 1;
								Course[j].n_student = to_string(n);
								check1 = false;
								break;
							}
						
							
						}
					}
					check = false;
					break;
				}
			}
		}
		cout << "Cancel subject successfully" << endl;
	}
	write_course(Course);
	write_object(Object);
	system("pause");
	system("cls");
}

void search_subject(vector<course> &Course)
{
	string key;
	int count = 0;
	cout << "Enter the key to search: ";
	getline(cin, key);
	for (int i = 0; i < Course.size(); i++)
	{
		int search = Course[i].course_name.find(key);
		if (search != -1) count++;
	}
	if (count == 0) cout << "Don't find subject" << endl;
	else
	{
		cout << setw(15) << "Course_ID" << setw(25) << "Course_name" << setw(15) << "Teacher_ID" << setw(15) << "Slot" << endl;
		for (int i = 0; i < Course.size(); i++)
		{
			int search = Course[i].course_name.find(key);
			if (search != -1)
			{
				cout << setw(15) << Course[i].course_id << setw(25) << Course[i].course_name << setw(15) << Course[i].teacher_id << setw(15) << Course[i].slot << endl;
			}

		}
	}
	system("pause");
	system("cls");
}

void see_learning(vector<course> &Course, vector<object> &Object, string user)
{
	int count = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if (Object[i].student_id == user && Object[i].score == "-1") count++;
	}
	if (count == 0) cout << "No exist elearning subjects" << endl;
	else
	{
		cout << setw(15) << "Course_ID" << setw(25) << "Course_name" << setw(15) << "Teacher_ID" << endl;
		for (int i = 0; i < Object.size(); i++)
		{
			if (Object[i].student_id == user && Object[i].score == "-1")
			{
				for (int j = 0; j < Course.size(); j++)
				{
					if (Course[j].teacher_id == Object[i].teacher_id && Course[j].course_id==Object[i].course_id) {
						cout << setw(15) << Course[j].course_id << setw(25) << Course[j].course_name << setw(15) << Course[j].teacher_id << endl;
					}
				}
			}
		}
	}
	system("pause");
	system("cls");
}

void see_registered(vector<course> &Course, vector<object> &Object, string user)
{
	int count = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if (Object[i].student_id == user) count++;
	}
	if (count == 0) cout << "No exist registered subjects" << endl;
	else
	{
		cout << setw(15) << "Course_ID" << setw(25) << "Course_name" << setw(15) << "Teacher_ID" << endl;
		for (int i = 0; i < Object.size(); i++)
		{
			if (Object[i].student_id == user)
			{
				for (int j = 0; j < Course.size(); j++)
				{
					if (Course[j].teacher_id == Object[i].teacher_id && Course[j].course_id == Object[i].course_id) {
						cout << setw(15) << Course[j].course_id << setw(25) << Course[j].course_name << setw(15) << Course[j].teacher_id << endl;
					}
				}
			}
		}
	}
	system("pause");
	system("cls");
}

void cal_gpa(vector<object> &Object, string user)
{
	float gpa = 0;
	int count = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if (Object[i].student_id == user)
		{
			gpa += stof(Object[i].score);
			count++;
		}
	}
	gpa = gpa / count;
	cout << "\nStudent has " << user << " is GPA: " << gpa << endl;
}

void indivadual_infor(vector<student> &Student,string user)
{
	for (int i = 0; i < Student.size(); i++)
	{
		if (Student[i].id == user)
		{
			cout << "Student name: " << Student[i].name << endl;
			cout << "Student ID: " << Student[i].id << endl;
			cout << "Student birthday: " << Student[i].birthday << endl;
			cout << "Student address: " << Student[i].address;
			return;
		}
	}
}
void summation(vector<object> &Object,vector<course> &Course, string user)
{
	int count = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (Course[i].teacher_id == user) count++;
	}
	if (count == 0) cout << "No exist course of teacher" << endl;
	else
	{
		cout << setw(15) << "Course_ID" << setw(25) << "Course_name" << endl;
		for (int i = 0; i < Course.size(); i++)
		{
			if (Course[i].teacher_id == user)
			{
				cout << setw(15) << Course[i].course_id << setw(25) << Course[i].course_name << endl;
			}
		}
		string id;
		int d = 0;
		bool check = true;
		while (check == true)
		{
			if (d == 0) cout << "Enter Course_ID need summation: ";
			else cout << "Please re-enter Course_ID need summation: ";
			getline(cin, id);
			d++;
			int k = 0;
			for (int i = 0; i < Object.size(); i++)
			{
				if (Object[i].course_id == id && Object[i].teacher_id == user)
				{
					k++;
				}
			}
			if (k == 0)
			{
				cout << "No exist student of course" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << setw(15) << "Student_ID" << setw(15) << "Score" << endl;
				for (int i = 0; i < Object.size(); i++)
				{
					if (Object[i].course_id == id && Object[i].teacher_id == user)
					{
						cout << setw(15) << Object[i].student_id << setw(15) << Object[i].score << endl;
					}
				}
				cout << "Summation the point successfully" << endl;
				check = false;
			}
		}	
	}
	system("pause");
	system("cls");
}

void menu() {
	thongtin_user infor = login(User);
	if (infor.admin == "admin") {
		while (true) {
			system("cls");
			int select;
			cout << "---------------------------ADMINISTRATOR---------------------------" << endl;
			cout << "0. Logout" << endl;
			cout << "1. Change pass" << endl;
			cout << "2. Add Teacher" << endl;
			cout << "3. Add Student" << endl;
			cout << "4. Delete Teacher" << endl;
			cout << "5. Delete Student" << endl;
			cout << "6. Display list User" << endl;
			cout << "7. Search name Teacher/Student by keyword" << endl;
			cout << "8. Delete Multi_Student of name: " << endl;
			cout << "9. Exit" << endl;
			char c;
			int d = 0;
			do
			{
				if (d == 0)
					printf("Enter select: ");
				if (d != 0)
					printf("Please re-enter select: ");
				d = d + 1;
			} while (((scanf_s("%d%c", &select, &c) != 2 || c != '\n') && clean_stdin() || select<0 || select>9));
			switch (select) {
			case 0:
				menu();
				break;
			case 1:
				change_pass(User, infor.user);
				break;
			case 2:
				add_teacher(Teacher, User);
				break;
			case 3:
				add_student(Student, User);
				break;
			case 4:
				del_teacher(Teacher, User);
				break;
			case 5:
				del_student(Student, User);
				break;
			case 6:
				display_user(User);
				break;
			case 7:
				search(Student, Teacher);
				break;
			case 8:
				del_multiple(Student, Teacher, User);
				break;
			case 9:
				exit(0);
			}
		}
	}
	else if (infor.admin == "teacher") {
		while (true) {
			system("cls");
			int select;
			cout << "---------------------------TEACHER---------------------------" << endl;
			cout << "0. Logout" << endl;
			cout << "1. Change pass" << endl;
			cout << "2. Add the subject" << endl;
			cout << "3. Enter score for a students" << endl;
			cout << "4. Edit score for a students" << endl;
			cout << "5. Summation point" << endl;
			cout << "6. See the list of subject opened" << endl;
			cout << "7. Exit" << endl;
			char c;
			int d = 0;
			do
			{
				if (d == 0)
					printf("Enter select : ");
				if (d != 0)
					printf("Please re-enter select: ");
				d = d + 1;
			} while (((scanf_s("%d%c", &select, &c) != 2 || c != '\n') && clean_stdin() || select<0 || select>7));
			switch (select) {
			case 0:
				menu();
				break;
			case 1:
				change_pass(User, infor.user);
				break;
			case 2:
				add_subject(Course, infor.user);
				break;
			case 3:
				enter_score(Course, Object, infor.user);
				break;
			case 4:
				edit_score(Course, Object, infor.user);
				break;
			case 5:
				summation(Object, Course, infor.user);
				break;
			case 6:
				list_subject(Course, infor.user);
				break;
			case 7:
				exit(0);

			}
		}
	}

	else if (infor.admin == "student") {
		while (true) {
			system("cls");
			int select;
			cout << "---------------------------STUDENT---------------------------" << endl;
			cout << "0. Logout" << endl;
			cout << "1. Change pass" << endl;
			cout << "2. Register subject" << endl;
			cout << "3. Cancel subject" << endl;
			cout << "4. Search subject" << endl;
			cout << "5. See the list of learning subjects" << endl;
			cout << "6. See the list of registered subjects" << endl;
			cout << "7. See GPA and individual information" << endl;
			cout << "8. Exit" << endl;
			char c;
			int d = 0;
			do
			{
				if (d == 0)
					printf("Enter select: ");
				if (d != 0)
					printf("Please re-enter select: ");
				d = d + 1;
			} while (((scanf_s("%d%c", &select, &c) != 2 || c != '\n') && clean_stdin() || select < 0 || select>8));
			switch (select) {
			case 0:
				menu();
				break;
			case 1:
				change_pass(User, infor.user);
				break;
			case 2:
				register_subject(Course, Object, infor.user);
				break;
			case 3:
				cancel_subject(Course, Object, infor.user);
				break;
			case 4:
				search_subject(Course);
				break;
			case 5:
				see_learning(Course, Object, infor.user);
				break;
			case 6:
				see_registered(Course, Object, infor.user);
				break;
			case 7:
				indivadual_infor(Student, infor.user);
				cal_gpa(Object, infor.user);
				system("pause");
				system("cls");
			case 8:
				exit(0);
			}
		}
		

	}
}

int main() {
	read_user(User);
	read_student(Student);
	read_teacher(Teacher);
	read_course(Course);
	read_object(Object);
	menu();
}