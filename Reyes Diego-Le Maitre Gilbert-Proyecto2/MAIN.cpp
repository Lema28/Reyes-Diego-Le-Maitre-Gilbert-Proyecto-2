#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Matricula.cpp"

using namespace std;

int main()
{

    MATRICULA A;
    char Eleccion;
    while (true)
    {
        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
        cout <<"--------------P-R-O-Y-E-C-T-O--D-E--P-R-O-G-R-A-M-A-C-I-O-N----------------------"<<endl;

        cout <<"-----SI DESEA INGRESAR AL SISTEMA DE MATRICULAS DIGITE (Y) SINO DIGITE (N)--------"<< endl;
        cout <<".................................................................................."<<endl;
        cout << "--> ";
        cin >> Eleccion;
        Eleccion = toupper(Eleccion);

        if (Eleccion == 'Y' || Eleccion == 'N')
        {
            break;
        }
        else
        {
            system("cls");
            cout << "No comprendí, intenta de nuevo...";
            getch();
        }
    }
    system("cls");
    if (Eleccion == 'Y')
    {
        bool x;
        char Elec;
        while (x = true)
        {
            system("cls");
            cout <<".................................................................................."<<endl;
            cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--M-A-T-R-I-C-U-L-A-------" << endl
                << "                      <*-------------------------*>" << endl
                << "                      <|'1'-> ARCHIVO ESTUDIANTE |>" << endl
                << "                      <|'2'-> ARCHIVO PROFESOR   |>" << endl
                << "                      <|'3'-> ARCHIVO CURSO      |>" << endl
                << "                      <|'4'-> ARCHIVO HORARIO    |>" << endl
                << "                      <|'5'-> ARCHIVO GRUPO      |>" << endl
                << "                      <|'6'-> ARCHIVO AULA       |>" << endl
                << "                      <|'7'-> ARCHIVO MATRICULA  |>" << endl
                << "                      <|'0'-> SALIR              |>" << endl
                << "                      <*-------------------------*>" << endl
                << "DIGITE LA OPCION QUE DESEA ELEGIR --> ";
            cin >> Elec;
            cout <<".................................................................................."<<endl;
            string CodigoEstudiante, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion, Creditos, Cupo, Descripcion, Dia, HoraioInicio, HoraioFinal, CodigoAula, Capacidad, CodigoMatricula, CodigoGrupo, CodigoCurso, CodigoProfesor, CodigoHorario, Comprobante, NuevoArchivo;

            switch (Elec)
            {
            case '1':
                char elijo;
                system("cls");
                cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--E-S-T-U-D-I-A-N-T-E-------" << endl
                    << "                     <*-------------------------------*>" << endl
                    << "                     <|'1'-> INGRESAR NUEVO ESTUDIANTE|>" << endl
                    << "                     <|'2'-> BUSCAR ESTUDIANTE        |>" << endl
                    << "                     <|'3'-> MODIFICAR ESTUDIANTE     |>" << endl
                    << "                     <|'4'-> ELIMINAR ESTUDIANTE      |>" << endl
                    << "                     <|'0'-> SALIR                    |>" << endl
                    << "                     <*-------------------------------*>" << endl
                    << "DIGITE LA OPCION QUE DESEA ELEGIR --> ";
                cin >> elijo;
                while (true)
                {
                    if (elijo == '1')
                    {
                        system("cls");
                        cout << "DIGITE EL CODIGO DE GRUPO: " << endl;
                        cin >> CodigoGrupo;
                        cout << "DIGITE LA CEDULA: " << endl;
                        cin >> Cedula;
                        cout << "DIGITE EL PRIMER APELLIDO: " << endl;
                        cin >> Apellido1;
                        cout << "DIGITE EL SUGUNDO APELLIDO: " << endl;
                        cin >> Apellido2;
                        cout << "DIGITE EL NOMBRE: " << endl;
                        cin >> Nombre;
                        cout << "DIGITE EL TELEFONO: " << endl;
                        cin >> Telefono;
                        cin.ignore(256, '\n');
                        cout << "DIGITE LA DIRECCION: " << endl;
                        getline(cin,Direccion);
                        system("cls");
                        A.ESTUDIANTE_TXT(CodigoGrupo, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion);
                        cin.get();
                        break;
                    }
                    else if (elijo == '2')
                    {
                        cout << "DIGITE EL CODIGO DE ESTUDIANTE: " << endl;
                        cin >> CodigoEstudiante;
                        A.BUSCAR_ESTUDIANTE_TXT(CodigoEstudiante);
                        cin.get();
                        break;
                    }
                    else if (elijo == '3')
                    {
                        cout << "DIGITE EL CODIGO DE ESTUDIANTE: " << endl;
                        cin >> CodigoEstudiante;
                        A.MODIFICAR_ESTUDIANTE_TXT(CodigoEstudiante);
                        cin.get();
                        break;
                    }
                    else if (elijo == '4')
                    {
                        cout << "DIGITE EL CODIGO DE ESTUDIANTE: " << endl;
                        cin >> CodigoEstudiante;
                        A.ELIMINAR_ESTUDIANTE_TXT(CodigoEstudiante);
                        cin.get();
                        break;
                    }
                    else if (elijo == '5')
                    {
                        system("cls");
                        A.IMPRIMIR_ESTUDIANTE_TXT();
                        system("PAUSE");
                        break;
                    }

                    else
                    {
                        system("cls");
                        cout << "NO COMPRENDI...INTENTA DE NUEVO..." << endl;
                        getch();
                        system("cls");
                    }
                }
                cin.get();
                x = false;
                break;

            case '2':
                char y;
                system("cls");
                cout <<".................................................................................."<<endl;
                cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--P-R-O-F-E-S-O-R-------" << endl
                    << "                   <*-----------------------------*>" << endl
                    << "                   <|'1'-> INGRESAR NUEVO PROFESOR|>" << endl
                    << "                   <|'2'-> BUSCAR PROFESOR        |>" << endl
                    << "                   <|'3'-> MODIFICAR PROFESOR     |>" << endl
                    << "                   <|'4'-> ELIMINAR PROFESOR      |>" << endl
                    << "                   <|'0'-> SALIR                  |>" << endl
                    << "                   <*-----------------------------*>" << endl
                    << "DIGITE LA OPCION QUE DESEA ELEGIR" << endl;
                cin >> y;
                cout <<".................................................................................."<<endl;//string CodigoProfesor, Cedula1, Nombre, Apellido1, Apellido2, Telefono, Direccion;
                while (true)
                {

                    if (y == '1')
                    {
                        system("cls");
                        cout << "DIGITE LA CEDULA: " << endl;
                        cin >> Cedula;
                        cout << "DIGITE EL PRIMER APELLIDO: " << endl;
                        cin >> Apellido1;
                        cout << "DIGITE EL SUGUNDO APELLIDO: " << endl;
                        cin >> Apellido2;
                        cout << "DIGITE EL NOMBRE: " << endl;
                        cin >> Nombre;
                        cout << "DIGITE EL TELEFONO: " << endl;
                        cin >> Telefono;
                        cin.ignore(256, '\n');
                        cout << "DIGITE LA DIRECCION: " << endl;
                        getline(cin,Direccion);
                        A.PROFESOR_TXT(Cedula, Nombre, Apellido1, Apellido2, Telefono, Direccion);
                        cin.get();
                        break;
                    }
                    else if (y == '2')
                    {
                        system("cls");
                        cout << "DIGITE EL CODIGO DE PROFESOR: " << endl;
                        cin >> CodigoProfesor;
                        A.BUSCAR_PROFESOR(CodigoProfesor);
                        cin.get();
                        break;
                    }
                    else if (y == '3')
                    {
                        system("cls");
                        cout << "DIGITE EL CODIGO DE PROFESOR: " << endl;
                        cin >> CodigoProfesor;
                        system("cls");
                        A.MODIFICAR_PROFESOR_TXT(CodigoProfesor);
                        cin.get();
                        break;
                    }
                    else if (y == '4')
                    {
                        system("cls");
                        cout << "DIGITE EL CODIGO DE PROFESOR: " << endl;
                        cin >> CodigoProfesor;
                        A.ELIMINAR_PROFESOR_TXT(CodigoProfesor);
                        cin.get();
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "no comprendi....";
                        getch();
                    }
                    
                }
                x = false;
                break;

            case '3':
                char z;
                cout <<".................................................................................."<<endl;
                cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--C-U-R-S-O--------" << endl
                    << "                   <*--------------------------*>" << endl
                    << "                   <|'1'-> INGRESAR NUEVO CURSO|>" << endl
                    << "                   <|'2'-> BUSCAR CURSO        |>" << endl
                    << "                   <|'3'-> MODIFICAR CURSO     |>" << endl
                    << "                   <|'4'-> ELIMINAR CURSO      |>" << endl
                    << "                   <|'5'-> IMPRIMIR CURSOS     |>" << endl
                    << "                   <|'0'-> SALIR               |>" << endl
                    << "                   <*--------------------------*>" << endl
                    << "DIGITE LA OPCION QUE DESEA ELEGIR --> ";
                cin >> z;
                cout <<".................................................................................."<<endl;//string CodigoCurso, NombreCurso, Creditos, Cupo;
                if (z == '1')
                {
                    system("cls");
                    int INT;
                    cout << "DIGITE EL NOMBRE DEL CURSO: " << endl;
                    cin >> Nombre;
                    cout << "DIGITE LOS CREDITOS: " << endl;
                    cin >> Telefono;
                    cout << "DIGITE LOS CUPOS: " << endl;
                    cin >> INT;
                    A.CURSO_TXT(Nombre, Creditos, INT);
                    cin.get();
                }
                else if (z == '2')
                {
                    system("cls");
                    cout << "DIGITE EL CODIGO DEL CURSO: " << endl;
                    cin >> CodigoCurso;
                    A.BUSCAR_CURSO(CodigoCurso);
                    cin.get();
                }
                else if (z == '3')
                {
                    system("cls");
                    cout << "DIGITE EL CODIGO DEL CURSO: " << endl;
                    cin >> CodigoCurso;
                    A.MODIFICAR_CURSO_TXT(CodigoCurso, 0);
                    cin.get();
                }
                else if (z == '4')
                {
                    system("cls");
                    cout << "DIGITE EL CODIGO DEL CURSO: " << endl;
                    cin >> CodigoCurso;
                    A.ELIMINAR_CURSO_TXT(CodigoCurso);
                    cin.get();
                }
                else if (z == '5')
                {
                    system("cls");
                    A.IMPRIMIR_CURSO_TXT();
                    cin.get();
                }
                x = false;
                break;

            case '4':
                char xy;
                system("cls");
                cout <<".................................................................................."<<endl;
                cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--H-O-R-A-R-I-O------" << endl
                    << "                    <*----------------------------*>" << endl
                    << "                    <|'1'-> INGRESAR NUEVO HORARIO|>" << endl
                    << "                    <|'2'-> BUSCAR HORARIO        |>" << endl
                    << "                    <|'3'-> MODIFICAR HORARIO     |>" << endl
                    << "                    <|'4'-> ELIMINAR HORARIO      |>" << endl
                    << "                    <|'5'-> IMPRIMIR HORARIO      |>" << endl
                    << "                    <|'0'-> SALIR                 |>" << endl
                    << "                    <*----------------------------*>" << endl
                    << "DIGITE LA OPCION QUE DESEA ELEGIR --> ";
                cin >> xy;
                cout <<".................................................................................."<<endl;//CodigoHorario, Descripcion, Dia, HoraioInicio, HoraioFinal;
                if (xy == '1')
                {
                    system("cls");
                    cout << "DIGITE LA DESCRIPCION: " << endl;
                    cin >> Descripcion;
                    cout << "DIGITE EL DIA: " << endl;
                    cin >> Dia;
                    cout << "DIGITE LA HORA DE INICIO: " << endl;
                    cin >> HoraioInicio;
                    cout << "DIGITE LA HORA DE FINALIZACION: " << endl;
                    cin >> HoraioFinal;
                    A.HORARIO_TXT(Descripcion, Dia, HoraioInicio, HoraioFinal);
                    cin.get();
                }
                else if (xy == '2')
                {
                    system("cls");
                    cout << "DIGITE EL CODIGO DEL HORARIO: " << endl;
                    cin >> CodigoHorario;
                    A.BUSCAR_HORARIO_TXT(CodigoHorario);
                    cin.get();
                }
                else if (xy == '3')
                {
                    system("cls");
                    cout << "DIGITE EL CODIGO DEL HORARIO: " << endl;
                    cin >> CodigoHorario;
                    A.MODIFICAR_HORARIO_TXT(CodigoHorario);
                    cin.get();
                }
                else if (xy == '4')
                {
                    system("cls");
                    cout << "DIGITE EL CODIGO DEL HORARIO: " << endl;
                    cin >> CodigoHorario;
                    A.ELIMINAR_HORARIO_TXT(CodigoHorario);
                    cin.get();
                }
                else if (xy == '5')
                {
                    system("cls");
                    A.IMPRIMIR_HORARIO_TXT();
                    cin.get();
                }
                else
                {
                    cout<<"no entendí";
                    getch();
                }
                x = false;
                break;

            case '5':
                char xz;
                system("cls");
                cout <<".................................................................................."<<endl;
                cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--G-R-U-P-O--------" << endl
                    << "                    <*--------------------------*>" << endl
                    << "                    <|'1'-> INGRESAR NUEVO GRUPO|>" << endl
                    << "                    <|'2'-> BUSCAR GRUPO        |>" << endl
                    << "                    <|'3'-> MODIFICAR GRUPO     |>" << endl
                    << "                    <|'4'-> ELIMINAR GRUPO      |>" << endl
                    << "                    <|'5'-> IMPRIMIR GRUPO      |>" << endl
                    << "                    <|'0'-> SALIR               |>" << endl
                    << "                    <*--------------------------*>" << endl
                    << "DIGITE LA OPCION QUE DESEA ELEGIR --> ";
                cin >> xz;
                cout <<".................................................................................."<<endl;//string CodigoGrupo, Descripcion, falsa;
                if (xz == '1')
                {
                    cout << "DIGITE LA DESCRIPCION: " << endl;
                    cin >> Descripcion;
                    A.GRUPO_TXT(Descripcion);
                    cin.get();
                }
                else if (xz == '2')
                {
                    cout << "DIGITE EL CODIGO DEL GRUPO: " << endl;
                    cin >> CodigoGrupo;
                    A.BUSCAR_GRUPO_TXT(CodigoGrupo);
                    cin.get();
                }
                else if (xz == '3')
                {
                    cout << "DIGITE EL CODIGO DEL GRUPO: " << endl;
                    cin >> CodigoGrupo;
                    A.MODIFICAR_GRUPO_TXT(CodigoGrupo);
                    cin.get();
                }
                else if (xz == '4')
                {
                    cout << "DIGITE EL CODIGO DEL GRUPO: " << endl;
                    cin >> CodigoGrupo;
                    A.ELIMINAR_GRUPO_TXT(CodigoGrupo);
                    cin.get();
                }
                else if (xz == '5')
                {
                    A.IMPRIMIR_GRUPO_TXT();
                    cin.get();
                }
                x = false;
                break;

            case '6':
                char yx;
                system("cls");
                cout <<".................................................................................."<<endl;
                cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--A-U-L-A--------" << endl
                    << "                    <*-------------------------*>" << endl
                    << "                    <|'1'-> INGRESAR NUEVO AULA|>" << endl
                    << "                    <|'2'-> BUSCAR AULA        |>" << endl
                    << "                    <|'3'-> MODIFICAR AULA     |>" << endl
                    << "                    <|'4'-> ELIMINAR AULA      |>" << endl
                    << "                    <|'5'-> IMPRIMIR AULA      |>" << endl
                    << "                    <|'0'-> SALIR              |>" << endl
                    << "                    <*-------------------------*>" << endl
                    << "DIGITE LA OPCION QUE DESEA ELEGIR --> ";
                cin >> yx;
                cout <<".................................................................................."<<endl;//string CodigoAula, Descripcion, Capacidad;
                if (yx == '1')
                {
                    cout << "DIGITE LA DESCRIPCION: " << endl;
                    cin >> Descripcion;
                    cout << "DIGITE LA CAPACIDAD: " << endl;
                    cin >> Capacidad;
                    A.AULA_TXT(Descripcion, Capacidad);
                    cin.get();
                }
                else if (yx == '2')
                {
                    cout << "DIGITE EL CODIGO DEL AULA: " << endl;
                    cin >> CodigoAula;
                    A.BUSCAR_AULA_TXT(CodigoAula);
                    cin.get();
                }
                else if (yx == '3')
                {
                    cout << "DIGITE EL CODIGO DEL AULA: " << endl;
                    cin >> CodigoAula;
                    A.MODIFICAR_AULA_TXT(CodigoAula);
                    cin.get();
                }
                else if (yx == '4')
                {
                    cout << "DIGITE EL CODIGO DEL AULA: " << endl;
                    cin >> CodigoAula;
                    A.ELIMINAR_AULA_TXT(CodigoAula);
                    cin.get();
                }
                else if (yx == '5')
                {
                    A.IMPRIMIR_AULA_TXT();
                    cin.get();
                }
                x = false;
                break;

            case '7':
                char elec;
                system("cls");
                cout <<"............................................................................................................"<<endl;
                cout << "-------------------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--M-A-T-R-I-C-U-L-A-S------------------------" << endl;
                cout << "SI DESEA INGRESAR AL PROCESO DE MATRICULA ABIERTA DIGITE (A) O (N) PARA INGRESAR A UN NUEVO PROCESO DE MATRICULA" << endl;
                cin >> elec;
                cout <<"............................................................................................................."<<endl;
                elec = toupper(elec);
                system("cls");
                if (elec == 'A')
                {
                    system("cls");
                    cout <<".................................................................................."<<endl;
                    cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--S-I-S-T-E-M-A--D-E--M-A-T-R-I-C-U-L-A--------" << endl
                        << "                    <*------------------------------*>" << endl
                        << "                    <|'1'-> Matricular un Estudiante|>" << endl
                        << "                    <|'2'-> BUSCAR MATRICULA        |>" << endl
                        << "                    <|'3'-> MODIFICAR MATRICULA     |>" << endl
                        << "                    <|'4'-> ELIMINAR MATRICULA      |>" << endl
                        << "                    <|'0'-> SALIR                   |>" << endl
                        << "                    <*------------------------------*>" << endl
                        << "DIGITE LA OPCION QUE DESEA ELEGIR --> ";
                    cin >> xy;
                    cout <<".................................................................................."<<endl; //string CodigoMatricula, CodigoEstudiante, CodigoGrupo, CodigoCurso, CodigoProfesor, CodigoHorario, Comprobante;
                    if (xy == '1')
                    {
                        system("cls");
                        A.VERIFICAR_MATRICULAR();
                        cin.get();
                    }
                    else if (xy == '2')
                    {
                        cout << "DIGITE EL CODIGO DE MATRICULA: " << endl;
                        cin >> CodigoMatricula;
                        A.BUSCAR_MATRICULA_TXT(CodigoMatricula, "x");
                        cin.get();
                    }
                    else if (xy == '3')
                    {
                        system("cls");
                        cout << "DIGITE EL CODIGO DE MATRICULA: " << endl;
                        cin >> CodigoMatricula;
                        system("cls");
                        A.MODIFICAR_MATRICULA(CodigoMatricula);
                        cin.get();
                    }
                    else if (xy == '4')
                    {
                        system("cls");
                        cout << "DIGITE EL CODIGO DE MATRICULA: " << endl;
                        cin >> CodigoMatricula;
                        A.ELIMINAR_MATRICULA_TXT(CodigoMatricula);
                        cin.get();
                    }
                    else
                    {
                        system("cls");
                        cout << "no comprendi....";
                        getch();
                    }
                    x = false;
                    break;
                }
                else if (elec == 'N')
                {
                    system("cls");
                    cout <<".................................................................................."<<endl;
                    cout << "-------B-I-E-N-V-E-N-I-D-O--A-L--N-U-E-V-O--S-I-S-T-E-M-A--D-E--M-A-T-R-I-C-U-L-A---" << endl
                        << "                    \nSUERTE EN TU PROCESO ;) " << endl << endl
                        << "              <>'1'-> CREAR NUEVO SISTEMA DE MATRICULA      .<>" << endl
                        << "              <>'2'-> ELEGIR UN PROCESO DE MATRICULA ABIERTO.<>" << endl                       
                        << "              <>'0'-> SALIR . . . . . . . . . . . . . . . . .<>" << endl
                        << "              <*---------------------------------------------*>" << endl
                        << "DIGITE LA OPCION QUE DESEA ELEGIR --> ";
                    cin >> xy;
                    cout <<".................................................................................."<<endl;
                    if (xy == '1')
                    {
                        system("cls");
                        A.NUEVO_MATRICULA_TXT();
                        system("cls");
                        cout << "NUEVO SISTEMA DE MATRICULA ABIERTO";
                        cin.get();
                        system("cls");
                       
                    }
                  
                }

            case '0':
                system("cls");
                cout << "GRACIAS POR USAR EL PROGRAMA";
                getch();
                exit(1);
                break;

            default:
                cout << "no entendí intenta de nuevo...";
                getch();
                break;
            }
        }
    }
    //string CodigoGrupo, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion;
    //A.ESTUDIANTE_TXT(CodigoGrupo, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion);
    return 0;
}
