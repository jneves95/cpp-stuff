#pragma once

#include <string>

class SongComponent {
public:
    SongComponent() {}
    ~SongComponent() {}

    virtual void add(SongComponent& component) { throw "Unsupported operation."; }
    virtual void remove(int index) { throw "Unsupported operation."; }
    virtual SongComponent* get(int index) { throw "Unsupported operation."; }
    virtual std::string getSongName() { throw "Unsupported operation."; }
    virtual std::string getBandName() { throw "Unsupported operation."; }
    virtual int getReleaseYear() { throw "Unsupported operation."; }
    virtual void displaySongInfo() { throw "Unsupported operation."; }
};