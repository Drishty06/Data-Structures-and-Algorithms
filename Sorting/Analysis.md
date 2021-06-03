<h2> ⚪Sorting Algorithms in Big O Notation </h2>
<img src=https://i.pinimg.com/originals/25/4f/84/254f84cc53af04da50fc93645e30ff4a.png>
<h2> ⚪Classification of Sorting Algorithms </h2>
Sorting algorithms can be categorized based on the following parameters:

<h3>•1 Based on Number of Swaps or Inversion:<br/> </h3>
  This is the number of times the algorithm swaps elements to sort the input. </br>
  SELECTION SORT requires the minimum number of swaps.</br>
<h3>•2 Based on Number of Comparisons:<br/> </h3>
   This is the number of times the algorithm compares elements to sort the input. </br>
   Using Big-O notation, the sorting algorithm examples listed above require at least O(nlogn) comparisons in the best case and O(n^2) comparisons in the worst case for most of the outputs.
<h3>•3 Based on Recursion or Non-Recursion: <br/> </h3>
Some sorting algorithms, such as QUICK SORT, use recursive techniques to sort the input.</br>
Other sorting algorithms, such as SELECTION SORT or INSERTION SORT, use non-recursive techniques. </br>
Finally, some sorting algorithm, such as MERGE SORT, make use of both recursive as well as non-recursive techniques to sort the input. </br>
<h3>•4 Based on Stability: <br/> </h3> 
Sorting algorithms are said to be stable if two equivalent elements remain in the same order in the sorted output as they were in the input.</br>
INSERTION SORT, MERGE SORT, and BUBBLE SORT are stable</br>
HEAP SORT and QUICK SORT are not stable</br>
<h3>•5 Based on Extra Space:<br/> </h3> 
Requirement Sorting algorithms are said to be IN PLACE if they require a constant O(1) extra space for sorting.</br>
INSERTION SORT and QUICK SORT are IN PLACE sort as we move the elements about the pivot and do not actually use a separate array which is NOT the case in MERGE SORT where the size of the input must be allocated beforehand to store the output during the sort.
MERGE SORT is an example of out place sort as it require extra memory space for it’s operations.
