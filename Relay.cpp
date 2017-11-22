#include "Relay.h"

Relay::Relay(gpio_num_t pin, bool inverted)
:
_PIN(pin),
_INVERTED(inverted)
{
  pinMode(_PIN,OUTPUT); 
}

void Relay::_switch(const bool state) {

  // Enforce a switch delay so that bad code cant flutter the relay
  if( abs(millis() - _cooldownTimer ) < _cooldown_ms){
    return;
  }

  const bool RAW_STATE = state ^ _INVERTED;
  digitalWrite(_PIN, RAW_STATE);
  
  _on = state;
  _cooldownTimer = millis();

}

void Relay::toggle() {
  _on ? off() : on();
}

Relay &Relay::cooldown(unsigned long ms){
  _cooldown_ms = ms;
  return *this;
}