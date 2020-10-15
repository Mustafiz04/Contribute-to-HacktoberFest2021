#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using std::vector;
struct point{
	int x; int y; int parent; int rank;
	point(int a, int b, int c, int d):x(a), y(b), parent(c), rank(d){}
};
struct Edge{
	int indexa, indexb;
	double length;
	Edge(int a, int b, double c):indexa(a), indexb(b), length(c){}
};
double distance(int x1, int y1, int x2, int y2){
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
struct sort_edges{
	inline bool operator()(const Edge& struct1, const Edge& struct2){
		return (struct1.length < struct2.length);
	}
};
int find(int i, vector<point> &points){
	int x=i;
	while(i != points[i].parent)
		i=points[i].parent;
	points[x].parent=i;
	return i;
}
void Union(int a, int b, vector<point> &points){
	if(points[a].rank < points[b].rank)
		points[a].parent = b;
	else {
		points[b].parent = a;
		if(points[a].rank == points[b].rank){
			points[a].rank++;
		}		
	}	
}
double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.0;
  vector<point> points;
  for(int i=0; i<x.size(); i++){
  	points.push_back({x[i], y[i], i, 0});
  }
  vector<Edge> edges;
  for(int i=0; i<x.size(); i++){
  	for(int j=i+1; j<x.size(); j++){
  		edges.push_back({i, j, distance(x[i], y[i], x[j], y[j])});
	}
  }
  std::sort(edges.begin(), edges.end(), sort_edges());
  for(int i=0; i<edges.size(); i++){
	int x=find(edges[i].indexa, points);
	int y=find(edges[i].indexb, points);
  	if(x!=y){
  		result += edges[i].length;
  		Union(x, y, points);
	  }
  };
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
