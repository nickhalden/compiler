flex FP.l;
gcc lex.yy.c -ll;
g++ -std=c++11  parser.cpp lex.yy.c Node.cpp -ll -o output
./output
echo $?
