file(REMOVE_RECURSE
  "libgames.a"
  "libgames.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/games.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
