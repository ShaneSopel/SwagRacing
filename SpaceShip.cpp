#include <array>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Include/SpaceConstants.h"
#include "Include/SpaceShip.h"

using namespace SpaceConstants;

SpaceShip::SpaceShip()
{
    name = "SpaceShip";
}

void SpaceShip::update()
{
	if (thrust)
      { dx+=cos(angle*DEGTORAD)*0.2;
        dy+=sin(angle*DEGTORAD)*0.2; }
     else
      { dx*=0.99;
        dy*=0.99; }

    int maxSpeed=15;
    float speed = sqrt(dx*dx+dy*dy);
    if (speed>maxSpeed)
     { dx *= maxSpeed/speed;
       dy *= maxSpeed/speed; }

    x_coord+=dx;
    y_coord+=dy;

    if (x_coord>MAP_WIDTH1) x_coord=0; if (x_coord<0) x_coord=MAP_WIDTH1;
    if (y_coord>MAP_HEIGHT1) y_coord=0; if (y_coord<0) y_coord=MAP_HEIGHT1;
}

int SpaceShip::GetScore()
{
  return m_score;
}

void SpaceShip::SetScore(int score)
{
  m_score += score;
}

int SpaceShip::GetLives()
{
  return m_lives;
}

void SpaceShip::SetLives(int lives)
{
  m_lives -= lives;
}
