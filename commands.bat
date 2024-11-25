nasm -f win64 asmfile.asm
gcc -c cfile.c -o cfile.obj -m64
gcc cfile.obj asmfile.obj -o cfile.exe -m64
cfile.exe
