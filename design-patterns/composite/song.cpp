#include "song.h"
#include <iostream>

void Song::displaySongInfo() {
    std::cout << getSongName() << " was recorded by " << getBandName() << " in " << getReleaseYear() << std::endl;
}