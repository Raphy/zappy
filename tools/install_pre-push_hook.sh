#!/bin/sh

ROOT_PATH="`dirname $0`"

cp "$ROOT_PATH/pre-push" "$ROOT_PATH/../.git/hooks/"
