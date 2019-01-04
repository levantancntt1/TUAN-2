#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
struct NhanVien {
    char Ten[30], Ho[30], Ma[5];
    int Luong;};
class DSNV{
    private:
        char Ten[30], Ho[30], Ma[5];
        int Luong ; 
        void DocfileDS(){ 
            system("cls");
            FILE *file;
            file= fopen("inputnv.txt", "r");
            cout<<"\nDanh sach nhan vien\n";
            cout<<"\n Ma        |     Ho     |     Ten     |     Luong\n";
            while(fscanf(file, "%s %s %s %d", &Ma[0],&Ho[0], &Ten[0], &Luong )!= EOF)
                cout<<"\n"<<Ma<<"\t\t"<<Ho<<"\t\t"<<Ten<<"\t\t"<<Luong;
            fclose(file);
            Trove();
        }

        void TimNV(){ 
            system("cls");
            FILE *file;
            char ktma[5];
            cout<<"\nNhap vao ma nhan vien: ";
            cin>>ktma;
            file= fopen("inputnv.txt", "r");
            while(fscanf(file, "%s %s %s %d", &Ma[0],&Ho[0], &Ten[0], &Luong )!= EOF)
                if(strcmp(ktma,Ma)==0){
                    cout<<"\nMa nhan vien: "<<Ma;
                    cout<<"\nHo nhan vien: "<<Ho;
                    cout<<"\nTen nhan vien: "<<Ten;
                    cout<<"\nLuong nhan vien: "<<Luong;
                    
                }
            fclose(file);
            Trove();
        }

        void SuaNV(){ 
            system("cls");
            char ktma[5];
            cout<<"\nNhap vao ma nhan vien: ";
            cin>>ktma;
            char Tenmoi[30], Homoi[30]; int Luongmoi;
            cout<<"\nNhap ho moi cua nhan vien: ";
            cin>>Homoi;
            cout<<"\nNhap ten moi cua nhan vien: ";
            cin>>Tenmoi;
            cout<<"\nNhap luong moi cua nhan vien: ";
            cin>>Luongmoi;
            FILE *file, *tempfile;
            file= fopen("inputnv.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %d", &Ma[0],&Ho[0], &Ten[0], &Luong )!= EOF)
			{
                if(strcmp(ktma, Ma)==0)
                    fprintf(tempfile, "\n%s %s %s %d\n", Ma, Homoi, Tenmoi, Luongmoi);
                else
                    fprintf(tempfile, "\n%s %s %s %d\n", Ma, Ho, Ten, Luong);
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("inputnv.txt");
            int isRenamed= rename("temp.txt", "inputnv.txt");
            Trove();
        }

        void ThemNV(){ 
            system("cls");
            cout<<"\n Nhap vao ma nhan vien: "; fflush(stdin);
            cin>>Ma;
            cout<<"\n----------------------------------------";
            cout<<"\n Nhap vao ho nhan vien: ";fflush(stdin);
            cin>>Ho;
            cout<<"\n----------------------------------------";
            cout<<"\n Nhap vao ten nhan vien: ";fflush(stdin);
            cin>>Ten;
            cout<<"\n----------------------------------------";
            cout<<"\n Nhap vao luong nhan vien: ";fflush(stdin);
            cin>>Luong;
            int ch;
            cout<<"\nBan co muon them nhan vien vao danh sach ?\n";
            cout<<"\n1. Luu.";
            cout<<"\n2. Thoat.\n";
            cin>>ch;
            switch(ch)
			{   case 1:
				{
					FILE  *file;
                    file= fopen("inputnv.txt","a");
                    fprintf(file, "\n %s %s %s %d \n", Ma, Ho, Ten, Luong);
                    fclose(file);
                    cout<<"\nDa them nhan vien vao danh sach\n";
				}
				break;
				case 2:
					ThemNV();
                    Trove();
				break;   
            }                          
        }


    public:
        void Menu(){ 
            while(true){
               system("cls");
                cout<<"1. Xem danh sach nhan vien"<<endl;
                cout<<"2. Them mot nhan vien moi vao danh sach"<<endl;
                cout<<"3. Tim mot nhan vien theo ma nhan vien"<<endl;
                cout<<"4. Sua thong tin mot nhan vien"<<endl;
                cout<<" Lua chon cua ban: "<<endl;
                
                int choice;
                cin>>choice;
                
                switch (choice) {
        
                    case 1:
                        DocfileDS();
                        break;
                    case 2:
                        ThemNV();
                        break;
                    case 3:
                        TimNV();
                        break;
                    case 4:
                       SuaNV();
                        break;
                    default:
                        cout<<"\nKhong co thao tac nay!\n";
                        break;
                }

            }
        }
        void Trove()
		{
            cout<<"\nNhan Enter de tro ve\n";
            cin.get();
            cin.get();
        }


};

int main(){
    DSNV ds;
    ds.Menu();
    return 0;
}



