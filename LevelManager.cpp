#include <iostream>
#include <sstream>
#include<chrono>
#include<thread>
#include<math.h>

#include <SFML/Graphics.hpp>

#include "Include/LevelManager.h"
#include "Include/PauseGame.h"

LevelManager::LevelManager(std::shared_ptr<Context> &context)
: m_context(context), m_isPaused(false), m_CarDirection({350, 350.f})
{
    
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
    m_context->m_assets->AddTexture(RACECAR, "./../Resources/Images/Car_3.png");
    m_race.Init(m_context->m_assets->GetTexture(RACECAR));  

    oneuptext.LoadFont();
    HighScore.LoadFont();
    Lives.LoadFont();

    backg.loadFromFile("./../Resources/Images/GameBackground.png");
    backg.setSmooth(false);
    backg.setRepeated(true); 
    
    back.setTexture(backg);
    back.setTextureRect({0,0,1600,1200});
    
    back1 = back;
    back2 = back;
}

void LevelManager::Draw()
{
    ScoreHandler();
    textureHeight = backg.getSize().y;

    back1.setPosition(0,BackgroundY1);
    back2.setPosition(0,BackgroundY2);
    if (BackgroundY2>0)
    {
        BackgroundY1=0;
        BackgroundY2=BackgroundY1-500;
    }
    BackgroundY1+=0.8;
    BackgroundY2+=0.8;

    m_context->m_window->clear();
    m_context->m_window->draw(back1);
    m_context->m_window->draw(back2);
    oneuptext.Draw(m_context->m_window);
    HighScore.Draw(m_context->m_window);
    Lives.Draw(m_context->m_window);
    m_context->m_window->draw(m_race);
    m_context->m_window->display();
}

void LevelManager::ScoreHandler()
{
    std::ostringstream p1Score;
    std::ostringstream highscoreIn;
    std::ostringstream livesIn;
    p1Score << "1UP "
            << "\n"
            << 0;//->GetScore();
    highscoreIn << "Highscore "
                << "\n"
                << "1000000";
    livesIn << "Lives "
            << "\n"
            << 3;//p->GetLives();
    oneuptext.TypeText(p1Score.str(), sf::Color::Yellow, {30, 30});
    HighScore.TypeText(highscoreIn.str(), sf::Color::Yellow, {325, 30});
    Lives.TypeText(livesIn.str(), sf::Color::Yellow, {675, 30});
}

void LevelManager::SplashScreen()
{
    m_context->m_window->clear();
    //m_context->m_window->draw(back1);

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