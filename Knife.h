#pragma once
#include "Shop.h"
#include <fstream>
#include <Windows.h>

struct CData
{
	string name_, rare_, type_;
	float f_value_;
	size_t price_;

};

class Knife : public Skin
{
public:
	Knife(const string& type, const string& rare, const size_t& price, const float& f)
	{
		setTypeSkin(type);
		setRareSkin(rare);
		setPriceSkin(price);
		setFValue(f);
	}
	Knife() = default;
	void input() override;
	void showSkin() override;
	void buySkin() override;
	void setTypeSkin(const string& type) override;
	void setRareSkin(const string& rare) override;
	void setFValue(const float& f) override;
	void setPriceSkin(const size_t& price) override;
	void print() const override;
private:
	CData data_;
};