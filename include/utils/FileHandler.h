//
// Created by peau_c on 2/6/17.
//

#ifndef NANOTEKSPICE_FILEHANDLER_H
#define NANOTEKSPICE_FILEHANDLER_H

#include <string>
#include <fstream>

class FileHandler {
	FileHandler(std::string const file);
	~FileHandler();

	std::string trim(const std::string str);
	std::string getValidLine();
	std::string epur(std::string);
	bool bothAreSpace(char lhs, char rhs);
	bool isLineValid(std::string line);

private:
	std::ifstream   _openedFile;
};

#endif //NANOTEKSPICE_FILEHANDLER_H