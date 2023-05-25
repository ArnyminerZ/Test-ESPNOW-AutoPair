/**
 * Utility functions for printing and data handling.
 * @file utils.h
 */

#ifndef __UTILS_H
#define __UTILS_H

#include <Arduino.h>

/**
 * Prints the given MAC address to the Serial output.
 * Uses the format: XX:XX:XX:XX:XX:XX
 * @param mac_addr The MAC address to print.
 */
void printMAC(const uint8_t * mac_addr){
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
}

#endif
