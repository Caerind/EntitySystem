#ifndef MYENTITYMANAGER_HPP
#define MYENTITYMANAGER_HPP

#include "../../Source/EntityManager.hpp"
#include "RenderSystem.hpp"
#include "SpriteComponent.hpp"
#include "RectangleComponent.hpp"

class MyEntityManager : public ses::EntityManager
{
    public:
        MyEntityManager();

        void handlePacket(sf::Packet& packet);
};

#endif // MYENTITYMANAGER_HPP
