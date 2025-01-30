// File to rename a lot of files so I don't have to do it manually.
// I used to rename all my week1 files to .cpp and .py files rather than text files.
// I'll keep this file in my repo in case I need to use it in the future again.

const fs = require("fs");
const path = require("path");

const directory = "./"; // Change this if needed

fs.readdir(directory, (err, files) => {
    if (err) {
        console.error("Error reading directory:", err);
        return;
    }

    files.forEach((file) => {
        let newName = file
            .replace(/\./g, "")   // Remove periods
            .replace(/\s/g, "-")  // Replace spaces with dashes
            .replace(/\(/g, "")   // Remove opening parenthesis
            .replace(/\)/g, ".py"); // Replace closing parenthesis with .cpp

        const oldPath = path.join(directory, file);
        const newPath = path.join(directory, newName);

        if (oldPath !== newPath) {
            fs.rename(oldPath, newPath, (err) => {
                if (err) {
                    console.error(`Error renaming ${file}:`, err);
                } else {
                    console.log(`Renamed: ${file} → ${newName}`);
                }
            });
        }
    });
});
