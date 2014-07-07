#!/usr/bin/env python3
print("running ./client.py ...")

import argparse

from client import Client

def parse_arguments():
    parser = argparse.ArgumentParser(conflict_handler='resolve')
    parser.add_argument('-n', '--team', help='the name of the drone team', required=True)
    parser.add_argument('-h', '--hostname', help='the server address or name', default='localhost')
    parser.add_argument('-p', '--port', help='the port used by the server', type=int, default=4242)
    parser.add_argument('-v', '--verbose', help='increase output verbosity', action='store_true')
    return parser.parse_args()

def main():
    args = parse_arguments()

    if args.verbose:
        print('Server = {0}:{1}'.format(args.hostname, args.port))
        print('Team name =', args.team)
        print('Verbose =', args.verbose)

    client = Client(args.team, args.hostname, args.port, args.verbose)
    if client.connect():
        client.run()

if __name__ == '__main__':
    main()
    pass
