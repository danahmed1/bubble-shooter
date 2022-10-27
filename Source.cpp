#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include<fstream>
#include<string>
using namespace std;
using namespace sf;


struct shoot_Level1
{                              //NADA RANEEM
	Sprite shooting_ball[24];
	int column_number0 = 16;
	int column_number1 = 15;
	int column_number2 = 14;
	int column_number3 = 13;
	int column_number4 = 12;
	int column_number5 = 11;
	int column_number6 = 10;
	int column_number7 = 9;

}ball;

struct shoot_Level2
{
	Sprite shooting_balls[25];
	int row1 = 16;
	int row2 = 16;
	int row3 = 16;
	int row4 = 16;
	int row5 = 16;
}balls;

struct shoot_level3
{
	Sprite shooting_ball[24];
	int row1 = 10;
	int row2 = 11;
	int row3 = 12;
	int row4 = 13;
	int row5 = 14;
	int row6 = 13;
	int row7 = 12;
	int row8 = 11;
	int row9 = 10;
}ballss;

struct player
{                           //DANA
	string player_name;
	int high_score = 0;
	int player_score = 0;
};

int count = 0;

//LEVEL 1 FUN

void set_pos_ball(int counter, Sprite clrs[], RenderWindow& window, Event& event, bool level1)     //RANEEM
{
	if (level1)
		clrs[counter].setScale(0.5, 0.5);
	else
		clrs[counter].setScale(0.6, 0.6);
	Vector2f ball_move(Mouse::getPosition(window).x - clrs[counter].getPosition().x, Mouse::getPosition(window).y - clrs[counter].getPosition().y);
	clrs[counter].move(ball_move * (1.f / 10.f));
}

void Filling_cannon_balls_Level1(Texture& redd, Texture& cyann, Texture& yelow, Texture& orangee)    //RANEEM
{
	for (int i = 0; i < 20; i += 4)
	{
		ball.shooting_ball[i].setTexture(redd);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(65, 55);
		//ball.shooting_ball[i].move(velocity);

	}
	for (int i = 1; i < 21; i += 4)
	{
		ball.shooting_ball[i].setTexture(yelow);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(65, 55);
		//ball.shooting_ball[i].move(velocity);
	}
	for (int i = 2; i < 22; i += 4)
	{
		ball.shooting_ball[i].setTexture(cyann);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(58, 58);
		//ball.shooting_ball[i].move(velocity);
	}
	for (int i = 3; i < 23; i += 4)
	{
		ball.shooting_ball[i].setTexture(orangee);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(58, 53);
		//	ball.shooting_ball[i].move(velocity);
	}
}

void Filling_upper_balls_Level1(Texture& redd, Texture& cyann, Texture& yelow, Texture& orangee, Sprite upper_ball_colors[10][25])
{
	//TRIANGLE SHAPE                     //SHAMS
	for (int row = 0; row < 8; row++)
	{
		if (row == 0)
		{
			for (int col = 2; col < 17; col++)
			{
				upper_ball_colors[row][col].setTexture(redd);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -407);
			}
		}
		if (row == 1)
		{
			for (int col = 3; col < 16; col++)
			{
				upper_ball_colors[row][col].setTexture(yelow);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -355);
			}
		}
		if (row == 2)
		{
			for (int col = 4; col < 15; col++)
			{
				upper_ball_colors[row][col].setTexture(orangee);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -308);
			}
		}
		if (row == 3)
		{
			for (int col = 5; col < 14; col++)
			{
				upper_ball_colors[row][col].setTexture(cyann);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -260);
			}
		}
		if (row == 4)
		{
			for (int col = 6; col < 13; col++)
			{
				upper_ball_colors[row][col].setTexture(redd);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -205);
			}
		}
		if (row == 5)
		{
			for (int col = 7; col < 12; col++)
			{
				upper_ball_colors[row][col].setTexture(yelow);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -153);
			}
		}
		if (row == 6)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_colors[row][col].setTexture(orangee);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -105);
			}
		}
		if (row == 7)
		{
			for (int col = 9; col < 10; col++)
			{
				upper_ball_colors[row][col].setTexture(cyann);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -55);
			}
		}
	}
	//end of loop
}

bool Animation_of_upper_balls_Level1(RenderWindow& window, Sprite upper_ball_colors[10][25])
{
	for (int row = 0; row < 8; row++)
	{

		if (row == 0)
		{
			for (int col = 2; col < 17; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 55)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 55);
				}
			}
		}
		else if (row == 1)
		{
			for (int col = 3; col < 16; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 105)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 105);
				}
			}
		}
		else if (row == 2)
		{
			for (int col = 4; col < 15; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 153)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 153);
				}
			}
		}
		else if (row == 3)
		{
			for (int col = 5; col < 14; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 205)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 205);
				}
			}
		}
		else if (row == 4)
		{
			for (int col = 6; col < 13; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 260)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 260);
				}
			}
		}
		else if (row == 5)
		{
			for (int col = 7; col < 12; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 308)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 308);
				}
			}
		}
		else if (row == 6)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 355)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 355);
				}
			}
		}
		else if (row == 7)
		{
			upper_ball_colors[row][9].move(0, 10);
			if (upper_ball_colors[row][9].getPosition().y >= 407)
			{
				upper_ball_colors[row][9].move(0, 0);
				upper_ball_colors[row][9].setPosition(50 * 9, 407);
			}

		}

	}

	return true;
}

void Collision_Level1(RenderWindow& window, Texture& redd, Texture& yelow, Texture& cyann, Texture& orangee, int& scorecounter, Text& scoree, bool& collided, int& counter, player& gameplayer, Sprite upper_ball_colors[10][25], Sound& bubblesound)
{
	for (int i = 0; i < 25; i++)
	{
		if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[0][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[0][i].getTexture() == &redd)
			{
				for (int r = 0; r < 10; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
						collided = true;
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 0; r < 1; r++)
				{
					for (int c = 2; c < 17; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);  //DANA
				scoree.setString("score :" + to_string(gameplayer.player_score));

				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}
			}
			else if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[0][i].getTexture() != &redd)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number0++;
				upper_ball_colors[0][ball.column_number0].setTexture(redd);
				upper_ball_colors[0][ball.column_number0].setScale(0.5, 0.5);
				upper_ball_colors[0][ball.column_number0].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[0][ball.column_number0].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number0++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[0][ball.column_number0].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[0][ball.column_number0].setTexture(cyann);
				else
					upper_ball_colors[0][ball.column_number0].setTexture(orangee);
				upper_ball_colors[0][ball.column_number0].setScale(0.5, 0.5);
				upper_ball_colors[0][ball.column_number0].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[0][ball.column_number0].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[1][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[1][i].getTexture() == &yelow)
			{
				for (int r = 1; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				for (int r = 1; r < 2; r++)
				{
					for (int c = 3; c < 16; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}

			}
			else if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[1][i].getTexture() != &yelow)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number1++;
				upper_ball_colors[1][ball.column_number1].setTexture(yelow);
				upper_ball_colors[1][ball.column_number1].setScale(0.5, 0.5);
				upper_ball_colors[1][ball.column_number1].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[1][ball.column_number1].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number1++;
				if (ball.shooting_ball[counter].getTexture() == &redd)
					upper_ball_colors[1][ball.column_number1].setTexture(redd);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[1][ball.column_number1].setTexture(cyann);
				else
					upper_ball_colors[1][ball.column_number1].setTexture(orangee);
				upper_ball_colors[1][ball.column_number1].setScale(0.5, 0.5);
				upper_ball_colors[1][ball.column_number1].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[1][ball.column_number1].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[2][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[2][i].getTexture() == &orangee)
			{
				for (int r = 2; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 2; r < 3; r++)
				{
					for (int c = 4; c < 15; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}
			}
			else if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[2][i].getTexture() != &orangee)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number2++;
				upper_ball_colors[2][ball.column_number2].setTexture(orangee);
				upper_ball_colors[2][ball.column_number2].setScale(0.5, 0.5);
				upper_ball_colors[2][ball.column_number2].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[2][ball.column_number2].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number2++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[2][ball.column_number2].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[2][ball.column_number2].setTexture(cyann);
				else
					upper_ball_colors[2][ball.column_number2].setTexture(redd);
				upper_ball_colors[2][ball.column_number2].setScale(0.5, 0.5);
				upper_ball_colors[2][ball.column_number2].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[2][ball.column_number2].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[3][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &cyann && upper_ball_colors[3][i].getTexture() == &cyann)
			{
				for (int r = 3; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 3; r < 4; r++)
				{
					for (int c = 5; c < 14; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}

			}
			else if (ball.shooting_ball[counter].getTexture() == &cyann && upper_ball_colors[3][i].getTexture() != &cyann)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number3++;
				upper_ball_colors[3][ball.column_number3].setTexture(cyann);
				upper_ball_colors[3][ball.column_number3].setScale(0.5, 0.5);
				upper_ball_colors[3][ball.column_number3].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[3][ball.column_number3].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number3++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[3][ball.column_number3].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &redd)
					upper_ball_colors[3][ball.column_number3].setTexture(redd);
				else
					upper_ball_colors[3][ball.column_number3].setTexture(orangee);
				upper_ball_colors[3][ball.column_number3].setScale(0.5, 0.5);
				upper_ball_colors[3][ball.column_number3].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[3][ball.column_number3].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[4][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[4][i].getTexture() == &redd)
			{
				for (int r = 4; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 4; r < 5; r++)
				{
					for (int c = 6; c < 13; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}
			}
			else if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[4][i].getTexture() != &redd)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number4++;
				upper_ball_colors[4][ball.column_number4].setTexture(redd);
				upper_ball_colors[4][ball.column_number4].setScale(0.5, 0.5);
				upper_ball_colors[4][ball.column_number4].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[4][ball.column_number4].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number4++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[4][ball.column_number4].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[4][ball.column_number4].setTexture(cyann);
				else
					upper_ball_colors[4][ball.column_number4].setTexture(orangee);
				upper_ball_colors[4][ball.column_number4].setScale(0.5, 0.5);
				upper_ball_colors[4][ball.column_number4].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[4][ball.column_number4].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[5][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[5][i].getTexture() == &yelow)
			{
				for (int r = 5; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 5; r < 6; r++)
				{
					for (int c = 7; c < 12; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}

			}
			else if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[5][i].getTexture() != &yelow)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number0++;
				upper_ball_colors[5][ball.column_number5].setTexture(yelow);
				upper_ball_colors[5][ball.column_number5].setScale(0.5, 0.5);
				upper_ball_colors[5][ball.column_number5].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[5][ball.column_number5].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number5++;
				if (ball.shooting_ball[counter].getTexture() == &redd)
					upper_ball_colors[5][ball.column_number5].setTexture(redd);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[5][ball.column_number5].setTexture(cyann);
				else
					upper_ball_colors[5][ball.column_number5].setTexture(orangee);
				upper_ball_colors[5][ball.column_number5].setScale(0.5, 0.5);
				upper_ball_colors[5][ball.column_number5].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[5][ball.column_number5].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[6][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[6][i].getTexture() == &orangee)
			{
				for (int r = 6; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;

				for (int r = 6; r < 7; r++)
				{
					for (int c = 8; c < 11; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{

					gameplayer.high_score = gameplayer.player_score;

				}
			}
			else if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[6][i].getTexture() != &orangee)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number6++;
				upper_ball_colors[6][ball.column_number6].setTexture(orangee);
				upper_ball_colors[6][ball.column_number6].setScale(0.5, 0.5);
				upper_ball_colors[6][ball.column_number6].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[6][ball.column_number6].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number6++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[6][ball.column_number6].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[6][ball.column_number6].setTexture(cyann);
				else
					upper_ball_colors[6][ball.column_number6].setTexture(redd);
				upper_ball_colors[6][ball.column_number6].setScale(0.5, 0.5);
				upper_ball_colors[6][ball.column_number6].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[6][ball.column_number6].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[7][i].getGlobalBounds()))
		{
			bubblesound.play();
			ball.shooting_ball[counter].move(0, 0);
			ball.column_number7++;
			if (ball.shooting_ball[counter].getTexture() == &yelow)
				upper_ball_colors[7][ball.column_number7].setTexture(yelow);
			else if (ball.shooting_ball[counter].getTexture() == &cyann)
				upper_ball_colors[7][ball.column_number7].setTexture(cyann);
			else if (ball.shooting_ball[counter].getTexture() == &redd)
				upper_ball_colors[7][ball.column_number7].setTexture(redd);
			else
				upper_ball_colors[7][ball.column_number7].setTexture(orangee);
			upper_ball_colors[7][ball.column_number7].setScale(0.5, 0.5);
			upper_ball_colors[7][ball.column_number7].setPosition(ball.shooting_ball[counter].getPosition());
			upper_ball_colors[7][ball.column_number7].setOrigin(ball.shooting_ball[counter].getOrigin());
			ball.shooting_ball[counter].setScale(0, 0);
			counter++;
		}
	}
}


