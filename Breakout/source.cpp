/*
*	souce.cpp
*	Breakout 2D game
*	Ashutosh
*/
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

// constant expression
constexpr int windowWidth{ 800 }, windowHeight{ 600 };
constexpr float ballRadius{ 10.f }, ballVelocity{ 6.f };
constexpr float paddleWidth{ 80.f }, paddleHeight{ 20.f }, paddleVelocity{ 10.f };
constexpr float brickWidth{ 60.f }, brickHeight{ 20.f };
constexpr int bricksCountX{ 11 }, bricksCountY{ 4 };

class Ball : public CircleShape
{
public:
	/*
	Ball constructor.
	(argument mX -> starting x coordinate)
	(argument mY -> starting y coordinate)
	*/
	Ball(float mX, float mY)
	{
		/*	setting-up position, color, radius and origin of Ball */
		setPosition(mX, mY);
		setFillColor(Color::Red);
		setRadius(ballRadius);
		setOrigin(ballRadius / 2, ballRadius / 2);
	}
	//	set velocityX of Ball
	void setVelocityX(float v)
	{
		velocity.x = v;
	}
	//	set velocityY of Ball
	void setVelocityY(float v)
	{
		velocity.y = v;
	}
	//	get velocity of Ball
	Vector2f getVelocity() const
	{
		return velocity;
	}
	//	update
	void update()
	{
		//	Add some velocity
		move(velocity);

		//	checking Horizontal boundary constraints
		if (getLeft() < 0)
		{
			velocity.x = ballVelocity;
		}
		else if (getRight() > windowWidth)
		{
			velocity.x = -ballVelocity;
		}
		//	checking vertical Boundary Constraints
		if (getTop() < 0)
		{
			velocity.y = ballVelocity;
		}
		else if (getBottom() > windowHeight)
		{
			velocity.y = -ballVelocity;
		}

	}
	// get X position of Ball
	float getX() const
	{
		return getPosition().x;
	}
	//	get Y position of Ball
	float getY() const
	{
		return getPosition().y;
	}
	// get position-left of Ball
	float getLeft() const
	{
		return getX() - ballRadius;
	}
	// get position-Right of Ball
	float getRight() const
	{
		return getX() + ballRadius;
	}
	// get position-Top of Ball
	float getTop()  const
	{
		return getY() - ballRadius;
	}
	// get position-Bottom of Ball
	float getBottom() const
	{
		return getY() + ballRadius;
	}
private:
	//	2D vector that stores velocity of Ball
	Vector2f velocity{ -ballVelocity,-ballVelocity };
};

class Paddle :public RectangleShape
{
public:
	/*
	Paddle constructor.
	(argument mX -> starting x coordinate)
	(argument mY -> starting y coordinate)
	*/
	Paddle(float mX, float mY)
	{
		/*	setting-up position,size,color and origin  of paddle*/
		setPosition(mX, mY);
		setSize({ paddleWidth, paddleHeight });
		setFillColor(Color::Blue);
		setOrigin(paddleWidth / 2, paddleHeight / 2);
	}
	//	update
	void update()
	{
		// Add some velocity
		move(velocity);
		// checking for Input and constraints
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && getLeft() > 0)
		{
			velocity.x = -paddleVelocity;	//	move Paddle to Left
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && getRight() < windowWidth)
		{
			velocity.x = paddleVelocity;	//	move Paddle to Right
		}
		else
			velocity.x = 0;	//	stop the Paddle
	}

	// get X position of Paddle
	float getX() const
	{
		return getPosition().x;
	}
	//	get Y position of Paddle
	float getY() const
	{
		return getPosition().y;
	}
	// get position-left of Paddle
	float getLeft() const
	{
		return getX() - paddleWidth / 2.f;
	}
	// get position-Right of Paddle
	float getRight() const
	{
		return getX() + paddleWidth / 2.f;
	}
	// get position-Top of Paddle
	float getTop() const
	{
		return getY() - paddleHeight / 2.f;
	}
	// get position-Bottom of Paddle
	float getBottom() const
	{
		return getY() + paddleHeight / 2.f;
	}
