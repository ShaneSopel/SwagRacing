

#include <iostream>
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Include/AssetMan.h"
#include "Include/Asteroids.h"
#include "Include/Animation.h"

#include "Include/Entity.h"
#include "Include/Game.h"
#include "Include/GamePlay.h"
#include "Include/Menu.h"
#include "Include/SpaceConstants.h"
#include "Include/SpaceShip.h"

using namespace Engine;
using namespace SpaceConstants;


Game::Game() : m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(MAP_WIDTH1, MAP_HEIGHT1), "SwagAsteroids", sf::Style::Close);
    m_context->m_states->Add(std::make_unique<Menu>(m_context));
    m_context->m_window->setFramerateLimit(60);
}
Game::~Game()
{
}

void Game::Run()
{

   // sf::Clock clock;
   // sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
       //timeSinceLastFrame += clock.restart();

       // while (timeSinceLastFrame > FRAMES_PER_SECOND)
       // {
       //    timeSinceLastFrame -= FRAMES_PER_SECOND;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->getCurrent()->ProcessInput();
            m_context->m_states->getCurrent()->Update();
            m_context->m_states->getCurrent()->Draw();
    
      //  }
    }

}

void level1 ()
{
    

}


