#pragma once
#include<map>
#include<string>
#include<iostream>
#include "User.h"
using namespace std;
class Admin
{
private:
	string Email;
	string Username;
	string password;
public:
	Admin();
	Admin(string us, string ps,string emial);
	void set_Username(string us);
	void set_password(string ps);
	void set_Email(string em);
	string get_username();
	string get_password();
	string get_Email();
	bool login(string us, string ps);
	string update(map<string, User>mp);
	void view_user(User mp);



};

