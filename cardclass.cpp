#include "cardclass.h"

Card::Card(char s){
    Kind=s;
}

Card::Card(){
    Kind=0;
}

int Card::stars(){
    return -1;
}

int Card::attributes(){
    return -1;
}

int Card::race(){
    return -1;
}

string Card::keyword(){
    return "";
}

int Card::getlink(){
    return 0;
}

int Card::getatk(){
    return -1;
}

int Card::getdef(){
    return -1;
}
