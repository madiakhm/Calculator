#include "calculator.h"
#include "muParser.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);

    display = new QLabel("0");
    display->setAlignment(Qt::AlignRight);
    layout->addWidget(display, 0, 0, 1, 6);

    // Create buttons
    QStringList buttons {"7", "8", "9", "/", "(", "C",
                        "4", "5", "6", "*", ")",
                        "3", "2", "1", "-",
                        "0", ".", "=", "+"};

    int row = 1;
    int column = 0;
    for (const QString &text : buttons) {
        createButton(text, layout, row, column);
        if (++column > 4) {
            column = 0;
            ++row;
        }
    }

    setLayout(layout);
    this->setStyleSheet("background-color: pink;");
}

void Calculator::calculateResult() {
    mu::Parser parser;
    parser.SetExpr(display->text().toStdString());
    try {
        double result = parser.Eval();
        display->setText(QString::number(result));
    } catch (mu::Parser::exception_type &e) {
        display->setText(QString("Error: %1").arg(e.GetMsg().c_str()));
    }
}

void Calculator::buttonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString text = button->text();
        if (text == "=") {
            calculateResult();
        } else if (text == "C") {
            display->setText("0");
        } else {
            if (display->text() == "0" && text != "." && text != "(") {
                display->setText(text);
            } else {
                display->setText(display->text() + text);
            }
        }
    }
}

void Calculator::createButton(const QString &text, QGridLayout *layout, int row, int column) {
    QPushButton *button = new QPushButton(text);
    layout->addWidget(button, row, column);
    connect(button, &QPushButton::clicked, this, &Calculator::buttonClicked);
}
