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
struct thongtinuser
{
	string user;
	string pass;
	string admin;
};
struct teacher
{
	string mscb;
	string hoten;
	string ngaysinh;
	string sdt;
	string diachi;
};
struct student
{
	string id;
	string hoten;
	string ngaysinh;
	string diachi;
};
vector<thongtinuser> Thongtin;
vector<teacher> Teacher;
vector<student> Student;
// clear stdin
int clean_stdin()
{
	while (getchar() != '\n')
	{
	}
	return 1;
}

string nhap()
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

// chuyen doi string thanh char*
int chuyendoistringthanhint(string str)
{
	char* ch = new char[str.length()];
	for (int i = 0; i < str.length(); i++)
	{
		ch[i] = str[i];
	}
	int x = atoi(ch);
	return x;
}
// doc file user.csv
string chuyenintthanhstring(int &t)
{
	ostringstream oss;
	oss << t;
	return oss.str();
}
void readuser(vector<thongtinuser> &Thongtin)
{
	thongtinuser tt;
	ifstream fin;
	fin.open("user.csv");
	while (fin.eof() == false)
	{
		getline(fin, tt.user, ',');
		getline(fin, tt.pass, ',');
		getline(fin, tt.admin);
		Thongtin.push_back(tt);
	}
	int x = Thongtin.size() - 1;
	Thongtin.erase(Thongtin.begin() + x);
	fin.close();
}

// doc file teacher.csv
void readteacher(vector<teacher> &Teacher)
{
	teacher tc;
	ifstream fin;
	fin.open("teacher.csv");
	while (!fin.eof())
	{
		getline(fin, tc.mscb, ',');
		getline(fin, tc.hoten, ',');
		getline(fin, tc.ngaysinh, ',');
		getline(fin, tc.sdt, ',');
		getline(fin, tc.diachi, '\n');
		Teacher.push_back(tc);
	}
	int x = Teacher.size() - 1;
	Teacher.erase(Teacher.begin() + x);
}

//doc file student.csv
void readstudent(vector<student> &Student)
{
	student st;
	ifstream fin;
	fin.open("student.csv");
	while (fin.eof() == false)
	{
		getline(fin, st.id, ',');
		getline(fin, st.hoten, ',');
		getline(fin, st.ngaysinh, ',');
		getline(fin, st.diachi, '\n');
		Student.push_back(st);
	}
	int x = Student.size() - 1;
	Student.erase(Student.begin() + x);
	fin.close();
}

struct course
{
	string id;
	string teacher_id;
	string name;
	string n_student;
	string slot;
};

vector<course> Course;

//doc file course
void readcourse(vector<course> &Course)
{
	course c;
	ifstream fin;
	fin.open("course.csv");
	string x;
	getline(fin, x);
	while (!fin.eof())
	{
		getline(fin, c.id, ',');
		getline(fin, c.teacher_id, ',');
		getline(fin, c.name, ',');
		getline(fin, c.n_student, ',');
		getline(fin, c.slot);
		Course.push_back(c);
	}
	int y = Course.size() - 1;
	Course.erase(Course.begin() + y);
	fin.close();
}

struct object
{
	string id;
	string student_id;
	string teacher_id;
	string score;
	string semeter_id;
};
vector<object> Object;
//doc file object
void readobject(vector<object> &Object)
{
	object O;
	ifstream fin;
	fin.open("object.csv");
	string x;
	getline(fin, x);
	while (!fin.eof())
	{
		getline(fin, O.id, ',');
		getline(fin, O.student_id, ',');
		getline(fin, O.teacher_id, ',');
		getline(fin, O.score, ',');
		getline(fin, O.semeter_id);
		Object.push_back(O);
	}
	int y = Object.size() - 1;
	Object.erase(Object.begin() + y);
	fin.close();
}


// kiem tra dang nhap
thongtinuser login(vector<thongtinuser> &Thongtin)
{
	bool checkLogin = false;
	ifstream fin;
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
		getline(cin, pass);
		int i = 0;
		while (i < Thongtin.size())
		{
			if (user.compare(Thongtin[i].user) == 0 && pass.compare(Thongtin[i].pass) == 0)
			{
				checkLogin == true;
				thongtinuser tt;
				tt.user = user;
				tt.pass = pass;
				tt.admin = Thongtin[i].admin;
				cout << Thongtin[i].admin << "\n";;
				return tt;
			}
			i++;
		}
	}

}

//ghi vao file user
void writeuser(vector<thongtinuser> &Thongtin)
{

	ofstream fout("user.csv", ios::trunc);
	for (int i = 0; i < Thongtin.size(); i++)
	{
		fout << Thongtin[i].user << ',';
		fout << Thongtin[i].pass << ',';
		fout << Thongtin[i].admin << endl;
	}
	fout.close();
}

// ghi vao file student
void writestudent(vector<student> &Student)
{
	ofstream fout;
	fout.open("student.csv", ios::trunc);
	for (int i = 0; i < Student.size(); i++)
	{
		fout << Student[i].id << ",";
		fout << Student[i].hoten << ",";
		fout << Student[i].ngaysinh << ",";
		fout << Student[i].diachi << endl;
	}
	fout.close();
}

