#ifndef __SCENE_LOGO_H__
#define __SCENE_LOGO_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;
class SceneLogo : public Module {
	public:
		SceneLogo(bool startEnabled);

		~SceneLogo();

		bool Start() override;

		//updates the scene's background animations
		bool Update(float dt) override;

		//forms the render call of all the parts of the scene's backgroud
		bool PostUpdate() override;

		bool CleanUp();

public:

	//sprite loaded into an SDL_Texture
	SDL_Texture* logotx = nullptr;
	SDL_Texture* bgTexture1 = nullptr;
	//The intro animation 
	Animation intro;
	Animation logo;
};

#endif