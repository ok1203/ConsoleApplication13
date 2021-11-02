#include <iostream>
#include <future>
#include "Blockchain.h"
#include "Miner.h"
int main()
{
    Blockchain blockchain;
    blockchain.printBlockchain();
    time_t current;
    TransactionData tt1( 111, "Omar", "Meiram", time(&current));
    blockchain.addBlock(tt1);
    blockchain.addBlock(tt1);
    blockchain.printBlockchain();

    TransactionData tt2(1000, "Yerzhan", "Damir", time(&current));
    Miner miner = Miner();
    if (blockchain.isBlockchainValid()) {
        cout << "Rabotaet" << endl;
    }
    miner.addwithout(tt2, blockchain);

    blockchain.printBlockchain();

}