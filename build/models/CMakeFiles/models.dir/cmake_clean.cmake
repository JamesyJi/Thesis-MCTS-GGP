file(REMOVE_RECURSE
  "libmodels.a"
  "libmodels.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/models.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
