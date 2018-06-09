CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = main.o  player.o square.o building.o academic.o block.o residence.o gym.o controller.o coopfee.o cosap.o dctims.o display.o gooseattack.o gotims.o nh.o nonproperty.o rurc.o slc.o tuition.o board.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
