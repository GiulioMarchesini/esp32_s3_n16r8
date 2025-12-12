# ESP32-S3 Blink Example

This project is a basic example for the **ESP32-S3 DevKitC-1** board using PlatformIO and the Arduino framework.
The code blinks the integrated RGB LED (NeoPixel) cycling through Red, Green, and Blue colors.

## Hardware

* **Board:** ESP32-S3 DevKitC-1
* **Flash:** 16MB (Quad I/O)
* **PSRAM:** 8MB (Octal SPI / OPI)
* **LED:** Integrated RGB (addressable via `neopixelWrite`)

## PlatformIO Configuration

The `platformio.ini` file is configured to:

* Use the **integrated JTAG** via USB for Upload and Debug (`esp-builtin`).
* Enable **USB CDC on Boot** to have the Serial Monitor via native USB.
* Correctly configure memory for N16R8 modules (16MB Flash, 8MB PSRAM OPI).

## Debug Driver Setup (Important)

To use debug and upload via the native USB port ("USB"), you must correctly configure the drivers on Windows using **Zadig**:

1. Connect the board via the native USB port (not UART).
2. Open **Zadig**.
3. Go to **Options** -> **List All Devices**.
4. Select **"USB JTAG/serial debug unit (Interface 2)"**
5. Select the **WinUSB (v6.1.7600.16385)** driver.
    * *Note:* Newer versions of WinUSB might cause issues.
6. Click on **Replace Driver** or **Reinstall WCID Driver**.

## How to use

1. **Build:** Run the PlatformIO `Build` task.
2. **Upload:** Connect the board to the USB port and run `Upload`.
3. **Monitor:** Open the Serial Monitor at 115200 baud to see debug messages.
4. **Debug:** Go to the "Run and Debug" section in VS Code and start "PIO Debug".

## Code Structure

* `src/main.cpp`: Contains the main logic. Uses `neopixelWrite()` to control the RGB LED without needing complex external libraries.
* `platformio.ini`: Environment configuration file, partitions, and build flags.
