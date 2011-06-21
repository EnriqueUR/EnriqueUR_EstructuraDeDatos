#include "conversiones.h"
#include <QDebug>

conversiones::conversiones()
{
    tabla_prioridad.push_back("(");
    tabla_prioridad.push_back(")");
    tabla_prioridad.push_back("*");
    tabla_prioridad.push_back("/");
    tabla_prioridad.push_back("+");
    tabla_prioridad.push_back("-");
    tabla_prioridad.push_back("^");

}
void conversiones::convertir_pos_fija(QStringList simb){

 for(int it= 0; it < simb.count();it++){
    bool ver = false;
    for(int i = 0; i < tabla_prioridad.count();i++){
        if(tabla_prioridad.at(i)==simb.at(it)){
            ver = true;
        }
    }

    if(!ver){
        numeros.push_back(simb.at(it));
    }

    if(operadores.count()!=0 && ver){
        if(simb.at(it) == "("){
            operadores.push_back("(");
        }else if(simb.at(it) == ")"){
            for(int i = operadores.count()-1; i >= 0; i--){
                if(operadores.at(i)=="("){
                    operadores.removeAt(i);
                    break;
                }
                numeros.push_back(operadores.takeLast());
            }
        }else if(simb.at(it) == "^"){
            if(operadores.last()=="^"){
                   numeros.push_back(operadores.takeLast());
                   operadores.push_back("^");
               }else{
                   operadores.push_back("^");
               }

        }else if(simb.at(it) == "*"){
            if(operadores.last()=="/"){
                   numeros.push_back(operadores.takeLast());
                   operadores.push_back("*");
               }else if(operadores.last()=="*"){
                   numeros.push_back(operadores.takeLast());
                   operadores.push_back("*");
               }else if(operadores.last()=="^"){
                      numeros.push_back(operadores.takeLast());
                      operadores.push_back("*");
               }else{
                   operadores.push_back("*");
               }

        }else if(simb.at(it) == "/"){
            if(operadores.last()=="*"){
                numeros.push_back(operadores.takeLast());
                operadores.push_back("/");
            }else if(operadores.last()=="/"){
                numeros.push_back(operadores.takeLast());
                operadores.push_back("/");
            }else if(operadores.last()=="^"){
                numeros.push_back(operadores.takeLast());
                operadores.push_back("/");
            }else{
                operadores.push_back("/");
            }

        }else if(simb.at(it) == "+"){
            if(operadores.last()=="-"){
                numeros.push_back(operadores.takeLast());
                operadores.push_back("+");
            }else if(operadores.last()=="+"){
                numeros.push_back(operadores.takeLast());
                operadores.push_back("+");
            }else if(operadores.last()!="("){
                    numeros.push_back(operadores.takeLast());
                    operadores.push_back("+");
                }else{
                    operadores.push_back("+");
                }

        }else if(simb.at(it) == "-"){
            if(operadores.last()=="+"){
                numeros.push_back(operadores.takeLast());
                operadores.push_back("-");
            }else if(operadores.last()=="-"){
                numeros.push_back(operadores.takeLast());
                operadores.push_back("-");
            }else if(operadores.last()!="("){
                    numeros.push_back(operadores.takeLast());
                    operadores.push_back("-");
                }else{
                    operadores.push_back("-");
                }
        }

    }else if(ver){
        operadores.push_back(simb.at(it));
    }
}
    for(int i=operadores.count()-1; i >= 0;i--){
         numeros.push_back(operadores.takeAt(i));
    }


}

double conversiones::resolver_pos_fija(QList<QString> posfija){
    for(int i= 0; i < posfija.count(); i++){
        if(posfija.at(i)== "+" || posfija.at(i)== "-" || posfija.at(i)== "/" || posfija.at(i)== "*" || posfija.at(i)== "^"){
            int n1 = posfija.at(i-2).toDouble();
            int n2 = posfija.at(i-1).toDouble();
            QString operador = posfija.at(i);
            posfija.removeAt(i-2);
            posfija.removeAt(i-2);
            posfija[i-2]= QString::number(evaluar(n1,n2,operador));
            i--;
       }
    }
    return posfija.first().toDouble();

}

double conversiones::evaluar(int n1, int n2, QString operador){
    if(operador == "+"){
        return (n1 + n2);
    }
    if(operador == "-"){
        return (n1 - n2);
    }
    if(operador == "/"){
        return (n1 / n2);
    }
    if(operador == "*"){
        return (n1 * n2);
    }
    if(operador == "^"){
        return pow(n1,n2);
    }
}

void conversiones::mezclar(){

}

void conversiones::guardar_numero_simbolo(char simb){


}

int conversiones::verificar_prioridad(char operador){

}

void conversiones::identificar_operador(QString simb,int indice, int fin){


}

