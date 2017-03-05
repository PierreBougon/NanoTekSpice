//
// Created by peau_c on 2/6/17.
//

#include <algorithm>
#include "utils/Logger.h"
#include "utils/FileHandler.h"

void nts::Utils::FileHandler::OpenFile() {
	if (_fileName.empty()) {
		Logger::log(Logger::Error, "The file name wasn't set before using OpenFile()\n", true);
	}
	_openedFile.open(_fileName, std::ios::in);
	if (!_openedFile.is_open()) {
		Logger::log(Logger::Error, "The file cannot be opened, check its name\n", true);
	}
}

nts::Utils::FileHandler::FileHandler(const std::string &file) {
	setFileName(file);
}

nts::Utils::FileHandler::~FileHandler() {
	if (_openedFile.is_open())
		_openedFile.close();
}

std::string nts::Utils::FileHandler::trim(const std::string str) {
	size_t first = str.find_first_not_of(' ');

	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(' ');

	return (str.substr(first, (last - first + 1)));
}

std::string nts::Utils::FileHandler::epur(std::string line) {
	std::string cleanedLine = line;

	std::replace(cleanedLine.begin(), cleanedLine.end(), '\t', ' ');
	std::string::iterator new_end = std::unique(cleanedLine.begin(), cleanedLine.end(),
	                                            [=](char lhs, char rhs){return (lhs == rhs) && (lhs == ' ');}
												);
	cleanedLine.erase(new_end, cleanedLine.end());
	cleanedLine = trim(line);

	return (cleanedLine);
}

bool nts::Utils::FileHandler::isLineValid(std::string line) {
	if (line.empty() || line.at(0) == '#')
		return (false);
	return (true);
}

std::string nts::Utils::FileHandler::getValidLine() {
	std::string line;

	if (!_openedFile.good())
		return ("");
	if (getline(_openedFile, line))
	line = epur(line);
	if (!isLineValid(line))
		line = getValidLine();
	return (line);
}

void nts::Utils::FileHandler::setFileName(std::string name) {
	_fileName = name;
	OpenFile();
}
nts::Utils::FileHandler::FileHandler() {}
