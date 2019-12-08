#ifndef TRANSFERHANDLER_H
#define TRANSFERHANDLER_H
#include <vector>
#include "Transfer.hpp"
#include <fstream>
class TransferHandler {
public:
    TransferHandler();
	std::vector<Transfer*> getTransfers();
	void setTransfers(std::vector<Transfer*> schedule);
	void addTransfer();
private:
	std::vector<Transfer*> transfers;
	void checkForTransfers();
	bool loadTransfersFromFile(std::string filename);
	void removeTransfer();
};

#endif
