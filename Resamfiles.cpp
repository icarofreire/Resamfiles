#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

#include "log.h"
#include "listar_arquivos.h"
#include "comparar_arquivos.h"

#define SSTR( x ) static_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()

struct arquivos_logs {
	
	string log_arquivos_removidos = "D:\\Documentos\\diffcpp\\REMOVIDO.txt";
	string log_arquivos_analisados = "D:\\Documentos\\diffcpp\\ANALISADO.txt";
	string log_contador_arquivos_removidos = "D:\\Documentos\\diffcpp\\arquivos-iguais-removidos.txt";
	
} *arqs_logs;

void remover_arquivos_iguais(string dir){
	
	cout << "..." << endl;
	
	int con_removidos = 0;
	vector<string> v;
	GetFilesInDirectory(v, dir);
    for(unsigned int i=0; i<v.size(); i++){
        for(unsigned int j=0; j<v.size(); j++){
			if( (i!=j) && exists_test1(v[i]) && exists_test1(v[j]) )
			{
				//~ cout << v[i] << endl;
				string arq1 = v[i];
				string arq2 = v[j];
				bool re1 = equal_files(arq1, arq2);
				bool re2 = compare_files(arq1, arq2);
				bool re3 = compare_files3(arq1, arq2);
				
				logg::i(arqs_logs->log_arquivos_analisados, arq1 + " || " + arq2 );
				
				if( re1 && re2 && re3 ){
					//~ cout << "igual: " << arq1 << endl;
					if( remove(arq1.c_str()) == 0 ){
						logg::i(arqs_logs->log_arquivos_removidos, arq1 + ":[REMOVIDO];" );
						con_removidos++;
					}
				}else{
					//~ cout << "diferente" << endl;
				}
			}
			
		}
    }
    cout << con_removidos << " Arquivos removidos." << endl;
	logg::a(arqs_logs->log_contador_arquivos_removidos, SSTR(con_removidos) + " arquivos removidos;" );
}

int main(int argc, char* argv[])
{
	//~ string arq1 = "C:\\Users\\Casa\\eclipse-workspace\\robo\\projeto-robo\\local-reserva\\SELENIUM-PAG-GRID-3F5[copi]c2kR6EgKj61gtuHG9 - Copia.txt";
	//~ string arq2 = "C:\\Users\\Casa\\eclipse-workspace\\robo\\projeto-robo\\local-reserva\\SELENIUM-PAG-GRID-3F5c2kR6EgKj61gtuHG9.txt";
	
	//~ bool re1 = equal_files(arq1, arq2);
	//~ bool re2 = compare_files(arq1, arq2);
	//~ bool re3 = compare_files3(arq1, arq2);
	
	//~ if( re1 && re2 && re3 ){
		//~ cout << "igual" << endl;
	//~ }else{
		//~ cout << "diferente" << endl;
	//~ }
	
	//~ string dir = "C:\\Users\\Casa\\eclipse-workspace\\robo\\projeto-robo\\local-reserva";
	//~ string dir = "C:\\Users\\Casa\\eclipse-workspace\\robo\\projeto-robo\\paginas-grid";
	
	string dir = argv[1];
	remover_arquivos_iguais(dir);
	


    return 0;
}
