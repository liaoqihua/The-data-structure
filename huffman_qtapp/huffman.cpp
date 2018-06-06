#include "huffman.h"

istream& operator >>(istream &in, FrequencyNode &obj)
{
    in >> obj.ch >> obj.weight;
    return in;
}

ifstream& operator >>(ifstream &fin, FrequencyNode &obj)
{
    fin >> obj.ch >> obj.weight;
    return fin;
}

void operator >>(string &str, FrequencyNode &obj)
{
    obj.ch = str[0];
    str.erase(0, 2);
    istringstream iss(str);
    iss >> obj.weight;
    return;
}

HuffmanNode::HuffmanNode()
{
    this->ch = '\0';
    this->weight = 0;
    this->parent = nullptr;
    this->lchild = nullptr;
    this->rchild = nullptr;
}

HuffmanNode::HuffmanNode(char ch, int weight)
{
    this->ch = ch;
    this->weight = weight;
    this->parent = nullptr;
    this->rchild = nullptr;
    this->lchild = nullptr;
}

HuffmanNode::~HuffmanNode()
{

}

Huffman::Huffman()
{
    this->read_freq("./frequencyfile");
    this->initial_root();
    this->initialCode(this->root);

    queue<HuffmanNode*> q;
    this->buildHuffmanMap(this->root, &q);
//    this->display();
}

Huffman::Huffman(string file_path)
{
//    this->cal_freq(file_path);
    this->read_freq(file_path);
    this->initial_root();
    this->initialCode(this->root);

    queue<HuffmanNode*> q;
    this->buildHuffmanMap(this->root, &q);
//    this->display();
}

Huffman::Huffman(string file_path, string frefile_path)
{
    this->cal_freq(file_path, frefile_path);
    this->read_freq(frefile_path);
    this->initial_root();
    this->initialCode(this->root);

    queue<HuffmanNode*> q;
    this->buildHuffmanMap(this->root, &q);
//    this->display();
}

void Huffman::cal_freq(string file_path, string frefile_path)
{
    ifstream fin(file_path);
    ofstream fout(frefile_path);

    map<char, int> freq;

    char ch_buffer;
    while(fin.get(ch_buffer))
    {
        auto ret = freq.insert({ch_buffer, 1});
        if(!ret.second)
            ++ret.first->second;
    }

    auto map_it = freq.cbegin();
    while(map_it != freq.cend())
    {
        ostringstream osstr;
        osstr << map_it->first << " " << to_string(map_it->second) << endl;
        fout << osstr.str();
        ++map_it;
    }

    fin.close();
    fout.close();
}

void Huffman::cal_freq(string file_path)
{
    ifstream fin(file_path);
    ofstream fout("./frequencyfile");

    map<char, int> freq;

    char ch_buffer;
    while(fin.get(ch_buffer))
    {
        auto ret = freq.insert({ch_buffer, 1});
        if(!ret.second)
            ++ret.first->second;
    }

    auto map_it = freq.cbegin();
    while(map_it != freq.cend())
    {
        ostringstream osstr;
        osstr << map_it->first << " " << to_string(map_it->second) << endl;
        fout << osstr.str();
        ++map_it;
    }

    fin.close();
    fout.close();
}

void Huffman::read_freq(string file_path)
{
    this->freq_v = new vector<FrequencyNode>;
    ifstream fin(file_path);
    FrequencyNode fqn;
    string str;
    while(getline(fin, str))
    {
        str >> fqn;
        this->freq_v->push_back(fqn);
    }

    fin.close();
}

void Huffman::initial_root()
{
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp> pq;
    HuffmanNode *hfn;
    for(auto i: *this->freq_v)
    {
        hfn = new HuffmanNode(i.ch, i.weight);
        pq.push(hfn);
    }
    for(decltype(this->freq_v->size()) i=0;i<this->freq_v->size()-1;++i)
    {
        hfn = new HuffmanNode();
        auto x = pq.top();
        pq.pop();
        auto y = pq.top();
        pq.pop();

        hfn->weight = x->weight + y->weight;
        x->parent = hfn;
        y->parent = hfn;
        hfn->lchild = x;
        hfn->rchild = y;

        pq.push(hfn);
    }
    this->root = pq.top();
    pq.pop();
}

