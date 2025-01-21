# homework7
#inital commit


#build:  
mkdir build  
cd build  
cmake ..  
cmake --build .  
  
#run  
./containers_tests  
  
#one case  
./containers_tests --gtest_filter=ListCont.Update  

#one typecase  
./containers_tests --gtest_filter=ListCont.*

#repeat  
./containers_tests --gtest_filter=ListCont.* --gtest_repeat=1000 --gtest_break_on_failure  

#report
./containers_tests --gtest_output=xml:out.xml 
  
#random
./containers_tests --gtest_shuffle