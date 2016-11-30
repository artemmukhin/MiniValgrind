import subprocess as sproc
NumberOfTests = 23
Answers = {1: "-2", 2: "116", 3: "-12\n5", 4: "27\n-27", 5: "10227", 6: "13", 7: "-42",
           8: "16", 9: "4", 10: "4", 11: "[1, 3, 5, 6, 7, 10, 15, 22]", 12: "50",
           13: "[0, 5, 10, 15, 20]", 14: "20", 15: "12", 16: "221", 17: "35", 18: "4",
           19: "120", 20: "2\n3\n5\n7\n11\n13\n17\n19", 21: "4", 22: "[1, 2, 3, None, None]",
           23: "[1, 3, 5, 6, 7, 10, 15, 22]",
           24: "[1, 2, 3]\n[1, 3, 2]\n[2, 1, 3]\n[2, 3, 1]\n[3, 1, 2]\n[3, 2, 1]",
           }
miniValg = '/home/ortem/prog/MiniValgrind/MiniValgrind'

for i in range(1, NumberOfTests + 1):
    inp = open('/home/ortem/prog/MiniValgrind/Tests/test' + str(i) + '.txt')
    p = sproc.Popen([miniValg, ''], stdin=inp, stdout=sproc.PIPE, stderr=sproc.PIPE)
    valgOut, valgErr = p.communicate()
    if valgOut == Answers[i] or valgOut == Answers[i] + '\n':
        print("Test #" + str(i) + ": correct")
    else:
        print("Test #" + str(i) + ": wrong")
        print("    Expected: " + Answers[i])
        print("    Got: " + valgOut)
