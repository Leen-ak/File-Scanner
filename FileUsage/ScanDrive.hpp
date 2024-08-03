/*
author: Leen Aboukkhail
Data: 12 April 2024
Purpose: The program is a command-line file utility that scans directories to analyze and report on file types and sizes,
        supporting sorting and filtering options via flags. Users can sort files by size, extension, or in reverse order,
        and apply regular expression filters to target specific file types. The tool provides formatted output detailing
        file extensions, counts, and total sizes, with options for recursive directory traversal and detailed help instructions.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <map>
#include <regex> 
using namespace std::filesystem;

/*
class:  Booleans
brief:  The Booleans struct holds flags that represent various command-line options for the file utility application. 
        These flags indicate whether to display help, reverse sorting order, sort files by size, sort by size within extensions, 
        and filter with regular expressions.
*/
struct Booleans {
    bool help{ false }; 
    bool reverse{ false };
    bool sortSize{ false }; 
    bool sortSizeByExt{ false }; 
    bool regex{ false };
};

/*
class:  Files
brief:  The Files class represents a file with its extension and size.
        It is used to store and manage information about files found during directory traversal, 
        facilitating sorting and reporting operations.
*/
class Files{
public:
    std::string fileExt;
    unsigned int fileSize; 

    Files(std::string fileExtension, unsigned int fileSize) 
        : fileExt(fileExtension), fileSize(fileSize) {}
};

/*
fn:     sortReverse 
brief:  provide custom sorting logic for the Files class objects. To sort the extension in descending order 
param:  Files object lhs, Files object rhs
return: bool 
*/
inline bool sortReverse(const Files& lhs, const Files& rhs) {
    return lhs.fileExt > rhs.fileExt; 
}

/*
fn:     sortSizeb
brief:  provide custom sorting logic for the Files class objects. sorting size of the file in ascending order 
param:  Files object lhs, Files object rhs
return: bool
*/
inline bool sortSize(const Files& lhs, const Files& rhs) {
    return lhs.fileSize < rhs.fileSize; 
}

/*
fn:     sortSizeByExt
brief:  provide custom sorting logic for the Files class objects. It is intended to order the files primarily 
        by their size and secondarily by their file extension 
param:  Files object lhs, Files object rhs
return: bool
*/
inline bool sortSizeByExt(const Files& lhs, const Files& rhs) {
    if (lhs.fileSize == rhs.fileSize)
        return lhs.fileExt > rhs.fileExt;
    else
        return lhs.fileSize > rhs.fileSize; 
}

/*
class:  FileReader
brief:  The FileReader class is responsible for managing the process of scanning directories, analyzing file data, 
        and printing detailed reports. It handles various command-line switches, 
        such as sorting options and regular expression filters, to customize the output according to user preferences. 
        The class uses maps to store file extensions and sizes and provides functions to calculate totals and format the output.
*/
class FileReader {
public:
    FileReader() = default;
    FileReader(path f) : filePath(f) {}

    /*
    fn:     switchCheck
    brief:  This function iterates through the command-line arguments (args) to check for specific flags (-h, -r, -s, -sr, -x) 
            and updates the switches struct accordingly to indicate which operations or behaviors should be applied.
    param:  Booleans object, vector<string>, vector<string>::iterator
    return: bool 
    */
    bool switchCheck(Booleans& switches, std::vector<std::string> args, std::vector<std::string>::iterator it) {

        it = std::find_if(args.begin(), args.end(), [](const std::string& arg) { return arg == "-h" || arg == "--help"; });
        if (it != args.end())
            return switches.help = true;

        it = std::find(args.begin(), args.end(), "-r");
        if (it != args.end())
            return switches.reverse = true;


        it = std::find(args.begin(), args.end(), "-s");
        if (it != args.end())
            return switches.sortSize = true;


        it = std::find(args.begin(), args.end(), "-sr");
        if (it != args.end())
            return switches.sortSizeByExt = true;

        it = std::find(args.begin(), args.end(), "-x");
        if (it != args.end())
            return switches.regex = true;

    }

    /*
    fn:     programHeader
    brief:  This function displays the program's header, including its name and version information.
    param:  nothing
    return: void
    */
    void programHeader() {
        std::cout << "fileusage {v4.0.0} (c) 2016-24, Leen Aboukhalil\n\n";
    }

