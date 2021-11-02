#include <iostream>
#include <future>
#include "Blockchain.h"
#include "Miner.h"
#include <thread>

using namespace std;

double getTotalVolume(Blockchain& chain) {
    double total = 0;
    for (auto iter = chain.chain.begin(); iter != chain.chain.end(); ++iter) {
        total = total + iter->getTransaction_data().amount;
    }
    return total;
}


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
    miner.mine(tt2);
    miner.mine(tt2);
    miner.mine(tt2);
    blockchain.printBlockchain();
    cout << getTotalVolume(blockchain) << endl;

    //double getTotalVolume(Blockchain &chain){
    //    return;
    //}
    //async();

}

