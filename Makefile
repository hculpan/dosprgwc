TARGET = dosprgwc.exe
WATCOM_BASE = C:\WATCOM
PLATFORM = dos
COMPILER = wcc
LINKER = wlink
CC_OPTIONS = -w4 -e25 -zq -od -d2 -ml

all : $(TARGET)

clean : .SYMBOLIC
	del *.obj >nul 2>&1
	del *.exe >nul 2>&1
	del *.map >nul 2>&1
	del *.sym >nul 2>&1
	del *.err >nul 2>&1

graphics.obj : src\graphics.c src\graphics.h
	$(COMPILER) src\graphics.c -i="$(WATCOM_BASE)/h"  $(CC_OPTIONS) -bt=$(PLATFORM) -fo=.obj

main.obj : src\main.c src\graphics.h
	$(COMPILER) src\main.c -i="$(WATCOM_BASE)/h" $(CC_OPTIONS) -bt=$(PLATFORM) -fo=.obj

$(TARGET) : graphics.obj main.obj
  $(LINKER) name dosprgwc d all sys $(PLATFORM) op m op maxe=25 op q op symf FIL graphics.obj,main.obj
