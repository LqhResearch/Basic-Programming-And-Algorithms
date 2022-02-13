#include<stdio.h>
#include<math.h>
/*
	Cho ban co vua kich thuoc (8x8).
	Hay sap 8 quan hau vao ban co sao cho khong co bat ki 2 quan hau nao co the an nhau.
*/
int arr[20];
bool Ok(int x2, int y2){
	//Kiem tra cach dat co thoa man khong
    for(int i = 1; i < x2; i++)
        if(arr[i] == y2 || abs(i - x2) == abs(arr[i] - y2))
            return false;
    //Neu kiem tra het cac truong hop vao khong sai thu tra ve true
    return true;
}
 
void Xuat(int n){
    //In ra mot ket qua
    for(int i=1; i<=n; i++)
        printf("%5d", arr[i]);
    printf("\n");
}
 
void Try(int i, int n){
    for(int j=1; j<=n; j++) //Thu dat quan hau tu 1 den n
        if(Ok(i, j) == true) {
            //Neu cach dat nay thoa man thu luu lai vi tri
            arr[i] = j;
            if(i==n) Xuat(n);	//Neu dat xong quan hau thi xuat ra mot ket qua
            Try(i+1,n);
        }
}
 
int main(){
    int n = 8; //Do ban co 8*8 nen n=8
    Try(1, n);
    return 0;
}
