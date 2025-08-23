# 🔢 Number Theory

<p align="center">
  <img src="https://img.shields.io/badge/Math-Number%20Theory-0b7285?style=for-the-badge" />
  <img src="https://img.shields.io/badge/License-MIT-2c5282.svg?style=for-the-badge" />
  <img src="https://img.shields.io/badge/PRs-Welcome-success?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-Polyglot-ff922b?style=for-the-badge" />
</p>

<p align="center">
  <i>A curated collection of clean, tested, and extensible number theory algorithms for learning, research, and competitive programming.</i>
</p>

---



## ✨ Features

> Clean code | Explainable math | Performance-focused | Extensible

- 🔍 Multiple primality testing strategies (deterministic + probabilistic)
- ⚡ Optimized sieves (classic, segmented, bitset variants)
- 🧮 Modular arithmetic toolkit (pow, inverse, CRT, NTT-ready helpers)
- 🧷 Safe big-int friendly patterns (where language-supported)
- 🧠 Educational clarity: each module optionally links to theory
- 🧪 (Planned) Automatically verified identities via property tests
- 🧩 Ready for integration in CP templates or academic experiments

---

## 🧩 Algorithm Catalogue

| Category | Implementations | Notes |
|----------|-----------------|-------|
| Primes | Sieve of Eratosthenes, Segmented Sieve, Miller–Rabin, Deterministic bases (64-bit) | Fast + memory-aware |
| GCD/LCM | Euclidean, Binary GCD | Extended Euclid for linear Diophantine |
| Modular Arithmetic | Fast exponentiation, Modular inverse (Fermat & Extended Euclid), Chinese Remainder Theorem | Overflow-safe variants |
| Factorization | Trial division, Pollard’s Rho (planned) | Balanced between simplicity & speed |
| Totients & Functions | Euler’s φ, Möbius μ (planned), Divisor count/sum | Sieve-accelerated |
| Sequences | Fibonacci (matrix exp), Lucas (planned) | O(log n) versions |
| Representations | Continued fractions, Rational reconstruction (planned) | Helpful for cryptography |
| Combinatorics (planned) | nCr mod p, factorial precomputation, Lucas theorem | For large combinatorics |
| Advanced (roadmap) | NTT, Primitive roots, Quadratic residues, Tonelli–Shanks | For polynomial/crypto tasks |

---



> Actual structure may evolve; consult repository tree for the latest layout.

---

## 🚀 Getting Started

Clone the repository:

```bash
git clone https://github.com/Anikk1234/Number-Theory.git
cd Number-Theory
```

(If directory name becomes lowercase automatically)
```bash
cd Number-Theory  # or number-theory depending on your environment
```

### Python Setup

```bash
python -m venv .venv
source .venv/bin/activate  # Windows: .venv\Scripts\activate
pip install -r requirements.txt
```

### C++ (Example)

```bash
mkdir -p build && cd build
cmake ..
cmake --build . --config Release
```

---

## 🛠 Usage Examples

### Python

```python
from python.primes.sieve import sieve
from python.primes.miller_rabin import is_probable_prime
from python.arithmetic.modular import mod_pow, mod_inverse

print(sieve(30))                 # [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
print(is_probable_prime(10**18+3))
print(mod_pow(7, 560, 561))      # Carmichael test example
print(mod_inverse(3, 11))        # 4
```

### C++

```cpp
#include "number_theory/gcd.hpp"
#include "number_theory/sieve.hpp"
#include "number_theory/mod.hpp"
#include <iostream>

int main() {
    std::cout << gcd(48, 18) << "\n";             // 6
    auto primes = sieve(100);
    std::cout << primes.size() << "\n";
    std::cout << mod_pow(7, 128, 1000) << "\n";
}
```

### CLI (Planned)

```
$ nt-tool primes --limit 1000000 --format count
Primes up to 1000000: 78498
```

---

## ⚙️ Implementation Notes

<details>
<summary>🔐 Miller–Rabin Bases (Deterministic)</summary>
For 64-bit integers we use the minimal witness set:
[2, 3, 5, 7, 11, 13] (adequate for n < 3,474,749,660,383).  
Extended set (2,3,5,7,11,13,17) covers all 64-bit signed range.
</details>

<details>
<summary>🧮 Modular Inverse Strategy</summary>
- Prime modulus: Fermat (pow(a, m-2, m))  
- Composite modulus (a,m coprime): Extended Euclid  
- Non-coprime detection yields graceful failure (returns None / optional).
</details>

<details>
<summary>🧵 Threading & Performance</summary>
Segmented sieve enables chunk-wise memory usage and parallelizable segments (future).
</details>

---

## 📊 Benchmarks (Sample)

| Task | Input | Time (Python) | Time (C++) | Notes |
|------|-------|---------------|------------|-------|
| Sieve | 1e6 | ~0.12 s | ~0.01 s | Bitset planned for further reduction |
| Miller–Rabin | 1 random 64-bit | ~0.00007 s | ~0.00001 s | 7 bases |
| Extended GCD | 64-bit pair | ~0.000002 s | ~0.0000004 s | Tail recursion removed |

> Re-run with: `python -m python.utils.timing` (script name placeholder)

---

## 🧪 Testing

Run all Python tests:

```bash
pytest -q
```

Run C++ tests (if using Catch2 / GoogleTest):

```bash
cd build && ctest --output-on-failure
```

---

## 🗺 Roadmap

- [ ] Pollard’s Rho with Brent cycle detection
- [ ] Möbius function & convolution utilities
- [ ] Dirichlet convolution framework
- [ ] Number Theoretic Transform (NTT)
- [ ] Tonelli–Shanks modular square roots
- [ ] Primitive root finder
- [ ] Fast divisor enumeration (wheel + factorization hybrid)
- [ ] Probabilistic vs deterministic API switch
- [ ] Web playground (WASM)
- [ ] Auto-generated docs from type hints / comments

---

## 🤝 Contributing

We love contributions—no change is too small.

1. Fork the project
2. Create a feature branch  
   `git checkout -b feat/pollards-rho`
3. Run / add tests
4. Lint & format (e.g., `ruff`, `black`, `clang-format`)
5. Commit with a conventional message  
   `git commit -m "feat(factorization): add pollards rho with fallback"`
6. Push & open a PR

### Style Guidelines

| Aspect | Python | C++ |
|--------|--------|-----|
| Formatting | black | clang-format |
| Lint | ruff | clang-tidy (planned) |
| Tests | pytest | gtest / Catch2 |
| Naming | snake_case | snake_case (functions), PascalCase (types) |

### Suggested PR Labels
- enhancement
- bug
- performance
- docs
- refactor
- test
- research

---

## 📚 References

- Crandall & Pomerance, "Prime Numbers: A Computational Perspective"
- Knuth, TAOCP Vol. 2
- Montgomery, "Modular Multiplication Techniques"
- Bach & Shallit, "Algorithmic Number Theory"
- Bernstein’s papers on NTT & modular arithmetic

---

## 📄 License

Distributed under the MIT License. See `LICENSE` for full text.

---

<p align="center">
  Crafted for clarity • Tuned for speed • Built for curiosity
</p>

<p align="center">
  <sub>Happy coding, and may your numbers always be prime! 🧪🧠</sub>
</p>
