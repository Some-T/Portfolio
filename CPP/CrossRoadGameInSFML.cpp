//Cross Road - By Jamie Cropley
//Only the main source code file has been supplied, ran out of time to re organise this code using OOP methods.
//Will need SFML 2.2 library to compile in Visual Studio 2013, additionally any assets will need to be recreated.
//This was created for a University Project.


#include <SFML/Graphics.hpp>
#include <string>

//SFML Events:
sf::Sprite spriteTopMud;
sf::Sprite spritePavement;
sf::Sprite spritePavement2;
sf::Sprite spritePlayer;
sf::Sprite spriteRoad;
sf::Sprite spriteWater;
sf::Texture textureTopMud;
sf::Texture texturePavement;
sf::Texture texturePlayer;
sf::Texture textureRoad;
sf::Texture textureWater;
sf::Sprite spriteCroc[2];
sf::Texture textureCroc[2];
sf::Sprite spriteSnake[3];
sf::Texture textureSnake[3];
sf::Sprite spriteCars[3];
sf::Texture textureCars[3];
sf::RectangleShape progressBarBackground;
sf::RectangleShape progressBar;
sf::Clock clockTimer;
sf::Clock clockGame;
sf::Font fontGlobal;
sf::Text textScore("Score: ", fontGlobal, 14);
sf::Text textTimer("Time: ", fontGlobal, 14);
sf::Text textHighScore("High Score: ", fontGlobal, 14);
sf::Text textLives("Lives Left: ", fontGlobal, 14);
sf::RenderWindow window(sf::VideoMode(800, 600), "Cross Road - By Jamie Cropley", sf::Style::Close);
sf::RectangleShape doors[6];

//Global Variables:
float fCarMovementAmount[3];
float fSnakeMovementAmount[3];
float fCrocMovementAmount[2];
float fPlayerMovementAmount = 18.0f;
int iScore = 0;
int iHighScore = 0;
int iLives = 6;
int iMaximumTime = 30; // The maximum time of the timer which is 30 seconds.

