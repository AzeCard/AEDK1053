#include<iostream>
#include<array>
#include<string>
#include"Dim3V2Funciones.hpp"

VentasPorRegion lista{{
    {
        "Norte",
        {{
            {"Alan", {}},
            {"Ezequiel", {}},
            {"Zacarias", {}},
        }}
    },
    {
        "Sur",
        {{
            {"Alan", {}},
            {"Ezequiel", {}},
            {"Zacarias", {}},
        }}
    },
    {
        "Este",
        {{
            {"Alan", {}},
            {"Ezequiel", {}},
            {"Zacarias", {}},
        }}
    },
    {
        "Oeste",
        {{
            {"Alan", {}},
            {"Ezequiel", {}},
            {"Zacarias", {}},
        }}
    },
}};

Mes Meses{
    //Se utiliza para MostrarLista y que muestre los meses.
    {"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"}
    //Para poner el mes entero en una funcion.
    ,{"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"}
};

int main(){
    AgregarSaldo(std::cin, lista);
    //MostraDatos(lista); 
    //TotalesDeCadaVendedor(lista);
    //TotalPorRegion(lista);
    //TrimestreDeCadaVendedor(lista);
    //TrimestreSeleccionado(1, lista);
    //MaximoDeVentas(lista, Meses);
    //MinimoDeVentas(lista, Meses);
    PromedioVentasCadaVendedor(lista);

}