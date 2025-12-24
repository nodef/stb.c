#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "stb" ]; then return; fi
URL="https://github.com/nothings/stb/archive/refs/heads/master.zip"
ZIP="${URL##*/}"
DIR="stb-master"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to stb/ ..."
rm -rf stb
mkdir -p stb
cp -rf ".build/$DIR"/*.h stb/
echo ""
}


# Test the project
test() {
echo "Running 01-stb_c_lexer.c ..."
clang -I. -o 01.exe examples/01-stb_c_lexer.c                 && ./01.exe && echo -e "\n"
echo "Running 02-stb_connected_components.c ..."
clang -I. -o 02.exe examples/02-stb_connected_components.c    && ./02.exe && echo -e "\n"
echo "Running 03-stb_divide.c ..."
clang -I. -o 03.exe examples/03-stb_divide.c                  && ./03.exe && echo -e "\n"
echo "Running 04-stb_ds.c ..."
clang -I. -o 04.exe examples/04-stb_ds.c                      && ./04.exe && echo -e "\n"
echo "Running 05-stb_dxt.c ..."
clang -I. -o 05.exe examples/05-stb_dxt.c                     && ./05.exe && echo -e "\n"
echo "Running 06-stb_easy_font.c ..."
clang -I. -o 06.exe examples/06-stb_easy_font.c               && ./06.exe && echo -e "\n"
# echo "Running 07-stb_herringbone_wang_tile.c ..."
# clang -I. -o 07.exe examples/07-stb_herringbone_wang_tile.c   && ./07.exe && echo -e "\n"
# echo "Running 08-stb_hexwave.c ..."
# clang -I. -o 08.exe examples/08-stb_hexwave.c                 && ./08.exe && echo -e "\n"
echo "Running 09-stb_image.c ..."
clang -I. -o 09.exe examples/09-stb_image.c                   && ./09.exe && echo -e "\n"
echo "Running 10-stb_image_resize2.c ..."
clang -I. -o 10.exe examples/10-stb_image_resize2.c           && ./10.exe && echo -e "\n"
echo "Running 11-stb_image_write.c ..."
clang -I. -o 11.exe examples/11-stb_image_write.c             && ./11.exe && echo -e "\n"
# echo "Running 12-stb_include.c ..."
# clang -I. -o 12.exe examples/12-stb_include.c                 && ./12.exe && echo -e "\n"
echo "Running 13-stb_leakcheck.c ..."
clang -I. -o 13.exe examples/13-stb_leakcheck.c               && ./13.exe && echo -e "\n"
echo "Running 14-stb_perlin.c ..."
clang -I. -o 14.exe examples/14-stb_perlin.c                  && ./14.exe && echo -e "\n"
echo "Running 15-stb_rect_pack.c ..."
clang -I. -o 15.exe examples/15-stb_rect_pack.c               && ./15.exe && echo -e "\n"
echo "Running 16-stb_sprintf.c ..."
clang -I. -o 16.exe examples/16-stb_sprintf.c                 && ./16.exe && echo -e "\n"
# echo "Running 17-stb_textedit.c ..."
# clang -I. -o 17.exe examples/17-stb_textedit.c                && ./17.exe && echo -e "\n"
# echo "Running 18-stb_tilemap_editor.c ..."
# clang -I. -o 18.exe examples/18-stb_tilemap_editor.c          && ./18.exe && echo -e "\n"
echo "Running 19-stb_truetype.c ..."
clang -I. -o 19.exe examples/19-stb_truetype.c                && ./19.exe && echo -e "\n"
# echo "Running 20-stb_voxel_render.c ..."
# clang -I. -o 20.exe examples/20-stb_voxel_render.c            && ./20.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
