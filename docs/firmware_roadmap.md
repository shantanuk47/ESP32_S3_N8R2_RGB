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

## Phase 2 — GPIO Validation

Version: v0.3.0  
Status: Pending  

### Objectives
- Identify RGB GPIO pins
- Confirm LED type (Common Anode/Cathode)
- Manual GPIO toggle test

### Validation Criteria
- Each color toggles independently
- No unintended GPIO interference
- Voltage verified if required

Exit Condition:
RGB hardware mapping confirmed and documented.

---

## Phase 3 — PWM Control

Version: v0.4.0  
Status: Pending  

### Objectives
- Initialize LEDC
- Implement per-channel brightness
- Static color mixing

### Validation Criteria
- Smooth brightness scaling
- No flickering
- PWM frequency stable
- No blocking delays

Exit Condition:
Stable PWM-based color control.

---

## Phase 4 — RGB Driver Abstraction

Version: v0.5.0  
Status: Pending  

### Objectives
- Implement rgb_init()
- Implement rgb_set_color()
- Remove hardware details from main.c
- All GPIO values isolated in config layer

### Validation Criteria
- No direct GPIO calls in application layer
- Driver fully modular
- Clean API boundary

Exit Condition:
Driver abstraction validated.

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
