const fs = require('fs');

// 遞歸函數遍歷目錄結構，輸出到README.md中
function generateReadme(path, level) {
  const files = fs.readdirSync(path);
  let output = '';
  level = level || 0;
  const indent = '  '.repeat(level); // 每一層的縮進

  files.forEach(function(file) {
    const stats = fs.statSync(path + '/' + file);
    if (stats.isDirectory()) {
      // 如果是資料夾，遞歸處理
      output += indent + '- ' + file + '\n';
      output += generateReadme(path + '/' + file, level + 1);
    } 
  });

  return output;
}

// 輸出目錄結構到README.md中
fs.writeFileSync('README.md', generateReadme('./'));
