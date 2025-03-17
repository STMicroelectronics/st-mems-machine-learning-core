function tbl = arff_to_table(arff_file)
    % Function to convert an ARFF file into a MATLAB table
    % arff_file: Path to the input ARFF file
    % tbl: Output MATLAB table

    % Open the ARFF file
    fid = fopen(arff_file, 'r');
    if fid == -1
        error('Could not open ARFF file.');
    end

    headers = strings(0);

    % Read the ARFF file line by line
    while ~feof(fid)
        line = strtrim(fgets(fid)); % Read a line and trim whitespace

        % Skip empty lines or comments
        if isempty(line) || startsWith(line, '%')
            continue;
        end

        % Parse the header section
        if startsWith(line, '@attribute', 'IgnoreCase', true)
            attribute = sscanf(line, '@attribute %s');
            headers = [headers attribute]; %#ok<AGROW>
        elseif startsWith(line, '@data', 'IgnoreCase', true)
            break;
        end
    end

    % Close the ARFF file
    fclose(fid);

    tbl = readtable(arff_file, 'FileType', 'text');
    tbl.Properties.VariableNames = headers;
end
