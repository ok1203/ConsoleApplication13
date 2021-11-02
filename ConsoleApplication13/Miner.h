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
	void mine(TransactionData& data,  Blockchain& blockchain) {
		srand(time(0));
		int captcha = 1000 + (rand() % 1000);
		int input;
		cout << "Type in this captcha:" << captcha << endl;
		cin >> input;
		if (input == captcha) {
			blockchain.addBlock(data);
			cout << "Captcha is solved" << endl;
		}
		else {
			mine(data, blockchain);
      cout << "Captcha is not solved" << endl;
    }
	}
};