name: Build ESP32-C6 Firmware

on:
  workflow_dispatch:

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - uses: actions/checkout@v4

      - uses: arduino/setup-arduino-cli@v2

      - run: |
          arduino-cli core update-index
          arduino-cli core install esp32:esp32

      - run: |
          mkdir -p build
          arduino-cli compile \
            --fqbn esp32:esp32:esp32c6 \
            --output-dir build \
            dashboard_rc.ino

      - uses: actions/upload-artifact@v4
        with:
          name: firmware
          path: build/*.bin