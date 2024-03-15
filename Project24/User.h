#pragma once
#include<iostream>
#include<string>
#include"ArrayList.cpp"
#include<map>
using namespace std;
class User
{
private:
	string name;
	string password;
	string gender;
	string country;
	string governorate;
	string national_ID;
	int age;
	bool already_vaccine;
	int how_many_vaccined;
	int pos;
public:
	User();  // default constructor
	~User(); // destructor
	// parameterized constructor
	User(string na, string pa, string ge, string co, string go, string id, int ag, bool al, int ho, int pos0);
	// setter methods
	void set_name(string name0);
	void set_password(string password0);
	void set_gender(string gender0);
	void set_country(string country0);
	void set_governorate(string governorate0);
	void set_national_ID(string national_ID0);
	void set_age(int age0);
	void set_already_vaccine(bool already_vaccine0);
	void set_how_many_vaccined(int how_many_vaccined0);
	void set_pos(int pos0);
	// getter methods
	string get_name();
	string get_password();
	string get_gender();
	string get_country();
	string get_governorate();
	string get_national_ID();
	bool get_already_vaccine();
	int get_how_many_vaccined();
	int get_age();
	int get_pos();
	// search method
	static int search(map<string, User>mp, string nat);
	// view method
	void view();
	// update method
    static 	User update(map<string, User>mp);
	// login method
	static 	int  login(map<string, User>mp, string n_id, string pas, bool& vac_condiont, int& number);
	// register
	void registr(map<string, User>mp);
};
