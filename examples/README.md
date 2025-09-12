# Examples

This folder contains ready-to-use examples for MEMS devices embedding the machine learning core (MLC).

Each folder is dedicated to a specific example and contains a `README.md` file with general information about that example and a set of sub-folders with the configuration for each of the supported MEMS sensors. Each sensor sub-folder contains:
- A `README.md` file, with information about the specific configuration.
- A `.json` file, containing the device configuration generated with STMicroelectronics tools. This file can be used to load the MLC program and sensor configuration into the sensor. For this purpose, different hardware tools provided by ST can be used ([STEVAL-MKI109D](https://www.st.com/en/evaluation-tools/steval-mki109d.html), [STM32 Nucleo](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards.html),  [SensorTile.box PRO](https://www.st.com/en/evaluation-tools/steval-mkboxpro.html), etc.).
- A `.h` file, containing the same information as the `.json` file, but in the format of a C header file. Examples of `.h` file integration in C projects are available in the [platform independent drivers repository](http://www.st.com/content/st_com/en/products/embedded-software/mems-and-sensors-software/drivers-for-mems/c-driver-mems.html) for STMicroelectronics MEMS sensors.

## How to use the JSON configuration files to run the examples

### Run the example with Professional MEMS tool board and MEMS Studio

To test an MLC example in [MEMS Studio](https://www.st.com/en/development-tools/mems-studio.html), the `.json` file has to be loaded as described in the following steps:

1. Download the latest version of MEMS Studio (if not already installed).
2. Plug the DIL24 adapter of the specific sensor to the Professional MEMS board.
3. Plug the Professional MEMS board to the PC with a USB cable.
    - If necessary, upgrade the firmware of your board using the `Firmware Programming` functionality embedded in MEMS Studio.
4. Open MEMS Studio and select the desired device (choose the COM port and the used sensor).
5. Go to `Sensor Evaluation`, `Load/Save Configuration` and load the `.json` configuration file.
6. Once the device has been configured, press the `▶` button in the top left corner to start streaming data from the sensor and visualize the MLC results in the `MLC Monitor` or `Data Monitor` views.

### Run the example with STM32 Nucleo board and MEMS Studio

MEMS Studio can work with Nucleo boards coupled with X-NUCLEO expansion boards (for example, X-NUCLEO-IKS4A1). Optionally, the DIL24 adapter of a sensor can be plugged on top of the X-NUCLEO expansion board. Do not plug a DIL24 adapter if it hosts a sensor with the same I2C address of one of the sensors host by the X-NUCLEO board, as a clash of addresses may cause problems.

To run an MLC example in MEMS Studio, the `.json` file has to be loaded as described in the following steps:

1. Download the latest version of MEMS Studio (if not already installed).
2. Download the latest version of [X-CUBE-MEMS1](https://www.st.com/en/embedded-software/x-cube-mems1.html).
3. Plug the X-NUCLEO expansion board on top of the Nucleo board.
4. Optionally plug the DIL24 adapter hosting a sensor with MLC in the DIL24 socket of the expansion board.
5. Plug the Nucleo board to the PC with a USB cable.
6. The Nucleo board has to be programmed with the DataLogExtended firmware from the X-CUBE-MEMS1 package (if not already programmed).
    - Locate the *DatalogExtended.bin* file in the X-CUBE-MEMS1 package under *Projects*, *STM32xxxxxx-Nucleo*, *Examples*, *IKSxxxx*, *DataLogExtended*, *Binary*.
    - Copy the *DatalogExtended.bin* file to the disk drive associated with the Nucleo board to flash the firmware.
7. Open MEMS Studio, connect to the Nucleo board, and select the desired sensors.
8. Go to `Sensor Evaluation`, `Load/Save Configuration` and load the `.json` configuration file.
9. Once the device has been configured, press the `▶` button in the top left corner to start streaming data from the sensor and visualize the MLC results in the `MLC Monitor` or `Data Monitor` views.

### Run the example with SensorTile.box PRO / STWIN.box and ST BLE Sensor application

The SensorTile.box PRO / STWIN.box board and the [ST BLE Sensor](https://www.st.com/en/embedded-software/stblesensor.html) application offer a wireless method to test an MLC example.

1. Download the latest version of the ST BLE Sensor application (if not already installed).
2. Download the latest version of [FP-SNS-DATALOG2](https://www.st.com/en/embedded-software/fp-sns-datalog2.html).
3. Connect the SensorTile.box PRO / STWIN.box board to the device via Bluetooth.
4. The SensorTile.box PRO has to be programmed with the DATALOG2 firmware from the FP-SNS-DATALOG2 package (if not already programmed).
    - Go to `Firmware Update` in the `settings` of the ST BLE Sensor application.
    - Choose the *DATALOG2_Release.bin* binary file and click on the `Upgrade` button.
5. Go to `HighSpeed DataLog2` and find the MLC (LSM6DSV16X) sensor.
6. Choose the MLC *.json* file and upload it to the SensorTile.box PRO.
7. Press the `▶ Start` button.
8. Go to `Machine Learning Core` and see the live results.

### Run the example with SensorTile.box PRO / STWIN.box and ST AIoT Craft

[ST AIoT Craft](https://staiotcraft.st.com) allows user to import a `.json` configuration file or use one of the already available examples.

1. Open the ST AIoT Craft webpage.
2. Plug the SensorTile.box PRO / STWIN.box to the PC with a USB cable.
3. The SensorTile.box PRO / STWIN.box has to be programmed with the DATALOG2 firmware.
    - While pairing your device click on `Update the firmware` link.
    - Choose whether you want to flash from PC or mobile app, and follow the steps.
    - Finally click on the `Flash firmware` button.
4. Choose an example from the offer or import your own configuration.
    - Example from the offer
        - Choose an example from `Project Examples` and click on the `Try out` button.
        - Select environment.
        - Connect the device.
        - Press the `Start` button to see the live results.
    - Importing your own configuration
        - Go to `My datasets` and create a new dataset. Choose name and insert the classes corresponding with the `.json` file configuration.
        - Open the dataset.
        - Go to `Log data from board`.
        - Connect the device.
        - In `Sensor Settings` find the `MLC` tab and click on `Upload JSON`.
        - Select the desired `.json` file and upload it.
        - Select mode `Monitoring`.
        - Finally click on the `Start` button and see the live results.

## Examples per device

* ASM330LHB
	* [tow_detection](./tow_detection/asm330lhb)
	* [vehicle_stationary_detection](./vehicle_stationary_detection/asm330lhb)
* ASM330LHBG1
	* [tow_detection](./tow_detection/asm330lhbg1)
	* [vehicle_stationary_detection](./vehicle_stationary_detection/asm330lhbg1)
* ASM330LHHX
	* [tow_detection](./tow_detection/asm330lhhx)
	* [vehicle_stationary_detection](./vehicle_stationary_detection/asm330lhhx)
* ASM330LHHXG1
	* [tow_detection](./tow_detection/asm330lhhxg1)
	* [vehicle_stationary_detection](./vehicle_stationary_detection/asm330lhhxg1)
* IIS2DULPX
	* [6d_position_recognition](./6d_position_recognition/iis2dulpx)
	* [vibration_monitoring](./vibration_monitoring/iis2dulpx)
* IIS2ICLX
	* [tilt_angle](./tilt_angle/iis2iclx)
	* [tilt_angle_dual_plane](./tilt_angle_dual_plane/iis2iclx)
* ISM330BX
	* [6d_position_recognition](./6d_position_recognition/ism330bx)
	* [vibration_monitoring](./vibration_monitoring/ism330bx)
* ISM330DHCX
	* [6d_position_recognition](./6d_position_recognition/ism330dhcx)
	* [motion_intensity](./motion_intensity/ism330dhcx)
	* [vehicle_stationary_detection](./vehicle_stationary_detection/ism330dhcx)
	* [vibration_monitoring](./vibration_monitoring/ism330dhcx)
* LIS2DUX12
	* [6d_position_recognition](./6d_position_recognition/lis2dux12)
	* [activity_recognition_for_mobile](./activity_recognition_for_mobile/lis2dux12)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lis2dux12)
	* [asset_tracking](./asset_tracking/lis2dux12)
	* [motion_intensity](./motion_intensity/lis2dux12)
	* [vibration_monitoring](./vibration_monitoring/lis2dux12)
* LIS2DUXS12
	* [6d_position_recognition](./6d_position_recognition/lis2duxs12)
	* [activity_recognition_for_mobile](./activity_recognition_for_mobile/lis2duxs12)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lis2duxs12)
	* [asset_tracking](./asset_tracking/lis2duxs12)
	* [motion_intensity](./motion_intensity/lis2duxs12)
	* [vibration_monitoring](./vibration_monitoring/lis2duxs12)
* LSM6DSO32X
	* [6d_position_recognition](./6d_position_recognition/lsm6dso32x)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lsm6dso32x)
	* [gym_activity_recognition](./gym_activity_recognition/lsm6dso32x)
	* [motion_intensity](./motion_intensity/lsm6dso32x)
	* [vibration_monitoring](./vibration_monitoring/lsm6dso32x)
* LSM6DSOX
	* [6d_position_recognition](./6d_position_recognition/lsm6dsox)
	* [activity_recognition_for_mobile](./activity_recognition_for_mobile/lsm6dsox)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lsm6dsox)
	* [asset_tracking](./asset_tracking/lsm6dsox)
	* [door_opening_closing_still](./door_opening_closing_still/lsm6dsox)
	* [gym_activity_recognition](./gym_activity_recognition/lsm6dsox)
	* [head_gestures](./head_gestures/lsm6dsox)
	* [motion_intensity](./motion_intensity/lsm6dsox)
	* [tennis_activity](./tennis_activity/lsm6dsox)
	* [vehicle_stationary_detection](./vehicle_stationary_detection/lsm6dsox)
	* [vibration_monitoring](./vibration_monitoring/lsm6dsox)
	* [yoga_pose_recognition](./yoga_pose_recognition/lsm6dsox)
* LSM6DSRX
	* [6d_position_recognition](./6d_position_recognition/lsm6dsrx)
	* [activity_recognition_for_mobile](./activity_recognition_for_mobile/lsm6dsrx)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lsm6dsrx)
	* [asset_tracking](./asset_tracking/lsm6dsrx)
	* [head_gestures](./head_gestures/lsm6dsrx)
	* [motion_intensity](./motion_intensity/lsm6dsrx)
	* [vehicle_stationary_detection](./vehicle_stationary_detection/lsm6dsrx)
	* [vibration_monitoring](./vibration_monitoring/lsm6dsrx)
* LSM6DSV16BX
	* [6d_position_recognition](./6d_position_recognition/lsm6dsv16bx)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lsm6dsv16bx)
	* [head_gestures](./head_gestures/lsm6dsv16bx)
	* [motion_intensity](./motion_intensity/lsm6dsv16bx)
	* [vibration_monitoring](./vibration_monitoring/lsm6dsv16bx)
* LSM6DSV16X
	* [6d_position_recognition](./6d_position_recognition/lsm6dsv16x)
	* [activity_recognition_for_mobile](./activity_recognition_for_mobile/lsm6dsv16x)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lsm6dsv16x)
	* [asset_tracking](./asset_tracking/lsm6dsv16x)
	* [door_opening_closing_still](./door_opening_closing_still/lsm6dsv16x)
	* [gym_activity_recognition](./gym_activity_recognition/lsm6dsv16x)
	* [head_gestures](./head_gestures/lsm6dsv16x)
	* [motion_intensity](./motion_intensity/lsm6dsv16x)
	* [vibration_monitoring](./vibration_monitoring/lsm6dsv16x)
	* [yoga_pose_recognition](./yoga_pose_recognition/lsm6dsv16x)
* LSM6DSV320X
	* [6d_position_recognition](./6d_position_recognition/lsm6dsv320x)
	* [activity_recognition_for_mobile](./activity_recognition_for_mobile/lsm6dsv320x)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lsm6dsv320x)
	* [asset_tracking](./asset_tracking/lsm6dsv320x)
	* [door_opening_closing_still](./door_opening_closing_still/lsm6dsv320x)
	* [gym_activity_recognition](./gym_activity_recognition/lsm6dsv320x)
	* [head_gestures](./head_gestures/lsm6dsv320x)
	* [motion_intensity](./motion_intensity/lsm6dsv320x)
	* [tennis_activity](./tennis_activity/lsm6dsv320x)
	* [vibration_monitoring](./vibration_monitoring/lsm6dsv320x)
	* [yoga_pose_recognition](./yoga_pose_recognition/lsm6dsv320x)
