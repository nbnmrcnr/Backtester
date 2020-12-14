#include "fonctionsnico.h"
#include <vector>
#include "csv.h"
//#include <JSon.hpp>
#include <ctime>
#include <iostream>
#include <sys/stat.h>

#include <string>
#include <fstream>
#include <Urlmon.h>
// for convenience
//using json = nlohmann::json;
using namespace std;

FonctionsNico::FonctionsNico()
{


}

#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
using namespace std;


double FonctionsNico::date_to_hours_left(std::string date) {
    double result = 0;
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int year_rn = now->tm_year - 100;
    int day_rn = now->tm_yday;
    int hour_rn = now->tm_hour;

    int year_target = std::stoi(date.substr(date.size() - 2, 2));
    std::string month_target_s = date.substr(date.size() - 5, 3);
    int month_tar = 0;
    if (month_target_s == "JAN") {
        month_tar = 1;
    }
    if (month_target_s == "FEV") {
        month_tar = 2;
    }
    if (month_target_s == "MAR") {
        month_tar = 3;
    }
    if (month_target_s == "APR") {
        month_tar = 4;
    }
    if (month_target_s == "MAY") {
        month_tar = 5;
    }
    if (month_target_s == "JUN") {
        month_tar = 6;
    }
    if (month_target_s == "JUL") {
        month_tar = 7;
    }
    if (month_target_s == "AUG") {
        month_tar = 8;
    }

    if (month_target_s == "SEP") {
        month_tar = 9;
    }
    if (month_target_s == "OCT") {
        month_tar = 10;
    }

    if (month_target_s == "NOV") {
        month_tar = 11;
    }
    if (month_target_s == "DEC") {
        month_tar = 12;
    }
    month_tar = month_tar - 1;
    int longueur_day = 2;
    if (date.size() == 8) {
        longueur_day = 1;
    }
    int day_l = std::stoi(date.substr(0, longueur_day));
    int hour_target = 8;
    int jours_mois = 0;
    int deus = 0;
    for (int mois = 0; mois < month_tar; mois++) {

        if (deus == 0) {
            deus = 1;
            jours_mois = jours_mois + 31;
        }
        if (deus == 1) {
            deus = 0;
            jours_mois = jours_mois + 30;
        }
    }

    int day_of_the_year = jours_mois + day_l;
    int jours_total = 0;
    if (year_target == year_rn) {
        jours_total = day_of_the_year - day_rn;
        result = jours_total * 24 - hour_rn + hour_target;
    }
    else if (year_target == year_rn + 1) {
        jours_total = 365 - day_rn;
        jours_total = jours_total + day_of_the_year;
        result = jours_total * 24 - hour_rn + hour_target;
    }
    return result;
}
double FonctionsNico::Normale(double quantile) {
    return 0.5;
}

int FonctionsNico::get_day_of_week() {

    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int month = now->tm_wday + 1;
    return month;
}

int FonctionsNico::get_index_of_str(std::vector<std::string> base, std::string element) {
    int to_ret = -1;
    for (int id_el = 0; id_el < base.size(); id_el++) {
        if (base[id_el] == element) {
            to_ret = id_el;
            break;

        }
    }
    return to_ret;
}
int FonctionsNico::get_day_of_year() {
    int r = 0;
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int month = now->tm_mon + 1;
    int day = now->tm_mday;

    if (month > 1) {
        day = day + 31;
    }

    if (month > 2) {
        day = day + 28;
    }

    if (month > 3) {
        day = day + 31;
    }

    if (month > 4) {
        day = day + 30;
    }

    if (month > 5) {
        day = day + 31;
    }

    if (month > 6) {
        day = day + 30;
    }

    if (month > 7) {
        day = day + 31;
    }

    if (month > 8) {
        day = day + 30;
    }

    if (month > 9) {
        day = day + 31;
    }

    if (month > 10) {
        day = day + 30;
    }

    if (month > 11) {
        day = day + 31;
    }

    return day + 1;
}

std::vector<std::pair<std::string, std::vector<double>>> FonctionsNico::read_csv_loc_two(std::string filename) {
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::pair<std::string, std::vector<double>>> result;

    // Create an input filestream
    std::ifstream myFile(filename);

    try {
        // Make sure the file is open
        if (!myFile.is_open()) throw std::runtime_error("Could not open file");

        // Helper vars
        std::string line, colname;
        int val;
        double ddbl;
        // Read the column names
        if (myFile.good())
        {
            // Extract the first line in the file
            std::getline(myFile, line);

            // Create a stringstream from line
            std::stringstream ss(line);

            // Extract each column name
            while (std::getline(ss, colname, ',')) {

                // Initialize and add <colname, int vector> pairs to result
                result.push_back({ colname, std::vector<double> {} });
            }
        }

        // Read data, line by line
        while (std::getline(myFile, line))
        {
            // Create a stringstream of the current line


            // Keep track of the current column index
            string current_line = line;
            string remaining = line;
            string substring;
            int colIdx = 0;
            for (int curs = 0; curs < result.size(); curs++) {
                string::size_type loc = remaining.find(",", 0);
                if (loc != string::npos) {
                    substring = remaining.substr(0, loc);
                    remaining = remaining.substr(loc + 1);
                    ddbl = atof(substring.c_str());
                }
                else {
                    ddbl = atof(remaining.c_str());
                }
                // Initialize and add <colname, int vector> pairs to result
                result[colIdx].second.push_back(ddbl);
                colIdx = colIdx + 1;
            }
            // Extract each integer

        }
    }
    catch (std::exception e) {
        int serafoy = 0;
    }
    // Close file
    myFile.close();

    return result;
}


