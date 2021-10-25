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

SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled)
{
	PressEnter.PushBack({ 0,0,85,26 });
	PressEnter.PushBack({ 0,0,1,1 });
	PressEnter.loop = true;
	PressEnter.speed = 0.1f;

}

SceneIntro::~SceneIntro() {

}

bool SceneIntro::Start() {
	LOG("Loading backgroud assets :)");

	bool ret = true;
    
	bgTexture = app->tex->Load("Assets/textures/Menu.png");
	PressEnterTex = app->tex->Load("Assets/textures/PressEnter.png");

	//app->audio->PlayMusic("assets/sound/music/intro.ogg", 1.0f);

	app->render->camera.x = 0;
	app->render->camera.y = 0;

	return ret;
}

bool SceneIntro::Update(float dt) {	// plays Game logo + animation
	bool ret = true;

	PressEnter.Update();
	intro.Update();



	/*if (intro.HasFinished())
	{
		app->fade->FadeToBlack(this, (Module*)app->titleScreen, 60);
	}*/
	


	 if (app->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		 /*CleanUp();*/
		app->fade->FadeToBlack((Module*)app->intro, (Module*)app->scene, 90);


	 }
	
	return ret;
}

//DRAW BACKGROUND

bool SceneIntro::PostUpdate() {
	bool ret = true;


	app->render->DrawTexture(PressEnterTex, 80 , 140, NULL);


	app->render->DrawTexture(bgTexture, 0, 0); // intro


	return ret;
}

bool SceneIntro::CleanUp()
{
	LOG("Cleaning SCENE 1");
	app->tex->UnLoad(bgTexture);
	//app->audio->Enable();
	//app->intro->Disable();
	return true;
}