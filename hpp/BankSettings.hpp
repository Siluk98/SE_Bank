#ifndef BANKSETTINGS_H
#define BANKSETTINGS_H

class BankSettings {

private:
	float intrestRate;
	BankSettings();

public:
	void loadSettingsFromFile();
	float getIntrestRate();
	void setIntrestRate(float intrestRate);
};

#endif