* LSM6DSV32X
	* [6d_position_recognition](./6d_position_recognition/lsm6dsv32x)
	* [activity_recognition_for_mobile](./activity_recognition_for_mobile/lsm6dsv32x)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lsm6dsv32x)
	* [asset_tracking](./asset_tracking/lsm6dsv32x)
	* [gym_activity_recognition](./gym_activity_recognition/lsm6dsv32x)
	* [head_gestures](./head_gestures/lsm6dsv32x)
	* [motion_intensity](./motion_intensity/lsm6dsv32x)
	* [tennis_activity](./tennis_activity/lsm6dsv32x)
	* [vibration_monitoring](./vibration_monitoring/lsm6dsv32x)
* LSM6DSV80X
	* [6d_position_recognition](./6d_position_recognition/lsm6dsv80x)
	* [activity_recognition_for_mobile](./activity_recognition_for_mobile/lsm6dsv80x)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/lsm6dsv80x)
	* [asset_tracking](./asset_tracking/lsm6dsv80x)
	* [door_opening_closing_still](./door_opening_closing_still/lsm6dsv80x)
	* [gym_activity_recognition](./gym_activity_recognition/lsm6dsv80x)
	* [head_gestures](./head_gestures/lsm6dsv80x)
	* [motion_intensity](./motion_intensity/lsm6dsv80x)
	* [tennis_activity](./tennis_activity/lsm6dsv80x)
	* [vibration_monitoring](./vibration_monitoring/lsm6dsv80x)
	* [yoga_pose_recognition](./yoga_pose_recognition/lsm6dsv80x)
* ST1VAFE3BX
	* [6d_position_recognition](./6d_position_recognition/st1vafe3bx)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/st1vafe3bx)
	* [motion_intensity](./motion_intensity/st1vafe3bx)
* ST1VAFE6AX
	* [6d_position_recognition](./6d_position_recognition/st1vafe6ax)
	* [activity_recognition_for_wrist](./activity_recognition_for_wrist/st1vafe6ax)
	* [motion_intensity](./motion_intensity/st1vafe6ax)

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2025 STMicroelectronics**
