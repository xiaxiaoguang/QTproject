#ifndef CELL_H
#define CELL_H

#include <QPushButton>
#include "cardclass.h"
#include <QVector>
#include "cardclass.h"
#include <vector>

using namespace std;

class Cell : public QPushButton
{
public:
    vector <Card *> source;
    int x , y; //pos
    int state; //1：攻击表示 ， 0：守备表示； 2：盖放 -1:没有卡
    int belonger; //0:A , 1:B
    Cell(int _x = 0, int _y = 0);
};

#endif // CELL_H
