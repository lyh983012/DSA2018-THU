#define default_capacity 5;
typedef int rank0;

template <typename T> class vector
{
protected:
	rank0 _size;
	int _capacity;
	T* _element;
	int begin,end;
public:
	vector();
	vector(const T& vec);
	~vector();
	rank0 size(){ return _size;}
	rank0 capacity(){ return _capacity;}
	T get(rank0 r){if (0<=r && r<_size) return _element[r]; }
	T remove (rank0 r);
	void insert(int n,T x);
	T operator[](rank0 r){return _element[r];}
	int put(int n,T x){ _element[n]=x;return (++_size);}
	int expand();
	int treverse();
	int sort();
	int bubsort();
	int chosort();
	int bichsort();
	int shelsort();

private:

};

template <typename T> 
vector<T>::vector(){
	_capacity=default_capacity;
	_element= new T[_capacity];
	_size=0;
}

template <typename T> 
vector<T>::vector(const T& vec){
	_capacity=vec._capacity;
	_size=vec._size;
	_element=new T[_size];
	for(int i = 0;i<= _size-1;i++)
		_element[i]=vec[i];
}

template <typename T> 
vector<T>::~vector(){
	delete _element;
}

template <typename T> 
int vector<T>::expand(){
	if( _size<_capacity)
		return;
	 _capacity*=2;
 	T* temp=new T[ _capacity];
	for(int i =0;i<=_size-1;i++)
		temp[i]=_element[i];
	delete _element;
	_element=temp;
	return _size;
}

template <typename T> 
void vector<T>::insert(int n,T x){
	while(_size>_capacity-2)
		expand();
	for (int i=_size;i>n;i--)
		_element[_size]=_element[_size-1];
	_element[n]=x;
	_size++;
}

template <typename T>
int vector<T>::sort(){
	return 0;

}

template <typename T>
int vector<T>::bubsort(){

int temp;
int n=_size;
int* ap=_element;
for (int i=0;i<=n-1;i++)
	for (int j=0;j<=n-2-i;j++){
		if (ap[j]>ap[j+1])
		{
			temp=ap[j];
			ap[j]=ap[j+1];
			ap[j+1]=temp;
		}
	}

return 0;
}

template <typename T>
int vector<T>::chosort(){
int n=_size;
int* ap=_element;
int temp;

for (int i=1;i<=n-1;i++)
{
	int j=i-1;
	temp=ap[i];
	while(ap[i]<ap[j] && j>=0)
		j--;
	j+=1;
	for (int k=i;k>j;k--)
		ap[k]=ap[k-1];
	ap[j]=temp;
}

return 0;
}

template <typename T>
int vector<T>::bichsort(){
int n=_size;
int* ap=_element;
int temp;
int lo,hi;
for (int i=1;i<=n-1;i++)
{
	int j=i-1;
	temp=ap[i];
	lo=0,hi=j;
	while(1)
	{

		if (ap[i]<ap[j])
		{
			hi=j;
			j=(lo+j)/2;
		}
		else if
		{
			lo=j;
			j=(hi+j)/2;
		}
		else if(j==0 && ap[i]<ap[j])
			break;
		else (ap[i]>=ap[j] && ap[i]<=ap[j+1])
			break;
	}
	for (int k=i;k>j+1;k--)
		ap[k]=ap[k-1];
	ap[j]=temp;
}
return 0;
}

template <typename T>
int vector<T>::shelsort(){
int n=_size;
int* ap=_element;
int temp;
int h=n;
while(h>1)
{
h=h/2;
for (int i=h;i<=n-h;i+=h)
{
	int j=i-h;
	temp=ap[i];
	while(ap[i]<ap[j] && j>=0)
		j-=h;
	j+=h;
	for (int k=i;k>j;k--)
		ap[k]=ap[k-h];
	ap[j]=temp;
}
}

return 0;
}

