#include "Admin.h"
#include<iostream>
#include<string>

Admin::Admin() {
	password = "no_password";
	Username = "no_username";
	Email = "suppour123@gmail.com";
}

Admin::Admin(string us, string ps,string email) {
	password = ps;
	Username = us;
	Email = email;
}
void Admin::set_Username(string us)
{
	Username = us;
}
void Admin::set_password(string ps) {

	password = ps;
}
void Admin::set_Email(string em)
{
	Email = em;
}
string Admin::get_password() {
	return password;
}
string Admin::get_Email()
{
	return Email;
}
string Admin::get_username()
{
	return Username;
}


bool Admin::login(string us, string ps)
{
	if (Username == us && password == ps) 
	{
		return true;
	}
	return false;
}

string Admin::update(map<string, User>mp)
{
	int choice;
	string nation_id;
	cout << "please Enter national id of user\n";
	cin >> nation_id;
	int it = mp.count(nation_id);
	if (it)
	{

		cout << "1-to update no_vaccined to one_vaccied" << endl;
		cout << "2-to update one_vaccined to two_vaccined" << endl;
		cin >> choice;
		if (choice == 1)
		{
			mp[nation_id].set_already_vaccine(true);
			mp[nation_id].set_how_many_vaccined(1);
		}
		else if (choice == 2)
		{
			mp[nation_id].set_how_many_vaccined(2);

		}
		return nation_id;
	}
	else
	{
		cout << "the id is not found \n";
		return "no_data";
	}

}

void Admin::view_user(User u)
{
	u.view();
}