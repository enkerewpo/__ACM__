// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int dis[100050];
int T, CC, Ts;
int vis[100050] = {0};
int heapsize = 0;
//togo heap[100050];
#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cstdint>
#include <limits>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;
#define reg register
/*
static char space[10000000],*sp=space;
template<typename T>
struct myalloc:allocator<T>{
    myalloc(){}
    template<typename T2>
    myalloc(const myalloc<T2> &a){}
    template<typename T2>
    myalloc<T>& operator=(const myalloc<T2> &a){return *this;}
    template<typename T2>
    struct rebind{typedef myalloc<T2> other;};
    inline T* allocate(size_t n){
        T *result=(T*)sp;sp+=n*sizeof(T);
        return result;
    }
    inline void deallocate(T* p,size_t n){}
};
vector< togo,myalloc<togo> >maap[100050];
*/
namespace radix_heap {
namespace internal {
template<bool Is64bit> class find_bucket_impl;

template<>
class find_bucket_impl<false> {
  public:
	static inline constexpr size_t find_bucket(uint32_t x, uint32_t last) {
		return x == last ? 0 : 32 - __builtin_clz(x ^ last);
	}
};

template<>
class find_bucket_impl<true> {
  public:
	static inline constexpr size_t find_bucket(uint64_t x, uint64_t last) {
		return x == last ? 0 : 64 - __builtin_clzll(x ^ last);
	}
};

template<typename T>
inline constexpr size_t find_bucket(T x, T last) {
	return find_bucket_impl<sizeof(T) == 8>::find_bucket(x, last);
}

template<typename KeyType, bool IsSigned> class encoder_impl_integer;

template<typename KeyType>
class encoder_impl_integer<KeyType, false> {
  public:
	typedef KeyType key_type;
	typedef KeyType unsigned_key_type;

	inline static constexpr unsigned_key_type encode(key_type x) {
		return x;
	}

	inline static constexpr key_type decode(unsigned_key_type x) {
		return x;
	}
};

template<typename KeyType>
class encoder_impl_integer<KeyType, true> {
  public:
	typedef KeyType key_type;
	typedef typename std::make_unsigned<KeyType>::type unsigned_key_type;

	inline static constexpr unsigned_key_type encode(key_type x) {
		return static_cast<unsigned_key_type>(x) ^
		       (unsigned_key_type(1) << unsigned_key_type(std::numeric_limits<unsigned_key_type>::digits - 1));
	}

	inline static constexpr key_type decode(unsigned_key_type x) {
		return static_cast<key_type>
		       (x ^ (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1)));
	}
};

template<typename KeyType, typename UnsignedKeyType>
class encoder_impl_decimal {
  public:
	typedef KeyType key_type;
	typedef UnsignedKeyType unsigned_key_type;

	inline static constexpr unsigned_key_type encode(key_type x) {
		return raw_cast<key_type, unsigned_key_type>(x) ^
		       ((-(raw_cast<key_type, unsigned_key_type>(x) >> (std::numeric_limits<unsigned_key_type>::digits - 1))) |
		        (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1)));
	}

	inline static constexpr key_type decode(unsigned_key_type x) {
		return raw_cast<unsigned_key_type, key_type>
		       (x ^ (((x >> (std::numeric_limits<unsigned_key_type>::digits - 1)) - 1) |
		             (unsigned_key_type(1) << (std::numeric_limits<unsigned_key_type>::digits - 1))));
	}

  private:
	template<typename T, typename U>
	union raw_cast {
public:
		constexpr raw_cast(T t) : t_(t) {}
		operator U() const { return u_; }

private:
		T t_;
		U u_;
	};
};

template<typename KeyType>
class encoder : public encoder_impl_integer<KeyType, std::is_signed<KeyType>::value> {};
template<>
class encoder<float> : public encoder_impl_decimal<float, uint32_t> {};
template<>
class encoder<double> : public encoder_impl_decimal<double, uint64_t> {};
}  // namespace internal

template<typename KeyType, typename EncoderType = internal::encoder<KeyType>>
class radix_heap {
  public:
	typedef KeyType key_type;
	typedef EncoderType encoder_type;
	typedef typename encoder_type::unsigned_key_type unsigned_key_type;

	radix_heap() : size_(0), last_(), buckets_() {
		buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
	}

	void push(key_type key) {
		const unsigned_key_type x = encoder_type::encode(key);
		assert(last_ <= x);
		++size_;
		const size_t k = internal::find_bucket(x, last_);
		buckets_[k].emplace_back(x);
		buckets_min_[k] = std::min(buckets_min_[k], x);
	}

	key_type top() {
		pull();
		return encoder_type::decode(last_);
	}

