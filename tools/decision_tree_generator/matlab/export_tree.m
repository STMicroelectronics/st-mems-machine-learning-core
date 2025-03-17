function export_tree(tree, file)
    % Function to export a Matlab tree into a text file for
    % STMicroelectronics tools
    %
    % tree: decision tree object (e.g., created using fitctree).
    % file: name of the output file to save the tree to.

    % Open the output file for writing
    fid = fopen(file, 'w');
    if fid == -1
        error('Could not open file for writing: %s.', file);
    end

    % Recursively write the tree
    write_node(tree, 1, fid, 0);

    % Close the file
    fclose(fid);
end

function write_node(tree, node_index, fid, depth)
    if is_leaf(tree, node_index)
        % Leaf node
        className = tree.NodeClass{node_index};
        fprintf(fid, ': %s\n', className);
    else
        % Decision node
        feature = tree.CutPredictor{node_index};
        value = tree.CutPoint(node_index);

        % Left branch (<= value)
        fprintf(fid, '%s%s <= %.6f', indent(depth), feature, value);
        if is_leaf(tree, tree.Children(node_index, 1))
            % If the left child is a leaf, write it in the same line
            write_node(tree, tree.Children(node_index, 1), fid, 0);
        else
            fprintf(fid, '\n');
            write_node(tree, tree.Children(node_index, 1), fid, depth + 1);
        end

        % Right branch (> value)
        fprintf(fid, '%s%s > %.6f', indent(depth), feature, value);
        if is_leaf(tree, tree.Children(node_index, 2))
            % If the right child is a leaf, write it in the same line
            write_node(tree, tree.Children(node_index, 2), fid, 0);
        else
            fprintf(fid, '\n');
            write_node(tree, tree.Children(node_index, 2), fid, depth + 1);
        end
    end
end

function is_leaf_node = is_leaf(tree, node_index)
    is_leaf_node = isnan(tree.CutPoint(node_index));
end

function spaces = indent(depth)
    spaces = repmat('|   ', 1, depth);
end
