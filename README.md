# File-Scanner
File-Scanner is a versatile command-line tool designed to scan directories, analyze file types and sizes, and provide detailed reports. It supports various sorting and filtering options, including sorting by size, extension, reverse order, and filtering with regular expressions. This tool is ideal for managing and understanding storage patterns, making it easier to analyze file distributions within a given directory.

## Features
1. Directory Scanning: Recursively scan directories to gather information about files.
2. Sorting Options: Sort files by size, extension, or in reverse order.
3. Regular Expression Filtering: Filter files using custom regular expressions.
4. Detailed Reporting: Generate reports with file extensions, counts, and total sizes.
5. User-friendly CLI: Easy-to-use command-line interface with customizable options.
6. Help and Documentation: Built-in help command to guide users on available features and usage.

## Installation
To use File-Scanner, you need to have a C++ compiler that supports C++17 or later and the necessary build tools.

## Usage
- The basic usage of fileUsage is as follows:
fileUsage [options] [directory]

**Command-Line Options**
- -h or --help: Display help information and usage instructions.
![help](https://github.com/user-attachments/assets/d83eb0d2-7e15-428b-ad15-4bb15a02e449)


- -r: Reverse the order of the listing.
![switch-r](https://github.com/user-attachments/assets/64103d8c-bf15-41b9-a415-8ee0d69c8a38)

- -s: Sort files by size in ascending order.
![switch-s](https://github.com/user-attachments/assets/55af7d8c-a729-4384-bbf8-7a7cb691de3e)

- -sr: Sort files primarily by size and secondarily by extension.
![switch-sr](https://github.com/user-attachments/assets/52a0e823-d5ad-4977-bb0b-9562d435d1a7)

- -x [regex]: Filter files using a specified regular expression.
![switch-x](https://github.com/user-attachments/assets/d8a6fc74-5042-436c-99b0-349b56880278)

- using just the executable file
![fileUsage](https://github.com/user-attachments/assets/af037039-d3ba-433a-bc53-ac3c3e034f37)

- using the executable file with a specific folder
![fileUsage-folder](https://github.com/user-attachments/assets/3cd1087f-3af3-420a-ae5a-136119dcd676)

- futest is a test summary tells you if you did all the school project requirements 
![pass](https://github.com/user-attachments/assets/5d5c2d18-eb21-4b4c-943b-1481e60f7b58)


## Project Structure
- main.cpp: The entry point of the application, handling argument parsing and initiating directory scans.
-  ScanDrive.hpp: Header file containing class declarations and function prototypes.
- FileReader Class: Responsible for scanning directories, analyzing file data, and printing detailed reports.
- Files Class: Represents individual files, storing their extension and size for sorting and reporting.
- Booleans Struct: Holds flags representing various command-line options for easy access throughout the program.

## Conclusion
This README file provides a comprehensive overview of your fileUsage project, including its features, installation instructions, usage examples,

## Author 
Leen Aboukhalil


