#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "PLYParser.h"
#include "../../../../Components/Simulation/Mesh/Mesh.h"

int stringToInt(std::string text) {

	int num = 0;

	std::stringstream convert(text);
	convert >> num;

	return num;
}

int stringToFloat(std::string text) {

	float num = 0;

	std::stringstream convert(text);
	convert >> num;

	return num;
}

Mesh* parsePLY(std::string filePath) {

	Mesh* mesh = new Mesh();

	std::ifstream fileStream(filePath.c_str());

	if(fileStream.is_open()) {

		std::string line;

		int numVertices = 0;
		bool inHeader = true;

		int vertexCount = 0;

		while (getline(fileStream, line)) {

			if(line.length() > 15) {

				if(line.substr(0, 14).compare("element vertex") == 0) {
					numVertices = stringToInt(line.substr(15));
				}
			}

			if(inHeader) {

				if(line.compare("end_header") == 0)
					inHeader = false;
			}

			else {

				if(vertexCount < numVertices) {

					float x = stringToFloat(line.substr(0, line.find(' ')));
					line = line.substr(line.find(' ') + 1);

					float y = stringToFloat(line.substr(0, line.find(' ')));
					line = line.substr(line.find(' ') + 1);

					float z = stringToFloat(line);

					std::cout << y << std::endl;

					vertexCount++;
				}
			}
		}
	}

	return mesh;
}