//LEVEL 2222 FUN 

void Filling_cannon_balls_level2(Texture& mint, Texture& cyan, Texture& light_green, Texture& yellow, Texture& orange)
{
	for (int i = 0; i < 21; i += 5)
	{
		balls.shooting_balls[i].setTexture(mint);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(65, 55);
	}
	for (int i = 1; i < 22; i += 5)
	{
		balls.shooting_balls[i].setTexture(cyan);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(65, 55);
	}
	for (int i = 2; i < 23; i += 5)
	{
		balls.shooting_balls[i].setTexture(light_green);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(58, 58);
	}
	for (int i = 3; i < 24; i += 5)
	{
		balls.shooting_balls[i].setTexture(orange);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(58, 53);
	}
	for (int i = 4; i < 25; i += 5)
	{
		balls.shooting_balls[i].setTexture(yellow);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(58, 53);
	}
}

void Filling_upper_balls_level2(Texture& mint, Texture& cyan, Texture& light_green, Texture& yellow, Texture& orange, Sprite upper_ball_level2[7][30])
{
	for (int row = 2; row < 7; row++)
	{
		if (row == 2)
		{
			for (int col = 1; col < 10; col++)
			{
				upper_ball_level2[row][col].setTexture(mint);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 70);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 10; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(yellow);
				upper_ball_level2[row][col].setPosition(55 * -col, 70);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
		if (row == 3)
		{
			for (int col = 1; col < 4; col++)
			{
				upper_ball_level2[row][col].setTexture(light_green);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 125);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 4; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(orange);
				upper_ball_level2[row][col].setPosition(55 * -col, 125);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
		if (row == 4)
		{
			for (int col = 1; col < 8; col++)
			{
				upper_ball_level2[row][col].setTexture(cyan);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 178);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 8; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(mint);
				upper_ball_level2[row][col].setPosition(55 * -col, 179);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
		if (row == 5)
		{
			for (int col = 1; col < 15; col++)
			{
				upper_ball_level2[row][col].setTexture(yellow);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 232);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 15; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(cyan);
				upper_ball_level2[row][col].setPosition(55 * -col, 232);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
		if (row == 6)
		{
			for (int col = 1; col < 4; col++)
			{
				upper_ball_level2[row][col].setTexture(orange);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 285);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 4; col < 8; col++)
			{
				upper_ball_level2[row][col].setTexture(cyan);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 285);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 8; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(light_green);
				upper_ball_level2[row][col].setPosition(55 * -col, 285);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
	}
}

bool Animation_level2(RenderWindow& window, Sprite upper_ball_level2[7][30])
{
	for (int row = 2; row < 7; row++)
	{
		if (row == 2)
		{
			for (int col = 1; col < 10; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 70);
				}
			}
			for (int col = 10; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 70);
				}
			}
		}
		else if (row == 3)
		{
			for (int col = 1; col < 4; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 125);
				}
			}
			for (int col = 4; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 125);
				}
			}
		}
		else if (row == 4)
		{
			for (int col = 1; col < 8; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 178);
				}
			}
			for (int col = 8; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 179);
				}
			}
		}
		else if (row == 5)
		{
			for (int col = 1; col < 15; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 232);
				}
			}
			for (int col = 15; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 232);
				}
			}
		}
		else if (row == 6)
		{
			for (int col = 1; col < 4; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 285);
				}
			}
			for (int col = 4; col < 8; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 285);
				}
			}
			for (int col = 8; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 285);
				}
			}
		}
	}
	return true;
}