//Main function of the game:
int main()
{
	//The below for loop sets initial aspects of the black squares at the top of the screen underneath topmud.png
	for (int i = 0; i < 6; i++)
	{
		doors[i].setPosition(sf::Vector2f(48 + (i * 64) + (i * 64), 17 + 32));
		doors[i].setSize(sf::Vector2f(64, 64));
		doors[i].setFillColor(sf::Color::Black);
	}
	//The below sets the values for each element in the array as per there variables therein:
	fCarMovementAmount[0] = 0.00022f;
	fCarMovementAmount[1] = 0.00032f;
	fCarMovementAmount[2] = 0.00038f;

	fSnakeMovementAmount[0] = 0.00032f;
	fSnakeMovementAmount[1] = 0.00012f;
	fSnakeMovementAmount[2] = 0.00036f;

	fCrocMovementAmount[0] = 0.00018f;
	fCrocMovementAmount[1] = 0.00026f;


	//The below loads textures from various files:
	textureTopMud.loadFromFile("assets/img/topmud.png");
	texturePavement.loadFromFile("assets/img/pavement.png");
	texturePlayer.loadFromFile("assets/img/frogstatic.png");
	textureRoad.loadFromFile("assets/img/road.png");
	textureWater.loadFromFile("assets/img/water.png");
	//The below assigns the sprites to the textures:
	spriteTopMud.setTexture(textureTopMud);
	spritePavement.setTexture(texturePavement);
	spritePavement2.setTexture(texturePavement);
	spritePlayer.setTexture(texturePlayer);
	spriteRoad.setTexture(textureRoad);
	spriteWater.setTexture(textureWater);


	//The below does similar to the above but is more specific to the enemies of the game, the below also sets there starting positions:

	//Croc Enemy:
	textureCroc[0].loadFromFile("assets/img/croc.png");
	textureCroc[1].loadFromFile("assets/img/crocrev.png");
	spriteCroc[0].setTexture(textureCroc[0]);
	spriteCroc[1].setTexture(textureCroc[1]);
	spriteCroc[0].setPosition(sf::Vector2f(0, 156));
	spriteCroc[1].setPosition(sf::Vector2f(0, 198));


	//Snake Enemy:
	textureSnake[0].loadFromFile("assets/img/snake.png");
	textureSnake[1].loadFromFile("assets/img/snakerev.png");
	textureSnake[2].loadFromFile("assets/img/snakerev.png");
	spriteSnake[0].setTexture(textureSnake[0]);
	spriteSnake[1].setTexture(textureSnake[1]);
	spriteSnake[2].setTexture(textureSnake[2]);
	spriteSnake[0].setPosition(sf::Vector2f(window.getSize().x, 266));
	spriteSnake[1].setPosition(sf::Vector2f(0, 232));
	spriteSnake[2].setPosition(sf::Vector2f(0, 118));

	//Car Enemy:
	textureCars[0].loadFromFile("assets/img/car1.png");
	textureCars[1].loadFromFile("assets/img/car2.png");
	textureCars[2].loadFromFile("assets/img/car3.png");
	spriteCars[0].setTexture(textureCars[0]);
	spriteCars[1].setTexture(textureCars[1]);
	spriteCars[2].setTexture(textureCars[2]);
	spriteCars[0].setPosition(sf::Vector2f(window.getSize().x, 480));
	spriteCars[1].setPosition(sf::Vector2f(0, 420));
	spriteCars[2].setPosition(sf::Vector2f(0, 360));

	//The below sets the permanent position of a sprite/texture or starting position, some of them are relative to other sprites/textures.
	spriteTopMud.setPosition(sf::Vector2f(0, 32));
	spriteWater.setPosition(sf::Vector2f(0, 116));
	spritePavement.setPosition(sf::Vector2f(0, window.getSize().y - texturePavement.getSize().y - 35));
	spriteRoad.setPosition(sf::Vector2f(0, spritePavement.getPosition().y - textureRoad.getSize().y));
	spritePavement2.setPosition(sf::Vector2f(0, spriteRoad.getPosition().y - texturePavement.getSize().y));
	spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
	spritePlayer.setOrigin(texturePlayer.getSize().x / 2, texturePlayer.getSize().y / 2);


	//The below loads and sets the font settings/aspects globally and for different individual text elements.
	fontGlobal.loadFromFile("assets/fonts/arialbd.ttf");
	textScore.setPosition(sf::Vector2f(2, 2));
	textTimer.setPosition(sf::Vector2f(2, 564));
	textHighScore.setPosition(sf::Vector2f(2, 582));
	textLives.setPosition(sf::Vector2f(650, 2));
	textScore.setColor(sf::Color::Black);
	textTimer.setColor(sf::Color::Black);
	textHighScore.setColor(sf::Color::Black);
	textLives.setColor(sf::Color::Black);


	//The below sets up all the aspects for the progress bar for the games main timer.
	progressBarBackground.setSize(sf::Vector2f(756, 10));
	progressBarBackground.setFillColor(sf::Color::Black);
	progressBarBackground.setPosition(sf::Vector2f(textTimer.getLocalBounds().width, 562 + textTimer.getLocalBounds().height / 2));
	progressBar.setFillColor(sf::Color::Red);
	progressBar.setPosition(sf::Vector2f(textTimer.getLocalBounds().width, 562 + textTimer.getLocalBounds().height / 2));




	/*The below while loops and if statements set various settings,
	some of which are player controls for the keyboard, scoring system,
	boundaries and timer.
	*/
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::Resized)
			{
				sf::View view = sf::View(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

				window.setView(view);

				// The above makes the window and its contents stay the same size if you resize the window, just incase of any problems on different resolutions.

			}
			// Keyboard controls
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{

					if (iScore < 54)
					{
						iScore += 2;
					}

					spritePlayer.move(sf::Vector2f(0, -fPlayerMovementAmount));
					spritePlayer.setRotation(0);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					if (iScore != 0)
					{
						iScore -= 2;
					}

					spritePlayer.move(sf::Vector2f(0, fPlayerMovementAmount));
					spritePlayer.setRotation(180);
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					spritePlayer.move(sf::Vector2f(-fPlayerMovementAmount, 0));
					spritePlayer.setRotation(-90);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					spritePlayer.move(sf::Vector2f(fPlayerMovementAmount, 0));
					spritePlayer.setRotation(90);
				}
			}
		}
		//Boundaries of the edge of the screen:
		if (spritePlayer.getPosition().y + texturePlayer.getSize().y / 2 > spritePavement.getPosition().y + texturePavement.getSize().y)
		{
			spritePlayer.setPosition(sf::Vector2f(spritePlayer.getPosition().x, spritePavement.getPosition().y + texturePlayer.getSize().x));
		}

		if (spritePlayer.getPosition().y < texturePlayer.getSize().y / 2 + 32)
		{
			spritePlayer.setPosition(sf::Vector2f(spritePlayer.getPosition().x, 0 + texturePlayer.getSize().y / 2 + 32));
		}

		if (spritePlayer.getPosition().x - texturePlayer.getSize().x / 2 < 0)
		{
			spritePlayer.setPosition(sf::Vector2f(texturePlayer.getSize().x / 2, spritePlayer.getPosition().y));
		}

		if (spritePlayer.getPosition().x + texturePlayer.getSize().x / 2 > window.getSize().x)
		{
			spritePlayer.setPosition(sf::Vector2f(window.getSize().x - texturePlayer.getSize().x / 2, spritePlayer.getPosition().y));
		}
		
		progressBar.setSize(sf::Vector2f((progressBarBackground.getSize().x / iMaximumTime) * clockTimer.getElapsedTime().asSeconds(), 10));
		//Timer run out then scores reset / similar to a game over type of implementation.
		if (clockTimer.getElapsedTime().asSeconds() > iMaximumTime)
		{
			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}



		}




		//Automatic Enemy Movements below:

		//Cars movement:

		if (spriteCars[0].getPosition().x < 0)
		{
			srand(clockGame.getElapsedTime().asMicroseconds());
			spriteCars[0].setPosition(sf::Vector2f(window.getSize().x, 480));
		}

		if (spriteCars[1].getPosition().x > 800)
		{
			srand(clockGame.getElapsedTime().asMicroseconds());
			spriteCars[1].setPosition(sf::Vector2f(0, 420));
		}

		if (spriteCars[2].getPosition().x > 800)
		{
			srand(clockGame.getElapsedTime().asMicroseconds());
			spriteCars[2].setPosition(sf::Vector2f(0, 360));
		}

		spriteCars[0].move(-(fCarMovementAmount[0] * clockGame.getElapsedTime().asMicroseconds()), 0);
		spriteCars[1].move(fCarMovementAmount[1] * clockGame.getElapsedTime().asMicroseconds(), 0);
		spriteCars[2].move(fCarMovementAmount[2] * clockGame.getElapsedTime().asMicroseconds(), 0);


		//Snakes movement:

		if (spriteSnake[0].getPosition().x < 0)
		{
			srand(clockGame.getElapsedTime().asMicroseconds());
			spriteSnake[0].setPosition(sf::Vector2f(window.getSize().x, 266));
		}

		if (spriteSnake[1].getPosition().x > 800)
		{
			srand(clockGame.getElapsedTime().asMicroseconds());
			spriteSnake[1].setPosition(sf::Vector2f(0, 232));
		}

		if (spriteSnake[2].getPosition().x > 800)
		{
			srand(clockGame.getElapsedTime().asMicroseconds());
			spriteSnake[2].setPosition(sf::Vector2f(0, 118));
		}

		spriteSnake[0].move(-(fSnakeMovementAmount[0] * clockGame.getElapsedTime().asMicroseconds()), 0);
		spriteSnake[1].move(fSnakeMovementAmount[1] * clockGame.getElapsedTime().asMicroseconds(), 0);
		spriteSnake[2].move(fSnakeMovementAmount[2] * clockGame.getElapsedTime().asMicroseconds(), 0);



		//Crocs movement:

		if (spriteCroc[0].getPosition().x < 0)
		{
			srand(clockGame.getElapsedTime().asMicroseconds());
			spriteCroc[0].setPosition(sf::Vector2f(window.getSize().x, 156));
		}

		if (spriteCroc[1].getPosition().x > 800)
		{
			srand(clockGame.getElapsedTime().asMicroseconds());
			spriteCroc[1].setPosition(sf::Vector2f(0, 198));
		}


		spriteCroc[0].move(-(fCrocMovementAmount[0] * clockGame.getElapsedTime().asMicroseconds()), 0);
		spriteCroc[1].move(fCrocMovementAmount[1] * clockGame.getElapsedTime().asMicroseconds(), 0);



		/*The below code initiates the start of the main game clock, additionally it converts various numbers to string elements to be displayed to the player
		where window.draw/etc... method is mentioned this draws various elements to the game, below I also set it so the player could not hold the key's down
		to make the game more challenging.*/

		clockGame.restart();

		textScore.setString("Score: " + std::to_string(iScore));
		textHighScore.setString("High Score: " + std::to_string(iHighScore));
		textLives.setString("Lives Left: " + std::to_string(iLives));

		window.clear(sf::Color::White);

		window.setKeyRepeatEnabled(false);

		window.draw(spriteTopMud);
		window.draw(spritePavement);
		window.draw(spritePavement2);
		window.draw(spriteRoad);
		window.draw(spriteWater);


		//The majority of the code below handles the enemy collisions with the player by using if statements, as well as drawing such enemies to the game window inbetween.

		//Croc collisions:

		if (spritePlayer.getGlobalBounds().intersects(spriteCroc[0].getGlobalBounds()))
		{

			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}
		}

		if (spritePlayer.getGlobalBounds().intersects(spriteCroc[1].getGlobalBounds()))
		{


			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}

		}

		window.draw(spriteCroc[0]);
		window.draw(spriteCroc[1]);

		//Snake collisions:

		if (spritePlayer.getGlobalBounds().intersects(spriteSnake[0].getGlobalBounds()))
		{


			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}
		}

		if (spritePlayer.getGlobalBounds().intersects(spriteSnake[1].getGlobalBounds()))
		{


			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}

		}

		if (spritePlayer.getGlobalBounds().intersects(spriteSnake[2].getGlobalBounds()))
		{


			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}
		}

		window.draw(spriteSnake[0]);
		window.draw(spriteSnake[1]);
		window.draw(spriteSnake[2]);


		// Winning game / black boxes collisions for winning game:

		for (int i = 0; i < 6; i++)
		{
			window.draw(doors[i]);
		}

		window.draw(spritePlayer);

		for (int i = 0; i < 6; i++)
		{
			if ((spritePlayer.getPosition().x + texturePlayer.getSize().x / 2) >= (doors[i].getPosition().x))
			{
				if ((spritePlayer.getPosition().x) <= (doors[i].getPosition().x + doors[i].getSize().x))
				{
					if ((spritePlayer.getPosition().y + texturePlayer.getSize().y / 2) >= (spritePlayer.getPosition().y))
					{
						if ((spritePlayer.getPosition().y) <= (doors[i].getPosition().y + doors[i].getSize().y))
						{
							//What happens on collision begins:
							spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
							spritePlayer.setRotation(0);


							clockTimer.restart();
							progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

							iScore += 200;
							iHighScore += iScore;
							iLives += 1;
							iScore = 0;

						}
					}
				}
			}
		}


		//Below is car enemy collisions and more window. methods.

		//Car collisions:

		if (spritePlayer.getGlobalBounds().intersects(spriteCars[0].getGlobalBounds()))
		{


			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}
		}

		if (spritePlayer.getGlobalBounds().intersects(spriteCars[1].getGlobalBounds()))
		{


			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}

		}

		if (spritePlayer.getGlobalBounds().intersects(spriteCars[2].getGlobalBounds()))
		{


			spritePlayer.setPosition(sf::Vector2f(window.getSize().x / 2, spritePavement.getPosition().y + texturePavement.getSize().y - texturePlayer.getSize().y));
			spritePlayer.setRotation(0);

			iHighScore += iScore;
			clockTimer.restart();
			progressBar.setSize(sf::Vector2f(progressBarBackground.getSize().x, 10));

			iScore = 0;
			iLives -= 1;


			if (iLives <= 0){
				iLives = 6;
				iHighScore = 0;
				iScore = 0;
			}
		}


		window.draw(spriteCars[0]);
		window.draw(spriteCars[1]);
		window.draw(spriteCars[2]);
		window.draw(textScore);
		window.draw(textTimer);
		window.draw(textHighScore);
		window.draw(textLives);
		window.draw(progressBarBackground);
		window.draw(progressBar);
		window.display();
	}
}