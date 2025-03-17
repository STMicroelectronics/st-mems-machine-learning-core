## 1 - Introduction

This Machine Learning Core (MLC) example implements Tennis activity algorithm which is able to detect and classify different tennis shots (forehand, backhand, slice-forehand, slice-backhand, serve).

A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [examples](../../) folder.

For information on how to create similar algorithms, please follow the instructions provided in the [tutorials](../../../tutorials) folder.

## 2 - Sensor configuration and orientation

The low-g accelerometer is configured with ±16 *g* full-scale and 480 Hz output data rate.

The high-g accelerometer is configured with ±80 *g* full-scale and 480 Hz output data rate.

The gyroscope is configured with 2000 *dps* full-scale and 480 Hz output data rate.

The sensor orientation for this algorithm is ENU

* X parallel to the arm
* Y perpendicular to the arm
* Z pointing up

## 3 - Machine Learning Core and Finite State Machine configuration

The MLC procsses the accelerometer and gyroscope data at 480 Hz:

* The MLC processes the accelerometer and gyroscope data in order to detect the tennis shot by using multiple features like (mean, minimum, variance, etc. on both accelerometer and gyroscope data of all 3 axes), computed every 240 samples (corresponding to 0.5 seconds).

  One decision tree with Eleven nodes has been configured to detect the different classes.

  The output of the MLC can be read from the MLC0_SRC (70h) register:
  * 00h = No Shot
  * 02h = Forehand
  * 04h = Backhand
  * 06h = Slice-forehand
  * 08h = Slice-backhand
  * 0Ch = Serve

The overall current consumption is about 885 µA.

## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value (when the state detected by the MLC changes). The duration of the interrupt pulse is 2.08 ms in this configuration.

------

**Copyright © 2025 STMicroelectronics**