    /*
    fn:     printHelp
    brief:  To display the help message that guides users on how to use the program and the available command-line switches.
    param:  nothing
    return: void
    */
    void printHelp() {
        std::cout << "        Usage: fileusage [--help] [-hrs(x regularexpression)] [folder]" << std::endl;
        std::cout << "        switches:" << std::endl;
        std::cout << "                h       help" << std::endl;
        std::cout << "                r       reverse the order of the listing" << std::endl;
        std::cout << "                s       sort by file sizes" << std::endl;
        std::cout << "                x       filter with a regular expression\n" << std::endl;
        std::cout << "        folder" << std::endl;
        std::cout << "                starting folder or current folder if not provided" << std::endl;
        exit(0);
    }

    /*
    fn:     printReport
    brief:  This function generates and displays a report of the files analyzed, showing their extensions, counts, and total sizes.
    param:  Booleans object
    return: void
    */
    void printReport(const Booleans& switches) {

        std::cout << std::right << std::setw(20) << "Ext"
            << std::right << std::setw(10) << "#"
            << std::right << std::setw(15) << "Total" << std::endl; 
        std::cout << std::endl; 

        std::vector<Files> filesVec;

        for (const auto& entry : extMap) {
            filesVec.emplace_back(entry.first, extSizeMap[entry.first]);
        }

        if (switches.sortSize) {
            std::sort(filesVec.begin(), filesVec.end(), sortSize);
        }
        else if (switches.reverse) {
            std::sort(filesVec.begin(), filesVec.end(), sortReverse);
        }
        else if (switches.sortSizeByExt) {
            std::sort(filesVec.begin(), filesVec.end(), sortSizeByExt);
        }

        for (const auto& file : filesVec) {
            std::cout << std::right << std::setw(20) << file.fileExt;         
            std::cout << std::right << std::setw(10) << extMap[file.fileExt];      
            std::cout << std::right << std::setw(15) << file.fileSize;            
            std::cout << std::endl;
        }

        std::cout << std::endl;
        std::cout << std::right << std::setw(20) << extMap.size();
        std::cout << std::right << std::setw(10) << extensionSum();
        std::cout << std::right << std::setw(15) << totalSize();
        std::cout << std::endl;
    }

    /*
    fn:     scan    
    brief:  To recursively traverse a given directory and gather information about the files it contains, such as their extensions and sizes.
    param:  Booleans object, path object, regex object 
    return: void
    */
    void scan(Booleans& switches, path const& filePath, std::regex regexFilter) {
        directory_iterator dir(filePath);
        directory_iterator end;
        std::string fileExtension;
        unsigned int fileSize;

        std::cout.imbue(std::locale(""));

        while (dir != end) {
            if (is_directory(dir->path())) {                        //check if the current entry is a directory
                scan(switches, dir->path(), regexFilter);           //recursively scan the subdirectory 
            }
            else {
                //process the file if it is not a directory
                fileExtension = dir->path().extension().string();   //get file extension
                fileSize = file_size(dir->path());                  //get the file size

                if (switches.regex) {                               //if the user wrote a spicified extension file like .txt, check if the file extension matches
                    if (std::regex_search(fileExtension, regexFilter)) {
                        extMap[fileExtension]++;
                        extSizeMap[fileExtension] += fileSize;
                    }
                }

                //update maps for file extension and size if regex is not used
                if (!switches.regex) {
                    extMap[fileExtension]++;
                    extSizeMap[fileExtension] += fileSize;
                }
            }
            ++dir;  //move to the next entry 
        }
    }

private:
    path filePath;
    std::map<std::string, unsigned int> extMap;
    std::map<std::string, unsigned int> extSizeMap;
    unsigned int extSum{ 0 };
    unsigned int sizeSum{ 0 };

    /*
    fn:     extensionSum
    brief:  To calculate the total number of file extensions encountered during the directory scan.
    param:  nothing 
    return: unsigned int
    */
    unsigned int extensionSum() {
        extSum = 0;
        for (const auto& total : extMap) {
            extSum += total.second;
        }
        return extSum;
    }

    /*
    fn:     totalSize
    brief:  To calculate the total size of all files encountered during the directory scan.
    param:  nothing 
    return: unsigned int
    */
    unsigned int totalSize() {
        sizeSum = 0;
        for (const auto& total : extSizeMap) {
            sizeSum += total.second;
        }
        return sizeSum;
    }
};