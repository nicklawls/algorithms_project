#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "board.h"

using namespace std;


int main(int argc, char** argv)
{
    Board testboard(5,5);

    for (int i = 0; i < testboard.depth(); ++i) {
        for (int j = 0; j < testboard.length(); ++j) {
            testboard.set_cell(i,j, i+j);
        }
    }

    cout << "printout of values using get_cell()" << endl;
    for (int i = 0; i < testboard.depth(); ++i) { // table filling
        for (int j = 0; j < testboard.length(); ++j) {
            cout << testboard.get_cell(i,j) << " ";
        }
        cout << endl;
    } cout << endl;

    cout << "printout of values using print()" << endl;

    testboard.print();
}
