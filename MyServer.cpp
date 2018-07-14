
#include "MyServer.h"

MyServer::MyServer(){}

MyServer::~MyServer(){}

void MyServer::startServer()
{
    if (this->listen(QHostAddress::Any,5555))
    {
        qDebug()<<"Listening";
    }
    else
    {
        qDebug()<<"Not listening";
    }
}

void MyServer::incomingConnection(int socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));

    qDebug()<<socketDescriptor<<"Client connected";

    socket->write("You are connect");
    qDebug()<<"Send client connected status - YES";

}

void MyServer::sockReady()
{

}

void MyServer::sockDisc()
{
    qDebug()<<"Disconnect";
    socket->deleteLater();
}
