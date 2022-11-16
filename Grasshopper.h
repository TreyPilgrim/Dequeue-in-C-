/*
 * Declaration of Grasshopper Class
 */
#pragma once
#include <string>
#include "Dequeue.h"
#include "Node.h"

using std::string;

class Grasshopper
{
private:
    Dequeue theTummy;

public:

    // Void return types
    void tummyCleanse();

    // Bool Return Type
    bool ateFood(string foodType);
    bool tookCaca();
    bool threwUp();
    bool displayTummy();
    bool isEmpty();

    // String Return Type
    string hungryStatus();





};


