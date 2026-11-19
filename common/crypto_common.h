#ifndef CSA5111_CRYPTO_COMMON_H
#define CSA5111_CRYPTO_COMMON_H
/* Shared helper routines for individual CSA5111 programs. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <openssl/evp.h>
#include <openssl/provider.h>
#include <openssl/bn.h>
#include <openssl/rand.h>

#define MAXBUF 8192
static char buf[MAXBUF];
static void readstr(const char *prompt,char *s,size_t n){printf("%s",prompt);if(!fgets(s,(int)n,stdin)){*s=0;return;}s[strcspn(s,"\r\n")]=0;}
static long long readint(const char *p){char s[128];readstr(p,s,sizeof s);return strtoll(s,NULL,10);}
static int mod(int a,int n){a%=n;return a<0?a+n:a;}
static int gcd_i(int a,int b){while(b){int t=a%b;a=b;b=t;}return a<0?-a:a;}
static int inv_i(int a,int n){for(int x=1;x<n;x++)if(mod(a*x,n)==1)return x;return -1;}
static void clean_alpha(const char*s,char*out){int n=0;for(int i=0;s[i]&&n<MAXBUF-2;i++)if(isalpha((unsigned char)s[i]))out[n++]=(char)tolower((unsigned char)s[i]);out[n]=0;}
static int hexval(char c){if(c>='0'&&c<='9')return c-'0';if(c>='a'&&c<='f')return c-'a'+10;if(c>='A'&&c<='F')return c-'A'+10;return -1;}
static int unhex(const char*s,unsigned char*out,int cap){int n=0;while(*s){while(*s&&isspace((unsigned char)*s))s++;if(!*s)break;if(!s[1]||hexval(s[0])<0||hexval(s[1])<0||n>=cap)return -1;out[n++]=(unsigned char)(hexval(s[0])*16+hexval(s[1]));s+=2;}return n;}
static void printhex(const unsigned char*p,int n){for(int i=0;i<n;i++)printf("%02X",p[i]);puts("");}
static void caesar(const char*s,int k){for(;*s;s++){char c=*s;if(isalpha((unsigned char)c)){char b=isupper((unsigned char)c)?'A':'a';c=(char)(b+mod(c-b+k,26));}putchar(c);}puts("");}
static void affine(const char*s,int a,int b,int dec){int ai=inv_i(a,26);if(dec&&ai<0){puts("Invalid key: a must be coprime to 26.");return;}for(;*s;s++){char c=*s;if(isalpha((unsigned char)c)){char z=isupper((unsigned char)c)?'A':'a';c=(char)(z+(dec?mod(ai*(c-z-b),26):mod(a*(c-z)+b,26)));}putchar(c);}puts("");}
static void vigenere(const char*s,const char*k,int dec){int n=(int)strlen(k),j=0;if(!n){puts("Keyword is empty.");return;}for(;*s;s++){char c=*s;if(isalpha((unsigned char)c)){int z=tolower((unsigned char)k[j++%n])-'a';char b=isupper((unsigned char)c)?'A':'a';c=(char)(b+mod(c-b+(dec?-z:z),26));}putchar(c);}puts("");}
static void keyword_alphabet(const char*k,char map[27]){int seen[26]={0},n=0;for(int i=0;k[i];i++)if(isalpha((unsigned char)k[i])){int x=tolower((unsigned char)k[i])-'a';if(!seen[x])map[n++]=(char)('A'+x),seen[x]=1;}for(int i=0;i<26;i++)if(!seen[i])map[n++]=(char)('A'+i);map[26]=0;}
static void substitution(const char*s,const char*key,int dec){char m[27],r[27];keyword_alphabet(key,m);for(int i=0;i<26;i++)r[m[i]-'A']=(char)('A'+i);for(;*s;s++){char c=*s;if(isalpha((unsigned char)c)){int x=toupper((unsigned char)c)-'A';char o=dec?r[x]:m[x];c=islower((unsigned char)c)?(char)tolower((unsigned char)o):o;}putchar(c);}puts("");}
static void show_keyword_map(const char*k){char m[27];keyword_alphabet(k,m);puts("Plain : ABCDEFGHIJKLMNOPQRSTUVWXYZ");printf("Cipher: %s\n",m);}
static void playfair_square(const char*text,const char square[25],int decrypt){
 char p[MAXBUF];int n=0;for(int i=0;text[i]&&n<MAXBUF-2;i++)if(isalpha((unsigned char)text[i])){char c=(char)tolower((unsigned char)text[i]);p[n++]=(c=='j')?'i':c;}
 if(decrypt&&n%2){puts("Playfair ciphertext must contain an even number of letters.");return;}
 for(int i=0;i<n;){char a=p[i],b=(i+1<n)?p[i+1]:'x';if(!decrypt&&a==b){b='x';i++;}else i+=2;
  int x=-1,y=-1;for(int z=0;z<25;z++){if(square[z]==a)x=z;if(square[z]==b)y=z;}if(x<0||y<0){puts("Invalid Playfair character.");return;}
  int r=x/5,c=x%5,u=y/5,d=y%5;
  if(r==u){c=mod(c+(decrypt?4:1),5);d=mod(d+(decrypt?4:1),5);}
  else if(c==d){r=mod(r+(decrypt?4:1),5);u=mod(u+(decrypt?4:1),5);}
  else{int t=c;c=d;d=t;}
  putchar(square[r*5+c]);putchar(square[u*5+d]);
 }puts("");
}
static void playfair_key(const char*text,const char*key,int decrypt){char sq[25],map[27];keyword_alphabet(key,map);int n=0,seen[26]={0};seen['j'-'a']=1;for(int i=0;i<26;i++){int x=map[i]-'A';if(x==9)x=8;if(!seen[x])sq[n++]=(char)('a'+x),seen[x]=1;}playfair_square(text,sq,decrypt);}
static void hill2(const char*text,int a,int b,int c,int d,int decrypt){int determinant=mod(a*d-b*c,26),iv=inv_i(determinant,26);int k[4]={a,b,c,d};if(decrypt){if(iv<0){puts("The key matrix is not invertible modulo 26.");return;}k[0]=mod(iv*d,26);k[1]=mod(-iv*b,26);k[2]=mod(-iv*c,26);k[3]=mod(iv*a,26);}char p[MAXBUF];clean_alpha(text,p);int n=(int)strlen(p);if(n%2)p[n++]='x',p[n]=0;for(int i=0;i<n;i+=2){int x=p[i]-'a',y=p[i+1]-'a';putchar('a'+mod(k[0]*x+k[1]*y,26));putchar('a'+mod(k[2]*x+k[3]*y,26));}puts("");}
static double chi_score(const char*s){static const double f[26]={8.167,1.492,2.782,4.253,12.702,2.228,2.015,6.094,6.966,0.153,0.772,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9.056,2.758,0.978,2.360,0.150,1.974,0.074};int c[26]={0},n=0;for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i]))c[tolower((unsigned char)s[i])-'a']++,n++;if(!n)return 1e9;double v=0;for(int i=0;i<26;i++){double e=n*f[i]/100.0,d=c[i]-e;v+=d*d/(e+0.0001);}return v;}
static void additive_attack(const char*cipher){struct Candidate{int k;double score;}v[26];char out[MAXBUF];for(int k=0;k<26;k++){for(int i=0;cipher[i];i++){char c=cipher[i];if(isalpha((unsigned char)c)){char b=isupper((unsigned char)c)?'A':'a';c=(char)(b+mod(c-b-k,26));}out[i]=c;}out[strlen(cipher)]=0;v[k].k=k;v[k].score=chi_score(out);}for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)if(v[j].score<v[i].score){struct Candidate t=v[i];v[i]=v[j];v[j]=t;}puts("Top 10 candidate decryptions (lower chi-square score is better):");for(int z=0;z<10;z++){int k=v[z].k;printf("%2d) shift=%2d score=%8.2f  ",z+1,k,v[z].score);caesar(cipher,-k);}}
static void mono_frequency_attack(const char*cipher){int count[26]={0},order[26],n=0;static const char*english="etaoinshrdlucmfwypvbgkjqxz";char map[26];for(int i=0;i<26;i++)order[i]=i;for(int i=0;cipher[i];i++)if(isalpha((unsigned char)cipher[i]))count[tolower((unsigned char)cipher[i])-'a']++,n++;for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)if(count[order[j]]>count[order[i]]){int t=order[i];order[i]=order[j];order[j]=t;}for(int i=0;i<26;i++)map[order[i]]=english[i];puts("Frequency-based candidate (heuristic; not guaranteed):");for(int i=0;cipher[i];i++){char c=cipher[i];if(isalpha((unsigned char)c)){char x=map[tolower((unsigned char)c)-'a'];c=islower((unsigned char)c)?x:(char)toupper((unsigned char)x);}putchar(c);}puts("");puts("Cipher letter counts:");for(int i=0;i<26;i++)if(count[i])printf("%c:%d ", 'A'+i,count[i]);puts("");puts("Top 10 simple variants: swap adjacent low-frequency assignments and inspect likely words:");for(int v=0;v<9;v++){char alt[26];memcpy(alt,map,26);int a=order[25-v],b=order[24-v];char t=alt[a];alt[a]=alt[b];alt[b]=t;printf("%2d) ",v+2);for(int i=0;cipher[i];i++){char ch=cipher[i];if(isalpha((unsigned char)ch)){char z=alt[tolower((unsigned char)ch)-'a'];ch=islower((unsigned char)ch)?z:(char)toupper((unsigned char)z);}putchar(ch);}puts("");}}
static void otp_numeric(const char*text,const int*key,int n,int decrypt){int j=0;for(int i=0;text[i];i++){char c=text[i];if(isalpha((unsigned char)c)){if(j>=n){puts("\nERROR: key stream is shorter than the plaintext.");return;}char b=isupper((unsigned char)c)?'A':'a';c=(char)(b+mod(c-b+(decrypt?-key[j]:key[j]),26));j++;}putchar(c);}puts("");}
static uint64_t modpow64(uint64_t a,uint64_t e,uint64_t m){uint64_t r=1%m;while(e){if(e&1)r=(uint64_t)((__uint128_t)r*a%m);a=(uint64_t)((__uint128_t)a*a%m);e>>=1;}return r;}
















static const int IP[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
static const int FP[64]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};
static const int E[48]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
static const int P[32]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
static const int S[8][4][16]={
{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
{{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
{{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
{{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
{{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
{{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
{{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
{{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
};
static const int PC1[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
static const int PC2[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
static const int SH[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
static uint64_t permute64(uint64_t x,const int*t,int n,int width){uint64_t y=0;for(int i=0;i<n;i++)y=(y<<1)|((x>>(width-t[i]))&1);return y;}
static void des_keys(uint64_t key,uint64_t sub[16]){uint64_t v=0;for(int i=0;i<56;i++)v=(v<<1)|((key>>(64-PC1[i]))&1);uint32_t c=(uint32_t)(v>>28),d=(uint32_t)(v&0xfffffff);for(int r=0;r<16;r++){int s=SH[r];c=((c<<s)|(c>>(28-s)))&0xfffffff;d=((d<<s)|(d>>(28-s)))&0xfffffff;uint64_t cd=((uint64_t)c<<28)|d;sub[r]=0;for(int j=0;j<48;j++)sub[r]=(sub[r]<<1)|((cd>>(56-PC2[j]))&1);}}
static uint32_t des_f(uint32_t r,uint64_t k){uint64_t e=0;for(int i=0;i<48;i++)e=(e<<1)|((r>>(32-E[i]))&1);e^=k;uint32_t o=0;for(int i=0;i<8;i++){int six=(int)((e>>(42-6*i))&63),row=((six&32)>>4)|(six&1),col=(six>>1)&15;o=(o<<4)|(uint32_t)S[i][row][col];}uint32_t z=0;for(int i=0;i<32;i++)z=(z<<1)|((o>>(32-P[i]))&1);return z;}
static uint64_t des_block(uint64_t x,uint64_t key,int decrypt){uint64_t sk[16];des_keys(key,sk);uint64_t z=permute64(x,IP,64,64);uint32_t l=(uint32_t)(z>>32),r=(uint32_t)z;for(int i=0;i<16;i++){uint32_t t=l^des_f(r,sk[decrypt?15-i:i]);l=r;r=t;}return permute64(((uint64_t)r<<32)|l,FP,64,64);}
static int parse_u64(const char*s,uint64_t*out){char*end=NULL;unsigned long long x=strtoull(s,&end,16);if(end==s||*end)return 0;*out=(uint64_t)x;return 1;}


static int evp_crypt(const char*name,const unsigned char*key,const unsigned char*iv,const unsigned char*in,int n,unsigned char*out,int encrypt,int padding){EVP_CIPHER*c=EVP_CIPHER_fetch(NULL,name,NULL);if(!c){fprintf(stderr,"Cipher %s unavailable (OpenSSL provider not loaded).\n",name);return -1;}EVP_CIPHER_CTX*x=EVP_CIPHER_CTX_new();int a=0,b=0,ok=EVP_CipherInit_ex2(x,c,key,iv,encrypt,NULL);if(ok&&padding>=0)EVP_CIPHER_CTX_set_padding(x,padding);if(ok)ok=EVP_CipherUpdate(x,out,&a,in,n);if(ok)ok=EVP_CipherFinal_ex(x,out+a,&b);EVP_CIPHER_CTX_free(x);EVP_CIPHER_free(c);return ok?a+b:-1;}

static int aes_pad80(const unsigned char*in,int n,unsigned char*out){int total=(n/16+1)*16;memcpy(out,in,n);out[n]=0x80;memset(out+n+1,0,total-n-1);return total;}
static int unpad80(unsigned char*p,int n){int i=n-1;while(i>=0&&p[i]==0)i--;if(i<0||p[i]!=0x80)return -1;return i;}
static void q21_mode(const char*mode){char kh[128],ivh[128],txt[MAXBUF];unsigned char key[16],iv[16],in[4096],pad[4128],out[4200],back[4200];readstr("AES-128 key (32 hex digits): ",kh,sizeof kh);readstr("IV (32 hex digits; ignored for ECB): ",ivh,sizeof ivh);readstr("Plaintext (UTF-8 text): ",txt,sizeof txt);if(unhex(kh,key,16)!=16){puts("AES key must be 16 bytes.");return;}memset(iv,0,16);if(strcmp(mode,"AES-128-ECB")&&unhex(ivh,iv,16)!=16){puts("IV must be 16 bytes.");return;}int n=(int)strlen(txt);memcpy(in,txt,n);int pn=aes_pad80(in,n,pad);int z=evp_crypt(mode,key,strcmp(mode,"AES-128-ECB")?iv:NULL,pad,pn,out,1,0);if(z<0){puts("Encryption failed.");return;}printf("%s padded ciphertext: ",mode);printhex(out,z);int b=evp_crypt(mode,key,strcmp(mode,"AES-128-ECB")?iv:NULL,out,z,back,0,0);int real=b<0?-1:unpad80(back,b);if(real>=0){back[real]=0;printf("Decrypted: %s\n",back);}else puts("Decryption/padding check failed.");}

static void q22(void);
static int perm_s(int x,const int*t,int n,int w){int y=0;for(int i=0;i<n;i++)y=(y<<1)|((x>>(w-t[i]))&1);return y;}
static void sdes_keys(int key,int*k1,int*k2){int p[]={3,5,2,7,4,10,1,9,8,6},q[]={6,3,7,4,8,5,10,9};int z=perm_s(key,p,10,10),l=z>>5,r=z&31;l=((l<<1)|(l>>4))&31;r=((r<<1)|(r>>4))&31;*k1=perm_s((l<<5)|r,q,8,10);l=((l<<2)|(l>>3))&31;r=((r<<2)|(r>>3))&31;*k2=perm_s((l<<5)|r,q,8,10);}
static int sdes_f(int r,int key){int ep[]={4,1,2,3,2,3,4,1},p[]={2,4,3,1};int s0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}},s1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};int x=perm_s(r,ep,8,4)^key,a=x>>4,b=x&15;int u=s0[((a&8)>>2)|(a&1)][(a>>1)&3],v=s1[((b&8)>>2)|(b&1)][(b>>1)&3];return perm_s((u<<2)|v,p,4,4);}
static int sdes_byte(int x,int key,int dec){int ip[]={2,6,3,1,4,8,5,7},fp[]={4,1,3,5,7,2,8,6},a,b;sdes_keys(key,&a,&b);int z=perm_s(x,ip,8,8),l=z>>4,r=z&15,t=l^sdes_f(r,dec?b:a);l=r;r=t;t=l^sdes_f(r,dec?a:b);return perm_s((t<<4)|r,fp,8,8);}








static void aes_block(const unsigned char key[16],const unsigned char in[16],unsigned char out[16]){EVP_CIPHER*c=EVP_CIPHER_fetch(NULL,"AES-128-ECB",NULL);EVP_CIPHER_CTX*x=EVP_CIPHER_CTX_new();int a=0,b=0;EVP_EncryptInit_ex2(x,c,key,NULL,NULL);EVP_CIPHER_CTX_set_padding(x,0);EVP_EncryptUpdate(x,out,&a,in,16);EVP_EncryptFinal_ex(x,out+a,&b);EVP_CIPHER_CTX_free(x);EVP_CIPHER_free(c);}
#endif
