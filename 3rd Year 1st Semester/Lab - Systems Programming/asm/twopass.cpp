#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<fstream>

#define pb push_back
#define mp make_pair
using namespace std;
#define MAXN 100000

void erase_apos(string& s){
    int l = s.size();
    for(int i=0;i<l;i++)
        if(s[i]==',')
            s[i]=' ';
    return;
}

struct Instruction{
    int opcode;
    int src;
    int dst;
    bool isSrcRegister;
    bool isDstRegister;

    Instruction(){

    }

    Instruction(int opcode,int dst,int src,bool isDstRegister,bool isSrcegister){
        this->opcode = opcode;
        this->dst = dst;
        this->src = src;
        this->isDstRegister = isDstRegister;
        this->isSrcRegister = isSrcRegister;
    }

    Instruction(int opcode,int dst){
        this->dst = dst;
        this->opcode = opcode;
        this->src = -1;
        this->isDstRegister = false;
        this->isSrcRegister = false;
    }

    Instruction(int opcode){
        this->dst = -1;
        this->src = -1;
        this->opcode = opcode;
        this->isDstRegister = false;
        this->isSrcRegister = false;
    }

    Instruction(int opcode,int dst,bool isDstRegister){
        this->opcode = opcode;
        this->dst = dst;
        this->src = src;
        this->isSrcRegister = false;
        this->isDstRegister = isDstRegister;
    }
};

class Assembler{
    public:    
        unordered_map<string,int> littab;
        unordered_map<string,int> optab;
        unordered_map<string,int> symtab;
        int recentVal;
        int memcnt;
        set<string> reg_names = {"a","b","c","d","e","f"};

        int memory[MAXN];
        int registers[6];

        int pc;

        Assembler(){
            pc = 0;
            recentVal = 0;
            memcnt = 0;
            symtab["a"]=0;symtab["b"]=1;symtab["c"]=2;
            symtab["d"]=3;symtab["e"]=4;symtab["f"]=5;
            optab["add"] = 0;optab["sub"] = 1;optab["inc"]=2;optab["dec"]=3;optab["print"]=4;optab["jnz"]=5;optab["jz"]=6;
            optab["end"]=7;optab["jmp"]=8;optab["mov"]=9;
        }

        Instruction getIns(string s){
            erase_apos(s);
            Instruction ret;
            stringstream ss(s);
            string word;
            vector<string> words;

            while(ss >> word)
                words.pb(word);

            if(optab.find(words[0])==optab.end()){
                if(symtab.find(words[0])!=symtab.end())
                    exit(2);
                symtab[words[0]]=pc;
                words.erase(words.begin());
            }

            if(words[0]=="add"||words[0]=="sub"||words[0]=="mov"){
                int opcode = optab[words[0]];
                int dst = symtab[words[1]];
                int src = symtab[words[2]];

                bool isDstRegister=false;
                bool isSrcRegister=false;

                if(reg_names.find(words[1])!=reg_names.end())
                    isDstRegister = true;
                if(reg_names.find(words[2])!=reg_names.end())
                    isSrcRegister = true;
                
                ret = Instruction(opcode,dst,src,isDstRegister,isSrcRegister);
                return ret;
            }

            else if(words[0]=="dec"||words[0]=="inc"||words[0]=="print"){
                int opcode = optab[words[0]];
                int dst = symtab[words[1]];
                bool isDstRegister = false;

                if(reg_names.find(words[1])!=reg_names.end())
                    isDstRegister = true;
                ret = Instruction(opcode,dst,isDstRegister);
                return ret;
            }

            else if(words[0]=="jmp"||words[0]=="jnz"||words[0]=="jz"){
                int opcode = optab[words[0]];
                if(symtab.find(words[1])==symtab.end())
                    ret = Instruction(opcode,-2);
                else
                    ret = Instruction(opcode,symtab[words[1]]);
                return ret;
            }

            else if(words[0]=="end"){
                int opcode = optab[words[0]];
                ret = Instruction(opcode);
                return ret;
            }
            return ret;
        }

