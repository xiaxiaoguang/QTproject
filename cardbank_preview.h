#ifndef CARDBANK_PREVIEW_H
#define CARDBANK_PREVIEW_H

#include <QDialog>

namespace Ui {
class cardbank_preview;
}

class cardbank_preview : public QDialog
{
    Q_OBJECT

public:
    explicit cardbank_preview(QWidget *parent = nullptr);
    ~cardbank_preview();

private:
    Ui::cardbank_preview *ui;
};

#endif // CARDBANK_PREVIEW_H