//ghi vao file teacher
void writeteacher(vector<teacher> &Teacher)
{
	ofstream fout;
	fout.open("teacher.csv", ios::trunc);
	for (int i = 0; i < Teacher.size(); i++)
	{
		fout << Teacher[i].mscb << ",";
		fout << Teacher[i].hoten << ",";
		fout << Teacher[i].ngaysinh << ",";
		fout << Teacher[i].sdt << ",";
		fout << Teacher[i].diachi << endl;
	}
	fout.close();
}

//ghi vao file coures
void writecourse(vector<course> &Course)
{
	ofstream fout;
	fout.open("course.csv", ios::trunc);
	fout << "Course_ID,Teacher_ID,Name,n_student,slot\n";
	for (int i = 0; i < Course.size(); i++)
	{
		fout << Course[i].id << ",";
		fout << Course[i].teacher_id << ",";
		fout << Course[i].name << ",";
		fout << Course[i].n_student << ",";
		fout << Course[i].slot << "\n";
	}
	fout.close();
}

//ghi vao file object
void writeobject(vector<object> &Object)
{
	ofstream fout;
	fout.open("object.csv");
	fout << "Course_id,Student_id,Teacher_id,Score,semeter_id\n";
	for (int i = 0; i < Object.size(); i++)
	{
		fout << Object[i].id << ',';
		fout << Object[i].student_id << ',';
		fout << Object[i].teacher_id << ',';
		fout << Object[i].score << ',';
		fout << Object[i].semeter_id << endl;
	}
	fout.close();
}
//doi mat khau

void doimatkhau(vector<thongtinuser> &Thongtin, string user)
{
	string matkhaumoi;
	cout << "Nhap mat khau moi: ";
	getline(cin, matkhaumoi);
	int i = 0;
	while (i < Thongtin.size() - 1)
	{
		if (user.compare(Thongtin[i].user) == 0)
		{
			Thongtin[i].pass = matkhaumoi;
		}
		i++;
	}
	writeuser(Thongtin);
	cout << "Ban da doi mat khau thanh cong!" << endl;
	system("pause");
	system("cls");
}

string taoid(vector<teacher> Teacher)
{
	vector<string> b(Teacher.size());
	for (int i = 0; i < Teacher.size(); i++)
	{
		string a;
		for (int j = 1; j < Teacher[i].mscb.length(); j++)
		{
			a = a + Teacher[i].mscb[j];
		}
		b[i] = a;
	}
	int min = chuyendoistringthanhint(b[0]);
	for (int i = 0; i < b.size(); i++)
	{
		if (min > chuyendoistringthanhint(b[i]))
		{
			min = chuyendoistringthanhint(b[i]);
		}
	}
	for (int j = min;; j++)
	{
		int d = 0;
		for (int i = 0; i <b.size(); i++)
		{
			if (j == chuyendoistringthanhint(b[i]))
			{
				break;
			}
			else d++;
		}
		if (d == b.size() && j<1000) return "S0" + chuyenintthanhstring(j);
		if (d == b.size() && j >= 1000) return 'S' + chuyenintthanhstring(j);

	}


}
//tao id auto
string taoidauto(vector<student> Student)
{
	int min = chuyendoistringthanhint(Student[0].id);
	for (int i = 0; i < Student.size(); i++)
	{
		if (min > chuyendoistringthanhint(Student[i].id))
		{
			min = chuyendoistringthanhint(Student[i].id);
		}
	}
	for (int j = min;; j++)
	{
		int d = 0;
		for (int i = 0; i < Student.size(); i++)
		{
			if (j == chuyendoistringthanhint(Student[i].id))
			{
				break;
			}
			else d++;
		}
		if (d == Student.size()) return chuyenintthanhstring(j);
	}

}

//them sinh vien
void themsinhvien(vector<thongtinuser>&Thongtin, vector<student> &Student)
{
	thongtinuser tt;
	student st;
	cout << "ID cua sinh vien: ";
	cout << taoidauto(Student) << endl;
	st.id = taoidauto(Student);
	cout << "Nhap vao ten sinh vien: ";
	getline(cin, st.hoten);
	cout << "Nhap vao ngay sinh: ";
	getline(cin, st.ngaysinh);
	cout << "Nhap vao dia chi: ";
	getline(cin, st.diachi);
	// ten login,pass ban dau = mssv;
	tt.user = st.id;
	tt.pass = tt.user;
	tt.admin = "student";
	Thongtin.push_back(tt);
	Student.push_back(st);
	cout << "Them thanh cong!\n";
	writestudent(Student);
	writeuser(Thongtin);
	system("pause");
	system("cls");
}