void Collision_level2(RenderWindow& window, Texture& mint, Texture& cyan, Texture& light_green, Texture& yellow, Texture& orange, Sprite upper_ball_level2[7][30], int& counter, Sound& bubblesound, int& scorecounter, player& gameplayer, Text& scoree, bool& collided)
{
	for (int i = 0; i < 30; i++)
	{
		if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[2][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &mint && upper_ball_level2[2][i].getTexture() == &mint)
			{
				scorecounter = 0;
				for (int r = 2; r < 7; r++)
				{
					for (int c = 1; c < 10; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
						collided = true;
					}
				}
				for (int r = 2; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x <= 495)
						{
							upper_ball_level2[r][c].setScale(0, 0);
							collided = true;
						}
					}
				}

				for (int i = 0; i < 9; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (balls.shooting_balls[counter].getTexture() == &yellow && upper_ball_level2[2][i].getTexture() == &yellow)
			{
				scorecounter = 0;
				for (int r = 2; r < 7; r++)
				{
					for (int c = 10; c < 17; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 2; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x > 495)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 7; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &mint && upper_ball_level2[2][i].getTexture() != &mint)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row1++;
				upper_ball_level2[2][balls.row1].setTexture(mint);
				upper_ball_level2[2][balls.row1].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[2][balls.row1].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[2][balls.row1].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &yellow && upper_ball_level2[2][i].getTexture() != &yellow)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row1++;
				upper_ball_level2[2][balls.row1].setTexture(yellow);
				upper_ball_level2[2][balls.row1].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[2][balls.row1].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[2][balls.row1].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row1++;
				if (balls.shooting_balls[counter].getTexture() == &cyan)
					upper_ball_level2[2][balls.row1].setTexture(cyan);
				else if (balls.shooting_balls[counter].getTexture() == &orange)
					upper_ball_level2[2][balls.row1].setTexture(orange);
				else
					upper_ball_level2[2][balls.row1].setTexture(light_green);
				upper_ball_level2[2][balls.row1].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[2][balls.row1].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[2][balls.row1].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[3][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &light_green && upper_ball_level2[3][i].getTexture() == &light_green)
			{
				scorecounter = 0;
				for (int r = 3; r < 7; r++)
				{
					for (int c = 1; c < 4; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 3; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x <= 165)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 3; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &orange && upper_ball_level2[3][i].getTexture() == &orange)
			{
				scorecounter = 0;
				for (int r = 3; r < 7; r++)
				{
					for (int c = 4; c < 17; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 3; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x > 165)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 14; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (balls.shooting_balls[counter].getTexture() == &light_green && upper_ball_level2[3][i].getTexture() != &light_green)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row2++;
				upper_ball_level2[3][balls.row2].setTexture(light_green);
				upper_ball_level2[3][balls.row2].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[3][balls.row2].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[3][balls.row2].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &orange && upper_ball_level2[3][i].getTexture() != &orange)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row2++;
				upper_ball_level2[3][balls.row2].setTexture(orange);
				upper_ball_level2[3][balls.row2].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[3][balls.row2].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[3][balls.row2].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row2++;
				if (balls.shooting_balls[counter].getTexture() == &cyan)
					upper_ball_level2[3][balls.row2].setTexture(cyan);
				else if (balls.shooting_balls[counter].getTexture() == &mint)
					upper_ball_level2[3][balls.row2].setTexture(mint);
				else
					upper_ball_level2[3][balls.row2].setTexture(yellow);
				upper_ball_level2[3][balls.row2].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[3][balls.row2].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[3][balls.row2].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[4][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[4][i].getTexture() == &cyan)
			{
				scorecounter = 0;
				for (int r = 4; r < 7; r++)
				{
					for (int c = 1; c < 8; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);

					}
				}
				for (int r = 4; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x <= 385)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 8; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (balls.shooting_balls[counter].getTexture() == &mint && upper_ball_level2[4][i].getTexture() == &mint)
			{
				scorecounter = 0;
				for (int r = 4; r < 7; r++)
				{
					for (int c = 8; c < 17; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 4; r < 7; r++)
				{
					for (int c = 17; c < 25; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x > 385)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 10; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[4][i].getTexture() != &cyan)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row3++;
				upper_ball_level2[4][balls.row3].setTexture(cyan);
				upper_ball_level2[4][balls.row3].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[4][balls.row3].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[4][balls.row3].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &mint && upper_ball_level2[4][i].getTexture() != &mint)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row3++;
				upper_ball_level2[4][balls.row3].setTexture(mint);
				upper_ball_level2[4][balls.row3].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[4][balls.row3].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[4][balls.row3].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row3++;
				if (balls.shooting_balls[counter].getTexture() == &orange)
					upper_ball_level2[4][balls.row3].setTexture(orange);
				else if (balls.shooting_balls[counter].getTexture() == &yellow)
					upper_ball_level2[4][balls.row3].setTexture(yellow);
				else
					upper_ball_level2[4][balls.row3].setTexture(light_green);
				upper_ball_level2[4][balls.row3].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[4][balls.row3].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[4][balls.row3].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[5][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &yellow && upper_ball_level2[5][i].getTexture() == &yellow)
			{
				scorecounter = 0;
				for (int r = 5; r < 7; r++)
				{
					for (int c = 1; c < 15; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 5; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x <= 770)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 14; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[5][i].getTexture() == &cyan)
			{
				scorecounter = 0;
				for (int r = 5; r < 7; r++)
				{
					for (int c = 15; c < 17; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 5; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x > 770)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 2; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &yellow && upper_ball_level2[5][i].getTexture() != &yellow)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row4++;
				upper_ball_level2[5][balls.row4].setTexture(yellow);
				upper_ball_level2[5][balls.row4].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[5][balls.row4].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[5][balls.row4].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[5][i].getTexture() != &cyan)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row4++;
				upper_ball_level2[5][balls.row4].setTexture(cyan);
				upper_ball_level2[5][balls.row4].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[5][balls.row4].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[5][balls.row4].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row4++;
				if (balls.shooting_balls[counter].getTexture() == &light_green)
					upper_ball_level2[5][balls.row4].setTexture(light_green);
				else if (balls.shooting_balls[counter].getTexture() == &mint)
					upper_ball_level2[5][balls.row4].setTexture(mint);
				else
					upper_ball_level2[5][balls.row4].setTexture(orange);
				upper_ball_level2[5][balls.row4].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[5][balls.row4].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[5][balls.row4].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[6][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &orange && upper_ball_level2[6][i].getTexture() == &orange)
			{
				scorecounter = 0;
				for (int c = 1; c < 4; c++)
				{
					upper_ball_level2[6][c].setScale(0, 0);
					scorecounter++;
				}
				for (int c = 17; c < 30; c++)
				{
					if (upper_ball_level2[6][c].getPosition().x <= 165)
					{
						upper_ball_level2[6][c].setScale(0, 0);
					}
				}
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[6][i].getTexture() == &cyan)
			{
				scorecounter = 0;
				for (int c = 4; c < 8; c++)
				{
					upper_ball_level2[6][c].setScale(0, 0);
					scorecounter++;
				}
				for (int c = 17; c < 30; c++)
				{
					if (upper_ball_level2[6][c].getPosition().x > 165 && upper_ball_level2[6][c].getPosition().x <= 385)
					{
						upper_ball_level2[6][c].setScale(0, 0);
					}
				}
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &light_green && upper_ball_level2[6][i].getTexture() == &light_green)
			{
				scorecounter = 0;
				for (int c = 8; c < 17; c++)
				{
					upper_ball_level2[6][c].setScale(0, 0);
					scorecounter++;
				}
				for (int c = 17; c < 30; c++)
				{
					if (upper_ball_level2[6][c].getPosition().x > 385)
					{
						upper_ball_level2[6][c].setScale(0, 0);
					}
				}
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &orange && upper_ball_level2[6][i].getTexture() != &orange)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row5++;
				upper_ball_level2[6][balls.row5].setTexture(orange);
				upper_ball_level2[6][balls.row5].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[6][balls.row5].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[6][balls.row5].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[6][i].getTexture() != &cyan)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row5++;
				upper_ball_level2[6][balls.row5].setTexture(cyan);
				upper_ball_level2[6][balls.row5].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[6][balls.row5].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[6][balls.row5].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &light_green && upper_ball_level2[6][i].getTexture() != &light_green)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row5++;
				upper_ball_level2[6][balls.row5].setTexture(light_green);
				upper_ball_level2[6][balls.row5].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[6][balls.row5].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[6][balls.row5].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row5++;
				if (balls.shooting_balls[counter].getTexture() == &mint)
					upper_ball_level2[6][balls.row5].setTexture(mint);
				else
					upper_ball_level2[6][balls.row5].setTexture(yellow);
				upper_ball_level2[6][balls.row5].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[6][balls.row5].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[6][balls.row5].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
	}
}


//level333 fun

void Filling_upper_balls_level3(Texture& mint, Texture& purple, Texture& light, Texture& yelow, Texture& orangee, Sprite upper_ball_level3[18][25])
{
	for (int row = 0; row < 11; row++)
	{
		if (row == 0)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_level3[row][col].setTexture(orangee);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col, -70);
			}
		}
		if (row == 1)
		{
			for (int col = 7; col < 10; col++)
			{
				upper_ball_level3[row][col].setTexture(mint);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col + 1000, 120);
			}
			for (int col = 10; col < 12; col++)
			{
				upper_ball_level3[row][col].setTexture(yelow);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(51 * -col, 123);
			}
		}
		if (row == 2)
		{
			for (int col = 6; col < 9; col++)
			{
				upper_ball_level3[row][col].setTexture(orangee);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col + 1000, 175);
			}
			for (int col = 9; col < 13; col++)
			{
				upper_ball_level3[row][col].setTexture(purple);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(51 * -col, 175);
			}
		}
		if (row == 3)
		{
			for (int col = 5; col < 8; col++)
			{
				upper_ball_level3[row][col].setTexture(yelow);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col + 1000, 225);
			}
			for (int col = 8; col < 14; col++)
			{
				upper_ball_level3[row][col].setTexture(purple);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(51 * -col, 225);
			}
		}
		if (row == 4)
		{
			for (int col = 4; col < 7; col++)
			{
				upper_ball_level3[row][col].setTexture(mint);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col + 1000, 278);
			}
			for (int col = 7; col < 12; col++)
			{
				upper_ball_level3[row][col].setTexture(orangee);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * -col, 278);
			}
			for (int col = 12; col < 15; col++)
			{
				upper_ball_level3[row][col].setTexture(mint);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col + 1000, 278);
			}

		}
		if (row == 5)
		{
			for (int col = 5; col < 9; col++)
			{
				upper_ball_level3[row][col].setTexture(yelow);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col + 1000, 330);
			}
			upper_ball_level3[row][9].setTexture(light);
			upper_ball_level3[row][9].setScale(0.2, 0.2);
			upper_ball_level3[row][9].setPosition(49 * 9, 330);   //make it animation
			for (int col = 10; col < 14; col++)
			{
				upper_ball_level3[row][col].setTexture(mint);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(52 * -col, 330);
			}
		}
		if (row == 6)
		{
			for (int col = 6; col < 10; col++)
			{
				upper_ball_level3[row][col].setTexture(purple);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col + 1000, 380);
			}
			for (int col = 10; col < 13; col++)
			{
				upper_ball_level3[row][col].setTexture(orangee);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * -col, 380);
			}
		}
		if (row == 7)
		{
			for (int col = 7; col < 10; col++)
			{
				upper_ball_level3[row][col].setTexture(mint);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col + 1000, 430);
			}
			for (int col = 10; col < 12; col++)
			{
				upper_ball_level3[row][col].setTexture(orangee);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * -col, 430);
			}
		}
		if (row == 8)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_level3[row][col].setTexture(yelow);
				upper_ball_level3[row][col].setScale(0.55, 0.55);
				upper_ball_level3[row][col].setPosition(50 * col, -480);
			}

		}
	}

}

void Fillig_cannon_balls_level3(Texture& mint, Texture& purple, Texture& yelow, Texture& orangee)
{
	for (int i = 0; i < 20; i += 4)
	{
		ballss.shooting_ball[i].setTexture(mint);
		ballss.shooting_ball[i].setScale(0.55, 0.55);
		ballss.shooting_ball[i].setPosition(497, 740);
		ballss.shooting_ball[i].setOrigin(65, 55);
	}
	for (int i = 1; i < 21; i += 4)
	{
		ballss.shooting_ball[i].setTexture(purple);
		ballss.shooting_ball[i].setScale(0.55, 0.55);
		ballss.shooting_ball[i].setPosition(497, 740);
		ballss.shooting_ball[i].setOrigin(65, 55);
	}
	for (int i = 2; i < 22; i += 4)
	{
		ballss.shooting_ball[i].setTexture(yelow);
		ballss.shooting_ball[i].setScale(0.55, 0.55);
		ballss.shooting_ball[i].setPosition(497, 740);
		ballss.shooting_ball[i].setOrigin(58, 58);
	}
	for (int i = 3; i < 23; i += 4)
	{
		ballss.shooting_ball[i].setTexture(orangee);
		ballss.shooting_ball[i].setScale(0.55, 0.55);
		ballss.shooting_ball[i].setPosition(497, 740);
		ballss.shooting_ball[i].setOrigin(58, 53);
	}
}

