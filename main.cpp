#include "Playlist.h"
#include <iostream>
#include <string>

using namespace std;
char userInput = ' ';
string userUniqueID = " ";
string userSongName = " ";
string userArtistName = " ";
int userSongLength = 0;
int newSongPosition = 0;
int currSongPosition = 0;
int count = 0;
PlaylistNode playList;
PlaylistNode *headPtr = nullptr;
PlaylistNode *tailPtr = nullptr;
PlaylistNode *currNode = nullptr;
PlaylistNode *temp = nullptr;
 string PlaylistName = " ";
//declares the PrintMenu function
void PrintMenu(string);

int main() {
 
  cout << "Enter playlist's title:" << endl;
  getline(cin, PlaylistName);
  cout << endl;
  PrintMenu(PlaylistName);
  return 0;
}

void PrintMenu(string title) {
  do {
    userInput = ' ';
    // checks for a valid input otherwises asks user for a valid input
      cout << title << " PLAYLIST MENU" << endl;
      cout << "a - Add song" << endl;
      cout << "d - Remove song" << endl;
      cout << "c - Change position of song" << endl;
      cout << "s - Output songs by specific artist" << endl;
      cout << "t - Output total time of playlist (in seconds)" << endl;
      cout << "o - Output full playlist" << endl;
      cout << "q - Quit" << endl << endl;
      cout << "Choose an option:";
      cin >> userInput;
      cout << endl;
      // used with getline to ignore the new line character
      cin.ignore();
   
    // If the menu option is "a", adds songs to playlist
    switch (userInput) {
    case 'a': {
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:";
      getline(cin, userUniqueID);
      cout << endl;
      cout << "Enter song's name:";
      getline(cin, userSongName);
      cout << endl;
      cout << "Enter artist's name:";
      getline(cin, userArtistName);
      cout << endl;
      cout << "Enter song's length (in seconds):";
      cin >> userSongLength;
      cout << endl << endl;

      currNode = new PlaylistNode(userUniqueID, userSongName, userArtistName, userSongLength);//creates a node in the linkedlist that holds the current info

      // adds the song by assigning the new song to the tailPtr which is assigned to the temp
      if (headPtr != nullptr) {
        temp = tailPtr;
        tailPtr = currNode;
        temp->SetNext(currNode);
      }
      // sets headPtr to the new song added and the tailPtr since the list is empty
      else {
        headPtr = currNode;
        tailPtr = currNode;
      }
      break;
    }
      // If the menu option is "d", removes songs to playlist
    case 'd': {
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:";
      getline(cin, userUniqueID);
      cout << endl;

      PlaylistNode *currNode = headPtr;
      // stores the input song into a temperary pointer
      temp = currNode;
      do {
        if (currNode->GetID() == userUniqueID) {
          userSongName = currNode->GetSongName();
          if (headPtr == currNode) {
            // checking to see if it is the only thing in this list
            if (headPtr == tailPtr) {
              tailPtr = nullptr;
            }
            // assigns new song to temp
            temp = headPtr;
            headPtr = currNode->GetNext();
            // deletes currNode
            delete temp;
            currNode = headPtr;
            temp = currNode;
          } else {
            if (tailPtr == currNode) {
              tailPtr = temp;
            }
            temp->SetNext(currNode->GetNext());
            delete currNode;
            currNode = temp;
            currNode = currNode->GetNext();
          }
          cout << "\"" << userSongName << "\" removed." << endl << endl;
        } else {
          temp = currNode;
          currNode = currNode->GetNext();
        }
      } while (currNode);
      break;
    }
      // If the menu option is "c", changes position of song
      // got help from the internet for option c
    case 'c': {
      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:";
      cin >> currSongPosition;
      cout << endl;
      currNode = headPtr;
      temp = headPtr;
      count = 1;

      while (count < currSongPosition) {
        temp = currNode;
        currNode = currNode->GetNext();
        count ++;
      }
      userSongName = currNode->GetSongName();

      //headPtr position
      //Moving Head Node
      if (headPtr == currNode) {
        headPtr = currNode->GetNext();
      }

      // Moving Tail Node
      else if (tailPtr == currNode) {
        temp->SetNext(tailPtr->GetNext());
        tailPtr = temp;
      }

      else {
        temp->SetNext(currNode->GetNext());
      }
      cout << "Enter new position for song:";
      cin >> newSongPosition;
      cout << endl;
      temp = headPtr;
      count = 2;

      //setting the current song position to the next position
      while (count < newSongPosition) {
        temp = temp->GetNext();
        count++;
      }
      // Moving a Node to the Head
      if (newSongPosition <= 1) {
        currNode->SetNext(headPtr);
        headPtr = currNode;
      }

      //Moving a node down the list
      else if (newSongPosition > (currSongPosition - 1)) {
        tailPtr = currNode;
        temp->InsertAfter(currNode);
      }
      else {
        temp->InsertAfter(currNode);
      }

      //outputs the new position of the song
      cout << "\"" << userSongName << "\" moved to position " << newSongPosition
           << endl
           << endl;
      break;
    }
      
    // If the menu option is "s", outputs songs by artist
    case 's': {
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:";
      getline(cin, userArtistName);
      cout << endl << endl;
      currNode = headPtr;
      count = 1;

      while (currNode) {
        if (currNode->GetArtistName() == userArtistName) {
          cout << count << '.' << endl;
          playList.PrintPlaylistNode(currNode);
        }

        currNode = currNode->GetNext();
        count++;
      }
      break;
    }
      // If the menu option is "t", outputs the total time of the playlist in seconds
    case 't': {
      PlaylistNode *currNode = headPtr;
      userSongLength = 0;
      while (currNode) {
        userSongLength += currNode->GetSongLength();
        currNode = currNode->GetNext();
      }
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      cout << "Total time: " << userSongLength << " seconds" << endl << endl;
      break;
    }
      // If the menu option is "0", outputs the full playlist
      // If the playlist is empty then headPtr == nullptr so the output is playlist is empty
    case 'o': {
      cout << title << " - OUTPUT FULL PLAYLIST" << endl;
      if (headPtr != nullptr) {
        PlaylistNode *currNode = headPtr;
        count = 1;
        while (currNode) {
          cout << count << '.' << endl;
          playList.PrintPlaylistNode(currNode);
          currNode = currNode->GetNext();
          count++;
        }
      }
      else {
        cout << "Playlist is empty" << endl << endl;
      }
      break;
    }
    default : {
      break;
    }
  }
  } while (userInput != 'q');
  return;
}