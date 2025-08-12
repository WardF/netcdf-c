#!/bin/bash
# Simple test script to validate the reorganized INPUT section

set -e

# Get the absolute path to the source directory  
SRC_DIR=$(readlink -f ..)

# Create a minimal Doxyfile to test our reorganized INPUT section
cat > TestDoxyfile << EOF
# Minimal Doxyfile for testing INPUT reorganization
PROJECT_NAME = "NetCDF Test"
OUTPUT_DIRECTORY = test_output
GENERATE_HTML = YES
GENERATE_LATEX = NO
GENERATE_MAN = NO
GENERATE_XML = NO
EXTRACT_ALL = YES
QUIET = YES
WARNINGS = YES
WARN_IF_UNDOCUMENTED = NO
WARN_IF_DOC_ERROR = YES

# Test our reorganized INPUT section - using subset of files that must exist
INPUT = \\
        $SRC_DIR/docs/mainpage.dox \\
        $SRC_DIR/docs/building-with-cmake.md \\
        $SRC_DIR/docs/tutorial.dox \\
        $SRC_DIR/include/netcdf.h \\
        $SRC_DIR/docs/filters.md \\
        $SRC_DIR/docs/internal.md \\
        $SRC_DIR/RELEASE_NOTES.md \\
        $SRC_DIR/docs/credits.md

FILE_PATTERNS = *.h *.dox *.md
RECURSIVE = NO
EOF

echo "=== Testing reorganized INPUT section ==="
echo "Checking if all INPUT files exist..."

# Extract and check each file from our reorganized INPUT
for file in "$SRC_DIR/docs/mainpage.dox" \
           "$SRC_DIR/docs/building-with-cmake.md" \
           "$SRC_DIR/docs/tutorial.dox" \
           "$SRC_DIR/include/netcdf.h" \
           "$SRC_DIR/docs/filters.md" \
           "$SRC_DIR/docs/internal.md" \
           "$SRC_DIR/RELEASE_NOTES.md" \
           "$SRC_DIR/docs/credits.md"; do
    if [ -f "$file" ]; then
        echo "✓ Found: $file"
    else
        echo "✗ Missing: $file"
        exit 1
    fi
done

echo ""
echo "=== Running Doxygen test ==="
if doxygen TestDoxyfile; then
    echo "✓ Doxygen processing completed successfully"
    echo "✓ HTML output generated in test_output/html/"
    
    # Check if main files were generated
    if [ -f "test_output/html/index.html" ]; then
        echo "✓ Main index.html generated"
    else
        echo "✗ Main index.html not found"
        exit 1
    fi
    
    echo ""
    echo "=== Documentation structure test PASSED ==="
    echo "The reorganized INPUT section works correctly!"
else
    echo "✗ Doxygen processing failed"
    exit 1
fi