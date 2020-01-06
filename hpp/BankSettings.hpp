#ifndef BANKSETTINGS_H
#define BANKSETTINGS_H

#include <iostream>
#include <fstream>
class BankSettings {

public:
    BankSettings();
    ~BankSettings();
    void setIntrestRate(float intrestRate);
	float getIntrestRate();
private:
    float intrestRate;
	bool loadSettingsFromFile();
	bool saveSettingsToFile();
};

#endif
