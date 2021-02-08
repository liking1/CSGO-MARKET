#include "Gun.h"
#include <Windows.h>

void Gun::input()
{
	cin.ignore(32767, '\n');
	cout << "Enter type : ";
	cin >> d.type_;
	cout << "Enter model : ";
	cin >> d.model_;
	cout << "Enter f value : ";
	cin >> d.f_value;
	cout << "Enter max-bullets : ";
	cin.ignore();
	cin >> d.MAX_BULLETS;
	cout << "Enter paint : ";
	cin >> d.paint_;
	cout << "Enter rare : ";
	cin >> d.rare_;
	cout << "Enter price : ";
	cin >> d.price_;
	ofstream fout("Gun.csv", ios::out | ios::app);
	if (fout.is_open())
	{
		fout << "-------" << d.type_ << "-------" << endl;
		fout << d.type_ << "   " << '\"' << d.type_ << '\"' << endl;
		fout << d.model_ << "   " << '\"' << d.type_ << '\"' << endl;
		fout << d.f_value << "   " << '\"' << d.type_ << '\"' << endl;
		fout << d.MAX_BULLETS << "   " << '\"' << d.type_ << '\"' << endl;
		fout << d.paint_ << "   " << '\"' << d.type_ << '\"' << endl;
		fout << d.rare_ << "   " << '\"' << d.type_ << '\"' << endl;
		fout << "-------" << d.type_ << "-------" << endl;
		cout << "data written successfully" << endl;
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
	CLEAN;
}

void Gun::showSkin()
{
	string line;
	ifstream myfile("Gun.csv");
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
	CLEAN;
}

void Gun::buySkin()
{
	vector<string> result;
	string name, s;
	cin.ignore(32767, '\n');
	cout << "Name of GUN: ";
	getline(cin, name);
	ifstream fout("Gun.csv");
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
	ofstream fsut("Gun.csv", ofstream::out | ofstream::trunc);
	fsut.close();
	ofstream fomt("Gun.csv", ios::out | ios::app);
	if (fomt.is_open())
	{
		for (int i = 0; i < result.size(); i++)
			fomt << result[i] << endl;
		cout << "Information deleted" << endl;
		fomt.close();
		Sleep(2000);
		CLEAN;
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
}

void Gun::setTypeSkin(const string& type)
{
	if (!type.empty())
		this->d.type_ = type;
	else
		ERROR;
}

void Gun::setModel(const string& model)
{
	if (!model.empty())
		this->d.model_ = model;
	else
		ERROR;
}

void Gun::setPaint(const string& paint)
{
	if (!paint.empty())
		this->d.paint_ = paint;
	else
		ERROR;
}

void Gun::setMaxBullets(const size_t& max)
{
	if (max != 0)
		this->d.MAX_BULLETS = max;
	else
		ERROR;
}

void Gun::setRareSkin(const string& rare)
{
	if (!rare.empty())
		this->d.rare_ = rare;
	else
		ERROR;
}

void Gun::setFValue(const float& f)
{
	if (f != 0)
		this->d.f_value = f;
	else
		ERROR;
}

void Gun::setPriceSkin(const size_t& price)
{
	if (price != 0)
		this->d.price_ = price;
	else
		ERROR;
}

void Gun::print() const
{
	CLEAN;
	cout << "____GUN PRINT____" << endl;
	cout << "Type : " << d.type_ << endl;
	cout << "Model : " << d.model_ << endl;
	cout << "Paint : " << d.paint_ << endl;
	cout << "Rare : " << d.rare_ << endl;
	cout << "Max bullets : " << d.MAX_BULLETS << endl;
	cout << "Float value : " << d.f_value << endl;
	cout << "Price : " << d.price_ << "$" << endl;
	cout << "_________________" << endl;
	PAUSE;
	CLEAN;
}