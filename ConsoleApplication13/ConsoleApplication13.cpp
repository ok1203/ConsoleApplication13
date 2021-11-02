#include <iostream>
#include <future>
#include <mutex>
#include "Blockchain.h"
#include "Miner.h"
#include <thread>

using namespace std;

mutex mu;

double getTotalVolume(Blockchain& chain) {
  double total = 0;
  for (auto iter = chain.chain.begin(); iter != chain.chain.end(); ++iter) {
    total = total + iter->getTransaction_data().amount;
  }
  return total;
}

void shared_mine(Miner& miner, TransactionData& tt, Blockchain& blockchain) {
    lock_guard<mutex> guard(mu);

    miner.mine(tt, blockchain);
}

void func(Miner& miner, TransactionData& tt, Blockchain& blockchain) {
  for (int i = 0; i < 3; ++i) {
    shared_mine(miner, tt, blockchain);
  }
}

int main()
{
  Blockchain blockchain;
  future<double> res = async(launch::deferred, getTotalVolume, ref(blockchain));
  time_t current;
  TransactionData tt1( 111, "Omar", "Meiram", time(&current));
  TransactionData tt2(1000, "Yerzhan", "Damir", time(&current));
  Miner miner1;
  Miner miner2;

  blockchain.printBlockchain();
  thread thread1(func, ref(miner1), ref(tt1), ref(blockchain));
  thread thread2(func, ref(miner2), ref(tt2), ref(blockchain));

  thread1.join();
  thread2.join();
  blockchain.printBlockchain();


  if (blockchain.isBlockchainValid()) {
    cout << "Rabotaet" << endl;
  }
  cout << res.get() << endl;
  cout << getTotalVolume(blockchain) << endl;

}