/* 
 * File:   INetworkEventHandler.hh
 * Author: marie
 *
 * Created on July 4, 2014, 3:53 PM
 */

#ifndef	    INETWORKEVENTHANDLER_HH
# define    INETWORKEVENTHANDLER_HH

# include   "World.hh"

class	    INetworkEventHandler
{
public:
    virtual ~INetworkEventHandler() {}

    virtual bool    handlerRelay(t_data * data) = 0;
};

#endif	/* INETWORKEVENTHANDLER_HH */

