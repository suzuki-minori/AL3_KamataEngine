#pragma once

#include "Model.h"
#include "WorldTransform.h"
#include"ViewProjection.h"

class Player {
public:
	
	//������
	void Initialize(Model* model, uint32_t textureHandles, ViewProjection* viewProjection);
	
	//�X�V
	void Update();

	//�`��
	void Draw();

private:

	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;

	//���f��

	Model* model_ = nullptr;
	
	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
	
	//�r���[�v���W�F�N�V����
	ViewProjection* viewProjection_ = nullptr;

};