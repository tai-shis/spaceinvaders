/**
    * @file psg.h
    * @brief Header file for psg.c
    * @date 2025-03-23
    * @details Contains functions for writing to the PSG registers. Handles out of bounds checks and does not modify if any inputs are invalid.
 */

 #ifndef PSG_H
 #define PSG_H
 
 #include "TYPES.H"
 
 /**
  * @brief Writes a value to a PSG register.
  * @param reg The register to write to.
  * @param val The value to write.
  */
 void write_psg(int reg, UINT8 val);
 
 /**
  * @brief Sets the tone for a specific channel.
  * @param channel The channel to set the tone for.
  * @param tuning The tuning value for the tone.
  */
 void set_tone(int channel, int tuning);
 
 /**
  * @brief Sets the volume for a specific channel.
  * @param channel The channel to set the volume for.
  * @param volume The volume level to set.
  */
 void set_volume(int channel, int volume);
 
 /**
  * @brief Enables or disables tone and noise for a specific channel.
  * @param channel The channel to configure.
  * @param tone_on One to enable tone, zero to disable.
  * @param noise_on One to enable noise, zero to disable.
  */
 void enable_channel(int channel, int tone_on, int noise_on);
 
 /**
  * @brief Stops all sound output.
  */
 void stop_sound();
 
 /**
  * @brief Sets the noise tuning value.
  * @param tuning The tuning value for the noise.
  */
 void set_noise(UINT8 tuning);
 
 /**
  * @brief Sets the envelope shape and sustain value.
  * @param shape The shape of the envelope.
  * @param sustain The sustain value for the envelope.
  */
 void set_envelope(UINT8 shape, UINT16 sustain);
 
 /**
  * @brief Reads a value from a PSG register.
  * @param reg The register to read from.
  * @return The value read from the register.
  */
 UINT8 read_psg(int reg);
 
 #endif