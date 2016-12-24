import subprocess as sproc
import os

NumberOfTests = 28
valgrindProc = 'valgrind'

for i in range(1, NumberOfTests + 1):
    inp = open('./Tests/test' + str(i) + '.txt')
    p = sproc.Popen([valgrindProc, os.getcwd() + '/MiniValgrind'],
                    stdin=inp, stdout=sproc.PIPE, stderr=sproc.PIPE)
    valgOut, valgErr = p.communicate()

    leakSummary = valgErr[valgErr.find("definitely lost") : ]
    leakSummary = leakSummary[ : leakSummary.find("==") - 1]
    
    errorSummary = valgErr[valgErr.find("ERROR SUMMARY") : ]
    errorSummary = errorSummary[ : errorSummary.find(" (suppressed")]
    
    print("Test #" + str(i))
    print(leakSummary)
    print(errorSummary)
    print