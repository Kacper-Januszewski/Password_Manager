#include "Writer.h"

void Writer::KeyWrite(std::string targetFile, std::string wrtKey)
{
	std::ofstream file_out_key(targetFile);
    if (!file_out_key.is_open()) {
        std::cout << "Cannot open file.";
        return;
    }

    file_out_key << wrtKey << '\n';

    file_out_key.close();
    return;
}

void Writer::timestampWrite(std::string targetFile, std::string wrtKey, int seconds, int minutes, int hours, int wday, int mday, int month, int year) {
    std::ofstream file_out_timestamp(targetFile, std::ios::app);
    if (!file_out_timestamp.is_open()) {
        std::cout << "Cannot open file.";
        return;
    }

    file_out_timestamp << seconds << '"' << minutes << '"' << hours << '"' << wday << '"' << mday << '"' << month << '"' << year << '\n';

    file_out_timestamp.close();
    return;
}

void Writer::BasicWrite(std::string targetFile, std::string wrtCategory, std::string wrtName, std::string wrtPassword)
{
	std::ofstream file_out_basic(targetFile, std::ios::app);

    if (!file_out_basic.is_open()) {
        std::cout << "Cannot open file.";
        return;
    }

    file_out_basic << wrtCategory << '"' << wrtName << '"' << wrtPassword << '\n';

    file_out_basic.close();
    return;
}

void Writer::FullWrite(std::string targetFile, std::string wrtCategory, std::string wrtName, std::string wrtPassword, std::string wrtSite, std::string wrtLogin)
{
	std::ofstream file_out_full(targetFile, std::ios::app);

    if (!file_out_full.is_open()) {
        std::cout << "Cannot open file.";
        return;
    }

    file_out_full << wrtCategory << '"' << wrtName << '"' << wrtPassword << '"' << wrtSite << '"' << wrtLogin << '\n';

    file_out_full.close();
    return;
}

void Writer::Rewrite(std::string targetFile, std::vector<Password_Data> rewriteData, std::string wrtKey, int seconds, int minutes, int hours, int wday, int mday, int month, int year) {
    std::ofstream file_out(targetFile);
    if (!file_out.is_open()) {
        std::cout << "Cannot open file.";
        return;
    }
    else {
        KeyWrite(targetFile, wrtKey);
        timestampWrite(targetFile, wrtKey, seconds, minutes, hours, wday, mday, month, year);
        for (Password_Data el : rewriteData) {
            if (el.getSize() == 1) {
                FullWrite(targetFile, el.getCategory(), el.getName(), el.getPassword(), el.getSite(), el.getLogin());
            }
            else {
                BasicWrite(targetFile, el.getCategory(), el.getName(), el.getPassword());
            }
        }
        file_out.close();
    }
    return;
}