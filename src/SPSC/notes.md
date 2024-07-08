# Single Producer Single Consumer Queue

Built using a circular buffer.

### First implementation

- Single threaded implementation.

### Second implementation

- Thread safe implementation (using mutex and vector as storage).

### Third implementation

- Thread safe implementation (using mutex and vector as storage).
- Added preallocation of the buffer + using placement new. Got a ~5% speedup -> meaning the bottleneck is not memory allocation.

### Fourth implementation
