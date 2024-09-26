#include <iostream>
using namespace std;
class Paciente{
	private: 
		string rut, nombre, fecha;
	public:
		Paciente(string rut, string nombre, string fecha){
			this->rut=rut;
			this->nombre=nombre;
			this->fecha=fecha;
		}
	string getRut(){
		return rut;
	}
	string getNombre(){
		return nombre;
	}
	string getfecha(){
		return fecha;
	}
	void setRut(string rut){
		this->rut=rut;
	}
	void setNombre(){
		this->nombre=nombre;
	}
	void setFecha(){
		this->fecha=fecha;
	}
	void imprimirDatos(){
		cout<< "Rut: "<< rut<< endl;
		cout<< "Nombre: "<<nombre<< endl;
		cout<< "Fecha: "<< fecha<< endl;
	}
};
class Riesco{
	private:
		int camasOcupadas=0;
		Paciente* paciente[300];
	public:
		Riesco(){
			for (int i=0; i<300; i++){
				paciente[i]= NULL;
			}
		}
	bool insertarPaciente(string rut, string nombre, string fecha){
		if (camasOcupadas<300){	
		paciente[camasOcupadas]=new Paciente(rut, nombre, fecha);
		camasOcupadas++;
		return true;
		}
	else{
		cout<<"No hay camas disponibles"<< endl;
		return false;
	}
	}
	bool darAlta(string rut){
		for (int i=0; i<camasOcupadas; i++){
			if(paciente[i]!=NULL && paciente[i]->getRut()== rut){
				paciente[i]=NULL;
				cout<< "Paciente con rut "<< rut << " ha sido dado de alta"<< endl;
				for (int j=i; j <camasOcupadas-1; j++){
					paciente[j]= paciente[j+1];
				}
				paciente[camasOcupadas-1]=NULL;
				camasOcupadas--;
				return true;
			}
		}
		cout<< "Paciente con rut "<< rut << " no encontrado"<< endl;
		return false;
	}
	bool darQEPD(string rut){
		for (int i=0; i<camasOcupadas; i++){
			if (paciente[i]!= NULL && paciente[i]->getRut()== rut){
				paciente[i]=NULL;
				cout<< "Paciente con rut "<< rut<< "  ha fallecido"<< endl;
				paciente[camasOcupadas-1]= NULL;
				camasOcupadas--;
				return true;
			}
		}
		cout<< "Paciente con rut "<< rut << " no encontrado"<< endl;
		return false;
	}
		int getCamas(){
			return camasOcupadas;
		}
};
int main(){
	Riesco hospital;
	int opcion;
	string rut, nombre, fecha; 
	while (opcion !=5){
		cout<<"--Menu--"<< endl;
		cout << "1. agregar paciente"<< endl;
		cout << "2. dar de alta a paciente "<< endl;
		cout << "3. Fallecimiento de paciente"<< endl;
		cout << "4. Cantidad de camas ocupadas"<< endl;
		cout<< "5. salir"<< endl;
		cout<< "SELECCIONE UNA OPCION"<< endl;
		cin>> opcion;
		switch(opcion){
			case 1:
				cout<< "Ingrese RUT:"<< endl;
				cin>> rut;
				cout<< "Ingrese Nombre:"<< endl;
				cin>> nombre;
				cout<<"Ingrese fecha de ingreso (YYYYMMDD)"<< endl;
				cin>> fecha;
				hospital.insertarPaciente(rut, nombre, fecha);
				break;
			case 2:
				cout<< "Ingrese rut del paciente para el alta"<< endl;
				cin>> rut;
				hospital.darAlta(rut);
				break;
			case 3:
				cout<< "Ingrese rut de paciente para informar fallecimiento "<< endl;
				cin>>rut;
				hospital.darQEPD(rut);
				break;
			case 4:
				cout<< "cantidad de camas ocupadas "<< hospital.getCamas()<< endl;
				break;
			case 5:
				cout<< "Saliendo..."<< endl;
				break;
			default: 
				cout<< "Opcion invalida "<< endl;
		}
		cout<< endl;
	}
	return 0;
}
