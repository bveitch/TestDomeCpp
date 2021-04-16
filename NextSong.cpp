#include <stdexcept>
#include <iostream>
#include <unordered_set>

class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        std::unordered_set<std::string> set;
        set.emplace(name);
        Song* nextsong = this->nextSong;
        while(nextsong){
            auto nextname=nextsong->name;
            auto got=set.find(nextname);
            if(got!=set.end()) return true;
            set.emplace(nextsong->name);
            nextsong=nextsong->nextSong;
        }
        return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Dog");
    Song* third = new Song("Time");
    Song* fourth = new Song("Eye of the tiger");
    
    first->next(second);
    second->next(third);
    third->next(fourth);
    fourth->next(second);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif
//this =100%