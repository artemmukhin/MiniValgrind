import subprocess as sproc

NumberOfTests = 28
miniValg = './MiniValgrind'

for i in range(1, NumberOfTests + 1):
    inp = open('./Tests/test' + str(i) + '.txt')
    answer = inp.readlines()[-3][len("// answer: "):]
    p = sproc.Popen([miniValg, ''], stdin=inp, stdout=sproc.PIPE, stderr=sproc.PIPE)
    valgOut, valgErr = p.communicate()
    if valgOut == answer:
        print("Test #" + str(i) + ": correct")
    else:
        print("Test #" + str(i) + ": wrong")
        print("    Expected: " + answer)
        print("    Got: " + valgOut)
