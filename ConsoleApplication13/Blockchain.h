#pragma once
#include "Block.h"
#include <vector>
#include <time.h>
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
    }
    Block* getLatestBlock()
    {
        return &chain.back();
    }
    Block printBlockchain(){
       // vector<Block>::iterator it_vec = chain.begin();
        for (auto it_vec = chain.begin(); it_vec != chain.end(); ++it_vec)
            cout << *it_vec <<' ';
    }


    bool isBlockchainValid() {
        auto iter = chain.begin();
        while (iter != chain.end()) {
            if (iter->generateHash() != iter->getBlockHash()) {
                return false;
            }
        }
        return true;
    }

};

