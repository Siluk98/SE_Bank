#include "../hpp/TransferHandler.hpp"

std::vector<Transfer*> TransferHandler::getTransfers() {
	return this->transfers;
}

void TransferHandler::setTransfers(std::vector<Transfer*> schedule) {
	this->transfers = schedule;
}

void TransferHandler::checkForTransfers() {
	// TODO - implement TransferHandler::checkForTransfers
	throw "Not yet implemented";
}

TransferHandler::TransferHandler() {
	// TODO - implement TransferHandler::TransferHandler
	throw "Not yet implemented";
}

bool TransferHandler::loadTransfersFromFile(std::string filename) {
	// TODO - implement TransferHandler::loadTransfersFromFile
	throw "Not yet implemented";
}

void TransferHandler::addTransfer() {
	// TODO - implement TransferHandler::addTransfer
	throw "Not yet implemented";
}

void TransferHandler::removeTransfer() {
	// TODO - implement TransferHandler::removeTransfer
	throw "Not yet implemented";
}
