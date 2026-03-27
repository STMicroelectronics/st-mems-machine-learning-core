## 1 - Introduction

This Machine Learning Core (MLC) example implements a classification algorithm that can detect different states of a nail gun: stationary, in use, and nailing.

A limited subset of data logs for this example is available [here](./datalogs/).

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [examples](../../) folder.

For information on how to create similar algorithms, please follow the instructions provided in the [tutorials](../../../tutorials) folder.

## 2 - Sensor configuration and orientation

The low-g accelerometer is configured with ±16 *g* full-scale and 960 Hz output data rate.

The high-g accelerometer is configured with ±320 *g* full-scale and 960 Hz output data rate.

Any sensor orientation is allowed for this algorithm.

## 3 - Machine Learning Core and Finite State Machine configuration

A high-pass filter has been applied to the low-g accelerometer input data, and two features have been used (variance of the filtered low-g accelerometer norm and peak-to-peak of the high-g accelerometer norm).

The MLC runs at 960 Hz, computing features on windows of 100 samples (corresponding to approximately 0.104 seconds).

One decision tree with 2 nodes has been configured to detect the different classes. A meta-classifier has been set to reduce false positives.

- MLC1_SRC (70h) register values
  - 0 = Unknown
  - 1 = Stationary
  - 4 = In use
  - 8 = Nailing

## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC1_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 1.04 ms in this configuration.

------

**Copyright © 2026 STMicroelectronics**