//them giang vien
void themgiangvien(vector<thongtinuser>&Thongtin, vector<teacher> &Teacher)
{
	thongtinuser tt;
	teacher tc;
	cout << "ID cua giang vien la: ";
	cout << taoid(Teacher) << endl;
	cout << "Nhap vao ten giang vien: ";
	getline(cin, tc.hoten);
	cout << "Nhap vao ngay sinh: ";
	getline(cin, tc.ngaysinh);
	cout << "Nhap vao sdt: ";
	getline(cin, tc.sdt);
	cout << "Nhap vao dia chi: ";
	getline(cin, tc.diachi);
	// ten login,pass ban dau =mscb;
	tc.mscb = taoid(Teacher);
	tt.user = tc.mscb;
	tt.pass = tt.user;
	tt.admin = "teacher";
	Thongtin.push_back(tt);
	Teacher.push_back(tc);
	writeteacher(Teacher);
	writeuser(Thongtin);
	cout << "Them thanh cong!\n";
	system("pause");
	system("cls");
}

//xem danh sach user
void dsuser(vector<thongtinuser> &Thongtin)
{
	int i = 0;
	cout << setw(15) << "User" << setw(25) << "Quyen truy cap" << endl;
	while (i < Thongtin.size())
	{
		cout << setw(15)<<Thongtin[i].user<<setw(25)<<Thongtin[i].admin << endl;
		i = i++;
	}
	system("pause");
	system("cls");
}

// xoa giang vien
void xoagiangvien(vector<teacher> Teacher, vector<thongtinuser> Thongtin)
{
	// xoa vector 
	int d = 0;
	string x;
	cout << "Nhap vao ID cua giang vien can xoa: ";
	cin >> x;
	for (int i = 0; i < Thongtin.size(); i++)
	{
		if (Thongtin[i].user.compare(x) == 0)
		{
			Thongtin.erase(Thongtin.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < Teacher.size(); i++)
	{
		if (Teacher[i].mscb.compare(x) == 0)
		{
			Teacher.erase(Teacher.begin() + i);
			i--;
			d = d++;
		}

	}
	if (d == 0) cout << "Khong co giang vien nay!" << endl;
	else
	{
		cout << "Da xoa thanh cong " << d << " giang vien!" << endl;
	}
	system("pause");
	system("cls");
	writeteacher(Teacher);
	writeuser(Thongtin);
}

//xoa sinh vien
void xoasinhvien(vector<student> &Student, vector<thongtinuser> &Thongtin)
{
	// xoa vector 
	string x;
	int d = 0;
	cout << "Nhap ID cua sinh vien can xoa: ";
	cin >> x;
	for (int i = 0; i < Thongtin.size(); i++)
	{
		if (Thongtin[i].user.compare(x) == 0)
		{
			Thongtin.erase(Thongtin.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < Student.size(); i++)
	{
		if (Student[i].id.compare(x) == 0)
		{
			Student.erase(Student.begin() + i);
			i--;
			d = d++;
		}
	}
	if (d == 0) cout << "Khong co sinh vien nay." << endl;
	else
	{
		cout << "Da xoa thanh cong " << d << " sinh vien." << endl;
	}
	system("pause");
	system("cls");
	writestudent(Student);
	writeuser(Thongtin);
}

//mo mon hoc
void momonhoc(string user, vector<course> &Course)
{
	course c;
	//kiem tra da mo du nam mon chua
	int d = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (user.compare(Course[i].teacher_id) == 0)
		{
			d = d + 1;
		}
	}
	if (d == 5)
	{
		cout << "Da du 5 mon khong the mo them.\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "Nhap ID mon hoc can mo: ";
		getline(cin, c.id);
		cout << "Nhap ten mon hoc: ";
		getline(cin, c.name);
		cout << "Nhap vao so luong slot: ";
		getline(cin, c.slot);

		c.teacher_id = user;
		c.n_student = "0";
	}
	int dem = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (c.id.compare(Course[i].id) == 0 && c.teacher_id.compare(Course[i].teacher_id) == 0)
		{
			cout << "Mon nay da duoc giang vien mo truoc do.\n";
			dem++;
			system("pause");
			system("cls");
			return;
		}
	}
	if (dem == 0) cout << "Ban da mo mon hoc thanh cong!" << endl;
	Course.push_back(c);
	system("pause");
	system("cls");
}

//nhap diem 
void nhapdiem(string user, vector<object> &Object, vector<course> &Course)
{
	//kiem tra giang vien co day mon nao ko 
	int d = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (user.compare(Course[i].teacher_id) == 0)
		{
			d = d + 1;
		}
	}
	if (d == 0)
	{
		cout << "Giang vien chua mo mon hoc nao.\n";
		system("pause");
		system("cls");
		return;
	}

	//in ra cac mon giang vien day.
	cout << "Cac mon hoc giang vien dang day:\n";
	cout << setw(10) << "ID mon hoc" << setw(30) << "Ten mon hoc" << endl;
	for (int i = 0; i < Course.size(); i++)
	{
		if (user.compare(Course[i].teacher_id) == 0)
		{
			cout << setw(10) << Course[i].id << setw(30) << Course[i].name << endl;
		}
	}
	string mamonhoc;
	cout << "Nhap vao ID mon hoc can nhap diem: ";
	cin >> mamonhoc;
	// kiem tra co sinh vien dang hoc hay ko
	int k = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if (mamonhoc.compare(Object[i].id) == 0)
		{
			k = k + 1;
		}
	}
	if (k == 0)
	{
		cout << "Khong co sinh vien hoc mon nay.\n";
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < Object.size(); i++)
	{
		if (((Object[i].id).compare(mamonhoc) == 0) && ((Object[i].teacher_id).compare(user) == 0))
		{
			cout << "Nhap diem cua sinh vien co ID " << Object[i].student_id << ": ";
			string score = nhap();
			Object[i].score = score;
		}
	}
	system("pause");
	system("cls");
}


