# MATLAB utilities

This folder contains some MATLAB utilities which allow the user to design a decision tree using MATLAB.

Two utilities are available:
- The ***arff_to_table*** function allows the user to convert an ARFF file to a MATLAB table. The MATLAB table can then be used as input for the MATLAB *fitctree* function.
- The ***export_tree*** function allows the user to export a MATLAB classification tree object to a text file suitable for STMicroelectronics tools.

An example showing how to use the two functions is available in the *example* script and in the snippet of code below.

```Matlab
tbl = arff_to_table('features.arff');
tree = fitctree(tbl, 'class');
export_tree(tree, 'dectree.txt');
```

The aim of this example is to show how to use the ***arff_to_table*** and ***export_tree*** functions. However, the example does not provide a complete pipeline and configuration to design the binary decision tree, which the user must implement based on the use case.

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2025 STMicroelectronics**
