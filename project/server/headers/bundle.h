/* 
 * File:   bundle.h
 * Author: svirch_n
 *
 * Created on 02 July 2014, 16:11
 */

#ifndef BUNDLE_H
# define	BUNDLE_H

# include       "serveur.h"

typedef struct  s_bundle
{
  t_serveur     *serveur;
  t_player      *player;
}               t_bundle;

#endif	/* BUNDLE_H */