std::vector<std::vector<double>> FonctionsNico::read_csv_loc(std::string filename) {
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::vector<double>> result;

    std::vector<std::string> unused_labels;
    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname;
    int val;
    double ddbl;
    // Read the column names
    if (myFile.good())
    {
        // Extract the first line in the file
        std::getline(myFile, line);

        // Create a stringstream from line
        std::stringstream ss(line);

        // Extract each column name
        while (std::getline(ss, colname, ',')) {
            std::vector<double> result_loc;
            // Initialize and add <colname, int vector> pairs to result
            unused_labels.push_back(colname);
            result.push_back(result_loc);
        }
    }

    // Read data, line by line
    while (std::getline(myFile, line))
    {
        // Create a stringstream of the current line


        // Keep track of the current column index
        string current_line = line;
        string remaining = line;
        string substring;
        int colIdx = 0;
        for (int curs = 0; curs < result.size(); curs++) {
            string::size_type loc = remaining.find(",", 0);
            if (loc != string::npos) {
                substring = remaining.substr(0, loc);
                remaining = remaining.substr(loc + 1);
                ddbl = atof(substring.c_str());
            }
            else {
                ddbl = atof(remaining.c_str());
            }
            // Initialize and add <colname, int vector> pairs to result
            result[colIdx].push_back(ddbl);
            colIdx = colIdx + 1;
        }
        // Extract each integer

    }

    // Close file
    myFile.close();

    return result;
}

string FonctionsNico::CurrentHourMinute()
{
    int r = 0;
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::string retour = "";
    retour = retour + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);
    return retour;
}

std::vector<std::string> FonctionsNico::read_csv_loc_string_only(std::string filename) {
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::string> result;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname;
    int val;
    std::string ddbl;
    // Read the column names


    // Read data, line by line

    while (std::getline(myFile, line))
    {
        // Create a stringstream of the current line


        // Keep track of the current column index
        string current_line = line;
        string remaining = line;
        string substring;
        int colIdx = 0;
        if (true) {
            string::size_type loc = remaining.find(",", 0);
            if (loc != string::npos) {
                substring = remaining.substr(0, loc);
                remaining = remaining.substr(loc + 1);
                ddbl = substring;
            }
            else {
                ddbl = remaining;
            }
            // Initialize and add <colname, int vector> pairs to result
            result.push_back(ddbl);
            colIdx = colIdx + 1;
        }
        // Extract each integer

    }

    // Close file
    myFile.close();
    result.erase(result.begin(), result.begin() + 1);
    return result;
}


std::vector<std::vector<double>> FonctionsNico::parse_datas(std::vector<std::vector<std::string>>) {
    std::vector<std::vector<double>> all_results;


    return all_results;
}

bool FonctionsNico::file_exists(std::string name) {
    std::ifstream f(name.c_str());
    return f.good();
}

string FonctionsNico::getFilename(string filename, string label_serie, int todayy) {
    return "local_saved_datas/" + filename + "_loc_" + label_serie + "_" + std::to_string(todayy) + ".csv";
}
void FonctionsNico::write_csv_all_datas(std::string filename, std::vector<std::vector<double>> dataset, std::vector<std::string> labels) {
    try {


        int _today_day = get_day_of_year();

        for (int serie = 0; serie < dataset.size(); serie++) {
            std::vector<std::vector<double>> dataset_tmp;
            std::vector<std::string> labels_tmp;
            dataset_tmp.push_back(dataset[serie]);
            labels_tmp.push_back(labels[serie]);
            write_csv(getFilename(filename, labels[serie], _today_day), dataset_tmp, labels_tmp);
        }
        write_csv_string_only("local_saved_datas/last_index.csv", labels, "Indexx");

    }
    catch (std::exception e) {
        int serafoy = 0;
    }
}

void FonctionsNico::write_csv(std::string filename, std::vector<std::vector<double>> dataset, std::vector<std::string> labels) {
    // Make a CSV file with one or more columns of integer values
    // Each column of data is represented by the pair <column name, column data>
    //   as std::pair<std::string, std::vector<int>>
    // The dataset is represented as a vector of these columns
    // Note that all columns should be the same size

    // Create an output filestream object
    std::ofstream myFile(filename);

    // Send column names to the stream
    for (int j = 0; j < dataset.size(); ++j)
    {
        myFile << labels[j];
        if (j != dataset.size() - 1) myFile << ","; // No comma at end of line
    }
    myFile << "\n";

    // Send data to the stream
    for (int i = 0; i < dataset[0].size(); ++i)
    {
        for (int j = 0; j < dataset.size(); ++j)
        {
            myFile << dataset[j][i];
            if (j != dataset.size() - 1) myFile << ","; // No comma at end of line
        }
        myFile << "\n";
    }

    // Close the file
    myFile.close();
}


void FonctionsNico::write_csv_string_only(std::string filename, std::vector<std::string> dataset, std::string labels) {
    // Make a CSV file with one or more columns of integer values
    // Each column of data is represented by the pair <column name, column data>
    //   as std::pair<std::string, std::vector<int>>
    // The dataset is represented as a vector of these columns
    // Note that all columns should be the same size

    // Create an output filestream object
    std::ofstream myFile(filename);

    // Send column names to the stream

    myFile << labels;

    myFile << "\n";

    // Send data to the stream
    for (int i = 0; i < dataset.size(); ++i)
    {
        myFile << dataset[i];
        myFile << "\n";
    }

    // Close the file
    myFile.close();
}
