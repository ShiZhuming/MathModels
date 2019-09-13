import openpyxl
import matplotlib
workbook = openpyxl.load_workbook("data3.xlsx")
workbook_rows = tuple(workbook.active.rows)
for i in workbook_rows:
    