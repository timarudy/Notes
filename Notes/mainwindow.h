#pragma once

#include <QWidget>

#include "noteslistwidget.h"
#include "note.h"
#include "notesmanager.h"

#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Note;
class NotesManager;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(NotesManager& manager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewNoteBtnClicked();
    void onRemoveNoteBtnClicked();

    void onNewNodeCreated(int id);
    void onNoteContentChanged(int id);

    void onSelectedNoteChanged(int id);
    void onRemoveNote(int id);


private:
    void addNoteToList(const Note& note);
    void removeNote(int id);

    void init();

    void makeConnections();

    Ui::MainWindow *ui;
    NotesManager& notesManager;
};
