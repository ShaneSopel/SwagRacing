#include <iostream>
#include <memory>

#include "Include/GameObject.h"
#include "Include/DrawMap.h"
#include "Include/LevelManager.h"
#include "Include/Menu.h"


#include "SpaceConstants.h"

using namespace SpaceConstants;

Menu::Menu(std::shared_ptr<Context> &context)
: m_context(context), m_isPlayButtonSelected(true), m_isPlayButtonPressed(false), m_isOptionsButtonSelected(false),
      m_isOptionsButtonPressed(false), m_isExitButtonSelected(false), m_isExitButtonPressed(false)
{
    float width = MAP_WIDTH1;
    float height = MAP_HEIGHT1;
    if(!font.loadFromFile("./../Resources/Images/ARCADE.TTF"))
    {

    }
   
    swaglogo.loadFromFile("./../Resources/Images/Asteroids.png");
    swag.setTexture(swaglogo);

    // Play Button
    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Play");
    text[0].setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.5));

    // Options Button
    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Options");
    text[1].setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    // Exit Button
    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Exit");
    text[2].setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.5));

}

Menu::~Menu()
{

}

void Menu::ProcessInput()
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
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
            {
                if (!m_isPlayButtonSelected)
                {
                    m_isPlayButtonSelected = true;
                    m_isOptionsButtonSelected = false;
                    m_isExitButtonSelected = false;
                }
                else if (!m_isOptionsButtonSelected)
                {
                    m_isPlayButtonSelected = false;
                    m_isOptionsButtonSelected = true;
                    m_isExitButtonSelected = false;
                }

                break;
            }
            case sf::Keyboard::Down:
            {

                if (!m_isOptionsButtonSelected)
                {
                    m_isPlayButtonSelected = false;
                    m_isOptionsButtonSelected = true;
                    m_isExitButtonSelected = false;
                }
                else
                {
                    m_isPlayButtonSelected = false;
                    m_isOptionsButtonSelected = false;
                    m_isExitButtonSelected = true;
                }

                break;
            }
            case sf::Keyboard::Return:
            {
                m_isPlayButtonPressed = false;
                m_isExitButtonPressed = false;
                m_isOptionsButtonPressed = false;

                if (m_isPlayButtonSelected)
                {
                    m_isPlayButtonPressed = true;
                }
                //  else if(m_isOptionsButtonSelected)
                //  {
                //      m_isOptionsButtonPressed = true;
                //  }
                else
                {
                    m_isExitButtonPressed = true;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void Menu::Update()
{
    if (m_isPlayButtonSelected)
    {
        text[0].setFillColor(sf::Color::Red);
        text[1].setFillColor(sf::Color::White);
        text[2].setFillColor(sf::Color::White);
    }
    else if (m_isExitButtonSelected)
    {
        text[0].setFillColor(sf::Color::White);
        text[1].setFillColor(sf::Color::White);
        text[2].setFillColor(sf::Color::Red);
    }

    if (m_isPlayButtonPressed)
    {
        m_context->m_states->Add(std::make_unique<LevelManager>(m_context), true);
    }

    if (m_isExitButtonPressed)
    {
        m_context->m_window->close();
    }
}


void Menu::Draw()
{

    m_context->m_window->clear();
    draw.Draw_map(m_context->m_window);
    m_context->m_window->draw(swag);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        m_context->m_window->draw(text[i]);
    }

    m_context->m_window->display();

}

void Menu::Init()
{
}

void Menu::Pause()
{

}

void Menu::Start()
{
    
}