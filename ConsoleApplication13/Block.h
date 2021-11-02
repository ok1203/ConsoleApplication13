#pragma once
#include <string>
#include "TransactionData.h"
#include <iostream>
using namespace std;
class Block
{
public:
    size_t generateHash() {
        // creating string of transaction data
        string toHashS = to_string(transaction_data.amount) + transaction_data.receiverKey + transaction_data.senderKey + to_string(transaction_data.timestamp);
        // 2 hashes to combine
        hash<string> tDataHash; // hashes transaction data string
        hash<string> prevHash; // re-hashes previous hash (for combination)
        // combine hashes and get size_t for block hash
        return tDataHash(toHashS) ^ (prevHash(to_string(prev_hash)) << 1);
    }
    //Constructor:
    Block(int index, TransactionData data, size_t prev_hash)
    {
        this->index = index;
        this->transaction_data = data;
        this->prev_hash = prev_hash;
        this->block_hash = generateHash();
    }
    size_t getBlockHash()
    {
        return block_hash;
    }
    friend std::ostream& operator<< (std::ostream& out, Block const& curr )
    {
        out << curr.block_hash;
        return out;
    };

    TransactionData getTransaction_data() {
        return transaction_data;
    }
private:
    int index;
    TransactionData transaction_data;
    size_t prev_hash;
    size_t block_hash;
};

