// XC code mixer
// Powered by wchengk09

#include <bits/stdc++.h>
using namespace std;
using str = string;
char buf[1 << 20];
string file;
int var_cnt = 0,func_cnt = 0,struct_cnt = 0;

inline int sys(string s){
    printf("%s\n",s.c_str());
    return system(s.c_str());
}

vector<int> findall(string big,string small){
    int pos = 0;
    vector<int> ret;
    while ((pos = big.find(small,pos)) != string::npos){
        ret.push_back(pos);
        pos ++;
    }
    return ret;
}

void deal_tree(FILE *fp,pair<int,int> beg,pair<int,int> fin){
    scanf("%s",buf);
    if (!strcmp(buf,"RETURN"))return;
    pair<int,int> bc,fc;
    scanf("%d%d%d%d",&bc.first,&bc.second,&fc.first,&fc.second);
    beg = max(beg,bc);
    fin = min(fin,fc);
    if (!strcmp(buf,"CXX_METHOD") || !strcmp(buf,"FUNCTION_DECL")){
        w
    }
}

int main(){
    FILE *fp = fopen("mixer0.cpp","w");
    int maxlen = 0;
    int lcnt = 0;
    while (fgets(buf,1 << 20,stdin)){
        lcnt ++;
        if (strstr(buf,"#include"))maxlen = lcnt;
        fputs(buf,fp);
    }
    fclose(fp);
    sys("g++ mixer0.cpp -E -o mixer1.cpp");
    fp = fopen("mixer1.cpp","r");
    FILE *fp2 = fopen("mixer2.cpp","w");
    int cnt = 0;
    while (fgets(buf,1 << 20,fp)){
        if (strstr(buf,"\"mixer0.cpp\""))
            cnt ++;
        if (cnt >= maxlen + 2 && buf[0] != '#' && buf[0] != '\n')
            fputs(buf,fp2),file += buf;
    }
    fclose(fp2);
    assert(!sys("python3 gen_tree.py mixer2.cpp > AST.txt"));
    fp = fopen("AST.txt","r");

    fclose(fp);
    return 0;
}