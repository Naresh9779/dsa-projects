﻿# dsa-projects
# 1.LRU CACHE:
             An LRU (Least Recently Used) Cache is a data structure that efficiently stores and retrieves a limited number of elements while maintaining the order of their usage to quickly discard the 
              least recently accessed items when the cache exceeds its capacity. The primary data structures used to implement an LRU Cache are a doubly linked list and a hash map. The hash map 
                provides O(1) time complexity for accessing cache elements, while the doubly linked list maintains the order of usage. Here's a brief description of the implementation in C++:

              # Doubly Linked List:
            
            Each node contains a key-value pair.
            The head represents the most recently used (MRU) element.
            The tail represents the least recently used (LRU) element.
            Nodes can be quickly moved to the front (MRU position) upon access.
            
              # Hash Map (unordered_map):
            
            Maps keys to their corresponding node addresses in the doubly linked list.
            Enables O(1) time complexity for get and put operations.



 
