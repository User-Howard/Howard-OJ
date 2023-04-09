const fs = require('fs');

// 遞歸函數遍歷目錄結構，輸出到README.md中
function generateReadme(path, level, countcpp, countpy) {
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
      if (file.endsWith('.cpp')) {
        countcpp++;
      }
      if (file.endsWith('.py')) {
        countpy++;
      }
    }
  });

  return { output: output, countcpp: countcpp, countpy: countpy };
}

// 生成程式碼區塊
const result = generateReadme('./', 0, 0, 0);
const readmeContent = `
# Howard-OJ

###### 專門紀錄我的程式資料夾。

\`\`\` 
${result.output}\`\`\`

\`總共有 ${result.countcpp} 個 .cpp 檔案。\`
\`總共有 ${result.countpy} 個 .py 檔案。\`
`;

// 輸出目錄結構到README.md中
fs.writeFileSync('README.md', readmeContent);