	void pop() {
		pull();
		buckets_[0].pop_back();
		--size_;
	}

	size_t size() const {
		return size_;
	}

	bool empty() const {
		return size_ == 0;
	}

	void clear() {
		size_ = 0;
		last_ = key_type();
		for (auto &b : buckets_) b.clear();
		buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
	}

	void swap(radix_heap<KeyType, EncoderType> &a) {
		std::swap(size_, a.size_);
		std::swap(last_, a.last_);
		buckets_.swap(a.buckets_);
		buckets_min_.swap(a.buckets_min_);
	}

  private:
	size_t size_;
	unsigned_key_type last_;
	std::array < std::vector<unsigned_key_type>,
	    std::numeric_limits<unsigned_key_type>::digits + 1 > buckets_;
	std::array < unsigned_key_type,
	    std::numeric_limits<unsigned_key_type>::digits + 1 > buckets_min_;

	void pull() {
		assert(size_ > 0);
		if (!buckets_[0].empty()) return;

		size_t i;
		for (i = 1; buckets_[i].empty(); ++i);
		last_ = buckets_min_[i];

		for (unsigned_key_type x : buckets_[i]) {
			const size_t k = internal::find_bucket(x, last_);
			buckets_[k].emplace_back(x);
			buckets_min_[k] = std::min(buckets_min_[k], x);
		}
		buckets_[i].clear();
		buckets_min_[i] = std::numeric_limits<unsigned_key_type>::max();
	}
};

template<typename KeyType, typename ValueType, typename EncoderType = internal::encoder<KeyType>>
class pair_radix_heap {
  public:
	typedef KeyType key_type;
	typedef ValueType value_type;
	typedef EncoderType encoder_type;
	typedef typename encoder_type::unsigned_key_type unsigned_key_type;

	pair_radix_heap() : size_(0), last_(), buckets_() {
		buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
	}

	void push(key_type key, const value_type &value) {
		const unsigned_key_type x = encoder_type::encode(key);
		assert(last_ <= x);
		++size_;
		const size_t k = internal::find_bucket(x, last_);
		buckets_[k].emplace_back(x, value);
		buckets_min_[k] = std::min(buckets_min_[k], x);
	}

	void push(key_type key, value_type &&value) {
		const unsigned_key_type x = encoder_type::encode(key);
		assert(last_ <= x);
		++size_;
		const size_t k = internal::find_bucket(x, last_);
		buckets_[k].emplace_back(x, std::move(value));
		buckets_min_[k] = std::min(buckets_min_[k], x);
	}

	template <class... Args>
	void emplace(key_type key, Args&&... args) {
		const unsigned_key_type x = encoder_type::encode(key);
		assert(last_ <= x);
		++size_;
		const size_t k = internal::find_bucket(x, last_);
		buckets_[k].emplace_back(std::piecewise_construct,
		                         std::forward_as_tuple(x), std::forward_as_tuple(args...));
		buckets_min_[k] = std::min(buckets_min_[k], x);
	}

	key_type top_key() {
		pull();
		return encoder_type::decode(last_);
	}

	value_type &top_value() {
		pull();
		return buckets_[0].back().second;
	}

	void pop() {
		pull();
		buckets_[0].pop_back();
		--size_;
	}

	size_t size() const {
		return size_;
	}

	bool empty() const {
		return size_ == 0;
	}

	void clear() {
		size_ = 0;
		last_ = key_type();
		for (auto &b : buckets_) b.clear();
		buckets_min_.fill(std::numeric_limits<unsigned_key_type>::max());
	}

	void swap(pair_radix_heap<KeyType, ValueType, EncoderType> &a) {
		std::swap(size_, a.size_);
		std::swap(last_, a.last_);
		buckets_.swap(a.buckets_);
		buckets_min_.swap(a.buckets_min_);
	}

  private:
	size_t size_;
	unsigned_key_type last_;
	std::array < std::vector<std::pair<unsigned_key_type, value_type>>,
	    std::numeric_limits<unsigned_key_type>::digits + 1 > buckets_;
	std::array < unsigned_key_type,
	    std::numeric_limits<unsigned_key_type>::digits + 1 > buckets_min_;

