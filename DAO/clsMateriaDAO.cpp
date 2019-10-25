#include "clsMateriaDAO.h"
#include <cstdio>

bool clsMateriaDAO::Insertar(clsMateriaDTO dto)
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_MATERIAS,"ab");
    if(archivo == NULL)return false;
    fwrite(&dto,sizeof(clsMateriaDTO),1,archivo);
    return true;
}

bool clsMateriaDAO::Eliminar(int ID)
{
    FILE *archivo;
    int pos = 0;
    clsMateriaDTO dto;
    archivo = fopen(ARCHIVO_MATERIAS,"rb+");
    if(archivo == NULL)return false;
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
    archivo = fopen(ARCHIVO_MATERIAS,"rb+");
    if(archivo == NULL)return false;
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
    archivo = fopen(ARCHIVO_MATERIAS,"rb");
    if(archivo == NULL)return false;
    while(fread(&dto_archivo,sizeof(clsMateriaDTO),1,archivo))
    {
        if(!dto_archivo.GetEliminado())
        {
            dto[pos++].Copy(dto_archivo);
        }
    }
    fclose(archivo);
}

int clsMateriaDAO::Count()
{
    FILE *archivo;
    int cantidad = 0;
    archivo = fopen(ARCHIVO_MATERIAS,"rb");
    if(archivo == NULL)return -1;

    //Cuenta la cantidad de registros sin eliminar.
    return 0;
}
