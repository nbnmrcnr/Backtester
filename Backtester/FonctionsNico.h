#ifndef FONCTIONSNICO_H
#define FONCTIONSNICO_H


#include "csv.h"
class FonctionsNico
{
public:
    FonctionsNico();
    static std::vector<std::vector<double>> read_csv_loc(std::string);
    static std::vector<std::string> read_csv_loc_string_only(std::string);
    static std::vector<std::pair<std::string, std::vector<double>>> read_csv_loc_two(std::string);
    static double date_to_hours_left(std::string);
    static double Normale(double);
    static int get_day_of_year();
    static int get_day_of_week();
    static void write_csv(std::string, std::vector<std::vector<double>>, std::vector<std::string>);
    static void write_csv_string_only(std::string, std::vector<std::string>, std::string);
    static void write_csv_all_datas(std::string, std::vector<std::vector<double>>, std::vector<std::string>);
    static bool file_exists(std::string);
    static std::vector<std::vector<double>> parse_datas(std::vector<std::vector<std::string>>);
    static std::string getFilename(std::string, std::string, int);
    static std::string CurrentHourMinute();
    static int get_index_of_str(std::vector<std::string>, std::string);
};

#endif // FONCTIONSNICO_H
