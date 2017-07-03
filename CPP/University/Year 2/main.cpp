//One of the main projects for this year, implementing physics in a puzzle type game or simulation using C++ based on a tutorial located at:

// https://veendeta.wordpress.com/2012/02/16/tutorial-getting-started-with-box2d/

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <iostream>


/** Convert between pixel and real-world coordinates*/
static const float SCALE = 30.f;


/** Create the base for the boxes to land */
void CreateGround(b2World& World, float X, float Y);
void CreateLeftBlock(b2World& World, float X, float Y);


/** Create the boxes */
void CreateBall(b2World& World, int MouseX, int MouseY);

int main()
{
	/** Prepare the window */
	sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Bounce It In!!!"); //Originally 800 x 600 resolution for the game window.
	Window.setFramerateLimit(60);


	/** Prepare the world */
	b2Vec2 Gravity(0.f, 9.8f);
	b2World World(Gravity);
	CreateGround(World, 400.f, 500.f);
	CreateLeftBlock(World, 200.f, 600.f);


	/** Prepare textures */
	sf::Texture Background;
	sf::Texture GroundTexture;
	sf::Texture BallTexture;
	sf::Texture LeftBlockTexture;
	sf::Texture RightBlockTexture;
	GroundTexture.loadFromFile("../assets/ground.png");
	BallTexture.loadFromFile("../assets/ball.png");
	LeftBlockTexture.loadFromFile("../assets/leftblock.png");
	RightBlockTexture.loadFromFile("../assets/rightblock.png");
	Background.loadFromFile("../assets/background.png");

	/** Sets the background **/
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(Background);

	/*Added bool below to try and help me create a mouse click 
	or implement a timer mechanism for mouse click, thus 0 = no ball 1 = a ball then develop from there.*/
	bool mPressed = true;


	while (Window.isOpen(), mPressed = true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::cout << mPressed << std::endl;
			int MouseX = sf::Mouse::getPosition(Window).x;
			int MouseY = sf::Mouse::getPosition(Window).y;
			CreateBall(World, MouseX, MouseY);
			mPressed = false;
			std::cout << mPressed << std::endl;
		}
		World.Step(1 / 60.f, 8, 3);
		Window.clear(sf::Color::White);
		Window.draw(backgroundSprite); //Draws the background


		int BodyCount = 0;
		for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{
			if (BodyIterator->GetType() == b2_dynamicBody)
			{
				sf::Sprite Sprite;
				Sprite.setTexture(BallTexture);
				Sprite.setOrigin(16.f, 16.f);
				Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				Sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
				Window.draw(Sprite);
				++BodyCount;
			}
			else
			{
				sf::Sprite GroundSprite;
				GroundSprite.setTexture(GroundTexture);
				GroundSprite.setOrigin(400.f, 8.f);
				GroundSprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
				Window.draw(GroundSprite);

				
				sf::Sprite LeftBlockSprite;
				LeftBlockSprite.setTexture(LeftBlockTexture);
				LeftBlockSprite.setOrigin(160, 0);
				LeftBlockSprite.setPosition(24, 86);
				LeftBlockSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
				Window.draw(LeftBlockSprite);
				

			}
		}
		Window.display();
	}
	return 0;
}


void CreateBall(b2World& World, int MouseX, int MouseY)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(MouseX / SCALE, MouseY / SCALE);
	BodyDef.type = b2_dynamicBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((32.f / 2) / SCALE, (32.f / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.0f;
	FixtureDef.friction = 0.0f;
	FixtureDef.shape = &Shape;
	FixtureDef.restitution = 1.0f;  // (Coeffecient of) 'Restitution' here is the key part of the code for the ball which makes it bounce off solid objects.
	Body->CreateFixture(&FixtureDef);
}


void CreateGround(b2World& World, float X, float Y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / SCALE, Y / SCALE);
	BodyDef.type = b2_staticBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}


void CreateLeftBlock(b2World& World, float X, float Y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / SCALE, Y / SCALE);
	BodyDef.type = b2_staticBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}
