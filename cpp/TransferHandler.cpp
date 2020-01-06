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
    Date date = getCurrentDate();
	for(auto t: transfers)
    {
        if(date>=t->getDate())
        {
            t->execute();
        }
    }
    std::remove_if(transfers.begin(), transfers.end(), [](std::shared_ptr<Transfer> t)->bool{return t->getIsExpired();});
}

TransferHandler::TransferHandler() {
	// TODO - implement TransferHandler::TransferHandler
	throw "Not yet implemented";
}

bool TransferHandler::loadTransfersFromFile(std::string filename) {
	// TODO - implement TransferHandler::loadTransfersFromFile
	throw "Not yet implemented";
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

Date TransferHandler::getCurrentDate()
{
    std::chrono::time_point t = std::chrono::system_clock::now();
    return Date(1970,1,1+std::chrono::system_clock::to_time_t(t)/86400);
}
