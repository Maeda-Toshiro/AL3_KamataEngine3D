#include "Model.h"
#include "WorldTransform.h"

class skydome {
public:
	void Intialize();

	void Update();

	void Draw();

private:
	WorldTransform worldTransform_;
	ViewProjection* viewProjection_ = nullptr;
	Model* model_ = nullptr;
};