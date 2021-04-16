#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

namespace HourglassSum {

    template<typename Type>
    void convolve2d(vector<vector<Type>>& out, const vector<vector<Type>>& filt, const vector<vector<Type>>& in){

        auto n1=out.size();
        auto m1=in.size();
        auto nf1=filt.size();
        if(m1 != nf1+n1-1) throw std::length_error("outer vec wrong size");
        for(int i1=0; i1<out.size(); i1++) 
            for(int f1=0; f1<filt.size(); f1++){
                auto n2=out[i1].size();
                auto m2=in[i1+f1].size();
                auto nf2=filt[f1].size();
                if(m2 != nf2+n2-1) throw std::length_error("inner vec wrong size");
                for(int i2=0; i2<out[i1].size(); i2++)
                    for(int f2=0; f2<filt[f1].size(); f2++){
                        out[i1][i2] +=filt[f1][f2]*in[i1+f1][i2+f2];
                    }
            }
    }
    template<typename oType, typename Type>
    oType sum(vector<vector<Type>> out){
        return std::accumulate(out.begin(),out.end(),0, [](oType sum, auto vec){
            return std::accumulate(vec.begin(),vec.end(),sum, [](oType s, auto v){ return s+v;});
        });
    }

    vector<vector<int>> filter ={{1,1,1},{0,1,0},{1,1,1}};

    double hourglass_sum(const vector<vector<int>>& input){
        vector<vector<int>> out(input.size()-filter.size()+1,vector<int>(input[0].size()-filter[0].size()+1,0));
        convolve2d(out,filter,input);

        return sum<double>(out);
    }


}

#ifndef RunTests
int main(int argc, const char* argv[])
{
    vector<vector<int>> input ={{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
    int sum =  HourglassSum::hourglass_sum(input);
    int sum_hglass4x4 =  8;
    int sum_hglass5x5 = sum_hglass4x4 + 4*1 +3; //two more from two extra sides + 3 from bottom corner 
    std::cout << "sum : " << sum << std::endl;  
    if(sum==(sum_hglass5x5+4+3)) std::cout << "test_passed" << std::endl;
    else std::cout << "test_failed" << std::endl;
}
#endif