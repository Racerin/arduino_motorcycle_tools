#include <Arduino.h>
#include <voltmeter.h>

Voltmeter vm(A0);

void setup() {
  // put your setup code here, to run once:
  vm.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  vm.update();
}