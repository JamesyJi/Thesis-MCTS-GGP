file(REMOVE_RECURSE
  "libmain.a"
  "libmain.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/main.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
