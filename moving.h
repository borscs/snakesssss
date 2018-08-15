#pragma once

#include <QList>
#include <QJsonObject>
#include <QJsonObject>

class Moving
{
public:
    Moving();
    int wherego(QJsonArray map, QVariantMap otherplayer, QJsonObject player, QVariantMap wal, int jep=0);
};

