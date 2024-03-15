#include<iostream>
#include"User.h"
#include<string>
#include<map>
using namespace std;
int main() {
	map<string, User>mp;
	ArrayList<User> no_vaccined;
	ArrayList<User>one_vaccined;
	ArrayList<User>two_vaccined;
	int choice1 = 0; int chioce2 = 0; int choice3 = 0; int choice4 = 0;
	int choice5 = 0;
	User u1 = User("mohamed", "4834rwe", "M", "egypt", "Cairo", "7865846465908", 43, 0, 0, no_vaccined.Length());
	no_vaccined.Append(u1);

	User u2 = User("mostafa", "5474rwe", "M", "egypt", "Cairo", "8643216450005", 43, 0, 0, no_vaccined.Length());
	no_vaccined.Append(u2);
	User u3 = User("mohamed", "4834rwe", "M", "egypt", "Cairo", "1234567891025", 43, 0, 0, no_vaccined.Length());
	no_vaccined.Append(u3);
	

	mp.insert({ u1.get_national_ID(),u1 });
	mp.insert({ u2.get_national_ID(),u2 });
	mp.insert({ u3.get_national_ID(),u3 });
	no_vaccined.Append(u1);
	one_vaccined.Append(u2);
	two_vaccined.Append(u3);


	/// user list 
	cout << "1-signup";
	cout << "2-login";
	cin >> choice1;
	switch (choice1)
	{
	case 1:
	{
		User u5;
		u5.registr(mp);
		if (u5.get_country() == "EGYPT")
		{
			if (u5.get_how_many_vaccined ()== 0)//  if he or she don't have any vacciend then add to no_vacceined list 
			{
				u5.set_pos(no_vaccined.Length());
				no_vaccined.Append(u5);
				mp[u5.get_national_ID()] = u5;

			}

			else if (u5.get_how_many_vaccined() == 1) // if he or she  have one dose only then add to one_vacceined list
			{
					u5.set_pos(one_vaccined.Length());
					one_vaccined.Append(u5);
					mp[u5.get_national_ID()] = u5;
			}

			else
			{
					u5.set_pos(two_vaccined.Length());// if he or she have two  dose  then add to two two_vacceind list
					two_vaccined.Append(u5);
					mp[u5.get_national_ID()] = u5;
			}

			cout << "your registertion is successfully done" << endl;

		}
		else
		{
			cout << "your registertion is failed" << endl;
		}

		break;

	}
	case 2:
	{
		string Nan_id = "";
		string pass = "";
		int num_dos = 0;
		bool vaccined = false;
		cout << "please Enter your National_ID:" << endl;
		cin >> Nan_id;
		cout << "please Enter your password:" << endl;
		cin >> pass;
		int pos = User::login(mp, Nan_id, pass, vaccined, num_dos);
	if (pos != -1)
	{
		if (vaccined != true)
		{
			cout << "welcome " << no_vaccined.At(pos).get_name() << endl;
			cout << "1:To View Your Data\n";
			cout << "2:To Update Your Data\n";
			cout << "3:To delete Your Data\n";
			cin >> choice4;
			switch (choice4)
			{
			case 1:
			{
				no_vaccined.At(pos).view();
				break;
			}
			case 2:
			{

				string prev = no_vaccined.At(pos).get_national_ID();
				no_vaccined.deleteAt(pos);
				no_vaccined.insertAt(pos, User::update(mp));

				if (no_vaccined.At(pos).get_national_ID() != prev) {
					mp.erase(prev);
					mp[no_vaccined.At(pos).get_national_ID()] = no_vaccined.At(pos);
				}
				else
				{
					mp[prev] = no_vaccined.At(pos);

				}
				break;
			}
			case 3:
			{
				mp.erase(no_vaccined.At(pos).get_national_ID());
				no_vaccined.deleteAt(pos);
				break;
			}
			default:
				cout << "invalid number";

			}
		}
		else
		{
				if (num_dos == 1)
				{

					cout << "welcome " << one_vaccined.At(pos).get_name() << endl;
					cout << "1:To View Your Data\n";
					cout << "2:To Update Your Data\n";
					cout << "3:To delete Your Data\n";
					cin >> choice4;

					switch (choice4)
					{
					case 1:
					{
						one_vaccined.At(pos).view();
						break;
					}
					case 2:
					{

						string prev = one_vaccined.At(pos).get_national_ID();
						one_vaccined.deleteAt(pos);
						one_vaccined.insertAt(pos, User::update(mp));

						if (one_vaccined.At(pos).get_national_ID() != prev) {
							mp.erase(prev);
							mp[one_vaccined.At(pos).get_national_ID()] = one_vaccined.At(pos);
						}
						else
						{
							mp[prev] = one_vaccined.At(pos);

						}
						break;
					}
					case 3:
					{
						mp.erase(one_vaccined.At(pos).get_national_ID());
						one_vaccined.deleteAt(pos);
						break;
					}
					default:
						cout << "invalid number";

					}


				}
				else
				{

					cout << "welcome " << two_vaccined.At(pos).get_name() << endl;
					cout << "1:To View Your Data\n";
					cout << "2:To Update Your Data\n";
					cout << "3:To delete Your Data\n";
					cin >> choice4;

					switch (choice4)
					{
					case 1:
					{
						two_vaccined.At(pos).view();
						break;
					}
					case 2:
					{

						string prev = two_vaccined.At(pos).get_national_ID();
						two_vaccined.deleteAt(pos);
						two_vaccined.insertAt(pos, User::update(mp));

						if (two_vaccined.At(pos).get_national_ID() != prev) {
							mp.erase(prev);
							mp[two_vaccined.At(pos).get_national_ID()] = two_vaccined.At(pos);
						}
						else
						{
							mp[prev] = two_vaccined.At(pos);

						}
						break;
					}
					case 3:
					{
						mp.erase(two_vaccined.At(pos).get_national_ID());
						two_vaccined.deleteAt(pos);
						break;
					}
					default:
						cout << "invalid number";

					}

				}
		}
	}
		break;
	}
	default:
		break;
	}
	User u;
	string prev = u.get_national_ID();
	u=User::update(mp);
	no_vaccined.deleteAt(0);
	no_vaccined.insertAt(0, u);
	cout<<""<<no_vaccined.At(0).get_name()<<endl ;
	if (no_vaccined.At(0).get_national_ID() != prev) {
		mp.erase(prev);
		mp[no_vaccined.At(0).get_national_ID()] = no_vaccined.At(0);
		cout << mp[no_vaccined.At(0).get_national_ID()].get_name();
	}
	else {
		mp[prev] = no_vaccined.At(0);
	
	}










	return 0;

}