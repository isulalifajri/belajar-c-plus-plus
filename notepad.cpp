// ==========================================
// Program: Notepad Sederhana (C++)
// Fitur: Buka, lihat, edit, dan simpan file teks
// ==========================================

#include <iostream>   // untuk input/output (cout, cin)
#include <fstream>    // untuk membaca dan menulis file
#include <string>     // untuk tipe data string
#include <vector>     // untuk menyimpan beberapa baris teks

using namespace std;  // supaya tidak perlu tulis std:: di setiap fungsi

int main() {
    string filename;  // variabel untuk menyimpan nama file dari user

    // --- Minta nama file dari user ---
    cout << "Masukkan nama file (.txt): ";
    getline(cin, filename);  // baca input satu baris penuh (bisa ada spasi)

    vector<string> lines;  // wadah (array dinamis) untuk menyimpan baris teks

    // --- Membuka file jika sudah ada ---
    ifstream file_in(filename);  // buat objek untuk membaca file
    if (file_in.is_open()) {     // cek apakah file berhasil dibuka
        string line;
        cout << "\nIsi file saat ini:\n";
        int i = 1;
        // baca file baris demi baris
        while (getline(file_in, line)) {
            cout << i++ << ": " << line << endl;  // tampilkan ke layar
            lines.push_back(line);                // simpan ke vector
        }
        file_in.close();  // tutup file setelah selesai dibaca
    } else {
        cout << "\nFile baru akan dibuat.\n";  // kalau file belum ada
    }

    // --- Masuk ke mode edit ---
    cout << "\n=== Mode Edit ===\n";
    cout << "Ketik teks baru di bawah ini.\n";
    cout << "(Ketik 'SAVE' untuk menyimpan dan keluar)\n\n";

    string input;
    // baca input user baris per baris
    while (true) {
        getline(cin, input);     // baca teks
        if (input == "SAVE")     // kalau user mengetik SAVE → berhenti
            break;
        lines.push_back(input);  // tambahkan ke daftar baris teks
    }

    // --- Simpan semua isi ke file ---
    ofstream file_out(filename);     // buat file baru (atau timpa file lama)
    for (const auto& line : lines) { // tulis semua baris ke file
        file_out << line << endl;
    }
    file_out.close();  // tutup file setelah selesai disimpan

    // --- Konfirmasi ke user ---
    cout << "\n✅ File berhasil disimpan ke: " << filename << endl;

    return 0;  // tanda program selesai dengan sukses
}
