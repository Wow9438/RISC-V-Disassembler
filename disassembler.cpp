#include <bits/stdc++.h>

using namespace std;

string hextobin(string s){
    if(s.length()==8){
    string s1;
    for(auto st : s){
        int p = (int)st;
        string s2;
        if(p>=48 && p<=57){
            int t = 4;
            p -= 48;
            while(t--){
                s2 = (char)((p)%2 + 48)+s2;
                p = p/2;
            }
        } else if(st == 'a'){
            s2 =  "1010";
        }else if(st == 'b'){
            s2 =  "1011";
        }else if(st == 'c'){
            s2 =  "1100";
        }else if(st == 'd'){
            s2 =  "1101";
        }else if(st == 'e'){
            s2 =  "1110";
        }else if(st == 'f'){
            s2 =  "1111";
        }
        s1 = s1+s2;
    }
    return s1;}
    else {
        return "";
    }
}

string bintohex(string s){
    string ans;
    int len = (s.length()%4);
    for(int i =1;i<=4-len;i++){
        s = "0"+s; 
    }
    for(int i =0;i<s.length();i+=4){
        if(s[i]=='1'){
            if(s[i+1]=='1'){
                if(s[i+2]=='1'){
                    if(s[i+3]=='1'){
                        ans+="f";
                    }else if(s[i+3]=='0'){
                        ans+="e";
                    }

                }else if(s[i+2]=='0'){
                    if(s[i+3]=='1'){
                        ans+="d";
                    }else if(s[i+3]=='0'){
                        ans+="c";
                    }
                }
            }else if(s[i+1]=='0'){
                if(s[i+2]=='1'){
                    if(s[i+3]=='1'){
                        ans+="b";
                    }else if(s[i+3]=='0'){
                        ans+="a";
                    }
                }else if(s[i+2]=='0'){
                    if(s[i+3]=='1'){
                        ans+="9";
                    }else if(s[i+3]=='0'){
                        ans+="8";
                    }
                }
            
            }
        }else if(s[i]=='0'){
            if(s[i+1]=='1'){
                if(s[i+2]=='1'){
                    if(s[i+3]=='1'){
                        ans+="7";
                    }else if(s[i+3]=='0'){
                        ans+="6";
                    }
                }else if(s[i+2]=='0'){
                    if(s[i+3]=='1'){
                        ans+="5";
                    }else if(s[i+3]=='0'){
                        ans+="4";
                    }
                }

        }else if(s[i+1]=='0'){

            if(s[i+2]=='1'){
                    if(s[i+3]=='1'){
                        ans+="3";
                    }else if(s[i+3]=='0'){
                        ans+="2";
                    }
                }else if(s[i+2]=='0'){
                    if(s[i+3]=='1'){
                        ans+="1";
                    }else if(s[i+3]=='0'){
                        if(ans.length()!=0||i==s.length()-1) ans+="0";
                    }
                }
            
        }
        }
    }
    return ans;
}

int bintounsignedint(string s){
    int ans = 0;
    for(int i =0;i<s.length();i++){
        if(s[i] == '1') ans = 2*ans+1;
        else ans *= 2;
    }
    return ans;
}

int bintosignedint(string s){
    int ans = 0;

    if(s[0]=='1') ans = -1;
    
    for(int i =0;i<s.length();i++){
        if(s[i] == '1') ans = 2*ans+1;
        else ans *= 2;
    }
    
    return ans;
}

void Rtype(string s,vector<string>&ans,int i){
    string func7 = s.substr(0,7);
    int rs2 = bintounsignedint(s.substr(7,5));
    int rs1 = bintounsignedint(s.substr(12,5));
    string func3 = s.substr(17,3);
    int rd = bintounsignedint(s.substr(20,5));
    if(func7=="0000000"){
        
        if(func3 =="000"){
            
            ans[i] +="add ";
    
        }else if(func3 =="100"){
            
            ans[i] +="xor ";
        
        }else if(func3 =="110"){
            
            ans[i] +="or ";
        
        }else if(func3 =="111"){
            
            ans[i] +="and ";
        
        }else if(func3 =="001"){
            
            ans[i] +="sll ";
        
        }else if(func3 =="101"){
            
            ans[i] +="srl ";
        
        }else if(func3 =="010"){
            
            ans[i] +="slt ";
        
        }else if(func3 =="011"){
            
            ans[i] +="sltu ";
        }

    }else if(func7=="0100000"){
       
         if(func3 =="000"){
        
            ans[i] +="sub ";
        
        }else if(func3 =="101"){
        
            ans[i] +="sra ";
        
        } 
    }
    ans[i] +="x"+to_string(rd)+",x"+to_string(rs1)+",x"+to_string(rs2);
    

}

