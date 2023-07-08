#### 2023.5.30

**不熟悉git的使用，这个md也算是测试**

##### 以下是coding记录

1. 新增加的文档是fightinterface.h , fightinterface.ui和fightinterface.cpp。插入了一张图片，battlefield.png。当然还有这个md文档。

2. 按键逻辑部分。实现了fightpre的start-fight button

   实现了fightinterface的back-to-main button。尚未实现fightinterface的点击卡牌显示信息

3. 遇到的困难

   1. 不知道如何实现手卡区域（比如每回合抽卡的时候新增等），暂时以一个Horizontal Layout和6个button代替。
   2. 点击卡牌然后显示卡牌信息的逻辑：是不是要一个个button修改？还是说可以通过搞定一个之后在设计师界面复制，然后就行了？
   3. 有没有统一修改尺寸的方法。
   4. 大部分控件的使用还不熟悉