void Huffman::display()
{
    auto map_it = this->huffman_code_map.cbegin();
    while(map_it != this->huffman_code_map.cend())
    {
        cout << map_it->first << " " << map_it->second << endl;
        ++map_it;
    }
}

void Huffman::initialCode(HuffmanNode *r)
{
    if(!r)
        return;

    if(r->lchild)
        r->lchild->code.assign(r->code + "0");
    if(r->rchild)
        r->rchild->code.assign(r->code + "1");
    this->initialCode(r->lchild);
    this->initialCode(r->rchild);
}

void Huffman::buildHuffmanMap(HuffmanNode *p, queue<HuffmanNode*> *q)
{
    while(p || !q->empty())
    {
        if(!p->lchild && !p->rchild)
        {
            this->huffman_code_map[p->ch] = p->code;
            this->huffman_code_set.insert(p->code);
            this->huffman_value_map[p->code] = p->ch;
        }
        if(p->lchild)
            q->push(p->lchild);
        if(p->rchild)
            q->push(p->rchild);
        if(!q->empty())
        {
            p = q->front();
            q->pop();
        }
        else
        {
            p = nullptr;
        }
    }

}

Huffman::~Huffman()
{

}

void Huffman::huffmanEncode(string source_filename, string target_filename)
{
    ifstream fin(source_filename, ifstream::in);
    ofstream fout(target_filename, ofstream::out);

    string s_buffer;
    char ch_buffer;
    while(fin.get(ch_buffer))
    {
        s_buffer.append(this->huffman_code_map[ch_buffer]);//将文件中的字符编码
        if(s_buffer.size()>=64)//如果字符串中的字符长度超过64，就将编码写入文件
        {
            unsigned char out_char[8] = {};
            string out_string = s_buffer.substr(0, 64);
            s_buffer.replace(0, 64, "");

            for(int i=0;i<8;++i)
            {
                for(int j=0;j<8;++j)
                {
                    out_char[i] = ((out_char[i]<<1)&0xfe)|(static_cast<unsigned char>(out_string[i*8+j]-'0')&0x01);
                }
            }

            for(auto i: out_char)
                fout << i;
        }
    }
    if(!s_buffer.empty())//将剩余的字符编码写入文件
    {
        int char_num = 0;
        if(s_buffer.size()%8)
            char_num = s_buffer.size()/8 + 1;
        else
            char_num = s_buffer.size()/8;

        unsigned char out_char[char_num] = {};

        for(int i=0;i<char_num;++i)
        {
            for(int j=0;j<8;++j)
            {
                if((i*8+j)<s_buffer.size())
                {
                    out_char[i] = ((out_char[i]<<1)&0xfe)|(static_cast<unsigned char>(s_buffer[i*8+j]-'0')&0x01);
                }
                else
                {
                    out_char[i] = ((out_char[i]<<1)&0xfe);
                }
            }
        }

        for(auto i: out_char)
        {
            fout << i;
        }
        fout << static_cast<unsigned char>(8-s_buffer.size()%8);
    }

    fin.close();
    fout.close();
}

void Huffman::huffmanDecode(string source_filename, string target_filename)
{
    ifstream fin(source_filename, ifstream::in);
    ofstream fout(target_filename, ofstream::out);
    string s_inbuffer;
    string str;
    while(getline(fin, str));

    unsigned erase_ch = 0;
    erase_ch = static_cast<unsigned>(str[str.size()-1]);
    str.erase(str.size()-1, 1);
    for(auto i: str)
    {
        for(int j=0;j<8;++j)
        {
            s_inbuffer.append(((i>>(7-j))&0x01)?"1":"0");
        }
    }
    s_inbuffer.erase(s_inbuffer.size()-erase_ch, erase_ch);

    str.clear();
    for(auto i: s_inbuffer)
    {
        str = str + i;
        if(this->huffman_code_set.find(str) != this->huffman_code_set.end())
        {
            fout << this->huffman_value_map[str];
            str.clear();
        }
    }

    fin.close();
    fout.close();
}
