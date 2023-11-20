//
// Created by Ethan Edwards on 11/19/2023.
//

#include "cashpro_wrapper.h"

cashpro_wrapper::cashpro_wrapper(){
    // Initialize cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

cashpro_wrapper::~cashpro_wrapper() {
    // Cleanup cURL
    curl_global_cleanup();
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

size_t HeaderCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

string cashpro_wrapper::get_current_balance() {
    string curr_balance, response_data;
    // Set up the request
    const char* json_data = "{\"clientId\":\"CASHPRO_MREAC3BN_111823183718_SB\",\"appId\":\"app_SonomaStateUniversityStudent_Reporting_SB\"}";
    if (curl){
        // Set curl options
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.bankofamerica.com/cashpro/reporting/v1/balance-inquiries/current-day");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data);
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        std::string header_data;
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, HeaderCallback);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_data);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Parse the response
            long http_response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_response_code);
            std::cout << "HTTP Response Code: " << http_response_code << std::endl;

            std::cout << "Response Headers:\n" << header_data << std::endl;
        }

        // Cleanup
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return response_data;
}
