#ifndef _ENIGMA_H_
#define _ENIGMA_H_

#include <string>
#include <array>

#include "rotor.hpp"
#include "reflector.hpp"
#include "steckerbrett.hpp"

typedef std::array<Rotor, 3> RotorSet;

// A three-rotor Engima simulator.
//
// Provides the `encode` method, which takes a message string and returns the
// encrypted message given the current state of the machine.
//
// The constructor arguments specify the inital state of the machine.
class Enigma
{
private:
  Rotor rotor_1, rotor_2, rotor_3;
  Reflector reflector;
  Steckerbrett steckerbrett;

  void increment_rotors();

public:
  Enigma() { };
  Enigma(RotorSet rotors, Reflector reflecting_rotor, Steckerbrett plugboard) {
    rotor_1 = rotors.at(0);
    rotor_2 = rotors.at(1);
    rotor_3 = rotors.at(2);
    reflector = reflecting_rotor;
    steckerbrett = plugboard;
  };

  std::string encode(std::string message);
  char encode_letter(char);
};

#endif
