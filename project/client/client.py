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
    parser = argparse.ArgumentParser()
    parser.add_argument('team_name', help='the name of the drone team')
    parser.add_argument('-a', '--address', help='the server address or name', default='localhost')
    parser.add_argument('-p', '--port', help='the port used by the server', type=int, default=4242)
    parser.add_argument('-v', '--verbose', help='increase output verbosity', action='store_true')
    return parser.parse_args()

def main():
    args = parse_arguments()

    hostname = args.address
    port = args.port
    team_name = args.team_name
    verbose = args.verbose

    print('Connecting on {0}:{1}'.format(hostname, port))
    print('Team name =', team_name)
    print('Verbose =', verbose)

    nw = client.network.Network()
    nw.connect(hostname, port)
    nw.hook_connected(connected_callback, (team_name, nw))
    nw.hook_disconnected(disconnected_callback, None)
    nw.run()

if __name__ == '__main__':
    main()
