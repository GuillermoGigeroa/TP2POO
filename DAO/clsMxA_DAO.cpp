#include "clsMxA_DAO.h"
#include <cstdio>
#include <cstdlib>

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

bool clsMxA_DAO::CargarVectorDinamico(clsMxA_DTO *listaDto)
{
    CrearArchivoMxASiNoExiste();
    FILE *archivo;
    archivo = fopen(ARCHIVO_MXA,"rb");
    if(archivo == NULL)return false;
    for (int x = 0; x < Count(); x++)
    {
        fread(&listaDto[x],sizeof(clsMxA_DTO),1,archivo);
    }
    fclose(archivo);
    return true;
}

bool clsMxA_DAO::GuardarEnDisco(clsMxA_DTO *listaDto)
{
    CrearArchivoMxASiNoExiste();
    FILE *archivo;
    archivo = fopen(ARCHIVO_MXA,"rb+");
    if(archivo==NULL)return false;
    fseek(archivo,0,SEEK_SET);
    for(int x = 0; x < Count(); x++)
    {
        fwrite(&listaDto[x],sizeof(clsMxA_DTO),1,archivo);
    }
    fclose(archivo);
    return true;
}

bool clsMxA_DAO::EliminarPorLegajo(int Legajo)
{
    bool salioTodoBien = false;
    CrearArchivoMxASiNoExiste();
    clsMxA_DTO *listaDto;
    listaDto = (clsMxA_DTO *)malloc(sizeof(clsMxA_DTO)*Count());
    if(CargarVectorDinamico(listaDto))
    {
        for(int x = 0; x < Count(); x++)
        {
            if(listaDto[x].GetLegajo() == Legajo)
            {
                listaDto[x].SetEliminado(true);
            }
        }
        if(GuardarEnDisco(listaDto))
        {
            salioTodoBien = true;
        }
    }
    free(listaDto);
    return salioTodoBien;
}

bool clsMxA_DAO::EliminarPorIdMateria(int ID)
{
    bool salioTodoBien = false;
    CrearArchivoMxASiNoExiste();
    clsMxA_DTO *listaDto;
    listaDto = (clsMxA_DTO *)malloc(sizeof(clsMxA_DTO)*Count());
    if(CargarVectorDinamico(listaDto))
    {
        for(int x = 0; x < Count(); x++)
        {
            if(listaDto[x].GetID_Materia() == ID)
            {
                listaDto[x].SetEliminado(true);
            }
        }
        if(GuardarEnDisco(listaDto))
        {
            salioTodoBien = true;
        }
    }
    free(listaDto);
    return salioTodoBien;
}

bool clsMxA_DAO::EliminarAlumnoDeMateria(int ID, int Legajo)
{
    bool seEncontro = false;
    bool seGuardo = false;
    CrearArchivoMxASiNoExiste();
    clsMxA_DTO *listaDto;
    listaDto = (clsMxA_DTO *)malloc(sizeof(clsMxA_DTO)*Count());
    if(CargarVectorDinamico(listaDto))
    {
        for(int x = 0; x < Count(); x++)
        {
            if(listaDto[x].GetLegajo() == Legajo && listaDto[x].GetID_Materia() == ID)
            {
                listaDto[x].SetEliminado(true);
                seEncontro = true;
            }
        }
        if(GuardarEnDisco(listaDto))
        {
            seGuardo = true;
        }
    }
    free(listaDto);
    if(seEncontro && seGuardo)
    {
        return true;
    }
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


void clsMxA_DAO::CrearArchivoMxASiNoExiste()
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_MXA,"ab");
    fclose(archivo);
}
