import csv

aruco_dict = {}

with open("model.csv", "r", encoding="utf-8", newline="") as f:
    reader = csv.DictReader(f, skipinitialspace=True)

    for row in reader:
        aruco_id = int(row["aruco_id"])  # 文字列 → 数値に変換
        word = row["word"]
        aruco_dict[aruco_id] = word

print(aruco_dict)