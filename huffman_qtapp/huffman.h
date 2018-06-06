#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <typeinfo>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;

struct HuffmanNode
{
    char ch;
    int weight;
    string code;
    HuffmanNode *lchild, *rchild, *parent;
    HuffmanNode();
    HuffmanNode(char ch, int weight);
    ~HuffmanNode();
};

struct FrequencyNode
{
    char ch;
    int weight;

    friend istream& operator >>(istream &in, FrequencyNode &obj);
    friend ifstream& operator >>(ifstream &in, FrequencyNode &obj);
    friend void operator >>(string &str, FrequencyNode &obj);
};

class Huffman
{
    HuffmanNode *root;
    vector<FrequencyNode> *freq_v;
    map<char, string> huffman_code_map;
    map<string, char> huffman_value_map;
    set<string> huffman_code_set;
public:
    Huffman();
    Huffman(string file_path);
    Huffman(string file_path, string frefile_path);
    ~Huffman();
    void cal_freq(string file_path);
    void cal_freq(string file_path, string frefile_path);
    void read_freq(string file_path);
    void initial_root();
    void display();
    void initialCode(HuffmanNode *r);
    void buildHuffmanMap(HuffmanNode *p, queue<HuffmanNode*> *q);
    void huffmanEncode(string source_filename, string target_filename);
    void huffmanDecode(string source_filename, string target_filename);
};

struct cmp
{
    bool operator ()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->weight > b->weight;
    }
};

#endif // HUFFMAN_H
