## Langkah-langkah Install Compiler C++ di Windows 11 (MinGW-w64)
1. Download MinGW-w64

Buka situs resminya:
```
https://winlibs.com/
```

nanti klik yang Zhip archive

`Win64 (without LLVM/Clang/LLD/LLDB): Zip archive`

Itu akan download file seperti ini:
`winlibs-x86_64-posix-seh-gcc-15.2.0-mingw-w64ucrt-13.0.0-r3.zip`

setelah itu ekstrak ke: `C:\mingw64`

2. Tambahkan ke Environment Variables


Supaya bisa dipanggil dari terminal:


```
Tekan Windows + S, ketik "Edit the system environment variables", buka.

Klik tombol Environment Variables…

Di bawah System variables, cari Path, klik Edit.

Klik New, tambahkan:

C:\mingw64\bin

```

Klik OK semua sampai keluar.

3. Cek apakah berhasil

Buka Command Prompt (CMD) dan ketik:


`g++ --version`


Kalau muncul tulisan seperti ini:

`g++ (GCC) 15.2.0`


Artinya compiler sudah berhasil terpasang 🎉

buat file baru, misal dengan nama: `hello.cpp`

kemudian cara jalanin programnya seperti ini:

```
g++ hello.cpp -o hello   ← compile
./hello                  ← jalankan

```

cara jalanin notepad gui: 
`g++ notepad_gui.cpp -o notepad_gui.exe -mwindows`
`./notepad_gui.exe`