#include "Playlist.h"
#include <iostream>
#include <string>

//default constructor
PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr){}

//parametrized constructor 
PlaylistNode::PlaylistNode(string id, string name, string artist, int length) {
    uniqueID = id;
    songName = name;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
 }

// Inserts a new node after the current one
void PlaylistNode::InsertAfter(PlaylistNode* currData) {
      // Create a new node and set its data
    PlaylistNode* temp = nullptr;
    temp = nextNodePtr;
    nextNodePtr = currData;

    // Set the next pointer of the new node to point to the current next node
    currData->SetNext(temp);
    return;
}

//mutator 
// Sets the next node pointer
void PlaylistNode::SetNext(PlaylistNode* next) {
    nextNodePtr = next;
    return;
}

//accessor
string PlaylistNode::GetID() const {
    return uniqueID;
}

//accessor
string PlaylistNode::GetSongName() const {
    return songName;
}

//accessor
string PlaylistNode::GetArtistName() const {
    return artistName;
}

//accessor
int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(PlaylistNode *nextData) const {
    cout << "Unique ID: " << nextData->GetID() << endl;
    cout << "Song Name: " << nextData->GetSongName() << endl;
    cout << "Artist Name: " << nextData->GetArtistName() << endl;
    cout << "Song Length (in seconds): " << nextData->GetSongLength() << endl << endl;
    return;
}
