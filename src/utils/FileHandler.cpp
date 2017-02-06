//
// Created by peau_c on 2/6/17.
//

#include "Logger.h"
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

std::string FileHandler::epur(std::string line) {
	std::string cleanedLine;

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

