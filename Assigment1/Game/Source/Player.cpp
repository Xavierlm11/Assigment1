#include "App.h"
#include "Render.h"
#include "Textures.h"
#include "Input.h"
#include "Player.h"
#include "Animation.h"
#include <stdio.h>
#include <stdlib.h>

#include "Defs.h"
#include "Log.h"

#include "SDL/include/SDL_scancode.h"

#include "SDL_image/include/SDL_image.h"
//#pragma comment(lib, "../Game/Source/External/SDL_image/libx86/SDL2_image.lib")

Player::Player() : Module()
{
	name.Create("player");

	idleAnimR.PushBack({8,11,21,19});
	idleAnimR.loop = false;
	idleAnimR.speed = 0.1f;

	walkAnimR.PushBack({ 254,11,20,18 });
	walkAnimR.PushBack({ 276,10,20,18 });
	walkAnimR.PushBack({ 299,11,20,18 });
	walkAnimR.PushBack({ 321,11,20,18 });
	walkAnimR.PushBack({ 342,11,20,18 });
	walkAnimR.PushBack({ 361,11,20,18 });
	walkAnimR.loop = true;
	walkAnimR.speed = 0.1f;

	walkAnimL.PushBack({ 254,11,20,18 });
	walkAnimL.PushBack({ 276,10,20,18 });
	walkAnimL.PushBack({ 299,11,20,18 });
	walkAnimL.PushBack({ 321,11,20,18 });
	walkAnimL.PushBack({ 342,11,20,18 });
	walkAnimL.PushBack({ 361,11,20,18 });
	walkAnimL.loop = true;
	walkAnimL.speed = 0.1f;



}

// Destructor
Player::~Player()
{}

// Called before render is available
bool Player::Awake(pugi::xml_node& config)
{
	LOG("Init Image library");
	bool ret = true;
	
	// Load support for the PNG image format
	
	int flags = IMG_INIT_PNG;
	int init = IMG_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("Could not initialize Image lib. IMG_Init: %s", IMG_GetError());
		ret = false;
	}

	return ret;
}

// Called before the first frame
bool Player::Start()
{
	texture = app->tex->Load("Assets/textures/PlayerKirby.png");
	LOG("start Player");
	bool ret = true;
	currentAnimation = &idleAnimR;
	app->player->position.x = 50;
	app->player->position.y = 20;

	return ret;
}

bool Player::PreUpdate()
{
	return true;
}

bool Player::Update(float dt) {
	bool ret = true;
	//right
	int speed = 2;
	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		position.x += speed;
		if (currentAnimation != &walkAnimR)
		{
			walkAnimR.Reset();
			currentAnimation = &walkAnimR;
			/*Player_Position = true;*/
		}
	}

	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE && currentAnimation != &walkAnimR) {
		currentAnimation = &idleAnimR;
	}

	currentAnimation->Update();
	return ret;
}

bool Player::PostUpdate()
{
	bool ret = true;
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	app->render->DrawTexture(texture, position.x - 10, position.y + 20, &rect);//draw player

	return ret;
}

// Called before quitting
bool Player::CleanUp()
{
	LOG("Freeing textures and Image library");
	ListItem<SDL_Texture*>* item;

	for (item = player.start; item != NULL; item = item->next)
	{
		SDL_DestroyTexture(item->data);
	}

	player.clear();
	IMG_Quit();
	return true;
}


