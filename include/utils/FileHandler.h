//
// Created by peau_c on 2/6/17.
//

#ifndef NANOTEKSPICE_FILEHANDLER_H
#define NANOTEKSPICE_FILEHANDLER_H

#include <string>
#include <fstream>

namespace nts {
	namespace Utils {
		class FileHandler {
		public:
			FileHandler(std::string const file);
			FileHandler();
			~FileHandler();
			std::string trim(const std::string str);
			std::string getValidLine();
			std::string epur(std::string);
			bool isLineValid(std::string line);
			void OpenFile();
			void setFileName(std::string name);
		private:
			std::string _fileName;
			std::ifstream _openedFile;
		};
	}
}

#endif //NANOTEKSPICE_FILEHANDLER_H
