/**
 * Relay.h
 * Scott Chase Waggener
 * 11/21/17
 * 
 * Provides relay control for ESP8266 on Arduino framework
 */

#ifndef SORELAY_H
#define SORELAY_H

#include "Arduino.h"

typedef uint8_t gpio_num_t;

class Relay {
  public:

    /**
     * @brief Sets up the given GPIO
     * 
     * @param pin The GPIO that this relay will be attached to
     * 
     */
    Relay(gpio_num_t pin, bool inverted = false);


    /**
     * @return The GPIO to which this relay is attached
     */
    const gpio_num_t pin() const { return _PIN; }

    /**
     * @brief Gets the current state of the relay
     * 
     * @return
     *   - true if the relay is on
     *   - false otherwise
     */
    const bool isOn() {return _on;}

   
    /**
     * @brief Sets the minimum interval in milliseconds between
     * changes of relay state. This helps prevent very rapid relay
     * switching
     * 
     * @param ms The interval in milliseconds
     * 
     * @return this
     */
    Relay &cooldown(unsigned long ms);
    const unsigned long cooldown() { return _cooldown_ms; }

    /**
     * @brief Turns the relay on
     * 
     */
    void on() { _switch(true); }

    /**
     * @brief Turns the relay off
     * 
     */
    void off() { _switch(false); }

    /**
     * @brief Toggles the state of the relay
     * 
     */
    void toggle();


  private:

    const gpio_num_t _PIN;
    const bool _INVERTED;
    bool _on;

    unsigned long _cooldown_ms;
    unsigned long _cooldownTimer = 0;

    /**
     * @brief Helper function to handle switching states
     * 
     * @param state True for switching on, false for switching off
     * 
     */
    void _switch(const bool state);

};

#endif