private:
	Vector2f velocity;
};

class Brick : public RectangleShape
{
public:
	/*
	Brick constructor.
	(argument mX -> starting x coordinate)
	(argument mY -> starting y coordinate)
	*/
	Brick(float mX, float mY)
	{
		/*	setting-up position,size,color and origin*/
		setPosition(mX, mY);
		setSize({ brickWidth, brickHeight });
		setFillColor(Color::Green);
		setOrigin(brickWidth / 2, brickHeight / 2);
	}
	//	set destroyed
	void setDestroyed(bool d)
	{
		destroyed = d;
	}
	// check destroyed
	bool isDestroyed() const
	{
		return destroyed;
	}
	// get X position of Brick
	float getX() const
	{
		return getPosition().x;
	}
	//	get Y position of Brick
	float getY() const
	{
		return getPosition().y;
	}
	// get position-left of Brick
	float getLeft() const
	{
		return getX() - brickWidth / 2.f;
	}
	// get position-Right of Brick
	float getRight() const
	{
		return getX() + brickWidth / 2.f;
	}
	// get position-Top of Brick
	float getTop() const
	{
		return getY() - brickHeight / 2.f;
	}
	// get position-Bottom of Brick
	float getBottom() const
	{
		return getY() + brickHeight / 2.f;
	}
private:
	bool destroyed = false;

};

/*
Return True if Two Objects Collide, otherwise False
Dealing with collisions: let's define a generic function
to check if two shapes are intersecting (colliding).
*/
template<typename T1, typename T2>
bool isIntersecting(T1& mA, T2& mB)
{
	return mA.getRight() >= mB.getLeft() && mA.getLeft() <= mB.getRight() &&
		mA.getTop() <= mB.getBottom() && mA.getBottom() >= mB.getTop();
}

// When collision happens
void onCollision(Paddle& mPaddle, Ball& mBall)
{
	if (!isIntersecting(mPaddle, mBall))	//	exit form function	
	{
		return;
	}

	mBall.setVelocityY(-ballVelocity);
	// And Now direct it dependently on the position where the Ball hit Paddle 
	if (mBall.getX() < mPaddle.getX())
	{
		mBall.setVelocityX(-ballVelocity);
	}
	else
	{
		mBall.setVelocityX(ballVelocity);
	}
}

// Here's the most complex part of our game: ball-brick collision.
void onCollision(Brick& mBrick, Ball& mBall, Sound& hit)
{
	// If there's no intersection, get out of the function.
	if (!isIntersecting(mBrick, mBall)) return;

	// Otherwise, the brick has been hit!
	mBrick.setDestroyed(true);
	//	play hit sound
	hit.play();

	/*
	Let's calculate how much the ball intersects the brick in every direction.
	*/
	float overlapLeft{ mBall.getRight() - mBrick.getLeft() };
	float overlapRight{ mBrick.getRight() - mBall.getLeft() };
	float overlapTop{ mBall.getBottom() - mBrick.getTop() };
	float overlapBottom{ mBrick.getBottom() - mBall.getTop() };

	/*
	If the magnitude of the left overlap is smaller than the
	right one we can safely assume the ball hit the brick
	from the left.\
	*/
	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));

	// We can apply the same idea for top/bottom collisions.
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	// Let's store the minimum overlaps for the X and Y axes.
	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	/*
	If the magnitude of the X overlap is less than the magnitude
	of the Y overlap, we can safely assume the ball hit the brick
	horizontally - otherwise, the ball hit the brick vertically.

	Then, upon our assumptions, we change either the X or Y velocity
	of the ball, creating a "realistic" response for the collision.
	*/
	if (abs(minOverlapX) < abs(minOverlapY))
		mBall.setVelocityX(ballFromLeft ? -ballVelocity : ballVelocity);
	else
		mBall.setVelocityY(ballFromTop ? -ballVelocity : ballVelocity);
}

