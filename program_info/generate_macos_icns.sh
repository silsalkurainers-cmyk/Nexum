#!/usr/bin/env bash
set -euo pipefail

source_svg="$1"
output_icns="$2"
iconset_dir="${output_icns%.icns}.iconset"

mkdir -p "$iconset_dir"
for size in 16 32 64 128 256 512; do
    "$RSVG_CONVERT" --width "$size" --height "$size" "$source_svg" > "$iconset_dir/icon_${size}x${size}.png"
    double_size=$((size * 2))
    "$RSVG_CONVERT" --width "$double_size" --height "$double_size" "$source_svg" > "$iconset_dir/icon_${size}x${size}@2x.png"
done

"$ICONUTIL" -c icns "$iconset_dir" -o "$output_icns"
