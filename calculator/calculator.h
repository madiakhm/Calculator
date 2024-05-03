#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "muParser.h"

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);

private slots:
    void calculateResult();
    void buttonClicked();

private:
    void createButton(const QString &text, QGridLayout *layout, int row, int column);

    QLabel *display;
};


