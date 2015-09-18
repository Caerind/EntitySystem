#include "Client.hpp"
#include "../EntityManager.hpp"

Client::Client(std::shared_ptr<EntityManager> entityManager)
: mManager(entityManager)
, mThread(Client::update,this)
{
    // Launch connection

    mRunning = true;
    mThread.launch();
}

Client::~Client()
{
    mMutex.lock();
    // TODO : Send message : Client left
    mRunning = false;
    mMutex.unlock();
    mThread.wait();
}

void Client::sendMessage(Message const& message)
{
    sf::Lock lock(mMutex);
    mSendQueue.push(message);
}

void Client::update()
{
    while(mRunning)
    {
        while (!mSendQueue.empty())
        {
            mSocket.send(mSendQueue.front());
            mSendQueue.pop();
        }
        mSendQueue.clear();

        Message message;
        while (mSocket.receive(message) && mManager != nullptr)
        {
            mManager->handleMessage(message);
        }
    }
}

sf::TcpSocket& Client::getSocket()
{
    return mSocket;
}
