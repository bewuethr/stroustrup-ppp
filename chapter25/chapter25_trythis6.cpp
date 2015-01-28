// Chapter 25, Try This 6: decrypt example text

#include<iostream>
#include<fstream>

using namespace std;

void decipher(const unsigned long *const v,
    unsigned long *const w,
    const unsigned long *const k)
{
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0xC6EF3720;
    unsigned long delta = 0x9E3779B9;
    unsigned long n = 32;

    while (n-- > 0) {
        z -= (y<<4 ^ y>>5) + y ^ sum + k[sum>>11 & 3];
        sum -= delta;
        y -= (z<<4 ^ z>>5) + z ^ sum + k[sum&3];
    }
    w[0] = y;
    w[1] = z;
}

int main()
try
{
    const int nchar = 2*sizeof(long);   // 64 bits
    const int kchar = 2*nchar;          // 128 bits
    const string ifname = "pics_and_txt/chapter25_trythis6_in.txt";
    const string ofname = "pics_and_txt/chapter25_trythis6_out.txt";
    
    string key = "bs";
    while (key.size() < kchar) key += '0';  // pad key

    ifstream inf(ifname);
    ofstream outf(ofname);
    if (!inf || !outf) throw runtime_error("can't open file");

    const unsigned long* k = reinterpret_cast<const unsigned long*>(key.data());

    unsigned long inptr[2];
    char outbuf[nchar+1];
    outbuf[nchar] = 0;  // terminator
    unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
    inf.setf(ios_base::hex,ios_base::basefield);

    while (inf >> inptr[0] >> inptr[1]) {
        decipher(inptr,outptr,k);
        outf << outbuf;
    }
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
}
catch (...) {
    cerr << "Exception\n";
}