//xem danh sach mon hoc da mo
void xemdanhsachmonhocgiangvien(string user)
{
	int d = 0;
	cout << setw(15) << "ID mon hoc" << setw(30) << "Ten mon hoc" << setw(20) << "slot" << setw(20) << "n_students" << endl;
	for (int i = 0; i < Course.size(); i++)
	{
		if (user.compare(Course[i].teacher_id) == 0)
		{
			d = d + 1;
			cout << setw(15) << Course[i].id << setw(30) << Course[i].name << setw(20) << Course[i].slot << setw(20) << Course[i].n_student << endl;
		}
	}
	if (d == 0)
	{
		cout << "Giang vien chua mo mon hoc nao.\n";
	}
	system("pause");
	system("cls");
}

struct diemtongket
{
	string id;
	string student_id;
	string teacher_id;
	string diemtk;
};
vector<diemtongket> Tongket;

//doc file tong ket
void readtongket(vector<diemtongket> &Tongket)
{
	diemtongket tk;
	ifstream fin;
	fin.open("tongket.csv");
	while (!fin.eof())
	{
		getline(fin, tk.id, ',');
		getline(fin, tk.student_id, ',');
		getline(fin, tk.teacher_id, ',');
		getline(fin, tk.diemtk);
		Tongket.push_back(tk);
	}
	fin.close();
	int x = Tongket.size() - 1;
	Tongket.erase(Tongket.begin() + x);
}

//ghi file tongket
void writetongket(vector<diemtongket> &Tongket)
{
	ofstream fout;
	fout.open("tongket.csv");
	for (int i = 0; i < Tongket.size(); i++)
	{
		fout << Tongket[i].id << ',';
		fout << Tongket[i].student_id << ',';
		fout << Tongket[i].teacher_id << ',';
		fout << Tongket[i].diemtk << endl;
	}
	fout.close();
}

void writetongket1()
{
	ofstream fout;
	fout.open("tongket.csv");
	fout << "Course_ID,Student_ID,Teacher_ID,Score" << endl;
	fout.close();
}

//tong ket diem.
void tongket(string user, vector<object> &Object, vector<course> &Course, vector<diemtongket> &Tongket)
{
	// Kiem tra giang vien co day mon nao ko
	int d = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (user.compare(Course[i].teacher_id) == 0)
		{
			d = d + 1;
		}
	}
	if (d == 0)
	{
		cout << "giang vien dang khong day mon hoc nao.\n";
		system("pause");
		system("cls");
		return;
	}

	// in ra list mon hoc cua giang vien
	cout << "list mon hoc cua giang vien:\n";
	cout << "ID mon hoc" << setw(30) << "Ten mon hoc" << endl;
	for (int i = 0; i < Course.size(); i++)
	{
		if (user.compare(Course[i].teacher_id) == 0)
		{
			cout << setw(10) << Course[i].id << setw(30) << Course[i].name << endl;
		}
	}

	diemtongket tk;
	//nhap mon hoc can tong ket
	cout << "nhap ID mon can tong ket diem: ";
	string mamonhoc;
	getline(cin, mamonhoc);
	// kiem tra mon nhap vao da tong ket chua

	for (int i = 0; i < Tongket.size(); i++)
	{
		if (Tongket[i].id.compare(mamonhoc) == 0 && Tongket[i].teacher_id.compare(user) == 0)
		{
			cout << "Mon hoc nay da duoc tong ket!\n";
			system("pause");
			system("cls");
			return;
		}
	}

	//tong ket diem cua mon hoc nhap vao
	int k = 0;
	cout << setw(15) << "ID_student" << setw(30) << "Diem tong ket\n";
	for (int i = 0; i < Object.size(); i++)
	{
		if (mamonhoc.compare(Object[i].id) == 0 && user.compare(Object[i].teacher_id) == 0)
		{
			cout << setw(15) << Object[i].student_id;
			cout << setw(28) << Object[i].score << endl;
			tk.id = Object[i].id;
			tk.student_id = Object[i].student_id;
			tk.teacher_id = Object[i].teacher_id;
			tk.diemtk = Object[i].score;
			Tongket.push_back(tk);
		}
	}

	cout << "Tong ket diem thanh cong!\n";
	system("pause");
	system("cls");
}

