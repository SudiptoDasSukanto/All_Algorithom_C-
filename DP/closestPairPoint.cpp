#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x ,y ;
};

int compareX(const void* x ,const void* y){
    point *p1 = (point*) x ;
    point *p2 = (point*) y;
    return (p1->x!=p2->x)?(p1->x-p2->x):(p1->y-p2->y);
}

int compareY(const void* x ,const void* y){
    point *p1 = (point*) x ;
    point *p2 = (point*) y;
    return (p1->y!=p2->y)?(p1->y-p2->y):(p1->x-p2->x);
}

float dist(point p1,point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

pair<point,point> bruteforceAlgo(point p[] ,int size){
    float min = FLT_MAX;
    pair<point,point> pr ;
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size ; j++){
            if(dist(p[i],p[j])<min){
                min = dist(p[i],p[j]);
                pr = make_pair(p[i],p[j]);
            }
        }
    }
    return pr ;
}

pair<point,point> minMarkedPlaceDist(point p[],int size , float d,pair<point,point>&anspoint){
    float min = d ;
    for(int i= 0 ; i<size ; i++){
        for (int j=i+1 ; j<size && (p[j].y-p[i].y)<min ; j++){
            if(dist(p[i],p[j])<min){
                min = dist(p[i],p[j]);
                anspoint = make_pair(p[i],p[j]);
                cout << min << endl;
            }
        }
    }
    
    return anspoint;
}

pair<point,point> dividePointArray(point px[] ,point py[] , int size){
    if(size<=3) return bruteforceAlgo(px,size);

    int mid = size/2 ;
    point midPoint = px[mid];

    point pyLeft[mid];
    point pyRight[size-mid];
    int li = 0 , ri = 0;

    for(int i=0 ; i<size ; i++){
        if(li<mid && (py[i].x<midPoint.x || (py[i].x==midPoint.x && py[i].y<midPoint.y))){
            pyLeft[li++] =py[i];
        }else{
            pyRight[ri++] = py[i] ;
        }
    }

    pair<point,point> dlpoint = dividePointArray(px,pyLeft,mid);
    pair<point,point> drpoint = dividePointArray(px+mid,pyRight,size-mid);
    float dl = dist(dlpoint.first,dlpoint.second);
    float dr = dist(drpoint.first,drpoint.second);

    float d = min(dl,dr);

    pair<point,point> anspoint ;
    if(dl<dr) anspoint = dlpoint;
    else anspoint = drpoint ;

    point markedPlacePoint[size];
    int j = 0 ;
    for(int i=0 ; i<size ; i++){
        if(abs(py[i].x-midPoint.x)<d){
            markedPlacePoint[j] = py[i];
            j++;
        }
    }

    return minMarkedPlaceDist(markedPlacePoint,j,d,anspoint);

}

pair<point,point> closestDistance(point p[] , int size){
    point px[size];
    point py[size];

    for(int i=0 ; i<size ; i++){
        px[i] = p[i];
        py[i] = p[i];
    }

    qsort(px,size,sizeof(point),compareX);
    qsort(py,size,sizeof(point),compareY);

    return dividePointArray(px,py,size);
}



int main(){

    point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(p)/sizeof(p[0]);

    pair <point, point> pr =  closestDistance(p,n);
    cout << dist(pr.first,pr.second)<< endl;
    cout << pr.first.x <<" " << pr.first.y << endl;
    cout << pr.second.x <<" " << pr.second.y << endl;

}