#include<vector>
#include<stdint.h>
class MapChipField {
	static inline const float KBlockWidth = 1.0f;
	static inline const float KBlockHigft = 1.0f;
	static inline const uint32_t KNumBlockVirtical = 20;
	static inline const uint32_t KNumBlockHorizontal = 100;

	MapChipData mapChipData_;

	void ResetMapchipData();
	void LoadMapChipCsv(const std::string& filePath);

	MapChipType GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex);
};
enum class MapChipType {
	kBlank,
	kBlock,
};
struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};
