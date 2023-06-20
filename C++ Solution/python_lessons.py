# teach me data structures in python
# 1. list
# 2. tuple
# 3. dictionary
# 4. set
# 5. stack
# 6. queue
# 7. linked list
# 8. binary tree
# 9. binary search tree
# 10. heap
# 11. graph
# 12. trie
# 13. hash table
# 14. bloom filter
# 15. bit array
# 16. red-black tree
# 17. splay tree
# 18. AVL tree
# 19. B-tree
# 20. segment tree
# 21. binary indexed tree
# 22. suffix array
# 23. suffix tree
# 24. disjoint set
# 25. k-d tree
# 26. bloom filter
# 27. hyperloglog
# 28. count-min sketch
# 29. skip list
# 30. adjacency list
# 31. adjacency matrix
# 32. incidence matrix
# 33. sparse matrix
# 34. adjacency multilist

# lesson 1: list
# list is a collection which is ordered and changeable. allows duplicate members.
# type me a list
my_list = ["apple", "banana", "cherry"]
print(my_list)

# access items
print(my_list[1])

# change item value
my_list[1] = "blackcurrant"


# loop through a list
for x in my_list:
    print(x)

# check if item exists
if "apple" in my_list:
    print("Yes, 'apple' is in the fruits list")
    
# list length
print(len(my_list))

# add items
my_list.append("orange")
print(my_list)

# insert items
my_list.insert(1, "orange")

# remove items
my_list.remove("banana")

# remove items by index
my_list.pop(1)

# delete items
del my_list[0]

# empty the list