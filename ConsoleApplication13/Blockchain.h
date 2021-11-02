#pragma once
#include "Block.h"
#include <vector>
#include <time.h>
#include <iomanip>
#include <iostream>

using namespace std;

class Blockchain
{
public:
    vector<Block> chain;
    //Has one constructor: 
    Blockchain() {
        Block firstBlock = createFirstBlock();
        chain.push_back(firstBlock);
    }
    //Methods:
    Block createFirstBlock()
    {
        time_t current;
        // Setup Initial Transaction Data
        TransactionData dataFirstBlock(0, "FirstBlock", "FirstBlock", time(&current));
        Block firstBlock(0, dataFirstBlock, 0);
        return firstBlock;
    }
    void addBlock(TransactionData data)
    {
        int index = (int)chain.size();
        size_t previousHash = getLatestBlock()->getBlockHash();
        Block newBlock(index, data, previousHash);
        chain.push_back(newBlock);
        cout << "success" << endl;
    }
    Block* getLatestBlock()
    {
        return &chain.back();
    }
    void printBlockchain(){
        for (auto it_vec = chain.begin(); it_vec != chain.end(); ++it_vec)
            cout<<"Sender: "<<setw(10)<<it_vec->getTransaction_data().senderKey<<" | "<<
            " Receiver: "<<setw(10)<<it_vec->getTransaction_data().receiverKey<<" | "<<" Amount: "<<setw(10)<<it_vec->getTransaction_data().amount<<" | "<<
            " Timestamp: "<<it_vec->getTransaction_data().timestamp<<" | "<<" Hash: "<<*it_vec<<endl;
    }

    bool isBlockchainValid() {
        for (auto iter = chain.begin(); iter != chain.end(); ++iter) {
            if (iter->generateHash() != iter->getBlockHash()) {
                return false;
            }
        }
        return true;
    }

};

