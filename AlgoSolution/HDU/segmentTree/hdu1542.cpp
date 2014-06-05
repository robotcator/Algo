#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct Line{
    double x;
    double y1, y2;
    int flag;   // left or right
}line[250];

struct Node{
    int l, r;
    int cover;
    double area;
}st[100005];

double y[250];
double ty[250]; //去除重复元素的y[]

int cmp(Line a, Line b)
{
    return a.x < b.x;
}

void build(int root, int left, int right)
{
    st[root].l = left;
    st[root].r = right;
    st[root].cover = 0;
    st[root].area = 0;
    if(left+1 < right){
        int mid = (left+right)/2;
        build(root*2, left, mid);
        build(root*2+1, mid, right);
    }
}

void update(int root)
{
    if(st[root].cover > 0)
        // 完全被覆盖的
        st[root].area = ty[st[root].r-1] - ty[st[root].l-1];
    else if(st[root].r - st[root].l == 1) st[root].area = 0;
    else {
        st[root].area = st[2*root].area + st[2*root+1].area;
    }
}

void Insert(int root, int left, int right)
{
    if(left <= st[root].l && st[root].r <= right){
        st[root].cover ++;
        update(root);
        return ;
    }
    if(st[root].r - st[root].l == 1) return ;
    int mid = (st[root].l + st[root].r)/2;
    if(left < mid) Insert(root*2, left, right);
    if(right > mid) Insert(root*2+1, left, right);
    update(root);//why?
}

void Delete(int root, int left, int right)
{
    if(left <= st[root].l && st[root].r <= right){
        st[root].cover --;
        update(root);
        return ;
    }
    if(st[root].r - st[root].l == 1) return ;
    int mid = (st[root].l + st[root].r)/2;
    if(left < mid) Delete(root*2, left, right);
    if(right > mid) Delete(root*2+1, left, right);
    update(root);//why?

}

int binary(double x, int left, int right)
{
    int l = left;
    int r = right-1;
    int mid;
    while(l < r){
        mid = (l+r)/2;
        if(x > ty[mid]) l = mid + 1;
        else r = mid;
    }
    return r+1;
}

int main()
{
    int n;
    double x1, y1, x2, y2;
    int count = 0;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        int m = 0;
        for(int i = 0; i < n; i ++){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            y[m] = y1;
            line[m].x = x1;
            line[m].y1 = y1;
            line[m].y2 = y2;
            line[m].flag = 0;
            m ++;

            y[m] = y2;
            line[m].x = x2;
            line[m].y1 = y1;
            line[m].y2 = y2;
            line[m].flag = 1;
            m ++;
        }

        sort(line, line+m, cmp);
        sort(y, y+m);
        ty[0] = y[0];
        int num = 1;
        for(int i = 1; i < m; i ++){
            if(y[i] != y[i-1])
                ty[num++] = y[i];
        }
       //for(int i = 0; i < num; i ++)
       //     cout << ty[i] << " ";
       // cout << endl;

        double ans = 0;
        build(1, 1, num);
        for(int i = 1; i < num<<1; i ++){
            cout << st[i].l << "---" << st[i].r << endl;
            cout << st[i].area << endl;
        }
        for(int i = 0; i < m-1; i ++){
            int l = binary(line[i].y1, 0, num);
            int r = binary(line[i].y2, 0, num);
            cout << "第几次 " << i << endl;
            cout << "l -- r" << l << r << endl;
            if(line[i].flag == 0) Insert(1, l, r);
            else Delete(1, l, r);
            ans += (line[i+1].x-line[i].x)*st[1].area;
        for(int j = 1; j < num<<1; j ++){
            cout << st[j].l << "---" << st[j].r << endl;
            cout << st[j].area << endl;
            cout << st[j].cover << endl;
        }
        }
        printf("Test case #%d\n", ++count);
        printf("Total explored area: %.2lf\n", ans );
        printf("\n");
    }
    return 0;
}
