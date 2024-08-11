#!/usr/bin/env bash
set -euo pipefail

jq -M -c .[1] <&0 | emojitsu emojify