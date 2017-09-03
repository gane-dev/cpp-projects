time_test.exe : main.obj name.obj time.obj utils.obj
	link /out:$@ $**

clean : @echo Cleaning the project ...
	del main.obj name.obj time.obj utils.obj utils.pch
	del time_test.exe

time.obj : time.cpp name.h utils.pch
	cl /EHsc /c time.cpp /Yuutils.h

name.obj : name.cpp name.h utils.pch
	cl /EHsc /c name.cpp /Yuutils.h

main.obj : main.cpp name.h time.h utils.pch
	cl /EHsc /c main.cpp /Yuutils.h 

utils.pch utils.obj :: utils.cpp utils.h
	cl /EHsc /c utils.cpp /Yc utils.h