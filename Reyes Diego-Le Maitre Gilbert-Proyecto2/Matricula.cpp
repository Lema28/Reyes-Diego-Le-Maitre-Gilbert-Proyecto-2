#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <sstream>
#include <windows.h>

using namespace std;

class MATRICULA
{
private:
    ofstream ESTUDIANTE;

public:
    MATRICULA()
    {

        ESTUDIANTE;
    }
    ~MATRICULA()
    {
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void ESTUDIANTE_TXT(string CodigoGrupo, string Cedula, string Apellido1, string Apellido2, string Nombre, string Telefono, string Direccion)
    {
        string CodigoEstudiante;
        char Codigo[4];
        srand(time(NULL));
        for (int i = 0; i <= 2; i++)
        {
            Codigo[i] = 48 + rand() % (57 - 48);
        }
        CodigoEstudiante = Codigo;
        if (BUSCAR_ESTUDIANTE_TXT(CodigoEstudiante))
        {
            ESTUDIANTE_TXT(CodigoGrupo, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion);
        }
        system("cls");
        ofstream ESTUDIANTE("PRUEBA_TXT.txt", ios ::out | ios ::app);
        ESTUDIANTE << CodigoEstudiante << "#" << CodigoGrupo << "#" << Cedula << "#" << Apellido1 << "#" << Apellido2 << "#" << Nombre << "#" << Telefono << "#" << Direccion << "@" << endl;
        cout << "EL ESTUDIANTE HA SIDO INGRESADO !" << endl;
        ESTUDIANTE.close();
    }

    void IMPRIMIR_ESTUDIANTE_TXT()
    {

        ifstream ESTUDIANTE;
        string CodigoEstudiante, CodigoGrupo, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion, falsa;

        ESTUDIANTE.open("PRUEBA_TXT.txt", ios::in);
        getline(ESTUDIANTE, CodigoEstudiante, '#');

        while (!ESTUDIANTE.eof())
        {
            getline(ESTUDIANTE, CodigoGrupo, '#');
            getline(ESTUDIANTE, Cedula, '#');
            getline(ESTUDIANTE, Apellido1, '#');
            getline(ESTUDIANTE, Apellido2, '#');
            getline(ESTUDIANTE, Nombre, '#');
            getline(ESTUDIANTE, Telefono, '#');
            getline(ESTUDIANTE, Direccion, '@');
            getline(ESTUDIANTE, falsa, '\n');
            cout << "------------------------------------------------" << endl;
            cout << "CodigoEstudiante -->" << CodigoEstudiante << endl;
            cout << "CodigoGrupo -->" << CodigoGrupo << endl;
            cout << "Cedula -->" << Cedula << endl;
            cout << "Apellido -->" << Apellido1 << endl;
            cout << "Apellido -->" << Apellido2 << endl;
            cout << "Nombre -->" << Nombre << endl;
            cout << "Telefono -->" << Telefono << endl;
            cout << "Direccion -->" << Direccion << endl;
            cout << "------------------------------------------------" << endl;

            getline(ESTUDIANTE, CodigoEstudiante, '#');
        }

        ESTUDIANTE.close();
    }

    bool BUSCAR_ESTUDIANTE_TXT(string CodigoEstudianteAUX)
    {

        ifstream ESTUDIANTE;
        string CodigoEstudiante, CodigoGrupo, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion, falsa;
        bool x = false;

        ESTUDIANTE.open("PRUEBA_TXT.txt", ios ::in);
        getline(ESTUDIANTE, CodigoEstudiante, '#');

        while (!ESTUDIANTE.eof() && !x)
        {

            getline(ESTUDIANTE, CodigoGrupo, '#');
            getline(ESTUDIANTE, Cedula, '#');
            getline(ESTUDIANTE, Apellido1, '#');
            getline(ESTUDIANTE, Apellido2, '#');
            getline(ESTUDIANTE, Nombre, '#');
            getline(ESTUDIANTE, Telefono, '#');
            getline(ESTUDIANTE, Direccion, '@');
            getline(ESTUDIANTE, falsa, '\n');

            if (CodigoEstudianteAUX == CodigoEstudiante)
            {
                cout << "CodigoEstudiante -->" << CodigoEstudiante << endl;
                cout << "CodigoGrupo -->" << CodigoGrupo << endl;
                cout << "Cedula -->" << Cedula << endl;
                cout << "Apellido -->" << Apellido1 << endl;
                cout << "Apellido -->" << Apellido2 << endl;
                cout << "Nombre -->" << Nombre << endl;
                cout << "Telefono -->" << Telefono << endl;
                cout << "Direccion -->" << Direccion << endl;
                x = true;
            }
            getline(ESTUDIANTE, CodigoEstudiante, '#');
        }
        ESTUDIANTE.close();
        if (!x)
        {
            cout << "NO LO LOGRE" << endl;
        }
        return x;
    }

    void MODIFICAR_ESTUDIANTE_TXT(string CodigoEstudianteAUX)
    {

        string CodigoEstudiante, CodigoGrupo, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion;
        ifstream ESTUDIANTE;
        string MODIFICO;
        ESTUDIANTE.open("PRUEBA_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("EDITADO.txt", ios ::out);
        bool x = false;

        if (ESTUDIANTE.is_open() && !x)
        {
            cout << "hola mundo000";
            getline(ESTUDIANTE, CodigoEstudiante, '#');

            while (!ESTUDIANTE.eof() && x == false)
            {
                cout << "hola mundo";

                getline(ESTUDIANTE, CodigoGrupo, '#');
                getline(ESTUDIANTE, Cedula, '#');
                getline(ESTUDIANTE, Apellido1, '#');
                getline(ESTUDIANTE, Apellido2, '#');
                getline(ESTUDIANTE, Nombre, '#');
                getline(ESTUDIANTE, Telefono, '#');
                getline(ESTUDIANTE, Direccion);

                if (CodigoEstudianteAUX == CodigoEstudiante)
                {
                    char respuesta;
                    cout << "MODIFICAR..." << endl
                         << "'1'->CODIGO DE GRUPO" << endl
                         << "'2'->CEDULA" << endl
                         << "'3'->PRIMER APELLIDO" << endl
                         << "'4'->SEGUNDO APELLIDO" << endl
                         << "'5'->NOMBRE" << endl
                         << "'6'->TELEFONO" << endl
                         << "'7'->DIRECCION" << endl
                         << "'0'->SALIR AL MENU" << endl
                         << "DIGITE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR" << endl;
                    cin >> respuesta;
                    switch (respuesta)
                    {
                    case '1':
                        cout << "DIGITE LA MODIFICACION DEL CODIGO" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoEstudiante << "#" << MODIFICO << "#" << Cedula << "#" << Apellido1 << "#" << Apellido2 << "#" << Nombre << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;
                    case '2':
                        cout << "DIGITE LA MODIFICACION DEL CEDULA" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoEstudiante << "#" << CodigoGrupo << "#" << MODIFICO << "#" << Apellido1 << "#" << Apellido2 << "#" << Nombre << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;
                    case '3':
                        cout << "DIGITE LA MODIFICACION DEL APELLIDO" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoEstudiante << "#" << CodigoGrupo << "#" << Cedula << "#" << MODIFICO << "#" << Apellido2 << "#" << Nombre << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;
                    case '4':

                        cout << "DIGITE LA MODIFICACION DEL APELLIDO" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoEstudiante << "#" << CodigoGrupo << "#" << Cedula << "#" << Apellido1 << "#" << MODIFICO << "#" << Nombre << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;
                    case '5':

                        cout << "DIGITE LA MODIFICACION DEL NOMBRE" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoEstudiante << "#" << CodigoGrupo << "#" << Cedula << "#" << Apellido1 << "#" << Apellido2 << "#" << MODIFICO << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;
                    case '6':

                        cout << "DIGITE LA MODIFICACION DEL TELEFONO" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoEstudiante << "#" << CodigoGrupo << "#" << Cedula << "#" << Apellido1 << "#" << Apellido2 << "#" << Nombre << "#" << MODIFICO << "#" << Direccion << endl;
                        x = true;
                        break;
                    case '7':
                        //getline(ESTUDIANTE,MODIFICO);
                        cin.ignore(256, '\n');
                        cout << "DIGITE LA MODIFICACION DE LA DIRECCION" << endl;
                        getline(cin, MODIFICO);
                        ARCHIVOAUX << CodigoEstudiante << "#" << CodigoGrupo << "#" << Cedula << "#" << Apellido1 << "#" << Apellido2 << "#" << Nombre << "#" << Telefono << "#" << MODIFICO << "@" << endl;
                        x = true;
                        break;
                    case '0':
                        x = true;
                        break;

                    default:
                        cout << "no entendí intenta de nuevo...";
                        getch();
                        x = false;
                        break;
                    }
                }
                else
                {
                    ARCHIVOAUX << CodigoEstudiante << "#" << CodigoGrupo << "#" << Cedula << "#" << Apellido1 << "#" << Apellido2 << "#" << Nombre << "#" << Telefono << "#" << Direccion << "@" << endl;
                }

                getline(ESTUDIANTE, CodigoEstudiante, '#');
            }
        }
        ESTUDIANTE.close();
        ARCHIVOAUX.close();
        remove("PRUEBA_TXT.txt");
        rename("EDITADO.txt", "PRUEBA_TXT.txt");
    }

    void ELIMINAR_ESTUDIANTE_TXT(string CodigoEstudianteAUX)
    {
        string CodigoEstudiante, CodigoGrupo, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion, falsa;
        ifstream ESTUDIANTE;
        string MODIFICO;
        ESTUDIANTE.open("PRUEBA_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("EDITADO.txt", ios ::out);
        bool x = false;

        if (ESTUDIANTE.is_open() && !x)
        {
            getline(ESTUDIANTE, CodigoEstudiante, '#');

            while (!ESTUDIANTE.eof() && x == false)
            {
                getline(ESTUDIANTE, CodigoGrupo, '#');
                getline(ESTUDIANTE, Cedula, '#');
                getline(ESTUDIANTE, Apellido1, '#');
                getline(ESTUDIANTE, Apellido2, '#');
                getline(ESTUDIANTE, Nombre, '#');
                getline(ESTUDIANTE, Telefono, '#');
                getline(ESTUDIANTE, Direccion, '@');
                getline(ESTUDIANTE, falsa, '\n');
                if (CodigoEstudianteAUX == CodigoEstudiante)
                {
                    cout << "ESTUDIANTE ELIMINADO";
                    getch();
                }
                else
                {
                    ARCHIVOAUX << CodigoEstudiante << "#" << CodigoGrupo << "#" << Cedula << "#" << Apellido1 << "#" << Apellido2 << "#" << Nombre << "#" << Telefono << "#" << Direccion << "@" << endl;
                }
                getline(ESTUDIANTE, CodigoEstudiante, '#');
            }
        }
        ESTUDIANTE.close();
        ARCHIVOAUX.close();
        remove("PRUEBA_TXT.txt");
        rename("EDITADO.txt", "PRUEBA_TXT.txt");
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void PROFESOR_TXT(string Cedula, string Nombre, string Apellido1, string Apellido2, string Telefono, string Direccion)
    {
        string CodigoProfesor;
        char Codigo[4];
        srand(time(NULL));
        for (int i = 0; i <= 2; i++)
        {
            Codigo[i] = 48 + rand() % (57 - 48);
        }
        CodigoProfesor = Codigo;
        if (BUSCAR_PROFESOR(CodigoProfesor))
        {
            PROFESOR_TXT(Cedula, Nombre, Apellido1, Apellido2, Telefono, Direccion);
        }
        system("cls");
        ofstream PROFESOR("PROFESOR_TXT.txt", ios::out | ios::app);
        PROFESOR << CodigoProfesor << "#" << Cedula << "#" << Nombre << "#" << Apellido1 << "#" << Apellido2 << "#" << Telefono << "#" << Direccion << "@" << endl;
        PROFESOR.close();
    }

    void IMPRIMIR_PROFESOR_TXT()
    {

        ifstream PROFESOR;
        string CodigoProfesor, Cedula, Nombre, Apellido1, Apellido2, Telefono, Direccion, falso;

        PROFESOR.open("PROFESOR_TXT.txt", ios::in);
        getline(PROFESOR, CodigoProfesor, '#');

        while (!PROFESOR.eof())
        {

            getline(PROFESOR, Cedula, '#');
            getline(PROFESOR, Nombre, '#');
            getline(PROFESOR, Apellido1, '#');
            getline(PROFESOR, Apellido2, '#');
            getline(PROFESOR, Telefono, '#');
            getline(PROFESOR, Direccion, '@');
            getline(PROFESOR, falso, '\n');
            cout << "------------------------------------------------" << endl;
            cout << "Codigo Profesor -->" << CodigoProfesor << endl;
            cout << "Cedula -->" << Cedula << endl;
            cout << "Nombre -->" << Nombre << endl;
            cout << "Apellido -->" << Apellido1 << endl;
            cout << "Apellido -->" << Apellido2 << endl;
            cout << "Telefono -->" << Telefono << endl;
            cout << "Direccion -->" << Direccion << endl;
            cout << "------------------------------------------------" << endl;

            getline(PROFESOR, CodigoProfesor, '#');
        }

        PROFESOR.close();
    }

    bool BUSCAR_PROFESOR(string codigoProfesorAux)
    {
        ifstream PROFESOR;
        string CodigoProfesor, Cedula, Apellido1, Apellido2, Nombre, Telefono, Direccion, falsa;
        bool x = false;

        PROFESOR.open("PROFESOR_TXT.txt", ios ::in);
        getline(PROFESOR, CodigoProfesor, '#');
        while (!PROFESOR.eof() && !x)
        {
            getline(PROFESOR, Cedula, '#');
            getline(PROFESOR, Nombre, '#');
            getline(PROFESOR, Apellido1, '#');
            getline(PROFESOR, Apellido2, '#');
            getline(PROFESOR, Telefono, '#');
            getline(PROFESOR, Direccion, '@');
            getline(PROFESOR, falsa, '\n');
            if (codigoProfesorAux == CodigoProfesor)
            {
                cout << "Encontrado..." << endl;
                cout << "CodigoProfesor --> " << CodigoProfesor << endl;
                cout << "Nombre --> " << Nombre << endl;
                cout << "Cedula --> " << Cedula << endl;
                cout << "Primer Apellido --> " << Apellido1 << endl;
                cout << "Segundo Apellido --> " << Apellido2 << endl;
                cout << "Telefono --> " << Telefono << endl;
                cout << "Direccion --> " << Direccion << endl;
                x = true;
            }
            getline(PROFESOR, CodigoProfesor, '#');
        }
        if (!x)
        {
            cout << "No se encontró ningun profesor con ese código " << endl;
        }
        return x;
    }

    void MODIFICAR_PROFESOR_TXT(string CodigoProfesorAUX)
    {

        string CodigoProfesor, Cedula, Nombre, Apellido1, Apellido2, Telefono, Direccion, falso;
        ifstream PROFESOR;
        string MODIFICO;
        PROFESOR.open("PROFESOR_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("EDITADO.txt", ios ::out);
        bool x = false;

        if (PROFESOR.is_open() && !x)
        {

            getline(PROFESOR, CodigoProfesor, '#');

            while (!PROFESOR.eof() && x == false)
            {

                getline(PROFESOR, Cedula, '#');
                getline(PROFESOR, Nombre, '#');
                getline(PROFESOR, Apellido1, '#');
                getline(PROFESOR, Apellido2, '#');
                getline(PROFESOR, Telefono, '#');
                getline(PROFESOR, Direccion, '@');
                getline(PROFESOR, falso, '\n');

                if (CodigoProfesorAUX == CodigoProfesor)
                {
                    char respuesta;
                    cout << "MODIFICAR..." << endl
                         << "'1'->CEDULA" << endl
                         << "'2'->NOMBRE" << endl
                         << "'3'->PRIMER APELLIDO" << endl
                         << "'4'->SEGUNDO APELLIDO" << endl
                         << "'5'->TELEFONO" << endl
                         << "'6'->DIRECCION" << endl
                         << "'0'->SALIR AL MENU" << endl
                         << "DIGITE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR" << endl;
                    cin >> respuesta;

                    switch (respuesta)
                    {

                    case '1':

                        cout << "DIGITE LA MODIFICACION DEL CEDULA" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoProfesor << "#" << MODIFICO << "#" << Nombre << "#" << Apellido1 << "#" << Apellido2 << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;

                    case '2':

                        cout << "DIGITE LA MODIFICACION DEL NOMBRE" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoProfesor << "#" << Cedula << "#" << MODIFICO << "#" << Apellido1 << "#" << Apellido2 << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;

                    case '3':

                        cout << "DIGITE LA MODIFICACION DEL APELLIDO" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoProfesor << "#" << Cedula << "#" << Nombre << "#" << MODIFICO << "#" << Apellido2 << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;

                    case '4':

                        cout << "DIGITE LA MODIFICACION DEL APELLIDO" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoProfesor << "#" << Cedula << "#" << Nombre << "#" << Apellido1 << "#" << MODIFICO << "#" << Telefono << "#" << Direccion << endl;
                        x = true;
                        break;

                    case '5':

                        cout << "DIGITE LA MODIFICACION DEL TELEFONO" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoProfesor << "#" << Cedula << "#" << Nombre << "#" << Apellido1 << "#" << Apellido2 << "#" << MODIFICO << "#" << Direccion << endl;
                        x = true;
                        break;

                    case '6':
                        //getline(ESTUDIANTE,MODIFICO);
                        cin.ignore(256, '\n');
                        cout << "DIGITE LA MODIFICACION DE LA DIRECCION" << endl;
                        getline(cin, MODIFICO);
                        ARCHIVOAUX << CodigoProfesor << "#" << Cedula << "#" << Nombre << "#" << Apellido1 << "#" << Apellido2 << "#" << Telefono << "#" << MODIFICO << "@" << endl;
                        x = true;
                        break;
                    case '0':
                        x = true;
                        break;

                    default:
                        cout << "no entendí intenta de nuevo...";
                        getch();
                        x = false;
                        break;
                    }
                }
                else
                {
                    ARCHIVOAUX << CodigoProfesor << "#" << Cedula << "#" << Nombre << "#" << Apellido1 << "#" << Apellido2 << "#" << Nombre << "#" << Telefono << "#" << Direccion << "@" << endl;
                }

                getline(PROFESOR, CodigoProfesor, '#');
            }
        }
        PROFESOR.close();
        ARCHIVOAUX.close();
        remove("PROFESOR_TXT.txt");
        rename("EDITADO.txt", "PROFESOR_TXT.txt");
    }
    void ELIMINAR_PROFESOR_TXT(string CodigoProfesorAUX)
    {
        string CodigoProfesor, Cedula, Nombre, Apellido1, Apellido2, Telefono, Direccion, falso;
        ifstream PROFESOR;
        PROFESOR.open("PROFESOR_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("Mientras.txt", ios ::out);
        bool x = false;

        if (PROFESOR.is_open() && !x)
        {
            getline(PROFESOR, CodigoProfesor, '#');

            while (!PROFESOR.eof() && x == false)
            {
                getline(PROFESOR, Nombre, '#');
                getline(PROFESOR, Cedula, '#');
                getline(PROFESOR, Apellido1, '#');
                getline(PROFESOR, Apellido2, '#');
                getline(PROFESOR, Telefono, '#');
                getline(PROFESOR, Direccion, '@');
                getline(PROFESOR, falso, '\n');

                if (CodigoProfesorAUX == CodigoProfesor)
                {
                    cout << "PROFESOR ELIMINADO";
                    getch();
                }
                else
                {
                    ARCHIVOAUX << CodigoProfesor << "#" << Cedula << "#" << Nombre << "#" << Apellido1 << "#" << Apellido2 << "#" << Telefono << "#" << Direccion << "@" << endl;
                }
                getline(PROFESOR, CodigoProfesor, '#');
            }
        }
        PROFESOR.close();
        ARCHIVOAUX.close();
        remove("PROFESOR_TXT.txt");
        rename("Mientras.txt", "PROFESOR_TXT.txt");
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CURSO_TXT(string Nombre, string Creditos, int Cupos)
    {
        string CodigoCurso;
        char Codigo[4];
        srand(time(NULL));
        for (int i = 0; i <= 2; i++)
        {
            Codigo[i] = 48 + rand() % (57 - 48);
        }
        CodigoCurso = Codigo;
        if (BUSCAR_GRUPO_TXT(CodigoCurso))
        {
            CURSO_TXT(Nombre, Creditos, Cupos);
        }
        system("cls");
        ofstream CURSO("CURSO_TXT.txt", ios::out | ios::app);
        CURSO << CodigoCurso << "#" << Nombre << "#" << Creditos << "#" << Cupos << "@" << endl;
        CURSO.close();
    }
    void IMPRIMIR_CURSO_TXT()
    {

        ifstream CURSO;
        string CodigoCurso, Nombre, Creditos, falso;
        string Cupos;

        CURSO.open("CURSO_TXT.txt", ios::in);
        getline(CURSO, CodigoCurso, '#');

        while (!CURSO.eof())
        {

            getline(CURSO, Nombre, '#');
            getline(CURSO, Creditos, '#');
            getline(CURSO, Cupos, '@');
            getline(CURSO, falso, '\n');
            cout << "------------------------------------------------" << endl;
            cout << "Codigo Curso -->" << CodigoCurso << endl;
            cout << "Nombre -->" << Nombre << endl;
            cout << "Creditos -->" << Creditos << endl;
            cout << "Cupos -->" << Cupos << endl;
            cout << "------------------------------------------------" << endl;

            getline(CURSO, CodigoCurso, '#');
        }

        CURSO.close();
    }
    bool BUSCAR_CURSO(string codigoCursoAux)
    {
        ifstream CURSO;
        string CodigoCurso, Nombre, Creditos, Cupos, falso;
        bool x = false;

        CURSO.open("CURSO_TXT.txt", ios ::in);
        getline(CURSO, CodigoCurso, '#');
        while (!CURSO.eof() && !x)
        {
            getline(CURSO, Nombre, '#');
            getline(CURSO, Creditos, '#');
            getline(CURSO, Cupos, '@');
            getline(CURSO, falso, '\n');
            if (codigoCursoAux == CodigoCurso)
            {
                cout << "Encontrado..." << endl;
                cout << "CodigoCurso --> " << CodigoCurso << endl;
                cout << "Nombre --> " << Nombre << endl;
                cout << "Creditos --> " << Creditos << endl;
                cout << "Cupos --> " << Cupos << endl;
                x = true;
            }
            getline(CURSO, CodigoCurso, '#');
        }
        if (!x)
        {
            cout << "No se encontró ningun Curso con ese código " << endl;
        }
        return x;
    }
    void MODIFICAR_CURSO_TXT(string CodigoCursoAUX, int modifico)
    {

        string CodigoCurso, Nombre, Creditos, Cupos, falso;
        int INT;

        ifstream CURSO;
        string MODIFICO;
        CURSO.open("CURSO_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("EDITADO.txt", ios ::out);
        bool x = false;

        if (CURSO.is_open() && !x)
        {

            getline(CURSO, CodigoCurso, '#');

            while (!CURSO.eof() && x == false)
            {

                getline(CURSO, Nombre, '#');
                getline(CURSO, Creditos, '#');
                getline(CURSO, Cupos, '@');
                getline(CURSO, falso, '\n');

                if (modifico == 1 and CodigoCursoAUX == CodigoCurso)
                {
                    istringstream(Cupos) >> INT;
                    INT += 1;
                    Cupos = INT;
                    ARCHIVOAUX << CodigoCurso << "#" << Nombre << "#" << Creditos << "#" << INT << "@" << endl;
                }
                else if (modifico == 2 and CodigoCursoAUX == CodigoCurso)
                {
                    istringstream(Cupos) >> INT;
                    INT -= 1;
                    Cupos = INT;
                    ARCHIVOAUX << CodigoCurso << "#" << Nombre << "#" << Creditos << "#" << INT << "@" << endl;
                }
                else if (CodigoCursoAUX == CodigoCurso)
                {
                    char respuesta;
                    cout << "MODIFICAR..." << endl
                         << "'1'->NOMBRE" << endl
                         << "'2'->CANTIDAD CREDITOS" << endl
                         << "'3'->CUPOS" << endl
                         << "'0'->SALIR AL MENU" << endl
                         << "DIGITE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR" << endl;
                    cin >> respuesta;

                    switch (respuesta)
                    {

                    case '1':
                        cout << "DIGITE LA MODIFICACION DEL NOMBRE" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoCurso << "#" << MODIFICO << "#" << Creditos << "#" << Cupos << endl;
                        x = true;
                        break;

                    case '2':
                        cout << "DIGITE LA MODIFICACION DE LA CANTIDAD DE CREDITOS" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoCurso << "#" << Nombre << "#" << MODIFICO << "#" << Cupos << endl;
                        x = true;
                        break;

                    case '3':
                        cout << "DIGITE LA MODIFICACION DE LA CANTIDAD DE CUPOS" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoCurso << "#" << Nombre << "#" << Creditos << "#" << MODIFICO << "@" << endl;
                        x = true;
                        break;

                    case '0':
                        x = true;
                        break;

                    default:
                        cout << "no entendí intenta de nuevo...";
                        getch();
                        x = false;
                        break;
                    }
                }

                else
                {
                    ARCHIVOAUX << CodigoCurso << "#" << Nombre << "#" << Creditos << "#" << Cupos << "@" << endl;
                }

                getline(CURSO, CodigoCurso, '#');
            }
        }
        CURSO.close();
        ARCHIVOAUX.close();
        remove("CURSO_TXT.txt");
        rename("EDITADO.txt", "CURSO_TXT.txt");
    }

    void ELIMINAR_CURSO_TXT(string CodigoCursoAUX)
    {
        string CodigoCurso, Nombre, Creditos, Cupos, falso;
        ifstream CURSO;
        CURSO.open("CURSO_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("Mientras.txt", ios ::out);
        bool x = false;

        if (CURSO.is_open() && !x)
        {
            getline(CURSO, CodigoCurso, '#');

            while (!CURSO.eof() && x == false)
            {
                getline(CURSO, Nombre, '#');
                getline(CURSO, Creditos, '#');
                getline(CURSO, Cupos, '@');
                getline(CURSO, falso, '\n');

                if (CodigoCursoAUX == CodigoCurso)
                {
                    cout << "CURSO ELIMINADO";
                    getch();
                }
                else
                {
                    ARCHIVOAUX << CodigoCurso << "#" << Nombre << "#" << Creditos << "#" << Cupos << "@" << endl;
                }
                getline(CURSO, CodigoCurso, '#');
            }
        }
        CURSO.close();
        ARCHIVOAUX.close();
        remove("CURSO_TXT.txt");
        rename("Mientras.txt", "CURSO_TXT.txt");
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void HORARIO_TXT(string Descripcion, string Dia, string HoraioInicio, string HoraioFinal)
    {
        string CodigoHorario;
        char Codigo[4];
        srand(time(NULL));
        for (int i = 0; i <= 2; i++)
        {
            Codigo[i] = 48 + rand() % (57 - 48);
        }
        CodigoHorario = Codigo;
        if (BUSCAR_GRUPO_TXT(CodigoHorario))
        {
            HORARIO_TXT(Descripcion, Dia, HoraioInicio, HoraioFinal);
        }
        system("cls");
        ofstream HORARIO("HORARIO_TXT.txt", ios ::out | ios ::app);
        HORARIO << CodigoHorario << "#" << Descripcion << "#" << Dia << "#" << HoraioInicio << "#" << HoraioFinal << "@" << endl;
        HORARIO.close();
    }

    void IMPRIMIR_HORARIO_TXT()
    {

        ifstream HORARIO;
        string CodigoHorario, Descripcion, Dia, HoraioInicio, HoraioFinal, falsa;

        HORARIO.open("HORARIO_TXT.txt", ios::in);
        getline(HORARIO, CodigoHorario, '#');

        while (!HORARIO.eof())
        {
            getline(HORARIO, Descripcion, '#');
            getline(HORARIO, Dia, '#');
            getline(HORARIO, HoraioInicio, '#');
            getline(HORARIO, HoraioFinal, '@');
            getline(HORARIO, falsa, '\n');
            cout << "------------------------------------------------" << endl;
            cout << "CodigoHorario -->" << CodigoHorario << endl;
            cout << "Descripcion -->" << Descripcion << endl;
            cout << "Dia -->" << Dia << endl;
            cout << "Hora de Inicio -->" << HoraioInicio << endl;
            cout << "Hora de Finalizacion -->" << HoraioFinal << endl;
            cout << "------------------------------------------------" << endl;

            getline(HORARIO, CodigoHorario, '#');
        }

        HORARIO.close();
    }

    bool BUSCAR_HORARIO_TXT(string CodigoHorariAUX)
    {

        ifstream HORARIO;
        string CodigoHorario, Descripcion, Dia, HoraioInicio, HoraioFinal, falsa;
        bool x = false;

        HORARIO.open("HORARIO_TXT.txt", ios ::in);
        getline(HORARIO, CodigoHorario, '#');

        while (!HORARIO.eof() && !x)
        {

            getline(HORARIO, Descripcion, '#');
            getline(HORARIO, Dia, '#');
            getline(HORARIO, HoraioInicio, '#');
            getline(HORARIO, HoraioFinal, '@');
            getline(HORARIO, falsa, '\n');

            if (CodigoHorariAUX == CodigoHorario)
            {
                cout << "CodigoHorario -->" << CodigoHorario << endl;
                cout << "Descripcion -->" << Descripcion << endl;
                cout << "Dia -->" << Dia << endl;
                cout << "Hora de Inicio -->" << HoraioInicio << endl;
                cout << "Hora de Finalizacion -->" << HoraioFinal << endl;
                x = true;
            }
            getline(HORARIO, CodigoHorario, '#');
        }
        HORARIO.close();
        if (!x)
        {
            cout << "NO LO LOGRE" << endl;
        }
        return x;
    }
    void MODIFICAR_HORARIO_TXT(string CodigoHorariAUX)
    {

        string CodigoHorario, Descripcion, Dia, HoraioInicio, HoraioFinal, falsa;
        ifstream HORARIO;
        string MODIFICO;
        HORARIO.open("HORARIO_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("EDITADO.txt", ios ::out);
        bool x = false;

        if (HORARIO.is_open() && !x)
        {
            getline(HORARIO, CodigoHorario, '#');

            while (!HORARIO.eof() && x == false)
            {

                getline(HORARIO, Descripcion, '#');
                getline(HORARIO, Dia, '#');
                getline(HORARIO, HoraioInicio, '#');
                getline(HORARIO, HoraioFinal, '@');
                getline(HORARIO, falsa, '\n');

                if (CodigoHorariAUX == CodigoHorario)
                {
                    char respuesta;
                    cout << "MODIFICAR..." << endl
                         << "'1'->DESCRIPCION" << endl
                         << "'2'->DIA" << endl
                         << "'3'->HORARIO DE INICIO" << endl
                         << "'4'->HORARIO DE FINALIZACION" << endl
                         << "'0'->SALIR AL MENU" << endl
                         << "DIGITE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR" << endl;
                    cin >> respuesta;
                    switch (respuesta)
                    {

                    case '1':

                        cout << "DIGITE LA MODIFICACION DE LA DESCRIPCION" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoHorario << "#" << MODIFICO << "#" << Dia << "#" << HoraioInicio << "#" << HoraioFinal << "@" << endl;
                        x = true;
                        break;

                    case '2':

                        cout << "DIGITE LA MODIFICACION DEL DIA" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoHorario << "#" << Descripcion << "#" << MODIFICO << "#" << HoraioInicio << "#" << HoraioFinal << "@" << endl;
                        x = true;
                        break;

                    case '3':

                        cout << "DIGITE LA MODIFICACION DEL HORARIO INICIAL " << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoHorario << "#" << Descripcion << "#" << Dia << "#" << MODIFICO << "#" << HoraioFinal << "@" << endl;
                        x = true;
                        break;

                    case '4':

                        cout << "DIGITE LA MODIFICACION DEL HORARIO FINAL" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoHorario << "#" << Descripcion << "#" << Dia << "#" << HoraioInicio << "#" << MODIFICO << "@" << endl;
                        x = true;
                        break;

                    case '0':

                        x = true;
                        break;

                    default:
                        cout << "No entendí intenta de nuevo...";
                        getch();
                        x = false;
                        break;
                    }
                }
                else
                {
                    ARCHIVOAUX << CodigoHorario << "#" << Descripcion << "#" << Dia << "#" << HoraioInicio << "#" << HoraioFinal << "@" << endl;
                }

                getline(HORARIO, CodigoHorario, '#');
            }
        }

        HORARIO.close();
        ARCHIVOAUX.close();
        remove("HORARIO_TXT.txt");
        rename("EDITADO.txt", "HORARIO_TXT.txt");
    }

    void ELIMINAR_HORARIO_TXT(string CodigoHorarioAUX)
    {
        string CodigoHorario, Descripcion, Dia, HoraioInicio, HoraioFinal, falso;
        ifstream HORARIO;
        HORARIO.open("HORARIO_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("Mientras.txt", ios ::out);
        bool x = false;

        if (HORARIO.is_open() && !x)
        {
            getline(HORARIO, CodigoHorario, '#');

            while (!HORARIO.eof() && x == false)
            {
                getline(HORARIO, Descripcion, '#');
                getline(HORARIO, Dia, '#');
                getline(HORARIO, HoraioInicio, '#');
                getline(HORARIO, HoraioFinal, '@');
                getline(HORARIO, falso, '\n');

                if (CodigoHorarioAUX == CodigoHorario)
                {
                    cout << "HORARIO ELIMINADO";
                    getch();
                }
                else
                {
                    ARCHIVOAUX << CodigoHorario << "#" << Descripcion << "#" << Dia << "#" << HoraioInicio << "#" << HoraioFinal << "@" << endl;
                }
                getline(HORARIO, CodigoHorario, '#');
            }
        }
        HORARIO.close();
        ARCHIVOAUX.close();
        remove("HORARIO_TXT.txt");
        rename("Mientras.txt", "HORARIO_TXT.txt");
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GRUPO_TXT(string Descripcion)
    {
        string CodigoGrupo;
        char Codigo[4];
        srand(time(NULL));
        for (int i = 0; i <= 2; i++)
        {
            Codigo[i] = 48 + rand() % (57 - 48);
        }
        CodigoGrupo = Codigo;
        if (BUSCAR_GRUPO_TXT(CodigoGrupo))
        {
            GRUPO_TXT(Descripcion);
        }
        system("cls");

        ofstream GRUPO("GRUPO_TXT.txt", ios ::out | ios ::app);
        GRUPO << CodigoGrupo << "#" << Descripcion << "@" << endl;
        GRUPO.close();
    }

    void IMPRIMIR_GRUPO_TXT()
    {
        ifstream GRUPO;
        string CodigoGrupo, Descripcion, falsa;

        GRUPO.open("GRUPO_TXT.txt", ios::in);
        getline(GRUPO, CodigoGrupo, '#');

        while (!GRUPO.eof())
        {
            getline(GRUPO, Descripcion, '@');
            getline(GRUPO, falsa, '\n');

            cout << "------------------------------------------------" << endl;
            cout << "CodigoGrupo -->" << CodigoGrupo << endl;
            cout << "Descripcion -->" << Descripcion << endl;
            cout << "------------------------------------------------" << endl;

            getline(GRUPO, CodigoGrupo, '#');
        }

        GRUPO.close();
    }

    bool BUSCAR_GRUPO_TXT(string CodigoGrupoAUX)
    {

        ifstream GRUPO;
        string CodigoGrupo, Descripcion, falsa;
        bool x = false;

        GRUPO.open("GRUPO_TXT.txt", ios ::in);
        getline(GRUPO, CodigoGrupo, '#');

        while (!GRUPO.eof() && !x)
        {

            getline(GRUPO, Descripcion, '@');
            getline(GRUPO, falsa, '\n');

            if (CodigoGrupoAUX == CodigoGrupo)
            {
                cout << "CodigoGrupo -->" << CodigoGrupo << endl;
                cout << "Descripcion -->" << Descripcion << endl;
                x = true;
            }
            getline(GRUPO, CodigoGrupo, '#');
        }
        GRUPO.close();
        if (!x)
        {
            cout << "NO LO LOGRE" << endl;
        }
        return x;
    }

    void MODIFICAR_GRUPO_TXT(string CodigoGrupoAUX)
    {

        string CodigoGrupo, Descripcion, falsa;
        ifstream GRUPO;
        string MODIFICO;
        GRUPO.open("GRUPO_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("EDITADO.txt", ios ::out);
        bool x = false;

        if (GRUPO.is_open() && !x)
        {

            getline(GRUPO, CodigoGrupo, '#');

            while (!GRUPO.eof() && x == false)
            {

                getline(GRUPO, Descripcion, '@');
                getline(GRUPO, falsa, '\n');

                if (CodigoGrupoAUX == CodigoGrupo)
                {
                    char respuesta;
                    cout << "MODIFICAR..." << endl
                         << "'1'->DESCRIPCION" << endl
                         << "'0'->SALIR AL MENU" << endl
                         << "DIGITE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR" << endl;
                    cin >> respuesta;

                    switch (respuesta)
                    {

                    case '1':
                        cin.ignore(256, '\n');
                        cout << "DIGITE LA MODIFICACION DE LA DESCRIPCION" << endl;
                        getline(cin, MODIFICO);
                        ARCHIVOAUX << CodigoGrupo << "#" << MODIFICO << "@" << endl;
                        x = true;
                        break;

                    case '0':
                        x = true;
                        break;

                    default:
                        cout << "no entendí intenta de nuevo...";
                        getch();
                        x = false;
                        break;
                    }
                }

                else
                {
                    ARCHIVOAUX << CodigoGrupo << "#" << Descripcion << "@" << endl;
                }

                getline(GRUPO, CodigoGrupo, '#');
            }
        }
        GRUPO.close();
        ARCHIVOAUX.close();
        remove("GRUPO_TXT.txt");
        rename("EDITADO.txt", "GRUPO_TXT.txt");
    }

    void ELIMINAR_GRUPO_TXT(string CodigoGrupoAUX)
    {
        string CodigoGrupo, Descripcion, falso;
        ifstream GRUPO;
        GRUPO.open("GRUPO_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("Mientras.txt", ios ::out);
        bool x = false;

        if (GRUPO.is_open() && x == false)
        {
            getline(GRUPO, CodigoGrupo, '#');

            while (!GRUPO.eof() && x == false)
            {
                getline(GRUPO, Descripcion, '@');
                getline(GRUPO, falso, '\n');

                if (CodigoGrupoAUX == CodigoGrupo)
                {
                    cout << "GRUPO ELIMINADO";
                    getch();
                }
                else
                {
                    ARCHIVOAUX << CodigoGrupo << "#" << Descripcion << "@" << endl;
                }
                getline(GRUPO, CodigoGrupo, '#');
            }
        }
        GRUPO.close();
        ARCHIVOAUX.close();
        remove("GRUPO_TXT.txt");
        rename("Mientras.txt", "GRUPO_TXT.txt");
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void AULA_TXT(string Descripcion, string Capacidad)
    {
        string CodigoAula;
        char Codigo[4];
        srand(time(NULL));
        for (int i = 0; i <= 2; i++)
        {
            Codigo[i] = 48 + rand() % (57 - 48);
        }
        CodigoAula = Codigo;
        if (BUSCAR_AULA_TXT(CodigoAula))
        {
            AULA_TXT(Descripcion, Capacidad);
        }
        system("cls");
        ofstream AULA("AULA_TXT.txt", ios ::out | ios ::app);
        AULA << CodigoAula << "#" << Descripcion << "#" << Capacidad << "@" << endl;
        AULA.close();
    }

    void IMPRIMIR_AULA_TXT()
    {
        ifstream AULA;
        string CodigoAula, Descripcion, Capacidad, falsa;

        AULA.open("AULA_TXT.txt", ios::in);
        getline(AULA, CodigoAula, '#');

        while (!AULA.eof())
        {
            getline(AULA, Descripcion, '#');
            getline(AULA, Capacidad, '@');
            getline(AULA, falsa, '\n');

            cout << "------------------------------------------------" << endl;
            cout << "CodigoAula -->" << CodigoAula << endl;
            cout << "Descripcion -->" << Descripcion << endl;
            cout << "Capacidad -->" << Capacidad << endl;
            cout << "------------------------------------------------" << endl;

            getline(AULA, CodigoAula, '#');
        }

        AULA.close();
    }

    bool BUSCAR_AULA_TXT(string CodigoAulaAUX)
    {

        ifstream AULA;
        string CodigoAula, Descripcion, Capacidad, falsa;
        bool x = false;

        AULA.open("AULA_TXT.txt", ios ::in);
        getline(AULA, CodigoAula, '#');

        while (!AULA.eof() && !x)
        {
            getline(AULA, Descripcion, '#');
            getline(AULA, Capacidad, '@');
            getline(AULA, falsa, '\n');

            if (CodigoAulaAUX == CodigoAula)
            {
                cout << "CodigoAula -->" << CodigoAula << endl;
                cout << "Descripcion -->" << Descripcion << endl;
                cout << "Capacidad -->" << Capacidad << endl;
                x = true;
            }
            getline(AULA, CodigoAula, '#');
        }
        AULA.close();
        if (!x)
        {
            cout << "NO LO LOGRE" << endl;
        }
        return x;
    }

    void MODIFICAR_AULA_TXT(string CodigoAulaAUX)
    {

        ifstream AULA;

        string CodigoAula, Descripcion, Capacidad, falsa;
        string MODIFICO;

        AULA.open("AULA_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("EDITADO.txt", ios ::out);
        bool x = false;

        if (AULA.is_open() && !x)
        {

            getline(AULA, CodigoAula, '#');

            while (!AULA.eof() && x == false)
            {

                getline(AULA, Descripcion, '#');
                getline(AULA, Capacidad, '@');
                getline(AULA, falsa, '\n');

                if (CodigoAulaAUX == CodigoAula)
                {
                    char respuesta;
                    cout << "MODIFICAR..." << endl
                         << "'1'->DESCRIPCION" << endl
                         << "'2'->CAPACIDAD" << endl
                         << "'0'->SALIR AL MENU" << endl
                         << "DIGITE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR" << endl;
                    cin >> respuesta;

                    switch (respuesta)
                    {

                    case '1':
                        cout << "DIGITE LA MODIFICACION DE LA DESCRIPCION" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoAula << "#" << MODIFICO << "#" << Capacidad << "@" << endl;
                        x = true;
                        break;

                    case '2':
                        cout << "DIGITE LA MODIFICACION DEL CAPACIDAD" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoAula << "#" << Descripcion << "#" << MODIFICO << "@" << endl;
                        x = true;
                        break;

                    case '0':
                        x = true;
                        break;

                    default:
                        cout << "no entendí intenta de nuevo...";
                        getch();
                        x = false;
                        break;
                    }
                }

                else
                {
                    ARCHIVOAUX << CodigoAula << "#" << Descripcion << "#" << Capacidad << "@" << endl;
                }

                getline(AULA, CodigoAula, '#');
            }
        }
        AULA.close();
        ARCHIVOAUX.close();
        remove("AULA_TXT.txt");
        rename("EDITADO.txt", "AULA_TXT.txt");
    }

    void ELIMINAR_AULA_TXT(string CodigoAulaAUX)
    {
        string CodigoAula, Descripcion, Capacidad, falsa;
        ifstream AULA;
        AULA.open("AULA_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("Mientras.txt", ios ::out);
        bool x = false;

        if (AULA.is_open() && x == false)
        {
            getline(AULA, CodigoAula, '#');

            while (!AULA.eof() && x == false)
            {
                getline(AULA, Descripcion, '#');
                getline(AULA, Capacidad, '@');
                getline(AULA, falsa, '\n');

                if (CodigoAulaAUX == CodigoAula)
                {
                    cout << "GRUPO ELIMINADO";
                    getch();
                }
                else
                {
                    ARCHIVOAUX << CodigoAula << "#" << Descripcion << "#" << Capacidad << "@" << endl;
                }
                getline(AULA, CodigoAula, '#');
            }
        }
        AULA.close();
        ARCHIVOAUX.close();
        remove("AULA_TXT.txt");
        rename("Mientras.txt", "AULA_TXT.txt");
    }

    void VERIFICAR_MATRICULAR()
    {
        string CodigoMatricula, CodigoEstudiante, CodigoGrupo, CodigoCurso, CodigoProfesor, CodigoHorario, Comprobante;
        char Codigo[4];
        srand(time(NULL));
        for (int i = 0; i <= 2; i++)
        {
            Codigo[i] = 48 + rand() % (57 - 48);
        }
        CodigoMatricula = Codigo;
        if (BUSCAR_MATRICULA_TXT(CodigoMatricula, "X"))
        {
            VERIFICAR_MATRICULAR();
        }
        system("cls");

        ///////////////////////////////////////////////////////////////////////////////
        cout << "DIGITE EL CODIGO DE ESTUDIANTE: " << endl;
        cin >> CodigoEstudiante;
        if (BUSCAR_ESTUDIANTE_TXT(CodigoEstudiante) == false)
        {
            system("cls");
            while (true)
            {
                cout << "CODIGO DE ESTUDIANTE INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE ESTUDIANTE " << endl;
                cin >> CodigoEstudiante;
                if (BUSCAR_ESTUDIANTE_TXT(CodigoEstudiante) == true)
                {
                    system("cls");
                    break;
                }
            }
        }
        system("cls");
        ///////////////////////////////////////////////////////
        cout << "DIGITE EL CODIGO DE GRUPO: " << endl;
        cin >> CodigoGrupo;
        system("cls");
        if (BUSCAR_GRUPO_TXT(CodigoGrupo) == false)
        {
            while (true)
            {
                cout << "CODIGO DE GRUPO INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE GRUPO " << endl;
                cin >> CodigoGrupo;
                if (BUSCAR_GRUPO_TXT(CodigoGrupo) == true)
                {
                    system("cls");
                    break;
                }
            }
        }
        system("cls");
        //////////////////////////////////////////////////

        cout << "DIGITE EL CODIGO DE CURSO: " << endl;
        cin >> CodigoCurso;

        if (BUSCAR_CURSO(CodigoCurso) == false)
        {
            system("cls");
            while (true)
            {
                cout << "CODIGO DE CURSO INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE CURSO " << endl;
                cin >> CodigoCurso;
                if (BUSCAR_CURSO(CodigoCurso) == true)
                {
                    system("cls");
                    break;
                }
            }
        }
        system("cls");
        //////////////////////////////////////////////////
        cout << "DIGITE EL CODIGO DE PROFESOR: " << endl;
        cin >> CodigoProfesor;

        if (BUSCAR_PROFESOR(CodigoProfesor) == false)
        {
            system("cls");
            while (true)
            {
                cout << "CODIGO DE PROFESOR INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE PROFESOR " << endl;
                cin >> CodigoProfesor;
                if (BUSCAR_PROFESOR(CodigoProfesor) == true)
                {
                    system("cls");
                    break;
                }
            }
        }
        system("cls");
        ///////////////////////////////////////////////////////
        cout << "DIGITE EL CODIGO DE HORARIO: " << endl;
        cin >> CodigoHorario;

        if (BUSCAR_HORARIO_TXT(CodigoHorario) == false)
        {
            system("cls");
            while (true)
            {
                cout << "CODIGO DE HORARIO INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE HORARIO " << endl;
                cin >> CodigoHorario;
                if (BUSCAR_HORARIO_TXT(CodigoHorario) == true)
                {
                    system("cls");
                    // NOMBRE DEL ARCHIVO  << CodigoEstudiante;
                    break;
                }
            }
        }
        system("cls");
        //////////////////////////////////////////////////
        char Com[50];
        srand(time(NULL));
        for (int i = 0; i <= 50; i++)
        {
            Com[i] = 48 + rand() % (90 - 48);
            if (Com[i] >= 58 and Com[i] <= 64)
            {
                Com[i] = 48 + rand() % (57 - 48);
            }
        }
        Comprobante = Com;
        //////////////////////////////////////////////////
        MATRICULA_TXT(CodigoMatricula, CodigoEstudiante, CodigoGrupo, CodigoCurso, CodigoProfesor, CodigoHorario, Comprobante);
    };

    void MATRICULA_TXT(string CodigoMatricula, string CodigoEstudiante, string CodigoGrupo, string CodigoCurso, string CodigoProfesor, string CodigoHorario, string Comprobante)
    {
        ofstream MATRICULA("MATRICULA_TXT.txt", ios ::out | ios ::app);
        MATRICULA << CodigoMatricula << "#" << CodigoEstudiante << "#" << CodigoGrupo << "#" << CodigoCurso << "#" << CodigoProfesor << "#" << CodigoHorario << "#" << Comprobante << "@" << endl;
        MODIFICAR_CURSO_TXT(CodigoCurso, 2);
        MATRICULA.close();
    }

    void MODIFICAR_MATRICULA(string CodigoMatriculaAUX)
    {

        ifstream MATRICULA;

        string CodigoMatricula, CodigoEstudiante, CodigoGrupo, CodigoCurso, CodigoProfesor, CodigoHorario, Comprobante, falsa;
        string MODIFICO;

        MATRICULA.open("MATRICULA_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("EDITADO.txt", ios ::out);
        bool x = false;

        if (MATRICULA.is_open() && !x)
        {

            getline(MATRICULA, CodigoMatricula, '#');

            while (!MATRICULA.eof() && x == false)
            {

                getline(MATRICULA, CodigoEstudiante, '#');
                getline(MATRICULA, CodigoGrupo, '#');
                getline(MATRICULA, CodigoCurso, '#');
                getline(MATRICULA, CodigoProfesor, '#');
                getline(MATRICULA, CodigoHorario, '#');
                getline(MATRICULA, Comprobante, '@');
                getline(MATRICULA, falsa, '\n');

                if (CodigoMatriculaAUX == CodigoMatricula)
                {
                    char respuesta;
                    cout << "MODIFICAR..." << endl
                         << "'1'->CODIGO ESTUDIANTE" << endl
                         << "'2'->CODIGO GRUPO" << endl
                         << "'3'->CODIGO CURSO" << endl
                         << "'4'->CODIGO PROFESOR" << endl
                         << "'5'->CODIGO HORARIO" << endl
                         << "'6'->COMPROBANTE" << endl
                         << "'0'->SALIR AL MENU" << endl
                         << "DIGITE EL NUMERO DE LA OPCION QUE DESEA MODIFICAR" << endl;
                    cin >> respuesta;

                    switch (respuesta)
                    {

                    case '1':

                        cout << "DIGITE LA MODIFICACION DEL CODIGO ESTUDIANTE" << endl;
                        cin >> MODIFICO;
                        if (BUSCAR_ESTUDIANTE_TXT(MODIFICO) == false)
                        {
                            system("cls");
                            while (true)
                            {
                                cout << "CODIGO DE ESTUDIANTE INVALIDO" << endl;
                                cout << "DIGITE NUEVAMENTE EL CODIGO DE ESTUDIANTE " << endl;
                                cin >> MODIFICO;
                                if (BUSCAR_ESTUDIANTE_TXT(MODIFICO) == true)
                                {
                                    system("cls");
                                    ARCHIVOAUX << CodigoMatricula << "#" << MODIFICO << "#" << CodigoGrupo << "#" << CodigoCurso << "#" << CodigoProfesor << "#" << CodigoHorario << "#" << Comprobante << "@" << endl;
                                    x = true;
                                    break;
                                }
                            }
                        }
                        system("cls");
                        x = true;
                        break;

                    case '2':

                        cout << "DIGITE LA MODIFICACION DEL CODIGO GRUPO" << endl;
                        cin >> MODIFICO;
                        system("cls");
                        if (BUSCAR_GRUPO_TXT(MODIFICO) == false)
                        {
                            while (true)
                            {
                                cout << "CODIGO DE GRUPO INVALIDO" << endl;
                                cout << "DIGITE NUEVAMENTE EL CODIGO DE GRUPO " << endl;
                                cin >> CodigoGrupo;
                                if (BUSCAR_GRUPO_TXT(MODIFICO) == true)
                                {
                                    system("cls");
                                    ARCHIVOAUX << CodigoMatricula << "#" << CodigoEstudiante << "#" << MODIFICO << "#" << CodigoCurso << "#" << CodigoProfesor << "#" << CodigoHorario << "#" << Comprobante << "@" << endl;
                                    x = true;
                                    break;
                                }
                            }
                        }
                        system("cls");
                        x = true;
                        break;

                    case '3':

                        cout << "DIGITE LA MODIFICACION DEL CODIGO DEL CURSO" << endl;
                        cin >> MODIFICO;
                        if (BUSCAR_CURSO(MODIFICO) == false)
                        {
                            system("cls");
                            while (true)
                            {
                                cout << "CODIGO DE CURSO INVALIDO" << endl;
                                cout << "DIGITE NUEVAMENTE EL CODIGO DE CURSO " << endl;
                                cin >> MODIFICO;
                                if (BUSCAR_CURSO(MODIFICO) == true)
                                {
                                    system("cls");
                                    ARCHIVOAUX << CodigoMatricula << "#" << CodigoEstudiante << "#" << CodigoGrupo << "#" << MODIFICO << "#" << CodigoProfesor << "#" << CodigoHorario << "#" << Comprobante << "@" << endl;
                                    x = true;
                                    break;
                                }
                            }
                        }
                        system("cls");
                        x = true;
                        break;

                    case '4':

                        cout << "DIGITE LA MODIFICACION DEL CODIGO PROFESOR" << endl;
                        cin >> MODIFICO;

                        if (BUSCAR_PROFESOR(MODIFICO) == false)
                        {
                            system("cls");
                            while (true)
                            {
                                cout << "CODIGO DE PROFESOR INVALIDO" << endl;
                                cout << "DIGITE NUEVAMENTE EL CODIGO DE PROFESOR " << endl;
                                cin >> MODIFICO;
                                if (BUSCAR_PROFESOR(MODIFICO) == true)
                                {
                                    system("cls");
                                    ARCHIVOAUX << CodigoMatricula << "#" << CodigoEstudiante << "#" << CodigoGrupo << "#" << CodigoCurso << "#" << MODIFICO << "#" << CodigoHorario << "#" << Comprobante << "@" << endl;
                                    x = true;
                                    break;
                                }
                            }
                        }
                        system("cls");
                        x = true;
                        break;

                    case '5':

                        cout << "DIGITE LA MODIFICACION DEL HORARIO" << endl;
                        cin >> MODIFICO;
                        if (BUSCAR_PROFESOR(MODIFICO) == false)
                        {
                            system("cls");
                            while (true)
                            {
                                cout << "CODIGO DE PROFESOR INVALIDO" << endl;
                                cout << "DIGITE NUEVAMENTE EL CODIGO DE HORARIO " << endl;
                                cin >> MODIFICO;
                                if (BUSCAR_PROFESOR(MODIFICO) == true)
                                {
                                    system("cls");
                                    ARCHIVOAUX << CodigoMatricula << "#" << CodigoEstudiante << "#" << CodigoGrupo << "#" << CodigoCurso << "#" << CodigoProfesor << "#" << MODIFICO << "#" << Comprobante << "@" << endl;
                                    x = true;
                                    break;
                                }
                            }
                        }

                        system("cls");
                        x = true;
                        break;

                    case '6':

                        cout << "DIGITE LA MODIFICACION DEL COMPROBANTE" << endl;
                        cin >> MODIFICO;
                        ARCHIVOAUX << CodigoMatricula << "#" << CodigoEstudiante << "#" << CodigoGrupo << "#" << CodigoCurso << "#" << CodigoProfesor << "#" << CodigoHorario << "#" << MODIFICO << "@" << endl;
                        x = true;
                        break;

                    case '0':

                        x = true;
                        break;

                    default:
                        cout << "no entendí intenta de nuevo...";
                        getch();
                        x = false;
                        break;
                    }
                }

                else
                {
                    ARCHIVOAUX << CodigoMatricula << "#" << CodigoEstudiante << "#" << CodigoGrupo << "#" << CodigoCurso << "#" << CodigoProfesor << "#" << CodigoHorario << "#" << Comprobante << "@" << endl;
                }

                getline(MATRICULA, CodigoMatricula, '#');
            }
        }

        MATRICULA.close();
        ARCHIVOAUX.close();

        remove("MATRICULA_TXT.txt");
        rename("EDITADO.txt", "MATRICULA_TXT.txt");
    }

    void ELIMINAR_MATRICULA_TXT(string CodigoMatriculaAUX)
    {
        string CodigoMatricula, CodigoEstudiante, CodigoGrupo, CodigoCurso, CodigoProfesor, CodigoHorario, Comprobante, falsa;
        ifstream MATRICULA;
        MATRICULA.open("MATRICULA_TXT.txt", ios ::in);
        ofstream ARCHIVOAUX("Mientras.txt", ios ::out);
        bool x = false;

        if (MATRICULA.is_open() && x == false)
        {
            getline(MATRICULA, CodigoMatricula, '#');

            while (!MATRICULA.eof() && x == false)
            {
                getline(MATRICULA, CodigoEstudiante, '#');
                getline(MATRICULA, CodigoGrupo, '#');
                getline(MATRICULA, CodigoCurso, '#');
                getline(MATRICULA, CodigoProfesor, '#');
                getline(MATRICULA, CodigoHorario, '#');
                getline(MATRICULA, Comprobante, '@');
                getline(MATRICULA, falsa, '\n');

                if (CodigoMatriculaAUX == CodigoMatricula)
                {

                    cout << "MATRICULA ELIMINADA";
                    MODIFICAR_CURSO_TXT(CodigoCurso, 1);
                    if (!BUSCAR_MATRICULA_TXT("x", CodigoEstudiante))
                    {
                        system("cls");
                        ELIMINAR_ESTUDIANTE_TXT(CodigoEstudiante);
                        cout << "ESTUDIANTE BORRADO DEL REGISTRO" << endl;
                        getch();
                    }
                    system("cls");
                    getch();
                }
                else
                {
                    ARCHIVOAUX << CodigoMatricula << "#" << CodigoEstudiante << "#" << CodigoGrupo << "#" << CodigoCurso << "#" << CodigoProfesor << "#" << CodigoHorario << "#" << Comprobante << "@" << endl;
                }
                getline(MATRICULA, CodigoMatricula, '#');
            }
        }
        MATRICULA.close();
        ARCHIVOAUX.close();
        remove("MATRICULA_TXT.txt");
        rename("Mientras.txt", "MATRICULA_TXT.txt");
    }
    bool BUSCAR_MATRICULA_TXT(string CodigoMatriculaAUX, string CodigoEstudianteAUX)
    {

        ifstream MATRICULA;
        string CodigoMatricula, CodigoEstudiante, CodigoGrupo, CodigoCurso, CodigoProfesor, CodigoHorario, Comprobante, falsa;
        bool x = false;

        MATRICULA.open("MATRICULA_TXT.txt", ios ::in);
        getline(MATRICULA, CodigoMatricula, '#');

        while (!MATRICULA.eof() && !x)
        {
            getline(MATRICULA, CodigoEstudiante, '#');
            getline(MATRICULA, CodigoGrupo, '#');
            getline(MATRICULA, CodigoCurso, '#');
            getline(MATRICULA, CodigoProfesor, '#');
            getline(MATRICULA, CodigoHorario, '#');
            getline(MATRICULA, Comprobante, '@');
            getline(MATRICULA, falsa, '\n');

            if (CodigoEstudianteAUX != "x")
            {
                if (CodigoMatriculaAUX == CodigoMatricula)
                {
                    cout << "Codigo Matricula -->" << CodigoMatricula << endl;
                    cout << "Codigo Estudiante -->" << CodigoEstudiante << endl;
                    cout << "Codigo Grupo -->" << CodigoGrupo << endl;
                    cout << "Codigo Curso -->" << CodigoCurso << endl;
                    cout << "Codigo Profesor -->" << CodigoProfesor << endl;
                    cout << "Codigo Horario -->" << CodigoHorario << endl;
                    cout << "Comprobante -->" << Comprobante << endl;
                    x = true;
                }
                getline(MATRICULA, CodigoMatricula, '#');
            }
            else
            {
                if (CodigoEstudianteAUX == CodigoEstudianteAUX)
                {
                    x = true;
                }
            }
        }
        MATRICULA.close();
        if (!x)
        {
            cout << "NO LOGRE ENCONTRAR UNA MATRICULA CON ESE CODIGO" << endl;
        }
        return x;
    }

    void NUEVO_MATRICULA_TXT()
    {
        string yo;
        string CodigoMatricula, CodigoEstudiante, CodigoGrupo, CodigoCurso, CodigoProfesor, CodigoHorario, Comprobante;

        cout << "DIGITE EL NOMBRE DEL NUEVO PROCESO DE MATRICULA" << endl;
        cin >> yo;
        yo = yo + ".txt";
        ofstream MATRICULA(yo.c_str(), ios ::out | ios ::app);
        system("cls");
        cout << "Creando nueva matricula...";
        for (int i = 0; i < 8; i++)
        {
            Sleep(900);
            cout << "...";
        }

        char Codigo[4];
        srand(time(NULL));
        for (int i = 0; i <= 2; i++)
        {
            Codigo[i] = 48 + rand() % (57 - 48);
        }
        
        CodigoMatricula = Codigo;
        char lec = 'd';
        while (lec != '0')
        {
            system("cls");
            ///////////////////////////////////////////////////////////////////////////////
        cout << "DIGITE EL CODIGO DE ESTUDIANTE: " << endl;
        cin >> CodigoEstudiante;
        if (BUSCAR_ESTUDIANTE_TXT(CodigoEstudiante) == false)
        {
            system("cls");
            while (true)
            {
                cout << "CODIGO DE ESTUDIANTE INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE ESTUDIANTE " << endl;
                cin >> CodigoEstudiante;
                if (BUSCAR_ESTUDIANTE_TXT(CodigoEstudiante) == true)
                {
                    system("cls");
                    break;
                }
            }
        }
        system("cls");
        ///////////////////////////////////////////////////////
        cout << "DIGITE EL CODIGO DE GRUPO: " << endl;
        cin >> CodigoGrupo;
        system("cls");
        if (BUSCAR_GRUPO_TXT(CodigoGrupo) == false)
        {
            while (true)
            {
                cout << "CODIGO DE GRUPO INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE GRUPO " << endl;
                cin >> CodigoGrupo;
                if (BUSCAR_GRUPO_TXT(CodigoGrupo) == true)
                {
                    system("cls");
                    break;
                }
            }
        }
        system("cls");
        //////////////////////////////////////////////////

        cout << "DIGITE EL CODIGO DE CURSO: " << endl;
        cin >> CodigoCurso;

        if (BUSCAR_CURSO(CodigoCurso) == false)
        {
            system("cls");
            while (true)
            {
                cout << "CODIGO DE CURSO INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE CURSO " << endl;
                cin >> CodigoCurso;
                if (BUSCAR_CURSO(CodigoCurso) == true)
                {
                    system("cls");
                    break;
                }
            }
        }
        system("cls");
        //////////////////////////////////////////////////
        cout << "DIGITE EL CODIGO DE PROFESOR: " << endl;
        cin >> CodigoProfesor;

        if (BUSCAR_PROFESOR(CodigoProfesor) == false)
        {
            system("cls");
            while (true)
            {
                cout << "CODIGO DE PROFESOR INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE PROFESOR " << endl;
                cin >> CodigoProfesor;
                if (BUSCAR_PROFESOR(CodigoProfesor) == true)
                {
                    system("cls");
                    break;
                }
            }
        }
        system("cls");
        ///////////////////////////////////////////////////////
        cout << "DIGITE EL CODIGO DE HORARIO: " << endl;
        cin >> CodigoHorario;

        if (BUSCAR_HORARIO_TXT(CodigoHorario) == false)
        {
            system("cls");
            while (true)
            {
                cout << "CODIGO DE HORARIO INVALIDO" << endl;
                cout << "DIGITE NUEVAMENTE EL CODIGO DE HORARIO " << endl;
                cin >> CodigoHorario;
                if (BUSCAR_HORARIO_TXT(CodigoHorario) == true)
                {
                    system("cls");
                    // NOMBRE DEL ARCHIVO  << CodigoEstudiante;
                    break;
                }
            }
        }
        system("cls");
        //////////////////////////////////////////////////

            char Com[50];
            srand(time(NULL));
            for (int i = 0; i <= 50; i++)
            {
                Com[i] = 48 + rand() % (90 - 48);
                if (Com[i] >= 58 and Com[i] <= 64)
                {
                    Com[i] = 48 + rand() % (57 - 48);
                }
            }
            Comprobante = Com;
            MATRICULA << CodigoMatricula << "#" << CodigoEstudiante << "#" << CodigoGrupo << "#" << CodigoCurso << "#" << CodigoProfesor << "#" << CodigoHorario << "#" << Comprobante << "@" << endl;
            MODIFICAR_CURSO_TXT(CodigoCurso, 2);
            while(true){
                system("cls");
                cout << " Presiona '0' para salir o '1' para añadir otro estudiante al sistema de matricula: " << endl;
                cin>>lec;
                if (lec != '0' and lec != '1')
                {
                    system("cls");
                    cout << "No comprendí..." << endl;
                    getch();
                }
                else
                {
                    break;
                }
            }
            if (lec == '0')
            {
                cout << "Dios";
                break;
            }
        }
        MATRICULA.close();
    }
};