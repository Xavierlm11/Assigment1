#include "SceneLogo.h"
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

SceneLogo::SceneLogo(bool startEnabled) : Module(startEnabled)
{


}

SceneLogo::~SceneLogo() {

}

bool SceneLogo::Start() {
	LOG("Loading backgroud assetsaaaaaaaaaaaaaaaaaaaaaa");

	bool ret = true;
    
	logotx = app->tex->Load("Assets/textures/LogoIntro.png");

	//app->audio->PlayMusic("assets/sound/music/intro.ogg", 1.0f);

	app->render->camera.x = 0;
	app->render->camera.y = 0;
	app->player->Disable();
	app->scene->Disable();
	//app->audio->Disable();

	app->tex->UnLoad(app->intro->bgTexture);

	return ret;
}

bool SceneLogo::Update(float dt) {	// plays Game logo + animation
	bool ret = true;

     app->render->DrawTexture(logotx, 0 /*/ 2 - 115*/, 0 /*/ 2 - 115*/); // intro
	//intro.Update();
	/*if (intro.HasFinished())
	{
		app->fade->FadeToBlack(this, (Module*)app->titleScreen, 60);
	}*/

	 if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		 app->tex->UnLoad(logotx);
		 //app->tex->(app->intro->bgTexture);
		CleanUp();
		app->fade->FadeToBlack((Module*)app->logo, (Module*)app->intro, 60);
		
	}
	
	return ret;
}

//DRAW BACKGROUD

bool SceneLogo::PostUpdate() {
	bool ret = true;
	
	return ret;
}

bool SceneLogo::CleanUp()
{
	LOG("Cleaning SCENE 1");
	app->tex->UnLoad(logotx);
	//app->audio->Enable();
	//app->intro->Disable();
	return true;
}