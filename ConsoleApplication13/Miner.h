#pragma once
#include "Blockchain.h"
#include "Block.h"
#include <time.h>
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

class Miner
{
public:
	Blockchain blockchain;

	Miner(Blockchain blockchain) {
		this->blockchain = blockchain;
	};

	void addwithout( TransactionData data) {
		blockchain.addBlock(data);
	}

	void mine(TransactionData data) {
		srand(time(0));
		int captcha = 1000 + (rand() % 1000);
		int input;
		cout << "Type in this captcha:" << captcha << endl;
		cin >> input;
		if (input == captcha) {
			blockchain.addBlock(data);
			cout << "gfhdshfdj" << endl;
		}
		else {
			mine(data);
			cout << "no not working" << endl;
		}
	}
};

