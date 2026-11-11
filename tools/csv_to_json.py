   import csv, json
   with open("menu.csv", newline="", encoding="utf-8") as f:
       items = list(csv.DictReader(f))
   with open("menu.json", "w", encoding="utf-8") as f:
       json.dump({"items": items}, f, indent=2)x
