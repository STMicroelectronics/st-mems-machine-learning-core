## 1 - Introduction

Sleep detection is intended as a example for a wearable device, like a smartwatch or a wristband.

To implement this algorithm with a decision tree, all the data logs have been acquired using the device (LSM6DSOX) mounted on a wristband on the left hand (or right hand). A limited subset of data logs for the case "left hand" is available [here](./datalogs/).

The classes detected in this example are two: awake and asleep.

For information on how to integrate this algorithm in the target platform, please follow the instructions available in the README file of the [examples](../../) folder.

For information on how to create similar algorithms, please follow the instructions provided in the [tutorials](../../../tutorials) folder.

## 2 - Sensor configuration and orientation

The accelerometer is configured with ±8 *g* full scale, 12.5 Hz output data rate, low power mode.

The sensor orientation for this algorithm is ENU
- X parallel to the arm
- Y perpendicular to the arm
- Z pointing up

## 3 - Machine Learning Core configuration

The features used for the classification are the peak-to-peak values on the three accelerometer axes.

The MLC runs at 12.5 Hz, computing features on windows of 255 samples (corresponding to about 20 seconds).

One decision tree with around 4 nodes has been configured to detect the different classes.

A metaclassifier value of 14 is set for both classes.

- MLC0_SRC (70h) register values
  - 0 = Awake
  - 4 = Asleep

## 4 - Interrupts

The configuration generates an interrupt (pulsed and active high) on the INT1 pin every time the register MLC0_SRC (70h) is updated with a new value. The duration of the interrupt pulse is 80 ms in this configuration.

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2026 STMicroelectronics**
