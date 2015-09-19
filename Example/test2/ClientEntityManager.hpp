#ifndef CLIENTENTITYMANAGER_HPP
#define CLIENTENTITYMANAGER_HPP

#include <iostream>

#include <SFML/Network.hpp>

#include "../../Source/EntityManager.hpp"

#include "../test1/SpriteComponent.hpp"
#include "../test1/RenderSystem.hpp"

class ClientEntityManager : public ses::EntityManager
{
    public:
        ClientEntityManager();

        void sendPacket(sf::Packet& packet);
        void handlePackets();
        void handlePacket(sf::Packet& packet);

    private:
        sf::TcpSocket mSocket;
        bool mConnected;
};

#endif // CLIENTENTITYMANAGER_HPP
