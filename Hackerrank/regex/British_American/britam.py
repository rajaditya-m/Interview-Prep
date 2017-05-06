import re

regex = ur"(\w)+ze(\b|$)"
pm_brit = re.compile(regex)

x = pm_brit.findall("trumpster ganster soleminize familiriaze")

for item in x:
	print(item)
