#ifndef LOG_H
#define LOG_H

// cria um arquivo para guardar informações;
namespace logg {

    void i(string file, string conteudo){//incrementa o conteúdo no final do arquivo;
      fstream myfile (file, ios::app);
      if (myfile.is_open())
      {
        myfile << conteudo << "\n";
        myfile.close();
      }
      else cout << "Unable to open file" << endl;
    }


    void a(string file, string conteudo){//apaga todo o conteúdo do arquivo;
      fstream myfile (file, ios::out | ios::trunc);
      if (myfile.is_open())
      {
        myfile << conteudo << "\n";
        myfile.close();
      }
      else cout << "Unable to open file" << endl;
    }

}

#endif
