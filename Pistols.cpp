#include "Pistols.h"
#include <Windows.h>

void Pistols::input()
{
	cin.ignore(32767, '\n');
	cout << "Enter type : ";
	cin >> p.type_;
	cout << "Enter model : ";
	cin >> p.model_;
	cout << "Enter f value : ";
	cin >> p.f_value;
	cout << "Enter max-bullets : ";
	cin.ignore();
	cin >> p.MAX_BULLETS;
	cout << "Enter  paint: ";
	cin >> p.paint_;
	cout << "Enter rare : ";
	cin >> p.rare_;
	cout << "Enter price : ";
	cin >> p.price_;
	ofstream fout("Pistol.csv", ios::out | ios::app);
	if (fout.is_open())
	{
		fout << "--------------" << endl;
		fout << p.type_ << endl;
		fout << p.model_ << endl;
		fout << p.f_value << endl;
		fout << p.MAX_BULLETS << endl;
		fout << p.paint_ << endl;
		fout << p.rare_ << endl;
		fout << "--------------" << endl;
		fout << endl;
		cout << "data written successfully" << endl;
		Sleep(2000);
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
	PAUSE;
}

void Pistols::showSkin()
{
	string line;
	ifstream myfile("Pistol.csv");
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

void Pistols::buySkin()
{
	vector<string> result;
	string name, s;
	cin.ignore(32767, '\n');
	getline(cin, name);
	ifstream fout("Pistol.csv");
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
	ofstream fsut("Pistol.csv", ofstream::out | ofstream::trunc);
	fsut.close();
	ofstream fomt("Pistol.csv", ios::out | ios::app);
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

void Pistols::setTypeSkin(const string& type)
{
	if (!type.empty())
		this->p.type_ = type;
	else
		ERROR;
}


void Pistols::setModel(const string& model)
{
	if (!model.empty())
		this->p.model_ = model;
	else
		ERROR;
}

void Pistols::setPaint(const string& paint)
{
	if (!paint.empty())
		this->p.paint_ = paint;
	else
		ERROR;
}

void Pistols::setMaxBullets(const size_t& max)
{
	if (max != 0)
		this->p.MAX_BULLETS = max;
	else
		ERROR;
}

void Pistols::setRareSkin(const string& rare)
{
	if (!rare.empty())
		this->p.rare_ = rare;
	else
		ERROR;
}

void Pistols::setFValue(const float& f)
{
	if (f != 0)
		this->p.f_value = f;
	else
		ERROR;
}

void Pistols::setSeler(const bool& s)
{
	this->p.isSilencer = s;
}

void Pistols::setPriceSkin(const size_t& price)
{
	if (price != 0)
		this->p.price_ = price;
	else
		ERROR;
}

void Pistols::print() const
{
	cout << "_______PRINT PISTOL________" << endl;
	cout << p.type_ << "\t" << p.model_ << "\t" << p.f_value << "\t" << p.MAX_BULLETS << "\t" << p.paint_ << "\t" << p.rare_ << "\t" << p.price_ << endl;
	cout << "___________________________" << endl;
	PAUSE;
}