#ifndef __FILE_UTILS_H__
#define __FILE_UTILS_H__

#include <vector>
#include <string>

using namespace std;

class FileUtils {
    public:
        static vector<string> split_line_to_strings(string input, char delimiter, char quote_char, char comment_char);
        static bool read_as_list_of_strings(string filename, vector<string> & lines);
        static bool read_as_list_of_split_strings(string filename, vector<vector<string>> & split_strings, char delimiter, char quote_char, char comment_char);
        static bool read_as_list_of_split_longs(string filename, vector<vector<long>> & split_longs, char delimiter, char quote_char, char comment);
};

#endif
