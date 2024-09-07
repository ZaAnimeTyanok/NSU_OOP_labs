Programm for **strings array managment**.
This programm reading each string **character by character**, then allocate memory for whole string and increase size of common array on 1, then put string in it.
When you need to delete string from array, programm just copies each string from the next one **starting from the position where placed string what should be deleted**. By the end programm decrease array len on 1 point. *There is no memory leaks because programm free every array element before copying*.

Other stages of programm work is obvious i guess **._.**
