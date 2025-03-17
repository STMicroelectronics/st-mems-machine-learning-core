# Python utilities

This folder contains some Python utilities which allow the user to design a decision tree using Python. The utilities are contained in the Python ***mlc_utils*** module, which can be imported by the user.

Two utilities are available in the module:
- The ***read_arff*** function allows the user to convert an ARFF file to a Python Tuple composed of two pandas dataframes containing the features and the labels. The features and labels can then be used as input for the scikit-learn *DecisionTreeClassifier.fit()* method.
- The ***export_tree*** function allows the user to export a scikit-learn *DecisionTreeClassifier* object to a text file suitable for STMicroelectronics tools.

An example showing how to use the ***mlc_utils*** module is available in the *example* script and in the snippet of code below.

```Python
import mlc_utils as mlc
from sklearn.tree import DecisionTreeClassifier

if __name__ == "__main__":
    X, y = mlc.read_arff("features.arff")
    dectree = DecisionTreeClassifier(random_state=42)
    dectree.fit(X, y)
    mlc.export_tree(dectree, "dectree.txt")
```

The aim of this example is to show how to use the ***read_arff*** and ***export_tree*** functions. However, the example does not provide a complete pipeline and configuration to design the decision tree classifier, which the user must implement based on the use case.

------

**More information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2025 STMicroelectronics**
