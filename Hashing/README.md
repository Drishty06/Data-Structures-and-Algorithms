## 🔻1. Comparision: Maps VS Unordered Maps:
| | Maps | Unordered_maps |
| --- | --- | --- |
| Ordering | Increasing order | No ordering | 
| Implementation | Self balancing Red black trees | Hash Table |
| Search Time | O(log n) | O(1) average & O(n) worst |
| Insertion time | O(log n) + rebalance | Same as search |
| Deletion time | O(log n) + rebalance | Same as search |
| Key Data Types | All Allowed | Complicated data types of keys are not allowed since they wrok on inbuilt has tables |
## 🔻2. Comparision: Chaining And Open Addressing
| Chaining | Open Addressing | 
| --- | --- |
| Hash table never fails | Table may become full and resizing becomes necessary |
| Less sensitive to hash functions | Extra care required  | 
| Poor Cache performance | Cache friendly |
| Extra space needed for chainings | Extra space may be required to achieve same performance as chaining |

## 🔻3. Comparisions: Open Addressing Methods
| Linear Probing | Quadratic Probing | Double Hashing | 
| --- | --- | --- |
| Fastest among three | Easiest to implement and deploy | Makes more efficient use of memory |
| Uses few probes | Uses extra memory for links and it does not probe all locations in the table | Uses few probes but takes more time |
| A problem occurs known as primary clustering | A problem occurs known as secondary clustering | More complicated to implement |
| Interval between probs is fixed - often at 1 | Interval between probes increases proportional to hash value | Interval between probes is computed by another hash function |

## 🔻4. Comparision: Linear Probing And Double Hashing
The choice between linear probing and double hashing depends on the cost of computing the hash
function and on the load factor [number of elements per slot] of the table. Both use few probes but
double hashing take more time because it hashes to compare two hash functions for long keys.
