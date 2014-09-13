#ifndef STECKERBRETT_H
#define STECKERBRETT_H

#include <map>
#include <string>

// The plugboard of an Enigma machine ('Steckerbrett' in German).
//
// The Steckerbrett is the simplest scrambling stage. It consists of a set of
// pairs of letters. If the input is one of the pairs that are partnered, the
// output is the other.
//
// `scramble` runs a character through the Steckerbrett. `add_stecker` adds a
// pair of characters to the board. `is_steckered` returns true if the value is
// plugged.
class Steckerbrett
{
private:
  std::map<char, char> board;

public:
  Steckerbrett() { };

  char scramble(char);
  void add_stecker(char, char);
  bool is_steckered(char);
};

#endif
