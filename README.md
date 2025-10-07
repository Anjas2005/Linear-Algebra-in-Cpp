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

---

## 🎯 Main Goal

The **main aim** of this project is to eventually develop a **full-featured C++ linear algebra library**.  
This includes not only basic operations like addition, subtraction, and multiplication, but also advanced functionalities such as:

- Determinants and matrix inverses  
- Transpose and adjoint operations  
- Eigenvalues and eigenvectors  
- LU, QR, and SVD decompositions  
- Efficient memory management and performance optimizations  
- Vector operations and system solvers  

The library is being built step by step, with a strong focus on **understanding the underlying algorithms** and providing a solid foundation for future enhancements.


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

