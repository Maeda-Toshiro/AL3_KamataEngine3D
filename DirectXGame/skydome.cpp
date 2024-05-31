#include "skydome.h"

void skydome::Intialize() {}

void skydome::Update() {}

void skydome::Draw() {
	
	model_->Draw(worldTransform_, viewProjection_);
	
}