void Itype(string s,string opcode,vector<string>&ans,int i){
    int imm = bintosignedint(s.substr(0,12));
    int imme = bintounsignedint(s.substr(6,6));
    int rs1 = bintounsignedint(s.substr(12,5));
    string func3 = s.substr(17,3);
    int rd = bintounsignedint(s.substr(20,5));
    if(opcode=="0010011"){

        if(func3 =="000"){
            
            ans[i] +="addi ";
        
        }else if(func3 =="100"){
            
            ans[i] +="xori ";
        
        }else if(func3 =="110"){
            
            ans[i] +="ori ";
        
        }else if(func3 =="111"){
            
            ans[i] +="andi ";
        
        }else if(func3 =="001"){
            
            ans[i] +="slli ";
        
        }else if(func3 =="101"){
            
            if(s.substr(0,6)=="000000"){ans[i] +="srli ";}
            
            else if(s.substr(0,6)=="010000"){ans[i] +="srai ";}
        
        }else if(func3 =="010"){
            
            ans[i] +="slti ";
        
        }else if(func3 =="011"){
            
            ans[i] +="sltui ";
        }

        if(func3 =="101"||func3 =="001"){

            ans[i] +="x"+to_string(rd)+",x"+to_string(rs1)+","+to_string(imme);   

        }else{
                ans[i] +="x"+to_string(rd)+",x"+to_string(rs1)+","+to_string(imm);
            }

    }else if(opcode=="0000011"){
        
        if(func3 =="000"){
            
            ans[i] +="lb ";
        
        }else if(func3 =="001"){
            
            ans[i] +="lh ";
        
        }else if(func3 =="010"){
            
            ans[i] +="lw ";
        
        }else if(func3 =="011"){
            
            ans[i] +="ld ";
        
        }else if(func3 =="100"){
            
            ans[i] +="lbu ";
        
        }else if(func3 =="101"){
            
            ans[i] +="lhu ";
        
        }else if(func3 =="110"){
            
            ans[i] +="lwu ";
        
        }

        ans[i] +="x"+to_string(rd)+","+to_string(imm)+"(x"+to_string(rs1)+")";

    }else if(opcode=="1100111"){
        if(func3=="000"){
            ans[i] +="jalr x"+to_string(rd)+",x"+to_string(rs1)+","+to_string(imm);
        }
    }
}

void Stype(string s,vector<string>&ans,int i){
    
    int imm = bintosignedint(s.substr(0,7)+s.substr(20,5));
    int rs1 = bintounsignedint(s.substr(12,5));
    int rs2 = bintounsignedint(s.substr(7,5));
    string func3 = s.substr(17,3);
    if( func3 == "000"){

        ans[i]+="sb ";

    }else if( func3 == "001"){

        ans[i]+="sh ";

    }else if( func3 == "010"){

        ans[i]+="sw ";

    }else if( func3 == "011"){

        ans[i]+="sd ";

    }
    ans[i]+="x"+to_string(rs2)+","+to_string(imm)+"(x"+to_string(rs1)+")";

}

void Utype(string sbin,string shex,string opcode,vector<string>&ans,int i){
    
    string imm = "0x"+shex.substr(0,5);
    int rd = bintounsignedint(sbin.substr(20,5));
    if(opcode == "0110111"){

        ans[i]+="lui x"+to_string(rd)+","+imm;

    }else if(opcode == "0010111"){

        ans[i]+="auipc x"+to_string(rd)+","+imm;

    }
}

void Btype1(string sbin,vector<string>&ans,int i){
    
    int rs1 = bintounsignedint(sbin.substr(12,5));
    int rs2 = bintounsignedint(sbin.substr(7,5));
    string func3 = sbin.substr(17,3);
    string imme ;
    imme+=  sbin[0];
    imme+=sbin[24] +sbin.substr(1,6)+sbin.substr(20,4)+"0";
    int imm = bintosignedint(imme);
    if(func3 == "000"){

        ans[i]+="beq ";

    }else if(func3 == "001"){

        ans[i]+="bne ";

    }else if(func3 == "100"){
        
        ans[i]+="blt ";

    }else if(func3 == "101"){
        
        ans[i]+="bge ";

    }else if(func3 == "110"){
        
        ans[i]+="bltu ";

    }else if(func3 == "111"){
        
        ans[i]+="bgeu ";

    }

    ans[i] += "x"+to_string(rs1)+",x"+to_string(rs2)+","+to_string(imm);

}

void Jtype1(string sbin,vector<string>&ans,int i){

    int rd = bintounsignedint(sbin.substr(20,5));
    string imm = sbin[0]+sbin.substr(11,8)+sbin[11]+sbin.substr(1,10)+"0";
    int imme = bintosignedint(imm);
    imm = bintohex(imm);
    ans[i] += "jal x"+to_string(rd)+",0x"+imm;


}