bool gameOver(Ball& mBall)
{
	if (mBall.getBottom() >= windowHeight)
	{
		mBall.setVelocityX(0);
		mBall.setVelocityY(0);
		return true;
	}
	else
		return false;
}

int WinMain()
{
	vector<Brick> bricks;	//	using STL vector, creating vector of Bricks
							/*
							Filling bricks (Brick Vector) in Grid like manner
							*/
	for (int iX{ 0 }; iX < bricksCountX; iX++)
	{
		for (int iY{ 0 }; iY < bricksCountY; iY++)
		{
			bricks.emplace_back(
				(iX + 1) * (brickWidth + 3) + 22, (iY + 2) * (brickHeight + 3));
		}
	}

	RenderWindow window(VideoMode(windowWidth, windowHeight), "BreakOut"); //	creating an instance of RenderWindow

	Paddle paddle(windowWidth / 2, windowHeight - 50);	//	creating an instance of Paddle
	Ball ball(windowWidth / 2, windowHeight / 2);	//	creating an instance of Ball at center

	window.setFramerateLimit(60); //	set frame rate 60 fps

								  /*	setting-up the background music */
	Music bgMusic;
	if (!bgMusic.openFromFile("duck.wav"))
	{
		return -1;	//	error
	}
	bgMusic.setLoop(true);	//	Loop music
	bgMusic.play();	//	play music

					/*	setting-up hit-sound and fall-sound*/
	SoundBuffer buffer;
	if (!buffer.loadFromFile("hit.wav"))
	{
		return -1;	//	error
	}
	Sound hitSound;	//	brick hit sound
	hitSound.setBuffer(buffer);

	/*	setting-up the font and Win-text*/
	Font font;
	if (!font.loadFromFile("myfont.ttf"))
	{
		return -1;	//	error
	}
	//	creating a Text object
	Text winText;
	winText.setFont(font);
	winText.setString("You Won!");
	winText.setCharacterSize(60);
	winText.setColor(Color::Black);
	winText.setPosition(windowWidth / 2 - 120, windowHeight / 2 - 60);

	// Game loop
	while (true)

	{
		window.clear(Color::White);	//	clear the window from the previous draw
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) //	Exit if Escape Key is pressed
		{
			break;
		}
		ball.update();	// run Ball update
		paddle.update();	// run Paddle Update

		onCollision(paddle, ball);	//	deal with collision

		// We use another C++11 foreach loop to test collisions
		// between the ball and EVERY brick.
		for (auto& brick : bricks) onCollision(brick, ball, hitSound);

		// And we use the "erase-remove idiom" to remove all `destroyed`
		// blocks from the block vector - using a cool C++11 lambda!
		bricks.erase(remove_if(begin(bricks), end(bricks),
			[](const Brick& mBrick)
		{
			return mBrick.isDestroyed();
		}),
			end(bricks));

		window.draw(ball);	//	drawing ball on screen
		window.draw(paddle);	//	drawing paddle on screen

		/* Draw Each Brick in bricks on the screen*/
		for (auto& brick : bricks)
		{
			window.draw(brick);
		}
		/*	checking is bricks empty for game Won*/
		if (bricks.empty())
		{
			window.clear(Color::White);
			window.draw(winText);
			bgMusic.stop();	 // stop music

		}
		/*	checking for game over*/
		else if (gameOver(ball))
		{
			bgMusic.stop();	 // stop music
			window.clear(Color::White);
			winText.setString("Game Over!");
			winText.setPosition(windowWidth / 2 - 120, windowHeight / 2 - 60);
			window.draw(winText);
		}
		window.display();	//	show the contents of window
	}
	return 0;
}
