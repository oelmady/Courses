import string 
widths = [i for i in range(26)]
assert len(widths) == 26 
ref = dict(zip(list(string.ascii_lowercase), widths))
print (ref)