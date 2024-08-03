# File-Usage

fileUsage is a versatile command-line tool designed to scan directories, analyze file types and sizes, 
and provide detailed reports. It supports various sorting and filtering options, including sorting by size, 
extension, reverse order, and filtering with regular expressions. This tool is ideal for managing and 
understanding storage patterns, making it easier to analyze file distributions within a given directory.

**Features**
1- **Directory Scanning:** Recursively scan directories to gather information about files.
2- **Sorting Options:** Sort files by size, extension, or in reverse order.
3- **Regular Expression** Filtering: Filter files using custom regular expressions.
4- **Detailed Reporting:** Generate reports with file extensions, counts, and total sizes.
5- **User-friendly CLI:** Easy-to-use command-line interface with customizable options.
6- **Help and Documentation:** Built-in help command to guide users on available features and usage.

**Installation**
To use fileUsage, you need to have a C++ compiler that supports C++17 or later and the necessary build tools.

**Usage**
**The basic usage of fileUsage is as follows:**
  fileUsage [options] [directory]

**Command-Line Options**
with the executable file name 
![fileUsage](https://github.com/user-attachments/assets/bd732600-b88e-491b-ad19-763672d1a09e)

with the executable file name and the name of the folder 
![fileUsage-file](https://github.com/user-attachments/assets/6a3d1b13-6cd3-4342-8df3-81ae4ba29725)


-h or --help: Display help information and usage instructions.
![help](https://github.com/user-attachments/assets/f137707c-9111-4ae4-be18-75db5c6a7ff2)

-r: Reverse the order of the listing.
![switch-r](https://github.com/user-attachments/assets/8b8063ea-8f23-4e61-bfeb-b1d6d2f89bc5)

-s: Sort files by size in ascending order.
![switch-s](https://github.com/user-attachments/assets/4d923451-e146-407a-815b-d06a5e13eb43)

-sr: Sort files primarily by size and secondarily by extension.
![switch-sr](https://github.com/user-attachments/assets/aa874acf-6dc0-405c-aa86-1d3d12e9e171)

-x [regex]: Filter files using a specified regular expression.
![switch-x](https://github.com/user-attachments/assets/e6fad4c3-63d4-4b42-8241-dba07cf012d1)

A test summary to see if I did all the requirements 
![pass](https://github.com/user-attachments/assets/321d668c-5760-469b-b954-871db8c6c193)

**Project Structure**
1- main.cpp: The entry point of the application, handling argument parsing and initiating directory scans.
2- ScanDrive.hpp: Header file containing class declarations and function prototypes.
3- FileReader Class: Responsible for scanning directories, analyzing file data, and printing detailed reports.
4- Files Class: Represents individual files, storing their extension and size for sorting and reporting.
5- Booleans Struct: Holds flags representing various command-line options for easy access throughout the program

**Author** 
Leen Aboukhalil 



