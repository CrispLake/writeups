AUTHOR: JUNIAS BONOU

Description
Here's a file that was recovered from a 32-bits system that organized the bytes a weird way. We're not even sure what type of file it is.
Download it here and see what you can get out of it

# solution

Analysing the challenge file it has some weird strings in it.

These look like the order of the bytes have been resorted
`&654*:987FEDCJIHGVUTSZYXWfedcjihgvutszyxw`

I created this simple a.py script to reverse the byte order in chunks of 4.

The output file seems to have more sensible strings and at the start it says JFIF so it is an image file.

I moved it into .jpg and It has the flag `picoCTF{cert!f1Ed_iNd!4n_s0rrY_3nDian_004850bf}`
