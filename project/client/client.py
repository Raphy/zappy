#!/usr/bin/env python3
print("running ./client.py ...")

import argparse
import client

def connected_callback(data):
    print('client connected')
    team_name, nw = data
    nw.send_team_name(team_name)

def disconnected_callback(data):
    print('client disconnected')

def parse_arguments():
    parser = argparse.ArgumentParser(conflict_handler='resolve')
    parser.add_argument('-n', '--team', help='the name of the drone team', required=True)
    parser.add_argument('-h', '--hostname', help='the server address or name', default='localhost')
    parser.add_argument('-p', '--port', help='the port used by the server', type=int, default=4242)
    parser.add_argument('-v', '--verbose', help='increase output verbosity', action='store_true')
    return parser.parse_args()

def main():
    args = parse_arguments()

    print('Connecting on {0}:{1}'.format(args.hostname, args.port))
    print('Team name =', args.team)
    print('Verbose =', args.verbose)

    nw = client.network.Network()
    nw.hook_connected(connected_callback, (args.team, nw))
    nw.hook_disconnected(disconnected_callback, None)
    nw.connect(args.hostname, args.port)
    nw.run()

if __name__ == '__main__':
    main()
    pass
