#include "clsMateriaDAO.h"
#include <cstdio>

bool clsMateriaDAO::Insertar(clsMateriaDTO dto)
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_MATERIAS,"ab");
    if(archivo == NULL)
        return false;
    fwrite(&dto,sizeof(clsMateriaDTO),1,archivo);
    fclose(archivo);
    return true;
}

bool clsMateriaDAO::Eliminar(int ID)
{
    FILE *archivo;
    int pos = 0;
    clsMateriaDTO dto;
    CrearArchivoMateriaSiNoExiste();
    archivo = fopen(ARCHIVO_MATERIAS,"rb+");
    if(archivo == NULL)
        return false;
    while(fread(&dto,sizeof(clsMateriaDTO),1,archivo))
    {
        if(dto.GetID()==ID && !dto.GetEliminado())
        {
            dto.SetEliminado(true);
            fseek(archivo,sizeof(clsMateriaDTO)*pos,SEEK_SET);
            fwrite(&dto,sizeof(clsMateriaDTO),1,archivo);
            fclose(archivo);
            return true;
        }
        pos++;
    }
    fclose(archivo);
    return false;
}

bool clsMateriaDAO::Modificar(clsMateriaDTO dto)
{
    FILE *archivo;
    int pos = 0;
    clsMateriaDTO dto_archivo;
    CrearArchivoMateriaSiNoExiste();
    archivo = fopen(ARCHIVO_MATERIAS,"rb+");
    if(archivo == NULL)
        return false;
    while(fread(&dto_archivo,sizeof(clsMateriaDTO),1,archivo))
    {
        if(dto_archivo.GetID()==dto.GetID() && !dto.GetEliminado())
        {
            fseek(archivo,sizeof(clsMateriaDTO)*pos,SEEK_SET);
            fwrite(&dto,sizeof(clsMateriaDTO),1,archivo);
            fclose(archivo);
            return true;
        }
        pos++;
    }
    fclose(archivo);
    return false;
}

bool clsMateriaDAO::Listar(clsMateriaDTO *dto)
{
    FILE *archivo;
    int pos = 0;
    clsMateriaDTO dto_archivo;
    CrearArchivoMateriaSiNoExiste();
    archivo = fopen(ARCHIVO_MATERIAS,"rb");
    if(archivo == NULL)
        return false;
    while(fread(&dto_archivo,sizeof(clsMateriaDTO),1,archivo))
    {
        if (!dto_archivo.GetEliminado())
        {
            dto[pos++].Copy(dto_archivo);
        }
    }
    fclose(archivo);
    return true;
}

int clsMateriaDAO::Count()
{
    FILE *archivo;
    int cantidad = 0;
    clsMateriaDTO dto;
    CrearArchivoMateriaSiNoExiste();
    archivo = fopen(ARCHIVO_MATERIAS,"rb");
    if(archivo == NULL)
        return 0;
    while(fread(&dto,sizeof(clsMateriaDTO),1,archivo))
    {
        if(!dto.GetEliminado())
        {
            cantidad++;
        }
    }
    fclose(archivo);
    return cantidad;
}

int clsMateriaDAO::GeneradorDeID()
{
    FILE *archivo;
    int cantidad = 0;
    clsMateriaDTO dto;
    CrearArchivoMateriaSiNoExiste();
    archivo = fopen(ARCHIVO_MATERIAS,"rb");
    if(archivo == NULL)
        return 0;
    while(fread(&dto,sizeof(clsMateriaDTO),1,archivo))
    {
        cantidad++;
    }
    fclose(archivo);
    return cantidad;
}

void clsMateriaDAO::CrearArchivoMateriaSiNoExiste()
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_MATERIAS,"ab");
    fclose(archivo);
}
