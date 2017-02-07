TARGET=dosprgwc.exe
WATCOM_BASE=C:\WATCOM
PLATFORM=dos
COMPILER=wcc
LINKER=wlink

all : $(TARGET)

clean : .SYMBOLIC
	del *.obj >nul 2>&1
	del *.exe >nul 2>&1
	del *.map >nul 2>&1

graphics.obj : src\graphics.c src\graphics.h
	$(COMPILER) src\graphics.c -i="$(WATCOM_BASE)/h" -w4 -e25 -zq -od -d2 -bt=$(PLATFORM) -fo=.obj -ml

main.obj : src\main.c src\graphics.h
	$(COMPILER) src\main.c -i="$(WATCOM_BASE)/h" -w4 -e25 -zq -od -d2 -bt=$(PLATFORM) -fo=.obj -ml

$(TARGET) : graphics.obj main.obj .SYMBOLIC
  $(LINKER) name dosprgwc d all sys $(PLATFORM) op m op maxe=25 op q op symf FIL graphics.obj,main.obj
