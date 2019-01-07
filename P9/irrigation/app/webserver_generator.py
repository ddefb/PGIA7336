import sys
import re
# from Client import *

file = open(sys.argv[1],'r')

fileName = file.name[:-4]

tipos = ['int', 'bool']
tiposEspecias = {}

def numBits(numero):
  if numero > 2:
    resto  = numero % 2
    if resto == 0:
      r = numero/2
      return r
    else:
      r = (numero/2) + 1
      return r
  else:
    return 1

def startWithNode(line):
  if line[0:4] == 'node':
    return True
  else:
    return False

def searchForTypes(line):

  if line[0:4] == 'type':
    line = line.split(' ')
    tipoName = line[1]
    tipoTipos = line[-1].split('|')
    tipos.append(tipoName)
    tiposEspecias[tipoName] = numBits(len(tipoTipos))
    
lines = file.readlines()
list(map(searchForTypes, lines))
lines = filter(startWithNode, lines)

automatonsList = []

def lineToAutomaton(line):
  line = line[5:-1]
  line = line.split("returns")
  
  name = line[0].split('(')[0]
  print (name)
  
  entradas = line[0].split('(')[1]
  entradas = entradas[0:-2]
  entradas = entradas.split(":")[0]
  entradas = entradas.split(",")
  print (entradas)
  def tirarEspacos(x):
    return x.strip()
  entradas = list(map(tirarEspacos,entradas))
  saidas = line[1].strip()[1:-1]
  print (saidas)

  
  def subst(x):
    
    if ('int' in x):
      x = re.sub('\:.*','',x)
      return x  
      
    elif ('bool' in x):
      x = re.sub('\:.*','',x)
      return x
    
    else:

      name = x.split(':')
      multiplicador = tiposEspecias[name[1].strip()]
      x = ''
      for i in range(1, multiplicador+1):
        x += name[0].strip()+'_'+str(i)+','
        print x

      return x[0:-1]
  
  saidas = saidas.split(';')
  saidas = map(subst, saidas)
  
  if ('' in saidas):
    saidas.remove('')
  
  saidas = ','.join(saidas)
  
  saidas = saidas.split(",")
  print (saidas)
  print("----------")

  automaton = {'name':name,'entradas': entradas,'saidas':saidas}

  automatonsList.append(automaton)

list(map(lineToAutomaton,lines))

task = automatonsList[-1]

constFunc = fileName[0].upper()+fileName[1:]+"__"+task['name'] 

mem = constFunc+"_mem mem;"
out = constFunc+"_out _res;"
step = constFunc+"_step("
reset = constFunc+"_reset(&mem);"

declaracoes ="int step_c;int step_max;"

def concateDec(x):
  global declaracoes
  declaracoes = declaracoes+"int %s;"%(x)


list(map(concateDec,task['entradas']))

ifs = ""


def concateIf(x):
  global ifs
  ifs += 'if (strcmp(dict[i].key, "%s") == 0){ %s= atoi(dict[i].value);} else '%(x,x)

list(map(concateIf,task['entradas']))


def concateStep(x):
  global step
  step += '%s,'%(x)

list(map(concateStep,task['entradas']))


resposta='strcat(json, "{");'

def concateRes(x):
  global resposta
  string1 = 'strcat(json, ", \''+x
  string2 = '\':");' 
  resposta+= string1+string2+'sprintf(aux, "%d", _res.'+x+');strcat(json, aux);'
  
list(map(concateRes,task['saidas']))

resposta+='strcat(json, "}");'

part1 = '''

#include <sys/types.h>
#ifndef _WIN32
#include <sys/select.h>
#include <sys/socket.h>
#else
#include <winsock2.h>
#endif
#include <string.h>
#include <microhttpd.h>
#include <stdio.h>
#include <stdlib.h>
#include "_main.h"

#define PORT 8082
#define n 57

%s
int glob_cnt=0;


struct item
{
    const char *key;
    const char *value;
};


struct item dict[n];

int save_items (void *cls, enum MHD_ValueKind kind, 
                   const char *key, const char *value)
{
  dict[glob_cnt].key = key; 
  dict[glob_cnt].value = value;
  glob_cnt += 1;
  return MHD_YES;
}
'''%(mem)

part2 = '''
static int
answer_to_connection (void *cls, struct MHD_Connection *connection,
                      const char *url, const char *method,
                      const char *version, const char *upload_data,
                      size_t *upload_data_size, void **con_cls)
{
  char *json = malloc( 10000 );
  struct MHD_Response *response;
  int ret;
  MHD_get_connection_values(connection, MHD_GET_ARGUMENT_KIND, &save_items, NULL);
  //printf("Counter:%d", glob_cnt);
  
  glob_cnt = 0; ''' + declaracoes + out

part3 = '''
  int i;
  for(i= 0; i < n; i++){
''' + ifs + '''
    {
      //printf("Not implemented %s", dict[i].key);
    }
  }
  
  for(i= 0; i < n; i++)
  {
    //printf("%s, %s",dict[i].key, dict[i].value);
  }  ''' + step + '''
  &_res, &mem);

  char aux[1];
  ''' + resposta +'''
  response =
  MHD_create_response_from_buffer (strlen (json), (void *) json, 
             MHD_RESPMEM_PERSISTENT);
  ret = MHD_queue_response (connection, MHD_HTTP_OK, response);
  MHD_destroy_response (response);

  return ret;
}

int main(int argc, char** argv) {
  
  struct MHD_Daemon *daemon;
  ''' + reset + '''
  int i;
  for(i= 0; i < n; i++)
  {
    dict[i].key = "";
    dict[i].value = "";
  }

  daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                             &answer_to_connection, NULL, MHD_OPTION_END);
  if (NULL == daemon)
    return 1;

  (void) getchar ();

  MHD_stop_daemon (daemon);
  return 0;
} '''

webservice = part1+part2+part3

file.close()

file2=open('webservices.c','w')
file2.write(webservice)
file2.close()

