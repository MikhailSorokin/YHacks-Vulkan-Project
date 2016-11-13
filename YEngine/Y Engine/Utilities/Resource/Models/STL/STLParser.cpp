#include <iostream>
#include <fstream>
#include <sstream>

#include "STLParser.h"
#include "../../../../Components/Simulation/Mesh/Mesh.h"

Mesh* parseSTL(std::string filePath) {

	Mesh* mesh = new Mesh();

	std::ifstream fileStream(filePath.c_str());

	if(fileStream.is_open()) {

		std::string line;

		while (getline(fileStream, line)) {
			
		}
	}

	return mesh;
}
