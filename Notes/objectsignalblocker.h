#pragma once

#include <QObject>

class ObjectSignalBlocker
{
private:
    QObject* _object;

public:
    ObjectSignalBlocker(QObject& obj);
    ~ObjectSignalBlocker();
};
