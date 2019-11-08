#include "clsMxA_DAO.h"
#include <cstdio>

bool clsMxA_DAO::Insertar(clsMxA_DTO dto)
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_MXA,"ab");
    if(archivo == NULL)
        return false;
    fwrite(&dto,sizeof(clsMxA_DTO),1,archivo);
    fclose(archivo);
    return true;
}

bool clsMxA_DAO::Eliminar(int ID)
{
    //TODO Modificar para que funcione con clsMxA
    FILE *archivo;
    int pos = 0;
    clsMxA_DTO dto;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb+");
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

bool clsMxA_DAO::Modificar(clsMateriaDTO dto)
{
    //TODO Modificar para que funcione con clsMxA
    FILE *archivo;
    int pos = 0;
    clsMateriaDTO dto_archivo;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb+");
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

bool clsMxA_DAO::Listar(clsMateriaDTO *dto)
{
    //TODO Modificar para que funcione con clsMxA
    FILE *archivo;
    int pos = 0;
    clsMateriaDTO dto_archivo;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb");
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

int clsMxA_DAO::Count()
{
    //TODO Modificar para que funcione con clsMxA
    FILE *archivo;
    int cantidad = 0;
    clsMateriaDTO dto;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb");
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

int clsMxA_DAO::GeneradorDeID()
{
    //TODO Modificar para que funcione con clsMxA
    FILE *archivo;
    int cantidad = 0;
    clsMateriaDTO dto;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb");
    if(archivo == NULL)
        return 0;
    while(fread(&dto,sizeof(clsMateriaDTO),1,archivo))
    {
        cantidad++;
    }
    fclose(archivo);
    return cantidad;
}

void clsMxA_DAO::CrearArchivoMxASiNoExiste()
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_MXA,"ab");
    fclose(archivo);
}