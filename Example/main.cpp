#include <iostream>

#include <SFML/Graphics.hpp>

#include "../Source/EntityManager.hpp"
#include "../Source/SystemManager.hpp"

#include "test1/RenderSystem.hpp"
#include "test1/InputSystem.hpp"
#include "test1/MyEntityManager.hpp"

#include "test2/ServerEntityManager.hpp"
#include "test2/ClientEntityManager.hpp"

void test1();
void test2();

int main()
{
    test2();
    return 0;
}

void test1()
{
    ses::EntityManager::Ptr em = std::shared_ptr<ses::EntityManager>(new MyEntityManager());
    //EntityManager::Ptr em = std::shared_ptr<EntityManager>(new EntityManager()); // This one don't have packet handling
    std::cout << "entity manager created" << std::endl;

    ses::SystemManager sm(em);
    std::cout << "system manager created" << std::endl;

    sm.addSystem<RenderSystem>();
    std::cout << "render system added" << std::endl;

    sm.addSystem<InputSystem>();
    std::cout << "input system added" << std::endl;

    // One way
    sf::Int32 id1 = em->usePrefab("Sprite");
    std::cout << "entity added : " << id1 << std::endl;
    if (sm.getSystem<RenderSystem>().entitiesCount() >= 1)
    {
        std::cout << "entity handled by sprite system" << std::endl;
    }

    // Other way
    sf::Packet packet;
    packet << 11 << 11 << "Rectangle";
    em->handlePacket(packet);
    std::cout << "entity added" << std::endl;
    if (sm.getSystem<RenderSystem>().entitiesCount() >= 2)
    {
        std::cout << "entity handled by sprite system" << std::endl;
    }

    sf::RenderWindow window(sf::VideoMode(800,600),"Test");
    std::cout << "window created" << std::endl;

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sm.getSystem<InputSystem>().update(clock.restart());

        window.clear();
        sm.getSystem<RenderSystem>().render(window);
        window.display();
    }

    std::cout << "em : " << em->entitiesCount() << " / ss : " << sm.getSystem<RenderSystem>().entitiesCount() << std::endl;
    em->removeEntity(id1);
    std::cout << "em : " << em->entitiesCount() << " / ss : " << sm.getSystem<RenderSystem>().entitiesCount() << std::endl;
    em->removeEntities();
    std::cout << "em : " << em->entitiesCount() << " / ss : " << sm.getSystem<RenderSystem>().entitiesCount() << std::endl;
}

void test2()
{
    ses::EntityManager::Ptr sem = std::shared_ptr<ses::EntityManager>(new ServerEntityManager());
    ses::SystemManager ssm(sem);
    ssm.addSystem<RenderSystem>();

    ses::EntityManager::Ptr cem = std::shared_ptr<ses::EntityManager>(new ClientEntityManager());
    ses::SystemManager csm(cem);
    csm.addSystem<RenderSystem>();
    csm.addSystem<InputSystem>();

    sf::RenderWindow wS(sf::VideoMode(500,500),"Server");
    wS.setPosition({100,100});
    sf::RenderWindow wC(sf::VideoMode(500,500),"Client");
    wC.setPosition({700,100});

    sem->usePrefab("Sprite");

    sf::Clock clock;
    bool run = true;
    while (run)
    {
        sf::Event e;
        while (wS.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                run = false;
            }
        }
        while (wC.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                run = false;
            }
        }

        csm.getSystem<InputSystem>().update(clock.restart());

        wS.clear();
        ssm.getSystem<RenderSystem>().render(wS);
        wS.display();

        wC.clear();
        csm.getSystem<RenderSystem>().render(wC);
        wC.display();
    }
    wC.close();
    wS.close();
}
