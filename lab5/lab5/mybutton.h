#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>

class MyButton : public QObject
{
    Q_OBJECT
public:
    explicit MyButton(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYBUTTON_H