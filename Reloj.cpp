#include <iostream>
using namespace std;
class Reloj{
	private:
		int hora, minutos, segundos;
	public:
		Reloj(int hora, int minutos, int segundos){
			this->hora=hora;
			this->minutos=minutos;
			this->segundos=segundos;
		}
		int getHora(){return hora;
		}
		int getMinutos(){return minutos;
		}
		int getSegundos(){return segundos;
		}
		void setSegundos(int segundos){
			this->segundos=segundos;
		}
		void setHora(int hora){
			this->hora=hora;
		}
		void setMinutos(int minutos){
			this->minutos=minutos;
		}
		void ajustarHoraOficial(Reloj *ho){
			if (hora== ho->hora && minutos== ho->minutos && segundos== ho->segundos){
				cout<< "El reloj esta a la hora "<< endl;
			}else if(hora > ho->hora || (hora== ho->hora && minutos>ho->minutos)|| (hora== ho->hora && minutos== ho->minutos && segundos> ho->segundos)){
				cout<< "El reloj esta adelantado "<< endl;
			}else{
				cout<< "El reloj esta atrasado "<< endl;
			}
			
			hora= ho->hora;
			minutos=ho->minutos;
			segundos= ho->segundos;
		}
		void mostrarHora(){
			cout<< "Hora actual "<< hora<<":"<<minutos<<":"<<segundos<<endl;
		}
		void mostrarHoraO(Reloj *ho){
		cout<< "Hora oficial "<< ho->hora<< ":"<< ho->minutos<<":"<< ho->segundos<< endl;		}
};
int main(){
	Reloj *ho= new Reloj(12,50,10);
	Reloj *hoa= new Reloj(12,50,11);
	ho->mostrarHoraO(ho);
	hoa->mostrarHora();
	hoa->ajustarHoraOficial(ho);
	hoa->mostrarHora();
	return 0;
	
	
}
