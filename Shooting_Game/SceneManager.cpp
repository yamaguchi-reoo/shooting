#include "SceneManager.h"

AbstractScene* SceneManager::Update() {
	AbstractScene* p = mScene->Update();

	if (p != mScene) {
		delete mScene;
		mScene = p; // ���ɕ\���������V�[��
	};

	return p;
};

void SceneManager::Draw() const {
	mScene->Draw();
};
