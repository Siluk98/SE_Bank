#ifndef TRANSFERHANDLER_HPP
#define TRANSFERHANDLER_HPP
#include <vector>
#include "Transfer.hpp"
#include <fstream>
#include <chrono>
#include <memory>
#include <algorithm>
#include "Date.hpp"
class TransferHandler {
public:
    static TransferHandler& getInstance();
	std::vector<std::shared_ptr<Transfer>> getTransfers();
	void setTransfers(std::vector<std::shared_ptr<Transfer>> schedule);
	bool addTransfer(unsigned int id, unsigned int idt, unsigned int money, Date date, Date Period);
	Date getCurrentDate();
private:
    TransferHandler();
	std::vector<std::shared_ptr<Transfer>> transfers;
	void checkForTransfers();
	bool loadTransfersFromFile(std::string filename);
	//void removeTransfer();
};

#endif
