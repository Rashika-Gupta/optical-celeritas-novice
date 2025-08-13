August 11
1. Enable the optical options in the setup option
2. ```code    issued by : celeritas/optical/MaterialParams.cc:133
Celeritas runtime error: refractive index values are not monotonically increasing``` -validation of the refractive index values be increasing is deisabled. (by commenting out) as in the example of  the air the refractive index values are constant.
3.```code issued by : celeritas/optical/ModelImporter.cc:108
 precondition failed: input_.import_material``` as in the example opnovice they use the mie and it is not incorportated in the celeritas yet. - add option of mie or for now added the refractive index as one of the check for the optical physics parameters, such as - ```code 
mat.properties().refractive_index()``` and the refractive index.

//add test in cherenkov.test.cc and then implement dndx calculator fro constant refractive index values...
import process does not have the optical physics - oprayleigh yet.
 import_optical_physics  in geant importer.cc
 add support to make a  empty grid in the  in mdfbuilder