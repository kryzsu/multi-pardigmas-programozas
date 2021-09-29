for i in *_build
do
  parts=(${i//_/ })
  cmake_dir=${parts[0]}
  cd $i && cmake ../$cmake_dir && make && cd ..
done

