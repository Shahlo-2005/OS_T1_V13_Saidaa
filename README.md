# Operatsion Tizimlar - 1-topshiriq (13-variant)

## Kompilyatsiya va Ishga tushirish

### 1-topshiriq A-qism
```bash
gcc -E hello.c -o hello.i
gcc -S hello.i -o hello.s
gcc -c hello.s -o hello.o
gcc hello.o -o hello
./hello
