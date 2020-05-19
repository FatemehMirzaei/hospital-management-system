// Å—ÊéÂ ò«—ê«Â.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
//##################################   class person   ######################################
class person
{
public:
	person() {};
	person(string name, string family, string address,string phone, int age);
	void setName(string name);
	void setFamily(string family);
	void setAddress(string address);
	void setPhone(string phone);
	void setAge(int age);
	string getName()const;
	string getFamily()const;
	string getAddress()const;
	string getPhone()const;
	int getAge()const;
	void report()const;
protected:
	string name, family, address, phone;
	int age;
};
person::person(string name,string family, string address, string phone, int age)
{
	this->name = name;
	this->family = family;
	this->address = address;
	this->phone = phone;
	this->age = age;
}
void person::setName(string name)
{
	this->name = name;
}
void person::setFamily(string family)
{
	this->family = family;
}
void person::setAddress(string address)
{
	this->address = address;
}
void person::setPhone(string phone)
{
	this->phone = phone;
}
void person::setAge(int age)
{
	this->age = age;
}
string person::getName()const
{
	return name;
}
string person::getFamily()const
{
	return family;
}
string person::getAddress()const
{
	return address;
}
string person::getPhone()const
{
	return phone;
}
int person::getAge()const
{
	return age;
}
void person::report()const
{
	cout << name << setw(10) << family << setw(10) << address << setw(10) << phone << setw(10) << age << setw(6) << endl;
}
//##################################   class doctor   ######################################
class doctor :public person
{
public:
	doctor() { counterd++; };
	doctor(string name, string family, string address, string phone, int age, string specialty, int doctorcode);
	void setSpecialty(string specialty);
	void setDoctorcode(int doctorcode);
	string getSpecialty()const;
	int getDoctorcode()const;
	static int getCounterd();
	void report()const;
private:
	string specialty;
	int doctorcode;
	static int counterd;
};
int doctor::counterd = 0;
doctor::doctor(string name, string family, string address, string phone, int age, string specialty, int doctorcode):person(name,family,address,phone,age)
{
	this->specialty = specialty;
	this->doctorcode = doctorcode;
	counterd++;
}
void doctor::setSpecialty(string specialty)
{
	this->specialty = specialty;
}
void doctor::setDoctorcode(int doctorcode)
{
	this->doctorcode = doctorcode;
}
string doctor::getSpecialty()const
{
	return specialty;
}
int doctor::getDoctorcode()const
{
	return doctorcode;
}
int doctor::getCounterd()
{
	return counterd;
}
void doctor:: report()const
{
	cout << name << setw(10) << family << setw(10) << address << setw(10) << phone << setw(10) << age << setw(6) << specialty << setw(4) << doctorcode << endl;
}
//##################################   class sick   ######################################
class sick :public person
{
public:
	sick() { counters++; };
	sick(string name, string family, string address, string phone, int age, string sickness, string doctorname,int dcode, int sickcode);
	void setSickness(string sickness);
	void setDoctorname(string doctorname);
	void setSickcode(int sickcode);
	void setDcode(int dcode);
	string getSickness()const;
	string getDoctorname()const;
	int getDcode()const;
	int getSickcode()const;
	static int getCounters();
	void report()const;
private:
	string sickness,doctorname;
	int sickcode,dcode;
	static int counters;
};
int sick::counters=0;
sick::sick(string name, string family, string address, string phone, int age, string sickness, string doctorname,int dcode, int sickcode) :person(name, family, address, phone, age)
{
	this->sickness = sickness;
	this->doctorname = doctorname;
	this->dcode = dcode;
	this->sickcode = sickcode;
	counters++;
}
void sick::setSickness(string sickness)
{
	this->sickness = sickness;
}
void sick::setDoctorname(string doctorname)
{
	this->doctorname = doctorname;
}
void sick::setSickcode(int sickcode)
{
	this->sickcode = sickcode;
}
string sick::getSickness()const
{
	return sickness;
}
string sick::getDoctorname()const
{
	return doctorname;
}
void sick::setDcode(int dcode)
{
	this->dcode = dcode;
}
int sick::getSickcode()const
{
	return sickcode;
}
int sick::getDcode()const
{
	return dcode;
}
int sick::getCounters()
{
	return counters;
}
void sick::report()const
{
	cout << name << setw(10) << family << setw(10) << address << setw(10) << phone << setw(10) << age << setw(6) << sickness<< setw(4) << doctorname << setw(4)<<dcode<<setw(4) << sickcode<< endl;
}
//##################################   functions of doctor   ######################################
vector<doctor>listd,listd2;
fstream outputfiledoctor;
void writedoctor()
{
	string name, family, address, phone, specialty;
	int age,doctorcode;
	cout << "enter doctor name\n";
	cin >> name;
	cout << "enter doctor family\n";
	cin >> family;
	cout << "enter doctor address\n";
	cin >> address;
	cout << "enter doctor phone\n";
	cin >> phone;
	cout << "enter doctor age\n";
	cin >> age;
	cout << "enter doctor specialty\n";
	cin >> specialty;
	cout << "enter doctor code\n";
	cin >> doctorcode;
	listd.push_back(doctor(name, family, address, phone, age, specialty, doctorcode));
	outputfiledoctor.open("doctor.csv", ios::app);
	outputfiledoctor << name + "," + family + "," + address + "," + phone + "," + to_string(age) + "," + specialty + "," + to_string(doctorcode) << endl;
}
void countd()
{
	cout << "number of doctor:" << doctor::getCounterd() << endl;
}
void modifyd(int doctorcode)
{
	string name, family, address, phone,  specialty;
	int age;
	int a;
	char c;
	for (int i = 0;i < listd.size();i++)
	{
		if (listd[i].getDoctorcode() == doctorcode)
		{
			system("cls");
			do {
				cout << "1.modify doctor name\n";
				cout << "2.modify doctor family\n";
				cout << "3.modify doctor address\n";
				cout << "4.modify doctor phone\n";
				cout << "5.modify doctor age\n";
				cout << "6.modify doctor specialty\n";
				cout << "enter your choice\n";
				cin >> a;
				switch (a)
				{
				case 1:
					cout << "enter correct name\n";
					cin >> name;
					listd[i].setName(name);
					break;
				case 2:
					cout << "enter correct family\n";
					cin >> family;
					listd[i].setFamily(family);
					break;
				case 3:
					cout << "enter correct address\n";
					cin >> address;
					listd[i].setAddress(address);
					break;
				case 4:
					cout << "enter correct phone\n";
					cin >> phone;
					listd[i].setPhone(phone);
					break;
				case 5:
					cout << "enter correct age\n";
					cin >> age;
					listd[i].setAge(age);
					break;
				case 6:
					cout << "enter correct specialty\n";
					cin >> specialty;
					listd[i].setSpecialty(specialty);
					break;
				default:
					cout << "you choiced a wrong number\n";
					break;
				}
				cout << "are you continue?(Y|N)\n";
				cin >> c;
			} while (c=='Y'||c=='y');
		}
	}
}
void displayalld()
{
	cout << "name" << setw(10) << "family" << setw(10) << "address "<< setw(10) << "phone" << setw(10) << "age" << setw(6) << "specialty" << setw(4) << "doctorcode "<< endl;
	for (int i = 0;i < listd.size();i++)
		cout << listd[i].getName() << setw(10) << listd[i].getFamily() << setw(10) << listd[i].getAddress() << setw(10) << listd[i].getPhone() << setw(10) << listd[i]. getAge()<< setw(6) << listd[i].getSpecialty() << setw(4) << listd[i]. getDoctorcode()<< endl;
}
void displayoned(int doctorcode)
{
	for (int i = 0;i < listd.size();i++)
	{
		cout << "name" << setw(10) << "family" << setw(10) << "address " << setw(10) << "phone" << setw(10) << "age" << setw(6) << "specialty" << setw(4) << "doctorcode " << endl;
		if (listd[i].getDoctorcode() == doctorcode)
		{
			cout << listd[i].getName() << setw(10) << listd[i].getFamily() << setw(10) << listd[i].getAddress() << setw(10) << listd[i].getPhone() << setw(10) << listd[i].getAge() << setw(6) << listd[i].getSpecialty() << setw(4) << listd[i].getDoctorcode() << endl;
		}
	}
}
void deletalld()
{
	listd.clear();
}
void deletoned(int doctorcode)
{
	for (int i = 0;i < listd.size();i++)
	{
		if (listd[i].getDoctorcode() != doctorcode)
			listd2.push_back(listd[i]);
	}
	listd = listd2;
	vector<doctor>().swap(listd2);
}
//##################################   functions of sick   ######################################
vector<sick>lists,lists2;
fstream outputfilesick;
void writesick()
{
	string name, family, address, phone, sickness,doctorname;
	int age, sickcode,dcode;
	cout << "enter sick name\n";
	cin >> name;
	cout << "enter sick family\n";
	cin >> family;
	cout << "enter sick address\n";
	cin >> address;
	cout << "enter sick phone\n";
	cin >> phone;
	cout << "enter sick age\n";
	cin >> age;
	cout << "enter sick sickness\n";
	cin >> sickness;
	cout << "enter sick doctor name\n";
	cin >> doctorname;
	cout << "enter sick doctor code\n";
	cin >> dcode;
	cout << "enter sick code\n";
	cin >> sickcode;
	lists.push_back(sick(name, family, address, phone, age, sickness, doctorname,dcode,sickcode));
	outputfilesick.open("sick.csv", ios::app);
	outputfilesick << name + "," + family + "," + address + "," + phone + "," + to_string(age) + "," + sickness + "," + doctorname+"," +to_string(dcode)+"," + to_string(sickcode) << endl;
}
void counts()
{
	cout << "number of sick:" << sick::getCounters() << endl;
}
void modifys(int sickcode)
{
	string name, family, address, phone,sickness,doctorname;
	int age,dcode;
	int a;
	char c;
	for (int i = 0;i < lists.size();i++)
	{
		if (lists[i].getSickcode() == sickcode)
		{
			system("cls");
			do {
				cout << "1.modify sick name\n";
				cout << "2.modify sick family\n";
				cout << "3.modify sick address\n";
				cout << "4.modify sick phone\n";
				cout << "5.modify sick age\n";
				cout << "6.modify sick sickness\n";
				cout << "7.modify sick doctor name\n";
				cout << "enter your choice\n";
				cin >> a;
				switch (a)
				{
				case 1:
					cout << "enter correct name\n";
					cin >> name;
					lists[i].setName(name);
					break;
				case 2:
					cout << "enter correct family\n";
					cin >> family;
					lists[i].setFamily(family);
					break;
				case 3:
					cout << "enter correct address\n";
					cin >> address;
					lists[i].setAddress(address);
					break;
				case 4:
					cout << "enter correct phone\n";
					cin >> phone;
					lists[i].setPhone(phone);
					break;
				case 5:
					cout << "enter correct age\n";
					cin >> age;
					lists[i].setAge(age);
					break;
				case 6:
					cout << "enter correct sickness\n";
					cin >> sickness;
					lists[i].setSickness(sickness);
					break;
				case 7:
					cout << "enter correct doctor name and doctor code\n";
					cin >> doctorname>>dcode;
					lists[i].setDoctorname(doctorname);
					lists[i].setDcode(dcode);
					break;
				default:
					cout << "you choiced a wrong number\n";
					break;
				}
				cout << "are you continue?(Y|N)\n";
				cin >> c;
			} while (c == 'Y' || c == 'y');
		}
	}
}
void displayalls()
{
	cout << "name" << setw(10) << "family" << setw(10) << "address" << setw(10) << "phone" << setw(10) << "age" << setw(6) << "sickness" << setw(4) << "doctor name" << setw(4) << "doctor code" << setw(4) << "sick code" << endl;
	for (int i = 0;i < lists.size();i++)
		cout << lists[i].getName() << setw(10) << lists[i].getFamily() << setw(10) << lists[i].getAddress() << setw(10) << lists[i].getPhone() << setw(10) << lists[i].getAge() << setw(6) << lists[i].getSickness() << setw(4) << lists[i].getDoctorname() << setw(4) << lists[i].getDcode() << setw(4) << lists[i].getSickcode() << endl;
}
void displayones(int sickcode)
{
	for (int i = 0;i < lists.size();i++)
	{
		if (lists[i].getSickcode() == sickcode)
		{
			cout << "name" << setw(10) << "family" << setw(10) << "address" << setw(10) << "phone" << setw(10) << "age" << setw(6) << "sickness" << setw(4) << "doctor name" << setw(4) << "doctor code" << setw(4) << "sick code" << endl;
			cout << lists[i].getName() << setw(10) << lists[i].getFamily() << setw(10) << lists[i].getAddress() << setw(10) << lists[i].getPhone() << setw(10) << lists[i].getAge() << setw(6) << lists[i].getSickness() << setw(4) << lists[i].getDoctorname() << setw(4) << lists[i].getDcode() << setw(4) << lists[i].getSickcode() << endl;
		}
	}
}
void deletalls()
{
	lists.clear();
}
void deletones(int sickcode)
{
	for (int i = 0;i < lists.size();i++)
	{
		if (lists[i].getSickcode() != sickcode)
			lists2.push_back(lists[i]);
	}
	lists = lists2;
	vector<sick>().swap(lists2);
}
void showsick(int doctorcode)
{
	for (int i = 0;i < lists.size();i++)
	{
		cout << "name" << setw(10) << "family" << setw(10) << "address" << setw(10) << "phone" << setw(10) << "age" << setw(6) << "sickness" << setw(4) << "doctor name" << setw(4) << "doctor code" << setw(4) << "sick code" << endl;
		if (lists[i].getDcode() == doctorcode)
		{
			cout << lists[i].getName() << setw(10) << lists[i].getFamily() << setw(10) << lists[i].getAddress() << setw(10) << lists[i].getPhone() << setw(10) << lists[i].getAge() << setw(6) << lists[i].getSickness() << setw(4) << lists[i].getDoctorname() << setw(4) << lists[i].getDcode() << setw(4) << lists[i].getSickcode() << endl;
		}
	}
}