//sua diem 
void suadiem(string user)
{
	//kiem tra giang vien co day mon nao ko 
	int d = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (user.compare(Course[i].teacher_id) == 0)
		{
			d = d + 1;
		}
	}
	if (d == 0)
	{
		cout << "giang vien chua mo mon hoc nao.\n";
		system("pause");
		system("cls");
		return;
	}

	//in ra cac mon giang vien day.
	cout << "cac mon hoc giang vien dang day:\n";
	cout << setw(10) << "ID Mon Hoc" << setw(30) << "Ten Mon Hoc" << endl;
	for (int i = 0; i < Course.size(); i++)
	{
		if (user.compare(Course[i].teacher_id) == 0)
		{
			cout << setw(10) << Course[i].id << setw(30) << Course[i].name << endl;
		}
	}
	string mamonhoc;
	cout << "Nhap vao ID mon hoc can sua diem: ";
	cin >> mamonhoc;
	// kiem tra co sinh vien dang hoc hay ko
	int k = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if (mamonhoc.compare(Object[i].id) == 0)
		{
			k = k + 1;
		}
	}
	if (k == 0)
	{
		cout << "Khong co sinh vien hoc mon nay.\n";
		system("pause");
		system("cls");
		return;
	}
	else
		//in ra danh sach sinh vien dang hoc mon nay
	{
		cout << setw(15) << "ID Sinh Vien" << setw(30) << "Ten Sinh Vien" << setw(25) << "Diem Mon Hoc\n";
		for (int i = 0; i < Object.size(); i++)
		{
			if (((Object[i].id).compare(mamonhoc) == 0) && ((Object[i].teacher_id).compare(user) == 0))
			{
				for (int j = 0; j < Student.size(); j++)
				{
					if (Object[i].student_id.compare(Student[j].id) == 0)
					{
						cout << setw(15) << Student[j].id << setw(30) << Student[j].hoten << setw(20) << Object[i].score << endl;
					}
				}
			}
		}
	}
	cout << "nhap ID cua sinh vien muon sua diem: ";
	string y;
	cin >> y;

	int dem = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if (y.compare(Object[i].student_id) == 0)
		{
			dem++;
		}
	}
	if (dem == 0)
	{
		cout << "Khong co sinh vien nay trong mon hoc cua ban. Vui long kiem tra lai." << endl;
		return;
	}

	for (int i = 0; i < Object.size(); i++)
	{
		if (((Object[i].id).compare(mamonhoc) == 0) && ((Object[i].teacher_id).compare(user) == 0) && Object[i].student_id.compare(y) == 0)
		{

			cout << "Nhap lai diem ban muon sua cua sinh vien co ID " << Object[i].student_id << ": ";
			string score = nhap();
			Object[i].score = score;
			for (int i = 0; i < Object.size(); i++)
			{
				for (int j = 0; j < Tongket.size(); j++)
				{
					if (Object[i].id == Tongket[j].id && Object[i].student_id == Tongket[j].student_id && Object[i].teacher_id == Tongket[j].teacher_id)
					{
						Tongket[j].diemtk = Object[i].score;
					}
				}
			}
		}
	}
	cout << "Ban da sua diem thanh cong!" << endl;
	system("pause");
	system("cls");
}

// dang ki mon hoc
void dangkimonhoc(string id, vector<object> &Object, vector<course> &Course)
{
	object dk;
	int d = 0;
	//kiem tra da du so chi chua(moi mon tuong ung vs 4 chi)
	for (int i = 0; i < Object.size(); i++)
	{
		if (id.compare(Object[i].student_id) == 0)
		{
			d = d + 1;
		}
	}
	if (d >= 5)
	{
		cout << "Da du so tin chi quy dinh khong the dang ki them.\n";
		system("pause");
		system("cls");
		return;
	}
	cout << endl;

	// xem dang sach mon co the dang ki
	cout << "So tin chi ban da dang ki : " << 4 * d << endl;
	cout << "Danh sach mon hoc van con slot: " << endl;
	cout << setw(10) << "ID mon hoc" << setw(30) << "Ten giang vien" << setw(20) << "ID giang vien" << endl;
	for (int i = 0; i < Course.size(); i++)
	{
		if (chuyendoistringthanhint(Course[i].slot)>chuyendoistringthanhint(Course[i].n_student))
		{
			cout << setw(10) << Course[i].id << setw(30) << Course[i].name << setw(20) << Course[i].teacher_id << endl;
		}
	}
	// nhap vao mon hoc can dang ki
	cout << "Nhap vao ID mon hoc can dang ki: ";
	getline(cin, dk.id);
	cout << "Nhap vao ID giang vien: ";
	// nhap vao id dung vs tren hien thi 
	getline(cin, dk.teacher_id);
	dk.student_id = id;
	dk.semeter_id = "171";
	dk.score = "-1";
	//kiem tra sinh vien da hoc mon nay chua
	for (int i = 0; i < Object.size(); i++)
	{
		if (id.compare(Object[i].student_id) == 0 && dk.id.compare(Object[i].id) == 0 && dk.teacher_id.compare(Object[i].teacher_id) == 0)
		{
			cout << "sinh vien da dang ki mon nay khong the dang ki lai.\n";
			system("pause");
			system("cls");
			return;
		}
	}

	//kiem tra so luong sinh vien cua mon hoc do
	int kt1 = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (dk.id.compare(Course[i].id) == 0 && dk.teacher_id.compare(Course[i].teacher_id) == 0)
		{
			kt1 = chuyendoistringthanhint(Course[i].slot);
			break;
		}
	}
	// doc so slot cua mon hoc sinh vien cho va chuyen doi 
	//slot tu string thanh int de so sanh vs so luong sinh vien 
	int kt = 0;
	for (int i = 0; i < Object.size(); i++)
	{
		if ((dk.id).compare(Object[i].id) == 0 && (dk.teacher_id).compare(Object[i].teacher_id) == 0)
		{
			kt = kt + 1;
		}
	}
	if (kt1 <= kt)
	{
		cout << "Khong the dang ki mon hoc nay. Vui long kiem tra lai!\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{

	}
	Object.push_back(dk);

	int kt2 = 0;
	for (int i = 0; i < Course.size(); i++)
	{
		if (dk.id.compare(Course[i].id) == 0 && dk.teacher_id.compare(Course[i].teacher_id) == 0)
		{
			kt2 = chuyendoistringthanhint(Course[i].n_student);
			std::string s = std::to_string(kt2 + 1);
			Course[i].n_student = s;
			break;
		}
	}

	cout << "Dang ki mon hoc thanh cong.\n";
	system("pause");
	system("cls");
}

