#include "objectsignalblocker.h"

ObjectSignalBlocker::ObjectSignalBlocker(QObject& obj) {
    _object = &obj;
    _object->blockSignals(true);
}

ObjectSignalBlocker::~ObjectSignalBlocker()
{
    _object->blockSignals(false);
}
