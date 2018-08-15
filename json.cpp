#include "json.h"


#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <QVariantMap>
#include <QObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
Json::Json()
{

}

void Json::read()
{
    std::string line;
    std::getline(std::cin,line);
    QString input = QString::fromStdString(line);
    parsing(input);

}

void Json::parsing(const QString &input)
{

   QJsonObject jsonobject = QJsonDocument::fromJson(input.toUtf8()).object();
    interval = jsonobject.value("interval").toInt();
    map = jsonobject.value("map").toArray();
    playerpos = jsonobject.value("player").toObject();
    otherplayers = jsonobject.value("other_players").toObject().toVariantMap();
    wals = jsonobject.value("walls").toObject().toVariantMap();
  // qDebug() << playerpos;
}

QJsonArray Json::getMap() const
{
    return map;
}

QJsonObject Json::getPlayerpos() const
{
    return playerpos;
}

QVariantMap Json::getWals() const
{
    return wals;
}

QVariantMap Json::getOtherplayers() const
{
    return otherplayers;
}

