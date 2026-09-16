#include<iostream>
#include<array>
#include"Dim3V2Funciones.hpp"

void AgregarSaldo(std::istream& inputs, VentasPorRegion& p){
    for(unsigned region, vend, mes, saldo; inputs>>region>>vend>>mes>>saldo;) p.at(region).vendedor.at(vend).VentasMes.at(mes) += saldo;
}

void MostraDatos(const VentasPorRegion& p){
    for(const auto& reg : p){
        std::cout<<reg.Region<<"\n";
        for(const auto& vendedores : reg.vendedor){
            std::cout << vendedores.Vendedor <<"| ";
            for(auto mes : vendedores.VentasMes) std::cout << mes << " ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

void TotalesDeCadaVendedor(const VentasPorRegion& p){
    for(const auto& reg: p){
        std::cout << reg.Region <<"\n";
        for(const auto& vendedores : reg.vendedor){
            unsigned total{};
            std::cout <<"El total de " << vendedores.Vendedor <<" es: $";
            for(const auto& mes : vendedores.VentasMes) total += mes;
            std::cout << total << "\n";
        }
        std::cout << "\n";
    }
}

void TotalPorRegion(const VentasPorRegion& p){
    for(const auto& reg: p){
        unsigned total{};
        std::cout << "El total de la region del " << reg.Region <<" es de: $";
        for(const auto& vendedores : reg.vendedor){
            for(const auto& mes : vendedores.VentasMes) total += mes;
        }
        std::cout <<total<<"\n";
    }
}

void TrimestreDeCadaVendedor(const VentasPorRegion& p){
    unsigned trimestre{};
    for(const auto& reg: p){
        std::cout << reg.Region <<"\n";
        for(const auto& vendedores : reg.vendedor){
            unsigned total{};
            std::cout << vendedores.Vendedor <<"\n";
            for(unsigned indice = 0; indice<vendedores.VentasMes.size(); indice++){
                unsigned resultado = indice /3;
                resultado == trimestre ? total +=vendedores.VentasMes.at(indice) : total += 0;
                if((indice + 1) % 3 == 0){
                    std::cout<< "El total del trimestre " << trimestre+1 <<" es de: $" << total <<"\n";
                    trimestre++;
                    total = 0;
                }
            }
            trimestre = 0;
        }
        std::cout << "\n";
    }
}

void TrimestreSeleccionado(unsigned trimestre, const VentasPorRegion& p){
    for(const auto& reg: p){
        std::cout << reg.Region <<"\n";
        for(const auto& vendedores : reg.vendedor){
            std::cout << vendedores.Vendedor << " ";
            unsigned total{};
            for(unsigned indice = 0; indice<vendedores.VentasMes.size(); indice++) indice / 3 == (trimestre - 1) ? total += vendedores.VentasMes.at(indice) : total += 0;
            std::cout<<"El trimestre " << trimestre << " es de: $" << total <<"\n";
        }
        std::cout<<"\n";
    }
}

void MaximoDeVentas(const VentasPorRegion& p, const Mes& d){
    unsigned mesexacto{},maximo{};
    std::string RegionMaximo, VendedorMaximo;
    for(const auto& reg: p){
        for(const auto& vendedores : reg.vendedor){
            unsigned contarmes{};
            for(const auto& mes : vendedores.VentasMes){
                if(mes >= maximo){
                    maximo = mes;
                    mesexacto = contarmes;
                    VendedorMaximo = vendedores.Vendedor;
                    RegionMaximo=reg.Region;
                }
                contarmes++;
            }
        }
    }
    std::cout << "El maximo vendedor es: " << VendedorMaximo <<"\n"
    << "Region: " << RegionMaximo << "\n"
    << "Mes: " << d.completo.at(mesexacto) <<"\n"
    << "Total: $" << maximo <<"\n";
}

unsigned GetMaximo(const VentasPorRegion& p){
    unsigned maximo{};
    for(const auto& reg: p){
        for(const auto& vendedores : reg.vendedor){
            for(const auto& mes : vendedores.VentasMes){
                if(mes >= maximo){
                    maximo = mes;
                }
            }
        }
    }
    return maximo;
}

void MinimoDeVentas(const VentasPorRegion& p, const Mes& d){
    unsigned minimo = GetMaximo(p);
    unsigned mesexacto{};
    std::string RegionMinimo, VendedorMinimo;
    for(const auto& reg: p){
        for(const auto& vendedores : reg.vendedor){
            unsigned contarmes{};
            for(const auto& mes : vendedores.VentasMes){
                if(mes <= minimo){
                    minimo = mes;
                    mesexacto = contarmes;
                    RegionMinimo = reg.Region;
                    VendedorMinimo = vendedores.Vendedor;
                }
                contarmes++;
            }
        }
    }
    std::cout << "El minimo vendedor es: " << VendedorMinimo <<"\n"
    << "Region: " << RegionMinimo << "\n"
    << "Mes: " << d.completo.at(mesexacto) <<"\n"
    << "Total: $" << minimo <<"\n";
}

void PromedioVentasCadaVendedor(const VentasPorRegion& p){
    for(const auto& reg : p){
        std::cout << reg.Region << "\n";
        for(const auto& vendedores : reg.vendedor){
            std::cout << "El promedio de " << vendedores.Vendedor << " es de: $";
            unsigned promedio;
            unsigned total{};
            for(const auto& mes : vendedores.VentasMes) total += mes;
            promedio = total / vendedores.VentasMes.size();
            std::cout << promedio << "\n";
        }
    }
}