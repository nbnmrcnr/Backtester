#include "General_ToolBox.h"
#include <vector>
#include <iostream>
#include<Windows.h>
#include<string>
#include <ctime>
#define CURL_STATICLIB
#include <curl\curl.h>

using namespace std;

size_t General_ToolBox::write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

General_ToolBox::General_ToolBox() {
    testin = 0;
};

void General_ToolBox::addin() {
    testin = testin + 1;
    cout << testin;
    addinn();
};
void General_ToolBox::addinn() {
    testin = testin + 1;
    cout << testin;
};

void General_ToolBox::downloadFile(const char* url, const char* fname) {
    curl = curl_easy_init();
    FILE* fp;
    if (curl) {
        fp = fopen(fname, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

size_t General_ToolBox::writeFunction_get_request(void* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

int General_ToolBox::get_day_of_year() {
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    int answer = 0;
    tm timeinfo = {};
    timeinfo.tm_year = timePtr->tm_year;
    timeinfo.tm_mon = timePtr->tm_mon;
    timeinfo.tm_mday = timePtr->tm_mday;
    mktime(&timeinfo);
    answer = timeinfo.tm_yday;
    return answer;

}

vector<string> General_ToolBox::get_request(const char* url) {

        vector<string> results;
        std::string response_string;
        std::string header_string;
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
            curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
            curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);


            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction_get_request);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

            curl_easy_perform(curl);

            cout << response_string;
            results.push_back(response_string);
            results.push_back(header_string);
            curl_easy_cleanup(curl);
            curl_global_cleanup();

            curl = NULL;
        }
        return results;
}






