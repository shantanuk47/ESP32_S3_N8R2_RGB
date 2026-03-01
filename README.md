# ESP32-S3 N8R2 RGB (HW-678)

Professional embedded firmware project for controlling the onboard 4-pin RGB LED 
on ESP32-S3 N8R2 (HW-678 board) using ESP-IDF and PlatformIO.

This repository follows strict embedded architecture, modular design, 
Git-controlled firmware versioning, and disciplined coding standards.

---

# 1. Project Objective

This project implements:

- Structured RGB LED driver
- Hardware abstraction layer (HAL)
- Clean configuration separation
- Git-based firmware version traceability
- Scalable embedded firmware architecture
- Strict comment and file documentation standards

The goal is not just LED control — but professional firmware engineering practice.

---

# 2. Current Status

**Firmware Version:** v0.2.0 – Boot Validation Completed ✅  
**Current Phase:** Phase 2 – GPIO Validation  

See [`docs/firmware_roadmap.md`](docs/firmware_roadmap.md) for detailed roadmap.

---

# 3. Hardware Information

Board        : ESP32-S3 N8R2 (HW-678)  
Flash        : 8MB  
PSRAM        : 2MB  
RGB LED      : Onboard 4-pin RGB (non-addressable)  
MCU          : ESP32-S3  
USB          : Native USB  

---

# 4. Development Environment

Framework    : ESP-IDF (FreeRTOS-based)  
Build System : PlatformIO  
IDE          : Visual Studio Code  
Environment  : esp32s3_hw678  

No manual ESP-IDF installation is required.  
PlatformIO manages the complete toolchain.

---

# 5. Firmware Versioning

Firmware version is automatically generated using:

```
git describe --tags --always --dirty
```

Behavior:

- If commit is tagged → Firmware shows tag (e.g., v0.1.0)
- If ahead of tag → Shows commits ahead + hash
- If uncommitted changes exist → Appends `-dirty`

Example:

```
v0.4.0-7-g91acbd2
```

This guarantees:

- Full build traceability
- Reproducible firmware
- Deployment debugging capability

`include/version.h` is auto-generated during build and NOT committed.

---

# 6. Project Architecture

This firmware follows layered embedded design:

- src/        → Application & driver implementation
- include/    → Public header files
- lib/        → Custom reusable components
- test/       → Unit testing
- config.c/h  → Hardware configuration abstraction layer

Key Design Rule:

Application logic MUST NOT hardcode GPIO numbers.

All hardware mappings must reside inside the configuration layer.

---

# 7. Repository Structure

```
ESP32_S3_N8R2_RGB/
│
├── src/
│   ├── main.c
│   ├── rgb.c
│   ├── config.c
│
├── include/
│   ├── rgb.h
│   ├── config.h
│   ├── version.h (auto-generated)
│
├── lib/
├── test/
├── docs/
│   └── firmware_roadmap.md
│
├── platformio.ini
├── .gitignore
└── README.md
```

---

# 8. Coding Standards

## 8.1 Comment Rules

Allowed:
```
/* Multi-line comment */
```

Not allowed:
```
// comment
```

Single-line comments using `//` are reserved ONLY for temporarily disabling code.

---

## 8.2 Mandatory File Header

Every `.c` and `.h` file MUST begin with:

```
/============================================================
Project : ESP32-S3 N8R2 RGB (HW-678 Board)
Author  : Shantanu Kumar
GitHub  : https://github.com/shantanuk47

Date :
File :
Purpose :
============================================================/
```

Files without header are non-compliant.

---

# 9. Build & Flash Process

All operations can be performed using PlatformIO GUI 
or via CLI (recommended).

## 9.1 Clean Project

```
pio run -t clean
```

## 9.2 Build Firmware

```
pio run
```

## 9.3 Upload Firmware

```
pio run -t upload
```

## 9.4 Serial Monitor

```
pio device monitor
```

Default Baud Rate: 115200

---

# 10. Git Discipline

The following are NOT tracked:

- .pio/
- build/
- sdkconfig
- IDE configuration files
- Binary artifacts (.bin, .elf, .map)
- include/version.h (auto-generated)

Only source code and stable configuration are version-controlled.

Releases must be tagged before deployment.

---

# 11. Engineering Philosophy

This project enforces:

- Strict compiler warnings (-Wall -Wextra -Werror)
- No magic numbers
- No uncontrolled global variables
- Deterministic task behavior
- Clean driver abstraction
- Hardware portability

Embedded firmware must be predictable, testable, and maintainable.

---

# 12. Roadmap

Phase 1 – Boot Validation completed ✅  
Current Phase: Phase 2 – GPIO Validation  

Detailed roadmap available in:

```
docs/firmware_roadmap.md
```

---

# 13. License

License to be defined.

Recommended:
- MIT (simpler open-source)
- Apache 2.0 (with patent protection)