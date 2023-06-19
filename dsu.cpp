    #include <bits/stdc++.h>
typedef std::vector<int> vi;
typedef long long ll;
#define eb emplace_back
#define print(a) for(auto it:a) std::cout<<it<<" ";
#define nl "\n" 
#define inp(v) for(auto &it:v) std::cin>>it;
#define all(a) begin(a),end(a)
// #define cerr if(false)cerr
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;
#define yy cout<<"YES"<<"\n" 
#define nn cout<<"NO"<<"\n" 

using namespace std;

class dsu{

    vector<int>par;
    vector<int>rank;
    int n;

    public:
    dsu(int n){
        this->n = n+1;        
        par.resize(this->n);
        rank.resize(this->n,1);
        for(int i=0;i<this->n;i++)par[i] = i;        
    }

    int getPar(int n){
        if(par[n] == n)return n;
        return par[n] = getPar(par[n]);
    }

    bool find(int x,int y){
        return getPar(x) == getPar(y);
    }

    void _union(int x,int y){
        int px = getPar(x);
        int py = getPar(y);
        if(px == py) return;
        if(rank[px] >= rank[py]){
            if(rank[px] == rank[py]) rank[px]++;
            par[py] = px;
        }
        else{
            par[px] = py;
        }
       return;
    }
};

int main(){
    cout<<fixed<<setprecision(5);
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    time_t start, end;
    time(&start);
    // dsu* d = new dsu(6);
    // cout<<boolalpha;
    dsu d(100);    
    d._union(1,2);
    d._union(1,3);
    d._union(1,4);
    d._union(5,6);
    d._union(6,8);
    d._union(9,7);
    d._union(7,6);    
    d._union(1,9);  
    if(d.find(4,90))
        cout<<"yes"<<nl;
    else  
        nn;  
    // for(int i=0;i<10000;i++){
    //     for(int j=0;j<10000;j++){
    //         d._union(i,j);
    //     }
    // }
    // cout<<d.find(5,1)<<nl;    
    // time(&end);
    // double time_taken = double(end - start);
    // cout<<typeid(time_taken).name()<<nl;
    // cout<<time_taken;

}