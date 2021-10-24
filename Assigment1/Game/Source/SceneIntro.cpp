#include "SceneIntro.h"
#include "App.h"
#include "Textures.h"
#include "Render.h"
#include "Audio.h"
#include "Input.h"
#include "Window.h"
//#include "Module.h"
//#include "ModuleFadeToBlack.h"
#include "Player.h"
#include "SDL/include/SDL_scancode.h"
#include "Scene.h"
#include "ModuleFadeToBlack.h"
#include "Defs.h"
#include "Log.h"

SceneIntro::SceneIntro(/*bool startEnabled*/) :Module(/*startEnabled*/)
{


}

SceneIntro::~SceneIntro() {

}

bool SceneIntro::Start() {
	LOG("Loading backgroud assets :)");

	bool ret = true;
    
	bgTexture = app->tex->Load("Assets/textures/Menu.png");

	//app->audio->PlayMusic("assets/sound/music/intro.ogg", 1.0f);

	app->render->camera.x = 0;
	app->render->camera.y = 0;

	return ret;
}

bool SceneIntro::Update(float dt) {	// plays Game logo + animation
	bool ret = true;
	intro.Update();
	/*if (intro.HasFinished())
	{
		app->fade->FadeToBlack(this, (Module*)app->titleScreen, 60);
	}*/

	 if ((app->input->GetKey(SDL_SCANCODE_P) == KEY_REPEAT))
	{
		app->fade->FadeToBlack(this, (Module*)app->scene, 60);

	}
	
	return ret;
}

//DRAW BACKGROUD

bool SceneIntro::PostUpdate() {
	bool ret = true;
	app->render->DrawTexture(bgTexture, 0 /*/ 2 - 115*/, 0 /*/ 2 - 115*/); // intro
	return ret;
}