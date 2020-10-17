#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Barang
{
   char Nama_Barang[1000];
   int stok;
}Barang;

typedef struct Order
{
	char Nama_Barang[1000];
	int Nama_O, stok;
}Order;
	
Barang Gudang[100];
Order Order_Barang[100];

void swap(Barang *xp, Barang *yp) 
{ 
    Barang temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void sortBarang(Barang arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j].stok > arr[j+1].stok) 
              swap(&arr[j], &arr[j+1]); 
}

void LoadBarang (int &banyakBarang)
{
	FILE *barangptr;

	
    if ((barangptr = fopen("Barang.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);   
    }
    
	printf("\n");
	
	int i = 0;
	while(!feof(barangptr))
    {
    	fscanf(barangptr, "%s %d%*c",&Gudang[i].Nama_Barang, &Gudang[i].stok);
		i++;
	}
	
    fclose(barangptr);
    banyakBarang = i;
}

void TampilkanBarang(int banyakBarang)
{	
    FILE *barangptr;

	
    if ((barangptr = fopen("Barang.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);   
    }
    
	printf("\n");
	
	int i = 0;
		printf("|No |	 Nama Barang	   | Stok |\n");
	while(!feof(barangptr))
    {
    	fscanf(barangptr, "%s %d%*c",&Gudang[i].Nama_Barang, &Gudang[i].stok);
		printf("|%d  | %-20s | %-5d|\n", i+1,Gudang[i].Nama_Barang, Gudang[i].stok);
		i++;
	}
	
    fclose(barangptr);
    banyakBarang = i;
}

void SearchBarang(int banyakBarang, int cari)
{	
    FILE *barangptr;

	
    if ((barangptr = fopen("Barang.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);   
    }
    
	printf("\n");
	
	int i = 0;
	while(!feof(barangptr))
    {
    	fscanf(barangptr, "%s %d%*c",&Gudang[i].Nama_Barang, &Gudang[i].stok);
		i++;
	}
	
    fclose(barangptr);
    banyakBarang = i;
	
	printf("|No |	 Nama Barang	   | Stok |\n");
	int no = 1;
	for(i = 0; i < banyakBarang; i++) {
		if (Gudang[i].stok == cari) {
			printf("|%d  | %-20s | %-5d|\n", no,Gudang[i].Nama_Barang, Gudang[i].stok);
			no++;
		}
	}
}

void TambahBarang(int bykBarang)
{
	FILE *barangptr;
	
    if ((barangptr = fopen("Barang.txt", "w")) == NULL)
    {
        printf("Error! opening file");
        exit(1);   
    }
    
    fprintf(barangptr, "\n%s %d", Gudang[0].Nama_Barang, Gudang[0].stok);
    fclose(barangptr);
	
	for(int i=1; i < bykBarang; i++) {
		if ((barangptr = fopen("Barang.txt", "a")) == NULL)
    	{
        	printf("Error! opening file");
        	exit(1);   
		}
		
		fprintf(barangptr, "\n%s %d", Gudang[i].Nama_Barang, Gudang[i].stok);
    	fclose(barangptr);
	}
}
void saveOrder(char *Nama_Barang, int Nama_O, int stok, int &bykOrder)
{
	int i = bykOrder;
	strcpy(Order_Barang[i].Nama_Barang, Nama_Barang);
	Order_Barang[i].Nama_O = Nama_O;
	Order_Barang[i].stok = stok;
	FILE *order;
	
	order = fopen ("Order.txt", "a"); 
    if (order == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }

	bykOrder++;
	fprintf(order, "\n%s %d %d", Order_Barang[i].Nama_Barang, Order_Barang[i].Nama_O, Order_Barang[i].stok); 
	
	fclose(order);
}

void clrscr()
{
	system ("@cls||clear");
}

void swap(Order *xp, Order *yp) 
{ 
    Order temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void SearchBarang2(int banyakBarang2, int cari2)
{	
    FILE *barangptr;

	
    if ((barangptr = fopen("Order.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);   
    }
    
	printf("\n");
	
	int i = 0;
	while(!feof(barangptr))
    {
    	fscanf(barangptr, "%s %d %d%*c",&Order_Barang[i].Nama_Barang,&Order_Barang[i].Nama_O,&Order_Barang[i].stok);
		i++;
	}
	
    fclose(barangptr);
    banyakBarang2 = i;
	
	printf("|No |	 Nama Barang	   | Gudang | Stok |\n");
	int no = 1;
	for(i = 0; i < banyakBarang2; i++) {
		if (Order_Barang[i].Nama_O == cari2) {
			printf("|%d  | %-20s | %-7d| %-5d|\n", no,Order_Barang[i].Nama_Barang,Order_Barang[i].Nama_O, Order_Barang[i].stok);
			no++;
		}
	}
}

void TambahBarang2(int bykBarang2)
{
	FILE *barangptr;
	
    if ((barangptr = fopen("Order.txt", "w")) == NULL)
    {
        printf("Error! opening file");
        exit(1);   
    }
    
    fprintf(barangptr, "\n%s %d %d", Order_Barang[0].Nama_Barang,Order_Barang[0].Nama_O, Gudang[0].stok);
    fclose(barangptr);
	
	for(int i=1; i < bykBarang2; i++) {
		if ((barangptr = fopen("Order.txt", "a")) == NULL)
    	{
        	printf("Error! opening file");
        	exit(1);   
		}
		
		fprintf(barangptr, "\n%s %d %d", Order_Barang[i].Nama_Barang,Order_Barang[i].Nama_O, Gudang[i].stok);
    	fclose(barangptr);
	}
}

void sortBarang2(Order arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j].Nama_O > arr[j+1].Nama_O) 
              swap(&arr[j], &arr[j+1]); 
}

void LoadBarang2 (int &banyakBarang2)
{
	FILE *barangptr;

	
    if ((barangptr = fopen("Order.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);   
    }
    
	printf("\n");
	
	int i = 0;
	while(!feof(barangptr))
    {
    	fscanf(barangptr, "%s %d %d%*c",&Order_Barang[i].Nama_Barang,&Order_Barang[i].Nama_O,&Order_Barang[i].stok);
		i++;
	}
	
    fclose(barangptr);
    banyakBarang2 = i;
}


void TampilkanBarang2(int banyakBarang2)
{	
    FILE *barangptr;

	
    if ((barangptr = fopen("Order.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);   
    }
    
	printf("\n");
	
	int i = 0;
		printf("|No |	 Nama Barang	   | Gudang | Stok |\n");
	while(!feof(barangptr))
    {
    	fscanf(barangptr, "%s %d %d%*c",&Order_Barang[i].Nama_Barang,&Order_Barang[i].Nama_O,&Order_Barang[i].stok);
		printf("|%d  | %-20s | %-7d| %-5d|\n", i+1,Order_Barang[i].Nama_Barang,Order_Barang[i].Nama_O, Order_Barang[i].stok);
		i++;
	}
	
    fclose(barangptr);
    banyakBarang2 = i;
}
	
int main()
{
	int banyakBarang = 0, banyakOrder = 0;
	int banyakBarang2 = 0;
	int choice;
	char username[100],password[100];
	do{
	clrscr();
	printf("==========================\n");
	printf("=------LOGIN PAGE--------=\n");
	printf("==========================\n\n");
	printf("Username	: ");
	scanf("%s",&username);
	printf("Password	: ");
	scanf("%s",&password);
	
	}while((strcmp(username,"user1")!=0 || strcmp(password,"user1")!=0) && (strcmp(username,"user2")!=0 || strcmp(password,"user2")!=0));
	if(strcmp(username,"user1")==0 || strcmp(username,"user1")==0){
		do
		{
			LoadBarang(banyakBarang);	
			printf("\n===============================================\n");
			printf("\tSelamat Datang @ Gudang Indomart\n");
			printf("===============================================\n");
		
			printf("1. Tampilkan Stok Barang\n");
			printf("2. Tambah Data Barang\n");
			printf("3. Sort\n");
			printf("4. Search\n");
			printf("5. Exit\n");
	
			do
			{
				printf("Masukkan Pilihan Anda [1..5] : ");
				scanf("%d", &choice);
			} while (choice > 5 || choice < 1);
			switch(choice){
				case 1:
					clrscr();
					TampilkanBarang(banyakBarang);
				break;
				case 2:
					clrscr();
					TampilkanBarang(banyakBarang);
					char nama_barang[1000];
					int stok;
					printf("Masukkan Nama Barang : ");
					scanf("%s", &nama_barang);
					printf("Masukkan Stok Barang : ");
					scanf("%d", &stok);
					
					strcpy(Gudang[banyakBarang].Nama_Barang,nama_barang);
					Gudang[banyakBarang].stok = stok;
					banyakBarang++;
					TambahBarang(banyakBarang);
					
					printf("Data berhasil ditambahkan \n");
				break;
				case 3:
					clrscr();
					LoadBarang(banyakBarang);
					sortBarang(Gudang, banyakBarang);
					TambahBarang(banyakBarang);
					TampilkanBarang(banyakBarang);
					break;
				case 4:
					clrscr();
					int cari;
					printf("Masukkan stok yang ingin di cari: ");
					scanf("%d", &cari);
					SearchBarang(banyakBarang, cari);
					break;
			}
		} while (choice != 5);
	}
	else{
		do
		{
			LoadBarang(banyakBarang);	
			printf("\n==========================================\n");
			printf("\tSelamat Datang @ Gudang Indomart\n");
			printf("==========================================\n");
		
			printf("1. Tampilkan Stok Barang\n");
			printf("2. Ambil Barang\n");
			printf("3. Sort\n");
			printf("4. Search\n");
			printf("5. Exit\n");
	
			do
			{
				printf("Masukkan Pilihan Anda [1..5] : ");
				scanf("%d", &choice);
			} while (choice > 5 || choice < 1);
			switch(choice){
				case 1:
					clrscr();
					TampilkanBarang2(banyakBarang2);
				break;
				case 2:
					clrscr();
					int namaOrder;
					int n,j;
					TampilkanBarang(banyakBarang);
					do
					{
						printf("Masukkan nomor barang [1..%d]", banyakBarang);
						scanf("%d", &n);
					} while (n > banyakBarang || n < 1);
					
					if (Gudang[n-1].stok > 0)
					{
						do
						{
							printf("Jumlah barang yang diambil [1..%d]", Gudang[n-1].stok);
							scanf("%d", &j);
						} while (j > Gudang[n-1].stok || j < 1);
						
						printf("Nomor Gudang Orderan : ");
						scanf("%d", &namaOrder);
						
						printf("Barang %s diorder oleh Gudang %d sejumlah %d barang\n", Gudang[n-1].Nama_Barang, namaOrder, j);
						
//						LoadPinjam(banyakPinjam);
						saveOrder(Gudang[n-1].Nama_Barang, namaOrder, j, banyakOrder);
						
						Gudang[n-1].stok -= j;
						
						TambahBarang(banyakBarang);
						printf("Data anda telah tersimpan!!!");
					}
				break;
				case 3:
					clrscr();	
					LoadBarang2(banyakBarang2);
					sortBarang2(Order_Barang, banyakBarang2);
					TambahBarang2(banyakBarang2);
					TampilkanBarang2(banyakBarang2);
					break;
				case 4:
					clrscr();
					int cari2;
					printf("Masukkan No Gudang yang ingin di cari: ");
					scanf("%d", &cari2);
					SearchBarang2(banyakBarang2, cari2);
					break;
					
			}
		} while (choice != 5);
	}
    return 0;
}

