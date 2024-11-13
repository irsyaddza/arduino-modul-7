#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int pushButtonPin = 7;
const int pirPin = 12;
const int buzzerPin = A0;
const int ledPin = 13;

int buttonState = 0;
int lastButtonState = 0;
int mode = 0;  // Menyimpan mode yang aktif
bool pirState = false;  // Status PIR (deteksi gerakan)
int buttonPressCount = 0;  // Menghitung jumlah tombol yang ditekan

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C untuk LCD (pastikan sudah benar)

void setup() {
  pinMode(pushButtonPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  lcd.init();  // Menggunakan init() untuk inisialisasi LCD
  lcd.clear();  // Membersihkan layar
  lcd.backlight();  // Menyalakan backlight LCD

  Serial.begin(9600);

  // Tampilan menu awal
  lcd.print("Tekan tombol");
  lcd.setCursor(0, 1);
  lcd.print("untuk mulai");
  Serial.println("Menu Awal: Tekan tombol untuk mulai");
}

void loop() {
  // Baca status tombol
  buttonState = digitalRead(pushButtonPin);

  // Jika tombol ditekan pertama kali, pindah ke mode pertama
  if (mode == 0 && buttonState == HIGH) {
    mode = 1;  // Mulai dari case pertama
    lcd.clear();  // Bersihkan layar sebelum masuk mode baru
    delay(200); // Debouncing
  }

  // Lanjutkan program dengan kondisi mode yang sudah ditentukan
  if (mode > 0) {
    // Detect perubahan tombol tekan
    if (buttonState == HIGH && lastButtonState == LOW) {
      buttonPressCount++;  // Meningkatkan penghitung tombol yang ditekan
      if (buttonPressCount > 3) {
        buttonPressCount = 0;  // Reset penghitung jika lebih dari 3 kali
      }
      mode++;  // Mengganti mode
      if (mode > 3) {
        mode = 1;  // Kembali ke mode 1 setelah mode 4
      }
      delay(200); // Debouncing
    }
    lastButtonState = buttonState;

    // Membaca status PIR
    pirState = digitalRead(pirPin);

    switch (mode) {
      case 1:
        // Mode pertama: PIR berjalan dan status ditampilkan di LCD dan Serial Monitor
        lcd.clear();
        lcd.print("PIR Mode 1");
        lcd.setCursor(0, 1);
        lcd.print("PIR: ");
        if (pirState) {
          lcd.print("Motion Detected");
          Serial.println("PIR: Motion Detected");
        } else {
          lcd.print("No Motion");
          Serial.println("PIR: No Motion");
        }
        break;

      case 2:
        // Mode kedua: Buzzer menyala jika ada orang (deteksi PIR)
        lcd.clear();
        lcd.print("PIR Mode 2");
        lcd.setCursor(0, 1);
        if (pirState) {
          lcd.print("Motion Detected");
          Serial.println("PIR: Motion Detected");
          digitalWrite(buzzerPin, HIGH); // Nyalakan buzzer jika ada orang
        } else {
          lcd.print("No Motion");
          Serial.println("PIR: No Motion");
          digitalWrite(buzzerPin, LOW); // Matikan buzzer jika tidak ada orang
        }
        break;

      case 3:
        // Mode ketiga: LED kelap-kelip jika ada orang (deteksi PIR)
        lcd.clear();
        lcd.print("PIR Mode 3");
        lcd.setCursor(0, 1);
        digitalWrite(buzzerPin, LOW);  // Pastikan buzzer dimatikan di mode ini
        if (pirState) {
          lcd.print("Motion Detected");
          Serial.println("PIR: Motion Detected");
          // LED berkedip jika ada orang
          digitalWrite(ledPin, HIGH); // Nyalakan LED
          delay(500);  // LED menyala
          digitalWrite(ledPin, LOW);  // Matikan LED
          delay(500);  // LED mati
        } else {
          lcd.print("No Motion");
          Serial.println("PIR: No Motion");
          digitalWrite(ledPin, LOW); // Matikan LED jika tidak ada orang
        }
        break;

      case 4:
        // Mode keempat: Kembali ke mode pertama
        lcd.clear();
        lcd.print("Mode 4: Resetting");
        lcd.setCursor(0, 1);
        lcd.print("Back to Mode 1");
        Serial.println("Mode 4: Resetting to Mode 1");
        delay(2000);  // Tunggu beberapa detik sebelum kembali ke mode 1
        mode = 1;  // Kembali ke mode 1 setelah mode 4 selesai
        break;
    }
  }
}