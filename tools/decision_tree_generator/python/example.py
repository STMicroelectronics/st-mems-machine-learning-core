import mlc_utils as mlc
from sklearn.tree import DecisionTreeClassifier

if __name__ == "__main__":
    X, y = mlc.read_arff("features.arff")
    dectree = DecisionTreeClassifier(random_state=42)
    dectree.fit(X, y)
    mlc.export_tree(dectree, "dectree.txt")
