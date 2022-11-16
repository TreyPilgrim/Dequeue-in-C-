/*
 * Function declarations for the Deque
 */

#include "Dequeue.h"
#include <map>
#include <memory>
#include <iostream>

using namespace std;
using ptr = shared_ptr<Node>;

    //      Private Functions   //
/*
 * Bool Return Type
 */

// Push to front
bool Dequeue::pushFront(string foodType)
{
    ptr tmp = make_shared<Node>(foodType);

    // Map for every input option
    map <string, int> foods;
    foods.insert (pair<string, int>("Seed", 1));
    foods.insert (pair<string, int>("seed", 1));
    foods.insert (pair<string, int> ("Leaf", 2));
    foods.insert (pair<string, int> ("leaf", 2));
    foods.insert(pair<string, int>("Grass", 5));
    foods.insert(pair<string, int>("grass", 5));


    // Using the map, set the size of node (foodSize)
    // to the string passed in. Set size to 0 if invalid input
    tmp->foodSize = (foods[foodType]) ? foods[foodType] : 0;

    // Return false if invalid input OR
    // Tummy is too full
    bool vibes = eating(tmp->foodSize);

    if (tmp->foodSize == 0 || !vibes)
    {
        // if failed because tummy is too full
        if (tmp->foodSize != 0)
            cout << "Tummy is too full, cannot eat the " << foodType << endl;
        else // otherwise, failed due to invalid input
            cout << "What are you having Hopper eat?? " << endl
            << "Grasshopper diets consist of: Seed, Leaf, and Grass" << endl;

        return false;
    }

    // If head == nullptr
    // update tail
    if (head == nullptr)
        tail = tmp;
    else { // Otherwise, update head->prev
        head->prev = tmp;
        tmp->next = head;
    }

    // Update Head and return true
    head = tmp;
    return true;


}

// Pop the tail
bool Dequeue::popBack()
{
    // return false if empty
    if (tail == nullptr)
        return false;

    ptr tmp = tail;

    // Update Tummy
    waste(tmp->foodSize);

    // if only 1 element in  Dequeue
    if (tummyCount == 0)
    {
        tail = nullptr;
        head = nullptr;
        return true;
    }
    // Update tail
    tmp->prev->next = nullptr;
    tail = tail->prev;

    return true;

}

// Pop the head
bool Dequeue::popFront()
{
    // return false if empty
    if (head == nullptr)
        return false;

    ptr tmp = head;

    // Update Tummy
    updateTummy(tmp->foodSize);

    // if only 1 element in  Dequeue
    if (tummyCount == 0)
    {
        tail = nullptr;
        head = nullptr;
        return true;
    }

    // Update Deque
    tmp->next->prev = nullptr;
    head = head->next;

    return true;
}
// Check if tummy is full
bool Dequeue::eating(int foodSize)
{
    tummyCount += foodSize;

    if (tummyCount > maxTummy)
    {
        tummyCount -= foodSize;
        return false;
    }

    return true;
}

// decrement tummyCount
bool Dequeue::waste(int foodSize)
{
    tummyCount -= foodSize;
    return true;
}

    //      Public Functions    //
/*
 *  Bool Return Type
 */
// pushFront
bool Dequeue::eatFood(std::string name)
{
    return pushFront(name);
}

// excrete
bool Dequeue::caca()
{
    return popBack();
}

// vomit
bool Dequeue::barf()
{
    return popFront();
}

// display theTummy
bool Dequeue::showTummy()
{
    if (head == nullptr)
        return false;

    ptr tmp = head;

    cout << "From most recent, to oldest:" << endl;

    while (tmp != nullptr)
    {
        displayNode(tmp);
        cout << "=========================================" << endl;
        tmp = tmp->next;
    }

    return true;
}

// is Dequeue emtpy
bool Dequeue::isEmpty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}
/*
 * Void Return Type
 */
// display the node
void Dequeue::displayNode(const ptr& food)
{
    cout << "Food: " << food->foodType << endl;
    cout << "Size: " << food->foodSize << endl;
}


/*
 * String Return Type
 */
// Let user know if tummy is full, starving
// or how much is in the tummy
string Dequeue::howHungry() const
{
    if (tummyCount == 0) // if empty stomach
        return "0 capacities filled, Hopper is starving";
    else if (tummyCount == 11) // if full stomach
        return "11 capacities filled, Hopper is full";
    else // otherwise
    {
        // Make map
        map<int, string> tummyValues;
        tummyValues.insert(pair<int, string>(1, "1 capacity filled, 10 remaining spaces"));
        tummyValues.insert(pair<int, string>(2, "2 capacities filled, 9 remaining spaces"));
        tummyValues.insert(pair<int, string>(3, "3 capacities filled, 8 remaining spaces"));
        tummyValues.insert(pair<int, string>(4, "4 capacities filled, 7 remaining spaces"));
        tummyValues.insert(pair<int, string>(5, "5 capacities filled, 6 remaining spaces"));
        tummyValues.insert(pair<int, string>(6, "6 capacities filled, 5 remaining spaces"));
        tummyValues.insert(pair<int, string>(7, "7 capacities filled, 4 remaining spaces"));
        tummyValues.insert(pair<int, string>(8, "8 capacities filled, 3 remaining spaces"));
        tummyValues.insert(pair<int, string>(9, "9 capacities filled, 2 remaining spaces"));
        tummyValues.insert(pair<int, string>(10, "10 capacities filled, 1 remaining space"));

        string tummyString = tummyValues[tummyCount];
        return tummyString;
    }
}