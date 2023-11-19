/*
 * Money manager
 * Created by Ethan Edwards on 11/13/23.
 * This program will help you manage your money, probably.
 */

#include <iostream>
#include <string>

#include "cashpro_wrapper.h"

using namespace std;

int main() {
    // Start subprocesses
    cashpro_wrapper cashpro;

    cout << cashpro.get_current_balance() << endl;

    return 0;
}
