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
