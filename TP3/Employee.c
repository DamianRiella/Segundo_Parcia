Employee* employee_new()
{
    Employee* empleado = (Employee*)malloc(sizeof(Employee));
    return empleado;
}
/**************************************************************/

Employee* employee_newParametros(Employee* this, char* idStr,char* nombreStr,char* horasTrabajadasStr, float* sueldo)
{
    int id, horas, sueldo;

    id= atoi(idStr);
    horas= atoi(horasTrabajadasStr);
    sueldo= atoi(sueldo);

    employee_setId(Employee* this,int idStr);
    employee_setNombre(Employee* this,char* nombreStr);
    employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
    employee_setSueldo(Employee* this,int sueldo);
}



