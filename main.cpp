/*
 * Student Name: Trey Fullwood
 * Student NetID: rf802
 * Compiler Used: clion using g++.exe
 * Program Description:
 * This program allows a grasshopper, Hopper, to eat, excrete, vomit food.
 * Via the program you can view the contents of the stomach, clear all contents, as well as check the hunger status.
 *
 * Inputs are:
 * load <file> - parses the contents of file as if they were entered in teh text-based interface
 * eat <leaf, grass, seed> - instructs Hopper to eat specified food. If stomach is full, Hopper will not eat
 * excrete - removes oldest item consumed
 * vomit - removes newest item consumed
 * clear - set contents of grasshopper's stomach to empty
 * status - reports if the grasshopper is starving, full, or how much of its stomach capacity is full
 * display - displays a list of items in the Hopper's stomach
 */
#include <iostream>
#include <string>
#include "Grasshopper.h"
#include "Tokenizer.h"
#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


bool processText(istream& is, Grasshopper &hopper, bool interactive = true)
{
    string line;
    string command;
    string arg1, food;
    Tokenizer tkn;


    while (true)
    {
        if (!interactive)
        {
            if (is.eof()) return true;
        }
        else { cout << ">> "; }

        getline(is, line);
        tkn.setString(line);

        tkn.readWord(command);

        // command == exit
        if (command == "exit")
        {
            cout << "Exiting ...." << endl;
            return false;
        }
        // command == load
        else if (command == "load")
        {
            // load expects a filename
            if (!tkn.readWord(arg1)) {
                cout << "Missing file name" << endl;
                continue; // skip back to the top of the read loop
            }
            ifstream fin;
            bool status = true;
            fin.open(arg1);
            if (fin.is_open())
            {
                status = processText(fin, hopper, false);
            }
            else { cout << "Failed to open the file" << endl; }
            fin.close();
            if (!status) return false;
        }
        // command == eat
        else if (command == "eat")
        {
            if (tkn.readWord(food))
            {
                if (hopper.ateFood(food))
                    cout << hopper.hungryStatus() << endl;
            }

            continue;
        }
        // command == excrete
        else if (command == "excrete")
        {
            if (hopper.tookCaca())
                cout << "Hopper has " << hopper.hungryStatus() << endl;
            else
                cout << "Hopper is starving... nothing to excrete, please feed Hopper." << endl;

            continue;
        }
        // command == vomit
        else if (command == "vomit")
        {
            if (hopper.threwUp())
                cout << "Hopper has " << hopper.hungryStatus() << endl;
            else
                cout << "Hopper is starving... nothing to vomit, please feed Hopper." << endl;

            continue;
        }
        // command == clear
        else if (command == "clear")
        {
            hopper.tummyCleanse();
            cout << hopper.hungryStatus() << endl;
            continue;
        }
        // command == status
        else if (command == "status")
        {
            cout << hopper.hungryStatus() << endl;
            continue;
        }
        // command == display
        else if (command == "display")
        {
            if (hopper.isEmpty()) // if tummy is empty
                cout << hopper.hungryStatus() << endl;
            else // otherwise
                hopper.displayTummy();

            continue;
        }
        // Otherwise
        else
        {
            cout << "You want to do WHAT to hopper???" << endl;
            continue;
        }

    }


}


int main()
{
    Grasshopper hopper;
    processText(cin, hopper);
    return 0;

}
