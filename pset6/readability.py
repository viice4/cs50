text = input("Text: ")

lt = 0
n = len(text)

for i in range(n):
    if text[i].isalpha():
        lt += 1

wd = 0
for i in range(n-1):
    if (text[i].isalpha() == False) and (text[i + 1].isalpha()) and text[i] != '\'':
        wd += 1

stc = 0
for i in range(n):
    if text[i] == '.' or text[i] == '?' or text[i] == "!":
        stc += 1

index = 0.0588 * lt * 100 / wd - 0.296 * stc * 100 / wd - 15.8
index0 = round(index)

if index0 >= 1 and index0 <= 16:
    print("Grade " + str(index0))
elif index0 < 1:
    print("Before Grade 1")
elif index0 > 16:
    print("Grade 16+")
