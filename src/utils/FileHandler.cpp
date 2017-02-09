//
// Created by peau_c on 2/6/17.
//

#include <algorithm>
#include "utils/Logger.h"
#include "utils/FileHandler.h"

FileHandler::FileHandler(const std::string file) {
	_openedFile.open(file);

	if (_openedFile.bad()) {
		Logger::log(Logger::Error, "The file cannot be opened, check its name", true);
	}
}

FileHandler::~FileHandler() {
	if (_openedFile.is_open())
		_openedFile.close();
}

bool FileHandler::bothAreSpace(char lhs, char rhs) {
	return (lhs == rhs) && (lhs == ' ');
}

std::string FileHandler::trim(const std::string str) {
	size_t first = str.find_first_not_of(' ');

	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(' ');

	return (str.substr(first, (last - first + 1)));
}

std::string FileHandler::epur(std::string line) {
	std::string cleanedLine = line;

	std::replace(cleanedLine.begin(), cleanedLine.end(), '\t', ' ');
	std::string::iterator new_end = std::unique(cleanedLine.begin(), cleanedLine.end(), bothAreSpace);
	cleanedLine.erase(new_end, cleanedLine.end());
	cleanedLine = trim(line);

	return (cleanedLine);
}

bool FileHandler::isLineValid(std::string line) {
	if (line.empty())
		return (false);
	return (true);
}

std::string FileHandler::getValidLine() {
	std::string line;

	getline(_openedFile, line);

	return (line);
}

