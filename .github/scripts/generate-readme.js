const fs = require('fs');

const tree = fs.readdirSync('.', { withFileTypes: true });
const directories = tree.filter(dirent => dirent.isDirectory()).map(dirent => dirent.name);
const readme = `# Directories\n\n${directories.map(d => `- ${d}`).join('\n')}\n`;

fs.writeFileSync('README.md', readme);
