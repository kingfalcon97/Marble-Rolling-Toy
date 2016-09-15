# Marble-Rolling-Toy

## Format File Input

Nama file : deskripsi.dat
    
    (Jumlah state)
    (Daftar state, alphanumeric, dipisahkan spasi)
    (Daftar simbol, ditulis berurutan, tanpa spasi)
    (State awal)
    (Jumlah final state)
    (Daftar state akhir, dipisahkan spasi)
    (Transition function berbentuk tabel)

Untuk transition function, ketentuannya sebagai berikut :
- Urutan state sesuai penulisan di deskripsi.dat
- Urutan simbol sesuai penulisan di deskripsi.dat
- Transition tabel terdiri dari sejumlah state baris, yang tiap baris berisi sejumlah simbol state
- Untuk setiap i dan j dengan 1 <= i <= jumlah state dan 1 <= j <= jumlah simbol, simbol ke-j akan mengarahkan state i ke state ke-j yang ada di baris ke-i