// huy mon hoc 
void huymonhoc(string id, vector<object> &Object, vector<course> &Course)
{
	cout << "Cac Mon Sinh Vien Dang Hoc:\n";
	cout << setw(15) << "ID Mon Hoc" << setw(30) << "Ten Mon Hoc" << setw(22) << "ID Giang Vien\n";
	for (int i = 0; i < Object.size(); i++)
	{
		if (id.compare(Object[i].student_id) == 0 && Object[i].score == "-1")
		{
			cout << setw(15) << Object[i].id;
			for (int j = 0; j < Course.size(); j++)
			{
				if (Object[i].id.compare(Course[j].id) == 0 && Object[i].teacher_id.compare(Course[j].teacher_id) == 0)
				{
					cout << setw(30) << Course[j].name << setw(20) << Course[j].teacher_id << endl;
				}
			}
		}
	}
	cout << "Nhap ID mon hoc can huy: ";
	string tenmonhoc;
	getline(cin, tenmonhoc);
	cout << "Nhap ID giang vien: ";
	string magiangvien;
	getline(cin, magiangvien);
	// tinh lai so luong n_student
	for (int i = 0; i < Object.size(); i++)
	{
		if (id.compare(Object[i].student_id) == 0 && tenmonhoc.compare(Object[i].id) == 0 && magiangvien.compare(Object[i].teacher_id) == 0)
		{
			for (int j = 0; j < Course.size(); j++)
			{
				if (Object[i].id.compare(Course[j].id) == 0 && Object[i].teacher_id.compare(Course[j].teacher_id) == 0)
				{
					int kt2 = chuyendoistringthanhint(Course[j].n_student) - 1;
					Course[j].n_student = chuyenintthanhstring(kt2);
					break;
				}
			}
			Object.erase(Object.begin() + i);
		}
	}
	system("pause");
	system("cls");
}

// xem dang sach mon hoc da dang ki
void xemdanhsachmonhocdadangki(vector<object> Object, string user, vector<course> Course)
{
	int d = 0;
	cout << setw(15) << "ID mon hoc" << setw(30) << "Ten mon hoc" << setw(20) << "ID giang vien" << endl;
	for (int i = 0; i < Object.size(); i++)
	{
		if (Object[i].student_id.compare(user) == 0)
		{
			d = d + 1;
			cout << setw(15) << Object[i].id;
			for (int j = 0; j < Course.size(); j++)
			{
				if (Object[i].id.compare(Course[j].id) == 0 && Object[i].teacher_id.compare(Course[j].teacher_id) == 0)
					cout << setw(30) << Course[j].name << setw(20) << Course[i].teacher_id << endl;
			}
		}
	}
	cout << endl;
	if (d == 0)
	{
		cout << "Chua dang ki mon hoc nao.\n";
	}
	system("pause");
	system("cls");
}

//xem danh sach mon hoc dang hoc
void xemdanhsachmonhocdanghoc(string user, vector<object> Object, vector<course> Course, vector<diemtongket> Tongket)
{
	cout << setw(15) << "ID Mon Hoc" << setw(30) << "Ten Mon Hoc" << setw(20) << "ID Giang Vien" << endl;
	for (int i = 0; i < Object.size(); i++)
	{
		int d = 0;
		if (user.compare(Object[i].student_id) == 0)
		{
			for (int j = 0; j < Tongket.size(); j++)
			{
				if (user.compare(Tongket[j].student_id) == 0 && Object[i].id.compare(Tongket[j].id) == 0 && Object[i].teacher_id.compare(Tongket[j].teacher_id) == 0)
				{
					break;
				}
				else d++;
			}
			if (d == Tongket.size())
			{
				for (int j = 0; j < Course.size(); j++)
				{
					if (Object[i].id.compare(Course[j].id) == 0 && Object[i].teacher_id.compare(Course[j].teacher_id) == 0)
					{
						cout << setw(15) << Course[j].id << setw(30) << Course[j].name << setw(20) << Course[j].teacher_id << endl;
					}
				}
			}
		}
	}
	writecourse(Course);
	writeobject(Object);
	system("pause");
	system("cls");
}

