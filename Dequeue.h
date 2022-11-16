/*
 * Declaration of Deque Class
 */
#pragma once
#include <string>
#include <memory>
#include "Node.h"
using ptr = std::shared_ptr<Node>;
class Dequeue
{
private:

    ptr head = std::make_shared<Node>();
    ptr tail = std::make_shared<Node>();

    const int maxTummy {11};
    int tummyCount {0};

    // Bool Return Type
    bool pushFront(string name);
    bool popBack();
    bool popFront();
    bool eating (int foodSize);
    bool waste (int foodSize);

public:

    // Default Constructor
    Dequeue(): head {nullptr}, tail {nullptr} {}
    ~Dequeue()
    {
        while (head != nullptr)
        {
            this->popBack();
        }
    }

    // Bool Return Type
    bool eatFood(string name);
    bool caca();
    bool barf();
    bool showTummy();
    bool isEmpty();

    // Void Return Type
    static void displayNode(const ptr& food);
    void updateTummy(int foodSize) {tummyCount -= foodSize;}

    // String Return Type
    string howHungry() const;


};
