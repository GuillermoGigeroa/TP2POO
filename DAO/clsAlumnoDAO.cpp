#include "clsAlumnoDAO.h"
#include <cstdio>

bool clsAlumnoDAO::Insertar(clsAlumnoDTO dto)
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_ALUMNOS,"ab");
    if(archivo == NULL)
        return false;
    fwrite(&dto,sizeof(clsAlumnoDTO),1,archivo);
    fclose(archivo);
    return true;
}

bool clsAlumnoDAO::Eliminar(int legajo)
{
    FILE *archivo;
    int pos = 0;
    clsAlumnoDTO dto;
    CrearArchivoAlumnosSiNoExiste();
    archivo = fopen(ARCHIVO_ALUMNOS,"rb+");
    if(archivo == NULL)
        return false;
    while(fread(&dto,sizeof(clsAlumnoDTO),1,archivo))
    {
        if(dto.GetLegajo()==legajo && !dto.GetEliminado())
        {
            dto.SetEliminado(true);
            fseek(archivo,sizeof(clsAlumnoDTO)*pos,SEEK_SET);
            fwrite(&dto,sizeof(clsAlumnoDTO),1,archivo);
            fclose(archivo);
            return true;
        }
        pos++;
    }
    fclose(archivo);
    return false;
}

bool clsAlumnoDAO::Modificar(clsAlumnoDTO dto)
{
    FILE *archivo;
    int pos = 0;
    clsAlumnoDTO dto_archivo;
    CrearArchivoAlumnosSiNoExiste();
    archivo = fopen(ARCHIVO_ALUMNOS,"rb+");
    if(archivo == NULL)
        return false;
    while(fread(&dto_archivo,sizeof(clsAlumnoDTO),1,archivo))
    {
        if(dto_archivo.GetLegajo()==dto.GetLegajo() && !dto.GetEliminado())
        {
            fseek(archivo,sizeof(clsAlumnoDTO)*pos,SEEK_SET);
            fwrite(&dto,sizeof(clsAlumnoDTO),1,archivo);
            fclose(archivo);
            return true;
        }
        pos++;
    }
    fclose(archivo);
    return false;
}

bool clsAlumnoDAO::Listar(clsAlumnoDTO *dto)
{
    FILE *archivo;
    int pos = 0;
    clsAlumnoDTO dto_archivo;
    CrearArchivoAlumnosSiNoExiste();
    archivo = fopen(ARCHIVO_ALUMNOS,"rb");
    if(archivo == NULL)
        return false;
    while(fread(&dto_archivo,sizeof(clsAlumnoDTO),1,archivo))
    {
        if (!dto_archivo.GetEliminado())
        {
            dto[pos++].Copy(dto_archivo);
        }
    }
    fclose(archivo);
    return true;
}

int clsAlumnoDAO::Count()
{
    FILE *archivo;
    int cantidad = 0;
    clsAlumnoDTO dto;
    CrearArchivoAlumnosSiNoExiste();
    archivo = fopen(ARCHIVO_ALUMNOS,"rb");
    if(archivo == NULL)
        return 0;
    while(fread(&dto,sizeof(clsAlumnoDTO),1,archivo))
    {
        if(!dto.GetEliminado())
        {
            cantidad++;
        }
    }
    fclose(archivo);
    return cantidad;
}

int clsAlumnoDAO::GeneradorDeLegajo()
{
    FILE *archivo;
    int cantidad = 0;
    clsAlumnoDTO dto;
    CrearArchivoAlumnosSiNoExiste();
    archivo = fopen(ARCHIVO_ALUMNOS,"rb");
    if(archivo == NULL)
        return 0;
    while(fread(&dto,sizeof(clsAlumnoDTO),1,archivo))
    {
        cantidad++;
    }
    fclose(archivo);
    return cantidad;
}

void clsAlumnoDAO::CrearArchivoAlumnosSiNoExiste()
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_ALUMNOS,"ab");
    fclose(archivo);
}
