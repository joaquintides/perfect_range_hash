#include <vector>
#include <iostream>
#include <math.h>
#include <random>

int main()
{
  static constexpr std::size_t num_trials=1'000'000;

  std::size_t a=0;
  std::size_t delta=1;
  std::size_t n=100;
  std::cout<<"m;p;tp\n";
  for(std::size_t m=7;m<=14;++m){
    std::vector<unsigned char>                 buckets(std::size_t(1)<<m);
    std::mt19937_64                            rng(1012);
    std::uniform_int_distribution<std::size_t> d;
    std::size_t                                count=0;
    for(std::size_t i=0;i<num_trials;++i){
      for(auto& x:buckets)x=0;
      auto c=d(rng);
      for(std::size_t j=0;j<n;++j){
        auto pos=(c*(a+delta*j))>>(sizeof(std::size_t)*CHAR_BIT-m);
        if(buckets[pos])goto next;
        buckets[pos]=1;
      }
      ++count;
    next:;
    }
    double p=(double)count/num_trials;
    double tp=(1.0-std::pow(2.0,std::ceil(std::log(n)/std::log(2.0))-m-1))*std::pow(1.-n/std::pow(2,m),0.75);
    std::cout<<m<<";"<<p<<";"<<tp<<"\n";
  }
}
