/*
 * Function declarations for Grasshopper.h
 */

#include "Grasshopper.h"

using namespace std;

/*
 * Void Return Type
 */
// empty theTummy
void Grasshopper::tummyCleanse()
{
    while (true)
    {
        theTummy.caca();

        if (isEmpty())
            break;
        else
            continue;
    }
}

/*
 * Bool Return Type
 */

// Make the Grasshopper eat
bool Grasshopper::ateFood(std::string foodType)
{
    return theTummy.eatFood(foodType);
}

// Make the Grasshopper caca
bool Grasshopper::tookCaca()
{
    return theTummy.caca();
}

// Make the Grasshopper barf
bool Grasshopper::threwUp()
{
    return theTummy.barf();
}

// Display guts
bool Grasshopper::displayTummy()
{
    return theTummy.showTummy();
}

// isEmtpy
bool Grasshopper::isEmpty()
{
    return theTummy.isEmpty();
}

/*
 * String Return Type
 */
// Hungry status
string Grasshopper::hungryStatus()
{
    return theTummy.howHungry();
}
