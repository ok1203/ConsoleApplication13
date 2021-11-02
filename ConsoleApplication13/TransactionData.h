#pragma once
#include <string>
using namespace std;

class TransactionData
{
public:
	TransactionData(double amount, string senderKey, string receiverKey, time_t timestamp) {
		this->amount = amount;
		this->senderKey = senderKey;
		this->receiverKey = receiverKey;
		this->timestamp = timestamp;
	}
    TransactionData(){};

	double amount;
	string senderKey;
	string receiverKey;
	time_t timestamp;
};

