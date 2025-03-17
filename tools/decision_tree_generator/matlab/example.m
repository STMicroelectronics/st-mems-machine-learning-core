tbl = arff_to_table('features.arff');
tree = fitctree(tbl, 'class');
export_tree(tree, 'dectree.txt');
