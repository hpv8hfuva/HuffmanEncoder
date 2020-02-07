# HuffmanEncoder
Reads in a textfile of sentences, and converts these characters into encoded representations found from huffman encoding. 

Using huffman encoding, the program reads in paragraphs of text. It will store each character into a map with their respective 
frequencies. Higher frequencies will receive smaller encodings compared to lower frequencies. The program will eventually
display each character's binary encoding and the entire paragraphs in encoded form.

In addition, it will print out the stats of the file, such as the number of encoded symbols, number of unique symbols, 
total number of bits in the file, total number of bits after compression, compression ratios, and cost of Huffman tree.

Note: You can test the program with sample files (use the normal1.txt -> normal4.txt) and it should display (encoded1.txt -> encoded4.txt)