void Collision_level3(RenderWindow& window, Texture& mint, Texture& light, Texture& purple, Texture& yelow, Texture& orangee, Sprite upper_ball_level3[18][25], int& counter3, Sound& bubblesound, int& scorecounter, player& gameplayer, Text& scoree, bool& collided)
{
	for (int i = 0; i < 25; i++)
	{
		scorecounter = 0;
		if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[0][i].getGlobalBounds()))
		{
			if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[0][i].getTexture() == &orangee)
			{
				for (int r = 0; r < 18; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						collided = true;
						scorecounter++;
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[0][i].getTexture() != &orangee)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row1++;
				upper_ball_level3[0][ballss.row1].setTexture(orangee);
				upper_ball_level3[0][ballss.row1].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[0][ballss.row1].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[0][ballss.row1].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row1++;
				if (ballss.shooting_ball[counter3].getTexture() == &mint)
					upper_ball_level3[0][ballss.row1].setTexture(mint);
				else if (ballss.shooting_ball[counter3].getTexture() == &yelow)
					upper_ball_level3[0][ballss.row1].setTexture(yelow);
				else
					upper_ball_level3[0][ballss.row1].setTexture(purple);
				upper_ball_level3[0][ballss.row1].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[0][ballss.row1].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[0][ballss.row1].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
		}
		else if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[1][i].getGlobalBounds()))
		{
			scorecounter = 0;
			if (ballss.shooting_ball[counter3].getTexture() == &mint && upper_ball_level3[1][i].getTexture() == &mint)
			{
				for (int r = 1; r < 18; r++)
				{
					for (int c = 0; c < 10; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 1; r < 18; r++)
				{
					for (int c = 13; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x <= 450)
						{
							upper_ball_level3[r][c].setScale(0, 0);

						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &yelow && upper_ball_level3[1][i].getTexture() == &yelow)
			{
				scorecounter = 0;
				for (int r = 1; r < 18; r++)
				{
					for (int c = 10; c < 12; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 1; r < 18; r++)
				{
					for (int c = 12; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x > 450)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &mint && upper_ball_level3[1][i].getTexture() != &mint)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row2++;
				upper_ball_level3[1][ballss.row2].setTexture(mint);
				upper_ball_level3[1][ballss.row2].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[1][ballss.row2].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[1][ballss.row2].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &yelow && upper_ball_level3[1][i].getTexture() != &yelow)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row2++;
				upper_ball_level3[1][ballss.row2].setTexture(yelow);
				upper_ball_level3[1][ballss.row2].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[1][ballss.row2].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[1][ballss.row2].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row2++;
				if (ballss.shooting_ball[counter3].getTexture() == &purple)
					upper_ball_level3[1][ballss.row2].setTexture(purple);
				else
					upper_ball_level3[1][ballss.row2].setTexture(orangee);
				upper_ball_level3[1][ballss.row2].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[1][ballss.row2].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[1][ballss.row2].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
		}
		else if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[2][i].getGlobalBounds()))
		{
			if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[2][i].getTexture() == &orangee)
			{
				scorecounter = 0;
				for (int r = 2; r < 18; r++)
				{
					for (int c = 0; c < 9; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 2; r < 18; r++)
				{
					for (int c = 13; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x <= 400)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &purple && upper_ball_level3[2][i].getTexture() == &purple)
			{
				scorecounter = 0;
				for (int r = 2; r < 18; r++)
				{
					for (int c = 9; c < 13; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 2; r < 18; r++)
				{
					for (int c = 13; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x > 400)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[2][i].getTexture() != &orangee)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row3++;
				upper_ball_level3[2][ballss.row3].setTexture(orangee);
				upper_ball_level3[2][ballss.row3].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[2][ballss.row3].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[2][ballss.row3].setPosition(ballss.shooting_ball[counter3].getPosition());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &purple && upper_ball_level3[2][i].getTexture() != &purple)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row3++;
				upper_ball_level3[2][ballss.row3].setTexture(purple);
				upper_ball_level3[2][ballss.row3].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[2][ballss.row3].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[2][ballss.row3].setPosition(ballss.shooting_ball[counter3].getPosition());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row3++;
				if (ballss.shooting_ball[counter3].getTexture() == &mint)
					upper_ball_level3[2][ballss.row3].setTexture(mint);
				else
					upper_ball_level3[2][ballss.row3].setTexture(yelow);
				upper_ball_level3[2][ballss.row3].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[2][ballss.row3].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[2][ballss.row3].setPosition(ballss.shooting_ball[counter3].getPosition());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
		}
		else if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[3][i].getGlobalBounds()))
		{
			scorecounter = 0;
			if (ballss.shooting_ball[counter3].getTexture() == &yelow && upper_ball_level3[3][i].getTexture() == &yelow)
			{
				for (int r = 3; r < 18; r++)
				{
					for (int c = 0; c < 8; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 3; r < 18; r++)
				{
					for (int c = 14; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x <= 350)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &purple && upper_ball_level3[3][i].getTexture() == &purple)
			{
				scorecounter = 0;
				for (int r = 2; r < 18; r++)
				{
					for (int c = 8; c < 14; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 3; r < 18; r++)
				{
					for (int c = 14; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x > 350)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (ballss.shooting_ball[counter3].getTexture() == &yelow && upper_ball_level3[3][i].getTexture() != &yelow)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row4++;
				upper_ball_level3[3][ballss.row4].setTexture(yelow);
				upper_ball_level3[3][ballss.row4].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[3][ballss.row4].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[3][ballss.row4].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &purple && upper_ball_level3[3][i].getTexture() != &purple)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row4++;
				upper_ball_level3[3][ballss.row4].setTexture(purple);
				upper_ball_level3[3][ballss.row4].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[3][ballss.row4].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[3][ballss.row4].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row4++;
				if (ballss.shooting_ball[counter3].getTexture() == &mint)
					upper_ball_level3[3][ballss.row4].setTexture(mint);
				else
					upper_ball_level3[3][ballss.row4].setTexture(orangee);
				upper_ball_level3[3][ballss.row4].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[3][ballss.row4].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[3][ballss.row4].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
		}
		else if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[4][i].getGlobalBounds()))
		{
			scorecounter = 0;
			if (ballss.shooting_ball[counter3].getTexture() == &mint && upper_ball_level3[4][i].getTexture() == &mint)
			{
				if (i >= 12)
				{
					for (int r = 4; r < 18; r++)
					{
						for (int c = 12; c < 15; c++)
						{
							upper_ball_level3[r][c].setScale(0, 0);
							scorecounter++;
						}
					}
					for (int r = 4; r < 18; r++)
					{
						for (int c = 15; c < 25; c++)
						{
							if (upper_ball_level3[r][c].getPosition().x <= 700 && upper_ball_level3[r][c].getPosition().x > 550)
							{
								upper_ball_level3[r][c].setScale(0, 0);
							}
						}
					}
					ballss.shooting_ball[counter3].setScale(0, 0);
					counter3++;

					gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
					scoree.setString("Score :" + to_string(gameplayer.player_score));
				}
				else
				{
					scorecounter = 0;
					for (int r = 4; r < 18; r++)
					{
						for (int c = 0; c < 7; c++)
						{
							upper_ball_level3[r][c].setScale(0, 0);
							scorecounter++;
						}
					}
					for (int r = 4; r < 18; r++)
					{
						for (int c = 15; c < 25; c++)
						{
							if (upper_ball_level3[r][c].getPosition().x <= 300)
							{
								upper_ball_level3[r][c].setScale(0, 0);
							}
						}
					}
					ballss.shooting_ball[counter3].setScale(0, 0);
					counter3++;

					gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
					scoree.setString("Score :" + to_string(gameplayer.player_score));
				}
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[4][i].getTexture() == &orangee)
			{
				scorecounter = 0;
				for (int r = 4; r < 18; r++)
				{
					for (int c = 7; c < 12; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 4; r < 18; r++)
				{
					for (int c = 15; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x > 300 && upper_ball_level3[r][c].getPosition().x <= 550)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &mint && upper_ball_level3[4][i].getTexture() != &mint)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row5++;
				upper_ball_level3[4][ballss.row5].setTexture(mint);
				upper_ball_level3[4][ballss.row5].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[4][ballss.row5].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[4][ballss.row5].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[4][i].getTexture() != &orangee)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row5++;
				upper_ball_level3[4][ballss.row5].setTexture(orangee);
				upper_ball_level3[4][ballss.row5].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[4][ballss.row5].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[4][ballss.row5].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row5++;
				if (ballss.shooting_ball[counter3].getTexture() == &yelow)
					upper_ball_level3[4][ballss.row5].setTexture(yelow);
				else
					upper_ball_level3[4][ballss.row5].setTexture(purple);
				upper_ball_level3[4][ballss.row5].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[4][ballss.row5].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[4][ballss.row5].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
		}
		else if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[5][i].getGlobalBounds()))
		{
			scorecounter = 0;
			if (ballss.shooting_ball[counter3].getTexture() == &yelow && upper_ball_level3[5][i].getTexture() == &yelow)
			{
				for (int r = 5; r < 18; r++)
				{
					for (int c = 0; c < 9; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 5; r < 18; r++)
				{
					for (int c = 14; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x <= 400)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (upper_ball_level3[5][i].getTexture() == &light)
			{
				scorecounter = 0;
				for (int r = 5; r < 18; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10) + 100;
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (ballss.shooting_ball[counter3].getTexture() == &mint && upper_ball_level3[5][i].getTexture() == &mint)
			{
				scorecounter = 0;
				for (int r = 4; r < 18; r++)
				{
					for (int c = 10; c < 15; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 5; r < 18; r++)
				{
					for (int c = 14; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x > 441)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &yelow && upper_ball_level3[5][i].getTexture() != &yelow)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row6++;
				upper_ball_level3[5][ballss.row6].setTexture(yelow);
				upper_ball_level3[5][ballss.row6].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[5][ballss.row6].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[5][ballss.row6].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else if (ballss.shooting_ball[counter3].getTexture() == &mint && upper_ball_level3[5][i].getTexture() != &mint)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row6++;
				upper_ball_level3[5][ballss.row6].setTexture(mint);
				upper_ball_level3[5][ballss.row6].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[5][ballss.row6].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[5][ballss.row6].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row6++;
				if (ballss.shooting_ball[counter3].getTexture() == &orangee)
					upper_ball_level3[5][ballss.row6].setTexture(orangee);
				else
					upper_ball_level3[5][ballss.row6].setTexture(purple);
				upper_ball_level3[5][ballss.row6].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[5][ballss.row6].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[5][ballss.row6].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
		}
		else if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[6][i].getGlobalBounds()))
		{
			scorecounter = 0;
			if (ballss.shooting_ball[counter3].getTexture() == &purple && upper_ball_level3[6][i].getTexture() == &purple)
			{
				for (int r = 6; r < 18; r++)
				{
					for (int c = 0; c < 10; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 6; r < 18; r++)
				{
					for (int c = 13; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x <= 450)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[6][i].getTexture() == &orangee)
			{
				scorecounter = 0;
				for (int r = 6; r < 18; r++)
				{
					for (int c = 10; c < 13; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 6; r < 18; r++)
				{
					for (int c = 13; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x > 450)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &purple && upper_ball_level3[6][i].getTexture() != &purple)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row7++;
				upper_ball_level3[6][ballss.row7].setTexture(purple);
				upper_ball_level3[6][ballss.row7].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[6][ballss.row7].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[6][ballss.row7].setScale(ballss.shooting_ball[counter3].getScale());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[6][i].getTexture() != &orangee)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row7++;
				upper_ball_level3[6][ballss.row7].setTexture(orangee);
				upper_ball_level3[6][ballss.row7].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[6][ballss.row7].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[6][ballss.row7].setScale(ballss.shooting_ball[counter3].getScale());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row7++;
				if (ballss.shooting_ball[counter3].getTexture() == &mint)
					upper_ball_level3[6][ballss.row7].setTexture(mint);
				else
					upper_ball_level3[6][ballss.row7].setTexture(yelow);
				upper_ball_level3[6][ballss.row7].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[6][ballss.row7].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[6][ballss.row7].setScale(ballss.shooting_ball[counter3].getScale());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
		}
		else if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[7][i].getGlobalBounds()))
		{
			scorecounter = 0;
			if (ballss.shooting_ball[counter3].getTexture() == &mint && upper_ball_level3[7][i].getTexture() == &mint)
			{
				for (int r = 7; r < 18; r++)
				{
					for (int c = 0; c < 10; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 7; r < 18; r++)
				{
					for (int c = 12; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x <= 450)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[7][i].getTexture() == &orangee)
			{
				scorecounter = 0;
				for (int r = 6; r < 18; r++)
				{
					for (int c = 10; c < 13; c++)
					{
						upper_ball_level3[r][c].setScale(0, 0);
						scorecounter++;
					}
				}
				for (int r = 7; r < 18; r++)
				{
					for (int c = 12; c < 25; c++)
					{
						if (upper_ball_level3[r][c].getPosition().x > 450)
						{
							upper_ball_level3[r][c].setScale(0, 0);
						}
					}
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &mint && upper_ball_level3[7][i].getTexture() != &mint)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row8++;
				upper_ball_level3[7][ballss.row8].setTexture(mint);
				upper_ball_level3[7][ballss.row8].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[7][ballss.row8].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[7][ballss.row8].setScale(ballss.shooting_ball[counter3].getScale());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else if (ballss.shooting_ball[counter3].getTexture() == &orangee && upper_ball_level3[7][i].getTexture() != &orangee)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row8++;
				upper_ball_level3[7][ballss.row8].setTexture(orangee);
				upper_ball_level3[7][ballss.row8].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[7][ballss.row8].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[7][ballss.row8].setScale(ballss.shooting_ball[counter3].getScale());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row8++;
				if (ballss.shooting_ball[counter3].getTexture() == &yelow)
					upper_ball_level3[7][ballss.row8].setTexture(yelow);
				else
					upper_ball_level3[7][ballss.row8].setTexture(purple);
				upper_ball_level3[7][ballss.row8].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				upper_ball_level3[7][ballss.row8].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[7][ballss.row8].setScale(ballss.shooting_ball[counter3].getScale());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
		}
		else if (ballss.shooting_ball[counter3].getGlobalBounds().intersects(upper_ball_level3[8][i].getGlobalBounds()))
		{
			scorecounter = 0;
			if (ballss.shooting_ball[counter3].getTexture() == &yelow && upper_ball_level3[8][i].getTexture() == &yelow)
			{
				for (int c = 0; c < 25; c++)
				{
					upper_ball_level3[8][c].setScale(0, 0);
					scorecounter++;
				}
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (ballss.shooting_ball[counter3].getTexture() == &yelow && upper_ball_level3[8][i].getTexture() != &yelow)
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row9++;
				upper_ball_level3[8][ballss.row9].setTexture(yelow);
				upper_ball_level3[8][ballss.row9].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[8][ballss.row9].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[8][ballss.row9].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;
			}
			else
			{
				ballss.shooting_ball[counter3].move(0, 0);
				ballss.row9++;
				if (ballss.shooting_ball[counter3].getTexture() == &mint)
					upper_ball_level3[8][ballss.row9].setTexture(mint);
				else if (ballss.shooting_ball[counter3].getTexture() == &orangee)
					upper_ball_level3[8][ballss.row9].setTexture(orangee);
				else
					upper_ball_level3[8][ballss.row9].setTexture(purple);
				upper_ball_level3[8][ballss.row9].setScale(ballss.shooting_ball[counter3].getScale());
				upper_ball_level3[8][ballss.row9].setPosition(ballss.shooting_ball[counter3].getPosition());
				upper_ball_level3[8][ballss.row9].setOrigin(ballss.shooting_ball[counter3].getOrigin());
				ballss.shooting_ball[counter3].setScale(0, 0);
				counter3++;

			}
		}
	}
}

void Animation_level3(RenderWindow& window, Sprite upper_ball_level3[18][25])
{
	for (int row = 0; row < 11; row++)
	{
		if (row == 0)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_level3[row][col].move(0, 15);
				if (upper_ball_level3[row][col].getPosition().y >= (70))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 70);
				}

			}
		}
		else if (row == 1)
		{
			for (int col = 7; col < 10; col++)
			{
				upper_ball_level3[row][col].move(-15, 0);
				if (upper_ball_level3[row][col].getPosition().x <= (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 120);
				}
			}
			for (int col = 10; col < 12; col++)
			{
				upper_ball_level3[row][col].move(15, 0);
				if (upper_ball_level3[row][col].getPosition().x > (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 120);
				}
			}
		}
		else if (row == 2)
		{
			for (int col = 6; col < 9; col++)
			{
				upper_ball_level3[row][col].move(-15, 0);
				if (upper_ball_level3[row][col].getPosition().x <= (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 175);
				}
			}
			for (int col = 9; col < 13; col++)
			{
				upper_ball_level3[row][col].move(15, 0);
				if (upper_ball_level3[row][col].getPosition().x > (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 175);
				}
			}

		}
		if (row == 3)
		{
			for (int col = 5; col < 8; col++)
			{
				upper_ball_level3[row][col].move(-15, 0);
				if (upper_ball_level3[row][col].getPosition().x <= (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 225);
				}
			}
			for (int col = 8; col < 14; col++)
			{
				upper_ball_level3[row][col].move(15, 0);
				if (upper_ball_level3[row][col].getPosition().x > (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 225);
				}
			}
		}
		if (row == 4)
		{
			for (int col = 4; col < 7; col++)
			{
				upper_ball_level3[row][col].move(-15, 0);
				if (upper_ball_level3[row][col].getPosition().x <= (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 278);
				}
			}
			for (int col = 7; col < 12; col++)
			{
				upper_ball_level3[row][col].move(15, 0);
				if (upper_ball_level3[row][col].getPosition().x > (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 278);
				}
			}
			for (int col = 12; col < 15; col++)
			{
				upper_ball_level3[row][col].move(-15, 0);
				if (upper_ball_level3[row][col].getPosition().x <= (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 278);
				}
			}
		}
		if (row == 5)
		{
			for (int col = 5; col < 9; col++)
			{
				upper_ball_level3[row][col].move(-15, 0);
				if (upper_ball_level3[row][col].getPosition().x <= (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 330);
				}
			}
			for (int col = 10; col < 14; col++)
			{
				upper_ball_level3[row][col].move(15, 0);
				if (upper_ball_level3[row][col].getPosition().x > (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 325);
				}
			}
		}
		if (row == 6)
		{
			for (int col = 6; col < 10; col++)
			{
				upper_ball_level3[row][col].move(-15, 0);
				if (upper_ball_level3[row][col].getPosition().x <= (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 380);
				}
			}
			for (int col = 10; col < 13; col++)
			{
				upper_ball_level3[row][col].move(15, 0);
				if (upper_ball_level3[row][col].getPosition().x > (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 380);
				}
			}
		}
		if (row == 7)
		{
			for (int col = 7; col < 10; col++)
			{
				upper_ball_level3[row][col].move(-15, 0);
				if (upper_ball_level3[row][col].getPosition().x <= (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 430);
				}

			}
			for (int col = 10; col < 12; col++)
			{
				upper_ball_level3[row][col].move(15, 0);
				if (upper_ball_level3[row][col].getPosition().x > (50 * col))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 430);
				}
			}
		}
		if (row == 8)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_level3[row][col].move(0, 15);
				if (upper_ball_level3[row][col].getPosition().y >= (480))
				{
					upper_ball_level3[row][col].move(0, 0);
					upper_ball_level3[row][col].setPosition(50 * col, 480);
				}
			}
		}
	}
}


//DANA  SHAMS
int draw = 0;
string names[100];
string scoreeeee[100];

void inputfromfile()
{
	ifstream input;
	input.open("file3.txt");
	char ch;

	while (1)
	{
		input >> ch;
		if ('a' <= ch && ch <= 'z')
		{
			names[draw] += ch;
		}

		if ('A' <= ch && ch <= 'Z')
		{
			names[draw] += ch;
		}

		if ('0' <= ch && ch <= '9')
		{
			scoreeeee[draw] += ch;
		}

		if (ch == ',')
		{
			draw++;
		}

		if (input.eof())
			break;
		cout << ch;
	}
	input.close();
}

void savetofile(player gameplayer)
{
	gameplayer.high_score += gameplayer.player_score;
	ofstream output;
	output.open("file3.txt", ios::app);
	output << gameplayer.high_score << "\t";
	output << gameplayer.player_name << "," << endl;
	output.close();
}

int main()
{

	RenderWindow window(VideoMode(1000, 800), "bubble shooter");
	window.setFramerateLimit(30);

	//variable declaration
	int animator = 0, counter = 0, counter2 = 0, counter3 = 0;
	int level = 3;
	bool check = false;
	bool collided = false;
	static bool click;
	string input_text;
	player gameplayer;
	int playindex = 0;
	int scorecounter = 0;
	bool losegame = false;
	bool move_ball = false;
	bool level1 = false;
	bool animated, animated2;

	//textures level1

	Texture redd, yelow, cyann, orangee, backk, cannon_sheet, cannon_base, background,
		bubble, start, animal, menu, monkey, monkey2, senjap, poma, bubb, buuu,
		highh, hscore, howplay, backimage, kass, animation, ground,
		pointer, bname, bhow, congrats, winscore, conball, mann, soundbutoon, soundonn, soundoff,
		nextlevel, level3back;;

	redd.loadFromFile("red.png");
	yelow.loadFromFile("yellow.png");
	cyann.loadFromFile("ball6.png");
	orangee.loadFromFile("orange.png");
	backk.loadFromFile("background.jpg");
	cannon_base.loadFromFile("cannon base.png");
	cannon_sheet.loadFromFile("Cannon spritesheet.png");
	cannon_sheet.loadFromFile("Cannon spritesheet.png");
	background.loadFromFile("back1.jpg");
	bubble.loadFromFile("bubblee.png");
	start.loadFromFile("bstart.png");
	animal.loadFromFile("animals.png");
	menu.loadFromFile("menuu.png");
	monkey.loadFromFile("monkey.png");    //loading images
	monkey2.loadFromFile("monkey2.png");
	senjap.loadFromFile("senjapc.png");
	poma.loadFromFile("boma.png");
	bubb.loadFromFile("bubb.png");
	backimage.loadFromFile("backk.jpeg");
	highh.loadFromFile("high.jpg");
	kass.loadFromFile("kaas.png");
	animation.loadFromFile("anim.png");
	ground.loadFromFile("groundd.jpg");
	pointer.loadFromFile("ppointer.png");
	bname.loadFromFile("board.png");
	howplay.loadFromFile("menu2.png");
	bhow.loadFromFile("howboard.png");
	congrats.loadFromFile("congratulations.png");
	winscore.loadFromFile("board.png");
	conball.loadFromFile("ball 5.png");
	mann.loadFromFile("mann.png");
	soundbutoon.loadFromFile("soundd.png");
	soundonn.loadFromFile("soundon.png");
	soundoff.loadFromFile("soundoff.png");

	nextlevel.loadFromFile("11.jpg");
	level3back.loadFromFile("level3.jpg");

	//sprites

	Sprite backs, base, cannon_sprite, upper_ball_colors[10][25], back, bub, st,
		ani, men, mon, mon2, sen, pom, bu[3], buu, b, hig, kas, animat, grou, point,
		bnam, howp, bhoow, congrt, winscor, coball, man, soundbutt, soundon, soundof,
		nextlevel2, level3;
	backs.setTexture(backk);
	backs.setScale(1.8, 1);

	base.setTexture(cannon_base);
	base.setOrigin(123, 74);
	base.setPosition(500, 750);

	cannon_sprite.setTexture(cannon_sheet);
	cannon_sprite.setPosition(423, 580);
	cannon_sprite.setTextureRect(IntRect(animator * 104, 0, 104, 144));

	back.setTexture(background);
	back.setScale(1.8, 1);

	bub.setTexture(bubble);
	bub.setScale(0.8, 0.8);
	bub.setPosition(270, 90);

	st.setTexture(start);
	st.setPosition(390, 410);
	st.setScale(0.7, 0.7);

	ani.setTexture(animal);
	ani.setPosition(370, 460);
	ani.setScale(0.7, 0.7);

	men.setTexture(menu);
	men.setPosition(280, 120);
	men.setScale(1, 1);

	mon.setTexture(monkey);
	mon.setPosition(700, 70);
	mon.setScale(0.6, 0.6);

	mon2.setTexture(monkey2);
	mon2.setPosition(60, 10);
	mon2.setScale(0.4, 0.4);

	sen.setTexture(senjap);
	sen.setPosition(130, 590);
	sen.setScale(0.3, 0.3);
	sen.setRotation(-30);

	pom.setTexture(poma);
	pom.setPosition(688, 27);
	pom.setScale(0.3, 0.3);

	for (int i = 0; i < 3; i++)
	{
		bu[i].setTexture(bubb);       //loop for repeat this image 
		bu[i].setScale(0.9, 0.9);
	}
	bu[0].setPosition(550, 250);
	bu[1].setPosition(250, 100);
	bu[2].setPosition(220, 350);

	buu.setTexture(buuu);
	buu.setPosition(610, 480);
	buu.setScale(0.6, 0.6);
	buu.setRotation(-25);

	soundbutt.setTexture(soundbutoon);
	soundbutt.setPosition(350, 110);
	soundbutt.setScale(0.5, 0.7);

	soundon.setTexture(soundonn);
	soundon.setPosition(320, 210);
	soundon.setScale(1, 1);

	soundof.setTexture(soundoff);
	soundof.setPosition(320, 310);
	soundof.setScale(1.2, 1.2);

	b.setTexture(backimage);
	b.setScale(1.8, 1);

	hig.setTexture(highh);
	hig.setPosition(300, 240);
	hig.setScale(1.6, 1.6);

	kas.setTexture(kass);
	kas.setPosition(310, 570);
	kas.setScale(0.9, 0.9);

	man.setTexture(mann);
	man.setPosition(50, 650);
	man.setScale(1, 1);

	animat.setTexture(animation);
	animat.setPosition(50, 600);
	animat.setScale(1, 1);

	grou.setTexture(ground);
	grou.setPosition(0, 735);
	grou.setScale(7, 1);

	point.setTexture(pointer);
	point.setPosition(100, 100);
	point.setScale(0.3, 0.3);

	bnam.setTexture(bname);
	bnam.setPosition(340, 280);
	bnam.setScale(0.6, 0.6);

	howp.setTexture(howplay);
	howp.setPosition(300, 490);
	howp.setScale(1, 1);

	bhoow.setTexture(bhow);
	bhoow.setPosition(230, 155);
	bhoow.setScale(1.5, 1.9);

	congrt.setTexture(congrats);
	congrt.setPosition(200, 60);
	congrt.setScale(1, 1);

	winscor.setTexture(winscore);
	winscor.setPosition(345, 280);
	winscor.setScale(0.6, 0.4);

	coball.setTexture(conball);
	coball.setPosition(235, 200);
	coball.setScale(0.6, 0.6);

	nextlevel2.setTexture(nextlevel);
	nextlevel2.setPosition(330, 400);
	nextlevel2.setScale(0.6, 0.6);



	//TEXTURE LEVEL 2


	Texture mint, light_green, backgroundl2;
	mint.loadFromFile("mint.png");
	light_green.loadFromFile("green.png");
	backgroundl2.loadFromFile("level2b.jpg");

	Sprite upper_ball_level2[7][30], backg2;
	backg2.setTexture(backgroundl2);
	backg2.setScale(1.5, 1);


	//texture level3
	Texture  purple, light;
	purple.loadFromFile("purple.png");
	light.loadFromFile("lighting ball.png");

	Sprite  upper_ball_level3[18][25];

	level3.setTexture(level3back);
	level3.setScale(1.8, 0.9);

	//CALL LEVEL 1

	Filling_cannon_balls_Level1(redd, cyann, yelow, orangee);
	Filling_upper_balls_Level1(redd, cyann, yelow, orangee, upper_ball_colors);

	//CALL LEVEL 2
	Filling_cannon_balls_level2(mint, cyann, light_green, yelow, orangee);
	Filling_upper_balls_level2(mint, cyann, light_green, yelow, orangee, upper_ball_level2);


	//CALL LEVEL 3
	Filling_upper_balls_level3(mint, purple, light, yelow, orangee, upper_ball_level3);
	Fillig_cannon_balls_level3(mint, purple, yelow, orangee);


	Font font, ffont, fffont;
	font.loadFromFile("font.ttf");
	ffont.loadFromFile("hhhh.ttf");
	fffont.loadFromFile("foont.ttf");

	Text sstart, play, exit, totalscores, hs, ssound, backh, leve, score, text, next, hello,
		name, how, howback, cong, scoree, winhigh, scorepage, conggrats, winssssscore, score_max,
		aa1, aa2, aa3, aa4, aa5, score_val, cconggrats, lose, htp, goodluck, playagain, soundword, ON, OF, backsound,
		level2, level2game, playgain2, level3game;

	sstart.setFont(font);
	sstart.setString("START");
	sstart.setPosition(420, 405);
	sstart.setFillColor(Color(90, 60, 80, 255));
	sstart.setCharacterSize(65);

	play.setFont(font);
	play.setString("Play");
	play.setPosition(460, 140);
	play.setCharacterSize(80);

	exit.setString("Back");
	exit.setFont(font);
	exit.setPosition(460, 625);
	exit.setCharacterSize(85);

	ssound.setFont(font);
	ssound.setString("Sound");
	ssound.setCharacterSize(75);
	ssound.setPosition(317, 520);

	soundword.setFont(fffont);
	soundword.setPosition(380, 120);
	soundword.setString("Sound :");
	soundword.setCharacterSize(60);
	soundword.setFillColor(Color(90, 60, 80, 255));

	ON.setFont(ffont);
	ON.setPosition(520, 210);
	ON.setString("ON");
	ON.setCharacterSize(70);
	ON.setFillColor(Color(90, 60, 80, 255));

	OF.setFont(ffont);
	OF.setPosition(520, 310);
	OF.setString("OFF");
	OF.setCharacterSize(70);
	OF.setFillColor(Color(90, 60, 80, 255));

	backsound.setFont(font);
	backsound.setString("Back");
	backsound.setPosition(405, 410);
	backsound.setFillColor(Color(100, 100, 50, 255));
	backsound.setCharacterSize(80);

	how.setFont(font);
	how.setPosition(450, 410);
	how.setString("how to play");
	how.setCharacterSize(43);

	totalscores.setString("Scores");
	totalscores.setFont(font);
	totalscores.setPosition(330, 277);
	totalscores.setCharacterSize(65);

	hs.setFont(ffont);
	hs.setString("SCORES");
	hs.setPosition(340, 130);
	hs.setFillColor(Color(210, 110, 60, 255));
	hs.setCharacterSize(75);

	backh.setString("Back");
	backh.setFont(font);
	backh.setPosition(610, 670);
	backh.setCharacterSize(85);

	leve.setFont(ffont);
	leve.setString("level: 1");
	leve.setPosition(15, 0);
	leve.setCharacterSize(50);
	leve.setFillColor(Color::White);

	score.setFont(ffont);
	score.setString("Score :");
	score.setPosition(750, 0);
	score.setFillColor(Color::White);
	score.setCharacterSize(50);

	howback.setFont(font);
	howback.setString("Back");
	howback.setCharacterSize(100);
	howback.setPosition(460, 670);

	scoree.setFont(ffont);
	scoree.setCharacterSize(50);
	scoree.setString("score :" + to_string(gameplayer.player_score));
	scoree.setPosition(720, 0);

	winhigh.setFont(font);
	winhigh.setString("SCORES");
	winhigh.setCharacterSize(80);
	winhigh.setPosition(380, 400);
	winhigh.setFillColor(Color(90, 60, 80, 255));

	cconggrats.setFont(fffont);
	cconggrats.setString("c   ngratulation");
	cconggrats.setCharacterSize(80);
	cconggrats.setPosition(180, 180);
	cconggrats.setFillColor(Color(90, 60, 80, 255));

	playagain.setFont(font);
	playagain.setString("Play again");
	playagain.setPosition(350, 390);
	playagain.setCharacterSize(70);

	lose.setString("You Failed!");
	lose.setCharacterSize(90);
	lose.setPosition(250, 150);
	lose.setFillColor(Color(90, 60, 80, 255));
	lose.setFont(ffont);

	goodluck.setFont(fffont);
	goodluck.setPosition(280, 230);
	goodluck.setFillColor(Color(90, 60, 80, 255));
	goodluck.setString("Hard Luck!");
	goodluck.setCharacterSize(86);

	htp.setFont(fffont);
	htp.setPosition(290, 280);
	htp.setFillColor(Color(90, 60, 80, 255));
	htp.setString("\t\t\t\tWELCOME\n Hope you enjoy our game .\n Once you start playing ,\n you will have a minute to \npop all the bubbles in order \nto win. \n \t\t\tGood Luck !\n\t\t Let's get popping !!");
	htp.setCharacterSize(30);

	aa1.setFont(ffont);
	aa1.setPosition(400, 240);
	aa1.setCharacterSize(40);
	aa1.setFillColor((Color::Black));

	aa2.setFont(ffont);
	aa2.setPosition(400, 300);
	aa2.setFillColor((Color::Black));
	aa2.setCharacterSize(40);

	aa3.setFont(ffont);
	aa3.setPosition(400, 360);
	aa3.setFillColor((Color::Black));
	aa3.setCharacterSize(40);

	aa4.setFont(ffont);
	aa4.setPosition(400, 420);
	aa4.setFillColor((Color::Black));
	aa4.setCharacterSize(40);

	aa5.setFont(ffont);
	aa5.setPosition(400, 470);
	aa5.setFillColor((Color::Black));
	aa5.setCharacterSize(40);

	//enter user name

	text.setFont(fffont);
	text.setPosition(395, 380);
	text.setCharacterSize(50);
	text.setFillColor(Color(0, 0, 0, 255));

	hello.setFont(ffont);
	hello.setString("Hello!");
	hello.setPosition(370, 110);
	hello.setFillColor(Color(210, 110, 60, 255));
	hello.setCharacterSize(70);

	name.setFont(ffont);
	name.setFont(ffont);
	name.setString("Please,Enter your name");
	name.setPosition(250, 220);
	name.setFillColor(Color(210, 110, 60, 255));
	name.setCharacterSize(42);

	next.setFont(font);
	next.setString("Next");
	next.setPosition(400, 470);
	next.setFillColor(Color(210, 110, 60, 255));
	next.setCharacterSize(110);

	Text timer;
	int timee = 0;
	timer.setString("Time : 00: " + to_string(timee));                        //  TIMER //
	timer.setFont(fffont);
	timer.setCharacterSize(50);
	timer.setFillColor(Color::White);
	timer.setPosition(290, 0);


	level2.setString("next level ");
	level2.setFont(ffont);
	level2.setCharacterSize(58);
	level2.setPosition(340, 400);

	level2game.setFont(ffont);
	level2game.setString("level: 2");
	level2game.setPosition(15, 0);
	level2game.setCharacterSize(50);
	level2game.setFillColor(Color::White);


	level3game.setFont(ffont);
	level3game.setString("level: 3");
	level3game.setPosition(15, 0);
	level3game.setCharacterSize(50);
	level3game.setFillColor(Color::White);


	//SOUND                 //MANAR
	SoundBuffer buff, bubblesoundbuffer, animationupper, winsound, losesound, rightshoot;
	buff.loadFromFile("soundclick (1).wav");
	bubblesoundbuffer.loadFromFile("bubble sound.wav");
	animationupper.loadFromFile("animationball.wav");
	winsound.loadFromFile("winplay.wav");
	losesound.loadFromFile("losesound.wav");
	rightshoot.loadFromFile("shoot right ball.wav");


	Sound sound, bubblesound, aniupper, losesou, winsou, rightshot;
	sound.setBuffer(buff);
	bubblesound.setBuffer(bubblesoundbuffer);
	aniupper.setBuffer(animationupper);
	winsou.setBuffer(winsound);
	losesou.setBuffer(losesound);
	losesou.setVolume(100);
	rightshot.setBuffer(rightshoot);


	Music music;
	music.openFromFile("game music.wav");
	music.play();
	music.setLoop(true);

	int count = 0;

	//end of loop

	counter = 0;            //RANEEM
	Clock clock, draww;

	int time;
	time = 32;  //intial time
	timee = 0;

	// SHAMS   DANA
	inputfromfile();
	aa1.setString(names[0] + "   " + scoreeeee[0]);

	aa2.setString(names[1] + "   " + scoreeeee[1]);

	aa3.setString(names[2] + "   " + scoreeeee[2]);

	aa4.setString(names[3] + "   " + scoreeeee[3]);

	aa5.setString(names[4] + "   " + scoreeeee[4]);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			//RAWAAAN

			if (event.KeyPressed)
			{
				point.setPosition(Mouse::getPosition(window).x,
					Mouse::getPosition(window).y);

				if (point.getGlobalBounds().intersects(sstart.getGlobalBounds()))
				{
					sstart.setFillColor(Color(0, 0, 0, 255));
				}
				else
					sstart.setFillColor(Color(90, 60, 80, 255));

				if (point.getGlobalBounds().intersects(play.getGlobalBounds()))
				{
					play.setFillColor(Color(0, 0, 0, 255));
				}
				else
					play.setFillColor(Color(100, 100, 50, 255));

				if (point.getGlobalBounds().intersects(ssound.getGlobalBounds()))
				{
					ssound.setFillColor(Color(0, 0, 0, 255));
				}
				else
					ssound.setFillColor(Color(100, 100, 50, 255));

				if (point.getGlobalBounds().intersects(totalscores.getGlobalBounds()))
				{
					totalscores.setFillColor(Color(0, 0, 0, 255));
				}
				else
					totalscores.setFillColor(Color(100, 100, 50, 255));

				if (point.getGlobalBounds().intersects(how.getGlobalBounds()))
				{
					how.setFillColor(Color(0, 0, 0, 255));
				}
				else
					how.setFillColor(Color(100, 100, 50, 255));

				if (point.getGlobalBounds().intersects(exit.getGlobalBounds()))
				{
					exit.setFillColor(Color(0, 0, 0, 255));
				}
				else
					exit.setFillColor(Color(100, 100, 50, 255));

				if (point.getGlobalBounds().intersects(next.getGlobalBounds()))
				{
					next.setFillColor(Color(0, 0, 0, 255));
				}
				else
					next.setFillColor(Color(100, 100, 50, 255));

				if (point.getGlobalBounds().intersects(backh.getGlobalBounds()))
				{
					backh.setFillColor(Color(0, 0, 0, 255));
				}
				else
					backh.setFillColor(Color(90, 60, 80, 255));

				if (point.getGlobalBounds().intersects(howback.getGlobalBounds()))
				{
					howback.setFillColor(Color(0, 0, 0, 255));
				}
				else
					howback.setFillColor(Color(90, 60, 80, 255));

				if (point.getGlobalBounds().intersects(winhigh.getGlobalBounds()))
				{
					winhigh.setFillColor(Color(0, 0, 0, 255));
				}
				else
					winhigh.setFillColor(Color(90, 60, 80, 255));

				if (point.getGlobalBounds().intersects(playagain.getGlobalBounds()))
				{
					playagain.setFillColor(Color(0, 0, 0, 255));
				}
				else
					playagain.setFillColor(Color(100, 100, 50, 255));

				if (point.getGlobalBounds().intersects(backsound.getGlobalBounds()))
				{
					backsound.setFillColor(Color(0, 0, 0, 255));
				}
				else
					backsound.setFillColor(Color(100, 100, 50, 255));

				if (point.getGlobalBounds().intersects(level2.getGlobalBounds()))
				{
					level2.setFillColor(Color(0, 0, 0, 255));
				}
				else
					level2.setFillColor(Color(90, 60, 80, 255));


			}

			//move between padges
			if (Mouse::isButtonPressed(Mouse::Left))
			{

				if (count == 0)
				{
					if
						(point.getGlobalBounds().intersects(sstart.getGlobalBounds()))
					{
						sound.play();
						count = 1;
					}
					break;
				}

				if (count == 1)
				{
					if (point.getGlobalBounds().intersects(play.getGlobalBounds()))
					{
						sound.play();
						count = 4;
					}
					if (point.getGlobalBounds().intersects(totalscores.getGlobalBounds()))
					{
						sound.play();
						count = 3;
					}
					if (point.getGlobalBounds().intersects(how.getGlobalBounds()))
					{
						sound.play();
						count = 5;
					}
					if (point.getGlobalBounds().intersects(exit.getGlobalBounds()))
					{
						sound.play();
						count = 0;
					}

					if (point.getGlobalBounds().intersects(ssound.getGlobalBounds()))
					{
						sound.play();
						count = 8;
					}

					break;
				}


				if (count == 3)
				{
					if
						(point.getGlobalBounds().intersects(backh.getGlobalBounds()))
					{
						sound.play();
						count = 1;
					}
				}
				if (count == 5)
				{
					if
						(point.getGlobalBounds().intersects(howback.getGlobalBounds()))
					{
						sound.play();
						count = 1;
					}
				}


				if (count == 7)
				{
					if (point.getGlobalBounds().intersects(playagain.getGlobalBounds()))
					{
						sound.play();
						count = 2;
						clock.restart();
						aniupper.play();

						gameplayer.player_score = 0;
						scoree.setString("score :" + to_string(gameplayer.player_score));

						ball.column_number0 = 16;
						ball.column_number1 = 15;
						ball.column_number2 = 14;
						ball.column_number3 = 13;
						ball.column_number4 = 12;
						ball.column_number5 = 11;
						ball.column_number6 = 10;
						ball.column_number7 = 9;
						counter = 0;

						for (int i = 0; i < 8; i++)
						{
							if (i == 0)
							{
								for (int j = 17; j < 25; j++)
								{
									if (upper_ball_colors[i][j].getScale().x > 0 && upper_ball_colors[i][j].getScale().y > 0)
									{
										upper_ball_colors[i][j].setScale(0, 0);
									}

								}
							}
							if (i == 1)
							{
								for (int j = 16; j < 25; j++)
								{
									if (upper_ball_colors[i][j].getScale().x > 0 && upper_ball_colors[i][j].getScale().y > 0)
									{
										upper_ball_colors[i][j].setScale(0, 0);
									}

								}
							}
							if (i == 2)
							{
								for (int j = 15; j < 25; j++)
								{
									if (upper_ball_colors[i][j].getScale().x > 0 && upper_ball_colors[i][j].getScale().y > 0)
									{
										upper_ball_colors[i][j].setScale(0, 0);
									}

								}
							}
							if (i == 3)
							{
								for (int j = 14; j < 25; j++)
								{
									if (upper_ball_colors[i][j].getScale().x > 0 && upper_ball_colors[i][j].getScale().y > 0)
									{
										upper_ball_colors[i][j].setScale(0, 0);
									}

								}
							}
							if (i == 4)
							{
								for (int j = 13; j < 25; j++)
								{
									if (upper_ball_colors[i][j].getScale().x > 0 && upper_ball_colors[i][j].getScale().y > 0)
									{
										upper_ball_colors[i][j].setScale(0, 0);
									}

								}
							}
							if (i == 5)
							{
								for (int j = 12; j < 25; j++)
								{
									if (upper_ball_colors[i][j].getScale().x > 0 && upper_ball_colors[i][j].getScale().y > 0)
									{
										upper_ball_colors[i][j].setScale(0, 0);
									}

								}
							}
							if (i == 6)
							{
								for (int j = 11; j < 25; j++)
								{
									if (upper_ball_colors[i][j].getScale().x > 0 && upper_ball_colors[i][j].getScale().y > 0)
									{
										upper_ball_colors[i][j].setScale(0, 0);
									}

								}
							}
							if (i == 7)
							{
								for (int j = 10; j < 25; j++)
								{
									if (upper_ball_colors[i][j].getScale().x > 0 && upper_ball_colors[i][j].getScale().y > 0)
									{
										upper_ball_colors[i][j].setScale(0, 0);
									}

								}
							}
						}
						Filling_upper_balls_Level1(redd, cyann, yelow, orangee, upper_ball_colors);
						Filling_cannon_balls_Level1(redd, cyann, yelow, orangee);
					}
				}

				if (count == 11)
				{
					if (point.getGlobalBounds().intersects(level2.getGlobalBounds()))
					{

						sound.play();
						count = 9;
						clock.restart();
						aniupper.play();

						gameplayer.player_score = 0;
						scoree.setString("score :" + to_string(gameplayer.player_score));
						balls.row1 = 16;
						balls.row2 = 16;
						balls.row3 = 16;
						balls.row4 = 16;
						balls.row5 = 16;
						counter2 = 0;
						for (int i = 2; i < 7; i++)
						{
							for (int j = 17; j < 30; j++)
							{
								if (upper_ball_level2[i][j].getScale().x > 0 && upper_ball_level2[i][j].getScale().y > 0)
								{
									upper_ball_level2[i][j].setScale(0, 0);
								}
							}

						}
						Filling_upper_balls_level2(mint, cyann, light_green, yelow, orangee, upper_ball_level2);
						Filling_cannon_balls_level2(mint, cyann, light_green, yelow, orangee);


					}
				}

				if (count == 10)
				{
					if (point.getGlobalBounds().intersects(level2.getGlobalBounds()))
					{
						sound.play();
						clock.restart();
						count = 12;

					}
					break;
				}


				if (count == 8)
				{
					if (point.getGlobalBounds().intersects(ON.getGlobalBounds()))
					{
						music.play();
						ON.setFillColor(Color(0, 0, 0, 255));
						OF.setFillColor(Color(90, 60, 80, 255));
					}

					if (point.getGlobalBounds().intersects(OF.getGlobalBounds()))
					{
						music.pause();
						OF.setFillColor(Color(0, 0, 0, 255));
						ON.setFillColor(Color(90, 60, 80, 255));

					}
					if (point.getGlobalBounds().intersects(backsound.getGlobalBounds()))
					{
						sound.play();
						count = 1;
					}

					break;
				}

				if (count == 6)
				{
					if
						(point.getGlobalBounds().intersects(level2.getGlobalBounds()))
					{
						sound.play();
						count = 9;
						clock.restart();
						aniupper.play();
						collided = false;
						gameplayer.player_score = 0;
						scoree.setString("score :" + to_string(gameplayer.player_score));
					}
					break;
				}
			}

			if (count == 10)
			{
				winssssscore.setString("Your Score :" + to_string(gameplayer.player_score));

			}





			//enter player name                     //RAWAAN
			if (event.type == Event::TextEntered)
			{
				if (count == 4)
				{
					if (isprint(event.text.unicode) && input_text.size() < 7)
						input_text += event.text.unicode;
				}
			}

			text.setString(input_text);


			//DANAA  SHAMS FILES
			for (int i = 0; i < 15; i++)
			{
				if (input_text == gameplayer.player_name)
				{
					playindex = i;
					break;
				}
				else
				{
					gameplayer.player_name = input_text;
					playindex = i;
					break;
				}
			}

			if (input_text.size() == 0)
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (point.getGlobalBounds().intersects(next.getGlobalBounds()))
					{
						sound.play();
						count = 4;
					}
				}
			}

			else if ((input_text.size() < 8))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (point.getGlobalBounds().intersects(next.getGlobalBounds()))
					{
						if (count == 4)
						{
							sound.play();
							count = 2;
							clock.restart();
							aniupper.play();
						}
					}
				}
			}


			if (Mouse::isButtonPressed(Mouse::Left))
			{
				move_ball = true;
			}

			if (!(Mouse::isButtonPressed(Mouse::Left)))
			{
				move_ball = false;
			}
		}

		if (count == 2)
		{
			level1 = true;

			if (move_ball)
			{
				set_pos_ball(counter, ball.shooting_ball, window, event, level1);
			}
		}

		if (count == 9)
		{
			level1 = false;

			if (move_ball)
			{

				set_pos_ball(counter2, balls.shooting_balls, window, event, level1);
			}
		}

		if (count == 12)
		{
			level1 = false;
			if (move_ball)
			{
				set_pos_ball(counter3, ballss.shooting_ball, window, event, level);
			}
		}

		Collision_Level1(window, redd, yelow, cyann, orangee, scorecounter, scoree, collided, counter, gameplayer, upper_ball_colors, bubblesound);
		Collision_level2(window, mint, cyann, light_green, yelow, orangee, upper_ball_level2, counter2, bubblesound, scorecounter, gameplayer, scoree, collided);
		Collision_level3(window, mint, light, purple, yelow, orangee, upper_ball_level3, counter3, bubblesound, scorecounter, gameplayer, scoree, collided);

		//RANEEM
		timee = time - clock.getElapsedTime().asSeconds();
		timer.setString("Time : 00: " + to_string(timee));

		window.clear();

		//RAWAN
		if (count == 0)
		{
			window.draw(back);          //  First Page  //
			window.draw(bub);
			window.draw(st);
			window.draw(sstart);
			window.draw(ani);
			window.draw(point);

		}
		if (count == 1)
		{
			window.draw(back);
			window.draw(men);
			window.draw(howp);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);          //second page
			window.draw(bu[0]);
			window.draw(bu[1]);
			window.draw(bu[2]);
			window.draw(play);
			window.draw(exit);
			window.draw(ssound);
			window.draw(totalscores);
			window.draw(how);
			window.draw(point);
		}
		if (count == 2) //play page
		{
			window.draw(backs);
			window.draw(grou);
			window.draw(base);
			window.draw(ball.shooting_ball[counter]);
			window.draw(cannon_sprite);
			//window.draw(animat);
			window.draw(man);

			if (upper_ball_colors[7][9].getPosition().x == 50 * 9 && upper_ball_colors[7][9].getPosition().y == 407)
			{
				window.draw(timer);
				window.draw(scoree);
				window.draw(leve);

			}

			animated = Animation_of_upper_balls_Level1(window, upper_ball_colors);

			//SHAMS
			for (int row = 0; row < 8; row++)
			{
				for (int col = 2; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 16)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
			> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 1; row < 8; row++)
			{
				for (int col = 3; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 15)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
			> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 2; row < 8; row++)
			{
				for (int col = 4; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 14)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
					> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 3; row < 8; row++)
			{
				for (int col = 5; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 13)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
			> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 4; row < 8; row++)
			{
				for (int col = 6; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 12)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
			> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 5; row < 8; row++)
			{
				for (int col = 7; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 11)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
			> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 6; row < 8; row++)
			{
				for (int col = 8; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 10)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
			> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int i = 23; i >= 0; i--)
				window.draw(ball.shooting_ball[i]);

			for (int row = 0; row < 20; row++)
			{
				for (int col = 0; col < 25; col++)
				{
					//RANEEM
					if (timee > 0 && collided)
					{
						//win window
						count = 6;
						winsou.play();
					}
					if (timee <= 0 && !(collided))
					{
						timer.setString("Time : 00:00 ");
						count = 7;
						losesou.play();

					}
				}
			}

			//DANA

			winssssscore.setFont(ffont);
			winssssscore.setString("Your Score :" + to_string(gameplayer.player_score));
			winssssscore.setPosition(300, 280);
			winssssscore.setCharacterSize(45);
			winssssscore.setFillColor(Color::Black);

		}
		if (count == 3)
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);                       //highscore
			window.draw(hig);
			window.draw(hs);
			window.draw(kas);
			window.draw(backh);
			window.draw(point);
			window.draw(aa1);
			window.draw(aa2);
			window.draw(aa3);
			window.draw(aa4);
			window.draw(aa5);
		}
		if (count == 4)                                 //Name page
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);
			window.draw(hello);
			window.draw(name);
			window.draw(bnam);
			window.draw(text);
			window.draw(next);
			window.draw(point);
		}
		if (count == 5)                    //   How To Play  //
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);
			window.draw(bhoow);
			window.draw(howback);
			window.draw(point);
			window.draw(htp);
		}
		if (count == 6)
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);                               //  WIN PAGE  //    
			window.draw(pom);
			window.draw(cconggrats);
			window.draw(coball);
			window.draw(ani);
			//window.draw(winhigh);
			scoree.setString("score :" + to_string(gameplayer.player_score));
			window.draw(winssssscore);
			window.draw(nextlevel2);
			window.draw(level2);
			window.draw(point);
		}
		if (count == 7)                                 //   LOSE PAGE   //
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);
			window.draw(lose);
			window.draw(goodluck);
			window.draw(ani);
			window.draw(playagain);
			window.draw(point);
		}
		if (count == 8)                                 //  SOUND//
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);
			window.draw(ani);
			window.draw(soundbutt);
			window.draw(soundword);
			window.draw(soundof);
			window.draw(soundon);
			window.draw(ON);
			window.draw(OF);
			window.draw(backsound);
			window.draw(point);
		}



		if (count == 9)

		{
			window.draw(backg2);
			window.draw(level2game);

			Animation_level2(window, upper_ball_level2);


			for (int row = 2; row < 7; row++)
			{
				for (int col = 1; col < 30; col++)
				{
					if (col > 16)
					{
						if (upper_ball_level2[row][col].getScale().x > 0 && upper_ball_level2[row][col].getScale().y > 0)
							window.draw(upper_ball_level2[row][col]);
						else
							continue;
					}
					else
						window.draw(upper_ball_level2[row][col]);
				}
			}
			window.draw(timer);
			window.draw(grou);
			window.draw(base);
			window.draw(ball.shooting_ball[counter]);
			window.draw(cannon_sprite);
			window.draw(man);
			window.draw(scoree);

			for (int i = 23; i >= 0; i--)
				window.draw(balls.shooting_balls[i]);

			for (int row = 0; row < 7; row++)
			{
				for (int col = 0; col < 30; col++)
				{
					//RANEEM
					if (timee > 0 && collided)
					{
						//win window
						count = 10;
						winsou.play();
					}
					if (timee <= 0 && !(collided))
					{
						timer.setString("Time : 00:00 ");
						count = 11;  //lose
						losesou.play();

					}
				}
			}

		}

		if (count == 10)
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);                               //  WIN PAGE  //    
			window.draw(pom);
			window.draw(cconggrats);
			window.draw(coball);
			window.draw(ani);
			//window.draw(winhigh);
			window.draw(winssssscore);
			scoree.setString("score :" + to_string(gameplayer.player_score));
			window.draw(nextlevel2);
			window.draw(level2);
			window.draw(point);
		}

		if (count == 11)
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);               //lose
			window.draw(lose);
			window.draw(goodluck);
			window.draw(ani);
			window.draw(playagain);
			window.draw(point);
		}

		if (count == 12)
		{
			Animation_level3(window, upper_ball_level3);

			window.draw(level3);
			window.draw(cannon_sprite);
			window.draw(base);
			window.draw(level3game);
			window.draw(timer);
			scoree.setString("score :" + to_string(gameplayer.player_score));
			window.draw(scoree);

			for (int row = 0; row < 11; row++)
			{
				if (row == 0)
				{
					for (int col = 8; col < 11; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 11; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}
				}
				if (row == 1)
				{
					for (int col = 7; col < 12; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 12; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}

				}
				if (row == 2)
				{
					for (int col = 6; col < 13; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 13; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}

				}
				if (row == 3)
				{
					for (int col = 5; col < 14; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 14; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}

				}
				if (row == 4)
				{
					for (int col = 4; col < 15; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 15; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}

				}
				if (row == 5)
				{
					for (int col = 5; col < 14; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 12; col < 16; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 16; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}


				}
				if (row == 6)
				{
					for (int col = 6; col < 13; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 13; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}

				}
				if (row == 7)
				{
					for (int col = 7; col < 12; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 12; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}

				}
				if (row == 8)
				{
					for (int col = 8; col < 11; col++)
					{
						window.draw(upper_ball_level3[row][col]);
					}
					for (int col = 11; col < 25; col++)
					{
						if (upper_ball_level3[row][col].getScale().x > 0 && upper_ball_level3[row][col].getScale().y > 0)
						{
							window.draw(upper_ball_level3[row][col]);
						}
					}

				}
			}



			for (int i = 23; i >= 0; i--)
				window.draw(ballss.shooting_ball[i]);
		}

		if (count == 13)
		{

			window.draw(backg2);

		}

		window.display();
	}
	savetofile(gameplayer);

	return 0;
}