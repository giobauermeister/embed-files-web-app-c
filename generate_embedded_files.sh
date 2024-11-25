#!/bin/bash

# Path to the output header file
EMBED_HEADER=$1
shift
WEB_FILES=("$@")

# Start the header guard and structure definition
echo "#ifndef EMBEDDED_FILES_H" > "$EMBED_HEADER"
echo "#define EMBEDDED_FILES_H" >> "$EMBED_HEADER"
echo "" >> "$EMBED_HEADER"

# File declarations
echo "// File data declarations" >> "$EMBED_HEADER"
for file in "${WEB_FILES[@]}"; do
    base=$(basename "$file" | sed 's/[^a-zA-Z0-9_]/_/g')  # Clean the filename
    file_len=$(wc -c < "$file")  # Get the file length in bytes

    # Generate the array with cleaned variable names
    xxd -i "$file" \
        | sed "s/unsigned char .*/unsigned char ${base}[] = {/" \
        | sed "s/unsigned int .*/const unsigned int ${base}_len = ${file_len};/" \
        >> "$EMBED_HEADER"
done

# End the header guard
echo "" >> "$EMBED_HEADER"
echo "#endif // EMBEDDED_FILES_H" >> "$EMBED_HEADER"
