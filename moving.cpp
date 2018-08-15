#include "moving.h"

#include <QtDebug>
#include <QString>
#include <QJsonArray>
#include <QJsonArray>



Moving::Moving()
{

}

int Moving::wherego(QJsonArray map, QVariantMap otherplayer, QJsonObject player, QVariantMap wal, int jep)
{

    // qDebug() <<player.value("dir");


    if(player.value("dir")=="DOWN")
    {
        //    qDebug() <<"+++++++++++++++++++++"<< player.value("coords").toArray().first();
        for( auto it=otherplayer.begin();it!=otherplayer.end();++it)
        {
            if(player.value("coords").toArray().last().toInt()-2 != otherplayer.value("coords").toJsonArray().last().toInt() && player.value("coords").toArray().first().toInt() != wal.value("coords").toJsonArray().first().toInt()&& player.value("coords").toArray().last().toInt()-1 != 0)
            {
               // if(player.value("coords").toArray().first().toInt()!= otherplayer.value("coords").toJsonArray().first().toInt() && player.value("coords").toArray().first().toInt()!= wal.value("coords").toJsonArray().first().toInt())
                    return 3;
            }
        }
    }
    if(player.value("dir")=="UP")
    {
        for( auto it=otherplayer.begin();it!=otherplayer.end();++it)
        {
            if(player.value("coords").toArray().last().toInt()+2 != otherplayer.value("coords").toJsonArray().last().toInt() && player.value("coords").toArray().first().toInt() != wal.value("coords").toJsonArray().first().toInt() && player.value("coords").toArray().last().toInt()+1 != wal.last().toInt())
            {
                 // if(player.value("coords").toArray().first().toInt() != otherplayer.value("coords").toJsonArray().first().toInt() && player.value("coords").toArray().first().toInt() != wal.value("coords").toJsonArray().first().toInt())
                    return 2;
            }
        }
    }
    if(player.value("dir")!="LEFT")
    {
        // qDebug() <<"+++++"<< player.value("coords").toArray().first();
        for( auto it=otherplayer.begin();it!=otherplayer.end();++it)
        {
            if(it.key()=="coords"){

                if(player.value("coords").toArray().first().toInt()-2 != otherplayer.value("coords").toJsonArray().first().toInt() && player.value("coords").toArray().last().toInt()-2 != wal.value("coords").toJsonArray().last().toInt()&& player.value("coords").toArray().first().toInt()-1 != 0)
                {
                    // if(player.value("coords").toArray().last().toInt()-2 != otherplayer.value("coords").toJsonArray().last().toInt() && player.value("coords").toArray().last().toInt()-2 != wal.value("coords").toJsonArray().last().toInt() )
                    return 0;
                }

            }
        }

    }
    if(player.value("dir")!="RIGHT")
    {
        for( auto it=otherplayer.begin();it!=otherplayer.end();++it)
        {
            if(player.value("coords").toArray().first().toInt()+1 != otherplayer.value("coords").toJsonArray().first().toInt() && player.value("coords").toArray().last().toInt()+1 != wal.value("coords").toJsonArray().last().toInt() && player.value("coords").toArray().first().toInt()-1 != wal.first().toInt())
            {
              //wal.first().toInt()   if(player.value("coords").toArray().last().toInt()-2 != otherplayer.value("coords").toJsonArray().last().toInt() && player.value("coords").toArray().first().toInt()-2 != wal.value("coords").toJsonArray().first().toInt())
                return 1;
            }
        }
    }
    return jep;
}
