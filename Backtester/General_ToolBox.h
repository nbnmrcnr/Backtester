#pragma once
#ifndef THE_FILE_NAME_H 
#define THE_FILE_NAME_H 
#define CURL_STATICLIB
#include <curl\curl.h>
#include <string>
#include <vector>
class General_ToolBox
{

private:
    CURL* curl;
    CURLcode res;
    int testin;

private:
    static size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream);
    static size_t writeFunction_get_request(void* ptr, size_t size, size_t nmemb, std::string* data);

public:
    void addin();
    void addinn();

    General_ToolBox();

  
    void downloadFile(const char* url, const char* fname);
    std::vector<std::string> get_request(const char* url);

    static int get_day_of_year();


};

#endif 