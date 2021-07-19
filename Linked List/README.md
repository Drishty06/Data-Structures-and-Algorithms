# Comparison of Linked Lists with Arrays & Dynamic Arrays
| Parameter | Linked List | Array | Dynamic Array |
| --- | --- | --- | --- |
| `Indexing` | `O(n)` | `O(1)` | `O(1)` |
| `Insertion or Deletion at beginning` | `O(1)` | `O(n)  if array is not full` | `O(n)` |
| `Insertion at ending` | `O(n)` | `O(1) if array is not full`| `O(1) if array is not full` `O(n)if array is full` |
| `Deletion at ending` | `O(n)` | `O(1)` | `O(n)` |
| `Insertion at middle` | `O(n)` | `O(n)  if array is not full` | `O(n)` |
| `Deletion at middle` | `O(n)` | `O(n)  if array is not full` | `O(n)` |
| `Wasted Space` | `O(n) for pointers` | `0` | `O(n)` | 
