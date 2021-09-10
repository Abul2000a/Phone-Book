#include <iostream>
#include <fstream>
#include <string>

const int maxRow = 30;std::string name[maxRow];

std::string lastname[maxRow];
std::string number[maxRow];
std::string address[maxRow];void seeAll(){
    std::cout << "All List"<<std::endl;
    int count = 0;
    std::cout << "-N.o- | Name         |  Last Name      |  Number         |  Address       " <<std::endl;
    for(int i = 0; i<maxRow;i++){
        if(name[i]!="\0"){
            count++;
            std::cout << "   " <<count<<"    " <<name[i] << "              "<<lastname[i]<<"     " << number[i] << "           "<<address[i]<<std::endl;        }
    }
}
void add(){
    std::string anun;
    std::string azganun;
    std::string hamar;
    std::string hasce;    std::cin.ignore();
    std::cout << "Enter name >> " ;
    std::getline(std::cin,anun);
    std::cout << "Enter last name >> " ;
    std::getline(std::cin ,azganun);
    std::cout << "Enter Phone Number >> ";
    std::getline(std::cin,hamar);
    std::cout << "Enter Address >> ";
    std::getline(std::cin,hasce);
    for(int i=0;i<maxRow;i++){
        if(name[i]=="\0"){
            name[i]=anun;
            lastname[i]=azganun;
            number[i]=hamar;
            address[i]=hasce;
            break;
        }
    }
}void delets(std::string search){
    int count = 0;
    for(int i = 0;i<maxRow;i++){
        if(name[i]==search){
            count ++;
            name[i]="";
            lastname[i]="";
            number[i]="";
            address[i]="";
            break;
        }
    }
}void edit(std::string search){
    std::string anun;
    std::string azganun;
    std::string hamar;
    std::string hasce;
    int count = 0;
    for(int i = 0;i<maxRow;i++){
        if(name[i]==search){
            count ++;
            std::cout <<"Enter Name>> " ;
            std::cin >> anun;
            name[i]=anun;
            std::cout << "Enter Last Name >>";
            std::cin >> azganun;
            lastname[i]=azganun;
            std::cout << "Enter Phone Number >>";
            std::cin >> hamar;
            number[i]=hamar;
            std::cout << "Enter Address >>";
            std::cin >> hasce;
            address[i]=hasce;        }
    }
}void loadfromfile(){
    std::ifstream file("text.txt");
    std::string anun;
    std::string azganun;
    std::string hamar;
    std::string hasce;
    while(file.good()){
        file >> anun >> azganun >> hamar >> hasce ;
        file.get();
        for(int i = 0;i<maxRow;i++){
            if(name[i].empty()){
                name[i]=anun;
                lastname[i]=azganun;
                number[i]=hamar;
                address[i]=hasce;
                break;
            }
        }
    }
    file.close();
}void savetofile(){
    std::ofstream file("text.txt",std::ios_base::trunc);
    for(int i =0;i<maxRow;i++){
        if(!name[i].empty()){
            file << name[i]<<" " << lastname[i]<<" "<<number[i] << "  " << address[i]<<std::endl;        }
    }
    file.close();}int main(){
    loadfromfile();
    int option;
    std::string sear;
    do{
        std::cout << "Menu"<<std::endl;
        std::cout <<"-1-See All"<<std::endl;
        std::cout << "-2-Add " <<std::endl;
        std::cout << "-3-Edit"<<std::endl;
        std::cout << "-4-Delete"<<std::endl;
        std::cout << "-5-Exit and save to text file"<<std::endl;
        std::cout << "=========================="<<std::endl;
        std::cout << "Select option >>";
        std::cin >> option;
     switch(option){
           case 1:seeAll();
            break;
           case 2:add();
            break;
             case 3:std::cin.ignore();
             std::getline(std::cin,sear);
             edit(sear);
             break;
             case 4:std::cin.ignore();
             std::getline(std::cin ,sear);
             delets(sear);
             break;         }    }
    while(option!=5);
    savetofile();}