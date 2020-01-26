#include "../hpp/TransferHandler.hpp"

TransferHandler& TransferHandler::getInstance()
{
    static TransferHandler T;
    return T;
}

std::vector<std::shared_ptr<Transfer>> TransferHandler::getTransfers() {
	return this->transfers;
}

void TransferHandler::setTransfers(std::vector<std::shared_ptr<Transfer>> schedule) {
	this->transfers = schedule;
}

void TransferHandler::checkForTransfers() {
    Date date = Date::getCurrentDate();
	for(auto t: transfers)
    {
        if(date>=t->getDate())
        {
            execute(t);
        }
    }
    std::remove_if(transfers.begin(), transfers.end(), [](std::shared_ptr<Transfer> t)->bool{return t->getIsExpired();});
    saveTransfersToFile("transfers.txt");
}

TransferHandler::TransferHandler() {
	loadTransfersFromFile("transfers.txt");
}

bool TransferHandler::loadTransfersFromFile(std::string filename) {
    std::ifstream file(filename);
    if(!file.good()) return false;
    std::string s;
    std::vector<std::string> vect;
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while(!file.eof())
    {
        std::getline(file, s);
        pos = 0;
        vect.clear();
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            vect.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        vect.push_back(s);
        if(s.size() != 9) continue;
        transfers.push_back(std::make_shared<Transfer>(
                          std::stoi(vect[0]),std::stoi(vect[1]),std::stoi(vect[2]),
                     Date(std::stoi(vect[3]),std::stoi(vect[4]),std::stoi(vect[5])),
                     Date(std::stoi(vect[6]),std::stoi(vect[7]),std::stoi(vect[8]))
                                                     ));
    }
    return true;
}

bool TransferHandler::saveTransfersToFile(std::string filename) {
    std::ofstream file(filename, std::ios::trunc);
    if(!file.good()) return false;
    for(auto i:transfers)
    {
        file << i->getFrom();
        file << i->getTo();
        file << i->getValue();
        file << i->getDate().getSpaceString();
        file << i->getPeriod().getSpaceString();
        file << std::endl;
    }
    return true;
}

bool TransferHandler::addTransfer(unsigned int id, unsigned int idt, unsigned int money, Date date, Date period) {
    std::shared_ptr<Transfer> t = std::make_shared<Transfer>(id, idt, money,date, period);
    //if(!t.check()) return false;
    transfers.push_back(t);
    return true;
}

/*
void TransferHandler::removeTransfer() {
	// TODO - implement TransferHandler::removeTransfer
	throw "Not yet implemented";
}
*/

bool TransferHandler::execute(std::shared_ptr<Transfer> arg)
{
    BankingSystem* bank = BankingSystem::getInstance();
    return bank->makeTransfer(arg);
}
