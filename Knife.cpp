#include "Knife.h"
#include <Windows.h>

void Knife::input()
{
	cin.ignore(32767, '\n');
	cout << "Enter name : ";
	cin >> data_.name_;
	cout << "Enter type : ";
	cin >> data_.type_;
	cout << "Enter f value : ";
	cin >> data_.f_value_;
	cout << "Enter rare : ";
	cin >> data_.rare_;
	cout << "Enter price : ";
	cin >> data_.price_;
	ofstream fout("Knife.csv", ios::out | ios::app);
	if (fout.is_open())
	{
		fout << "-------" << data_.name_ << "-------" << endl;
		fout << data_.type_ << "   " << '\"' << data_.type_ << '\"' << endl;
		fout << data_.name_ << "   " << '\"' << data_.type_ << '\"' << endl;
		fout << data_.rare_ << "   " << '\"' << data_.type_ << '\"' << endl;
		fout << data_.price_ << "   " << '\"' << data_.type_ << '\"' << endl;
		fout << "-------" << data_.type_ << "-------" << endl;
		fout << endl;
		cout << "data written successfully" << endl;
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
	PAUSE;
}

void Knife::showSkin()
{
	string line;
	ifstream myfile("knife.csv");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			cout << line << endl;
		}
	}
	myfile.close();
	PAUSE;
}

void Knife::buySkin()
{

	vector<string> result;
	string name, s;
	cin.ignore(32767, '\n');
	getline(cin, name);
	ifstream fout("Knife.csv");
	if (fout.is_open())
	{
		while (getline(fout, s))
		{
			if (s.find(name) == string::npos)
				result.push_back(s);
		}
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
	ofstream fsut("Knife.csv", ofstream::out | ofstream::trunc);
	fsut.close();
	ofstream fomt("Knife.csv", ios::out | ios::app);
	if (fomt.is_open())
	{
		for (int i = 0; i < result.size(); i++)
			fomt << result[i] << endl;
		cout << "Information deleted" << endl;
		fomt.close();
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
	PAUSE;
}

void Knife::setTypeSkin(const string& type)
{
	if (!type.empty())
		this->data_.type_ = type;
	else
		cerr << "error with type knife!" << endl;
}

void Knife::setRareSkin(const string& rare)
{
	if (!rare.empty())
		this->data_.rare_ = rare;
	else
		cerr << "error with rare knife!" << endl;
}

void Knife::setFValue(const float& f)
{
	if (f != 0)
		this->data_.f_value_ = f;
	else
		ERROR;

}

void Knife::setPriceSkin(const size_t& price)
{
	if (price != 0)
		this->data_.price_ = price;
	else
		cerr << "error with price knife!" << endl;
}

void Knife::print() const
{
	CLEAN;
	cout << "~~~~~~~~KNIFE PRINT~~~~~~~" << endl;
	cout << "Type knife : " << data_.type_ << endl;
	cout << "Name knife : " << data_.name_ << endl;
	cout << "Rare knife : " << data_.rare_ << endl;
	cout << "Float value : " << data_.f_value_ << endl;
	cout << "Price knife : " << data_.price_ << "$" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	PAUSE;
	CLEAN;
}