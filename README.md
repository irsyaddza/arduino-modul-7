# 🚶 IMPLEMENTASI SENSOR PIR PADA ARDUINO UNO
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![Sensors](https://img.shields.io/badge/Sensors-PIR-red?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-1.0-blue?style=for-the-badge)

### 🔧 Komponen yang Dibutuhkan
- Arduino Board
- Sensor PIR
- LCD Display
- Buzzer
- LED
- Push Button
- Kabel Jumper
- Resistor

## 🎯 Mode Operasi & Fitur

### Mode 1: Monitoring Dasar PIR 👁️
```plaintext
[Tekan Tombol #1]
```
- Mengaktifkan sensor PIR
- Menampilkan status kerja PIR di LCD
- Monitoring real-time melalui serial monitor
- Ideal untuk pengujian dan kalibrasi sensor

### Mode 2: Deteksi dengan Alarm 🔔
```plaintext
[Tekan Tombol #2]
```
- Deteksi gerakan dengan feedback suara
- Buzzer aktif saat terdeteksi gerakan
- Tampilan status di LCD
- Output detail di serial monitor

### Mode 3: Deteksi Visual 💡
```plaintext
[Tekan Tombol #3]
```
- LED berkedip saat terdeteksi gerakan
- LED mati saat tidak ada gerakan
- Informasi status di LCD
- Monitoring melalui serial monitor

### Mode 4: Reset Sistem 🔄
```plaintext
[Tekan Tombol #4]
```
- Kembali ke Mode 1
- Reset semua output
- Siap untuk siklus baru

## ⚡ Cara Kerja Detail

### 1️⃣ Mode Monitoring Dasar
- Sensor PIR aktif dan mulai scanning
- LCD menampilkan "PIR AKTIF"
- Serial monitor menampilkan status detail
- Ideal untuk testing awal

### 2️⃣ Mode Alarm
- Deteksi gerakan → Buzzer aktif
- LCD menampilkan "TERDETEKSI GERAKAN!"
- Serial monitor mencatat waktu deteksi
- Buzzer berhenti saat tidak ada gerakan

### 3️⃣ Mode Visual
- Gerakan terdeteksi → LED berkedip
- Tidak ada gerakan → LED mati
- LCD menampilkan status real-time
- Serial monitor mencatat semua aktivitas

### 4️⃣ Mode Reset
- Sistem kembali ke mode awal
- Semua output di-reset
- Siap memulai siklus baru
