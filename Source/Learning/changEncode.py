import os

# 需要转换的目录（你可根据你的项目修改）
TARGET_DIRS = ["Private", "Public"]

# 要转换的文件后缀
EXTS = [".h", ".hpp", ".cpp", ".ini", ".txt"]

def is_target_file(file):
    return any(file.lower().endswith(ext) for ext in EXTS)

def convert_gbk_to_utf8(file_path):
    try:
        with open(file_path, "r", encoding="gbk") as f:
            content = f.read()
    except UnicodeDecodeError:
        print(f"跳过（不是 GBK 编码）：{file_path}")
        return

    with open(file_path, "w", encoding="utf-8") as f:
        f.write(content)

    print(f"转换成功：{file_path}")

def scan_and_convert():
    for root in TARGET_DIRS:
        if not os.path.exists(root):
            print(f"目录不存在：{root}")
            continue

        for path, dirs, files in os.walk(root):
            for file in files:
                if is_target_file(file):
                    full_path = os.path.join(path, file)
                    convert_gbk_to_utf8(full_path)


if __name__ == "__main__":
    scan_and_convert()
