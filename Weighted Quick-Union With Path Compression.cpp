//http://blog.csdn.net/dm_vincent/article/details/7655764
class UF {
private:
  int id[];
  int count;
  
public:
  UF(int N) {
		// Initialize component id array.
		count = N;
		id = new int[N];
		for (int i = 0; i < N; i++)
			id[i] = i;
	}
	
	int count() { 
	  return count; 
	}
	
	boolean connected(int p, int q) { 
	  return find(p) == find(q); 
	}
	
	int find(int p) {
	  while (p != id[p]) {
		  // 将p节点的父节点设置为它的爷爷节点
		  id[p] = id[id[p]];
		  p = id[p];
	  }
	  return p;
  }
  
  void union(int p, int q) {
	  int i = find(p);
	  int j = find(q);
	  if (i == j) return;
	  // 将小树作为大树的子树
	  if (sz[i] < sz[j]) { 
	    id[i] = j; 
	    sz[j] += sz[i]; 
	  } else { 
	    id[j] = i; 
	    sz[i] += sz[j]; 
	  }
	  count--;
  }
  
};
