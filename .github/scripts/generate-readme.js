const fs = require('fs');

// 遞歸函數遍歷目錄結構，輸出到README.md中
function generateReadme(path, level, count) {
  const files = fs.readdirSync(path);
  let output = '';
  level = level || 0;
  const indent = '  '.repeat(level); // 每一層的縮進

  files.forEach(function(file) {
    const stats = fs.statSync(path + '/' + file);
    if (stats.isDirectory()) {
      // 如果是資料夾，遞歸處理
      output += indent + '- ' + file + '\n';
      const result = generateReadme(path + '/' + file, level + 1, count);
      output += result.output;
      count = result.count;
    } else {
      // 如果是檔案，輸出檔名
      if (file.endsWith('.cpp') || file.endsWith('.py') || file.endsWith('.c')) {
        count++;
      }
    }
  });

  return { output: output, count: count };
}

// 生成程式碼區塊
const result = generateReadme('./', 0, 0, 0);
const readmeContent = `
# Howard-OJ

###### 專門紀錄我的程式資料夾。

\`總共完成了 ${result.count} 個題目。\`

\`\`\` 
${result.output}\`\`\`
`;

// 輸出目錄結構到README.md中
fs.writeFileSync('README.md', readmeContent);
