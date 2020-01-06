#include "../hpp/BankSettings.hpp"

BankSettings::BankSettings() {
	if(!loadSettingsFromFile())
        std::cout << "Bank settings could not be loaded" << std::endl;
}

BankSettings::~BankSettings()
{
    saveSettingsToFile();
}

bool BankSettings::loadSettingsFromFile() {
	std::ifstream file;
	file.open("settings.conf");
	if(!file.good())
    {
        setIntrestRate(0);
        return false;
    }
    float f;
    file>>f;
    setIntrestRate(f);
    return true;
}

bool BankSettings::saveSettingsToFile()
{
    std::ofstream file;
    file.open("settings.conf",std::ios::out|std::ios::trunc);
    if(!file.good()) return false;
    file << intrestRate;
    return true;

}

float BankSettings::getIntrestRate() {
	return this->intrestRate;
}

void BankSettings::setIntrestRate(float intrestRate) {
	this->intrestRate = intrestRate;
}
