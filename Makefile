#CXX=clang++
CXX=g++

CXXFLAGS= -g -O3 -std=c++14 

BINARIES=dataProj testReport testReport2

all: ${BINARIES}

tests: ${BINARIES}
	./testReport
	./testReport2

dataProj: dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o parse.o main.o
	${CXX} $^ -o $@

testReport: testReport.o dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o  parse.o  tddFuncs.o
	${CXX} $^ -o $@

testReport2: testReport2.o dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o  parse.o tddFuncs.o
	${CXX} $^ -o $@


clean:
	/bin/rm -f ${BINARIES} *.o 
