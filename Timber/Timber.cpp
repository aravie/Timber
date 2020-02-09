#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the texture to the sprite
	spriteBackground.setPosition(0, 0);

	// Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	// Is the bee currently moving
	bool beeActive = false;
	// How fast can the bee fly
	float beeSpeed = 0.0f;

	// make 3 cloud sprites from 1 texture
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	// Variables to control time itself
	Clock clock;

	while (window.isOpen())
	{
		// Handle Players input
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		// Update the scene

		// Measure time
		Time dt = clock.restart();

		if (!beeActive)
		{
			// How fast is the bee
			srand((int)time(0) * 10);
			beeSpeed = (rand() % 200) + 200;

			// How high is the bee
			srand((int)time(0) * 10);
			float height = (rand() % 500) + 500;
			spriteBee.setPosition(2000, height);
			beeActive = true;
		}
		else
			// Move the bee
		{
			spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), 
				spriteBee.getPosition().y);
			
			// Has the bee reached the right hand edge of the screen?
			if (spriteBee.getPosition().x < -100)
			{
				// Set it up ready to be a whole new cloud next frame
				beeActive = false;
			}
		}

		// Draw the scene
		// Clear everything from the last frame
		window.clear();

		// Draw our game scene
		window.draw(spriteBackground);

		// Draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		// Draw the tree
		window.draw(spriteTree);

		//Draw the insect
		window.draw(spriteBee);

		// Show everything we just drew
		window.display();
	}
	return 0;
}