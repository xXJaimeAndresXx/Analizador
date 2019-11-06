#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <fstream>
#include <iostream>
#include <QFileDialog>
#include <QtGui>
#include <QtCore>

using namespace std;

static int matriz[18][26]={
                    {1,1,3,506,16,6,8,15,11,506,12,13,14,112,113,117,118,119,120,121,124,17,0,0,0,506},
                    {1,1,1,2,100,100,100,100,100,100,100,100,100,100,2,100,100,100,100,100,100,100,100,100,100,100},
                    {1,1,1,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501},
                    {101,101,3,101,4,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,501},
                    {500,500,5,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500},
                    {102,102,5,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102},
                    {6,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
                    {100,103,103,103,103,6,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103},
                    {116,116,116,116,116,116,116,9,116,116,116,116,116,116,116,116,116,116,116,116,116,116,116,116,116,116},
                    {9,9,9,9,9,9,9,10,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                    {502,502,502,502,502,502,104,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502},
                    {11,11,11,11,11,11,11,11,11,105,11,11,11,11,1,11,11,11,11,11,11,11,11,11,11,11},
                    {503,503,503,503,503,503,503,503,503,503,106,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503},
                    {107,107,107,107,107,107,107,107,107,107,109,107,108,107,107,107,107,107,107,107,107,107,107,107,107,107},
                    {110,110,110,110,110,110,110,110,110,110,11,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110},
                    {114,114,114,114,114,114,114,115,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114},
                    {122,122,122,122,123,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122},
                    {125,125,125,125,125,125,125,125,125,125,126,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125}
                     };
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Token->setReadOnly(true);
    ui->Error->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString iden;
QString Tokens;
QString textoA;
QString texto;
void Token(int e){



    switch(e){
    case 100:

        Tokens+=textoA+" "+iden+"\n";
        break;
    case 101:

        Tokens+=textoA+" Numeros enteros\n";
        break;
    case 102:

        Tokens+=textoA+" Numeros Reales\n";
        break;
    case 103:
        Tokens+=textoA+" letrero\n";
        break;
    case 104:
        Tokens+=textoA+" Comentario\n";
        break;
    case 105:

        Tokens+=textoA+" Comentarios\n";
        break;
    case 106:

        Tokens+=textoA+" Igualdades\n";
        break;
    case 107:

        Tokens+=textoA+" Menor\n";
        break;
    case 108:

        Tokens+=textoA+" Diferente\n";
        break;
    case 109:

        Tokens+=textoA+" Menor Igual\n";
        break;
    case 110:

        Tokens+=textoA+" Mayor\n";
        break;
    case 111:

        Tokens+=textoA+" Mayor igual\n";
        break;
    case 112:

        Tokens+=textoA+" Suma\n";
        break;
    case 113:

        Tokens+=textoA+" Resta\n";
        break;
    case 114:

        Tokens+=textoA+" Multiplicacion\n";
        break;
    case 115:

        Tokens+=textoA+" PorPor\n";
        break;
    case 116:

        Tokens+=textoA+" division\n";
        break;
    case 117:

        Tokens+=textoA+" parentesis que abre\n";
        break;
    case 118:

        Tokens+=textoA+" parentesis que cierra\n";
        break;
    case 119:

        Tokens+=textoA+" corchete que abre\n";
        break;
    case 120:

        Tokens+=textoA+" corchete que cierra\n";
        break;
    case 121:

        Tokens+=textoA+" coma\n";
        break;
    case 122:

        Tokens+=textoA+" Punto\n";
        break;
    case 123:

        Tokens+=textoA+" punto y punto\n";
        break;
    case 124:
        Tokens+=textoA+" punto y coma\n";
        break;
    case 125:

        Tokens+=textoA+" dos puntos\n";
        break;
    case 126:

        Tokens+=textoA+" asignacion\n";
        break;
    case 127:

        Tokens+=textoA+" \n";
        break;

    }

}
QString errores;
void Errores(int e){
    switch(e){
    case 500:

        errores+=textoA+" Real Mal Formado\n";
        break;
    case 501:

        errores+=textoA+" identificador mal formado\n";
        break;
    case 502:

        errores+=textoA+" Comentario mal formado\n";
        break;
    case 503:

        errores+=textoA+" operacion mal formada\n";
        break;
    case 504:
        errores+=textoA+" Error debe de escribir un numero para completar la expresion\n";
        break;
    case 505:
        errores+=textoA+" Error debe escribir un caracter entre las '\n";
        break;
    case 506:
        errores+=textoA+" Error lexico '\n";
        break;

    }

}

bool evaluaPR(){

    int conta=0;
    std::string cadenaStd = textoA.toStdString();
    for(int i=0;i<textoA.length();i++){
        char car=cadenaStd[i];
        if(car=='\n' || car=='\t' || car==32)
            conta++;
    }
    QString temp=textoA.mid(conta,textoA.length());
    if((textoA=="Array" || temp=="Array") || (textoA=="ARRAY" || temp=="ARRAY") || (textoA=="array" || temp=="array") ||
       (textoA=="BEGIN" || temp=="BEGIN") || (textoA=="begin" || temp=="begin") || (textoA=="Begin" || temp=="Begin") ||
       (textoA=="CASE" || temp=="CASE") || (textoA=="Case" || temp=="Case") || (textoA=="case" || temp=="case") ||
       (textoA=="Const" || temp=="Const") || (textoA=="const" || temp=="const") || (textoA=="CONST" || temp=="CONST") ||
       (textoA=="DO" || temp=="DO") || (textoA=="Do" || temp=="Do") || (textoA=="do" || temp=="do") ||
       (textoA=="ELSE" || temp=="ELSE") || (textoA=="Else" || temp=="Else") || (textoA=="else" || temp=="else") ||
       (textoA=="WRITELN" || temp=="WRITELN") || (textoA=="Writeln" || temp=="Writeln") || (textoA=="writeln" || temp=="writeln") ||
       (textoA=="Readln" || temp=="Readln") || (textoA=="READLN" || temp=="READLN") || (textoA=="readln" || temp=="readln") ||
       (textoA=="ElseIf" || temp=="ElseIf") || (textoA=="ELSEIF" || temp=="ELSEIF") || (textoA=="elseif" || temp=="elseif") ||
       (textoA=="end" || temp=="end") || (textoA=="End" || temp=="End") || (textoA=="END" || temp=="END") ||
       (textoA=="FOR" || temp=="FOR") || (textoA=="For" || temp=="For") || (textoA=="for" || temp=="for") ||
       (textoA=="if" || temp=="if") || (textoA=="IF" || temp=="IF") || (textoA=="If" || temp=="If") ||
       (textoA=="Loop" || temp=="Loop") || (textoA=="LOOP" || temp=="LOOP") || (textoA=="loop" || temp=="loop") ||
       (textoA=="MODULE" || temp=="MODULE") || (textoA=="Module" || temp=="Module") || (textoA=="modulo" || temp=="module") ||
       (textoA=="FUNCTION" || temp=="FUNCTION") || (textoA=="Function" || temp=="Function") || (textoA=="function" || temp=="function") ||
       (textoA=="EXIT" || temp=="EXIT") || (textoA=="Exit" || temp=="Exit") || (textoA=="exit" || temp=="exit") ||
       (textoA=="NOT" || temp=="NOT") || (textoA=="not" || temp=="not") || (textoA=="Not" || temp=="Not") ||
            (textoA=="Of" || temp=="Of") || (textoA=="OF" || temp=="OF") || (textoA=="of" || temp=="of") ||
            (textoA=="MOD" || temp=="MOD") || (textoA=="Mod" || temp=="Mod") || (textoA=="mod" || temp=="mod") ||
            (textoA=="record" || temp=="record") || (textoA=="RECORD" || temp=="RECORD") || (textoA=="Record" || temp=="Record") ||
            (textoA=="repeat" || temp=="repeat") || (textoA=="REPEAT" || temp=="REPEAT") || (textoA=="Repeat" || temp=="Repeat") ||
            (textoA=="return" || temp=="return") || (textoA=="RETURN" || temp=="RETURN") || (textoA=="Return" || temp=="Return") ||
            (textoA=="Procedure" || temp=="Procedre") || (textoA=="PROCEDURE" || temp=="PROCEDURE") || (textoA=="procedure" || temp=="procedure") ||
            (textoA=="BY" || temp=="BY") || (textoA=="By" || temp=="By") || (textoA=="by" || temp=="by") ||
            (textoA=="Then" || temp=="Then") || (textoA=="THEN" || temp=="THEN") || (textoA=="then" || temp=="then") ||
            (textoA=="TO" || temp=="TO") || (textoA=="To" || temp=="To") || (textoA=="to" || temp=="to") ||
            (textoA=="until" || temp=="until") || (textoA=="Until" || temp=="Until") || (textoA=="UNTIL" || temp=="UNTIL") ||
            (textoA=="VAR" || temp=="VAR") || (textoA=="Var" || temp=="Var") || (textoA=="var" || temp=="var") ||
            (textoA=="while" || temp=="while") || (textoA=="While" || temp=="While") || (textoA=="WHILE" || temp=="WHILE") ||
            (textoA=="with" || temp=="with") || (textoA=="With" || temp=="With") || (textoA=="WITH" || temp=="WITH") ||
            (textoA=="true" || temp=="true") || (textoA=="True" || temp=="True") || (textoA=="TRUE" || temp=="TRUE") ||
            (textoA=="FALSE" || temp=="FALSE") || (textoA=="false" || temp=="false") || (textoA=="False" || temp=="False") ||
            (textoA=="Div" || temp=="Div") || (textoA=="div" || temp=="div") || (textoA=="DIV" || temp=="DIV") ||
            (textoA=="INTEGER" || temp=="INTEGER") || (textoA=="Integer" || temp=="Integer") || (textoA=="integer" || temp=="integer") ||
            (textoA=="real" || temp=="real") || (textoA=="Real" || temp=="Real") || (textoA=="REAL" || temp=="REAL") ||
            (textoA=="Char" || temp=="Char") || (textoA=="CHAR" || temp=="CHAR") || (textoA=="char" || temp=="char") ||
            (textoA=="String" || temp=="String") || (textoA=="string" || temp=="string") || (textoA=="STRING" || temp=="STRING") ||
            (textoA=="BYTE" || temp=="BYTE") || (textoA=="Byte" || temp=="Byte") || (textoA=="byte" || temp=="byte") ||
            (textoA=="BOOLEAN" || temp=="BOOLEAN") || (textoA=="Boolean" || temp=="Boolean") || (textoA=="boolean" || temp=="boolean")){

        iden=" Palabra reservada";
        return true;
                }
    if((textoA=="AND" || temp=="AND") || (textoA=="OR" || temp=="OR") ||
       (textoA=="class" || temp=="class")){
        iden=" Operador Logico";
        return true;
                }
    iden=" Identificador";
    return false;
}
int Relaciona(char c){
   int valor;

   if(c>=48 && c<=57){
       return 2;
   }
   if(c>=65 && c<=90){
       return 1;
   }
   if(c>=97 && c<=122){
       return 0;
   }
   if(c==32 || c=='#' || c==39 || c=='$' || c=='&' || c=='%' || c==33 || c==92 || c==63|| c==126 || c==94 || c==96)
   {

       return 25;
   }


   switch(c){
   case '\t': valor=22;
       break;
   case '\n': valor=23;
       break;
   case '\b': valor=24;
       break;
   case ':': valor=21;
       break;


   case '<': valor=11;
       break;
   case '>': valor=12;
       break;
   case '+': valor=13;
       break;
   case '=': valor=10;
       break;
   case '-': valor=14;
       break;
   case '"': valor=5;
       break;
   case '[': valor=17;
       break;
   case ']': valor=18;
       break;
   case '(': valor=15;
       break;
   case ')': valor=16;
       break;
   case ';': valor=20;
       break;
   case ',': valor=19;
       break;
   case '_': valor=3;
       break;
   case '/': valor=6;
       break;
   case '*': valor=7;
       break;
   case '{': valor=8;
       break;
   case '}': valor=9;
       break;

   default:
       valor=4;

   }
   return valor;
}

void Analiza(QString cadena){
    std::string cadenaStd = cadena.toStdString();
    int edo=0,col;
    char car=cadenaStd[0];

    textoA="";

    int numero=1;
    while(edo<=25){

        col=Relaciona(car);

        edo=matriz[edo][col];


        if(edo==112)
            textoA.append('+');
        if(edo==113)
            textoA.append('-');
        if(edo==117)
            textoA.append('(');
        if(edo==118)
            textoA.append(')');
        if(edo==119)
            textoA.append('[');
        if(edo==120)
            textoA.append(']');
        if(edo==124)
            textoA.append(';');
        if(edo==121)
            textoA.append(',');

        if(edo<100 || edo>=500){
            textoA.append(car);

        }
        if(edo==0 && car=='\n')
        {

            edo=506;

        }
        if(edo==506 )
        {

            edo=506;

        }

        if(edo==123 && car==' ')
        {

            edo=123;

        }

        if(edo==123 && car!=' ' and car!='.')
        {
            textoA.append(car);
            edo=122;

        }



        if(edo==126 && car=='=')
        {
            textoA.append(car);
            edo=126;
        }
        if(edo==22 || edo==23 || edo==24)
        {
            textoA.append(car);
            edo=506;
        }


        if(edo==115 && car=='*')
        {
            textoA.append(car);
            edo=115;
        }
        if(edo==123 && car=='.')
        {
            textoA.append(car);
            edo=123;

        }
        if(edo==1 && car=='.')
        {

            edo=123;
        }


        if(edo==4 && car!='.')
        {
            textoA.append(car);
            edo=101;
        }
        if(edo==106 && car=='=')
        {
            textoA.append(car);
            edo=106;
        }
        if(edo==104 && car=='/')
        {
            textoA.append(car);
            edo=104;
        }

        if(edo==108 && car=='>')
        {
            textoA.append(car);
            edo=108;
        }
        if(edo==11 && car=='=')
        {

            edo=111;
        }
        if(edo==109 && car=='=')
        {
            textoA.append(car);
            edo=109;
        }


        if(edo==105 && car=='}'){
            textoA.append(car);
            edo=105;
        }


        if(edo==100){
          if(evaluaPR()==true){
                edo=100;
            }else if(evaluaPR()==false){
                edo=100;
                iden="Identificador";
            }

        }

        if(edo==101 && car=='.'){
            textoA.append('.');
            edo=22;
        }






        car=cadenaStd[numero];

        numero++;

    }



    int longitud=textoA.length();
    texto=texto.remove(0,longitud);
    if(textoA.at(0)==' '){
        textoA.remove(0,1);
    }

    if(edo>=100 && edo<=199){
        Token(edo);
    }else{
        Errores(edo);
    }


}

void MainWindow::on_pushButton_clicked()
{

    Tokens="";
    errores="";
    ui->Token->setPlainText("");
    ui->Error->setPlainText("");
    texto=ui->textoAnalizar->toPlainText();
    while(texto!=""){
    Analiza(texto);

    }
    ui->Token->appendPlainText(Tokens);
    ui->Error->appendPlainText(errores);


}




void MainWindow::on_pushButton_3_clicked()
{

    ui->Token->setPlainText("");
    ui->Error->setPlainText("");
}
