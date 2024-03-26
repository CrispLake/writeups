AUTHOR: NGIRIMANA SCHADRACK

Description
Can you handle APKs?
Download the android apk here.


# solution

Using `strings | grep flag` I found out that there is a file called `res/color/flag.txt`

I opened online apk decompiler and found the file. The contents are just these numbers `7069636f4354467b6178386d433052553676655f4e5838356c346178386d436c5f37303364643965667d`

Convert from hex and get flag `picoCTF{ax8mC0RU6ve_NX85l4ax8mCl_703dd9ef}`