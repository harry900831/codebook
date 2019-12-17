//tioj 1305
#define MOD 1000000007
int Rand(){
	return (1LL*rand()*rand()%MOD+rand())%MOD;
}
srand(time(NULL));

//
struct Treap{
	struct Node{
		Node *l,*r;
		int val,sz,pri;
		Node(int _val): l(NULL),r(NULL),val(_val),sz(1),pri(Rand()){}
	}*root;
	void init(){root = NULL;}
	int size(Node *x){return x ? x->sz : 0;}
	void pull(Node *x){
		x->sz = 1;
		x->sz += size(x->l)+size(x->r);
	}
	Node* merge(Node *a,Node *b){
		if(!a || !b)return a?a:b;
		if(a->pri < b->pri){
			a->r = merge(a->r,b);
			pull(a);
			return a;
		}else{
			b->l = merge(a,b->l);
			pull(b);
			return b;
		}
	}
	void split(Node *o,int k,Node* &a,Node* &b){
		if(!o){
			a = b = NULL;
			return;
		}
		if(o->val < k){
			a = o;
			split(o->r,k,a->r,b);
			pull(a);
		}else{
			b = o;
			split(o->l,k,a,b->l);
			pull(b);
		}
	}
	void insert(int x){
		Node *a,*b;
		split(root,x,a,b);
		Node* tmp = new Node(x);
		root = merge(a,merge(tmp,b));
	}
	void erase(int x){
		Node *a,*b,*c,*d;
		split(root,x,a,b);
		split(b,x+1,c,d);
		delete c;
		root = merge(a,d);
	}
	//kth_small
	int find_kth(Node *now,int k){
		if(size(now->l)+1 == k)return now->val;
		if(size(now->l)+1 > k){
			return find_kth(now->l,k);
		}else{
			return find_kth(now->r,k-size(now->l)-1);
		}
	}
}treap;


//toj 31 MLE/RE
#include <bits/stdc++.h>
#define lld long long
#define PB push_back
#define F first
#define S second
#define jizz cin.tie(0);ios_base::sync_with_stdio(0);
#define endl '\n'
#define INF 500000007
using namespace std;
#define MOD 1000000007
int Rand(){
	return ((1LL*rand()*rand()%MOD)+MOD)%MOD;
}
struct Treap{
    struct Node{
        Node *l,*r;
        int pri,val,sum,mx,lmx,rmx,sz;
        bool rev;
        Node(int _val):l(NULL),r(NULL),pri(Rand()),val(_val),sum(_val),mx(_val),lmx(_val),rmx(_val),sz(1),rev(0){}
    }*root;


    void init(){root = NULL;}
	int size(Node *x){return x?x->sz:0;}
    int getsum(Node *x){return x?x->sum:0;}
    int getmx(Node *x){return x?x->mx:-INF;}
    int getlmx(Node *x){return x?x->lmx:-INF;}
    int getrmx(Node *x){return x?x->rmx:-INF;}
	void pull(Node *x){
        x->sum = getsum(x->l)+getsum(x->r)+x->val;
        x->mx = max({getmx(x->l),getmx(x->r),max(getrmx(x->l),0)+x->val+max(0,getlmx(x->r))});
        x->lmx = max({getlmx(x->l),x->val+getsum(x->l)+max(0,getlmx(x->r))});
        x->rmx = max({getrmx(x->r),x->val+getsum(x->r)+max(0,getrmx(x->l))});
		x->sz = size(x->l)+size(x->r)+1;
	}
	void push(Node *x){
		if(x->rev){
			x->rev = 0;
			swap(x->l,x->r);
			if(x->l){
                swap(x->l->lmx,x->l->rmx);
                x->l->rev = !x->l->rev;
			}
			if(x->r){
                swap(x->r->lmx,x->r->rmx);
				x->r->rev = !x->r->rev;
			}
            pull(x);
		}
	}

    Node* merge(Node *a,Node *b){
        if(!a || !b)return a?a:b;
        push(a);push(b);
        if(a->pri < b->pri){
            a->r = merge(a->r,b);
            pull(a);
            return a;
        }else{
            b->l = merge(a,b->l);
            pull(b);
            return b;
        }
    }
    void split(Node *o,int k,Node* &a,Node* &b){
        if(!o){a = b = NULL;return;}
        push(o);
        if(size(o->l)+1 <= k){
            a = o;
            split(o->r,k-size(o->l)-1,a->r,b);
            pull(a);
        }else{
            b = o;
            split(o->l,k,a,b->l);
            pull(b);
        }
    }
	void insert(int p,int k,int *c){
		Node *a,*b;
		split(root,p,a,b);
		Node *tmp = NULL;
		for(int i = 0; i < k; i++){
			Node *t = new Node(c[i]);
			tmp = merge(tmp,t);
		}
		root = merge(a,merge(tmp,b));
	}
    void remove(int p,int k){
        Node *a,*b,*c,*d;
        split(root,p-1,a,b);
        split(b,k,c,d);
        delete c;
        root = merge(a,d);
    }
    void make_same(int p,int k,int l){
        Node *a,*b,*c,*d;
        split(root,p-1,a,b);
        split(b,k,c,d);
        delete c;
		Node *tmp = NULL;
        for(int i = 0; i < k; i++){
            Node *t = new Node(l);
            tmp = merge(tmp,t);
        }
        root = merge(a,merge(tmp,d));
    }
    void reverse(int p,int k){
        Node *a,*b,*c,*d;
        split(root,p-1,a,b);
        split(b,k,c,d);
        c->rev = !c->rev;
        root = merge(a,merge(c,d));
    }
    int get_sum(int p,int k){
        Node *a,*b,*c,*d;
        split(root,p-1,a,b);
        split(b,k,c,d);
        int res = c->sum;
        root = merge(a,merge(c,d));
        return res;
    }
    int max_sum(){
        return root->mx;
    }

	void travel(Node *x){
		if(x == NULL)return;
		push(x);
		travel(x->l);
		cout << x-> val << ' ';
		travel(x->r);
	}
}treap;

int a[1000005];
signed main(){jizz
	int n,m;cin >> n >> m;
	treap.init();
	for(int i = 0; i < n; i++)cin >> a[i];
	treap.insert(0,n,a);
	while(m--){
		string s;cin >> s;
		if(s == "INSERT"){
			int p,k;cin >> p >> k;
			for(int i = 0; i < k; i++)cin >> a[i];
			treap.insert(p,k,a);
		}else if(s == "DELETE"){
			int p,k;cin >> p >> k;
			treap.remove(p,k);
		}else if(s == "MAKE-SAME"){
			int p,k,l;cin >> p >> k >> l;
			treap.make_same(p,k,l);
		}else if(s == "REVERSE"){
			int p,k;cin >> p >> k;
			treap.reverse(p,k);
		}else if(s == "GET-SUM"){
			int p,k;cin >> p >> k;
			cout << treap.get_sum(p,k) << endl;
		}else{
			cout << treap.max_sum() << endl;
		}
	//	treap.travel(treap.root);cout << endl;
	}


	return 0;
}


