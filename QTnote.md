# QT for Beginners

进度条

使用上方buttonLayOut，这样可以同时调整他们的大小

选择第二个按键，然后点击进度条拉到横拉条

然后再用slider连接到progressbar

脚本语言中，对应connect函数

第一个是sender参数输入
我们想要发出信号的对象slider

第二个是signal，就是做出什么信号

第三个是progressbar接受的对象

第四个输入SLOT(SetValue(int))
表示progressbar收到什么信号

然后就会发现我们同样拥有一样效果

一个是sender一个是receiver

效果就是让sender的信号到receiver

同样我们有disconnect函数用来分离两个

QMessageBoxExample

加入一个pushbotton

重命名

我们mainwindow.ui就会加入一个新的对象`

```cpp

#include<QMessageBox>

QMessageBox :: about(this,"My Title",
"This is my custom message");

```
里面有一些基本的函数

about

aboutQt

critical

information

question

warning

这是一些列message类型

aboutQT就是返回一些关于QTFramework的信息

critical三个参数

会返回一个带有红叉的信息

information message就会返回一个带i的

question则是返回一个？，并且有yes和np的选项

warning是黄色！

question第四个参数可以放入一个选项信息显示的调整
```cpp
#include<qDebug>

if(reply == QMessageBox::Yes){
    QApplication::quit();
}else{
    qDebug << "No is clicked";
}

```
如果我们点击no，那么会在下方调试窗口弹出一个No is clicked


layout布局

有两种方式

直接水平竖直合并成一个layout，但是之后改变大小只能同时改变。

或者水平竖直对齐，而不合并不同的layout，并放一个spliter在中间

spliter可以被控制调整两侧layout的水平/竖直占比

合并为layout之后，使用editbuddies可以继续处理单一对象（连接信息之类的

第四个是edit tab，这个是我们切换我们tab按键首先选中的对象。

Tab就是键盘上的选中

新建窗口

New file QT QT designer form class

model approch:

```cpp

void MainWindow::on_pushbutton_clicked(){
    secdialog qwq;
    qwq.setmodel(true);
    qwq.exec();
}

```
当打开第二个窗口的时候，你不能操作第一个窗口。

model less approch:

```cpp

void MainWindow::on_pushbutton_clicked(){
    secdialog = new secdialog(this);
    secdialog->show();
}
```

可以同时操作两个窗口了

注意，这样需要在mainwindow.h里面先加入这个成员:secdialog* 类型的指针。

有的时候你希望隐藏原先的窗口

可以使用hide(); methed  直接调用即可，但是之后好像不会再出现（

点击进入pushbutton clicked相关函数，表示点击该按键我们会执行什么

```cpp
    Qstring username = ui -> lineedit_username ->text();
    Qstring password = ui -> lineedit_password ->text();

    if(username == "tst" && password == "tst"){
        QMessageBox::information(this,"Login","Username and password is correct");
        hide();
        secDialog = new secDialog(this);
        secDialog->show();
    }else {
        QMessageBox::Warning(this,"Login","Username and password is not correct");
    }
```

首先include QPixmap，这允许我们使用Qpixmap object

在电脑中拷贝你需要的文件的路径

mention the slash
```cpp
QPixmap pix("/data/img.png");

ui->label_pic->setPixmap(pix);
```

但是这样不会让图片resize到合适的样子

使用pix.scaled(100,100,Qt::KeepAspectRatio)

保持长宽比例到100*100

我们可以提取下wh然后放缩到恰好合适：
```cpp
int w = ui->label_pic->width();
int h = ui->label_pic->height();

ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

```

我们也可以简单的通过ui界面插入图片，但是还没学怎么ui调整图片

QstatusBar

```cpp
ui->QstatusBar->showMessage("Usrname and password is correct",timeout=0);

```

timeout is 延迟多少秒之后消失


```cpp

ui->statusBar->addPermanentWidget(ui->label,1);

```

可以调整label位置1的意思好像是1by1，3就是3by1，也就是3对1的宽度比

statusBar也可通过sendtext来返回信息

qrc file

addprefix

我们就创建了一个程序所需要的resource文件夹，我们可以之后在里面加入任何图片文件等等，并且再在代码中访问他们的时候就不需要去用系统路径了，只需要相对于resource去建立

输入框中的echoMode，从Normal改为Password那么输入的时候就会让password变成*防止窥屏

textlabel中可以使用HTML语法

```html

<b><font color = red> hello world<font>

```

表示红色然后加粗字体

<i>表示倾斜

<h1>一级标题

当然我们也有很多Html技术

比如插入一个table

当然也可以在style sheet来调整的方法

color:red;//颜色

font-size:20 px//字号

font-style italic;//倾斜

font:"Times New Roman"//字体

border-style//边框类型

border-color//边框颜色

然后我们在resources加入一个图片，然后

点击整个窗口，加入一个backgroud

## QcheckBox

```cpp
#include<QMessageBox>

void on_pushbotton_clicked()
{
    if(ui->checkBox->isChecked()){
        QMessageBox::information(this,"title","Yes users likes apples");
    }
}

```

但是这样实在user点击check之后才会有反应，所以我们可以用
```cpp
void on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        QMessageBox::information(this,"title","Yes users likes apples");
    }
}

```

如果你想要by default，我们可以在构造函数中使用

```cpp

ui->checkBox->setChecked(true);

```

How can use radio button in QT

QRatioButton

is circle checkbox?

but all the Ratio Button you can only choose one RatioButtons.

我们可以看ratiobutton的对象名，之后就可以在cpp中访问这两个对象

```cpp
if(ui->ratioButton->isChecked()){
    QMessageBox::information(this,"title","mark");
}

if(ui->ratioButton_2->isChecked()){
    QMessageBox::information(this,"title","mark");
}

```

isCheckable 是这个按钮是否可以按。

我们怎么分成不同的问题的ratiobuttons

我们可以把他们分入不同的group里来解决这个问题。

我们可以加入menu item，其中可以放置各种类型item。

我们先把三个图片计入resources

然后在gui界面可以设计这三个选项的图像，就可以用这三者。

我们有了图像就可以插入到上边栏就快速了

我们在cpp界面设置这三个按键被点击的效果

```cpp
void MainWindow::on_actionExit_triggered()
{

}   

```

QComboBox

下拉菜单

```cpp
ui->comboBox->addItem(QIcon(":/qwq.img"),"Mark");
ui->comboBox->addItem(QIcon(":/qaq.img"),"John");
ui->comboBox->addItem(QIcon(":/quq.img"),"Ben");

```

这样会创建三个下拉选项，每一个有qwq/qaq/quq作为开头的图标。

利用循环可以一下创建多个
```cpp
for i in range(10):
    ui->comboBox->addItem(Qstring::number(i)+"name");
```

这样就会创建1～10name的人物

可以通过自建立的文件中读取具体的名字。这样就无需写超长代码。

利用

```cpp
ui->comboBox->currentText();
```

可以调取目前正在选中的那个选项的名称字符串。

选择

```cpp
ui->comboBox->currentIndex();

```

就可以得到对应的是第几个选项

使用insertItem可以在某个位置加入一个选项

```cpp
ui->comboBox->insertItem(3,QIcon(""),"a")
```

