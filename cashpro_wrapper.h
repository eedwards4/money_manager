//
// Created by Ethan Edwards on 11/19/2023.
// A wrapper for sending JSON requests to the cashpro API.
//

#ifndef MONEY_MANAGER_CASHPRO_WRAPPER_H
#define MONEY_MANAGER_CASHPRO_WRAPPER_H

#include <curl/curl.h>
#include <string>
#include <iostream>

using namespace std;

class cashpro_wrapper {
public:
    cashpro_wrapper();
    ~cashpro_wrapper();
    string get_current_balance();

private:
    CURL* curl;
    CURLcode res;

    string CLIENT_ID = "CASHPRO_MREAC3BN_111823183718_SB";
    string APP_ID = "app_SonomaStateUniversityStudent_Reporting_SB";

};


#endif //MONEY_MANAGER_CASHPRO_WRAPPER_H
