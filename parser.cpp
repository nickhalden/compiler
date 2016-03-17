#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>  //for std::vector
#include <string.h>
#include <stack>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <map>
#include "FP.h" 
#include "symbol_node.h"
#include <iostream>
#include "Node.cpp"
#include <queue>
extern int yylex();
extern int yylineno;
extern char *yytext;
extern FILE  *yyin;
extern void yyrestart(FILE *);

struct node {
    string name="";
    vector<node *> child;
    
    //char* name;
    node *next;
};


using namespace std;
//Stack of states
stack <string> states;
string table[100][100];
void initialiseTable();
void readSFP();
string reduce(string,int);
map <string,int> test2;
bool reduction=false;
queue<string> order;
stack<string> printStack;
void createTree(string,string,string);
void printNodeLevelWise(node*);
struct symbol_node *treehead;
void printTree();

int main(int argc,char **argv){
node *root;
states.push("1");
//cout << states.top();
string path;
initialiseTable();
readSFP();
//printTree();
cout<<"end of main";

}



void initialiseTable(){
int k,l;
vector<string> list;
ifstream fp;
string path2;
cout << "enter the path of input file (input.pt) "<<endl;
cin>>path2;
fp.open(path2);
//fp.open("input.pt");
if(fp==NULL){
cout<<"File not found \n";
}
else{
	string line;
	int i=0,j=1;
	cout << "\t";
	while(getline(fp,line)){
	stringstream lineStream(line);
	while(lineStream.good())
	{
		lineStream >> table[i][j];
		cout << table [i][j] <<"\t";
		j++;
	}
	cout << endl;
	i++;
	j=0;
}

fp.close();
}

}
void readSFP( ){
string token[]={"{","{","=","p","l",""};
std::map<char,int> first;
map<int,string> test;


//hashmap for the other columns
test2.insert(pair<string,int>("$",9));
test2.insert(pair<string,int>("P",10));
test2.insert(pair<string,int>("T",11));
test2.insert(pair<string,int>("S",12));
test2.insert(pair<string,int>("R",13));
test2.insert(pair<string,int>("C",14));
string path1;
cin >> path1;
cout << "enter the sfp file";
yyin = fopen("sample.sfp","r");
int n=yylex();
while(n)
{
  
	map<int,string> ::iterator itr;
	string s=states.top();
	//cout <<  s << " , " << n << endl;
  	int  state= atoi(s.c_str());
	if(table[state][n]=="0"){
	cout<< "error no valid shift reduce found in the parsing table for " << s <<" and " << n <<  endl;
	printTree();
	//cout << "token could not be processed "<<table[0][n];
	exit(1);
	}
	else {
		string val=table[state][n];
		if (val.size()<3){
		states.push(table[0][n]);
		states.push(table[state][n]);	
		printStack.push(table[0][n]);

		//cout << table[0][n] << " token is processed " << endl;
		//cout << "on seeing : "<<table[0][n] <<" move to : " <<states.top()<< endl;
		n=yylex();
		if (n==-1){
		  n=9;
		  printStack.push("P");
		}
		}else {
		      if (table[state][n] == "9999"){
			   cout << "accepted the input" << " success " << endl ;
			   printTree();
			   
			   exit(0);
			}
		      //cout<<"---reducing ----"<< endl<< "on seeing " << table[state][n] << " element at top :" <<states.top()<<endl;
			
		      reduce(table[state][n],n);
		}
	}


}

}
  string reduce(string production,int n){
	
	reduction=true;
	cout << production << " production is used " << endl ;
	string delimiter = "-";
	string lhs = production.substr(0, production.find(delimiter));
	string rhs = production.substr(production.find(delimiter)+1,production.size());

	order.push(production);

	cout << "lhs is : " << lhs << " rhs is : " << rhs << endl;
	for (int c=0;c<rhs.size();c++){
	//cout<< " poping state "<< states.top() << " from the stack ";
	states.pop();
	//cout << "; poping element "<<states.top() << " from the stack" << endl;
	states.pop();
	}
       	//states.push(tables[states.top][lhs]);
	int t=atoi((states.top()).c_str()); 
	int A=test2[lhs];
	
	//push the lhs  (Sy:mbol Pushed)
	states.push(lhs);                     //--------------------------------------//
        cout << endl; 
	// create a new node that points to the stack
	createTree(lhs,production,rhs);

	printStack.push(rhs);
	printStack.push(lhs);

	
	//looked up goto state pushed
	string goState=table[t][A];
	states.push(goState);                 //-------------------------------------//
	
	
	return states.top();
	//go to


  }

  void createTree(string terminal,string production,string rhs){
	node *root=new node;
	root->name=terminal;
        printNodeLevelWise(root);
       //root->child.push_back(node new node*it);

	 //root->child.push_back(node *rhs[i]);
	//root->child.push_back(production[0]);


	 //Node<string> *element;
         //element=new Node<string>(states.top());
	
        //Node<string> *parent,*child,*temp;
       
//	vector<string> list;//associate with the list
//	for (int i=0;i=rhs.size();i++){
//		list.push_back(rhs[i]);
//	}
	
	//child= new Node<string>(child);
        //temp=new Node<string>(parent,child);
	//create a parent node
	//parent(terminal,NULL);
	//for (int i=0;i<rhs.size();i++){
        //Node<string>(rhs[i],&parent);
	//}
	// pass the referrence to the parent to the childeren when the are built means parent field
	// in a datastructure i see if the varaible is still there if yes address and pop
	//}
	//parent= new Node<string>(terminal,child);
	//child=(parent->NextNode());

  }
  void printNodeLevelWise(node * root)
{
        if (root==NULL)
                return;

        queue<node *>q;
        q.push(root);

        while (!q.empty())
        {
                int n = q.size();
                while (n>0)
                {
                        node * p = q.front();
                        q.pop();
                        cout << p->name << " ";

                        for (int i=0; i<p->child.size(); i++)
                                q.push(p->child[i]);
                        n--;
                }

                cout << endl; // Separator between levels
        }
}
void printTree(){
        cout << "---- printing the parse tree ----" <<endl;
        int level=order.size();
	cout << "P" << endl;
        for (int i=0;i<order.size();i++){
            cout << "order applied for tree "<<order.front()<<endl;
            order.pop();
        }
        //order;
 }
