#include "User.h"
#include<iostream>
#include<string>
#include<algorithm>

User::User() {
	name = "no name";
	password = "0000";
	gender = "no information";
	country = "no informatiom";
	governorate = "no information";
	national_ID = "0000";
	age = 00;
	already_vaccine = false;
	how_many_vaccined = 0;
	pos = 0;
}
User::User(string na, string pa, string ge, string co, string go, string id, int ag, bool al, int ho, int pos0)
{
	name = na;
	password = pa;
	gender = ge;
	country = co;
	governorate = go;
	national_ID = id;
	age = ag;
	already_vaccine = al;
	how_many_vaccined = ho;
	pos = pos0;
}

User::~User() {

}
void User::set_name(string name0) 
{
	name = name0;
}

void User::set_password(string password0) 
{
	password = password0;
}
void User::set_gender(string gender0) 
{
	gender = gender0;
}
void User::set_age(int age0) 
{
	age = age0;
}
void User::set_already_vaccine(bool already_vaccine0) 
{
	already_vaccine = already_vaccine0;
}
void User::set_country(string country0) 
{
	country = country0;
}
void User::set_national_ID(string national_ID0) 
{
	national_ID = national_ID0;
}
void User::set_governorate(string gover) 
{
	governorate = gover;
}
void User::set_how_many_vaccined(int how_many_vaccined0) 
{
	how_many_vaccined = how_many_vaccined0;
}
void User::set_pos(int pos0) 
{
	pos = pos0;
}


string User::get_name() 
{
	return name;
}
bool User::get_already_vaccine() 
{
	return already_vaccine;
}
string User::get_password() 
{
	return password;
}
string User::get_country() 
{
	return country;
}
string User::get_gender() 
{
	return gender;
}
int User::get_how_many_vaccined() 
{
	return how_many_vaccined;
}
string User::get_national_ID()
{
	return national_ID;
}
string User::get_governorate() 
{
	return governorate;
}
int User::get_age() 
{
	return age;
}
int User::get_pos() 
{
	return pos;
}

int User::search(map<string, User>mp, string nat) 
{ 
	int it = mp.count(nat);
	if (it == 1) 
		return 1;  // true
	else
		return 0;  // false
}

void User::registr(map<string, User>mp) {
	cout << "Enter personal data \n";
	cin.ignore();
    cout << "Enter name \n";
	getline(cin,name);
	cout << "Enter password \n";
	cin>>password;
	cout << "Enter gender \n";
    cin>>gender;
	cout << "Enter country \n";
	cin >> country;
	transform(country.begin(), country.end(), country.begin(), ::toupper);//to convert country to Upper case(EGYPT) ;
	if (country != "EGYPT")
	{
		cout << "System for Egyption only \n";
		return;
	}
	cout << "Enter governorate \n";
	cin >> governorate;//enumration 
	string nid;
	cout << "Enter national id \n";
	//cin >> national_ID;  // string nid
	cin >> nid;
	while (nid.length() != 13 || search(mp, nid))
	{
		cout << "invalid National id \n";
		cout << "Enter national id \n";
		cin >> nid;
	}
	national_ID = nid;
	cout << "Enter Your Age \n";
	cin >> age;
	cout << "have you ever taken vaccine\n";
	cout << "1:Yes\n";
	cout << "2:No\n";
	cin >> already_vaccine;
	if (already_vaccine)
	{
		cout << "How many vaccine have you taken  2 or 1 ?\n";
		cin >> how_many_vaccined;
	}

}

void User::view()
{
	cout <<"Full Name Is : "<< get_name() << endl;
	//cout << get_password() << endl;
	cout<<"Your Gender Is : "<< get_gender() << endl;
	cout <<"Your Country IS : "<< get_country() << endl;
	cout <<"Your Governorate Is : "<< get_governorate() << endl;
	cout <<"Your National ID Is :  "<< get_national_ID() << endl;
	cout <<"Your Age Is : "<< get_age() << endl;
	cout <<"Already Vaccine ? :"<< get_already_vaccine() << endl;
	cout <<"How Many Vaccined ? "<< get_how_many_vaccined() << endl;
}
User User::update(map<string, User>mp) {


	User user;
	cout << "press \n";
	cout << "1 to Update Your Name \n ";
	cout << "2 to Update Your Password \n ";
	//cout << "3 to update gender \n ";
	cout << "3 to Update Your Governorate \n ";
	cout << "4 to Update Your National Id \n ";
	cout << "5 to update Your Age \n ";
	int x;
	cin >> x;
	cin.ignore();
	switch (x)
	{
	case 1:
	{
		string na;
		cout << "Enter Your Name :\n";
		getline(cin, na);
		user.set_name(na);
		break;
	}

	case 2:
	{
		string pas;
		cout << "Enter your Password :\n";
		cin>>pas;
		user.set_password(pas);
		break;
	}
	
	case 3:
	{
		string gov;
		cout << "Enter your Governorate: \n";
		cin >> gov;
		user.set_governorate(gov);

		break;
	}
	case 4:
	{

		string nid;
		cout << " Enter Your National Id \n ";
		//cin >> national_ID;
		cin >> nid;
		while ((nid.length() != 13) || search(mp, nid))
		{
			cout << "invalid National Id \n";
			cout << "Enter national id \n";
			cin >> nid;
		}
		user.set_national_ID(nid);
		break;
	}
	case 5:
	{
		int ag;
		cout << " Enter Your Age\n";
		cin >> ag;
		user.set_age(ag);
		break;

	}
	default:
		cout << "This Is Wrong , you must choice number from this list\n";

	}
	return user;
}


int User::login(map<string, User>mp, string n_id, string pas, bool& vac_condiont, int& number_of_dose) 
{
	auto it = mp.find(n_id);
	if (it != mp.end())
	{
		if (mp[n_id].password == pas)
		{
			number_of_dose = mp[n_id].how_many_vaccined;
			vac_condiont = mp[n_id].already_vaccine;
			return  mp[n_id].pos;
		}
		else {
			cout << "your password is not correct";
		}
	}
	else 
	{
		cout << "you are not in this system";
		number_of_dose = 0;
		vac_condiont = 0;
		return -1;
	}


}