	void pull() {
		assert(size_ > 0);
		if (!buckets_[0].empty()) return;

		size_t i;
		for (i = 1; buckets_[i].empty(); ++i);
		last_ = buckets_min_[i];

		for (size_t j = 0; j < buckets_[i].size(); ++j) {
			const unsigned_key_type x = buckets_[i][j].first;
			const size_t k = internal::find_bucket(x, last_);
			buckets_[k].emplace_back(std::move(buckets_[i][j]));
			buckets_min_[k] = std::min(buckets_min_[k], x);
		}
		buckets_[i].clear();
		buckets_min_[i] = std::numeric_limits<unsigned_key_type>::max();
	}
};
}
using namespace radix_heap;
/*
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
*/
inline void output(int a) {
	if (a < 0) {putchar('-'); a = -a;}
	if (a > 9)output(a / 10);
	putchar(a % 10 + '0');
}
/*
void push(togo d){
//	debug;
	int now,next;
	heap[++heapsize]=d;
//	debug;
	now=heapsize;
//	debug;
//	cout<<now<<" "<<next<<endl;
	while(now>1){
//		debug;
		next=now>>1;
//		cout<<next<<endl;
//		debug;
		if(heap[now].val>=heap[next].val)break;
		swap(heap[now],heap[next]);
		now=next;
	}
}
void pop(){
	int now,next;
//	debug;
	heap[1]=heap[heapsize--];
//	debug;
	now=1;
//	debug;
	while(now<<1<=heapsize){
		next=now<<1;
		if(next<heapsize&&heap[next+1].val<heap[next].val)next++;
		if(heap[now].val<=heap[next].val)break;
		swap(heap[now],heap[next]);
		now=next;
	}
}
*/
pair_radix_heap<int, int>heap;
#define dbg printf("Passing line %d\n",__LINE__)
#define re register int
#define fp(i,a,b) for(re i=a,I=b;i<=I;++i)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
char ss[1 << 17], *A = ss, *B = ss;
inline char gc() {if (A == B) {B = (A = ss) + fread(ss, 1, 1 << 17, stdin); if (A == B)return EOF;} return*A++;}
template<class T>inline void sdf(T&x) {
	char c; re y = 1; while (c = gc(), c < 48 || 57 < c)if (c == '-')y = -1; x = c ^ 48;
	while (c = gc(), 47 < c && c < 58)x = (x << 1) + (x << 3) + (c ^ 48); x *= y;
}
char sr[1 << 20], z[20]; int C = -1, Z;
template<class T>inline void wer(T x) {
	re y = 0; if (x < 0)y = 1, x = -x;
	while (z[++Z] = x % 10 + '0', x /= 10); if (y)z[++Z] = '-';
	while (sr[++C] = z[Z], --Z); sr[++C] = ' ';
}
struct node {int to, next, w;} a[404040];
int first[404040]; int tot = 0;
inline void add(int x, int y, int w) {
	tot++; a[tot].to = y; a[tot].w = w;
	a[tot].next = first[x]; first[x] = tot;
}
int main() {
//	pp=(p=in)+fread(in,1,10000000,stdin);
//	scanf("%d%d%d",&T,&C,&Ts);
//	T=read();C=read();Ts=read();
	sdf(T); sdf(CC); sdf(Ts);
	for (register int i = 1; i <= T + 10; i++)dis[i] = 0x7fffffff;
	for (int i = 1; i <= CC; i++) {
		int from, to, val;
//		scanf("%d%d%d",&from,&to,&val);
//		from=read();to=read();val=read();
		sdf(from); sdf(to); sdf(val);
		add(from, to, val); //add(to,from,val);
//		from=io.read_u32();to=io.read_u32();val=io.read_u32();
//		maap[from].push_back((togo){to,val});
//		if(from==Ts)dis[to]=val;
	}

//	for(int i=1;i<=T;i++)
//		for(int j=0;j<maap[i].size();j++)
//			push(maap[i][j].val);
//	dis[Ts]=0;
//	vis[Ts]=1;
//	for(int i=1;i<=T;i++){
//		int u,minval=0x7fffffff;
//		for(int j=1;j<=T;j++)if(!vis[j]&&dis[j]<minval)u=j,minval=dis[j];
//		vis[u]=1;
//		for(int v=1;v<=T;v++)
//			if(r[u][v])
//				if(dis[u]+maap[u][v]<dis[v])
//					dis[v]=dis[u]+maap[u][v];
//
//	}

	dis[Ts] = 0;
	heap.push(0, Ts); //push((togo){Ts,0});
	while (!heap.empty()) {
//		togo tmp=heap[1];
		int x = heap.top_value();
		heap.pop();
//		int x=tmp.to;
		if (vis[x])continue;
		vis[x] = 1;
		for (int k = first[x]; k != 0; k = a[k].next) {
			int w = a[k].to;
			int v = a[k].w;
//			cout<<"_________"<<v+dis[x]<<"_________"<<endl;
			if (v + dis[x] < dis[w]) {
				dis[w] = v + dis[x];
//				push((togo){w,dis[w]});
				heap.push(dis[w], w);
			}
		}
	}

	for (int i = 1; i <= T; i++)wer(dis[i]);
	fwrite(sr, 1, C + 1, stdout);

	return 0;
}