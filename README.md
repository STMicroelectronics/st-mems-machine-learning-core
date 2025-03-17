# MLC - machine learning core

This repository provides examples, tutorials, and tools for the **MLC**, a dedicated core for machine learning processing, able to execute algorithms directly inside the sensor. Products that embed the MLC can be distinguished by the "X" at the end of their name.

The machine learning processing capability allows moving some algorithms from the application processor to the MEMS sensor, enabling consistent reduction of power consumption.

The machine learning processing capability is obtained through decision tree logic. A decision tree is a mathematical tool composed of a series of configurable nodes. Each node is characterized by an “if-then-else” condition, where an input signal (represented by statistical parameters calculated from the sensor data) is evaluated against a threshold.

The results of the decision tree can be read from the application processor at any time. Furthermore, there is the possibility to generate an interrupt for every change in the result in the decision tree.

For more information about MLC, please explore the dedicated page available on the ST website: [MEMS Sensors Ecosystem for Machine Learning](https://www.st.com/content/st_com/en/MEMS-Sensors-Ecosystem-for-Machine-Learning.html).

## Repository overview

This repository is structured as follows:

- An [examples](./examples/) folder, containing examples ready to be used with the sensors.
- A [tools](./tools/) folder, containing various tools that can be used to develop applications using the MLC.
- A [tutorials](./tutorials/) folder, containing tutorials describing how to create example solutions using different ST hardware kits and software tools.

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2025 STMicroelectronics**
