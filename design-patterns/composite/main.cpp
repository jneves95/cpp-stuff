#include "song_group.h"
#include "song.h"
#include "player.h"

using namespace std;

int main() {
    SongGroup playlist("Playlist", "multiple genres");

    SongGroup rockMusic("Rock", "broad genre of popular music that originated as \"rock and roll\" in the United States in the late 1940s and early 1950s");
    SongGroup dubstep("Dubstep", "electronic dance music that originated in South London in the late 1990s");
    SongGroup rnb("Rhythm and blues", "often abbreviated as R&B, is a genre of popular music that originated in African-American communities in the 1940s");

    SongGroup pinkFloyd("Pink Floyd", "English rock band formed in London in 1965");
    SongGroup album("Dark Side of the Moon", "1973, 8th studio album");
    Song song1("Speak to Me", "Pink Floyd", 1973);
    Song song2("Breathe", "Pink Floyd", 1973);
    Song song3("On the Run", "Pink Floyd", 1973);
    Song song4("Time", "Pink Floyd", 1973);

    album.add(song1);
    album.add(song2);
    album.add(song3);
    album.add(song4);

    SongComponent* x = album.get(2);
    x->displaySongInfo();

    album.remove(2);

    pinkFloyd.add(album);

    rockMusic.add(pinkFloyd);

    playlist.add(rockMusic);
    playlist.add(dubstep);
    playlist.add(rnb);

    Player player(playlist);
    player.getSongList();
}