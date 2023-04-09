const fs = require('fs');

const { execSync } = require('child_process');

const tree = execSync('tree -aI node_modules').toString();

const readme = `# My Repository\n\n\'\'\' ${tree}\'\'\'`;

console.log(readme);

fs.writeFileSync('README.md', readme);
