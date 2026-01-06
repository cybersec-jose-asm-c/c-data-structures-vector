# C Data Structures

**High-performance data structures implemented from scratch in pure C.**

Built with passion, systems thinking, and pure grind by **cybersec-jose-asm-c**.

## Extreme Benchmarks (MacBook Pro i9 2019 - 8 cores)

### Dynamic Vector
- **4,294,967,296 elements inserted** (max 32-bit size_t)
- **Time: ~30 seconds**
- **Capacity: 8,589,934,592**
- **Automatic resizing with load factor control**

> "From single-thread basics to billions of elements under concurrent load.  
> This is real systems programming." — cybersec-jose-asm-c

## Features

- **Dynamic Vector**
  - Auto-growing array
  - Load factor monitoring
  - Safe realloc handling

- Pure C · No external dependencies · Clean modular design

## Build & Run

```bash
make clean && make
./hashtable_test          # Basic hash table test
./benchmark               # Hash table 1M multi-thread
./benchmark_extreme       # Hash table 100M extreme
./vector_test             # Dynamic vector tests
```
