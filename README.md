# Catalog Secret Recovery Assignment

This project implements a simplified version of **Shamir's Secret Sharing** using Lagrange Interpolation.

## ✅ Features
- Reads input from two JSON files
- Decodes y-values in different bases
- Uses first `k` roots to solve polynomial
- Finds the secret (constant term)

---

## 📁 Files
- `main.cpp`: Source code
- `test1.json`, `test2.json`: Test cases
- `json.hpp`: JSON parser header file (nlohmann/json)
- `output.txt`: Output of program

---

## 🧠 How to Run

1. **Install g++**
2. Download `json.hpp` from:
   [nlohmann/json.hpp](https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp)
3. Compile and Run:

```bash
g++ main.cpp -o secret.exe
.\secret.exe