void Btype2(string sbin,vector<string>&ans,int i,int &label){
    int rs1 = bintounsignedint(sbin.substr(12,5));
    int rs2 = bintounsignedint(sbin.substr(7,5));
    string func3 = sbin.substr(17,3);
    string imme ;
    imme+=  sbin[0];
    imme+=sbin[24] +sbin.substr(1,6)+sbin.substr(20,4)+"0"; 
    int imm = bintosignedint(imme);
    
    if(func3 == "000"){

        ans[i]+="beq ";

    }else if(func3 == "001"){

        ans[i]+="bne ";

    }else if(func3 == "100"){
        
        ans[i]+="blt ";

    }else if(func3 == "101"){
        
        ans[i]+="bge ";

    }else if(func3 == "110"){
        
        ans[i]+="bltu ";

    }else if(func3 == "111"){
        
        ans[i]+="bgeu ";

    }
    int x = -1;
    for(int j =0;j<ans[i+(imm/4)].length();j++){
        if(ans[i+(imm/4)][j] == ':') break;
        x++;
    }
    if(i+(imm/4)<ans.size()&&i+(imm/4)>=0){
        if(x<ans[i+(imm/4)].length()-1 && ans[i+(imm/4)].length()>0){

            ans[i] += "x"+to_string(rs1)+",x"+to_string(rs2)+","+ans[i+(imm/4)].substr(0,x+1);

        }else if(ans[i+(imm/4)].length()==0||x>=ans[i+(imm/4)].length()-1){

            ans[i+(imm/4)] = "L"+to_string(label)+":"+ans[i+(imm/4)];
            ans[i] += "x"+to_string(rs1)+",x"+to_string(rs2)+","+"L"+to_string(label);
            label++;
        }
    }else {
        ans[i] += "x"+to_string(rs1)+",x"+to_string(rs2)+","+to_string(imm);
    }
}

void Jtype2(string sbin,vector<string>&ans,int i,int &label){
    int rd = bintounsignedint(sbin.substr(20,5));
    string imm = sbin[0]+sbin.substr(11,8)+sbin[11]+sbin.substr(1,10)+"0";
    int imme = bintosignedint(imm);
    imm = bintohex(imm);
    int x = -1;
    for(int j =0;j<ans[i+(imme/4)].length();j++){
        if(ans[i+(imme/4)][j] == ':') break;
        x++;
    }
    if(i+(imme/4)<ans.size()&&i+(imme/4)>=0){
        if(x!=ans[i+(imme/4)].length()-1 && ans[i+(imme/4)].length()>0){

            ans[i] += "jal x"+to_string(rd)+","+ans[i+(imme/4)].substr(0,x+1);

        }else if(ans[i+(imme/4)].length()==0||x>=ans[i+(imme/4)].length()-1){
            ans[i+(imme/4)] = "L"+to_string(label)+":"+ans[i+(imme/4)];
            ans[i] += "jal x"+to_string(rd)+","+"L"+to_string(label);
            label++;
        }
    }else {
        Jtype1(sbin,ans,i);
    }
}

void instructions(string sbin,string shex,vector<string>&ans,int i,int &label){

    if(sbin.length() == 32){
        string opcode = sbin.substr(25,7);
        
        if(opcode == "0110011"){
            //R type
            Rtype(sbin,ans,i);
        }else if(opcode=="0010011"||opcode=="0000011"|opcode=="1100111"){
            //I type
            Itype(sbin,opcode,ans,i);
        }else if(opcode=="0100011"){
            //S type
            Stype(sbin,ans,i);
        }else if(opcode=="1100011"){
            //B Type
            Btype2(sbin,ans,i,label);
            //Btype1(sbin,ans,i);
        }else if(opcode=="1101111"){
            //J type
            Jtype2(sbin,ans,i,label);
            //Jtype1(sbin,ans,i);
        }else if(opcode=="0110111"||opcode=="0010111"){
            //U type
            Utype(sbin,shex,opcode,ans,i);
        }
    }
}


int main(int argc,char*argv[]){
    
    vector<string>arr;
    ifstream input;
    ofstream output;
    input.open(argv[1]);
    output.open(argv[2]);
    string s;
    while(!input.eof()){
        input>>s;
        arr.push_back(s);
    }
    input.close();
    int label = 1;
    vector<string>ans(arr.size());
    for(int i =0;i<arr.size();i++){
    string shex = arr[i];
    string sbin = hextobin(shex);
    instructions(sbin,shex,ans,i,label);
    }
    for(int i =0;i<arr.size()-1;i++){
        output<<ans[i];
        output<<endl;
    }
    output<<ans[arr.size()-1];
    output.close();
    return 0;
}