#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char productos[20][30] = {"zapatos","balones","gorras","shorts","hoodies","medias"};
int elementosdefault = 6;
float precios[20] = {50.0,20.0,15.0,20.0,60.0,10.0};
int cantidades[20] = {19,25,8,40,5,10};

void Menu();

void limpiarconsola(){
  system("clear");
}

void EditarProducto(){
  limpiarconsola();
  char producto[30];
  int indice = -1;
  char nuevoproducto[30];
  float precio;
  int cantidad; 
  char conf;
  printf("Producto           Precio     Cantidad\n");
  for (int l = 0; l < elementosdefault; l++) {
      printf("%d. --%s--\t\t", l + 1, productos[l]);
      printf("%.2f\t", precios[l]);
      printf("    %d\t\t\n", cantidades[l]);
  }

  printf("\n\nIngrese el producto a editar\n");
  scanf("%s", producto);
  for (int j = 0; j < elementosdefault; j++) {
    if (strcmp(producto, productos[j]) == 0) {
      printf("Se encontro el producto\n");
      indice = j;
      printf("Quiere cambiar el producto? S/N\n");
      getchar(); 
      scanf("%c", &conf);
      
      if (tolower(conf) == 's') {
        printf("--Ingrese el producto nuevo:-- \n");
        scanf("%s", nuevoproducto);
        strcpy(productos[indice], nuevoproducto);
      }
      
      printf("Quiere cambiar el precio del producto? S/N\n");
      getchar(); 
      scanf("%c", &conf);

      if (tolower(conf) == 's') {
        printf("--Ingrese el precio del producto nuevo:-- \n");
        scanf("%f", &precio);
        precios[indice] = precio;
      }
      
      printf("Quiere cambiar la cantidad del producto? S/N\n");
      getchar(); 
      scanf("%c", &conf);

      if (tolower(conf) == 's') {
        printf("--Ingrese la cantidad del producto nuevo:-- \n");
        scanf("%d", &cantidad);
        cantidades[indice] = cantidad;
      }
      break;
    }
  }

  if (indice == -1) {
      printf("No se encontro el producto indicado\n");
  } else {
      printf("Se edito con exito\n");
  }

  printf("Presione cualquier tecla para continuar...\n");
  getchar();
  getchar(); 
  limpiarconsola();
  
}

void ImprimirInventario(){
  limpiarconsola();
  printf("Producto           Precio     Cantidad\n");
  for (int l = 0; l < elementosdefault; l++)
  {
    printf("%d. --%s--\t\t",l+1,productos[l]);
    printf("%.2f\t", precios[l]);
    printf("    %d\t\t\n", cantidades[l]);
  }
  printf("\n\nPresione enter para volver\n");
  getchar();
  getchar();
  limpiarconsola();
}

void IngresarProductos (){
  limpiarconsola();
  char a = 's';
  if (elementosdefault != 10){
    while(a == 's'){
      char nuevoproducto[30];
      float precio;
      int cantidad; 
      printf("\n\n\n\n--Ingrese el producto nuevo:-- \n");
      scanf("%s",nuevoproducto);
      for(int i=0; i < elementosdefault; i++){
        if(strcmp(nuevoproducto,productos[i])==0){
          printf("El producto ya existe\n");
          printf("Presione enter para volver\n");
          getchar();
          getchar();
          return;
          break;
        }
      }
      getchar();
      printf("--Ingrese el precio del producto nuevo:-- \n");
      scanf("%f",&precio);
      printf("--Ingrese la cantidad del producto nuevo:-- \n");
      scanf("%d",&cantidad);
      getchar();
      strcpy(productos[elementosdefault], nuevoproducto);
      precios[elementosdefault] = precio;
      cantidades[elementosdefault] = cantidad;
      elementosdefault++;
      printf("Desea ingresar mas productos? S/N\n");
      scanf("%c",&a);
      a = tolower(a);
      limpiarconsola();
    }
  }
  else{
    printf("El numero maximo de productos es 10\n\n");
  }
  limpiarconsola();
}

