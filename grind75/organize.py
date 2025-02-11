# My folders were originally structured like this:
# grind75/cpp/week1/... and grind75/python/week1...
# This file re-organizes my directories
# To this, grind75/week1/problem/, and that contains both the py and cpp files

import os
import shutil

# Set the target directory
directory = r"F:\repos\LeetCode-Solutions-main\grind75\week1"  # Update this if needed

# Ensure the directory exists
if not os.path.exists(directory):
    print(f"Error: Directory '{directory}' not found.")
    exit()

# Get all files in the directory
files = os.listdir(directory)

# Dictionary to track problem numbers and corresponding files
file_groups = {}

for file in files:
    if '.' in file:  # Ensure it's a file with an extension
        base_name, ext = os.path.splitext(file)  # Split into filename and extension
        parts = base_name.split('-', 1)  # Split at the first '-'

        if len(parts) < 2:
            continue  # Skip files that don't match the pattern

        problem_number = parts[0]  # Extract the problem number (e.g., "001")

        if problem_number not in file_groups:
            file_groups[problem_number] = []

        file_groups[problem_number].append(file)

# Create folders and move files
for problem_number, filenames in file_groups.items():
    if len(filenames) > 1:  # Only create a folder if there are multiple files with the same problem number
        folder_name = filenames[0].rsplit('.', 1)[0]  # Use the first filename without extension
        folder_path = os.path.join(directory, folder_name)

        os.makedirs(folder_path, exist_ok=True)  # Create folder if it doesn't exist

        for filename in filenames:
            src_path = os.path.join(directory, filename)
            dest_path = os.path.join(folder_path, filename)
            shutil.move(src_path, dest_path)

print("Files have been organized into folders.")
