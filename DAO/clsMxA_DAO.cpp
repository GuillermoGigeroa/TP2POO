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

bool clsMxA_DAO::Eliminar(int ID_Materia, int Legajo)
{
    FILE *archivo;
    int pos = 0;
    clsMxA_DTO dto;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb+");
    if(archivo == NULL)
        return false;
    while(fread(&dto,sizeof(clsMxA_DTO),1,archivo))
    {
        if(dto.GetID_Materia()==ID_Materia && dto.GetLegajo()==Legajo && !dto.GetEliminado())
        {
            dto.SetEliminado(true);
            fseek(archivo,sizeof(clsMxA_DTO)*pos,SEEK_SET);
            fwrite(&dto,sizeof(clsMxA_DTO),1,archivo);
            fclose(archivo);
            return true;
        }
        pos++;
    }
    fclose(archivo);
    return false;
}

bool clsMxA_DAO::Modificar(clsMxA_DTO dto)
{
    FILE *archivo;
    int pos = 0;
    clsMxA_DTO dto_archivo;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb+");
    if(archivo == NULL)
        return false;
    while(fread(&dto_archivo,sizeof(clsMxA_DTO),1,archivo))
    {
        if(dto_archivo.GetID_Materia()==dto.GetID_Materia() && dto_archivo.GetLegajo()==dto.GetLegajo() && !dto.GetEliminado())
        {
            fseek(archivo,sizeof(clsMxA_DTO)*pos,SEEK_SET);
            fwrite(&dto,sizeof(clsMxA_DTO),1,archivo);
            fclose(archivo);
            return true;
        }
        pos++;
    }
    fclose(archivo);
    return false;
}

bool clsMxA_DAO::Listar(clsMxA_DTO *dto)
{
    FILE *archivo;
    int pos = 0;
    clsMxA_DTO dto_archivo;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb");
    if(archivo == NULL)
        return false;
    while(fread(&dto_archivo,sizeof(clsMxA_DTO),1,archivo))
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
    FILE *archivo;
    int cantidad = 0;
    clsMxA_DTO dto;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb");
    if(archivo == NULL)
        return 0;
    while(fread(&dto,sizeof(clsMxA_DTO),1,archivo))
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
    FILE *archivo;
    int cantidad = 0;
    clsMxA_DTO dto;
    CrearArchivoMxASiNoExiste();
    archivo = fopen(ARCHIVO_MXA,"rb");
    if(archivo == NULL)
        return 0;
    while(fread(&dto,sizeof(clsMxA_DTO),1,archivo))
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