// tim theo ten 
void timtheoten(vector<teacher> Teacher, vector<thongtinuser> Thongtin, vector<student> Student)
{
	cout << "Nhap ten ten sinhvien/giangvien can tim: ";
	string user;
	getline(cin, user);
	cout << "\n- Giang vien:\n\n";
	for (int i = 0; i < Teacher.size(); i++)
	{
		int32_t search = Teacher[i].hoten.find(user);
		if (search != -1)
		{
			cout << Teacher[i].hoten << " - " << Teacher[i].mscb << endl;
		}
	}
	cout << "\n- Sinh vien:\n\n";
	for (int i = 0; i < Student.size(); i++)
	{
		int32_t search = Student[i].hoten.find(user);
		if (search != -1)
		{
			cout << Student[i].hoten << " - " << Student[i].id << endl;
		}
	}
	system("pause");
	system("cls");
}

//tim mon hoc theo ten
void timmonhoc(vector<course> Course)
{
	int dem = 0;
	cout << "Nhap keyword can tim: ";
	string tenmonhoc;
	getline(cin, tenmonhoc);

	for (int i = 0; i < Course.size(); i++)
	{
		int32_t search = Course[i].name.find(tenmonhoc);
		if (search != -1)
		{
			dem++;
		}
	}

	if (dem == 0)
	{
		cout << "Khong co mon hoc nay!" << endl;
	}
	else
	{
		cout << "ID mon hoc" << setw(15) << "ID giang vien" << setw(25) << "Ten mon hoc" << setw(20) << "So luong hien tai" << setw(10) << "Slot" << endl;
	}
	for (int i = 0; i < Course.size(); i++)
	{
		int32_t search = Course[i].name.find(tenmonhoc);
		if (search != -1)
		{
			cout << setw(10) << Course[i].id << setw(15) << Course[i].teacher_id << setw(25) << Course[i].name << setw(20) << Course[i].n_student << setw(10) << Course[i].slot << endl;
		}
	}
	system("pause");
	system("cls");
}

//tinh gpa
void tinhgpa(string user, vector<diemtongket> Tongket)
{
	//xem thong tin ca nhan
	for (int i = 0; i < Student.size(); i++)
	{
		if (user.compare(Student[i].id) == 0)
		{
			cout << "Ho va ten sinh vien: ";
			cout << Student[i].hoten << endl;
			cout << "Ngay sinh: ";
			cout << Student[i].ngaysinh << endl;
			cout << "Dia chi: ";
			cout << Student[i].diachi << endl;
		}
	}
	float gpa = 0;
	int d = 0;
	for (int i = 0; i < Tongket.size(); i++)
	{
		if (Tongket[i].student_id.compare(user) == 0)
		{
			string point = Tongket[i].diemtk;
			gpa = gpa + stof(point);
			d = d + 1;
		}
	}
	if (gpa == 0)
	{
		gpa = 0;
	}
	else
	{
		gpa = (float)gpa / d;
	}
	cout << "Diem trung binh tich luy(trung binh cac mon da tong ket) GPA = " << gpa << endl;
	system("pause");
	system("cls");
}

//xoa nhieu sinh vien theo ten
void xoanhieusinhvientheoten(vector<thongtinuser> &Thongtin, vector<student> &Student)
{
	cout << "Nhap ten sinh vien can xoa: ";
	string tensinhvien;
	getline(cin, tensinhvien);
	int d = 0;
	for (int i = 0; i < Student.size(); i++)
	{
		int32_t search = Student[i].hoten.find(tensinhvien);
		if (search != -1)
		{
			cout << Student[i].hoten << endl;
			Student.erase(Student.begin() + i);
			i = i--;
			d = d + 1;
			//xoa trong file user;
			for (int j = 0; j < Thongtin.size(); j++)
			{
				if (Student[i].id.compare(Thongtin[j].user) == 0)
				{
					Thongtin.erase(Thongtin.begin() + j);
					break;
				}
			}
		}
	}
	if (d == 0)
	{
		cout << "Khong tim thay sinh vien can xoa.\n";
	}
	else
	{
		cout << "Da xoa thanh cong " << d << " sinh vien" << endl;
	}
	writestudent(Student);
	writeuser(Thongtin);
	system("pause");
	system("cls");

}


