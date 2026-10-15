cmake_minimum_required(VERSION 3.10)
project(ICPportfolio C)

# ==============================================================================
# AUTOMATIC BUILD SCRIPT
# You do NOT need to edit this file when you create new C programs.
#
# How it works:
# 1. It searches every folder in this project for files ending in ".c".
# 2. It automatically creates a run button (executable) for each file it finds.
#
# IMPORTANT: When you create a new .c file, be sure to uncheck "Add to targets"
# and make sure the "Type" is set to .c and not .cpp,
# in the creation prompt. Then, you must tell CLion to rescan the folders.
# To do this, right-click this CMakeLists.txt file and select "Reload CMake Project",
# or click the "Reload changes" banner at the top of the editor.
# ==============================================================================

# Find all .c files in any directory or nested sub-directory
file(GLOB_RECURSE C_FILES "*.c")

# Loop through each file found and create a run target
foreach(C_FILE IN LISTS C_FILES)
    # Get the name of the file without the .c (e.g., "my_name" from "my_name.c")
    get_filename_component(TARGET_NAME ${C_FILE} NAME_WE)


endforeach()