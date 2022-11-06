#include <iostream>
#include <sstream>
#include<chrono>
#include<thread>

#include "Include/LevelManager.h"



LevelManager::LevelManager(std::shared_ptr<Context> &context)
: m_context(context), m_AsteroidNum(5) //, p()
{
    oneuptext.LoadFont();
    HighScore.LoadFont();
    Lives.LoadFont();
    Levels.LoadFont();
    AsteroidsRemain.LoadFont();
    sound.LoadSound();
    swaglogo.loadFromFile("./../Resources/Images/Asteroids.png");
    swag.setTexture(swaglogo);
}

LevelManager::~LevelManager()
{
}

void LevelManager::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        } 

    }


}

void LevelManager::Update()
{
     

}





void LevelManager::Init()
{
   

    //m_context->m_assets->AddTexture(SpaceConstants::Rock_IMG, "./../Resources/Images/rock.png");
    //t1 = m_context->m_assets->GetTexture(SpaceConstants::Rock_IMG);
    //Animation sRock(t1, 0, 0, 64, 64, 16, 0.2);

 
}

void LevelManager::Draw()
{
    m_context->m_window->clear();

}

void LevelManager::SplashScreen()
{
    m_context->m_window->clear();
    m_context->m_window->draw(swag);
    Levels.Draw(m_context->m_window);
    m_context->m_window->display();
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
} 

void LevelManager::Pause()
{

}

void LevelManager::Start()
{

}