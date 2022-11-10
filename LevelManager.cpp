#include <iostream>
#include <sstream>
#include<chrono>
#include<thread>

#include "Include/LevelManager.h"
#include "Include/PauseGame.h"

LevelManager::LevelManager(std::shared_ptr<Context> &context)
: m_context(context), m_isPaused(false), m_CarDirection({350, 350.f})
{
     if(!backg.loadFromFile("./../Resources/Images/GameBackground.png"))
    {
        std::cout << "error";
    }
    backg.setSmooth(true);
    back.setTexture(backg);
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

        else if (event.type == sf::Event::KeyPressed)
        {
            sf::Vector2f newDirection = m_CarDirection;
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                RaceCarY -= 10.f;
                newDirection = {RaceCarX, RaceCarY};
                break;
            case sf::Keyboard::Down:
                RaceCarY += 10.f;
                newDirection = {RaceCarX, RaceCarY};
                break;
            case sf::Keyboard::Left:
                RaceCarX -= 10.f;
                newDirection = {RaceCarX, RaceCarY};
                break;
            case sf::Keyboard::Right:
                RaceCarX += 10.f;
                newDirection = {RaceCarX, RaceCarY};
                break;
            case sf::Keyboard::Escape:
                m_context->m_states->Add(std::make_unique<PauseGame>(m_context));
                break;
            default:
                break;
            }
                m_CarDirection = newDirection;
        } 

    }

}

void LevelManager::Update(sf::Time deltaTime)
{
    m_race.Move(m_CarDirection);
}

void LevelManager::Init()
{
     m_context->m_assets->AddTexture(RACECAR, "./../Resources/Images/Car_1.png");
     m_race.Init(m_context->m_assets->GetTexture(RACECAR));    
}

void LevelManager::Draw()
{

    m_context->m_window->clear();
    m_context->m_window->draw(back);

    m_context->m_window->draw(m_race);
    m_context->m_window->display();

}

void LevelManager::SplashScreen()
{
    m_context->m_window->clear();
   //m_context->m_window->draw(swag);
   //Levels.Draw(m_context->m_window);

    m_context->m_window->draw(back);
    m_context->m_window->display();
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
} 

void LevelManager::Pause()
{
    m_isPaused = true;
}

void LevelManager::Start()
{
    m_isPaused = false;
}