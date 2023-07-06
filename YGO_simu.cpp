#include <iostream>
#include <vector>

using namespace std;

class QPushButton
{
private:
    /* data */
public:
    QPushButton(/* args */);
    ~QPushButton();
};

QPushButton::QPushButton(/* args */)
{
}

QPushButton::~QPushButton()
{
}

class Cell;
class Card : public QPushButton
{
public:
    int atk , def;
    string name;
    int state; //1：攻击表示 ， 0：守备表示； 2：盖放
    int belonger; //0:A , 1:B
    Cell * cellFrom = NULL;
public:
    Card(int _atk, int _def, int _state , int _belonger, string _name = ""):
     state(_state), atk(_atk) , def(_def) ,name(_name) , belonger(_belonger)
    {}
    ~Card();
};

Card::~Card()
{
}

class Cell
{
public :
    vector <Card *> source;
    int x , y; //pos
public:
    Cell(int _x = 0, int _y = 0): x(_x) , y(_y)
    {}
    ~Cell();
};

Cell::~Cell()
{
}

class checkerboard
{
public :
    int gameRes; //游戏胜利情况。 0：未结束。 1：A胜利 ， 2：B胜利
    int scoreA , scoreB , cardNumA , cardNumB;
    vector <Card *> cardSummon; //所有场上卡的备份，用于析构函数删除
    Cell AMonsters[5] , BMonsters[5] , AMagic[5] , BMagic[5];
    Cell AVenueMagic , BVenueMagic; //场地魔法
    Cell ATomb , BTomb ,AHandCards , BHandCards; //墓地和手卡
    Cell AOut , BOut; //除外区
    Cell additional_1 , additional_2; //额外怪兽区
    Cell ACards , BCards; //卡组
    //TODO 额外卡组  
public:

//场地信息。竖着的是x坐标，横着的是y坐标。均从1开始.

//B魔法1 , B魔法2 , B魔法3 , B魔法4 , B魔法5

//B怪兽1，B怪兽2，B怪兽3，B怪兽4，B怪兽5，

//          A               B

//A怪兽1，A怪兽2，A怪兽3，A怪兽4，A怪兽5，

//A魔法1，A魔法2，A魔法3，A魔法4，A魔法5.

//A场地魔法 ， B场地魔法
    checkerboard():scoreA(8000) , scoreB(8000)
    {
        for (int i = 0 ; i < 5 ; ++ i) {
            AMonsters[i].x = 4; BMonsters[i].x = 2;
            AMagic[i].x = 5; BMagic[i].x = 1;
            AMonsters[i].y = BMonsters[i].y = AMagic[i].y = BMagic[i].y = i + 1;
            AVenueMagic.x = BVenueMagic.x = 6 ; AVenueMagic.y = 1 ; BVenueMagic.y = 2;
            additional_1.x = additional_2.x = 3; additional_1.y = 2 ; additional_2.y = 4;
        }
    }
    ~checkerboard();

    void initialize()
    {
        scoreA = scoreB = 8000;
        gameRes = 0;
        //input Monsters-card info
        printf("initialize. Please input card info.\n");
        scanf("%d %d",&cardNumA , &cardNumB);
        for (int i = 1 ; i <= cardNumA ; ++ i)
        {
            int _atk , _def , _state;
            string _name;
            cin >> _name;
            scanf("%d %d", &_atk , &_def);
            Card * p = new Card(_atk , _def , 0 , 0 , _name);
            ACards.source.push_back(p);
            cardSummon.push_back(p);
        }
        for (int i = 1 ; i <= cardNumB ; ++ i)
        {
            int _atk , _def;
            string _name;
            cin >> _name;
            scanf("%d %d", &_atk , &_def);
            Card * p = new Card(_atk , _def ,0 , 1 , _name);
            BCards.source.push_back(p);     
            cardSummon.push_back(p);
        }
        
        //TODO 分发手卡
    }

    void clear()
    {
        vector <Card *> :: iterator p = cardSummon.begin();
        for (;p != cardSummon.end(); ++ p) delete *p;
    }
    void send2Tomb(Card * card) {
        card->cellFrom->source.clear();
        if (card->belonger == 0) {
            ATomb.source.push_back(card);
        }
        else {
            BTomb.source.push_back(card);
        }
    }
    void printScores(){
        cout << "A:"<< scoreA << " B:" << scoreB << endl;
    }

    int checkWins() // 用于战斗中的判断，看是否某人score <= 0。返回0表示未结束，返回1表示A胜利，返回B表示B胜利（如果胜利就输出相关信息）。
    {
        if (scoreA <= 0 || gameRes == 2) {
            printf("B wins!\n"); 
            return 2;
        }
        if (scoreB <= 0 || gameRes == 1){
            printf("A wins!\n");
            return 1;
        }
        return 0;
    }

