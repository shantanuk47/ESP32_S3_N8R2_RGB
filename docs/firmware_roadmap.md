# Firmware Roadmap
Project: ESP32-S3 N8R2 RGB (HW-678)

This roadmap defines structured development milestones.
Each version must meet validation criteria before tagging.

---

# Versioning Model

Semantic Versioning:
MAJOR.MINOR.PATCH

- MAJOR → Breaking architectural change
- MINOR → Feature milestone
- PATCH → Bug fix

Tags are created ONLY after hardware validation.

---

## Phase 0 — Foundation

Version: v0.1.0  
Status: Completed  

### Objectives
- Folder structure finalized
- platformio.ini configured
- Git-based version generation implemented
- Coding standards defined
- README and documentation established

### Validation Criteria
- Project builds successfully
- Firmware prints Git-based version
- No compiler warnings
- Clean Git state (no -dirty build)

Exit Condition:
Tag v0.1.0 created.

---

## Phase 1 — Boot Validation

Version: v0.2.0  
Status: Completed ✅

### Objectives
- Minimal app_main()  
- Confirm board boots without reset loop  
- Serial logging verified  

### Validation Criteria
- Stable boot for 60 seconds ✅  
- No watchdog resets ✅  
- Correct version string displayed ✅  

Exit Condition:
Hardware boot stability confirmed.  
**Tag v0.2.0 created.**

---

## Phase 2 — WS2812 GPIO Validation

Version: v0.3.0  
Status: Completed  

### Objectives
- Identify onboard RGB LED type
- Determine correct data GPIO pin
- Validate WS2812 protocol communication using RMT
- Confirm stable color control

### Hardware Findings
- LED Type: WS2812 (addressable RGB)
- Data GPIO: GPIO 48
- Control Protocol: 800kHz (RMT peripheral)
- Supply Voltage: 5V confirmed
- No discrete RGB pins (single-wire data LED)

### Validation Criteria
- RED, GREEN, BLUE, OFF cycle verified
- No watchdog resets
- No RMT transmission errors
- Stable runtime > 60 seconds
- Clean config-based GPIO abstraction (no hardcoded pins in app layer)

Exit Condition:
WS2812 hardware mapping confirmed, documented, and abstracted via config layer.

---

## Phase 3 — RGB Abstraction & System Initialization

Version: v0.4.0  
Status: Completed  

### Objectives
- Introduce RGB abstraction layer (`rgb.c/h`)
- Remove direct WS2812 usage from `main.c`
- Implement global brightness scaling
- Preserve hardware configuration abstraction (`config.h`)
- Introduce `system_init.c/h` for centralized boot initialization

### Implementation Summary
- `rgb.c` now manages:
  - Internal RGB state
  - Brightness scaling (0–255)
  - Encapsulated WS2812 driver calls
- `system_init.c` handles:
  - Firmware version logging
  - Boot diagnostics
  - Module initialization (RGB)
- `main.c` is reduced to a clean firmware entry point

### Validation Criteria
- RGB color cycling functional
- Brightness scaling verified on hardware
- No direct WS2812 calls from `main.c`
- Clean compilation under `-Wall -Wextra -Werror`

Exit Condition:
RGB control fully abstracted and system initialization centralized.

---

## Phase 4 — LED Engine Architecture

Version: In Progress  
Status: Active  

### Objectives
- Introduce LED engine task (FreeRTOS-based)
- Move LED ownership from main.c to engine layer
- Implement pattern abstraction (color cycle)
- Ensure non-blocking RTOS-safe architecture
- Stabilize system lifecycle (prevent app_main return)

### Completed
- LED engine task introduced
- RGB abstraction integrated
- system_init layer introduced
- app_main converted to orchestration-only
- RTOS lifecycle bug fixed (app_main no longer returns)
- Clean task-based LED ownership established

### Validation Criteria
- No reboot loop
- No duplicate WS2812 initialization
- Engine task runs independently
- LED behavior controlled only by engine

---

## Phase 5 — FreeRTOS Integration

Version: v0.6.0  
Status: Planned  

### Objectives
- Create dedicated RGB task
- Create control task
- Implement queue-based communication
- Remove blocking delays

### Validation Criteria
- No race conditions
- CPU usage stable
- No watchdog resets
- Tasks properly delayed

Exit Condition:
Deterministic multitasking behavior confirmed.

---

## Phase 6 — Stability Freeze

Version: v1.0.0  
Status: Future  

### Objectives
- Architecture frozen
- API frozen
- All major features implemented
- Documentation complete

### Validation Criteria
- No compiler warnings
- Stable runtime for extended duration
- All roadmap phases completed
- Clean tagged release

Exit Condition:
Production-ready firmware.

---

# Long-Term Expansion

- HSV color engine
- Smooth fading scheduler
- Non-blocking animation engine
- Hardware abstraction layer for board portability
- Unit testing under test/
