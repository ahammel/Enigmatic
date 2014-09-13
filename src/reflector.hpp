#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <map>

// The reflecting rotor of an Enigma machine.
//
// Provides the `reflect` method, which returns a character which can then be
// passed back through the rotors. This is equivalent to a simple, static
// substitution cipher. The reflector is never incrememnted and therefore has
// no position.
//
// The `Reflector_*` class methods return Reflectors corresponding to the three
// used by the Kriegsmarine.
class Reflector
{
private:
  std::map<char,char> wiring;
public:
  Reflector() { };
  Reflector(std::map<char,char> wiring_diagram) {
    wiring = wiring_diagram;
  };

  char reflect(char);

  static Reflector Reflector_A();
  static Reflector Reflector_B();
  static Reflector Reflector_C();
};

#endif