//menu
void menu()
{
	thongtinuser ttin = login(Thongtin);
	if (ttin.admin == "admin")
	{
		while (true)
		{
			system("cls");
			cout << "========ADMINISTRATOR========" << endl;
			int luachon;
			cout << "0: Doi mat khau.\n";
			cout << "1: Dang xuat.\n";
			cout << "2: Xem danh sach user.\n";
			cout << "3: Them sinh vien.\n";
			cout << "4: Them giang vien.\n";
			cout << "5: Xoa sinh vien.\n";
			cout << "6: Xoa giang vien.\n";
			cout << "7: Tim kiem theo ten.\n";
			cout << "8: Xoa nhieu sinh vien cung luc theo ten khi tot nghiep.\n";
			cout << "9: Thoat." << endl;
			char c;
			int d = 0;
			do
			{
				if (d == 0)
					printf("Nhap lua chon: ");
				if (d != 0)
					printf("Nhap lai lua chon: ");
				d = d + 1;
			} while (((scanf_s("%d%c", &luachon, &c) != 2 || c != '\n') && clean_stdin() || luachon<0 || luachon>9));
			switch (luachon)
			{
			case 0:
			{
				doimatkhau(Thongtin, ttin.user);
				break;
			}
			case 1:
			{
				menu();
				break;
			}
			case 2:
			{
				dsuser(Thongtin);
				break;
			}
			case 3:
			{
				themsinhvien(Thongtin, Student);
				break;
			}
			case 4:
			{
				themgiangvien(Thongtin, Teacher);
				break;
			}
			case 5:
			{
				xoasinhvien(Student, Thongtin);
				break;
			}
			case 6:
			{
				xoagiangvien(Teacher, Thongtin);
				break;
			}
			case 7:
			{
				timtheoten(Teacher, Thongtin, Student);
				break;
			}
			case 8:
			{
				xoanhieusinhvientheoten(Thongtin, Student);
				break;
			}
			case 9:
				exit(0);
			}
		}
	}
	else if (ttin.admin == "teacher")
	{

		while (true)
		{
			system("cls");
			cout << "========TEACHER========" << endl;
			int luachon;
			cout << "0: Doi mat khau.\n";
			cout << "1: Dang xuat.\n";
			cout << "2: Mo mon hoc.\n";
			cout << "3: Nhap diem.\n";
			cout << "4: Sua diem cua sinh vien.\n";
			cout << "5: Tong ket diem.\n";
			cout << "6: Xem danh sach mon hoc da mo.\n";
			cout << "7: Thoat." << endl;
			char c;
			int d = 0;
			do
			{
				if (d == 0)
					cout << "Nhap lua chon: ";
				if (d != 0)
					cout << "Nhap lai lua chon: ";
				d = d + 1;
			} while (((scanf_s("%d%c", &luachon, &c) != 2 || c != '\n') && clean_stdin() || luachon<0 || luachon>7));
			switch (luachon)
			{
			case 0:
			{
				doimatkhau(Thongtin, ttin.user);
				break;
			}
			case 1:
			{
				menu();
				break;
			}
			case 2:
			{
				momonhoc(ttin.user, Course);
				writecourse(Course);
				writeobject(Object);
				break;
			}
			case 3:
			{
				nhapdiem(ttin.user, Object, Course);
				writecourse(Course);
				writeobject(Object);
				break;
			}
			case 4:
			{
				//sua diem
				suadiem(ttin.user);
				writecourse(Course);
				writeobject(Object);
				writetongket(Tongket);
				break;
			}
			case 5:
			{
				tongket(ttin.user, Object, Course, Tongket);
				writetongket(Tongket);
				break;

			}
			case 6:
			{
				// xem danh sach mon hoc da mo
				xemdanhsachmonhocgiangvien(ttin.user);
				break;
			}
			case 7:
				exit(0);
			}
		}
	}

	else if (ttin.admin == "student")
	{
		while (true)
		{
			system("cls");
			cout << "========STUDENT========" << endl;
			int luachon;
			cout << "0: Doi mat khau.\n";
			cout << "1: Dang xuat.\n";
			cout << "2: Dang ki mon hoc.\n";
			cout << "3: Huy mon hoc.\n";
			cout << "4: Tim mon hoc.\n";
			cout << "5: Xem danh sach mon hoc dang hoc(chua tong ket diem)\n";
			cout << "6: Xem danh sach mon hoc da dang ki\n";
			cout << "7: Xem gpa va thong tin ca nhan.\n";
			cout << "8: Thoat." << endl;
			char c;
			int d = 0;
			do
			{
				if (d == 0)
					cout << "Nhap lua chon: ";
				if (d != 0)
					cout << "Nhap lai lua chon: ";
				d = d + 1;
			} while (((scanf_s("%d%c", &luachon, &c) != 2 || c != '\n') && clean_stdin() || luachon<0 || luachon>8));
			switch (luachon)
			{
			case 0:
			{
				doimatkhau(Thongtin, ttin.user);
				break;
			}
			case 1:
			{
				menu();
				break;
			}
			case 2:
			{
				dangkimonhoc(ttin.user, Object, Course);
				writecourse(Course);
				writeobject(Object);
				break;
			}
			case 3:
			{
				huymonhoc(ttin.user, Object, Course);
				writecourse(Course);
				writeobject(Object);
				break;
			}
			case 4:
			{
				timmonhoc(Course);
				break;
			}
			case 5:
			{
				xemdanhsachmonhocdanghoc(ttin.user, Object, Course, Tongket);
				break;

			}
			case 6:
			{
				// xem danh sach mon hoc da mo
				xemdanhsachmonhocdadangki(Object, ttin.user, Course);
				break;
			}
			case 7:
			{
				tinhgpa(ttin.user, Tongket);
				break;
			}
			case 8:
				exit(0);
			}
		}
	}
}


int main()
{
	writetongket1();
	readuser(Thongtin);
	readteacher(Teacher);
	readstudent(Student);
	readcourse(Course);
	readobject(Object);
	readtongket(Tongket);
	menu();
}