//La declaracion de los struct
struct VentasPorMes{
        std::string Vendedor;
        std::array<unsigned,12> VentasMes;
    };

using Vendedor = std::array<VentasPorMes, 3>;

    struct Regiones{
        std::string Region;
        Vendedor vendedor;
    };

using VentasPorRegion = std::array<Regiones, 4>;

struct Mes{
    std::array<std::string,12> simplificado, completo;
};

//El prototipo de las funciones
void AgregarSaldo(std::istream& inputs, VentasPorRegion& p);
void MostraDatos(const VentasPorRegion& p);
void TotalesDeCadaVendedor(const VentasPorRegion& p);
void TotalPorRegion(const VentasPorRegion& p);
void TrimestreDeCadaVendedor(const VentasPorRegion& p);
void TrimestreSeleccionado(unsigned trimestre, const VentasPorRegion& p);
void MaximoDeVentas(const VentasPorRegion& p, const Mes& d);
void MinimoDeVentas(const VentasPorRegion& p, const Mes& d);
void PromedioVentasCadaVendedor(const VentasPorRegion& p);