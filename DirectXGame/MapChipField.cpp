#include <map>
#include<string>
#include "MapChipfield.h"
#include<fstream>
#include<sstream>
#include<assert.h>

namespace {

	std::map<std::string, MapChipType> mapChipTable = {
		{"0", MapChipType::kBlank},
		{"1", MapChipType::kBlock},
	};
}

uint32_t MapChipField::GetNumBlockVirtical() { return KNumBlockVirtical; }

uint32_t MapChipField::GetNumBlockHorizontal() { return KNumBlockHorizontal; }


void MapChipField::ResetMapchipData() {

	mapChipData_.data.clear();

	mapChipData_.data.resize(KNumBlockVirtical);

	for (std::vector<MapChipType>& mapChipDataLine : mapChipData_.data) {
		mapChipDataLine.resize(KNumBlockHorizontal);
	}
}

void MapChipField::LoadMapChipCsv(const std::string& filePath) {

	ResetMapchipData();
	
	std::ifstream file;
	file.open(filePath);

	assert(file.is_open());

	std::stringstream mapChipCsv;

	mapChipCsv << file.rdbuf();

	file.close();

	for (uint32_t i = 0; i < KNumBlockVirtical; ++i) {

		std::string line;
		getline(mapChipCsv, line);

		std::istringstream line_stream(line);

		for (uint32_t j = 0; j < KNumBlockHorizontal; ++j) {
		
		
			std::string word;
			getline(line_stream, word, ',');

			if (mapChipTable.contains(word)) {

				mapChipData_.data[i][j] = mapChipTable[word];

			}

		}
	}


}

MapChipType MapChipField::GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex) {
	
	if (xIndex < 0 || KNumBlockHorizontal - 1 < xIndex) {

		return MapChipType::kBlank;
	}
	if (yIndex < 0 || KNumBlockVirtical - 1 < yIndex) {
	
		return MapChipType::kBlank;
	
	}

	
	
	return mapChipData_.data[yIndex][xIndex];
}

Vector3 MapChipField::GetMapChipPositionByIndex(uint32_t xIndex, uint32_t yIndex) { 
	
	return Vector3(KBlockWidth * xIndex,KBlockHight * (KNumBlockVirtical-1-yIndex),0); 

}

