#include "Player.h"
#include <cassert>
#include<numbers>
void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection, const Vector3& position) {
	// NULLチェック
	assert(model);
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
	// 引数の内容をメンバ変数に記録
	model_ = model;
	textureHandle_ = textureHandle;
	viewProjection_ = viewProjection;
}

void Player::Update() {

//行列を定数バッファに転送
	worldTransform_.TransferMatrix();

}
void Player::Draw() {

	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);

}