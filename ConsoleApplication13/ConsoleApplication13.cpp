#include <iostream>
#include <future>
#include "Blockchain.h"
#include "Miner.h"
int main()
{
    //std::cout << "Hello World!\n";
    Blockchain blockchain;
    blockchain.printBlockchain();
    time_t current;
    TransactionData tt1( 111, "Omar", "Meiram", time(&current));
    blockchain.addBlock(tt1);
    blockchain.addBlock(tt1);
    blockchain.addBlock(tt1);
    blockchain.printBlockchain();
    
    time_t current2;
    TransactionData tt2(1000, "Erzhan", "Damir", time(&current2));
    Miner miner(blockchain);
    if (blockchain.isBlockchainValid()) {
        cout << "Rabotaet" << endl;
    }
    miner.addwithout(tt2);
    miner.addwithout(tt2);
    miner.addwithout(tt2);
    blockchain.printBlockchain();

    //double getTotalVolume(Blockchain &chain){
    //    return;
    //}
    //async();

}