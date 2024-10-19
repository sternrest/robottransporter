## Program buat Robot Transporter menggunakan Arduino Uno dan NodeMCU ESP32
[robot]: https://raw.githubusercontent.com/sternrest/robottransporter/main/robot.jpg "robot"
[controller]: https://raw.githubusercontent.com/sternrest/robottransporter/main/controller.jpg "controller"

|||
|-----------|-----------|
|![robot][robot]|![controller][controller]|

## Unduh kode sumber di sini
[Link rilis paket](https://github.com/sternrest/robottransporter/releases/download/v0.1/TransporterRobotSource.zip)

## Paket rilis ini berisi :
1. Kode sumber untuk Arduino Uno dengan controller DualShock PS2
2. Kode sumber unt NodeMCU ESP32 dengan controller [Dabble](https://thestempedia.com/product/dabble/) via Bluetooth

## Bahan yang dibutuhkan : 
- Arduino Uno + DualShock Ctroller atau ESP32 + Aplikasi Dabble pada Smartphone
- 2 buah Servo Motor 18
- 1 set Gripper Ro
- 2 buah Motor DC Gear
- 1 buah Driver Motor 
- 3 buah Baterai 18650 dan Holder-nya
- Kabel Jumper secukupn

## Library yang perlu dipasan
### Jika menggunakan Arduino Uno dan DualShock Controlle
  - '#include <PS2X_lib.h>' untuk library controller dualshoc
  - '#include <Servo.h>' untuk library servo moto
### Jika Menggunakan ESP32 dan Aplikasi Dabbl
  - '#include <DabbleESP32.h>' untuk library controller dabble khusus esp32
  - '#include <ESP32Servo.h>' untuk library servo motor khusus esp3
