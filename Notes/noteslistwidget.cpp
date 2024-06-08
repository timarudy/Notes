#include "noteslistwidget.h"
#include "ui_noteslistwidget.h"

#include "note.h"
#include "objectsignalblocker.h"

NotesListWidget::NotesListWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NotesListWidget)
{
    ui->setupUi(this);

    setStyleSheet("background-color: white;");

    connect(ui->listWidget, &QListWidget::itemSelectionChanged,
            this, &NotesListWidget::onItemSelectionChanged);
}

NotesListWidget::~NotesListWidget()
{
    delete ui;
}

void NotesListWidget::addNote(const Note &note)
{
    auto* item = new QListWidgetItem();
    ui->listWidget->insertItem(0, item);

    setupNote(note, item);
}

void NotesListWidget::removeCurrentNote()
{
    auto* currentItem = ui->listWidget->currentItem();

    if(currentItem)
        delete currentItem;
}

void NotesListWidget::updateCurrentNote(const Note &note)
{
    if(ui->listWidget->currentRow() != 0)
        moveCurrentItemToTop(note);
}

int NotesListWidget::currentNoteId()
{
    auto* currentItem = ui->listWidget->currentItem();
    int noteId = currentItem->data(Qt::UserRole).toInt();
    return noteId;
}

void NotesListWidget::onItemSelectionChanged()
{
    auto* currentItem = ui->listWidget->currentItem();
    if(currentItem)
    {
        int id = currentNoteId();

        emit selectedNoteChanged(id);
    }
}

void NotesListWidget::moveCurrentItemToTop(const Note &note)
{
    ObjectSignalBlocker blocker{*this};

    auto* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    ui->listWidget->insertItem(0, item);
    setupNote(note, item);
}

void NotesListWidget::setupNote(const Note& note, QListWidgetItem *item)
{
    item->setText(note.title);
    item->setData(Qt::UserRole, note.id);
    ui->listWidget->setCurrentItem(item);
}
