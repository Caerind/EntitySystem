#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <memory>
#include <queue>

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "../Message.hpp"

class EntityManager;

class Client
{
    public:
        Client(std::shared_ptr<EntityManager> entityManager);
        ~Client();

        void sendMessage(Message const& message);

        void update();

        sf::TcpSocket& getSocket();

    private:
        std::shared_ptr<EntityManager> mManager;
        std::queue<Message> mSendQueue;
        sf::Thread mThread;
        sf::Mutex mMutex;
        bool mRunning;
        sf::TcpSocket mSocket;
};

#endif // CLIENT_HPP
