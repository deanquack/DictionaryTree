# DictionaryTree
Dictionary Tree (January 2022 - March 2022): This class project was designed to implement a tree data structure that takes a text file input to be parsed using another text file that contains all of the words in a dictionary. Each word is parsed using a delimiter to insert each character of the word into the tree while at the same, holding an array of letters from A to Z including a comma in their respective order. I also implemented a search and count implementation that checks if the tree structure contains the word in that particular order and if it does then increase the count of that word. The time complexity should be O(n).
This project was developed using C/C++ using the Red Hat Linux System provided by the university. 
Insert: The insert function inserts a word from the dictionary byte by byte or character by character and then puts them into a tree. If the words were inputed in the exact following order like "bat" and then inserting "batman" the program would have already known that the word bat would've exact order of the traversal so it would create another tree level that extends off from that end of the word. It would continously insert until there are no more characters in the particualr string after each line. In addition, it would also keep track of this index value and a "next" array where the index value has values of "A" TO "Z" including ' , to keep the order of letters in tact. The goal for the insert is to make it so that each character is inserted after each line and then return true if there are no more characters in that line otherwise the node is false and it continues the insertion.
Search: The serach function is designed to traverse the tree of words from the dictionary to see if the word exists and if it exists then it would return the node that exists within that tree structure. This function is intertwind with the count function which occurs after the search function. This function is implemented as a binary search where it loops until the length of characters reaches null.
Count: The count function increments by 1 everytime the same word occurs. For example, if the word "time" appears 10 times in the text, the output for the program should be "time 10" and then a newline for another word. This function is implemented as a recursive implementation.
