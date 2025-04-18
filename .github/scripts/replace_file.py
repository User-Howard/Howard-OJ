import os
import shutil

def move_files(source_dir):
    """
    将指定目录下的特定文件移动到另一个指定目录
    """
    # 获取源目录下的所有文件名
    filenames = os.listdir(source_dir)
    print('filenames', filenames)
    for filename in filenames:
        # 判断是否是目标文件
        if "readme" not in filename.lower():
            # 构造源文件路径和目标文件路径
            

            # 移动文件
            if filename[0:2] == "ZJ":
              src_path = os.path.join(source_dir, filename)
              dst_path = os.path.join("./ZeroJudge/", filename[2:])
              shutil.move(src_path, dst_path)
            elif filename[0:2] == "CF":
              src_path = os.path.join(source_dir, filename)
              dst_path = os.path.join("./CodeForces/", filename[2:])
              shutil.move(src_path, dst_path)
            elif filename[0:2] == "CSES":
              src_path = os.path.join(source_dir, filename)
              dst_path = os.path.join("./CSES/", filename[4:])
              shutil.move(src_path, dst_path)

if __name__ == "__main__":
    # 设置源目录和目标目录
    source_dir = "."
    move_files(source_dir)
