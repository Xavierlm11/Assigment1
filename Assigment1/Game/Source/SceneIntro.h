#ifndef __SCENE_INTRO_H__
#define __SCENE_INTRO_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;
class SceneIntro : public Module {
	public:
		SceneIntro(/*bool startEnabled*/);

		~SceneIntro();

		bool Start() override;

		//updates the scene's background animations
		bool Update(float dt) override;

		//forms the render call of all the parts of the scene's backgroud
		bool PostUpdate() override;

public:

	//sprite loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* bgTexture1 = nullptr;
	SDL_Texture* PressEnterTex = nullptr;
	//The intro animation 
	Animation intro;
	Animation logo;
	Animation PressEnter;
};

#endif