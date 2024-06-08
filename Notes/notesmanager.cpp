#include "notesmanager.h"
#include "note.h"

#include <QTextDocument>
#include <QSignalMapper>

int nextNodeId();

NotesManager::NotesManager(QObject *parent)
{
    mapChangedSignalToNoteId = new QSignalMapper(this);
    connect(mapChangedSignalToNoteId, &QSignalMapper::mappedInt,
        this,
        &NotesManager::onNoteContentChanged);

    readNotes();

    if (notes.size() == 0)
        createNewNote();
}

NotesManager::~NotesManager()
{
    writeNotes();
}

void NotesManager::createNewNote()
{
    int id = nextNodeId();
    auto& [note, textDocument] = notes[id];
    note.id = id;
    note.title = QString("Node %0").arg(id);
    note.lastModified = QDateTime::currentDateTime();
    textDocument = createNewTextDocument(note);

    emit newNoteCreated(id);
}

void NotesManager::removeNote(int id)
{
    notes.erase(id);

    if(notes.empty())
        createNewNote();
}

void NotesManager::renameNote(int id, const QString &newTitle)
{
    // Do later
    Q_UNUSED(id);
    Q_UNUSED(newTitle);
}

const Note &NotesManager::note(int id) const
{
    return notes.at(id).first;
}

QTextDocument *NotesManager::noteDocument(int id) const
{
    auto found = notes.find(id);
    if(found != notes.end())
    {
        return found->second.second.get();
    }

    return nullptr;
}

void NotesManager::onNoteContentChanged(int id)
{
    notes.at(id).first.lastModified = QDateTime::currentDateTime();

    emit noteContentChanged(id);
}

void NotesManager::readNotes()
{
    // Do later
}

void NotesManager::writeNotes()
{
    // Do later
}

std::unique_ptr<QTextDocument> NotesManager::createNewTextDocument(const Note &note)
{
    auto textDocument = std::make_unique<QTextDocument>(note.content);
    connect(textDocument.get(), &QTextDocument::contentsChanged,
            mapChangedSignalToNoteId, qOverload<>(&QSignalMapper::map));
    mapChangedSignalToNoteId->setMapping(textDocument.get(), note.id);

    return textDocument;
}

std::vector<std::reference_wrapper<Note>> NotesManager::noteCollection()
{
    std::vector<std::reference_wrapper<Note>> out;
    for (auto& i : notes) {
        auto& [note, textDocument] = i.second;
        note.content = textDocument->toPlainText();
        out.push_back(note);
    }
    return out;
}

size_t NotesManager::count() const
{
    return notes.size();
}

int nextNodeId()
{
    static int id = 0;
    return ++id;
}
