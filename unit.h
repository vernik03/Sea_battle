#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QQuickItem>
#include <fstream>
#include <string>
#include <iostream>

class unit: public QObject
{
    Q_OBJECT
public:
    QQuickItem* qTile;
    unit();
    void ReadFile(std::string path = "../Sea_Battle_test/table.txt");
    //bool ships[100]={1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0};
    bool ships[100];
public slots:
    void cppSlot(int x, int y, int index);
signals:
    void cppSignal(int index, bool isShip);

};

#endif // TILE_H
