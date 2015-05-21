Binary Search Tree project:

requires c language

Will put entered integers into a binary search tree then print them back out for you in pre-order
	(post-order and in-order missing)
At the moment I have hit an error that I don't know what to do with:

"
Undefined symbols for architecture x86_64:
"_main", referenced from:
implicit entry/start for main executable
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [all] Error 1
"

I can't seem to find anything about it on the internet either, and it deletes the main.c file when this error occurs
	
The code in tree.c / tree.h should all work, but this error in main.c is preventing me from doing much with it
Testing is basically impossible, and useless as none of these functions actually return anything, they all return void