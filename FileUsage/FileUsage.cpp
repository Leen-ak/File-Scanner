/*
author: Leen Aboukkhail
Data: 12 April 2024
Purpose: The program is a command-line file utility that scans directories to analyze and report on file types and sizes, 
        supporting sorting and filtering options via flags. Users can sort files by size, extension, or in reverse order, 
        and apply regular expression filters to target specific file types. The tool provides formatted output detailing 
        file extensions, counts, and total sizes, with options for recursive directory traversal and detailed help instructions.
*/

#include "ScanDrive.hpp"

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv + 1, argc + argv);
    std::vector<std::string>::iterator it;

    //set teh default folder path to the current working directory 
    path folder = current_path();
    path currentPath = ".";
    FileReader readFolder;
    Booleans switches;
    std::regex regexFilter; 

    for (int i = 0; i < argc; ++i) {                        //populate teh args vector with commaind-line arguments 
        args.push_back(argv[i]);
    }

    readFolder.switchCheck(switches, args, it);             //check the command line arguments for flags and update the switches status 

    if (switches.help) {                                    //if help flag is set, display the program header, and help info
        readFolder.programHeader();
        readFolder.printHelp();
    }

    if(switches.regex)                                      //if regex flas is set, set the regex filter to the last argument
        regexFilter = *(args.end() - 1); 

    //find the first directory in the arguments line
    auto dir_it = std::find_if(args.begin(), args.end(), [](const std::string& path) {return is_directory(path);});
    if (dir_it != args.end()) {                               //if a directory is found, scan that directory and print the report 
        readFolder.scan(switches, *dir_it, regexFilter);
        readFolder.printReport(switches);
    }
    else {
        readFolder.scan(switches, currentPath, regexFilter); //otherwise, scan the current directory and print the report 
        readFolder.printReport(switches);
    }
}
