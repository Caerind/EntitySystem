#ifndef SERVERENTITYMANAGER_HPP
#define SERVERENTITYMANAGER_HPP

#include <iostream>

#include <SFML/Network.hpp>

#include "../../Source/EntityManager.hpp"

#include "../test1/SpriteComponent.hpp"
#include "../test1/RenderSystem.hpp"

class ServerEntityManager : public ses::EntityManager
{
    public:
        ServerEntityManager();

        void sendPacket(sf::Packet& packet);
        void handlePackets();
        void handlePacket(sf::Packet& packet);

    private:
        sf::TcpListener mListener;
        sf::TcpSocket mSocket;
        bool mConnected;
};

#endif // SERVERENTITYMANAGER_HPP
