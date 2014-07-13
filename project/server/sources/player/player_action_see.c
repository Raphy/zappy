/*
** player_action_see.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 17:45:20 2014 damien sauvalle
** Last update Wed Jul  9 15:29:37 2014 damien sauvalle
*/

#include "list.h"
#include "server.h"
#include	"player.h"
#include "bundle.h"
#include "zappy.h"

static inline char to_binary_mask(t_case *current)
{
    char ret;
            
    ret = 0;
    if (list_length(&current->players) > 0)
        ret |= 1;
    if (current->inventory.food > 0)
        ret |= 2;
    if (current->inventory.linemate > 0)
        ret |= 4;
    if (current->inventory.deraumere > 0)
        ret |= 8;
    if (current->inventory.sibur > 0)
        ret |= 16;
    if (current->inventory.mendiane > 0)
        ret |= 32;
    if (current->inventory.phiras > 0)
        ret |= 64;
    if (current->inventory.thystame > 0)
        ret |= 128;
    printf("Server de merde: %x\n", (unsigned int)ret);
    return ret;
}

static void get_position(t_position *pos, int (*it)[3],
        t_player *player, t_arg *max_map)
{
    int or[4];
    
    or[0] = -1;
    or[1] = 1;
    or[2] = 1;
    or[3] = -1;
    if (player->direction == ORIENTATION_NORTH
            || player->direction == ORIENTATION_SOUTH)
    {
        (*pos).x = TO_MAP(player->x +\
                or[player->direction - 1] * ((*it)[1] + (*it)[2]), max_map->x_world);
        (*pos).y = TO_MAP(player->y +\
                or[player->direction - 1] * (*it)[1], max_map->y_world);
    }
    else
    {
        (*pos).x = TO_MAP(player->x +\
                or[player->direction - 1] * (*it)[1], max_map->x_world);
        (*pos).y = TO_MAP(player->y -\
                or[player->direction - 1] * ((*it)[1] + (*it[2])), max_map->y_world);
    }
}

static int fill_tab(char (*items)[81], t_player *player, t_server *server)
{
    int it[3];
    t_position pos;
    
    it[0] = 0;
    it[1] = -1;
    while (++it[1] < player->level)
    {
        it[2] = -1;
        while (++it[2] < it[1] * 2 + 1)
        {
            if (player->direction == ORIENTATION_UNKNOWN)
                return (RET_FAILURE);
            else
              get_position(&pos, &it, player, server->arg);
            (*items)[it[0]++] = to_binary_mask(&(server->map[pos.y][pos.x]));
        }
    }
    return (RET_SUCCESS);
}

/*
 * or = { North, East, South, West }
 */

void	player_action_see(t_zc *zc, void *data)
{
    char items[81];
    
    if (RET_FAILURE == fill_tab(&items, ((t_bundle *)data)->player,
            ((t_bundle *)data)->server))
        zs_send_ko(((t_bundle *)data)->server->zs, zc);
    else
    {
        int value = 0;
        int i = 0;
        while (i <= ((t_bundle *)data)->player->level)
        {
            value += i * 2 + 1;
            i++;
        }
        printf("Server: ");
        int x = 0;
        while (x < value)
            printf("%x ", (unsigned int)items[x++]);
        printf("value: %d\n", value);
        zs_send_look(((t_bundle *)data)->server->zs, zc, &items, value);
    }
}