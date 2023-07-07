#include "cell.h"

Cell::Cell(int _x, int _y): x(_x) , y(_y)
{
    belonger=0;
    state = 0;
    source.clear();
}
