#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int userArr[]={1,2,3,4,5,6,7,8,9,10};
int passArr[]={111, 112, 113, 114, 115, 116, 117, 118, 119, 110};
float money[]= {20000, 30000, 40000, 50000, 25000, 35000, 45000, 55000, 25000, 40000};
int status[]= {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
char name[][25] ={"Juan", "Ana", "Brian", "Anabella", "Peter", "Juliana", "Roman", "claudia", "Adalberto", "Sandra"};
int user;

bool userValid( int userIn, int pass);
float deposit();
float howMoney();
float extract();

int main() 
{
    int pass;
    int userIn = 0;
    int valUser;
    int numUser;
    bool valid;
    int elec;
    int mov=10;                                   

    do                                              //do-while para que siempre esté operando el cajero.
    {
        printf("*** Bienvenido a Cajeros Saturno *** \n\n");
        do                                         // do-while para los 3 intentos.
        {
            printf("Ingrese su n%cmero de cuenta: \n", 163);
            scanf("%i",  &userIn);
            printf("Ingrese su contrase%ca: \n", 164);
            scanf("%i", &pass);
            valid = userValid(userIn,pass);         //Se valida usuario y contraseña. si es valido entra en el menu, sino va a elseif o else.

                if(valid)
                {
                    mov = 10;                     //cantidad de movimientos que se pueden realizar en un ingreso. reinicia la cant al salir de una cuenta.
                    printf("\n Le damos la bienvenida %s.\n", name[user]);
                    do
                    {
                        printf("\n %cQu%c operaci%cn desea realizar? \n  1 - Dep%csito.  \n  2 - Extracci%cn.  \n  3 - Consultar Saldo. \n  4 - mostrar la cantidad de operaciones realizadas y el saldo actual.\n  5 - Salir. \n\n",168, 130, 162, 162, 162);
                        scanf("%i", &elec);

                        switch (elec)
                        {
                        case 1:
                            deposit();
                            mov--;
                            break;
                        case 2:
                            extract();
                            mov--;
                            break;
                        case 3:
                            howMoney();
                            mov--;
                            break;
                        case 4:
                            howMoney();
                            printf("Usted ha realizado %i movimientos.\n", 10 - mov);
                            break;
                        case 5:
                            
                            break;
                        default:
                            printf("La opcion ingresada no es valida.\n");
                            break;
                        }

                    } while(mov > 0 && elec != 5);
                } 
                else if(status[user] == 0)
                {
                    printf("\nSu cuenta se encuentra bloqueada, comuniquese con la entidad bancaria para su restablecimiento. \n\n");                   
                }
                else
                {
                    printf("\nN%cmero de cuenta o contrase%ca incorrecta. Por favor ingreselo nuevamente. \n\n", 163, 164);
                }  
            if (mov == 0)
            {
                printf("\nLleg%c al l%cmite de operaciones. Fin. Gracias!\n\n", 162, 161);
            }
            
        } while (!valid && status[user] != 0);
        
        for (int i=0; i<10; i++)
        {
            if (status[i]>0)
            {
                status[i]=3;
            }
        }

    } while ( 1 == 1);

    system("pause");
    return 0;
    
}

bool userValid( int userIn, int pass)            //valída si el cliente existe
{
    int i;
    bool val, x;
    val = false;
    x = false;

    for (i = 0; i < 10; i++)
        {
            if (userIn == userArr[i])
            {
                x = true;   
                user = i;                        //variable global de tipo int para saber que num de usuario esta operando 
                break;                               
            }           
        }

        if(x = true && status[user] > 0 )
        {
            if (pass == passArr[user])
            {
                val = true;
            }
            else
            {
                status[user]--; 
            }
        } 
        
return val;                                    //val siempre es FALSE excepto que entre en el if, es decir cuenta y contraseña coincidan. En ese caso val cambia a TRUE.
};

float deposit()                                //Función para realizar depositos.
{
    float moneyIn;
    printf("\nIngrese el monto que desea depositar.\n");
    scanf("%f", &moneyIn);
    money[user] = money[user] + moneyIn;
    printf("\nSu dinero se deposit%c correctamente.\n", 162);
}

float extract()                                 //Función para realizar extracciones.
{
    float moneyOut;
    printf("\n Ingrese el monto que desea retirar.\n");
    scanf("%f", &moneyOut);

    if (money[user]>= moneyOut)
    {
        money[user] = money[user] - moneyOut;
        printf("\nTransacci%cn aprobada, retire su dinero.\n", 162);
    }
    else
    {
        printf("\nEl monto que desea retirar es mayor al saldo actual.\n");
    }
    

}

float howMoney()                                //Función para conocer el saldo actual de la cuenta.
{
    printf("\nEl saldo actual de su cuenta es de: $ %.2f \n",money[user]);
}