    void printHandCards(int obj) {
        if (obj == 0) {
            vector <Card *> :: iterator p = AHandCards.source.begin();
            printf("A's handcards:\n");
            for (; p != AHandCards.source.end() ; ++ p) {
                cout << (*p)->name << " " << (*p)->atk << " " << (*p)->def << endl;
            }
        }
        else {
            vector <Card *> :: iterator p = BHandCards.source.begin();
            printf("B's handcards:\n");
            for (; p != BHandCards.source.end() ; ++ p) {
                cout << (*p)->name << " " << (*p)->atk << " " << (*p)->def << endl;
            }            
        }
    }
    void performAttack(Card * attacker , Card * defencer)
    {
        int res; //用于表示战斗结果.1:A win,2:B win;0 : peace

        int va , vd; //比较的值。atk , def中的一个
        va = attacker->atk;
        if (defencer->state == 1) 
            vd = defencer->atk ; 
        else {
            vd = defencer->def;
            if (defencer->state == 2) //盖放情况，把卡牌翻出来
            {
                defencer->state = 1;
            }
        }
        if (va > vd) {
            res = 1;
            if (defencer->state == 1) {
                if (attacker->belonger == 0) scoreB -= va - vd;
                else scoreA -= va - vd;
            }
            else {}//守备表示
            send2Tomb(defencer);
        }
        if (va < vd) {
            res = 2;
            if (attacker->belonger == 0) scoreA -= vd - va; else scoreB -= vd - va;
            send2Tomb(attacker);
        }
        if (va == vd) res = 0;

        //output the result
        if (res == 0) {cout << "peace.\n";}
        if (res == 1) cout << "monsterA Win\n"; 
        if (res == 2) cout << "monsterB win\n";
        printScores();
    }

    //以下几个阶段 obj均表示谁执行操作。 若obj = 0 , A操作； =1 ， B操作；
    void prepare_stage(int obj) {
        printf("prepare_stage of %d\n" , obj);
        if (obj == 0) {
            if (ACards.source.size() == 0) { //牌堆空，A lose
                gameRes = 2;
                return;
            }

            //从牌堆中拿一张牌
            AHandCards.source.push_back(*(--ACards.source.end())); //最上面一张牌
            ACards.source.erase(--ACards.source.end());
            printHandCards(0);
        }
        else {
            if (BCards.source.size() == 0) { //牌堆空，B lose
                gameRes = 1;
                return;
            }

            BHandCards.source.push_back(*(--BCards.source.end()));
            BCards.source.erase(--BCards.source.end());
            printHandCards(1);
        }
        printf("\n");
    }
    void M1_stage(int obj) {
        //TODO
        printf("M1_stage of %d\n" , obj);
        char query; //记录询问是否放置卡牌的结果。 Y表示 yes , N 表示No；
        if (obj == 0) {
            //输出场地信息，有多少个空位可以上怪兽。手牌的情况。
            printHandCards(0);
            printf("Empty positions are ");
            for (int i = 0 ; i < 5 ; ++ i) {
                if (AMonsters[i].source.empty()) {
                    printf("(4,%d) ",i);
                }
            }
            printf("\nDo you want to place a monster? (Y/N)\n");
            cin >> query;
            if (query == 'Y') {
                printf("input 4 numbers:\n");
                //第一个是选哪张上场(下标从0开始)。 第二个和第三个是放置的坐标。
                //第四个是0/1/2，0表示守备，1表示攻击。 2表示盖放
                int choice , x , y , state;
                cin >> choice >> x >> y >> state; //suppose the coordinate denotes an empty place!
                AHandCards.source[choice]->state = state;
                AMonsters[y].source.push_back(AHandCards.source[choice]);
                AHandCards.source.erase(AHandCards.source.begin() + choice);
            }
        }
        else {
            printHandCards(1);
            printf("Empty positions are ");
            for (int i = 0 ; i < 5 ; ++ i) {
                if (BMonsters[i].source.empty()) {
                    printf("(2,%d) ",i);
                }
            }
            printf("\nDo you want to place a monster? (Y/N)\n");
            cin >> query;
            if (query == 'Y') {
                printf("input 4 numbers:\n");
                //第一个是选哪张上场(下标从0开始)。 第二个和第三个是放置的坐标。
                //第四个是0/1/2，0表示守备，1表示攻击。 2表示盖放
                int choice , x , y , state;
                cin >> choice >> x >> y >> state; //suppose the coordinate denotes an empty place!
                BHandCards.source[choice]->state = state;
                BMonsters[y].source.push_back(BHandCards.source[choice]);
                BHandCards.source.erase(BHandCards.source.begin() + choice);
            }
        }
    }
    void BP_stage(int obj) {
        //TODO
        //思路：选择能攻击的怪兽，再选定对方怪兽，执行performAttack
    }
    void M2_state(int obj) {
        //TODO
    }
    void EP_stage(int obj) {
        if (obj == 0) {
            if (AHandCards.source.size() > 6) {
                //A弃牌
            }
        }
        else {
            if (BHandCards.source.size() > 6) {
                //B弃牌
            }
        }
    }
    void simu() {
        //1.抽签
        int obj = rand() % 2; // 0/1. 0 表示A先开始 ， 1表示B先开始。
        //2.initialize
        initialize();

        //3.循环
        while (1) {
            prepare_stage(obj);
            if (checkWins() != 0) {
                break;
            }

            M1_stage(obj);
            if (checkWins() != 0) {
                break;
            }

            BP_stage(obj);
            if (checkWins() != 0) {
                break;
            }

            M2_state(obj);
            if (checkWins() != 0) {
                break;
            }     

            EP_stage(obj);

            obj = (obj + 1) % 2;      
        }

        //4.
        printf("\nGame ends!\n");
        clear(); 
    }
};

checkerboard::~checkerboard()
{
}
