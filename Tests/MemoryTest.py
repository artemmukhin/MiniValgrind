import subprocess as sproc
import os

NumberOfTests = 28
valgrindProc = 'valgrind'

for i in range(1, NumberOfTests + 1):
    inp = open('./Tests/test' + str(i) + '.txt')
    p = sproc.Popen([valgrindProc, os.getcwd() + '/MiniValgrind'],
                    stdin=inp, stdout=sproc.PIPE, stderr=sproc.PIPE)
    valgOut, valgErr = p.communicate()

    errorSummary = valgErr[valgErr.find("ERROR SUMMARY") : valgErr[valgErr.find("ERROR SUMMARY"):].find("==")]
    print("Test #" + str(i))
    print(errorSummary)
    print