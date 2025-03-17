import re
from typing import TextIO, Tuple
import pandas as pd
from scipy.io import arff
from sklearn.tree import DecisionTreeClassifier, export_text

def read_arff(file: TextIO) -> Tuple[pd.DataFrame, pd.DataFrame]:
    arff_data, _ = arff.loadarff(file)
    arff_df = pd.DataFrame(arff_data)
    X = arff_df.drop("class", axis="columns")
    y = arff_df["class"].astype("string")
    return X, y

def export_tree(dectree: DecisionTreeClassifier, file: TextIO):
    text = export_text(dectree, feature_names=dectree.feature_names_in_, decimals=6, max_depth=dectree.tree_.max_depth)
    text = re.sub(r">  ", r"> ", text)
    dt = re.sub(r"\|--- ", r"", text).splitlines()
    new_dt = []
    line_idx = 1
    while line_idx < len(dt):
        match = re.search(r"class: (\w+)$", dt[line_idx])
        if match is not None:
            new_dt.append(f"{dt[line_idx - 1]}: {match.group(1)}")
            line_idx += 2
        else:
            new_dt.append(dt[line_idx - 1])
            line_idx += 1
    weka_str = "\n".join(new_dt) + "\n"

    with open(file, "w") as f:
        f.write(weka_str)
