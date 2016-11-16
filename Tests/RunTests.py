import subprocess as sproc
NumberOfTests = 18
Answers = {1: "PRINT: -2\n", 2: "PRINT: 116\n", 3: "PRINT: -12\nPRINT: 5\n", 4: "PRINT: 27\nPRINT: -27\n",
           5: "PRINT: 10227\n", 6: "PRINT: 13\n", 7: "PRINT: -42\n", 8: "PRINT: 16\n", 9: "PRINT: 4\n",
           10: "PRINT: 4\n", 11: "PRINT: [1, 3, 5, 6, 7, 10, 15, 22]\n", 12: "PRINT: 50\n",
           13: "PRINT: [0, 5, 10, 15, 20]\n", 14: "PRINT: 20\n", 15: "PRINT: 12\n", 16: "PRINT: 221\n",
           17: "PRINT: 35\n", 18: "PRINT: 4\n"}
miniValg = '/home/ortem/MiniValgrind/MiniValgrind.exe'

for i in range(1, NumberOfTests + 1):
    inp = open('/home/ortem/MiniValgrind/Tests/test' + str(i) + '.txt')
    p = sproc.Popen([miniValg, ''], stdin=inp, stdout=sproc.PIPE, stderr=sproc.PIPE)
    valgOut, valgErr = p.communicate()
    if valgOut == Answers[i]:
        print("Test #" + str(i) + ": correct")
    else:
        print("Test #" + str(i) + ": wrong")
        print("    Expected: " + Answers[i])
        print("    Got: " + valgOut)
