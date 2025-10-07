# Linear Algebra in C++  

This repository is my personal project to implement **core linear algebra operations** in C++ from scratch.  
The goal is to understand how matrix operations actually work behind the scenes — not to rely on existing libraries like Eigen or Armadillo.

---

## 📁 Project Structure

| File / Module | Description |
|---------------|-------------|
| `qbMatrix.h`  | Core matrix class that defines all basic operations (add, subtract, multiply, etc.) |
| `TestCode.cpp` | Test file demonstrating matrix creation and operations |
| `.gitignore`   | Ignored build files / artifacts |

---

## 🚀 Features Implemented

The current version includes:

- ✅ Matrix creation (custom size, initialization)  
- ✅ Matrix addition (`Matrix + Matrix`)  
- ✅ Matrix subtraction (`Matrix - Matrix`)  
- ✅ Matrix–Matrix multiplication  
- ✅ Scalar–Matrix multiplication (both directions)  

These cover the essential building blocks for linear algebra computations.

---

## 🧪 How to Build & Run

To compile and run:

```bash
# Clone the repo
git clone https://github.com/Anjas2005/Linear-Algebra-in-Cpp.git
cd Linear-Algebra-in-Cpp

# Compile
g++ -std=c++17 TestCode.cpp -o matrix_exec

# Run
./matrix_exec


---

Would you like me to make this a bit more **formal and professional** (like a mini-library README) or keep this **learning-project tone**?
