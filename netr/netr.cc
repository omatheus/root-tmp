
#define _GNU_SOURCE

#define APRESENTAR std::cout << \
				"NETR - Listar interfaces e suas propriedades" \
                             << std::endl << "Matheus H. Silva\n" << std::endl;


#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <linux/if_link.h>

  #include <iostream>


#define Sucesso (int)0;


//******************************************

namespace NetRSIS

{

  class NetRPrincipal

  {

  public:


   NetRPrincipal( );


  };

};

//******************************************

NetRSIS::NetRPrincipal::NetRPrincipal
( )

{

  struct ifaddrs *ifaddr, *ifa;


  int 
    family, 
    s, 
    n;


  char host[ NI_MAXHOST ];



  if 
    ( getifaddrs(&ifaddr) == -1 ) 

    {
     
      std::cout << "Houveram problemas durante esta execucao..." << std::endl;

    }

  else

    {

           APRESENTAR;


           for 
	     ( ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++ ) 
	     
	     {
               

	       
	       std::cout << ( n ) << ". " <<
 
		         "\n+-------------------------+\n" << std::endl;



	     if (ifa->ifa_addr == NULL)
                   continue;



               family = ifa->ifa_addr->sa_family;


               
	       std::cout <<
                     
		 ifa->ifa_name 
			 
			 << std::endl <<
                      
		 ( char * )

		  ( 

		  (family == AF_PACKET) ? "AF_PACKET" :
		       
                  (family == AF_INET) ? "AF_INET" :
		       
		  (family == AF_INET6) ? "AF_INET6" : "???" 

		  )
			 
			 << std::endl;



               if 
		 ( family == AF_INET || family == AF_INET6 ) 
		 
		 {
                   
		 s = getnameinfo
		                 ( ifa->ifa_addr,
                           
				 (family == AF_INET) ? 
				 
				 sizeof( struct sockaddr_in ) :
                                                 
				 sizeof( struct sockaddr_in6 ),
				 
				 host, NI_MAXHOST,
				 
				 NULL, 0, NI_NUMERICHOST);




		 if 
		 ( s != 0 ) 
		   
		   {
                      
		       std::cout << "Falha durante chamada de GET_NAME_INFO."
				 << std::endl;

		   }

		 else
		   
		   {

		     std::cout << "\taddr=" << host << std::endl;

		   }

 


           
    }
	     


	       std::cout << "\n+-------------------------+\n" << std::endl;

    }





	   freeifaddrs( ifaddr );

    }

}


//******************************************


int main
(void)

{


  NetRSIS::NetRPrincipal  *nto  = new  NetRSIS::NetRPrincipal( );
  delete nto;
  

  return Sucesso;
}
