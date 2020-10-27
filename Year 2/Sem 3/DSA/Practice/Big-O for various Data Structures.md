# Big-O for various Data Structures

`Big-O` notation is a mathematical notation that describes the limiting behavior
of a function when the argument tends towards a particular value or infinity

Here `n` denotes the number of elements in that data structure
and `x` denotes a specific element on which the operation is to be performed.

| Operation | Array (unsorted) | Linked List | Array (sorted) | Binary Search Tree (balanced) |
| ------ | ------ | ------ | ------ | ------ |
| Search(x) | O(n) | O(n) | O(log(n)) | O(log(n)) |
| Insert(x) | O(1) | O(1) | O(n) | O(log(n)) |
| Remove(x) | O(n) | O(n) | O(n) | O(log(n)) |


These figures tell us the `efficiency` with which various data structures can 
perform operations on the data they hold.

Hence making it easy for us to choose a `data structure` according to uor application

![Big-O](https://assets.digitalocean.com/articles/alligator/js/big-o-notation/o-complexity.png)