# Parallel File Encryptor (Work in Progress)

## Overview
This project is a C++ based file encryption and decryption system.  
It is designed using a modular approach and will be extended to support parallel processing.

---

## Modules

### IO
- Handles file operations (read/write)

### Task
- Represents a single task (file + action)

### ProcessManagement
- Manages tasks using a queue
- Uses `std::unique_ptr` for safe memory handling

### Cryption
- Performs encryption and decryption

### Main Programs
- `main.cpp` → Core application entry  
- `CryptionMain.cpp` → CLI-based encryption/decryption entry  

---

## Encryption Logic

```cpp
ch = (ch + key) % 256;        // encryption
ch = (ch - key + 256) % 256;  // decryption
