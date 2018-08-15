#ifndef JSON_H
#define JSON_H

#include <QString>
#include <QObject>
#include <QList>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>

class Json
{

public:
    Json();
    void read();
    void parsing(const QString &input);


     QVariantMap otherplayers, wals;
     QJsonObject playerpos;
     QJsonArray map;
     int interval;


     QVariantMap getOtherplayers() const;
     QVariantMap getWals() const;
     QJsonObject getPlayerpos() const;
     QJsonArray getMap() const;
};

#endif // JSON_H