void EliminarProductos() {
  limpiarconsola();
  char productoAEliminar[30];
  printf("Ingrese el nombre del producto que desea eliminar:\n");
  scanf("%s", productoAEliminar);

  for (int i = 0; i < 10; i++) {
      if (strcmp(productos[i], productoAEliminar) == 0) {
        elementosdefault--;
        for (int j = i; j < 9; j++) {
          strcpy(productos[j], productos[j + 1]);
        }
        strcpy(productos[elementosdefault], ""); 
        printf("\nSe ellimino con exito\n\n");
        break; 
      }
  }
  ImprimirInventario();
} 

void Facturacion(){
  limpiarconsola();
  char producto[30], facturacionP[20][30], opcion = 's';
  int indice, cantidad=0, indicador = 0,facturacionC[20]; 
  float multiplicacion[20], acumulador = 0, facturacionPr[20];
  while(tolower(opcion) == 's'){
    printf("Producto           Precio     Cantidad\n");
    for (int l = 0; l < elementosdefault; l++)
    {
      printf("%d. --%s--\t\t",l+1,productos[l]);
      printf("%.2f\t", precios[l]);
      printf("    %d\t\t\n", cantidades[l]);
    }
    printf("Indifique el producto que quiere\n");
    scanf("%s", producto);
    getchar();

    for(int i = 0; i < elementosdefault; i++){
      indice = i;
      if(strcmp(producto, productos[i])==0){
        printf("El costo del producto es: %.2f, indique cuantas unidades quiere\n",precios[indice]);
        scanf("%d",&cantidad);
        getchar();
        break;
      }
      else{
        indice = -1;
      }
    }

    if(indice == -1){
      printf("el producto no existe, intentelo de nuevo\n");
    }
    else{
      if(cantidad > cantidades[indice]){
        printf("Supero la cantidad de articulos existentes\n");
      }
      else{
        strcpy(facturacionP[indicador], producto);
        facturacionPr[indicador] = precios[indice];
        facturacionC[indicador] = cantidad;
        multiplicacion[indicador] = precios[indice] * cantidad;
        acumulador = multiplicacion[indicador] + acumulador;
        cantidades[indice] = cantidades[indice]-cantidad;
        indicador++;
      }
    }
    printf("Desea ingresar mas productos? S/N\n");
    scanf("%c",&opcion);
    limpiarconsola();
  }
  

  printf("\n                   Factura Marathon Sports\n");
  printf("\nUsuario: Profe de Progra          correo:carlos.guaita@udla.edu.ec\n");
  printf("\nUsted compro los siguientes productos:\n");
  printf("Descripcion              Valor            Cantidad         Valor\n");
  for (int k = 0; k < elementosdefault;k++){
    if (multiplicacion[k] >= 1){
      printf("\n%s                   %.2f               %d            %.2f \n",facturacionP[k],facturacionPr[k],facturacionC[k],multiplicacion[k]);   
    }
  }

  printf("--------------------------------------------------------------------");
  printf("\nSub total es: %.2f\n",acumulador);
  printf("--------------------------------------------------------------------");
  printf("\nIva fue del: %.2f\n",acumulador*0.15);
  printf("--------------------------------------------------------------------");
  printf("\nTotal de tu factura es: %.2f\n",acumulador+acumulador*0.15);
  printf("Presione enter para volver");
  getchar();
  getchar();
  limpiarconsola();
  }

void Opciones (int a){
  switch(a){
    case 1:
      IngresarProductos();
      Menu();
    break;
    case 2:
      EliminarProductos();
      Menu();
    break;
    case 3:
      EditarProducto();
      Menu();
    case 4:
      ImprimirInventario();
      Menu();
    break;
    case 5:
      Facturacion();
      Menu();
    break;
    case 6:
      printf("Gracias por usar el portal");
    break;
    default:
      limpiarconsola();
      printf("\n\nLa opcion marcada no esta en el menu\n\n\n");
      Menu();
    break;
  }
}

void Menu(){
  int opcion;
  printf("--- BIENVENIDO A MARATHON SPORTS ---\n\n");
  printf("    1. -Ingresar productos-\n\n");  
  printf("    2. -Eliminar productos-\n\n");
  printf("    3. -Editar productos-\n\n"); 
  printf("    4. -Mostrar inventario-\n\n");
  printf("        5. Facturacion\n\n");
  printf("          6. Salir\n\n");
  printf("    ----INGRESE LA OPCION----\n");
  scanf("%d",&opcion);
  Opciones(opcion);
}
