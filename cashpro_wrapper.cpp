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

string cashpro_wrapper::get_current_balance() {
    string curr_balance, response_data;
    if (curl){
        // Set curl options
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Request was successful, handle the response data
            cout << "Response: " << response_data << endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    return response_data;
}
