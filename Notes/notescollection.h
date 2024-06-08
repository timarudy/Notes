#pragma once

#include <Note.h>
#include <QTextDocument>

struct Note;


class NotesCollection
{
public:
    NotesCollection();

    std::unordered_map<int, std::pair<Note, std::unique_ptr<QTextDocument>>> notes;
};
