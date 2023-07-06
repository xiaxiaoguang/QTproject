void updateUI(QLabel* label_3, QLabel* label_4, int cardtype, int number) {
	//label_3,label_4分别是fightinterface的图片和信息的显示控件,与ui中名称相同
    // 设置图片路径
    //cardtype:怪兽为0,魔法为1,额外为2
    //number:卡牌序号
    QString imagePath = QString(":/card/%1/%2.jpg").arg(cardtype).arg(number);
    QPixmap pixmap(imagePath);

    // 替换 label_3 的背景为卡牌图片
    label_3->setPixmap(pixmap);

    // 读取文本信息
    QString textPath = QString(":/card/%1/%2.txt").arg(cardtype).arg(number);
    QFile file(textPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString text = in.readAll();

        // 显示文本信息在 label_4
        label_4->setText(text);

        file.close();
    } else {
        // 如果无法打开文本文件，则在 label_4 中显示错误消息
        label_4->setText("Error: Unable to load text information");
    }
    return;
}