//##################################   functions of menu   ######################################
void intro()
{
	system("cls");
	cout << "\t\t\t\nSYSTEM HOSPITAL\n";
	cout << "\t\t\t\nAdvance C++ Project\n";
	cout << "\t\t\t\nMade By : Fatemeh Mirzaei";
	cout << "\t\t\t\nSchool : Qom University";
	cin.get();
}
void report_menu()
{
	int a,b,c,doctorcode,sickcode;
	system("cls");
	cout << "\t\t\t\nreport menu\n";
	cout << "\t\t\t\n1.reports\n";
	cout << "\t\t\t\n2.back to main menu\n";
	cout << "\t\t\t\nenter your choice(1/2)";
	cin >> a;
	switch (a)
	{
	case 1:
		system("cls");
		cout << "\t\t\t\nreports menu\n";
		cout << "\t\t\t\n1.doctor reports\n";
		cout << "\t\t\t\n2.sick reports\n";
		cout << "\t\t\t\n3.sick of a doctor reports\n";
		cout << "\t\t\t\nenter your choice(1/2/3)\n";
		cin >> b;
		switch (b)
		{
		case 1:
			system("cls");
			cout << "\t\t\t\ndoctor reports\n";
			cout << "\t\t\t\n1.all doctor report\n";
			cout << "\t\t\t\n2.doctor report\n";
			cout << "\t\t\t\nenter your choice(1/2)\n";
			cin >> c;
			switch (c)
			{
			case 1:
				displayalld();
				_getch();
				break;
			case 2:
				cout << "\t\t\t\nenter doctor code\n";
				cin >> doctorcode;
				displayoned(doctorcode);
				_getch();
				break;
			default:
				cout << "\t\t\t\nyou selected a wrong number\n";
				break;
			}
			break;
		case 2:
			system("cls");
			cout << "\t\t\t\nsick reports\n";
			cout << "\t\t\t\n1.all sick report\n";
			cout << "\t\t\t\n2.sick report\n";
			cout << "\t\t\t\nenter your choice(1/2)\n";
			cin >> c;
			switch (c)
			{
			case 1:
				displayalls();
				_getch();
				break;
			case 2:
				cout << "\t\t\t\nenter sick code\n";
				cin >> sickcode;
				displayones(sickcode);
				_getch();
				break;
			default:
				cout << "\t\t\t\nyou selected a wrong number\n";
				break;
			}
			break;
		case 3:
			cout << "\t\t\t\nsick of a doctor reports\n";
			cout << "\t\t\t\nenter doctor code\n";
			cin >> doctorcode;
			showsick(doctorcode);
			_getch();
			break;
		default:
			cout << "\t\t\t\nyou selected a wrong number\n";
			break;
		}
		break;
	default:
		break;
	}
}
void entry_menu()
{
	system("cls");
	int a,doctorcode,sickcode;
	char ch;
	cout << "\t\t\t\nentry/edit menu\n";
	cout << "\t\t\t\n1.entry menu doctor\n";
	cout << "\t\t\t\n2.entry menu sick\n";
	cout << "\t\t\t\n3.back to main menu\n";
	cout << "enter your choice(1-3)\n";
	cin >> a;
	switch (a)
	{
	case 1:
		system("cls");
		cout << "\t\t\t\nentry menu doctor\n";
		cout << "\t\t\t\n1.create doctor record\n";
		cout << "\t\t\t\n2.modify doctor record\n";
		cout << "\t\t\t\n3.delet doctor record\n";
		cout << "\t\t\t\n4.delet doctor records\n";
		cout << "\t\t\t\n5.back to main menu\n";
		cout << "\t\t\t\nenter your choice\n";
		cin >> a;
		switch (a)
		{
		case 1:
			do
			{
				writedoctor();
				cout << "\t\t\t\ndoctor record has been created\n";
				_getch();
				system("cls");
				cout << "\t\t\t\ndo you want to inser new record of doctor?(Y|N)\n";
				cin >> ch;
				system("cls");
			} while (ch == 'Y' || ch == 'y');
			break;
		case 2:
			cout << "\t\t\t\nenter doctor code for modifinig\n";
			cin >> doctorcode;
			modifyd(doctorcode);
			break;
		case 3:
			cout << "\t\t\t\nenter doctor code for deleting\n";
			cin >> doctorcode;
			deletoned(doctorcode);
			break;
		case 4:
			deletalld();
			break;
		case 5:
			break;
		default:
			cout << "\t\t\t\nyou selected a wrong number\n";
			break;
		}
		break;
	case 2:
		system("cls");
		cout << "\t\t\t\nentry menu sick\n";
		cout << "\t\t\t\n1.create sick record\n";
		cout << "\t\t\t\n2.modify sick record\n";
		cout << "\t\t\t\n3.delet sick record\n";
		cout << "\t\t\t\n4.delet sick records\n";
		cout << "\t\t\t\n5.back to main menu\n";
		cout << "\t\t\t\nenter your choice(1-5)\n";
		cin >> a;
		switch (a)
		{
		case 1:
			do
			{
				writesick();
				cout << "\t\t\t\nsick record has been created\n";
				system("cls");
				cout << "\t\t\t\ndo you want insert new record of sick(Y|N)?\n";
				cin >> ch;
				system("cls");
			} while (ch == 'Y' || ch == 'y');
			break;
		case 2:
			cout << "\t\t\t\nenter sick code fo modifing\n";
			cin >> sickcode;
			modifys(sickcode);
			break;
		case 3:
			cout << "\t\t\t\nenter sick code for deleting\n";
			cin >> sickcode;
			deletones(sickcode);
			break;
		case 4:
			deletalls();
			break;
		case 5:
			break;
		default:
			cout << "\t\t\t\nyou selected a wrong number\n";
			break;
		}
		break;
	case 3:
		break;
	default:
		cout << "\t\t\t\nyou selected a wrong number\n";
		break;
	}
}
int main()
{
	int a;
	do
	{
		system("cls");
		cout << "\t\t\t\nmain menu\n";
		cout << "\t\t\t\n1.report menu\n";
		cout << "\t\t\t\n2.entry/edit menu\n";
		cout << "\t\t\t\n3.exit\n";
		cout << "\t\t\t\nenter your choice(1-3)\n";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
			report_menu();
			break;
		case 2:
			entry_menu();
			break;
		case 3:
			break;
		}
	} while (a != 3);
	_getch();
    return 0;
}