        void processData(string s){
            erase_apos(s);
            Instruction ret;
            stringstream ss(s);
            string word;
            vector<string> words;

            while (ss >> word)
                words.pb(word);
            
            memory[memcnt] = stoi(words[2]);
            symtab[words[0]] = memcnt;
            memcnt++;
            return;
        }   

        bool performOperation(Instruction ins){

            int opcode = ins.opcode;
            int dst = ins.dst;
            int src = ins.src;
            bool isSrcRegister = ins.isSrcRegister;
            bool isDstRegister = ins.isDstRegister;
            
            int srcVal = -1;
            int dstVal = -1;
            if(src!=-1)
                srcVal = isSrcRegister ? registers[src] : memory[src];
            if(dst!=-1)
                dstVal = isDstRegister ? registers[dst] : memory[dst];


            if(opcode==optab["add"]){
                if(srcVal==-1||dstVal==-1)
                    exit(1);
                
                int val = srcVal+dstVal;
                val = val%(1<<16);

                if(isDstRegister)
                    registers[dst] = val;
                else
                    memory[dst] = val;
                recentVal = val;
                pc++;
                return true;
            }

            else if(opcode==optab["sub"]){
                if(srcVal ==-1||dstVal==-1)
                    exit(1);
                
                int val = dstVal-srcVal;
                val = val%(1<<16);

                if(isDstRegister)
                    registers[dst] = val;
                else
                    memory[dst] = val;
                recentVal = val;
                pc++;
                return true; 
            }

            else if(opcode==optab["mov"]){
                if(srcVal==-1||dstVal==-1)
                    exit(1);
                
                if(isDstRegister)
                    registers[dst] = srcVal;
                else
                    memory[dst] = srcVal;
                pc++;
                return true;
            }

            else if(opcode==optab["inc"]){
                
                if(isDstRegister)
                    {registers[dst] = (registers[dst]+1)%(1<<16);recentVal=registers[dst];}
                else
                    {memory[dst] = (registers[dst]+1)%(1<<16);recentVal=registers[dst];}
                pc++;
                return true;
            }

            else if(opcode==optab["dec"]){
                if(isDstRegister)
                    {registers[dst] = (registers[dst]-1)%(1<<16);recentVal = registers[dst];}
                else
                    {memory[dst] = (memory[dst]-1)%(1<<16);recentVal=memory[dst];}

                pc++;
                return true;
            }

            else if(opcode==optab["jmp"]){
                if(srcVal!=-1)
                    exit(-1);
                pc = dst;
                return true;
            }

            else if(opcode==optab["jnz"]){
                if(srcVal!=-1)
                    exit(1);
                
                if(recentVal!=0)
                    pc=dst;
                else
                    pc++;
                return true;
            }

            else if(opcode==optab["jz"]){
                if(srcVal!=-1)
                    exit(1);
                if(recentVal==0)
                    pc = dst;
                else
                    pc++;
                return true;
            }

            else if(opcode==optab["print"]){
                cout<<dstVal<<endl;
                pc++;
                return true;
            }

            else if(opcode==optab["end"]){
                return false;
            }
            else{
                return false;
            }
            return false;
        }

        void run(string filename){
            ifstream file(filename);

            vector<string> lines;
            string line;

            while(getline(file,line))
                lines.pb(line);
            
            int i=1;
            if(lines[0]==".data"){
                string temp;
                for(i=1;i<lines.size();i++){
                    if(lines[i]!=".code")
                        processData(lines[i]);
                    else
                        break;
                }
            }

            pc=0;
            i++;
            vector<Instruction> ins;

            for(;i<lines.size();i++){
                ins.pb(getIns(lines[i]));
                pc++;
            }

            bool cont = true;
            pc = 0;
            while(cont){
                cont=performOperation(ins[pc]);
            }
            return;
        }
};

int main(int argc,char** argv){
    string filename = argv[1];
    Assembler as;
    cout<<filename<<endl;
    as.run(filename);
    return 0;
}