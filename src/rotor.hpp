#ifndef _ROTOR_H_
#define _ROTOR_H_

#include <boost/bimap.hpp>

typedef boost::bimap<char, char> char_bimap;

// An Enigma machine rotor simulator.
//
// Provides the `scramble` methods, which encode a single character to another
// by a simple alphabetic substitution. `scramble_left` is called when the signal
// is on the way to the reflector and `scramble_right (the inverse) is called when
// the signal is on the way back to the lampboard.
//
// The `Rotor_*` class methods return rotor instances corresponding to the five
// rotors used in the Kriegsmarine three-rotor Enigma.
class Rotor
{
private:
  char position;
  std::string notches;
  char_bimap wiring;
  char ring_setting;

public:
  Rotor() { };
  Rotor(char_bimap  wiring_diagram,
        std::string notch_positions,
        char        initial_position,
        char        initial_ring_setting) {
    wiring = wiring_diagram;
    notches = notch_positions;
    position = initial_position;
    ring_setting = initial_ring_setting;
  };

  // Getters and setters
  void set_position(char c) { position = c; };
  char get_position()       { return position; };

  std::string get_notches() { return notches; }

  // Scrambling functions
  char scramble_left(char);
  char scramble_right(char);

  // Pre-configured rotors
  static Rotor Rotor_I();
  static Rotor Rotor_II();
  static Rotor Rotor_III();
  static Rotor Rotor_IV();
  static Rotor Rotor_V();
};

#endif
