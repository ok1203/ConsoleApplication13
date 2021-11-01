#pragma once
#include "Blockchain.h"
#include <ctime>
#include <iostream>
using namespace std;

class Miner
{
public:
	void mine(Blockchain blockchain, TransactionData data) {
		srand(time(0));
		int captcha = 1000 + (rand() % 1000);
		int input;
		cout << "Type in this captcha:" << captcha << endl;
		cin >> input;
		if (input == captcha) {
			blockchain.addBlock(data);
		}
		else {
			mine(blockchain, data);
		}
	}
};

