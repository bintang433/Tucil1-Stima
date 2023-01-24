# Tugas kecil 1 Strategi Algoritma

## 24 Card Game Solver

Dibuat oleh Bintang Hijriawan Jachja - 13521003 dalam rangka penyelesaian tugas Strategi Algoritma IF2211

## Deskripsi Permasalahan

Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka mendapatkan hasil akhir sejumlah 24. 

Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.

Projek ini adalah membuat suatu algoritma dengan pendekatan *brute force* untuk menyelesaikan permainan kartu 24.

## Algoritma yang digunakan

Pencarian solusi permainan kartu 24 dilakukan dengan pendekatan *brute force*, secara intuisi, algoritma yang dijalankan adalah sebagai berikut:


- misalkan a b c d sebagai 4 kartu/angka yang dipilih
- lakukan permutasi dari 4 kartu, dan permutasi dari 3 Simbol.
- untuk setiap bentuk persamaan, evaluasi hasil permutasi 4 kartu dan 3 simbol tersebut.
- Jika hasil evaluasi adalah 24, maka urutan tersebut termasuk solusi.


## Menjalankan Program

Untuk menjalankan program, pada *root directory*, jalankan run.bat (pada *windows*):
```
./run.bat
```
Program akan berjalan, mulai dari *compile main.cpp* dan menjalankan *main.exe*
